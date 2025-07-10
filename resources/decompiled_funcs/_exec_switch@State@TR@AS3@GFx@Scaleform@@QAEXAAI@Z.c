void __thiscall Scaleform::GFx::AS3::TR::State::exec_switch(Scaleform::GFx::AS3::TR::State *this, unsigned int *bcp)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // esi
  unsigned int CurrOffset; // ebx
  int v6; // eax
  int v7; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // ecx
  unsigned int v9; // ebx
  int i; // ebx
  int v11; // eax
  int case_count; // [esp+10h] [ebp-8h]
  unsigned int base_location; // [esp+14h] [ebp-4h]
  unsigned int *bcpa; // [esp+1Ch] [ebp+4h]

  pTracer = this->pTracer;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  CurrOffset = pTracer->CurrOffset;
  base_location = CurrOffset;
  v6 = Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(pTracer->pCode, bcp);
  Scaleform::GFx::AS3::Tracer::StoreOffset(pTracer, *bcp, this, CurrOffset + v6 - *bcp, 1);
  v7 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pTracer->pCode, bcp);
  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)pTracer->WCode;
  v9 = WCode->Size + 1;
  case_count = v7;
  bcpa = (unsigned int *)WCode;
  if ( v9 >= WCode->Size )
  {
    if ( v9 < WCode->Policy.Capacity )
      goto LABEL_7;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      v9 + (v9 >> 2));
  }
  else
  {
    if ( v9 >= WCode->Policy.Capacity >> 1 )
      goto LABEL_7;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      v9);
  }
  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)bcpa;
LABEL_7:
  WCode->Size = v9;
  WCode->Data[v9 - 1] = case_count;
  for ( i = 0; i <= case_count; ++i )
  {
    v11 = Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(pTracer->pCode, bcp);
    Scaleform::GFx::AS3::Tracer::StoreOffset(pTracer, *bcp, this, base_location + v11 - *bcp, i + 3);
  }
  Scaleform::GFx::AS3::Tracer::AddBlock(pTracer, this, *bcp, tDead, (Scaleform::GFx::AS3::TR::State *)1);
}
