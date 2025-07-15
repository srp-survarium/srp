vostok::ai::sensors::damage_sensor *__thiscall vostok::ai::sensors::damage_sensor::`vector deleting destructor'(
        vostok::ai::sensors::damage_sensor *this,
        char a2)
{
  vostok::ai::sensors::damage_sensor::~damage_sensor(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
