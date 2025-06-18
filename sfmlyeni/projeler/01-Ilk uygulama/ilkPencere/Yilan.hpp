#pragma once
#include "Hucre.hpp"
#include <SFML/Graphics.hpp>

class Yilan : public Cizilebilir
{
public:
	Yilan();
	void ayarla(float hucreBoyut,
		float pencereGenislik,
		float pencereYukseklik);
	void kuyrugaEkle();
	void hareket();
	void yemKontrol();
	bool carptiMi() const;
	void yonAta(HucreYon yenYon);
	void sifirla();
	void ciz(Pencere& pencere) override;
private:
	void          yemiYenile();
	Hucre               m_yem;
	std::vector<Hucre>  m_hucreler;
	float               m_alinanMesafe;
	float               m_hucreBoyut;
	float               m_pencereGenislik;
	float               m_pencereYukseklik;

	HucreYon            m_yeniYon;

	sf::Font m_font;
	sf::Text m_yemSembol;
};