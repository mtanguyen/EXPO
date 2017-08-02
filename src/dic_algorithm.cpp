#include "declarations.h"

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <regex>
#include <set>

#define html_filename "html.txt"

using namespace std;

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream){
    int written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

vector<string> dic_algorithm(string wordToGet){
    CURL *curl_handle;

    FILE *html;
    html = fopen(html_filename, "w");
    if(html == NULL){
      cout << html_filename << " did not open." << endl;
    }

    string address = "http://www.thesaurus.com/browse/"+wordToGet+"?s=t";
    char *url_address = new char[address.length() + 1];
    strcpy(url_address, address.c_str());

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();

    curl_easy_setopt(curl_handle, CURLOPT_URL, url_address);
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, html);

    curl_easy_perform(curl_handle);

    fclose(html);

    string line;
    vector<string> v;
    fstream html_file(html_filename, ios::in);
    while(getline(html_file, line)){
        v.push_back(line);
    }
    html_file.close();

    curl_easy_cleanup(curl_handle);

    string whole_file;
    for(unsigned int i = 0; i < v.size(); i++){
        whole_file += v.at(i);
    }

    set<string> parts;
    set<string> parts2;
    vector<string> word_types;
    smatch m, m2;
    regex r("<em class=\"txt\">.+");
    regex r2("<span class=\"text\">.+");

    regex_search(whole_file, m, r);
    regex_search(whole_file, m2, r2);

    string::const_iterator searchStart( whole_file.cbegin() );

    while ( regex_search( searchStart, whole_file.cend(), m, r ) ) {
      parts.insert(m[0]);
      searchStart += m.position() + m.length();
    }
    while ( regex_search( searchStart, whole_file.cend(), m2, r2 ) ) {
      parts2.insert(m2[0]);
      searchStart += m2.position() + m2.length();
    }

    for (set<string>::iterator itr=parts.begin(); itr!=parts.end(); ++itr){
        string tempStr = (*itr);
        tempStr = tempStr.substr(16,tempStr.length());
        tempStr = tempStr.substr(0,tempStr.length()-5);

        word_types.push_back(tempStr);
    }

    for (set<string>::iterator itr=parts2.begin(); itr!=parts2.end(); ++itr){
        string tempStr = (*itr);
        
        size_t pos1 = tempStr.find("<span class=\"text\">");
        size_t pos2 = tempStr.find("</span><span class=\"star inactive\">star</span></a></li>");

        cout << "pos1 " << pos1 << " pos2 " << pos2 << endl;

        tempStr = tempStr.substr(19 ,tempStr.size()-19);
        size_t pos = tempStr.find("</");
        tempStr = tempStr.substr(0 ,pos);

        cout << "*itr: " << *itr << endl;
        cout << "Synonyms: " << tempStr << endl;
        cout << endl;
    }

    return word_types;
}
