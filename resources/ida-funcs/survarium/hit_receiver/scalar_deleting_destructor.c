survarium::hit_receiver *__thiscall survarium::hit_receiver::`scalar deleting destructor'(
        survarium::hit_receiver *this,
        char a2)
{
  this->__vftable = (survarium::hit_receiver_vtbl *)&survarium::hit_receiver::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
