float file_compare(string master_location, string duplicate_location){
	int num_errors = 0;
	int num_characters = 0;
	float error_percentage = 0;
	
	istream master;
	string master_line;
	master.open(master_location):
	
	istream duplicate;
	string duplicate_line;
	duplicate.open(duplicate_location);
	
	if(duplicate.is_open() && master.is_open()){
		while(getline(master, master_line)){
			getline(duplicate, duplicate_line);
			
			for(int i = 0; i < master_line.length(); i++){
				char mchar = master_line[i];
				char dchar = duplicate_line[i];
				
				if(mchar != dchar)
				num_error++;
				
				num_characters++;
			}
		}
		error_percentage = (float)num_error/num_characters;
	}
	else if(duplicate.is_open() && !master.is_open()){
		cout << "[ERROR]: Master file was unable to open.";
	}
	else if(!duplicate.is_open() && master.is_open()){
		cout << "[ERROR]: Duplicate file was unable to open.";
	}
	else cout << "[ERROR]: Both Master and Duplicate failed to open.";
	
	master.close();
	duplicate.close();
	
	return error_percentage;
}
