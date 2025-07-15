survarium::damage_model *__thiscall survarium::damage_model::`vector deleting destructor'(
        survarium::damage_model *this,
        char a2)
{
  survarium::damage_model::~damage_model(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
