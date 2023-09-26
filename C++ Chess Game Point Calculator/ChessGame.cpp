#include <iostream>
#include <string>

class Chessman {		// Chessman ad�nda bir base class
protected:            // T�retilmi� s�n�flardan color a eri�mek i�in
    std::string color;
public:
    Chessman(std::string color) : color(color) {}   	// Ta��n rengini parametre alan kurucu fonksiyon
    virtual int getScore() = 0;          		 // Ta��n puan�n� d�nd�rmek i�in sanal fonksiyon
    std::string getColor() { return color; } 	 // Ta��n rengi i�in sanal fonksiyon
    virtual std::string getName() = 0; 			// Ta��n ad�n� d�nd�ren bir fonksiyon ekledim
};

class Knight : public Chessman {  // At ta�� i�in bir s�n�f , Chessman'den kal�t�m al�yor
public:
    Knight(std::string color) : Chessman(color) {} // rengi parametre alan kurucu fonksiyon
    int getScore() override {		//Base classtaki sanal fonksiyonu ge�ersiz k�lmak i�in override i�lemi , puan� geri d�nd�rmek i�in
        return 3;                  //At�n puan� 3
    }
    std::string getName() override {
        return color == "WHITE" ? "ab" : "as";     // Ta� beyaz ise ab d�nd�r de�ilse as d�nd�r
    }
};

class King : public Chessman {		// �ah ta�� i�in bir s�n�f , Chessman'den kal�t�m al�yor
public:
    King(std::string color) : Chessman(color) {}   // rengi parametre alan kurucu fonksiyon
    int getScore() override {			//Base classtaki sanal fonksiyonu ge�ersiz k�lmak i�in override i�lemi , puan� geri d�nd�rmek i�in
        return 100;      
    }
    std::string getName() override {				
        return color == "WHITE" ? "sb" : "ss";      // Ta� beyaz ise sb d�nd�r de�ilse ss d�nd�r
    }
};

class Bishop : public Chessman{    // Fil Ta��
	public:
	Bishop(std::string color) : Chessman (color){	}  // kurucu fonksiyon
	int getScore() override {                          // puan� geri d�nd�rmek i�in override
	 return 3;
	}
	std::string getName() override{
		return color == "WHITE" ? "fb" : "fs";      	// Ta� beyaz ise fb d�nd�r de�ilse fs d�nd�r
	}	
};

class Queen : public Chessman {   // Vezir Ta�� kal�t�m
public:
    Queen(std::string color) : Chessman(color) {} // kurucu fonksiyon
    int getScore() override {						//virtual� iptal etmek i�in puan� d�nd�ren override
        return 9;
    }
    std::string getName() override {
        return color == "WHITE" ? "vb" : "vs";      // Ta� beyaz ise vb d�nd�r de�ilse vs d�nd�r
    }
};

class Pawn : public Chessman {    // Piyon Ta��
public:
    Pawn(std::string color) : Chessman(color) {}
    int getScore() override {
        return 1;
    }
    std::string getName() override {
        return color == "WHITE" ? "pb" : "ps";		// Ta� beyaz ise pb d�nd�r de�ilse ps d�nd�r
    }
};

class Rook : public Chessman {       // Kale Ta��
	public:
		Rook(std::string color) : Chessman (color){}  // Renk i�in kurucu fonksiyon
		int getScore() override {
			return 5 ;
		}		
	std::string getName() override {
		return color == "WHITE" ? "kb" : "ks" ;     // Ta� beyaz ise kb d�nd�r de�ilse ks d�nd�r
	}
	};

int main() {
    Chessman* board[8][8] = {nullptr};  // 8x8 boyutunda array satran� tahtas� (Chessman tipinde pointer)

	
	
	
	//board 1 dizilimi
	// Rook = Kale , Knight = At , Bishop = Fil , Queen = Vezir , King = �ah , Pawn = Piyon , 
	board[0][0] = new Rook("BLACK");  //sol en �ste vezir nesnesini yerle�tir,bellekten yer ayur
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
    board[0][0] = new Queen("WHITE");   //sol en �ste vezir nesnesini yerle�tir,bellekten yer ayur
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
 
    for (int i = 0; i < 8; ++i) {  						// 8x8 matrisin sat�rlar�n� gezmek i�in
        for (int j = 0; j < 8; ++j) {					// 8x8 matrisin s�tunlar�n� gezmek i�in
            if (board[i][j] != nullptr) {				// bulundu�u karede ta� var m� yok mu (e�er null de�ilse d�ng�ye devam et)
                
                if (board[i][j]->getName() == "pb" || board[i][j]->getName() == "ps") {      	// ta� piyon beyaz veya piyon siyah m�
                    Chessman* catchPiece = nullptr;										// yiyebilece�imiz ta� var m� diye bakmak i�in
                  //E�er piyon beyaz ise sol �st �apraza ve sa� �st �apraza bak
                  //yiyebilece�i ta� varsa catchPiece e ata     board[0][0] = sol en �st   ,board[7][7] = sa� en alt                  
                    if (board[i][j]->getColor() == "WHITE") {
                        if (i > 0 && j > 0 && board[i-1][j-1] != nullptr && board[i-1][j-1]->getName() == "ps") catchPiece = board[i-1][j-1];// sol �st �aprazda ta� varsa yiyebilece�i ta� olarak ata 
                        if (i > 0 && j < 7 && board[i-1][j+1] != nullptr && board[i-1][j+1]->getName() == "ps") catchPiece = board[i-1][j+1];//sa� �st �apraz
                    }
                    else {	//e�er piyon siyahsa solt alt �apraza ve sa� alt �apraz�na bak
                        if (i < 7 && j > 0 && board[i+1][j-1] != nullptr && board[i+1][j-1]->getName() == "pb") catchPiece = board[i+1][j-1];// e�er sol alt �aprazda beyaz ta� varsa yiyebilece�i ta� olarak ata
                        if (i < 7 && j < 7 && board[i+1][j+1] != nullptr && board[i+1][j+1]->getName() == "pb") catchPiece = board[i+1][j+1];// sa� alt �apraz
                    }
                    if (catchPiece != nullptr) {										// yiyebilece�imiz bir ta� varsa (null de�ilse)
                        if (board[i][j]->getColor() == "WHITE") {						// ta� beyazsa yedi�i ta� puan�n�n yar�s�n� beyaza ekle , siyahtan d���r.
                            whiteScore += board[i][j]->getScore() / 2.0;
                            blackScore -= catchPiece->getScore() / 2.0;
                        }
                        else {															// ta� siyahsa yedi�i ta� puan�n�n yar�s�n� siyaha ekle , beyazdan d���r.
                            blackScore += board[i][j]->getScore() / 2.0;
                            whiteScore -= catchPiece->getScore() / 2.0;
                        }
                    } else {																			// E�er piyonun yiyebilece�i bir ta� yoksa
                        if (board[i][j]->getColor() == "WHITE") whiteScore += board[i][j]->getScore();  // Beyaz puan�na piyonun tam puan�n� ekle
                        else blackScore += board[i][j]->getScore();										// Siyah puan�na piyonun tam puan�n� ekle
                    }
                } 
               
                else if (board[i][j]->getName() == "ab" || board[i][j]->getName() == "as") {	//E�er ta� at beaz veya at siyah ise
                    Chessman* catchPiece = nullptr;										// yiyebilece�i bir ta� var m� diye tutan de�i�ken
                    
                    int xekseni[] = {-2, -1, 1, 2, 2, 1, -1, -2};     // At�n x eksenindeki hareketleri
                    int yekseni[] = {1, 2, 2, 1, -1, -2, -2, -1};	// At�n y eksenindeki hareketleri
                    for (int k = 0; k < 8; ++k) {				// At�n gidebilece�i 8 kare oldu�u i�in 8 kere d�ng�
                        int nx = i + xekseni[k], ny = j + yekseni[k];		// yeni karenin koordinatlar�	
                        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] != nullptr && board[nx][ny]->getName() == board[i][j]->getName()) { // E�er yeni kare tahtan�n i�inde ve rakip bir ta� varsa
                            catchPiece = board[nx][ny];   		// Yiyebilece�i ta� olarak ata
                            break; // d�ng�den ��k
                        }
                    }
                    if (catchPiece != nullptr) {				// E�er yiyebilece�i bir ta� varsa
                      
                        if (board[i][j]->getColor() == "WHITE") { // at beyazsa
                            whiteScore += board[i][j]->getScore() / 2.0;  	// // Beyaz puan�na at�n puan�n�n yar�s�n� ekle
                            blackScore -= catchPiece->getScore() / 2.0; 	//// Siyah puan�ndan yedi�i ta��n puan�n�n yar�s�n� ��kar
                        }
                        else {		 // E�er at siyah ise
                            blackScore += board[i][j]->getScore() / 2.0;  // Siyah puan�na at�n puan�n�n yar�s�n� ekle
                            whiteScore -= catchPiece->getScore() / 2.0;  // Beyaz puan�ndan yedi�i ta��n puan�n�n yar�s�n� ��kar
                        }
                    } else {  // E�er yiyebilece�i bir ta� yoksa
                       
                        if (board[i][j]->getColor() == "WHITE") whiteScore += board[i][j]->getScore();  // Beyaz puan�na at�n tam puan�n� ekle
                        else blackScore += board[i][j]->getScore(); // Siyah puan�na at�n tam puan�n� ekle
                    }
                } 
                else if (board[i][j]->getName() == "vb" || board[i][j]->getName() == "vs") { // E�er ta� beyaz vezir veya siyah vezirse
                    Chessman* catchPiece = nullptr; // Yiyebilece�i bir ta� olup olmad���n� tutan de�i�ken
                
                    int xekseni[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // Vezirin x eksenindeki hareketleri
                    int yekseni[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // Vezirin y eksenindeki hareketleri
                    for (int k = 0; k < 8; ++k) { // Vezirin gidebilece�i 8 y�ne bak
                        int new_x = i + xekseni[k], new_y = j + yekseni[k]; // Yeni karenin koordinatlar�n� hesapla
                        while (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8 && board[new_x][new_y] == nullptr) { // Kenara gidene kadar veya ta� bulana kadar bo� kareler �zerinde ayn� y�nde ilerle
                            
                            new_x += xekseni[k], new_y += yekseni[k]; // Yeni karenin koordinatlar�n� g�ncelle
                        }
                        if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8 && board[new_x][new_y] != nullptr && board[new_x][new_y]->getName() == board[i][j]->getName()) { // E�er yeni kare tahtan�n i�inde ve rakip bir ta� varsa
                            catchPiece = board[new_x][new_y]; // Yiyebilece�i ta� olarak ata
                            break; // D�ng�den ��k
                        }
                    }
                    if (catchPiece != nullptr) { // E�er yiyebilece�i bir ta� varsa
                      
                        if (board[i][j]->getColor() == "WHITE") { // E�er vezir beyaz ise
                            whiteScore += board[i][j]->getScore() / 2.0; // Beyaz puan�na vezirin puan�n�n yar�s�n� ekle
                            blackScore -= catchPiece->getScore() / 2.0; // Siyah puan�ndan yedi�i ta��n puan�n�n yar�s�n� ��kar
                        }
                        else { // E�er vezir siyah ise
                            blackScore += board[i][j]->getScore() / 2.0; // Siyah puan�na vezirin puan�n�n yar�s�n� ekle
                            whiteScore -= catchPiece->getScore() / 2.0; // Beyaz puan�ndan yedi�i ta��n puan�n�n yar�s�n� ��kar
                        }
                    } else { // E�er yiyebilece�i bir ta� yoksa
                        // If the queen cannot capture, add the full score of the piece
                        if (board[i][j]->getColor() == "WHITE") whiteScore += board[i][j]->getScore(); // Beyaz puan�na vezirin tam puan�n� ekle
                        else blackScore += board[i][j]->getScore(); // Siyah puan�na vezirin tam puan�n� ekle
                    }
                } 
                else { // E�er ta� bir piyon, at veya vezir de�ilse
                   
                    if (board[i][j]->getColor() == "WHITE") whiteScore += board[i][j]->getScore(); // Beyaz puan�na ta��n tam puan�n� ekle
                    else blackScore += board[i][j]->getScore(); // Siyah puan�na ta��n tam puan�n� ekle
                }
            }
	}
}


	for (int i = 0; i < 8; ++i) {      // sat�r ve s�tunlar� gez bo� yerlere "--" koy
         for (int j = 0; j < 8; ++j) {
             if (board[i][j] != nullptr)
                 std::cout << board[i][j]->getName() << ' ';
             else
                 std::cout << "-- ";
         }
         std::cout << '\n';
     }
     
    
    
	std::cout<<std::endl;
    std::cout << "Beyaz Tas  Puan: " << whiteScore << std::endl;      // ta�lar�n puan�n� ekrana bast�rma
    std::cout << "Siyah Tas Puan: " << blackScore << std::endl;
    
      // ta�lar� bellekten silmek i�in
     for (int i = 0; i < 8; ++i) {
         for (int j = 0; j < 8; ++j) {
             delete board[i][j];
         }
     }

    return 0;
}
