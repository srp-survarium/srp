int __thiscall Scaleform::GFx::DisplayObject::GetContinueAnimationFlag(Scaleform::GFx::DisplayObject *this)
{
  return (this->Flags >> 4) & 1;
}
