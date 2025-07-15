survarium::carryable_object *__thiscall survarium::carryable_object::`scalar deleting destructor'(
        survarium::carryable_object *this,
        char a2)
{
  survarium::usable_object::~usable_object(&this->survarium::usable_object);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
