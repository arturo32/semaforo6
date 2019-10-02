# semaforo6
School project using Arduino Uno to command traffic and pedestrian lights.

Pelo visto não decidi se escrevi isso em inglês ou português. Enfim. Esse projeto envolve a produção de um código para comandar dois semáforos em um cruzamento, cada um com 6 luzes para a cor verde e 6 luzes para cor vermelha, que vão descendo quando estão prestes a mudar de cor. Há também dois semáforos de pedestre com uma luz verde e vermelha cada. Além disso há um aviso sonoro produzido por uma alto falante que avisa quando é permitido atravessar para os pedetre com deficiência visual.

Contando com as duas luzes amarelas, um para cada semáforo de tráfego, há ao todo 30 luzes. Como o Arduino Uno não possui essa quantidade de portas foi necessário usar CIs chamados registradores de deslocamento (74HC595). "pinclock", "pindata" e "pinlatch" no códido representam a manipulação desses CIs.

Esse foi o primeiro código que escrevi na minha vida. Aprendi como programar na linguagem do Arduino (baseada em C++) somente por meio de vídeos já que a única coisa que o nosso professor ensinou foi fazer um led piscar.
