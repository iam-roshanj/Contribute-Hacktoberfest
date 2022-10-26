public class Conta_Corrente extends Conta {
    @Override
    public double atualiza(double d)
    {
        return this.saldo += this.saldo * (taxa*2)/100;
    }

    @Override
    public double deposita(double valor)
    {
       return this.saldo += (valor-0.10);
    }

    
}
