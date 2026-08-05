# Sistema de Gerenciamento de Resgates
Sistema de gerenciamento interativo desenvolvido em linguagem **C** para automatizar o atendimento, controle de pedidos e organização de uma central de resgate, projeto estruturado com boas práticas de programação como a divisão em scripts diferentes e endereçamentos ".h" e ".c" direto para a main e a execução principal.

## Estrutura do Projeto 

Para manter o código limpo e organizado, o sistema foi separado nos seguintes arquivos:

*   **`dados.h`**: Arquivo de Header responsável por armazenar as definições das estruturas de dados (`structs`),evitando a poluição visual na função principal e centraliza a modelagem dos dados do sistema de resgate.
*   **`frota.c`**: Funções relacionadas a lógica das frotas disponíveis e os veículos disponíveis.
*   **`main.c`**: Execução de tudo, sendo assim inclui-se toda a estrutura das funções e das structs.
*   **`missoes.c`**: Funções relacionadas a lógica das missões requeridas e da organização das frotas.
*   **`operadores.c`**: Funções relacionadas a lógica da organização de quem vai.

   ## ⚙️ Funcionalidades

*   [x] Menu interativo de navegação.
*   [x] Gerenciamento e estruturação de dados através de `structs`.
*   [x] Separação de responsabilidades (Modularização em C).
*   [x] Localização das viaturas.
*   [x] Organização das frotas. 
