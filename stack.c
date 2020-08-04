Pilha* tira_maior_pilha(Pilha *p,int maior)
{
    Pilha *aux=CriaPilha();
    int valor;
    while(vazia(p))
    {
        valor=pop(p);
        if(valor!=maior)
            push(aux,valor);
    }
    return aux;
}    
    






Pilha* ordena(Pilha *p,int tam)
{
    Pilha *aux,*ordenada=CriaPilha();
    int i,maior,valor;
    for(i=0;i<tam;i++)
    {
        Pilha *aux = CriaPilha();
        maior=pop(p);///tira da pilha
        push(p,maior);///devolve para pilha
        while(vazia(p))
        {
            valor=pop(p);
            if(valor>maior)
                maior=valor;
            push(aux,valor);
        }
        push(ordenada,maior);
        libera(p);
        p=tira_maior_pilha(aux,maior);///vai tirar o elemento maior elemento da pilha que foi adicionado na ordenada, para continuar a comparação com os menores.
        libera(aux);
    }
    return ordenada;
}
