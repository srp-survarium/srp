survarium::hit_initiator *__thiscall survarium::hit_initiator::`scalar deleting destructor'(
        survarium::hit_initiator *this,
        char a2)
{
  this->__vftable = (survarium::hit_initiator_vtbl *)&survarium::hit_initiator::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
