#include "Loader.h"

/**
* Loader functions
*/


/**
 * Function that loads the nodes to the graph passed as reference in the argument
 * @param graph
 */
void LoadNodes(Graph<Node> &graph) {

    string line;
    int numNodes;
    ifstream file("..\\Nodes_Porto\\T02_nodes_X_Y_Porto.txt");

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    getline(file, line);
    numNodes = stoi(line);

    cout << "Loading nodes..." << endl;


    while (getline(file, line)) {
        string aux;
        int id;
        float x;
        float y;
        char space;

        line = line.substr(1, line.length() - 2);

        istringstream sLine(line);

        getline(sLine, aux, ',');
        id = stoi(aux);
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
        cout << "nodes : " << graph.getNumVertex() << "     expected: " << numNodes << endl;
        cout << "An unexpected error happened, please reinitialize the program." << endl;
        file.close();
        exit(1);
    }

    file.close();
}

/**
 * Function that loads the edges to the graph passed as reference in the argument
 * @param graph
 */
void LoadEdges(Graph<Node> &graph) {
    string line;
    int numEdges;
    ifstream file("..\\Nodes_Porto\\T02_edges_Porto.txt");

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    getline(file, line);
    numEdges = stoi(line);

    cout << "Loading edges..." << endl;

    while (getline(file, line)) {
        string aux;
        int id_start;
        int id_end;
        Node start, end;
        double weight;

        line = line.substr(1, line.length() - 2);

        istringstream sLine(line);

        getline(sLine, aux, ',');
        id_start = stoi(aux);
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

    int counter = 0;
    for (auto a : graph.getVertexSet()) {
        counter += a->getEdges().size();
    }


    if (numEdges == counter) {
        cout << "Edges successfully loaded!" << endl;
    } else {
        cout << "An unexpected error happened, please reinitialize the program. " << endl;
        file.close();
        exit(1);
    }

    file.close();
}

/**
 * Function that loads the tags to the graph passed as reference in the argument
 * @param graph
 * @return idAndAttributes
 */
vector<vector<int>> LoadTags() {
    vector<vector<int>> idAndAttributes;
    vector<int> ids;
    string line;
    int id;
    int counter = 0;
    int numberOfObjects;
    ifstream file("..\\Nodes_Porto\\T02_tags_Porto.txt");

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    getline(file, line);//this first line doesn't matter to us

    cout << "Loading tags..." << endl;

    for (int nrTags = 0; nrTags < 3; nrTags++) {

        getline(file, line);//get type
        line.clear();
        getline(file, line);//get number of objects
        // cout << line << endl;
        numberOfObjects = stoi(line);//get nr of objects of such categories
        // cout << "in id, expectd : " << numberOfObjects << endl;

        line.clear();
        while (counter < numberOfObjects) {

            getline(file, line);
            //cout << "line " << counter << ": " << line << endl;
            id = stoi(line); //get id of the node
            ids.push_back(id);

            counter++;
            line.clear();
        }

        idAndAttributes.push_back(ids);
        ids.clear();
        counter = 0;
    }
    cout << "Tags successfully loaded!" << endl << endl;

    file.close();

    return idAndAttributes;
}

