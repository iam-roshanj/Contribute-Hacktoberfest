class Conta 
{
    //Atributos ----------------------------------------------------------------
    protected double saldo;
    protected double taxa=10;

    
    //GET & SET ----------------------------------------------------------------
    public double getSaldo() {
        return saldo;
    }
    
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }
    
    //METODOS ----------------------------------------------------------------
    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return this.getClass().getName();
    }
    
    public double saca(double valor)
    {
        
        return this.saldo -= valor;
        
    }
    
    public double deposita(double valor)
    {
        return this.saldo += valor;
        
    }
    
    public double atualiza(double d)
    {
        return this.saldo += this.saldo * (taxa)/100;
    }
    
}
