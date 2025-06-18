#include "Yilan.hpp"
#include "Pencere.hpp"
#include <random>
#include <iostream>

Yilan::Yilan()
{
    m_yeniYon = HucreYon::Sag;
    m_alinanMesafe = 0.0f;
}

void Yilan::ayarla(float hucreBoyut, float pencereGenislik, float pencereYukseklik)
{
    m_hucreler.clear();
    m_pencereGenislik = pencereGenislik;
    m_pencereYukseklik = pencereYukseklik;
    m_hucreBoyut = hucreBoyut;

    m_yeniYon = HucreYon::Sag;
    m_alinanMesafe = 0.0f;

    kuyrugaEkle();
    kuyrugaEkle();
    kuyrugaEkle();
    kuyrugaEkle();

    yemiYenile();
}

void Yilan::kuyrugaEkle()
{
    Hucre yeniHucre;

    if (!m_hucreler.empty())
    {
        
        yeniHucre = m_hucreler.back().hucreUret();
    }
    else
    {
        yeniHucre.konumAta(sf::Vector2f(200.f, 200.f));
        yeniHucre.yonAta(m_yeniYon);
        yeniHucre.hizAta(m_hucreBoyut / 10.f);
    }

    yeniHucre.boyutAta(m_hucreBoyut);
    m_hucreler.push_back(yeniHucre);
}

void Yilan::hareket()
{
    for (auto& hucre : m_hucreler)
    {
        hucre.hareket();
    }

    m_alinanMesafe += m_hucreler[0].hizGetir();

    if (m_alinanMesafe >= m_hucreler[0].boyutGetir())
    {
        
        for (int i = static_cast<int>(m_hucreler.size()) - 1; i > 0; --i)
        {
            m_hucreler[i].yonAta(m_hucreler[i - 1].yonGetir());
        }

        m_hucreler[0].yonAta(m_yeniYon);
        m_alinanMesafe = 0.0f;

        yemKontrol();  
    }
}

void Yilan::yemKontrol()
{
    if (m_hucreler.empty()) return;

    sf::Vector2f basKonum = m_hucreler[0].konumGetir();
    sf::Vector2f yemKonum = m_yem.konumGetir();

    if (basKonum == yemKonum)
    {
        kuyrugaEkle();
        yemiYenile();
    }
}

void Yilan::yonAta(HucreYon yenYon)
{
    m_yeniYon = yenYon;
}

void Yilan::sifirla()
{
    m_hucreler.clear();
    m_yeniYon = HucreYon::Sag;
    m_alinanMesafe = 0.0f;
    ayarla(m_hucreBoyut, m_pencereGenislik, m_pencereYukseklik);
}

void Yilan::ciz(Pencere& pencere)
{
    pencere.ciz(m_yemSembol);

    for (auto& hucre : m_hucreler)
    {
        hucre.ciz(pencere);
    }
}

void Yilan::yemiYenile()
{
    if (m_hucreler.empty()) return;

    int sutunSayisi = m_pencereGenislik / m_hucreBoyut;
    int satirSayisi = m_pencereYukseklik / m_hucreBoyut;

    float x = (std::rand() % sutunSayisi) * m_hucreBoyut;
    float y = (std::rand() % satirSayisi) * m_hucreBoyut;

    m_yem.konumAta(sf::Vector2f(x, y));
    m_yem.boyutAta(m_hucreBoyut);
    m_yem.renkAta(sf::Color::Transparent); 

   
    if (!m_font.loadFromFile("C:/Users/Lenovo/Desktop/sfmlyeni/bin/x64/Debug/seguiemj.ttf"))
    {
        std::cerr << "Yazı tipi yüklenemedi!\n";
        return;
    }

    m_yemSembol.setFont(m_font);
    m_yemSembol.setString(L"\u25CF"); 
    m_yemSembol.setCharacterSize(static_cast<unsigned int>(m_hucreBoyut));
    m_yemSembol.setFillColor(sf::Color::Red);
    m_yemSembol.setPosition(x, y);
}
bool Yilan::carptiMi() const
{
  
    sf::Vector2f basKonum = m_hucreler[0].konumGetir();
    if (basKonum.x < 0 || basKonum.x >= m_pencereGenislik ||
        basKonum.y < 0 || basKonum.y >= m_pencereYukseklik)
    {
        return true;
    }

  
    for (size_t i = 1; i < m_hucreler.size(); ++i)
    {
        if (m_hucreler[i].konumGetir() == basKonum)
        {
            return true;
        }
    }

    return false;
}