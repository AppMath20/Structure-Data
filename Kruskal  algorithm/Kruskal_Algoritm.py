V=5
parent =[0]*V

def Find(i):
    while(parent[i]!=i):
        i=parent[i]
    return i

def Union(i,j):
    a=Find(i)
    b=Find(j)
    parent[a]=b

def Kruskal_Alg(matr):
     mincost=0
     for i in range(V):
        parent[i]=i

     edge_count=0
     while(edge_count<V-1):
         min=1000
         a = -1
         b = -1
         for i in range(V):
             for j in range(V):
                 if (Find(i) !=Find(j)) and (matr[i][j]<min):
                     min=matr[i][j]
                     a=i
                     b=j

         Union(a,b)
         edge_count=edge_count+1
         print("Edge %d:(%d,%d) cost:%d"%(edge_count,a,b,min))
         mincost+=min
     print("Minimum cost= %d"%(mincost))

M=[
     [1000,2,1000,6,1000], [ 2,1000,3,8,5],	[ 1000,3,1000, 1000,7],[ 6,8,1000,1000,9],[ 1000,5,7,9,1000 ],
  ]
Kruskal_Alg(M)


