import java.util.Scanner;
/**
 * This program demonstrates radioactive half-life decay in a specified number of particles using randomly generated probabilities of decay.
 * @author (Jacob Landerer)
 * @version (4.1.20)
 */
public class RadioActivityProbability
{
    static int n;
    static Scanner UserInput = new Scanner (System.in);
    public static void main(){
        System.out.println('\u000C');
        System.out.println(" How many particles would you like to use for this simulation?");
        n = UserInput.nextInt();
        boolean Particles[] = new boolean [n];
        int NumRounds[] = new int [n];
        int turn = 0; 
        double delay = 50.0; // time for 1 turn
        try{ // Because ExecuteDecay throws an exception, it is necessary to call it within a try catch bracket
            ExecuteDecay(Particles, turn, NumRounds, delay);
        }
        catch (InterruptedException Threading){}
        try{
            Print(NumRounds, delay, turn); // Prints results of the simulation
        }
        catch(InterruptedException Threading){}
        Histogram.GetMaximums(NumRounds); // Continues to the histogram
    }

    public static void ExecuteDecay(boolean Particles[], int turn, int NumRounds[], double delay) throws InterruptedException{
        if (!ArrayState(Particles)){ // If at least one particle has yet to decay
            Thread.sleep((int)delay); // Time unit delay
            turn++; // increment turn
            for (int i = 0; i < NumRounds.length; i++){ // For each particle
                if (NumRounds[i] == 0){ // If the particle has not decayed
                    Particles[i] = DetermineDecay(); // See if it decays based on an assigned probability
                    if (Particles[i]) // If yes
                        NumRounds[i] = turn; // Save the round it decayed at
                }
            }
            ExecuteDecay(Particles, turn, NumRounds, delay); // loops the function until all particles have decayed
        }
    }

    public static void Print(int NumRounds[], double delay, double turn) throws InterruptedException{
        System.out.println('\u000C');
        for (int k = 0; k < NumRounds.length; k++){ // For each particle
            System.out.print((k + 1) + ". "); // print its number
            for(int l = 0; l < NumRounds[k]; l++){ // For the number of rounds particle k survived
                System.out.print("*");
            }
            System.out.println(" - " + NumRounds[k] + " rounds");
        }
        Thread.sleep(3000);
        System.out.println('\u000C');
        System.out.println("Please wait for the results to be plotted");
        for (int i = 0; i < 10; i++){
            Thread.sleep(200);
            System.out.print(".");
        }
    }

    public static boolean DetermineDecay(){ // returns the outcome of a random generation compared to the likelihood of decay
        if (Math.random() <= .20)
            return true;
        else
            return false;
    }

    public static boolean ArrayState(boolean array[]){ // checks the states of each element in an array
        // if any one value is false, this method returns false, allowing the simulation to continue
        for ( int i = 0; i < array.length; i++ ) {
            if (!array[i] )
                return false;
        }
        return true;
    }
}