bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *obj)
{
  unsigned int v4; // eax
  int v6; // edi
  Scaleform::GFx::AS3::Abc::ScriptInfo *v7; // ebp
  Scaleform::GFx::AS3::Abc::ScriptInfo *v8; // eax
  unsigned int v9; // edi
  Scaleform::GFx::AS3::Abc::ScriptInfo **Data; // eax
  Scaleform::GFx::AS3::Abc::ScriptInfo *v11; // edi
  bool v12; // cc
  bool result; // al
  Scaleform::GFx::AS3::Abc::ScriptInfo *v14; // edi
  unsigned int Size; // eax
  unsigned int v16; // edi
  int v17; // [esp+10h] [ebp-8h] BYREF
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
    v17 = 338;
    v8 = (Scaleform::GFx::AS3::Abc::ScriptInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this,
                                                   16,
                                                   &v17);
    if ( v8 )
    {
      v8->obj_traits.Data.Data = 0;
      v8->obj_traits.Data.Size = 0;
      v8->obj_traits.Data.Policy.Capacity = 0;
      v8->method_info_ind = -1;
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
    Data = (Scaleform::GFx::AS3::Abc::ScriptInfo **)obj->Data;
    obj->Size = v9;
    Data[v9 - 1] = v7;
    v11 = (Scaleform::GFx::AS3::Abc::ScriptInfo *)obj->Data[obj->Size - 1];
    v11->method_info_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
    if ( !Scaleform::GFx::AS3::Abc::Reader::ReadTraits(this, (int)t, &v11->obj_traits) || v11->method_info_ind < 0 )
      break;
    v12 = i + 1 < count;
    result = 1;
    ++i;
    if ( !v12 )
      return result;
    v7 = 0;
  }
  v14 = (Scaleform::GFx::AS3::Abc::ScriptInfo *)obj->Data[obj->Size - 1];
  if ( v14 )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14->obj_traits.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
  }
  Size = obj->Size;
  v16 = Size - 1;
  if ( Size )
  {
    if ( v16 < obj->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        obj,
        obj,
        Size - 1);
      obj->Size = v16;
      return 0;
    }
  }
  else if ( v16 >= obj->Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v16 + (v16 >> 2));
  }
  obj->Size = v16;
  return 0;
}
