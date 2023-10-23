from time import sleep


continuar = "s"
lista = []
Nome = input("Me conte seu nome: ")
print(f"Abrindo sua lista de tarefas {Nome}")

sleep(3)


while(continuar == "s"):
    tarefa = input('Nova tarefa:')
    lista.append(tarefa)
    print(lista)
    continuar = input("deseja continuar(s/n):")
print("Essa é sua lista de afazeres :")
for item in lista:
    print(item)

remover = input('deseja remover algo da lista?')

if( remover == "s"):
    lista.pop(int(input('qual item deseja remover')- 1))
    for item in lista:
        print(item)
        print('fim')
else:
    print('Fim')
