#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Ferrum");
	
	while (App.IsOpened())
	{
		sf::Event Event;
		while (App.GetEvent(Event))
		{
			if ((Event.Type == sf::Event::Closed) || 
			   ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape)))
			{
				App.Close();
				break;
			}
		}
		
		App.Clear();
		App.Display();
	}
	
	return 0;
}
