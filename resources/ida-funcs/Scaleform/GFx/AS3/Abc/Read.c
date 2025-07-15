char __cdecl Scaleform::GFx::AS3::Abc::Read(const unsigned __int8 **ptr, Scaleform::GFx::AS3::Abc::MethodInfo *obj)
{
  int v2; // esi
  int v3; // eax
  Scaleform::GFx::AS3::Abc::MethodInfo *v4; // ebp
  Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *p_ParamTypes; // edi
  int v7; // eax
  unsigned int v8; // esi
  int v9; // ebp
  bool v10; // zf
  unsigned int *Data; // edx
  unsigned __int8 v12; // cl
  unsigned int v13; // eax
  int v14; // esi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy> *p_OptionalParams; // edi
  int v16; // ebp
  unsigned __int8 v17; // cl
  unsigned int v18; // esi
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v19; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *p_ParamNames; // edi
  int j; // ebp
  int v22; // eax
  unsigned int v23; // esi
  int *v24; // edx
  int param_count; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  int ia; // [esp+10h] [ebp-10h]
  int ind; // [esp+14h] [ebp-Ch]
  int inda; // [esp+14h] [ebp-Ch]
  int detail_4; // [esp+1Ch] [ebp-4h]

  v2 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(ptr);
  param_count = v2;
  v3 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(ptr);
  v4 = obj;
  obj->RetTypeInd = v3;
  if ( v3 < 0 )
    return 0;
  p_ParamTypes = &obj->ParamTypes;
  if ( v2 > obj->ParamTypes.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&obj->ParamTypes,
      &obj->ParamTypes,
      v2);
  if ( v2 > 0 )
  {
    i = v2;
    do
    {
      v7 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(ptr);
      v8 = obj->ParamTypes.Data.Size + 1;
      v9 = v7;
      if ( v8 >= obj->ParamTypes.Data.Size )
      {
        if ( v8 >= obj->ParamTypes.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)p_ParamTypes,
            p_ParamTypes,
            v8 + (v8 >> 2));
      }
      else if ( v8 < obj->ParamTypes.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&obj->ParamTypes,
          &obj->ParamTypes,
          obj->ParamTypes.Data.Size + 1);
      }
      v10 = i-- == 1;
      Data = p_ParamTypes->Data.Data;
      obj->ParamTypes.Data.Size = v8;
      Data[v8 - 1] = v9;
    }
    while ( !v10 );
    v4 = obj;
    v2 = param_count;
  }
  Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(ptr);
  v12 = *(*ptr)++;
  v4->Flags = v12;
  if ( (v12 & 8) != 0 )
  {
    v13 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(ptr);
    v14 = v13;
    p_OptionalParams = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy> *)&v4->OptionalParams;
    ind = v13;
    if ( v13 > v4->OptionalParams.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy> *)&v4->OptionalParams,
        &v4->OptionalParams,
        v13);
    for ( ia = 0; ia < v14; ++ia )
    {
      v16 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(ptr);
      v17 = *(*ptr)++;
      detail_4 = v17;
      if ( v16 < 0 )
        return 0;
      v18 = p_OptionalParams->Size + 1;
      if ( v18 >= p_OptionalParams->Size )
      {
        if ( v18 >= p_OptionalParams->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_OptionalParams,
            p_OptionalParams,
            v18 + (v18 >> 2));
      }
      else if ( v18 < p_OptionalParams->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_OptionalParams,
          p_OptionalParams,
          p_OptionalParams->Size + 1);
      }
      v19 = &p_OptionalParams->Data[v18 - 1];
      p_OptionalParams->Size = v18;
      if ( v19 )
      {
        v19->KeyInd = v16;
        v19->ValueInd = detail_4;
      }
      v14 = ind;
      v4 = obj;
    }
    v2 = param_count;
  }
  if ( (v4->Flags & 0x80u) != 0 )
  {
    p_ParamNames = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&v4->ParamNames;
    if ( v2 > v4->ParamNames.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&v4->ParamNames,
        &v4->ParamNames,
        v2);
    for ( j = 0; j < param_count; v24[v23 - 1] = inda )
    {
      v22 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(ptr);
      v23 = p_ParamNames->Size + 1;
      inda = v22;
      if ( v23 >= p_ParamNames->Size )
      {
        if ( v23 >= p_ParamNames->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ParamNames,
            p_ParamNames,
            v23 + (v23 >> 2));
      }
      else if ( v23 < p_ParamNames->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ParamNames,
          p_ParamNames,
          v23);
      }
      v24 = p_ParamNames->Data;
      ++j;
      p_ParamNames->Size = v23;
    }
  }
  return 1;
}
