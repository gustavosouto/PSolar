## Painel Solar Automático com Arduino
Este projeto consiste em um painel solar automatizado que se move em busca da máxima eficiência, utilizando fotossensores para detectar a intensidade da luz ambiente. O objetivo é garantir que a placa solar esteja sempre posicionada de forma a capturar a maior quantidade de luz possível.

## Componentes Utilizados
- Arduino Uno R3
- Fotossensores (Fotorresistores)
- Posicional Micro Servo
- Resistor de 10 kΩ
- Placa solar (simbólica, utilizada apenas para fins de prototipagem)

## Funcionamento
O painel solar é montado sobre um suporte que permite movimento rotacional. Dois fotossensores são posicionados em direções opostas no suporte, de modo que um está exposto à luz direta do sol enquanto o outro está na sombra. O servo motor é conectado ao suporte do painel solar e é responsável por ajustar sua posição.

O Arduino lê continuamente os valores dos fotossensores para determinar a diferença de intensidade de luz entre eles. Com base nessa diferença, o Arduino calcula a direção em que o painel solar deve se mover para maximizar a exposição à luz solar. O servo motor é então acionado para girar o painel na direção adequada.

## Tinkercad Simulation
Você pode acessar uma simulação deste projeto no Tinkercad clicando [aqui](https://www.tinkercad.com/things/202XwRQpPTr-stunning-jofo/editel?sharecode=MUUWKSFR_3raqsbHuUJFdEVzhuwG0FYNYcGzFMw1Ny8). Esta simulação permite visualizar o funcionamento do painel solar automatizado em um ambiente virtual antes de implementá-lo fisicamente.

## Instalação
Monte o suporte do painel solar e fixe os fotossensores em posições opostas.
Conecte os componentes eletrônicos de acordo com o esquema fornecido.
Carregue o código Arduino fornecido neste repositório para o Arduino Uno.
Certifique-se de que o painel solar está em um local onde possa receber luz solar direta.

## ThingSpeak
Você pode acessar o canal do ThingSpeak clicando [aqui](https://thingspeak.com/channels/2558350). Este canal mostra status que permite visualizar os gráficos de linha da Luminosidade e Rotação, que é referente ao funcionamento do painel solar automatizado.

## Twilio
A plataforma de comunicação em nuvem (cloud) a qual foi utilizada foi a Twilio para fins de fornecimento de API para SMS.

## MyAppInventor
Esta aplicação foi utilizada para exibir os graficos de linhas e videos diretamente no Dashboard. [aqui](https://ai2.appinventor.mit.edu/#5913412504715264)

## Youtube
A apresentação deste projeto foi gravado por videor e publicado no Youtube através do link: [aqui](https://www.youtube.com/watch?v=NhYf1FsS7JQ)

## Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para propor melhorias, corrigir problemas ou adicionar novos recursos ao projeto.
