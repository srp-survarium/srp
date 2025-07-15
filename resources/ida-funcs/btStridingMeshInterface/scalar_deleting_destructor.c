btStridingMeshInterface *__thiscall btStridingMeshInterface::`scalar deleting destructor'(
        btStridingMeshInterface *this,
        char a2)
{
  this->__vftable = (btStridingMeshInterface_vtbl *)&btStridingMeshInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
