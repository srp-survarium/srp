void __thiscall Scaleform::GFx::AS3::Tracer::PopNewOpCode(Scaleform::GFx::AS3::Tracer *this)
{
  unsigned int v2; // edi
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // esi

  v2 = this->NewOpcodePos.Data.Data[this->NewOpcodePos.Data.Size - 1];
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy>>::Pop(&this->NewOpcodePos);
  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
  if ( v2 >= WCode->Size )
  {
    if ( v2 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v2 + (v2 >> 2));
  }
  else if ( v2 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      v2);
    WCode->Size = v2;
    return;
  }
  WCode->Size = v2;
}
