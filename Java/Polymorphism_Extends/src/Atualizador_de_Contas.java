public class Atualizador_de_Contas extends Conta
{
    // ATRIBUTOS----------------------------------------------------------------
    private double saldoTotal=0;
    private double selic;
    
    
    
    
    // GET & SET----------------------------------------------------------------
    public double getSelic() {
        return selic;
    }
    
    public void setSelic(double selic) {
        this.selic = selic;
    }
    
    public double getSaldoTotal() {
        return saldoTotal;
    }
    
    public void setSaldoTotal(double saldoTotal) {
        this.saldoTotal = saldoTotal;
    }
    
    
    // METODOS ----------------------------------------------------------------
    
    public Atualizador_de_Contas(double d) {
        this.selic = d;
    }

    public void roda(Conta c)
    {
        System.out.println("-------------- RODA CONTA: "+c+"---------------------");
        //Imprimi o saldo anterior,
        System.out.println("|Saldo anterior: " + c.getSaldo());
        
        //Atualiza a conta,
        c.atualiza(saldo);
        
        //Imprime o saldo final
        System.out.println("|Saldo Final: " + c.getSaldo());
        
        // saldo total + saldofinal
        saldoTotal += c.getSaldo();
        System.out.println("|Saldo Total: "+saldoTotal);
        System.out.println("------------------------------------------------\n");

    }


}
