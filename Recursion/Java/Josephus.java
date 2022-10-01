public class Josephus {
        public static int DeathGame(int noOfPlayer, int shotPlayer)
        {
            if(noOfPlayer==1)
            return 0;
            return (DeathGame(noOfPlayer-1,shotPlayer)+shotPlayer)%noOfPlayer;
        }
        public static void main(String[] args) {
            System.out.println(DeathGame(5 ,    3));
        }
}
