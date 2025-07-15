survarium::object_volumetric_sound *__thiscall survarium::object_volumetric_sound::`scalar deleting destructor'(
        survarium::object_volumetric_sound *this,
        char a2)
{
  survarium::object_volumetric_sound::~object_volumetric_sound(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
