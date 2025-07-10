BOOL __thiscall Scaleform::GFx::MorphCharacterDef::NeedsResolving(Scaleform::GFx::MorphCharacterDef *this)
{
  return (this->pShape1.pObject->Flags & 4) != 0 || (this->pShape2.pObject->Flags & 4) != 0;
}
