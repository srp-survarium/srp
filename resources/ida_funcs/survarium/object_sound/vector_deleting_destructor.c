survarium::object_sound *__thiscall survarium::object_sound::`vector deleting destructor'(
        survarium::object_sound *this,
        char a2)
{
  survarium::object_sound::~object_sound(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
