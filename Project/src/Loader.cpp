
  #include "Loader.h"

void LoadNodes(Graph<Node> &graph) {
    string line;
    int numNodes;
    ifstream file("C:\\Users\\Andreia Gouveia\\Documents\\Aulas\\CAL\\CAL-Projecto\\T02\\Porto\\T02_nodes_X_Y_Porto.txt");

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
        graph.getVertexSet()[graph.getNumVertex() - 1]->setID(id); //Setting a id to be easier to create the edges
    }

    if (numNodes == graph.getNumVertex()) {
        cout << "Nodes successfully loaded!" << endl;
    }
    else {
        cout << "An unexpected error happened, please reinitialize the program." << endl;
        file.close();
        exit(1);
    }

    file.close();
}

void LoadEdges(Graph<Node> &graph) {
    string line;
    int numEdges;
    ifstream file("T02_edges_Porto.txt");

    if(!file.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    getline(file, line);
    numEdges = stoi(line);

    cout << "Loading edges..." << endl;

    while(getline(file, line)) {
        string aux;
        float id_start;
        float id_end;
        char space;
        Node start, end;
        double weight;

        line = line.substr(1, line.length() - 2);

        istringstream sLine(line);

        getline(sLine, aux, ',');
        sLine >> id_start;
        sLine >> space;
        sLine >> id_end;

        for (auto v : graph.getVertexSet()) {
            if (v->getID() == id_start) {
                start = v->getInfo();
            }
            if (v->getID() == id_end) {
                end = v->getInfo();
            }
        }

        weight = start.distance(end);
        graph.addEdge(start, end, weight);
    }

    if (numEdges == graph.getNumVertex()) {
        cout << "Nodes successfully loaded!" << endl;
    }
    else {
        cout << "An unexpected error happened, please reinitialize the program." << endl;
        file.close();
        exit(1);
    }

    file.close();
}
