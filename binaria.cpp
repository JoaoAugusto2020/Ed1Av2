#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct No {

    int valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Pilha {

    No* topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    void inserir(int valor) {
        No* novo = new No(valor);
        if (topo == NULL) {
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    void remover() {
        if (n == 0) return;
        if (n == 1) {
            delete(topo);
            topo = NULL;
            n = 0;
            return;
        }
        No* aux = topo;
        topo = topo->prox;
        delete(aux);
        n--;
    }

    int topoPilha() {
        if (topo == NULL) return 0;
        return topo->valor;
    }

};

int main() {

    Pilha p;
	int n=0;
	
	cin>>n;
	while(n--){
		int decimal=0, resto=0, proximo=0;
		cin>>decimal;
		
		while(decimal>0){
			resto = decimal % 2;
			decimal = decimal / 2;
			p.inserir(resto);
		}
		
		while(p.n!=0){
			cout<<p.topoPilha();
			p.remover();
		}
		cout<<endl;
	}
    
    p.remover();

    return 0;
}
