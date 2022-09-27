#include <iostream>
#include <unordered_map>


struct Coordinates
{
  Coordinates();
  Coordinates(float latitude, float longitude, float altitude) : 
    _latitude(latitude), _longitude(longitude), _altitude(altitude) {};
  
  float _latitude;
  float _longitude;
  float _altitude;
};

struct Airport
{
  Airport(std::string city, std::string code, Coordinates coordinates):
  _city(city), _code(code), _coordinates(coordinates){}
  ~Airport();

  std::string _city;
  std::string _code;
  Coordinates _coordinates;
};

class Airports
{
public:
  Airports();
  Airports(std::string datafile) : _datafile(datafile){};

  inline const std::unordered_map<std::string, Airport>& getAirportMap(){return _airportMap;}
  inline const bool inMap(std::string& cityName)
  {
    return _airportMap.find(cityName) == _airportMap.end();
  }
  inline void printAirportMap()
  {
    for(auto&[code, airport]: _airportMap)
    {
      std::cout<<airport._city<< " (" <<airport._code<< ") " 
        <<airport._coordinates._latitude
        << ", " <<airport._coordinates._longitude
        << ", " <<airport._coordinates._altitude << "\n";
    }
  }

private:
  std::string _datafile;
  void readFile();
//code -> Airport
  std::unordered_map<std::string, Airport> _airportMap;

};