//Angelo Almeida Ferro(SIG) - #HacktoberFest22
public class main {
    public static void main(String[] args) throws Exception {
        //Polimorfismo
        Conta c = new Conta();
        Conta cc = new Conta_Corrente();
        Conta cp = new Conta_Poupanca();
        
        
        c.deposita(1000);
        cc.deposita(1000);
        cp.deposita(1000);

        System.out.println("\n-------------ANTES------------------------");
        System.out.println("|Saldo Conta: " +c.getSaldo());
        System.out.println("|Saldo Conta Corrente: " +cc.getSaldo());
        System.out.println("|Saldo Conta Poupanca: " +cp.getSaldo());
        System.out.println("--------------------------------------\n");
        
        c.atualiza(0.01);
        cc.atualiza(0.01);
        cp.atualiza(0.01);
        
        
        System.out.println("\n-------------DEPOIS------------------------");
        System.out.println("|Saldo Conta: " +c.getSaldo());
        System.out.println("|Saldo Conta Corrente: " +cc.getSaldo());
        System.out.println("|Saldo Conta Poupanca: " +cp.getSaldo());
        System.out.println("--------------------------------------\n");
        
        c.deposita(1000);
        cc.deposita(1000);
        cp.deposita(1000);

        Atualizador_de_Contas adc = new Atualizador_de_Contas(0.01);

        adc.roda(c);
        adc.roda(cc);
        adc.roda(cp);
        
        System.out.println("\n-------------TOTAL------------------------");
        System.out.println("Saldo Total: " +adc.getSaldoTotal());
        System.out.println("--------------------------------------\n");
        

    }
}
