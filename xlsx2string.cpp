#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <OpenXLSX.h>
#include <vector>
#include <string>
#include <csv_engine.h>
#include <algorithm>
using namespace std;
using namespace OpenXLSX;




bool  checkstream(const std::string & T){

//for(int i=0; i<blacklist.size();i++){
//if(blacklist[i]==T[0]){T[0]=replace;}
//}
//
//
	std::string::iterator iter=T.begin();
	for(iter=T.begin();iter!=T.end();iter++)
	{

	if(*iter=='\n' && *iter==';'){return(false);}
	
	}
	return(true);
//cout<<endl<<T[i]<<" "<<int(T[i]);

}


std::string xlsx2string(char *filename)
{

	std::string file(filename);
	std::string fend(file.end()-5,file.end());
	if(fend==".xlsx"){	
	
	XLDocument doc;
	doc.OpenDocument(filename);
	auto  list= doc.Workbook().WorksheetNames();
	//cout<<doc.Workbook().WorksheetCount()<<endl;
	std::vector<std::string>::iterator iter;
	iter=list.begin();
	XLWorksheet wks = doc.Workbook().Worksheet(*iter);
	auto cols=wks.ColumnCount();
	auto rows=wks.RowCount();
	string file;
	int k,j;
	string test1;
	string cell_value;
	string primary_key;

file.reserve(cols*rows*30);

for(int i=1;i<=rows;i++)
{
	for(j=1; j<=cols;j++)
	{
	cell_value=wks.Cell(i,j).Value().AsString();
//	primary_key=wks.Cell(i,1).Value().AsString();
//	if(i>1  && primary_key=="")	{
//	k=i-1;
//	while(cell_value=="")	{
//	cell_value=wks.Cell(k,j).Value().AsString();
//	k=k-1;
//				}
//					}
	}
	if(checkstream(cell_value))
	{
	file.append(1,'"');
	file.append(cell_value);
	file.append(1,'"');
	}
	else{
	file.append(cell_value);
	}
	if(j<cols){file.append(";");}

	}

	
	if(j==cols+1){file.append("\n");}
}

doc.CloseDocument();

return(file);
}
return("");
}


int main(){
int i,j;
int k;

char fi[]="file.xlsx";
string all=ingest_xlsx(fi);
csv_file test(all);
test.write("file.csv");
/*
ofstream sData;
sData.open("output.csv");
//sData<<all;
sData.close();
char file[]="test3.csv";

test.write("test.csv");
*/
test.show_header();
while(0==0){
cin>>i;
cin>>j;
cout<<test.cell(i,j)<<endl;
}



//cout<<sizeof(char)*all.size()<<" bytes"<<endl;
}
