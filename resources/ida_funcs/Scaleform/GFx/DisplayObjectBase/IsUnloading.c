BOOL __thiscall Scaleform::GFx::DisplayObjectBase::IsUnloading(Scaleform::GFx::DisplayObjectBase *this)
{
  return (this->Flags & 0x1000) != 0 || this->Depth < -1;
}
