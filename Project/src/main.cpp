#include <iostream>

#include "Loader.h"
#include "Graph.h"

using namespace std;

int main() {
    Graph<Node> a;
    LoadNodes(a);
    LoadEdges(a);
    system("pause");
    return 0;
}