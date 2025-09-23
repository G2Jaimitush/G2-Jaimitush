public class Ejercicio2_LanzamientoDeDado {
    public static void main (String[] args) {
        int[] resultados = new int[6];
        int lanzamientos = 100000;
        int dado;

        for (int i = 0; i < lanzamientos; i++) {
            dado = (int)(Math.random() * 6);
            resultados[dado]++;
        }

        mostrar(resultados, lanzamientos);
    }


    private static void mostrar(int[] resultados, int lanzamientos) {
        for (int i = 0; i < resultados.length; i++) {
            System.out.printf("El %d ha salido %d veces (%.2f%%)\n", i + 1, resultados[i], (resultados[i] * 100.0) / lanzamientos);
        }

        System.out.println("Total lanzamientos: " + lanzamientos);
    }

}
