bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::GFx::AS3::Abc::MethodTable *mt,
        int obj)
{
  Scaleform::GFx::AS3::Abc::Reader *v4; // edi
  unsigned int v5; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *v6; // esi
  int v7; // ebx
  int v8; // ebp
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v9; // eax
  int v10; // eax
  int v11; // ebx
  unsigned int v12; // edi
  int *Data; // edx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v14; // edi
  bool result; // al
  unsigned int Size; // edx
  void *v17; // edi
  unsigned int v18; // eax
  unsigned int v19; // edi
  int count; // [esp+14h] [ebp-4h]

  v4 = this;
  v5 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  v6 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)obj;
  v7 = v5;
  count = v5;
  if ( v5 > *(_DWORD *)(obj + 8) )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)obj,
      (const void *)obj,
      v5);
  v8 = 0;
  if ( v7 <= 0 )
    return 1;
  while ( 1 )
  {
    obj = 338;
    v9 = (Scaleform::GFx::AS3::Abc::MethodBodyInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       v4,
                                                       52,
                                                       &obj);
    if ( v9 )
    {
      Scaleform::GFx::AS3::Abc::MethodBodyInfo::MethodBodyInfo(v9);
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    v12 = v6->Size + 1;
    if ( v12 >= v6->Size )
    {
      if ( v12 >= v6->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v6,
          v6,
          v12 + (v12 >> 2));
    }
    else if ( v12 < v6->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v6,
        v6,
        v6->Size + 1);
    }
    Data = v6->Data;
    v6->Size = v12;
    Data[v12 - 1] = v11;
    v14 = (Scaleform::GFx::AS3::Abc::MethodBodyInfo *)v6->Data[v6->Size - 1];
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, t, v14) )
      break;
    mt->Info.Data.Data[v14->method_info_ind]->MethodBodyInfoInd = v8++;
    result = 1;
    if ( v8 >= count )
      return result;
    v4 = this;
  }
  Size = v6->Size;
  v17 = (void *)v6->Data[Size - 1];
  if ( v17 )
  {
    Scaleform::GFx::AS3::Abc::MethodBodyInfo::~MethodBodyInfo((Scaleform::GFx::AS3::Abc::MethodBodyInfo *)v6->Data[Size - 1]);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v17);
  }
  v18 = v6->Size;
  v19 = v18 - 1;
  if ( v18 )
  {
    if ( v19 < v6->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v6,
        v6,
        v18 - 1);
      v6->Size = v19;
      return 0;
    }
  }
  else if ( v19 >= v6->Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v6,
      v6,
      v19 + (v19 >> 2));
  }
  v6->Size = v19;
  return 0;
}
