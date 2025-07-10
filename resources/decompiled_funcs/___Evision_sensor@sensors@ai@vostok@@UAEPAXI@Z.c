vostok::ai::sensors::vision_sensor *__thiscall vostok::ai::sensors::vision_sensor::`vector deleting destructor'(
        vostok::ai::sensors::vision_sensor *this,
        char a2)
{
  vostok::ai::sensors::vision_sensor::~vision_sensor(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
