# Microservices

## 1. Monolithic Architecture 
Monolithic application where you have everything (all services) in one place (one package).

### Drawbacks of Monolithic architecture
- Team dependencies ( to upgrade a single service depending on other team)
- Scalabilty (instead of scaling particular service need to scale whole application )
- Same technology ( All services should wriiten in same language becoz all are binded into single pakage )
- Crashing together ( if one service failed the whole application goes down )

#### NOTE: Scaling
1. Horizontal Scaling 
- by running multiple instances to handle more number of requests

2. Vertical Scaling
- by adding more servers or increasing RAM power to handle large number of requests

## 2. Microservices Architecture 
Microservices architecture gives you control to split project to small individual services and each service will communicate with each other using HTTP requests when they need.

### Advantages of Microservices architecture
- No Team dependencies ( you can upgrade a single service without others )
- Scalabilty ( scaling particular service is possible when there is a need )
- Diverse ( you can use different technology or language for diff services )
- independant ( if one service goes down other can work seamlessly )

### What other thing need for to implement microservices ?
- API Gateway
- Service Registry
- Load balancer
- Failed fast logic

### Dependencies need to included in normal spring boot project
- Spring Web 
- PostgreSQL Driver
- Lombok
- Spring Data JPA

### Extra Dependencies need to included in microservice
- OpenFeign
- Eureka Discovery Client

### Running multiple instances for same microservice
- when you need horizinatal scaling of application you can change server port number of each instances and run them parallely
- to do that , in intellij create new Run configuration and in VM Options give this
`-Dserver-port=8081`.so, new instance will run in new port without disturbing exist service.







