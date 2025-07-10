survarium::usable_object *__thiscall survarium::ladder::ladder_occluder::`vector deleting destructor'(
        survarium::usable_object *this,
        char a2)
{
  survarium::usable_object::~usable_object(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
