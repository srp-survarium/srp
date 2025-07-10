int __thiscall Scaleform::GFx::DisplayObjectBase::GetVisible(Scaleform::GFx::DisplayObjectBase *this)
{
  return (this->Flags >> 14) & 1;
}
