SpeedTree::CCoordSysBase *__thiscall SpeedTree::CCoordSysBase::`scalar deleting destructor'(
        SpeedTree::CCoordSysBase *this,
        char a2)
{
  this->__vftable = (SpeedTree::CCoordSysBase_vtbl *)&SpeedTree::CCoordSysBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
