#include <iostream>
#include <string>

class Chessman {		// Chessman adýnda bir base class
protected:            // Türetilmiþ sýnýflardan color a eriþmek için
    std::string color;
public:
    Chessman(std::string color) : color(color) {}   	// Taþýn rengini parametre alan kurucu fonksiyon
    virtual int getScore() = 0;          		 // Taþýn puanýný döndürmek için sanal fonksiyon
    std::string getColor() { return color; } 	 // Taþýn rengi için sanal fonksiyon
    virtual std::string getName() = 0; 			// Taþýn adýný döndüren bir fonksiyon ekledim
};

class Knight : public Chessman {  // At taþý için bir sýnýf , Chessman'den kalýtým alýyor
public:
    Knight(std::string color) : Chessman(color) {} // rengi parametre alan kurucu fonksiyon
    int getScore() override {		//Base classtaki sanal fonksiyonu geçersiz kýlmak için override iþlemi , puaný geri döndürmek için
        return 3;                  //Atýn puaný 3
    }
    std::string getName() override {
        return color == "WHITE" ? "ab" : "as";     // Taþ beyaz ise ab döndür deðilse as döndür
    }
};

class King : public Chessman {		// Þah taþý için bir sýnýf , Chessman'den kalýtým alýyor
public:
    King(std::string color) : Chessman(color) {}   // rengi parametre alan kurucu fonksiyon
    int getScore() override {			//Base classtaki sanal fonksiyonu geçersiz kýlmak için override iþlemi , puaný geri döndürmek için
        return 100;      
    }
    std::string getName() override {				
        return color == "WHITE" ? "sb" : "ss";      // Taþ beyaz ise sb döndür deðilse ss döndür
    }
};

class Bishop : public Chessman{    // Fil Taþý
	public:
	Bishop(std::string color) : Chessman (color){	}  // kurucu fonksiyon
	int getScore() override {                          // puaný geri döndürmek için override
	 return 3;
	}
	std::string getName() override{
		return color == "WHITE" ? "fb" : "fs";      	// Taþ beyaz ise fb döndür deðilse fs döndür
	}	
};

class Queen : public Chessman {   // Vezir Taþý kalýtým
public:
    Queen(std::string color) : Chessman(color) {} // kurucu fonksiyon
    int getScore() override {						//virtualý iptal etmek için puaný döndüren override
        return 9;
    }
    std::string getName() override {
        return color == "WHITE" ? "vb" : "vs";      // Taþ beyaz ise vb döndür deðilse vs döndür
    }
};

class Pawn : public Chessman {    // Piyon Taþý
public:
    Pawn(std::string color) : Chessman(color) {}
    int getScore() override {
        return 1;
    }
    std::string getName() override {
        return color == "WHITE" ? "pb" : "ps";		// Taþ beyaz ise pb döndür deðilse ps döndür
    }
};

class Rook : public Chessman {       // Kale Taþý
	public:
		Rook(std::string color) : Chessman (color){}  // Renk için kurucu fonksiyon
		int getScore() override {
			return 5 ;
		}		
	std::string getName() override {
		return color == "WHITE" ? "kb" : "ks" ;     // Taþ beyaz ise kb döndür deðilse ks döndür
	}
	};

int main() {
    Chessman* board[8][8] = {nullptr};  // 8x8 boyutunda array satranç tahtasý (Chessman tipinde pointer)

	
	
	
	//board 1 dizilimi
	// Rook = Kale , Knight = At , Bishop = Fil , Queen = Vezir , King = Þah , Pawn = Piyon , 
	board[0][0] = new Rook("BLACK");  //sol en üste vezir nesnesini yerleþtir,bellekten yer ayur
    board[0][1] = new Knight("BLACK");
    board[0][2] = new Bishop("BLACK");
    board[0][3] = new Queen("BLACK");
    board[0][4] = new King("BLACK");
    board[0][5] = new Bishop("BLACK");
    board[0][7] = new Rook("BLACK");    
    board[1][0] = new Pawn("BLACK");
    board[1][1] = new Pawn("BLACK");
    board[1][4] = new Pawn("BLACK");
    board[1][5] = new Pawn("BLACK");
    board[1][7] = new Pawn("BLACK");    
    board[2][2] = new Pawn("BLACK");    
    board[3][3] = new Knight("BLACK");
    board[3][6] = new Pawn("BLACK");    
    board[4][0] = new Queen("WHITE");
    board[4][3] = new Pawn("WHITE");
    board[4][5] = new Bishop("WHITE");
    board[4][7] = new Pawn("WHITE");    
    board[5][2] = new Knight("WHITE");    
    board[6][0] = new Pawn("WHITE");
    board[6][1] = new Pawn("WHITE");
    board[6][4] = new Pawn("WHITE");
    board[6][5] = new Pawn("WHITE");
    board[6][6] = new Pawn("WHITE");
    board[7][0] = new Rook("WHITE");
    board[7][4] = new King("WHITE");
    board[7][5] = new Bishop("WHITE");
    board[7][6] = new Knight("WHITE");
    board[7][7] = new Rook("WHITE");
    
    
    //board 3 dizilimi
    /*
    board[0][0] = new Queen("WHITE");   //sol en üste vezir nesnesini yerleþtir,bellekten yer ayur
    board[0][3] = new Queen("BLACK");   
    board[0][4] = new King("BLACK");
    board[1][5] = new Pawn("BLACK");
    board[1][7] = new Pawn("BLACK");
    board[2][1] = new Knight("BLACK");
    board[2][2] = new Pawn("BLACK");
    board[2][4] = new Pawn("WHITE");
    board[2][6] = new Knight("WHITE");
    board[3][3] = new Knight("WHITE");
    
    board[5][6] = new Pawn("WHITE");
    board[7][4] = new King("WHITE");
*/

float  blackScore = 0;
float whiteScore = 0;
 
    for (int i = 0; i < 8; ++i) {  						// 8x8 matrisin satýrlarýný gezmek için
        for (int j = 0; j < 8; ++j) {					// 8x8 matrisin sütunlarýný gezmek için
            if (board[i][j] != nullptr) {				// bulunduðu karede taþ var mý yok mu (eðer null deðilse döngüye devam et)
                
                if (board[i][j]->getName() == "pb" || board[i][j]->getName() == "ps") {      	// taþ piyon beyaz veya piyon siyah mý
                    Chessman* catchPiece = nullptr;										// yiyebileceðimiz taþ var mý diye bakmak için
                  //Eðer piyon beyaz ise sol üst çapraza ve sað üst çapraza bak
                  //yiyebileceði taþ varsa catchPiece e ata     board[0][0] = sol en üst   ,board[7][7] = sað en alt                  
                    if (board[i][j]->getColor() == "WHITE") {
                        if (i > 0 && j > 0 && board[i-1][j-1] != nullptr && board[i-1][j-1]->getName() == "ps") catchPiece = board[i-1][j-1];// sol üst çaprazda taþ varsa yiyebileceði taþ olarak ata 
                        if (i > 0 && j < 7 && board[i-1][j+1] != nullptr && board[i-1][j+1]->getName() == "ps") catchPiece = board[i-1][j+1];//sað üst çapraz
                    }
                    else {	//eðer piyon siyahsa solt alt çapraza ve sað alt çaprazýna bak
                        if (i < 7 && j > 0 && board[i+1][j-1] != nullptr && board[i+1][j-1]->getName() == "pb") catchPiece = board[i+1][j-1];// eðer sol alt çaprazda beyaz taþ varsa yiyebileceði taþ olarak ata
                        if (i < 7 && j < 7 && board[i+1][j+1] != nullptr && board[i+1][j+1]->getName() == "pb") catchPiece = board[i+1][j+1];// sað alt çapraz
                    }
                    if (catchPiece != nullptr) {										// yiyebileceðimiz bir taþ varsa (null deðilse)
                        if (board[i][j]->getColor() == "WHITE") {						// taþ beyazsa yediði taþ puanýnýn yarýsýný beyaza ekle , siyahtan düþür.
                            whiteScore += board[i][j]->getScore() / 2.0;
                            blackScore -= catchPiece->getScore() / 2.0;
                        }
                        else {															// taþ siyahsa yediði taþ puanýnýn yarýsýný siyaha ekle , beyazdan düþür.
                            blackScore += board[i][j]->getScore() / 2.0;
                            whiteScore -= catchPiece->getScore() / 2.0;
                        }
                    } else {																			// Eðer piyonun yiyebileceði bir taþ yoksa
                        if (board[i][j]->getColor() == "WHITE") whiteScore += board[i][j]->getScore();  // Beyaz puanýna piyonun tam puanýný ekle
                        else blackScore += board[i][j]->getScore();										// Siyah puanýna piyonun tam puanýný ekle
                    }
                } 
               
                else if (board[i][j]->getName() == "ab" || board[i][j]->getName() == "as") {	//Eðer taþ at beaz veya at siyah ise
                    Chessman* catchPiece = nullptr;										// yiyebileceði bir taþ var mý diye tutan deðiþken
                    
                    int xekseni[] = {-2, -1, 1, 2, 2, 1, -1, -2};     // Atýn x eksenindeki hareketleri
                    int yekseni[] = {1, 2, 2, 1, -1, -2, -2, -1};	// Atýn y eksenindeki hareketleri
                    for (int k = 0; k < 8; ++k) {				// Atýn gidebileceði 8 kare olduðu için 8 kere döngü
                        int nx = i + xekseni[k], ny = j + yekseni[k];		// yeni karenin koordinatlarý	
                        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] != nullptr && board[nx][ny]->getName() == board[i][j]->getName()) { // Eðer yeni kare tahtanýn içinde ve rakip bir taþ varsa
                            catchPiece = board[nx][ny];   		// Yiyebileceði taþ olarak ata
                            break; // döngüden çýk
                        }
                    }
                    if (catchPiece != nullptr) {				// Eðer yiyebileceði bir taþ varsa
                      
                        if (board[i][j]->getColor() == "WHITE") { // at beyazsa
                            whiteScore += board[i][j]->getScore() / 2.0;  	// // Beyaz puanýna atýn puanýnýn yarýsýný ekle
                            blackScore -= catchPiece->getScore() / 2.0; 	//// Siyah puanýndan yediði taþýn puanýnýn yarýsýný çýkar
                        }
                        else {		 // Eðer at siyah ise
                            blackScore += board[i][j]->getScore() / 2.0;  // Siyah puanýna atýn puanýnýn yarýsýný ekle
                            whiteScore -= catchPiece->getScore() / 2.0;  // Beyaz puanýndan yediði taþýn puanýnýn yarýsýný çýkar
                        }
                    } else {  // Eðer yiyebileceði bir taþ yoksa
                       
                        if (board[i][j]->getColor() == "WHITE") whiteScore += board[i][j]->getScore();  // Beyaz puanýna atýn tam puanýný ekle
                        else blackScore += board[i][j]->getScore(); // Siyah puanýna atýn tam puanýný ekle
                    }
                } 
                else if (board[i][j]->getName() == "vb" || board[i][j]->getName() == "vs") { // Eðer taþ beyaz vezir veya siyah vezirse
                    Chessman* catchPiece = nullptr; // Yiyebileceði bir taþ olup olmadýðýný tutan deðiþken
                
                    int xekseni[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // Vezirin x eksenindeki hareketleri
                    int yekseni[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // Vezirin y eksenindeki hareketleri
                    for (int k = 0; k < 8; ++k) { // Vezirin gidebileceði 8 yöne bak
                        int new_x = i + xekseni[k], new_y = j + yekseni[k]; // Yeni karenin koordinatlarýný hesapla
                        while (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8 && board[new_x][new_y] == nullptr) { // Kenara gidene kadar veya taþ bulana kadar boþ kareler üzerinde ayný yönde ilerle
                            
                            new_x += xekseni[k], new_y += yekseni[k]; // Yeni karenin koordinatlarýný güncelle
                        }
                        if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8 && board[new_x][new_y] != nullptr && board[new_x][new_y]->getName() == board[i][j]->getName()) { // Eðer yeni kare tahtanýn içinde ve rakip bir taþ varsa
                            catchPiece = board[new_x][new_y]; // Yiyebileceði taþ olarak ata
                            break; // Döngüden çýk
                        }
                    }
                    if (catchPiece != nullptr) { // Eðer yiyebileceði bir taþ varsa
                      
                        if (board[i][j]->getColor() == "WHITE") { // Eðer vezir beyaz ise
                            whiteScore += board[i][j]->getScore() / 2.0; // Beyaz puanýna vezirin puanýnýn yarýsýný ekle
                            blackScore -= catchPiece->getScore() / 2.0; // Siyah puanýndan yediði taþýn puanýnýn yarýsýný çýkar
                        }
                        else { // Eðer vezir siyah ise
                            blackScore += board[i][j]->getScore() / 2.0; // Siyah puanýna vezirin puanýnýn yarýsýný ekle
                            whiteScore -= catchPiece->getScore() / 2.0; // Beyaz puanýndan yediði taþýn puanýnýn yarýsýný çýkar
                        }
                    } else { // Eðer yiyebileceði bir taþ yoksa
                        // If the queen cannot capture, add the full score of the piece
                        if (board[i][j]->getColor() == "WHITE") whiteScore += board[i][j]->getScore(); // Beyaz puanýna vezirin tam puanýný ekle
                        else blackScore += board[i][j]->getScore(); // Siyah puanýna vezirin tam puanýný ekle
                    }
                } 
                else { // Eðer taþ bir piyon, at veya vezir deðilse
                   
                    if (board[i][j]->getColor() == "WHITE") whiteScore += board[i][j]->getScore(); // Beyaz puanýna taþýn tam puanýný ekle
                    else blackScore += board[i][j]->getScore(); // Siyah puanýna taþýn tam puanýný ekle
                }
            }
	}
}


	for (int i = 0; i < 8; ++i) {      // satýr ve sütunlarý gez boþ yerlere "--" koy
         for (int j = 0; j < 8; ++j) {
             if (board[i][j] != nullptr)
                 std::cout << board[i][j]->getName() << ' ';
             else
                 std::cout << "-- ";
         }
         std::cout << '\n';
     }
     
    
    
	std::cout<<std::endl;
    std::cout << "Beyaz Tas  Puan: " << whiteScore << std::endl;      // taþlarýn puanýný ekrana bastýrma
    std::cout << "Siyah Tas Puan: " << blackScore << std::endl;
    
      // taþlarý bellekten silmek için
     for (int i = 0; i < 8; ++i) {
         for (int j = 0; j < 8; ++j) {
             delete board[i][j];
         }
     }

    return 0;
}
