BOOL __thiscall Scaleform::GFx::AS3::Multiname::IsAnyNamespace(Scaleform::GFx::AS3::Multiname *this)
{
  return (this->Kind & 3u) <= 1 && !this->Obj.pObject;
}
