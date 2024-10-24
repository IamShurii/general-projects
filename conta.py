'''
Projeto de conta bancaria 
Atributos: nome, saldo
Metodos: Mostrar saldo, sacar , depositar
'''
class Conta:
    def __init__(self,nome,saldo):
        self.nome = nome
        self.saldo = saldo
        self.saque_total = 0 
        self.extrato = []

    def exibir_saldo(self):
        print(f'Saldo atual: R${self.saldo}')
    
    def depositar(self, valor_depositar):
        self.extrato.append('+ R$' + str(valor_depositar))
        self.saldo += valor_depositar
        print(f'O valor R${valor_depositar} foi depositado')
        self.exibir_saldo()

    def sacar(self, valor_saque):
        taxa = 5
        valor_taxa = valor_saque * (taxa/100)
        if valor_saque + valor_taxa > self.saldo:
            print('Saldo insuficiente!')
        else:
            self.saque_total += valor_saque
            limite = 100 

            if (self.saque_total > limite):
                print('Limite atingido')
            else:
                self.extrato.append('- R$' + str(valor_saque))
                self.saldo -= valor_saque + valor_taxa
                print(f'O valor de R${valor_saque} foi sacado!')
                print(f'Taxa: R${valor_taxa}')
                self.exibir_saldo()

    def exibir_extrato(self):
        print('\nExtrato:')
        for i in self.extrato:
            print(i)

    def transferir(self, valor_transf, conta_destino):
        self.saldo -= valor_transf
        conta_destino.depositar(valor_transf)
        print(f'Transferencia de R${valor_transf} realizada')
        self.extrato.append('- R$' + str(valor_transf))

conta1 = Conta('Alexandre', 4250 )
conta1.depositar(150)
conta1.sacar(200)
conta1.exibir_extrato()

conta2 = Conta('Luiz', 3500)
conta2.transferir(30,conta1)

conta1.exibir_saldo()
conta2.exibir_saldo()