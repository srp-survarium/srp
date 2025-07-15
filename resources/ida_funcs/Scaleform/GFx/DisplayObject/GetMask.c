Scaleform::GFx::DisplayObject *__thiscall Scaleform::GFx::DisplayObject::GetMask(Scaleform::GFx::DisplayObject *this)
{
  if ( !this->pMaskCharacter || this->IsUsedAsMask(this) )
    return 0;
  else
    return this->pMaskCharacter;
}
