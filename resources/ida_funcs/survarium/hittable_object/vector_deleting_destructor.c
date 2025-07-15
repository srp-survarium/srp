survarium::hittable_object *__thiscall survarium::hittable_object::`vector deleting destructor'(
        survarium::hittable_object *this,
        char a2)
{
  survarium::hittable_object::~hittable_object(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
