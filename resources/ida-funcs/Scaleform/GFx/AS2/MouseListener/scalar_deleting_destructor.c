Scaleform::GFx::AS2::MouseListener *__thiscall Scaleform::GFx::AS2::MouseListener::`scalar deleting destructor'(
        Scaleform::GFx::AS2::MouseListener *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS2::MouseListener_vtbl *)&Scaleform::GFx::AS2::MouseListener::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
