bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        const Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *obj)
{
  unsigned int v4; // eax
  int v6; // edi
  Scaleform::GFx::AS3::Abc::MetadataInfo *v7; // ebp
  Scaleform::GFx::AS3::Abc::MetadataInfo *v8; // eax
  unsigned int v9; // edi
  Scaleform::GFx::AS3::Abc::MetadataInfo **Data; // edx
  bool v11; // cc
  bool result; // al
  Scaleform::GFx::AS3::Abc::MetadataInfo *v13; // edi
  unsigned int Size; // eax
  unsigned int v15; // edi
  int v16; // [esp+10h] [ebp-8h] BYREF
  int count; // [esp+14h] [ebp-4h]
  int i; // [esp+20h] [ebp+8h]

  v4 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  v6 = v4;
  count = v4;
  if ( v4 > obj->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v4);
  v7 = 0;
  i = 0;
  if ( v6 <= 0 )
    return 1;
  while ( 1 )
  {
    v16 = 338;
    v8 = (Scaleform::GFx::AS3::Abc::MetadataInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this,
                                                     20,
                                                     &v16);
    if ( v8 )
    {
      v8->Name.pStr = 0;
      v8->Name.Size = 0;
      v8->Items.Data.Data = 0;
      v8->Items.Data.Size = 0;
      v8->Items.Data.Policy.Capacity = 0;
      v7 = v8;
    }
    v9 = obj->Size + 1;
    if ( v9 >= obj->Size )
    {
      if ( v9 >= obj->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          obj,
          obj,
          v9 + (v9 >> 2));
    }
    else if ( v9 < obj->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        obj,
        obj,
        obj->Size + 1);
    }
    Data = (Scaleform::GFx::AS3::Abc::MetadataInfo **)obj->Data;
    obj->Size = v9;
    Data[v9 - 1] = v7;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(
            this,
            cp,
            (Scaleform::GFx::AS3::Abc::MetadataInfo *)obj->Data[obj->Size - 1]) )
      break;
    v11 = i + 1 < count;
    result = 1;
    ++i;
    if ( !v11 )
      return result;
    v7 = 0;
  }
  v13 = (Scaleform::GFx::AS3::Abc::MetadataInfo *)obj->Data[obj->Size - 1];
  if ( v13 )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13->Items.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  }
  Size = obj->Size;
  v15 = Size - 1;
  if ( Size )
  {
    if ( v15 < obj->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        obj,
        obj,
        Size - 1);
      obj->Size = v15;
      return 0;
    }
  }
  else if ( v15 >= obj->Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v15 + (v15 >> 2));
  }
  obj->Size = v15;
  return 0;
}
