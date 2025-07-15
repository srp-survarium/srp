int __thiscall Scaleform::GFx::SwfShapeCharacterDef::NeedsResolving(Scaleform::GFx::SwfShapeCharacterDef *this)
{
  return (this->pShape.pObject->Flags >> 2) & 1;
}
