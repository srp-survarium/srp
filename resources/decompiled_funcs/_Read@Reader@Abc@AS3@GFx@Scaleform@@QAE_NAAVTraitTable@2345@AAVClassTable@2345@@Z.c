bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *obj)
{
  Scaleform::GFx::AS3::Abc::Reader *v3; // ebp
  unsigned int v4; // eax
  bool v6; // bl
  Scaleform::GFx::AS3::Abc::ClassInfo *v7; // eax
  Scaleform::GFx::AS3::Abc::ClassInfo *v8; // ebx
  unsigned int v9; // edi
  Scaleform::GFx::AS3::Abc::ClassInfo **Data; // edx
  Scaleform::GFx::AS3::Abc::ClassInfo *v11; // edi
  unsigned int Size; // eax
  unsigned int v13; // edi
  int j; // ebp
  Scaleform::GFx::AS3::Abc::StaticInfo *v15; // edi
  int count; // [esp+20h] [ebp-8h]
  int v19; // [esp+24h] [ebp-4h] BYREF
  int i; // [esp+30h] [ebp+8h]

  v3 = this;
  v4 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  count = v4;
  v6 = 1;
  if ( v4 > obj->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v4);
  for ( i = 0; i < count; ++i )
  {
    v19 = 338;
    v7 = (Scaleform::GFx::AS3::Abc::ClassInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  v3,
                                                  60,
                                                  &v19);
    if ( v7 )
    {
      v7->inst_info.obj_traits.Data.Data = 0;
      v7->inst_info.obj_traits.Data.Size = 0;
      v7->inst_info.obj_traits.Data.Policy.Capacity = 0;
      v7->inst_info.method_info_ind = -1;
      v7->inst_info.name_ind = -1;
      v7->inst_info.super_name_ind = -1;
      v7->inst_info.protected_namespace_ind = -1;
      v7->inst_info.implemented_interfaces.info.Data.Data = 0;
      v7->inst_info.implemented_interfaces.info.Data.Size = 0;
      v7->inst_info.implemented_interfaces.info.Data.Policy.Capacity = 0;
      v7->stat_info.obj_traits.Data.Data = 0;
      v7->stat_info.obj_traits.Data.Size = 0;
      v7->stat_info.obj_traits.Data.Policy.Capacity = 0;
      v7->stat_info.method_info_ind = -1;
      v8 = v7;
    }
    else
    {
      v8 = 0;
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
    Data = (Scaleform::GFx::AS3::Abc::ClassInfo **)obj->Data;
    obj->Size = v9;
    Data[v9 - 1] = v8;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(
            this,
            t,
            (Scaleform::GFx::AS3::Abc::Instance *)obj->Data[obj->Size - 1]) )
    {
      v11 = (Scaleform::GFx::AS3::Abc::ClassInfo *)obj->Data[obj->Size - 1];
      v6 = 0;
      if ( v11 )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11->stat_info.obj_traits.Data.Data);
        Scaleform::Memory::pGlobalHeap->Free(
          Scaleform::Memory::pGlobalHeap,
          v11->inst_info.implemented_interfaces.info.Data.Data);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11->inst_info.obj_traits.Data.Data);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
      }
      Size = obj->Size;
      v13 = Size - 1;
      if ( Size )
      {
        if ( v13 < obj->Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            obj,
            obj,
            v13);
      }
      else if ( v13 >= obj->Policy.Capacity )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          obj,
          obj,
          v13 + (v13 >> 2));
      }
      obj->Size = v13;
      break;
    }
    v3 = this;
    v6 = 1;
  }
  for ( j = 0; v6; ++j )
  {
    if ( j >= count )
      break;
    v15 = (Scaleform::GFx::AS3::Abc::StaticInfo *)(obj->Data[j] + 44);
    v15->method_info_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
    v6 = Scaleform::GFx::AS3::Abc::Reader::ReadTraits(this, (int)t, &v15->obj_traits) && v15->method_info_ind >= 0;
  }
  return v6;
}
