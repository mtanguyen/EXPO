#include "declarations.h"

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <regex>
#include <set>

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

vector<string> dic_algorithm(string wordToGet){
  CURL *curl;
  CURLcode res;
  string readBuffer;

  vector<string> word_types;
  
  string address = "http://www.thesaurus.com/browse/"+wordToGet+"?s=t";
  curl = curl_easy_init();
  
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }

  set<string> parts;
  set<string>::iterator itr;
  string str(readBuffer);
  regex r("<em class=\"txt\">.+");
  smatch m;
  regex_search(str, m, r);

  string::const_iterator searchStart( str.cbegin() );

  while ( regex_search( searchStart, str.cend(), m, r ) ) {
    parts.insert(m[0]);
    searchStart += m.position() + m.length();
  }

  for (itr=parts.begin(); itr!=parts.end(); ++itr){
    string tempStr = (*itr);
    tempStr = tempStr.substr(16,tempStr.length());
    tempStr = tempStr.substr(0,tempStr.length()-5);
    cout << tempStr << endl;

    word_types.push_back(tempStr);
  }

  return word_types;
}
