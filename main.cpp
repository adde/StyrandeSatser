#include <iostream>

using namespace std;

int main() 
{
	int day = 24*60*60,
		startNumber = 1, 
		startTime = 0, 
		endTime = 0, 
		totalTime = 0, 
		nrOfParticipants = 0,
		winnerStartNumber = 0,
		winnerTotalTime = 0,
		h = 0, m = 0, s = 0;

	while(startNumber > 0)
	{
		cout << "Startnummer: " << endl;
		cin >> startNumber;

		if(startNumber < 1) 
		{
			break;
		}

		cout << "Starttid: " << endl;
		cin >> h >> m >> s;
		startTime = (h*60*60) + (m*60) + s;

		cout << "Måltid: " << endl;
		cin >> h >> m >> s;
		endTime = (h*60*60) + (m*60) + s;

		if(endTime < startTime) 
		{
			totalTime = endTime+(day) - startTime;
		}
		else
		{
			totalTime = endTime - startTime;
		}

		if(winnerStartNumber == 0) 
		{
			winnerStartNumber = startNumber;
			winnerTotalTime = totalTime;
		}
		else 
		{
			if(totalTime < winnerTotalTime)
			{
				winnerStartNumber = startNumber;
				winnerTotalTime = totalTime;
			}
		}

		nrOfParticipants++;
	}

	h = winnerTotalTime/3600;
	winnerTotalTime = winnerTotalTime%3600;
	m = winnerTotalTime/60;
	winnerTotalTime = winnerTotalTime%60;
	s = winnerTotalTime;

	cout << "Vinnare är startnr: " << winnerStartNumber << endl;
	cout << "Tim: " << h << " Min: " << m << " Sek: " << s << endl;
	cout << "Antal tävlande: " << nrOfParticipants << endl;

	system("pause");
	return 0;
}