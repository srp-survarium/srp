Scaleform::GFx::AS3::FlashUI *__thiscall Scaleform::GFx::AMP::SocketImplFactory::`scalar deleting destructor'(
        Scaleform::GFx::AS3::FlashUI *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::FlashUI_vtbl *)&Scaleform::GFx::AMP::SocketImplFactory::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
