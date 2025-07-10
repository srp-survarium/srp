survarium::ladder_cook *__thiscall survarium::ladder_cook::`vector deleting destructor'(
        survarium::ladder_cook *this,
        char a2)
{
  survarium::ladder_cook::~ladder_cook(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
