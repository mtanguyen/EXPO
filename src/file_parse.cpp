boolean file_parse(string line){
	int a = 0;
	
	if(line != NULL){
		while(line[a] != '/0'){
			switch(line[a]){
				case 0x41 ... 0x5A:
					break;
				case 0x61 .. 0x7A:
					break;
			}
		
			a++;
		}
	
		return true;
	}
	else return false;
}
