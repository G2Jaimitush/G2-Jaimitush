public class Ejercicio1_JuegoLoteria {

    public static void main(String[] args) {

        int generados = 0;
        int[] nums = new int[6];
        int n;

        do {
            n = (int)(Math.random() * 49 + 1);
            if (!repetidos(n, nums, generados)) {
                nums[generados] = n;
                generados++;
            }
        } while (generados < 6);

        ordenar(nums);
        mostrar(nums);
    }

    private static boolean repetidos(int n, int[] nums, int generados) {
        for (int i = 0; i < generados; i++) {
            if (nums[i] == n) {
                return true;
            }
        }
        return false;
    }

    private static void ordenar(int[] nums) {
        int aux;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] > nums[j]) {
                    aux = nums[i];
                    nums[i] = nums[j];
                    nums[j] = aux;
                }
            }
        }
    }

    private static void mostrar(int[] nums) {
        for (int num:nums) {
            System.out.print(num+", ");
        }
    }
}
