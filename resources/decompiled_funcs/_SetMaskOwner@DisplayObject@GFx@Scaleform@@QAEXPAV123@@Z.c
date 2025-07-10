void __thiscall Scaleform::GFx::DisplayObject::SetMaskOwner(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::DisplayObject *pmaskOwner)
{
  if ( this->pMaskCharacter && !this->IsUsedAsMask(this) && this->pMaskCharacter )
    Scaleform::GFx::DisplayObject::SetMask(this, 0);
  this->pMaskCharacter = pmaskOwner;
  if ( pmaskOwner )
    this->Flags |= 4u;
  else
    this->Flags &= ~4u;
}
