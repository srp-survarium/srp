SpeedTree::CRHCS_Yup *__thiscall SpeedTree::CRHCS_Yup::`vector deleting destructor'(
        SpeedTree::CRHCS_Yup *this,
        char a2)
{
  this->__vftable = (SpeedTree::CRHCS_Yup_vtbl *)&SpeedTree::CRHCS_Yup::`vftable';
  this->__vftable = (SpeedTree::CRHCS_Yup_vtbl *)&SpeedTree::CCoordSysBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
