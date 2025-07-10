vostok::ai::sensors::hearing_sensor *__thiscall vostok::ai::sensors::hearing_sensor::`scalar deleting destructor'(
        vostok::ai::sensors::hearing_sensor *this,
        char a2)
{
  vostok::ai::sensors::hearing_sensor::~hearing_sensor(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
