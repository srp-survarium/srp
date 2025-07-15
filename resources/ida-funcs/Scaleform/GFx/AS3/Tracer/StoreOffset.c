void __thiscall Scaleform::GFx::AS3::Tracer::StoreOffset(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned int bcp,
        const Scaleform::GFx::AS3::TR::State *st,
        int offset,
        int base)
{
  int v6; // ebp
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *v7; // esi
  int v8; // ebx
  unsigned int v9; // edi
  int *v10; // edx
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v12; // esi
  int *Data; // eax
  Scaleform::GFx::AS3::Tracer::Recalculate val; // [esp+10h] [ebp-8h] BYREF

  v6 = bcp + offset;
  if ( offset >= 0 )
  {
    Scaleform::GFx::AS3::Tracer::AddBlock(this, st, bcp + offset, tUnknown, (Scaleform::GFx::AS3::TR::State *)1);
    WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
    v12 = WCode->Size + 1;
    if ( v12 >= WCode->Size )
    {
      if ( v12 >= WCode->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          WCode,
          WCode,
          v12 + (v12 >> 2));
    }
    else if ( v12 < WCode->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        WCode->Size + 1);
    }
    Data = WCode->Data;
    WCode->Size = v12;
    Data[v12 - 1] = v6;
    val.pos = this->WCode->Data.Size - 1;
    val.base = base;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Tracer::Recalculate,Scaleform::AllocatorDH_POD<Scaleform::GFx::AS3::Tracer::Recalculate,328>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      &this->PosToRecalculate,
      &val);
  }
  else
  {
    v7 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
    v8 = base + this->Orig2newPosMap.Data.Data[v6] - v7->Size;
    v9 = v7->Size + 1;
    if ( v9 >= v7->Size )
    {
      if ( v9 >= v7->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v7,
          v7,
          v9 + (v9 >> 2));
    }
    else if ( v9 < v7->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v7,
        v7,
        v7->Size + 1);
    }
    v10 = v7->Data;
    v7->Size = v9;
    v10[v9 - 1] = v8;
  }
}
