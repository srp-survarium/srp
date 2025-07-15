BOOL __thiscall Scaleform::GFx::AS3::Multiname::IsRunTime(Scaleform::GFx::AS3::Multiname *this)
{
  return (this->Kind & 3) == 1 || (this->Kind & 4) != 0;
}
