// �����ڽ�2017���һ�⼴Ϊ�Ҽ�·����û�л�·
// uv:ָ�������� path���ڴ��·�������� d������·����� kָ���ĳ���
void FindPath(ALGraph * algraph,int u,int v,int path[],int d,int k){
    int w;
    ArcNode * p;
    d++;
    path[d] = u;/*path��¼��v���������Ľ��*/
    visited[u] = 1;
    if(u==v){/*�˴�Ϊ�ݹ���ڣ���v����Ѱ��u, ��һ��v�ߵ����յ�*/
        if(d==k){/*������յ�Ĳ���Ϊk,��ô�����·��*/
            printPath(path, d);
        }
        visited[v] = 0;
        return;
    }
    p = algraph->vertices[u].first;/*�ڽӱ���u��Ӧ��ͷָ��*/
    while(p!=NULL){/*����dfs����*/
        w = p->adjvex;
        if(visited[w] == 0){
            FindPath(algraph,w,v,path,d,k);
        }
        p = p->next;
    }
    visited[u] = 0;/*ΪʲôҪ�ָ��أ�*/
}

void findpath(ALGraph &G, int v, int u, int k, , int d,int flag) { //(v,u) 
	visited[v] = 1; 
	d++; 
	if (u == v) 
		if (d == k) 
			flag = 1;//������������1 
	for(int w = FirstNeighbor(G, v); w > 0; w = NextNeighbor(G, v, w)) { 
		if (!visited[w]) 
			findpath(G, w, u, k, d,flag); //flag==1 ˵���и�·�� 
	} 
	visited[v] = 0; //����Ϊδ���ʡ� 
} 
