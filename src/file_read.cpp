string file_read(string file_location){
	istream file;
	string file_line;
	
	file.open(file_location);
	
	if(file.is_open()){
		if(getline(file, file_line));
		else return NULL;
	}
	else cout << "[ERROR]: File does not open.";
	
	return file_line;
}
