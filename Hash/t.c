TABELA HASH

Uma tabela hash, também conhecida como tabela de dispersão, é uma estrutura de dados usada em ciência da computação para armazenar e recuperar dados de forma eficiente. 
Ela é projetada para associar chaves (ou chaves de pesquisa) a valores, permitindo que você procure um valor rapidamente, dada a chave correspondente, 
sem a necessidade de percorrer uma lista inteira de elementos.

1 - Inserção (Insert): Em uma tabela de hash bem projetada, a inserção de um elemento tem uma complexidade média de tempo de O(1). 
No entanto, em casos extremos, quando ocorrem muitas colisões, a complexidade pode se aproximar de O(n), onde "n" é o número de elementos na tabela.

2 - Busca (Search): Assim como a inserção, a busca em uma tabela de hash bem projetada tem uma complexidade média de tempo de O(1).
 No entanto, novamente, em casos de colisões frequentes, a complexidade pode ser maior.

3 - Remoção (Delete): A remoção em uma tabela de hash também tem uma complexidade média de tempo de O(1),
 mas pode se aproximar de O(n) em casos de colisões significativas.

É importante notar que essas complexidades (O(1)) são médias e pressupõem uma boa distribuição das chaves e um fator de carga adequado
 (ou seja, o número de elementos na tabela em relação ao tamanho da tabela). Se o fator de carga for muito alto, a tabela de hash pode se tornar ineficiente devido a um grande número de colisões.

Função hash padrão:

M = "tamanho do vetor"

int hash(int chave){

    return chave % M;
} 

Uma boa escolhe para M define uma boa implementação de tabela hash, ja que esta ligada a função de espalhamento, uma boa escolha costuma ser:

1- Primo suficientemente grande.
    Geralmente usa-se: 2 * "Quantidade de chaves" -> usa o primo mais proximo

MAIS SOBRE O CUSTO DAS FUNÇÕES:

sendo "q" o numero de colisões numa tabela e que a função hash espalha as chaves de maneira uniforme e independente na tabela, sabemos:

      N -> total de chaves
q <=  /
      M -> tamanho da tabela(vetor)

    O custo médio das operações em uma tabela hash é frequentemente expresso em termos do fator de carga (load factor),
    que é definido como o quociente entre o número de elementos (N) e o tamanho da tabela (M), ou seja, Load Factor (LF) = N/M, 
    sendo o número de colisões proporcional ao fator de carga.

    Sendo assim, nos piores casos a compelxidade pode chegar a O(N), havendo muitas colisões. 

FATOR DE CARGA: 

Fator de Carga Baixo (LF < 1): Quando o fator de carga é baixo, significa que há mais slots vazios na tabela do que elementos armazenados.                 -|
 Isso geralmente resulta em uma distribuição uniforme das chaves pelos slots, minimizando assim as colisões.                                                |
 Em média, cada slot terá poucas ou nenhuma colisão. Portanto, um fator de carga baixo é desejável para evitar colisões.                                    |
                                                                                                                                                            |-          iSSO SERVE PARA HASH SEQUENCIAL GERALMENTE
Fator de Carga Alto (LF > 1): Quando o fator de carga é alto, significa que há mais elementos armazenados do que slots disponíveis na tabela.               |           JA QUE AS ENCADEADAS PODEM TER N>= M,E AINDA NÃO TER COLISÕES
 Isso aumenta a probabilidade de colisões, porque mais chaves competem pelos mesmos slots.                                                                  |            E AINDA NÃO TER COLISÕES
  Se o fator de carga for muito alto, as colisões podem se tornar frequentes e afetar o desempenho da tabela hash.                                         -|

Portanto, um fator de carga muito alto aumenta significativamente a probabilidade de colisões, enquanto um fator de carga muito baixo pode resultar em um desperdício de espaço.
 O desafio é encontrar um equilíbrio entre esses dois extremos,
  mantendo o fator de carga em um valor razoável para minimizar colisões e garantir que a tabela não seja muito grande em relação ao número de elementos armazenados.

OBS: HASH ENCADEADAS podem ter N>= M

No caso das sequenciais se a tabela encher e for necessasrio inserir mais elementos é recomendado que:

    Obs:  redimensiornar quando N = M/2

1 - Realocar o tamanho da tabela para o primo maior e mais proximo de 2 * M.
2 - Reaplicar a função hash em todos os elementos novamente.

