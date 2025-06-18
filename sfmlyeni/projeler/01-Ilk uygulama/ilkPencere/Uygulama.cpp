#include "Uygulama.hpp"
#include "OyunSonuEkrani.hpp"
#include <iostream>

Uygulama::Uygulama()
{
    m_oyunBitti = false;  
}

void Uygulama::insaEt(int genislik, int yukseklik)
{

    if (!m_muzik.openFromFile("C:/Users/Lenovo/Desktop/sfmlyeni/bin/x64/Debug/No-Rush-Dyalla.ogg")) {
        std::cerr << "Müzik yüklenemedi!\n";
    }
    else {
        m_muzik.setLoop(true);
        m_muzik.play();
    }

    m_pencereGenislik = genislik;
    m_pencereYukseklik = yukseklik;

    m_pencere.olustur(genislik, yukseklik);
    m_izgara.ayarla(genislik, 50);
    m_yilan.ayarla(50, genislik, yukseklik);
    m_oyunSonuEkrani.ayarla(genislik, yukseklik);

    m_pencere.fareHareketFonksiyonuEkle(
        std::bind(&Uygulama::fareHareket, this, std::placeholders::_1));
    m_pencere.fareTiklanmaFonksiyonuEkle(
        std::bind(&Uygulama::fareTiklandi, this, std::placeholders::_1));
    m_pencere.tusaBasFonksiyonuEkle(
        std::bind(&Uygulama::tusBasildi, this, std::placeholders::_1));
    m_pencere.tusuBirakFonksiyonuEkle(
        std::bind(&Uygulama::tusBirakildi, this, std::placeholders::_1));
}

void Uygulama::baslat(int fps)
{
    float cerfps = 1.0f / fps;
    m_cerceveSuresi = sf::seconds(cerfps);
    m_gecenSure = m_saat.restart();

    while (m_pencere.pencereAcikmi())
    {
        m_pencere.olaylariIsle();

        if (m_oyunBitti)
        {
            m_pencere.temizle();
            m_oyunSonuEkrani.ciz(m_pencere);
            m_pencere.goster();
            continue;
        }

        m_gecenSure = m_saat.getElapsedTime();

        if (m_gecenSure >= m_cerceveSuresi)
        {
            cerceveOlustur();
            m_gecenSure = sf::seconds(0.0f);
            m_saat.restart();
        }
        else
        {
            sf::sleep(m_cerceveSuresi - m_gecenSure);
        }
    }
}

void Uygulama::cerceveOlustur()
{
    sahneGuncelle();
    cizimFonksiyonu();
}

void Uygulama::cizimFonksiyonu()
{
    m_pencere.temizle();
    m_izgara.ciz(m_pencere);
    m_yilan.ciz(m_pencere);
    m_pencere.goster();
}

void Uygulama::sahneGuncelle()
{
    if (!m_oyunBitti)
    {
        m_yilan.hareket();

        if (m_yilan.carptiMi())
        {
            m_oyunBitti = true;
            m_muzik.stop();
        }
    }
}

void Uygulama::tusBasildi(sf::Keyboard::Key tus)
{
    if (tus == sf::Keyboard::Left)
        m_yilan.yonAta(HucreYon::Sol);
    if (tus == sf::Keyboard::Right)
        m_yilan.yonAta(HucreYon::Sag);
    if (tus == sf::Keyboard::Up)
        m_yilan.yonAta(HucreYon::Yukari);
    if (tus == sf::Keyboard::Down)
        m_yilan.yonAta(HucreYon::Asagi);
    if (tus == sf::Keyboard::Space)
        m_yilan.kuyrugaEkle();
}

void Uygulama::tusBirakildi(sf::Keyboard::Key tus)
{
    
}

void Uygulama::fareHareket(sf::Event::MouseMoveEvent olay)
{
   
}

void Uygulama::fareTiklandi(sf::Event::MouseButtonEvent olay)
{
    if (m_oyunBitti)
    {
        sf::Vector2f tiklamaKonumu(static_cast<float>(olay.x), static_cast<float>(olay.y));
        if (m_oyunSonuEkrani.tiklamaDenetle(tiklamaKonumu))
        {
            if (m_oyunSonuEkrani.tekrarDeneSecildi())
            {
                m_yilan.sifirla(); 
                m_oyunBitti = false;
                m_muzik.play();
            }
            else
            {
                m_pencere.kapat(); 
            }
        }
    }
}