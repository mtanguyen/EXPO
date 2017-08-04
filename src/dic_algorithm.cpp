#include "declarations.h"

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <regex>
#include <set>

using namespace std;

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream){
    int written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

list<string> dic_algorithm(string wordToGet){
    CURL *curl_handle;
    FILE *html;

    ofstream logs(dic_algorithm_log, ios::out | ios::app);

    
    logs << date_time() << " [DIC_ALGORITHM]: Entered function." << endl;
    logs << date_time() << " [DIC_ALGORITHM]: Word to get " << wordToGet << endl;
    cout << date_time() << " [DIC_ALGORITHM]: Word to get " << wordToGet << endl;

    html = fopen("../doc/html/html.txt", "w");
    if(html == NULL){
      cout << "../doc/html/html.txt" << " did not open." << endl;
    }

    string address = "http://www.thesaurus.com/browse/"+wordToGet+"?s=t";
    char *url_address = new char[address.length() + 1];
    strcpy(url_address, address.c_str());

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();

    curl_easy_setopt(curl_handle, CURLOPT_URL, url_address);
    delete [] url_address;
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, html);

    curl_easy_perform(curl_handle);

    fclose(html);

    string line;
    list<string> v;
    fstream html_file("../doc/html/html.txt", ios::in);
    while(getline(html_file, line)){
        v.push_back(line);
    }
    html_file.close();

    curl_easy_cleanup(curl_handle);

    string whole_file;
    for(list<string>::iterator it = v.begin(); it != v.end(); it++){
        whole_file += *it;
    }

    smatch m, m2;
    set<string> parts, parts2;
    list<string> word_types;
    regex r("<em class=\"txt\">.+");
    regex r2("<span class=\"text\">.+");
    string::const_iterator searchStart(whole_file.cbegin());

    regex_search(whole_file, m, r);

    while ( regex_search( searchStart, whole_file.cend(), m, r ) ) {
        parts.insert(m[0]);
        searchStart += m.position() + m.length();
    }

    for (set<string>::iterator itr=parts.begin(); itr!=parts.end(); ++itr){
        string tempStr = (*itr);

        tempStr = tempStr.substr(16,tempStr.length());
        tempStr = tempStr.substr(0,tempStr.length()-5);
                
        word_types.push_back(tempStr);
    }

          

    string html_filename = "../doc/html/html_" + wordToGet + ".txt";
    ofstream html_synonym(html_filename, ios::out | ios::app);

    if(!html_synonym.is_open()){
      cout << html_filename << " did not open." << endl;
    }
    regex_search(whole_file, m2, r2);

    while ( regex_search( searchStart, whole_file.cend(), m2, r2 ) ) {
        parts2.insert(m2[0]);
        searchStart += m2.position() + m2.length();
    }

    for (set<string>::iterator itr = parts2.begin(); itr!=parts2.end(); ++itr){
        string tempStr = (*itr);

        tempStr = tempStr.substr(19 ,tempStr.size()-19);
        size_t pos = tempStr.find("</");
        tempStr = tempStr.substr(0 ,pos);

        html_synonym << tempStr << endl;
    }

    logs << date_time() << " [DIC_ALGORITHM]: Exitited function." << endl;
    logs.close();

    return word_types;
}