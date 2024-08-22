#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<ctype.h>

using namespace std;

struct No {

    char valor;
    No* prox;

    No() {
    	valor = {};
        prox = NULL;
    }

    No(char _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Fila {

    No* inicio;
    No* fim;
    int n;

    Fila() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void enfileirar(char valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void desenfileirar(){
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

   	char frente() {
        if (inicio == NULL) return 0;
        return inicio->valor;
    }

};

struct Pilha {

    No* topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    void inserir(char valor) {
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

    char topoPilha() {
        if (topo == NULL) return 0;
        return topo->valor;
    }

};

int main() {

    Pilha vogaisInvertido;
	Fila vogais;
	char palavra[100], maiusculo[100];
	
	cin>>palavra;
    
    //pegando as vogais
    for(int i=0; i<strlen(palavra); i++){
    	palavra[i] = toupper(palavra[i]);
    	if((palavra[i] == 'A') || (palavra[i] == 'E') || (palavra[i] == 'I') || (palavra[i] == 'O') || (palavra[i] == 'U')){
    		//é vogal
    		vogais.enfileirar(palavra[i]);
		}
	}
	
	
	//invertendo
	while(vogais.n>0){
		vogaisInvertido.inserir(vogais.frente());
		vogais.desenfileirar();
	}
	
	//onde for vogal, inprime da pilha com as vogais invertida, 
	//se não for vogal, só imprime a letra
	for(int i=0; i<strlen(palavra); i++){
    	if((palavra[i] == 'A') || (palavra[i] == 'E') || (palavra[i] == 'I') || (palavra[i] == 'O') || (palavra[i] == 'U')){
    		//é vogal
    		cout<<vogaisInvertido.topoPilha();
    		vogaisInvertido.remover();
		}else{
			cout<<palavra[i];
		}
		
	}

    return 0;
}
