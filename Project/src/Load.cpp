//
// Created by Andreia Gouveia on 26/05/2019.
//

#include "Load.h"

vector<vector<int>> LoadTags(){


    vector<vector<int>> idAndAttributes;
    vector<int> ids;
    string line;
    int id;
    int counter = 0;
    int numberOfObjects;
    ifstream file("C:\\Users\\Andreia Gouveia\\Documents\\Aulas\\CAL\\CAL-Projecto\\T02\\Porto\\T02_tags_Porto.txt");//COLOCAR O PROPIO PATH, SENAO NAO FUNCIONA

    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    getline(file, line);//this first line doesn't matter to us

    cout << "Loading nodes..." << endl;

    for(int nrTags=0; nrTags<3; nrTags++) {

        getline(file, line);//get type
        line.clear();
        getline(file, line);//get number of objects
        // cout<<line<<endl;
        numberOfObjects = stoi(line);//get nr of objects of such categories
       // cout<<"in id, expectd : "<<numberOfObjects<<endl;

        line.clear();
        while (counter < numberOfObjects) {

            getline(file, line);
            //cout<<"line "<<counter<<": "<<line<<endl;
            id = stoi(line);//get id of the node
            ids.push_back(id);

            counter++;
            line.clear();
        }
        idAndAttributes.push_back(ids);
        ids.clear();
        counter = 0;
    }
    cout << "Finnished loading nodes..." << endl;

    file.close();

    return idAndAttributes;

}