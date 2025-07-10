void __thiscall Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(
        Scaleform::GFx::AS3::Multiname *this,
        const Scaleform::GFx::AS3::Value *nameVal)
{
  Scaleform::GFx::AS3::Value::V1U v3; // ecx
  int v4; // ecx
  Scaleform::GFx::AS3::Value *p_Name; // ecx
  unsigned int Flags; // edx

  if ( (nameVal->Flags & 0x1F) - 12 <= 3 )
  {
    v3 = nameVal->value.VS._1;
    if ( v3.VInt )
    {
      v4 = *(_DWORD *)(v3.VInt + 20);
      if ( *(_DWORD *)(v4 + 60) == 12 && (*(_DWORD *)(v4 + 56) & 0x20) == 0 )
      {
        Scaleform::GFx::AS3::Multiname::SetFromQName(this, nameVal);
        return;
      }
    }
  }
  p_Name = &this->Name;
  if ( nameVal != &this->Name )
  {
    Flags = nameVal->Flags;
    _mm_prefetch((const char *)nameVal, 2);
    p_Name->Flags = Flags;
    this->Name.Bonus.pWeakProxy = nameVal->Bonus.pWeakProxy;
    this->Name.value.VNumber = nameVal->value.VNumber;
    if ( (p_Name->Flags & 0x1F) > 9 )
    {
      if ( (p_Name->Flags & 0x200) != 0 )
      {
        ++this->Name.Bonus.pWeakProxy->RefCount;
        Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
        return;
      }
      Scaleform::GFx::AS3::Value::AddRefInternal(p_Name);
    }
  }
  Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
}
