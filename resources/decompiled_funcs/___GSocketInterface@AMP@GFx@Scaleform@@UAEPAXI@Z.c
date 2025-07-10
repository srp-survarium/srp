Scaleform::GFx::AMP::SocketInterface *__thiscall Scaleform::GFx::AMP::SocketInterface::`scalar deleting destructor'(
        Scaleform::GFx::AMP::SocketInterface *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AMP::SocketInterface_vtbl *)&Scaleform::GFx::AMP::SocketInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
