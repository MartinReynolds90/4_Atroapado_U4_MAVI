#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "iostream"

using namespace sf;
using namespace std;

int main() {
	RenderWindow ventana(VideoMode(800, 600), "Atrapado");
	Event evento;
	Sprite figura;

	Texture tx_cuadrado, tx_circulo;

	tx_cuadrado.loadFromFile("cuad_yellow.png");
	tx_circulo.loadFromFile("rcircleg.png");

	figura.setTexture(tx_cuadrado);
	figura.setScale(0.25f, 0.25f);

	while (ventana.isOpen()) {
		while (ventana.pollEvent(evento)) {
			if (figura.getPosition().x <= 0.0) {
				figura.setPosition(0.0, figura.getPosition().y);
			}
			if (figura.getPosition().x + 128 >= ventana.getSize().x) {
				figura.setPosition(ventana.getSize().x - 128, figura.getPosition().y);
			}
			if (figura.getPosition().y <= 0.0) {
				figura.setPosition(figura.getPosition().x, 0.0);
			}
			if (figura.getPosition().y + 128 >= ventana.getSize().y) {
				figura.setPosition(figura.getPosition().x, ventana.getSize().y - 128);
			}
			if (evento.type == Event::KeyPressed) {
				if (evento.key.code == Keyboard::D) {
					figura.move(10, 0);
				}
				if (evento.key.code == Keyboard::A) {
					figura.move(-10, 0);
				}
				if (evento.key.code == Keyboard::W) {
					figura.move(0, -10);
				}
				if (evento.key.code == Keyboard::S) {
					figura.move(0, 10);
				}
				if (evento.key.code == Keyboard::Space) {
					if (figura.getScale().x == 0.25f) {
						figura.setTexture(tx_circulo);
						figura.setScale(1.f, 1.f);
					}
					else {
						figura.setTexture(tx_cuadrado);
						figura.setScale(0.25f, 0.25f);
					}
				}
			}

		}
		ventana.clear(Color::Black);
		ventana.draw(figura);
		ventana.display();
	}
	return 0;
}