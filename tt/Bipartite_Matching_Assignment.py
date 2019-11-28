
class BipartiteGraph():
    def __init__(self, V1, V2, E = [], W = None):
        '''Class constructor
        V1 and V2 are iterables containing the vertices in the first and second partitions
        vertices can be any hashable objects
        E is an iterable of edges (edges are iterables of size 2)
        W is an iterable containing the weights of the edges
        '''
        self.V1 = set(V1)
        self.V2 = set(V2)
        self.V = self.V1|self.V2
        self.Adj = {v:set() for v in self.V}
        for (v1, v2) in E:
            self.Adj[v1].add(v2)
            self.Adj[v2].add(v1)

        if W != None:
            self.W = {tuple(e):W[k] for (k, (u, v)) in enumerate(E) for e in [(u,v), (v,u)] }
        self.E = set(tuple(e) for e in E)

def MaximumCardinalityMatching(B, M = [], returnLabeled = False): 
    '''Computes the maximum cardinality matching of the bipartite graph B
    B must be an object of the BipartiteGraph class above
    M is an iterable containing edges (iterables of size 2) in a previously known matching
    '''
    mate = {v:None for v in B.V}
    for (v1, v2) in M:
        mate[v1], mate[v2] = v2, v1

    label = {v:None for v in B.V}
    labeledV1, labeledV2 = set(), set()

    L = set(v for v in B.V1 if mate[v] == None)
    for v in L:
        label[v] = '*'

    while L:
       v = L.pop()
       if v in B.V1:
            labeledV1.add(v)
            for u in B.Adj[v]:
                if u != mate[v]:
                    label[u] = v
                    L.add(u)
       else:
            labeledV2.add(v)
            if mate[v] == None: #Augmenting path found
                while v != '*':
                    u = label[v]
                    mate[u], mate[v] = v, u
                    v = label[u]

                label = {v:None for v in B.V}

                L = set(v for v in B.V1 if mate[v] == None)
                for v in L:
                    label[v] = '*'

            else:
                u = mate[v]
                label[u] = v
                L.add(u)

    M = [(v1, v2) for (v1, v2) in B.E if mate[v1] == v2 ]

    if returnLabeled:
        return M, labeledV1, labeledV2
    else:
        return M
                
def AssignmentProblem(B):
    '''Computes the maximum cost assignment of the bipartite graph B
    B is assumed to be complete
    '''
    d = {v:max(B.W[(v, u)] for u in B.Adj[v]) for v in B.V} 
    modW = {(u,v):(B.W[(u, v)] -d[u] -d[v]) for (u,v) in B.E}

    M = []
    while True:
        modB = BipartiteGraph(B.V1, B.V2, E = [e for e in B.E if abs(modW[e]) < 1e-6])
        M, lV1, lV2 = MaximumCardinalityMatching(modB, M, returnLabeled = True)

        if len(M) != len(B.V1):
            #Dual step
            delta = min(-modW[(v1, v2)] for v1 in lV1 for v2 in B.V2-lV2)

            for v1 in lV1:
                d[v1] -= delta/2
            for v2 in lV2:
                d[v2] += delta/2

            for v1 in B.V1-lV1:
                d[v1] += delta/2
            for v2 in B.V2-lV2:
                d[v2] -= delta/2

            modW = {(u,v):(B.W[(u, v)] -d[u] -d[v]) for (u,v) in B.E}

        else:
            break

    return M
