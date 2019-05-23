#include "Loader.h"

void LoadNodes(Graph<Node> &graph) {
    string line;
    int numNodes;
    ifstream file("T02_nodes_X_Y_Porto.txt");

    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    getline(file, line);
    numNodes = stoi(line);

    cout << "Loading nodes..." << endl;

    while(getline(file, line)) {
        string aux;
        int id;
        float x;
        float y;
        char space;

        line = line.substr(1, line.length() - 2);

        istringstream sLine(line);

        getline(sLine, aux, ',');
        sLine >> id;
        sLine >> space;
        sLine >> x;
        sLine >> space;
        sLine >> y;

        Node point = Node(id, x, y);
        graph.addVertex(point);
    }

    if (numNodes == graph.getNumVertex()) {
        cout << "Nodes successfully loaded!" << endl;
    }
    else {
        cout << "An unexpected error happened, please reinitialize the program." << endl;
    }

    file.close();
}

void LoadEdges(Graph<Node> &graph) {

}
