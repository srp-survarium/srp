Scaleform::GFx::AvmButtonBase *__thiscall Scaleform::GFx::AS2::AvmSprite::ToAvmDispContainerBase(
        Scaleform::GFx::AS2::AvmButton *this)
{
  if ( this )
    return &this->Scaleform::GFx::AvmButtonBase;
  else
    return 0;
}


Scaleform::GFx::AvmButtonBase *__thiscall Scaleform::GFx::AS2::AvmSprite::ToAvmDispContainerBase(char *this)
{
  return Scaleform::GFx::AS2::AvmSprite::ToAvmDispContainerBase((Scaleform::GFx::AS2::AvmButton *)(this - 24));
}
