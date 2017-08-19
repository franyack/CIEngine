#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/matx.hpp>
#include <opencv2/imgproc.hpp>

#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"

#include "pdi_functions.h"
#include "utils.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <opencv2/core/cvdef.h>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iterator>
#include <ctime>
#include <cstdio>

using namespace cv;
using namespace pdi;
using namespace std;
using namespace rapidjson;


int GetCluster(){
//	srand((unsigned)time(0)); 
	int i;
	i = (rand()%10)+1; 
	return i ;
}

void sample_other() {
	// document is the root of a json message
	Document document;
	
	// define the document as an object rather than an array
	document.SetObject();
	
	// create a rapidjson array type with similar syntax to std::vector
	Value array(rapidjson::kArrayType);
	
	// must pass an allocator when the object may need to allocate memory
	rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
	
	// chain methods as rapidjson provides a fluent interface when modifying its objects
	array.PushBack("hello", allocator).PushBack("world", allocator);//"array":["hello","world"]
	
	document.AddMember("Name", "XYZ", allocator);
	document.AddMember("Rollnumer", 2, allocator);
	document.AddMember("array", array, allocator);
	
	// create a rapidjson object type
	rapidjson::Value object(rapidjson::kObjectType);
	object.AddMember("Math", "50", allocator);
	object.AddMember("Science", "70", allocator);
	object.AddMember("English", "50", allocator);
	object.AddMember("Social Science", "70", allocator);
	document.AddMember("Marks", object, allocator);
	//	fromScratch["object"]["hello"] = "Yourname";
	
	StringBuffer strbuf;
	Writer<StringBuffer> writer(strbuf);
	document.Accept(writer);
	
	std::cout << strbuf.GetString() << std::endl;
}


int main(int argc, char** argv) {
	
//	string images[4];
//	images[0] = "1.png";
//	images[1] = "2.png";
//	images[2] = "3.png";
//	images[3] = "4.png";

//	const char json[] = " { \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4],\"img1\": \"1.png\" } ";
	
	const char json[] = " {\"img1\": \"images/1.png\",\"img2\": \"images/2.png\",\"img3\": \"images/3.png\",\"img4\": \"images/4.png\" } ";
	
	printf("Original JSON:\n %s\n", json);					
	
	
	Document document;
	document.Parse(json);
	
//	assert(document.HasMember("img1"));
//	assert(document["img1"].IsString());
//	printf("img1 = %s\n", document["img1"].GetString());
	
//	
	Mat img1_mem = imread(document["img1"].GetString());
	namedWindow("imagen1",CV_WINDOW_KEEPRATIO);
	imshow("imagen1",img1_mem);
//	
	Mat img2_mem = imread(document["img2"].GetString());
	namedWindow("imagen2",CV_WINDOW_KEEPRATIO);
	imshow("imagen2",img2_mem);
//	
	Mat img3_mem = imread(document["img3"].GetString());
	namedWindow("imagen3",CV_WINDOW_KEEPRATIO);
	imshow("imagen3",img3_mem);
//	
	Mat img4_mem = imread(document["img4"].GetString());
	namedWindow("imagen4",CV_WINDOW_KEEPRATIO);
	imshow("imagen4",img4_mem);
	
	
	//-----this doesn't work-------
	
	
//	Value& s = document["img1"];
//	s.SetString("probando");
//	StringBuffer buffer;
//	Writer<StringBuffer> writer(buffer);
//	document.Accept(writer);
	
//document["img1"] = "probando"; 
	
	//----------------
	
	
	const char json2[] = " {\"img1\": 0,\"img2\": 0,\"img3\": 0,\"img4\": 0} ";
	
	printf("Original JSON2:\n %s\n", json2);	
	
	
	Document d;
	d.Parse(json2);
	
	// 2. Modify it by DOM.
	Value& s1 = d["img1"];
	s1.SetInt(GetCluster());
	
	Value& s2 = d["img2"];
	s2.SetInt(GetCluster());
	
	Value& s3 = d["img3"];
	s3.SetInt(GetCluster());
	
	Value& s4 = d["img4"];
	s4.SetInt(GetCluster());

	cout<<endl<<endl;
	
	// 3. Stringify the DOM
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);
	
	cout<<buffer.GetString()<<endl<<endl<<endl; //show changes
	
	
	
	printf("Modified JSON2:\n %s\n", json2); //doesn't show changes
	
	cout<<endl<<endl;
	
	//Example!
	sample_other();
	
	waitKey(0);
	return 0;
} 
