Scaleform::DefaultAmpServer *__thiscall Scaleform::AmpServer::`scalar deleting destructor'(
        Scaleform::DefaultAmpServer *this,
        char a2)
{
  this->__vftable = (Scaleform::DefaultAmpServer_vtbl *)&Scaleform::AmpServer::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
