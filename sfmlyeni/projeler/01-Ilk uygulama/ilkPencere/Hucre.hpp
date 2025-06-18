#pragma once
#include "Cizilebilir.hpp"

enum class HucreYon
{
	Sol,
	Sag,
	Yukari,
	Asagi
};

class Hucre :public Cizilebilir
{
public:
	Hucre();

	Hucre      hucreUret();
	void       yonAta(HucreYon yon);
	HucreYon   yonGetir();
	float      boyutGetir();
	void       boyutAta(float boyut);
	void       hizAta(float hiz);
	float      hizGetir();
	void konumAta(sf::Vector2f konum);
	sf::Vector2f konumGetir() const;

	void       hareket();

	void ciz(Pencere& pencere) override;
	void renkAta(const sf::Color& renk);

private:
	HucreYon             m_yon;
	sf::RectangleShape   m_sekil;
	float                m_boyut;
	float                m_hiz;
	sf::Vector2f         m_konum;

};
