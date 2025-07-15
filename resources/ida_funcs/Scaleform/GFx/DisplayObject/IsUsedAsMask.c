int __thiscall Scaleform::GFx::DisplayObject::IsUsedAsMask(Scaleform::GFx::DisplayObject *this)
{
  return (this->Flags >> 2) & 1;
}
