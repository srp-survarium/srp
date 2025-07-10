survarium::animated_model_instance *__thiscall survarium::animated_model_instance::`scalar deleting destructor'(
        survarium::animated_model_instance *this,
        char a2)
{
  survarium::animated_model_instance::~animated_model_instance(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
