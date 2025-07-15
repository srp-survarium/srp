Scaleform::GFx::AvmButtonBase *__thiscall Scaleform::GFx::AS3::AvmSprite::ToAvmDispContainerBase(
        Scaleform::GFx::AS3::AvmButton *this)
{
  if ( this )
    return &this->Scaleform::GFx::AvmButtonBase;
  else
    return 0;
}


Scaleform::GFx::AvmButtonBase *__thiscall Scaleform::GFx::AS3::AvmSprite::ToAvmDispContainerBase(
        Scaleform::GFx::AS3::AvmButton *this)
{
  return Scaleform::GFx::AS3::AvmSprite::ToAvmDispContainerBase(this - 1);
}
