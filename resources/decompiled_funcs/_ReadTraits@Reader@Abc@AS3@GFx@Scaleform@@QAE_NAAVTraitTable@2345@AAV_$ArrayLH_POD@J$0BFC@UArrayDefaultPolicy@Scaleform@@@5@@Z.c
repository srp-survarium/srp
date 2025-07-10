char __thiscall Scaleform::GFx::AS3::Abc::Reader::ReadTraits(
        Scaleform::GFx::AS3::Abc::Reader *this,
        int t,
        Scaleform::ArrayLH_POD<long,338,Scaleform::ArrayDefaultPolicy> *obj_traits)
{
  unsigned int v3; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *v4; // ebp
  int v5; // esi
  char v6; // bl
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *v7; // edi
  unsigned int Size; // ebx
  unsigned int v9; // esi
  int *Data; // edx
  _DWORD *v11; // eax
  _DWORD *v12; // ebx
  unsigned int v13; // esi
  int *v14; // eax
  bool v15; // cc
  char result; // al
  unsigned int v17; // eax
  unsigned int v18; // esi
  void **v19; // esi
  unsigned int v20; // eax
  unsigned int v21; // esi
  int count; // [esp+14h] [ebp-4h]

  v3 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  v4 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)obj_traits;
  v5 = v3;
  count = v3;
  v6 = 1;
  if ( v3 > obj_traits->Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)obj_traits,
      obj_traits,
      v3);
  v7 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)t;
  if ( (unsigned int)(v5 + *(_DWORD *)(t + 4)) > *(_DWORD *)(t + 8) )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)t,
      (const void *)t,
      v5 + *(_DWORD *)(t + 4));
  obj_traits = 0;
  if ( v5 > 0 )
  {
    while ( 1 )
    {
      Size = v7->Size;
      v9 = v4->Size + 1;
      if ( v9 >= v4->Size )
      {
        if ( v9 >= v4->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v4,
            v4,
            v9 + (v9 >> 2));
      }
      else if ( v9 < v4->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v4,
          v4,
          v4->Size + 1);
      }
      Data = v4->Data;
      v4->Size = v9;
      Data[v9 - 1] = Size;
      t = 338;
      v11 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 36, &t);
      v12 = 0;
      if ( v11 )
      {
        v11[1] = -1;
        v11[2] = -1;
        v11[3] = -1;
        v11[5] = 0;
        v11[4] = -1;
        v11[6] = 0;
        v11[7] = 0;
        v11[8] = 0;
        v12 = v11;
      }
      v13 = v7->Size + 1;
      if ( v13 >= v7->Size )
      {
        if ( v13 >= v7->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v7,
            v7,
            v13 + (v13 >> 2));
      }
      else if ( v13 < v7->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v7,
          v7,
          v7->Size + 1);
      }
      v14 = v7->Data;
      v7->Size = v13;
      v14[v13 - 1] = (int)v12;
      if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, (Scaleform::GFx::AS3::Abc::TraitInfo *)v7->Data[v7->Size - 1]) )
        break;
      v15 = (int)&obj_traits->Data.Data + 1 < count;
      result = 1;
      obj_traits = (Scaleform::ArrayLH_POD<long,338,Scaleform::ArrayDefaultPolicy> *)((char *)obj_traits + 1);
      if ( !v15 )
        return result;
    }
    v17 = v4->Size;
    v18 = v17 - 1;
    v6 = 0;
    if ( v17 )
    {
      if ( v18 < v4->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v4,
          v4,
          v17 - 1);
    }
    else if ( v18 >= v4->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v4,
        v4,
        v18 + (v18 >> 2));
    }
    v4->Size = v18;
    v19 = (void **)v7->Data[v7->Size - 1];
    if ( v19 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19[6]);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
    }
    v20 = v7->Size;
    v21 = v20 - 1;
    if ( v20 )
    {
      if ( v21 < v7->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v7,
          v7,
          v21);
    }
    else if ( v21 >= v7->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v7,
        v7,
        v21 + (v21 >> 2));
    }
    v7->Size = v21;
  }
  return v6;
}
