char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *obj)
{
  Scaleform::GFx::AS3::Abc::Reader *v2; // ebp
  unsigned int v3; // eax
  int v5; // edi
  Scaleform::GFx::AS3::Abc::MethodInfo *v6; // eax
  Scaleform::GFx::AS3::Abc::MethodInfo *v7; // ebp
  unsigned int v8; // edi
  Scaleform::GFx::AS3::Abc::MethodInfo **Data; // eax
  Scaleform::GFx::AS3::Abc::MethodInfo *v10; // edi
  unsigned int Size; // eax
  unsigned int v12; // edi
  int v15; // [esp+14h] [ebp-8h] BYREF
  int count; // [esp+18h] [ebp-4h]
  int i; // [esp+20h] [ebp+4h]

  v2 = this;
  v3 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  v5 = v3;
  count = v3;
  if ( v3 > obj->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v3);
  for ( i = 0; ; ++i )
  {
    if ( i >= v5 )
      return 1;
    v15 = 338;
    v6 = (Scaleform::GFx::AS3::Abc::MethodInfo *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   v2,
                                                   48,
                                                   &v15);
    if ( v6 )
    {
      v6->RetTypeInd = -1;
      v6->MethodBodyInfoInd = -1;
      v6->ParamTypes.Data.Data = 0;
      v6->ParamTypes.Data.Size = 0;
      v6->ParamTypes.Data.Policy.Capacity = 0;
      v6->OptionalParams.Data.Data = 0;
      v6->OptionalParams.Data.Size = 0;
      v6->OptionalParams.Data.Policy.Capacity = 0;
      v6->ParamNames.Data.Data = 0;
      v6->ParamNames.Data.Size = 0;
      v6->ParamNames.Data.Policy.Capacity = 0;
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    v8 = obj->Size + 1;
    if ( v8 >= obj->Size )
    {
      if ( v8 >= obj->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          obj,
          obj,
          v8 + (v8 >> 2));
    }
    else if ( v8 < obj->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        obj,
        obj,
        obj->Size + 1);
    }
    Data = (Scaleform::GFx::AS3::Abc::MethodInfo **)obj->Data;
    obj->Size = v8;
    Data[v8 - 1] = v7;
    if ( !Scaleform::GFx::AS3::Abc::Read(&this->CP, (Scaleform::GFx::AS3::Abc::MethodInfo *)obj->Data[obj->Size - 1]) )
      break;
    v5 = count;
    v2 = this;
  }
  v10 = (Scaleform::GFx::AS3::Abc::MethodInfo *)obj->Data[obj->Size - 1];
  if ( v10 )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10->ParamNames.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10->OptionalParams.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10->ParamTypes.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
  }
  Size = obj->Size;
  v12 = Size - 1;
  if ( Size )
  {
    if ( v12 < obj->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        obj,
        obj,
        v12);
      obj->Size = v12;
      return 0;
    }
  }
  else if ( v12 >= obj->Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v12 + (v12 >> 2));
  }
  obj->Size = v12;
  return 0;
}
