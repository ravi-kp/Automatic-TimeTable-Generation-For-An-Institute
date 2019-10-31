from Bipartite_Matching_Assignment import *

def TestMaximumBipartiteMatching():
    V1, V2, E = [], [], []
    
    m = int(input())
    for i in range(m):
        v1, v2 = input().split()
        V1.append(v1)
        V2.append(v2)
        E.append((v1, v2))

    B = BipartiteGraph(V1, V2, E)
    print(MaximumCardinalityMatching(B, []))

def TestAssignmentProblem():
    V1, V2, E, W = [], [], [], []
    input_graph=open("input_graph.txt","r")
    m = int(input_graph.readline())
    for i in range(m):
        v1, v2, w = (input_graph.readline()).split()
        V1.append(v1)
        V2.append(v2)
        E.append((v1, v2))
        W.append(float(w))

    B = BipartiteGraph(V1, V2, E, W)
    temp=AssignmentProblem(B)
    with open('output_graph.txt', 'w') as fp:
         fp.write('\n'.join('%s %s' % x for x in temp))    
    
if __name__ == '__main__':
    #TestMaximumBipartiteMatching()
    TestAssignmentProblem()
    