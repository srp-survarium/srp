SpeedTree::CLHCS_Yup *__thiscall SpeedTree::CLHCS_Yup::`scalar deleting destructor'(
        SpeedTree::CLHCS_Yup *this,
        char a2)
{
  this->__vftable = (SpeedTree::CLHCS_Yup_vtbl *)&SpeedTree::CLHCS_Yup::`vftable';
  this->__vftable = (SpeedTree::CLHCS_Yup_vtbl *)&SpeedTree::CCoordSysBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
