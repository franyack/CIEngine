#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "json.hpp"
using namespace cv;
using namespace std;
using jsonlib = nlohmann::json;

void WriteJSON(vector<string> imagenes){
	
	
	jsonlib json;
	
	for(int i=0;i<imagenes.size();i++) {
		string value = imagenes[i];
		int number = i+1;
		stringstream ss;
		ss << number;
		string str = ss.str();
		string key = "img" + str;
		
		json[key] = value;
		
	}
	
	string json_string;
	
	json_string = json.dump(4); // o json.dump();
	
	//cout<<json_string;
	
	ofstream file("images.json");
	file << json_string;
	file.close();
}

jsonlib ReadJSON(string path){
	jsonlib json;
	
	std::ifstream i(path);
	i >> json;
	
	return json;
	//	string json_string;
	//	json_string = json.dump(4);
	//	cout<< json_string;
}


int GetCluster(){
	//	srand((unsigned)time(0));
	int i;
	i = (rand()%10)+1;
	return i ;
}

int main(int argc, char** argv) {
	
	//--------------------
	/* GENERAR JSON */
	//--------------------
	
	//Deberï¿\u0153a buscar la forma de automatizar esto
	vector<string> imagenes;
	imagenes.push_back("images/1.png");
	imagenes.push_back("images/2.png");
	imagenes.push_back("images/3.png");
	imagenes.push_back("images/4.png");
	imagenes.push_back("images/5.png");
	imagenes.push_back("images/6.png");
	
	//	WriteJSON(imagenes);
	
	//--------------------
	/* LEVANTAR JSON */
	//--------------------
	
	jsonlib json;
	
	json = ReadJSON("images.json");
	
	//--------------------
	/* PROBANDO */
	//--------------------
	
	
	jsonlib outputjson;
	
	//ANDA!
	for (jsonlib::iterator it = json.begin(); it != json.end(); ++it) {
		//		std::cout << it.key() << " : " << it.value() << "\n";
		Mat img = imread(it.value());
		imshow("Probando",img);
		
		//		outputjson[it.key()] ={it.value(),GetCluster()};
		// or
		outputjson[it.key()] =GetCluster();
		
		waitKey(0);
	}
	
	string outjson;
	outjson = outputjson.dump(4);
	cout<<outjson;
	
	
	
	
	
	waitKey(0);
	return 0;
} 
