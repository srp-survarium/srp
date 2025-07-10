SpeedTree::CLHCS_Zup *__thiscall SpeedTree::CLHCS_Zup::`scalar deleting destructor'(
        SpeedTree::CLHCS_Zup *this,
        char a2)
{
  this->__vftable = (SpeedTree::CLHCS_Zup_vtbl *)&SpeedTree::CLHCS_Zup::`vftable';
  this->__vftable = (SpeedTree::CLHCS_Zup_vtbl *)&SpeedTree::CCoordSysBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
