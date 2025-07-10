SpeedTree::CDefaultCoordinateSystem *__thiscall SpeedTree::CDefaultCoordinateSystem::`scalar deleting destructor'(
        SpeedTree::CDefaultCoordinateSystem *this,
        char a2)
{
  this->__vftable = (SpeedTree::CDefaultCoordinateSystem_vtbl *)&SpeedTree::CDefaultCoordinateSystem::`vftable';
  this->__vftable = (SpeedTree::CDefaultCoordinateSystem_vtbl *)&SpeedTree::CCoordSysBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
