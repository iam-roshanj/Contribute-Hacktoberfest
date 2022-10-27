public class Conta_Poupanca extends Conta {
    
    @Override
    public double atualiza(double d)
    {
        return this.saldo += this.saldo * (taxa*3)/100;
        
    }

    @Override
    public double deposita(double valor)
    {
       return this.saldo += (valor);
    }

    
}
