char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, int *v)
{
  *v = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  return 1;
}


char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::Code *obj)
{
  obj->code.Data = this->CP;
  this->CP += Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  return 1;
}


bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::ConstPool *obj)
{
  const unsigned __int8 **p_CP; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ebp
  Scaleform::ArrayLH_POD<long,339,Scaleform::ArrayDefaultPolicy> *p_ConstInt; // esi
  unsigned int v6; // edi
  int *Data; // edx
  int v8; // eax
  unsigned int v9; // edi
  int v10; // ebp
  bool v11; // zf
  int *v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // ebp
  Scaleform::ArrayLH_POD<unsigned long,339,Scaleform::ArrayDefaultPolicy> *p_ConstUInt; // esi
  unsigned int v16; // edi
  unsigned int *v17; // edx
  int v18; // eax
  unsigned int v19; // edi
  int v20; // ebp
  unsigned int *v21; // edx
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // ebp
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::StringView,339,Scaleform::ArrayDefaultPolicy> *p_ConstStr; // esi
  unsigned int v26; // edi
  Scaleform::GFx::AS3::Abc::StringView *v27; // eax
  const unsigned __int8 *v28; // ebp
  unsigned int v29; // edi
  Scaleform::GFx::AS3::Abc::StringView *v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // ebp
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339,Scaleform::ArrayDefaultPolicy> *p_ConstNamespace; // edi
  bool v34; // bl
  unsigned int v35; // esi
  Scaleform::GFx::AS3::Abc::NamespaceInfo *v36; // eax
  unsigned int v37; // ebp
  unsigned int v38; // esi
  int *v39; // eax
  int NextIndex; // edx
  int NameIndex; // ecx
  unsigned int v42; // eax
  unsigned int v43; // ebp
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339,Scaleform::ArrayDefaultPolicy> *p_const_ns_set; // esi
  unsigned int v45; // edi
  Scaleform::GFx::AS3::Abc::NamespaceSetInfo *v46; // ecx
  unsigned int v47; // ebp
  unsigned int j; // edi
  unsigned int v49; // edi
  Scaleform::GFx::AS3::Abc::NamespaceSetInfo *v50; // edx
  unsigned int v51; // ebp
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::Multiname,339,Scaleform::ArrayDefaultPolicy> *p_const_multiname; // edi
  bool v53; // bl
  unsigned int v54; // esi
  Scaleform::GFx::AS3::Abc::Multiname *v56; // ecx
  unsigned int v57; // ebp
  unsigned int v58; // esi
  Scaleform::GFx::AS3::Abc::Multiname *v59; // ecx
  int v60; // esi
  int *p_Ind; // eax
  int v62; // ecx
  int v63; // edx
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // ecx
  bool result; // [esp+13h] [ebp-21h]
  unsigned int i; // [esp+14h] [ebp-20h]
  unsigned int ia; // [esp+14h] [ebp-20h]
  unsigned int ib; // [esp+14h] [ebp-20h]
  unsigned int ic; // [esp+14h] [ebp-20h]
  const unsigned __int8 **cp; // [esp+18h] [ebp-1Ch]
  const unsigned __int8 *v72; // [esp+20h] [ebp-14h]
  Scaleform::GFx::AS3::Abc::Multiname info; // [esp+24h] [ebp-10h] BYREF

  p_CP = &this->CP;
  cp = &this->CP;
  v3 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  v4 = v3;
  p_ConstInt = &obj->ConstInt;
  if ( v3 > obj->ConstInt.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)&obj->ConstInt,
      &obj->ConstInt,
      v3);
  v6 = obj->ConstInt.Data.Size + 1;
  if ( v6 >= obj->ConstInt.Data.Size )
  {
    if ( v6 >= obj->ConstInt.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)p_ConstInt,
        p_ConstInt,
        v6 + (v6 >> 2));
  }
  else if ( v6 < obj->ConstInt.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)&obj->ConstInt,
      &obj->ConstInt,
      obj->ConstInt.Data.Size + 1);
  }
  Data = p_ConstInt->Data.Data;
  obj->ConstInt.Data.Size = v6;
  Data[v6 - 1] = 0;
  if ( v4 > 1 )
  {
    i = v4 - 1;
    do
    {
      v8 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
      v9 = obj->ConstInt.Data.Size + 1;
      v10 = v8;
      if ( v9 >= obj->ConstInt.Data.Size )
      {
        if ( v9 >= obj->ConstInt.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)p_ConstInt,
            p_ConstInt,
            v9 + (v9 >> 2));
      }
      else if ( v9 < obj->ConstInt.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)&obj->ConstInt,
          &obj->ConstInt,
          obj->ConstInt.Data.Size + 1);
      }
      v11 = i-- == 1;
      v12 = p_ConstInt->Data.Data;
      obj->ConstInt.Data.Size = v9;
      v12[v9 - 1] = v10;
    }
    while ( !v11 );
  }
  v13 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  v14 = v13;
  p_ConstUInt = &obj->ConstUInt;
  if ( v13 > obj->ConstUInt.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)&obj->ConstUInt,
      &obj->ConstUInt,
      v13);
  v16 = obj->ConstUInt.Data.Size + 1;
  if ( v16 >= obj->ConstUInt.Data.Size )
  {
    if ( v16 >= obj->ConstUInt.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)p_ConstUInt,
        p_ConstUInt,
        v16 + (v16 >> 2));
  }
  else if ( v16 < obj->ConstUInt.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)&obj->ConstUInt,
      &obj->ConstUInt,
      obj->ConstUInt.Data.Size + 1);
  }
  v17 = p_ConstUInt->Data.Data;
  obj->ConstUInt.Data.Size = v16;
  v17[v16 - 1] = 0;
  if ( v14 > 1 )
  {
    ia = v14 - 1;
    do
    {
      v18 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
      v19 = obj->ConstUInt.Data.Size + 1;
      v20 = v18;
      if ( v19 >= obj->ConstUInt.Data.Size )
      {
        if ( v19 >= obj->ConstUInt.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)p_ConstUInt,
            p_ConstUInt,
            v19 + (v19 >> 2));
      }
      else if ( v19 < obj->ConstUInt.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)&obj->ConstUInt,
          &obj->ConstUInt,
          obj->ConstUInt.Data.Size + 1);
      }
      v11 = ia-- == 1;
      v21 = p_ConstUInt->Data.Data;
      obj->ConstUInt.Data.Size = v19;
      v21[v19 - 1] = v20;
    }
    while ( !v11 );
  }
  obj->DoubleCount = 0;
  obj->Doubles = 0;
  v22 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  obj->DoubleCount = v22;
  obj->Doubles = *p_CP;
  if ( v22 )
    *p_CP += 8 * v22 - 8;
  v23 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  v24 = v23;
  p_ConstStr = &obj->ConstStr;
  if ( v23 > obj->ConstStr.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)p_ConstStr,
      p_ConstStr,
      v23);
  v26 = obj->ConstStr.Data.Size + 1;
  if ( v26 >= obj->ConstStr.Data.Size )
  {
    if ( v26 >= obj->ConstStr.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)p_ConstStr,
        p_ConstStr,
        v26 + (v26 >> 2));
  }
  else if ( v26 < obj->ConstStr.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)&obj->ConstStr,
      &obj->ConstStr,
      obj->ConstStr.Data.Size + 1);
  }
  v27 = &p_ConstStr->Data.Data[v26 - 1];
  obj->ConstStr.Data.Size = v26;
  if ( v27 )
    v27->Data = &Scaleform::GFx::AS3::Abc::StringView::Empty;
  ib = 0;
  if ( v24 )
  {
    v72 = (const unsigned __int8 *)(v24 - 1);
    while ( ib < (unsigned int)v72 )
    {
      v28 = *p_CP;
      v29 = obj->ConstStr.Data.Size + 1;
      if ( v29 >= obj->ConstStr.Data.Size )
      {
        if ( v29 >= obj->ConstStr.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)p_ConstStr,
            p_ConstStr,
            v29 + (v29 >> 2));
      }
      else if ( v29 < obj->ConstStr.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339>,Scaleform::ArrayDefaultPolicy> *)&obj->ConstStr,
          &obj->ConstStr,
          obj->ConstStr.Data.Size + 1);
      }
      v30 = &p_ConstStr->Data.Data[v29 - 1];
      obj->ConstStr.Data.Size = v29;
      if ( v30 )
        v30->Data = v28;
      *p_CP += Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
      ++ib;
    }
  }
  v31 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  v32 = v31;
  p_ConstNamespace = &obj->ConstNamespace;
  v34 = 1;
  if ( v31 > obj->ConstNamespace.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->ConstNamespace.Data,
      &obj->ConstNamespace,
      v31);
  v35 = obj->ConstNamespace.Data.Size + 1;
  if ( v35 >= obj->ConstNamespace.Data.Size )
  {
    if ( v35 >= obj->ConstNamespace.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &p_ConstNamespace->Data,
        p_ConstNamespace,
        v35 + (v35 >> 2));
  }
  else if ( v35 < obj->ConstNamespace.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->ConstNamespace.Data,
      &obj->ConstNamespace,
      obj->ConstNamespace.Data.Size + 1);
  }
  v36 = &p_ConstNamespace->Data.Data[v35 - 1];
  obj->ConstNamespace.Data.Size = v35;
  if ( v36 )
  {
    v36->Kind = NS_Public;
    v36->NameURI.pStr = (const char *)&buf;
    v36->NameURI.Size = 0;
  }
  if ( v32 > 1 )
  {
    v37 = v32 - 1;
    do
    {
      info.Ind = 0;
      info.NextIndex = (int)&buf;
      info.NameIndex = 0;
      v34 = v34 && Scaleform::GFx::AS3::Abc::Reader::Read(this, obj, (Scaleform::GFx::AS3::Abc::NamespaceInfo *)&info);
      v38 = obj->ConstNamespace.Data.Size + 1;
      if ( v38 >= obj->ConstNamespace.Data.Size )
      {
        if ( v38 >= obj->ConstNamespace.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_ConstNamespace->Data,
            p_ConstNamespace,
            v38 + (v38 >> 2));
      }
      else if ( v38 < obj->ConstNamespace.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &obj->ConstNamespace.Data,
          &obj->ConstNamespace,
          obj->ConstNamespace.Data.Size + 1);
      }
      v39 = (int *)&p_ConstNamespace->Data.Data[v38 - 1];
      obj->ConstNamespace.Data.Size = v38;
      if ( v39 )
      {
        NextIndex = info.NextIndex;
        *v39 = info.Ind;
        NameIndex = info.NameIndex;
        v39[1] = NextIndex;
        v39[2] = NameIndex;
      }
      --v37;
    }
    while ( v37 );
    if ( !v34 )
      return 0;
  }
  v42 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(cp);
  v43 = v42;
  p_const_ns_set = &obj->const_ns_set;
  result = 1;
  if ( v42 > obj->const_ns_set.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->const_ns_set.Data,
      &obj->const_ns_set,
      v42);
  v45 = obj->const_ns_set.Data.Size + 1;
  if ( v45 >= obj->const_ns_set.Data.Size )
  {
    if ( v45 >= obj->const_ns_set.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &p_const_ns_set->Data,
        p_const_ns_set,
        v45 + (v45 >> 2));
  }
  else if ( v45 < obj->const_ns_set.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->const_ns_set.Data,
      &obj->const_ns_set,
      obj->const_ns_set.Data.Size + 1);
  }
  v46 = p_const_ns_set->Data.Data;
  obj->const_ns_set.Data.Size = v45;
  v46[v45 - 1].Data = (const unsigned __int8 *)obj;
  obj->const_ns_set.Data.Data[obj->const_ns_set.Data.Size - 1].Data = 0;
  if ( v43 > 1 )
  {
    ic = v43 - 1;
    do
    {
      if ( result )
      {
        v72 = *cp;
        v47 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(cp);
        for ( j = 0; j < v47; ++j )
        {
          if ( !Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(cp) )
            goto LABEL_92;
        }
        result = 1;
      }
      else
      {
LABEL_92:
        result = 0;
      }
      v49 = obj->const_ns_set.Data.Size + 1;
      if ( v49 >= obj->const_ns_set.Data.Size )
      {
        if ( v49 >= obj->const_ns_set.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_const_ns_set->Data,
            p_const_ns_set,
            v49 + (v49 >> 2));
      }
      else if ( v49 < obj->const_ns_set.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &obj->const_ns_set.Data,
          &obj->const_ns_set,
          obj->const_ns_set.Data.Size + 1);
      }
      v11 = ic-- == 1;
      v50 = p_const_ns_set->Data.Data;
      obj->const_ns_set.Data.Size = v49;
      v50[v49 - 1].Data = v72;
    }
    while ( !v11 );
    if ( !result )
      return 0;
  }
  v51 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(cp);
  p_const_multiname = &obj->const_multiname;
  v53 = 1;
  if ( v51 + 1 > obj->const_multiname.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::Multiname,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->const_multiname.Data,
      &obj->const_multiname,
      v51 + 1);
  v54 = obj->const_multiname.Data.Size + 1;
  if ( v54 >= obj->const_multiname.Data.Size )
  {
    if ( v54 >= obj->const_multiname.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::Multiname,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &p_const_multiname->Data,
        p_const_multiname,
        v54 + (v54 >> 2));
  }
  else if ( v54 < obj->const_multiname.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::Multiname,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->const_multiname.Data,
      &obj->const_multiname,
      obj->const_multiname.Data.Size + 1);
  }
  v56 = p_const_multiname->Data.Data;
  obj->const_multiname.Data.Size = v54;
  if ( &v56[v54] != (Scaleform::GFx::AS3::Abc::Multiname *)16 )
    v56[v54 - 1] = Scaleform::GFx::AS3::Abc::Multiname::AnyType;
  if ( v51 > 1 )
  {
    v57 = v51 - 1;
    do
    {
      info.Ind = -1;
      info.NextIndex = -1;
      info.NameIndex = 0;
      info.Kind = MN_QName;
      v53 = v53 && Scaleform::GFx::AS3::Abc::Reader::Read(this, obj, (int)&info);
      v58 = obj->const_multiname.Data.Size + 1;
      if ( v58 >= obj->const_multiname.Data.Size )
      {
        if ( v58 >= obj->const_multiname.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::Multiname,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_const_multiname->Data,
            p_const_multiname,
            v58 + (v58 >> 2));
      }
      else if ( v58 < obj->const_multiname.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::Multiname,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &obj->const_multiname.Data,
          &obj->const_multiname,
          obj->const_multiname.Data.Size + 1);
      }
      v59 = p_const_multiname->Data.Data;
      obj->const_multiname.Data.Size = v58;
      v60 = v58;
      p_Ind = &v59[v60 - 1].Ind;
      if ( &v59[v60] != (Scaleform::GFx::AS3::Abc::Multiname *)16 )
      {
        v62 = info.NextIndex;
        *p_Ind = info.Ind;
        v63 = info.NameIndex;
        p_Ind[1] = v62;
        Kind = info.Kind;
        p_Ind[2] = v63;
        p_Ind[3] = Kind;
      }
      --v57;
    }
    while ( v57 );
  }
  return v53;
}


char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *obj)
{
  const unsigned __int8 **p_CP; // esi
  unsigned int v3; // eax
  int i; // ebp
  int count; // [esp+10h] [ebp-1Ch]
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo info; // [esp+18h] [ebp-14h] BYREF

  p_CP = &this->CP;
  v3 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  count = v3;
  if ( v3 > obj->info.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->info.Data,
      obj,
      v3);
  for ( i = 0; i < count; ++i )
  {
    Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo::ExceptionInfo(&info);
    info.from = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
    info.to = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
    info.target = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
    info.exc_type_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, (int *)&info.var_name_ind) )
      return 0;
    Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &obj->info.Data,
      &info);
  }
  return 1;
}


bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::File *obj)
{
  unsigned __int16 v3; // ax

  Scaleform::GFx::AS3::Abc::File::Clear(obj);
  obj->MinorVersion = Scaleform::GFx::AS3::Abc::Read16<unsigned char>(&this->CP);
  v3 = Scaleform::GFx::AS3::Abc::Read16<unsigned char>(&this->CP);
  obj->MajorVersion = v3;
  return v3 == 46
      && obj->MinorVersion == 16
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->Const_Pool)
      && Scaleform::GFx::AS3::Abc::Reader::Read(
           this,
           (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&obj->Methods)
      && Scaleform::GFx::AS3::Abc::Reader::Read(
           this,
           &obj->Const_Pool,
           (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&obj->Metadata)
      && Scaleform::GFx::AS3::Abc::Reader::Read(
           this,
           &obj->Traits,
           (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&obj->AS3_Classes)
      && Scaleform::GFx::AS3::Abc::Reader::Read(
           this,
           &obj->Traits,
           (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&obj->Scripts)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->Traits, &obj->Methods, (int)&obj->MethodBodies);
}


char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::Instance::Interfaces *obj)
{
  const unsigned __int8 **p_CP; // ebp
  unsigned int v3; // eax
  int v5; // esi
  int v6; // eax
  unsigned int v7; // esi
  int v8; // ebx
  bool v9; // zf
  int *Data; // edx
  Scaleform::GFx::AS3::Abc::Instance::Interfaces *obja; // [esp+10h] [ebp+4h]

  p_CP = &this->CP;
  v3 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  v5 = v3;
  if ( v3 > obj->info.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->info.Data,
      obj,
      v3);
  if ( v5 > 0 )
  {
    obja = (Scaleform::GFx::AS3::Abc::Instance::Interfaces *)v5;
    do
    {
      v6 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
      v7 = obj->info.Data.Size + 1;
      v8 = v6;
      if ( v7 >= obj->info.Data.Size )
      {
        if ( v7 >= obj->info.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &obj->info.Data,
            obj,
            v7 + (v7 >> 2));
      }
      else if ( v7 < obj->info.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &obj->info.Data,
          obj,
          obj->info.Data.Size + 1);
      }
      v9 = obja == (Scaleform::GFx::AS3::Abc::Instance::Interfaces *)1;
      obja = (Scaleform::GFx::AS3::Abc::Instance::Interfaces *)((char *)obja - 1);
      Data = obj->info.Data.Data;
      obj->info.Data.Size = v7;
      Data[v7 - 1] = v8;
    }
    while ( !v9 );
  }
  return 1;
}


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


bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitInfo *obj)
{
  Scaleform::GFx::AS3::Abc::TraitInfo *v2; // esi
  const unsigned __int8 **p_CP; // edi
  unsigned __int8 v5; // cl
  bool v6; // sf
  bool result; // al
  bool IsValidValueKind; // bl
  unsigned __int8 kind; // [esp+Ch] [ebp-4h]

  v2 = obj;
  p_CP = &this->CP;
  v2->name_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  v5 = *(*p_CP)++;
  v6 = v2->name_ind < 0;
  v2->kind = v5;
  if ( v6 )
    return 0;
  switch ( v5 & 0xF )
  {
    case 0:
    case 6:
      obj = 0;
      if ( Scaleform::GFx::AS3::Abc::Reader::Read(this, &v2->SlotId) )
      {
        if ( Scaleform::GFx::AS3::Abc::Reader::Read(this, &v2->Ind) )
        {
          if ( Scaleform::GFx::AS3::Abc::Reader::Read(this, (int *)&obj) )
          {
            IsValidValueKind = 1;
            if ( !obj )
              goto LABEL_15;
            kind = *(*p_CP)++;
            IsValidValueKind = Scaleform::GFx::AS3::Abc::IsValidValueKind(kind);
            v2->default_value.ValueIndex = (int)obj;
            v2->default_value.Kind = kind;
            if ( IsValidValueKind )
              goto LABEL_15;
          }
        }
      }
      goto LABEL_9;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, &v2->SlotId)
        || !Scaleform::GFx::AS3::Abc::Reader::Read(this, &v2->Ind)
        || v2->SlotId < 0
        || v2->Ind < 0 )
      {
        goto LABEL_9;
      }
      IsValidValueKind = 1;
LABEL_15:
      if ( (v2->kind & 0x40) != 0 )
        IsValidValueKind = Scaleform::GFx::AS3::Abc::Reader::Read(
                             this,
                             (Scaleform::GFx::AS3::Abc::Instance::Interfaces *)&v2->meta_info) != 0;
      result = IsValidValueKind;
      break;
    default:
LABEL_9:
      result = 0;
      break;
  }
  return result;
}


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


bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::GFx::AS3::Abc::HasCode *obj)
{
  obj->method_info_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  return Scaleform::GFx::AS3::Abc::Reader::ReadTraits(this, (int)t, &obj->obj_traits) && obj->method_info_ind >= 0;
}


bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::GFx::AS3::Abc::Instance *obj)
{
  const unsigned __int8 **p_CP; // esi
  unsigned __int8 v5; // cl
  bool v6; // sf
  bool v7; // al

  p_CP = &this->CP;
  obj->name_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  obj->super_name_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  v5 = *(*p_CP)++;
  v6 = obj->name_ind < 0;
  obj->flags = v5;
  v7 = !v6 && obj->super_name_ind >= 0;
  if ( (v5 & 8) != 0 )
  {
    if ( !v7 )
      return 0;
    obj->protected_namespace_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  }
  else if ( !v7 )
  {
    return 0;
  }
  return Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->implemented_interfaces)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, t, obj);
}


bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo *obj)
{
  const unsigned __int8 **p_CP; // edi

  p_CP = &this->CP;
  obj->method_info_ind = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  obj->max_stack = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  obj->local_reg_count = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  obj->init_scope_depth = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
  return Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->max_scope_depth)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->code)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->exception)
      && Scaleform::GFx::AS3::Abc::Reader::ReadTraits(this, (int)t, &obj->obj_traits)
      && obj->method_info_ind >= 0;
}


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


char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        const Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::GFx::AS3::Abc::MetadataInfo *obj)
{
  unsigned int v4; // eax
  int v5; // ebp
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338,Scaleform::ArrayDefaultPolicy> *p_Items; // edi
  unsigned int v7; // esi
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v9; // eax
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v10; // esi
  int v11; // esi
  int v12; // ebp
  int count[2]; // [esp+8h] [ebp-8h] BYREF
  const unsigned __int8 **cpa; // [esp+14h] [ebp+4h]
  Scaleform::GFx::AS3::Abc::MetadataInfo *obja; // [esp+18h] [ebp+8h]

  count[0] = 0;
  count[1] = 0;
  if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, cp, &obj->Name, (const Scaleform::StringDataPtr *)count) )
    return 0;
  cpa = &this->CP;
  v4 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  v5 = v4;
  p_Items = &obj->Items;
  count[0] = v4;
  if ( v4 > obj->Items.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &p_Items->Data,
      p_Items,
      v4);
  if ( v5 > 0 )
  {
    obja = (Scaleform::GFx::AS3::Abc::MetadataInfo *)v5;
    do
    {
      v7 = p_Items->Data.Size + 1;
      if ( v7 >= p_Items->Data.Size )
      {
        if ( v7 >= p_Items->Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_Items->Data,
            p_Items,
            v7 + (v7 >> 2));
      }
      else if ( v7 < p_Items->Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &p_Items->Data,
          p_Items,
          p_Items->Data.Size + 1);
      }
      v9 = &p_Items->Data.Data[v7 - 1];
      p_Items->Data.Size = v7;
      if ( v9 )
      {
        v9->KeyInd = 0;
        v9->ValueInd = 0;
      }
      v10 = &p_Items->Data.Data[p_Items->Data.Size - 1];
      v10->KeyInd = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(cpa);
      obja = (Scaleform::GFx::AS3::Abc::MetadataInfo *)((char *)obja - 1);
    }
    while ( obja );
  }
  v11 = 0;
  if ( v5 > 0 )
  {
    do
    {
      v12 = (int)&p_Items->Data.Data[v11];
      *(_DWORD *)(v12 + 4) = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(cpa);
      ++v11;
    }
    while ( v11 < count[0] );
  }
  return 1;
}


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


bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        const Scaleform::GFx::AS3::Abc::ConstPool *cp,
        int obj)
{
  const unsigned __int8 *v4; // eax
  const unsigned __int8 **p_CP; // ecx
  int v6; // edx
  bool result; // al
  Scaleform::GFx::AS3::Abc::MultinameKind v8; // edx
  int *v9; // esi
  char v10; // al
  Scaleform::GFx::AS3::Abc::Multiname *v11; // eax

  v4 = this->CP;
  p_CP = &this->CP;
  v6 = *v4;
  *p_CP = v4 + 1;
  result = 1;
  switch ( v6 )
  {
    case 7:
      v8 = MN_QName;
      break;
    case 9:
      v8 = MN_Multiname;
      break;
    case 13:
      v8 = MN_QNameA;
      break;
    case 14:
      v8 = MN_MultinameA;
      break;
    case 15:
      v8 = MN_RTQName;
      break;
    case 16:
      v8 = MN_RTQNameA;
      break;
    case 17:
      v8 = MN_RTQNameL;
      break;
    case 18:
      v8 = MN_RTQNameLA;
      break;
    case 27:
      v8 = MN_MultinameL;
      break;
    case 28:
      v8 = MN_MultinameLA;
      break;
    case 29:
      v8 = MN_Typename;
      break;
    default:
      v8 = MN_Invalid;
      result = 0;
      break;
  }
  v9 = (int *)obj;
  *(_DWORD *)(obj + 12) = v8;
  switch ( v8 )
  {
    case MN_QName:
    case MN_QNameA:
      if ( result )
      {
        *v9 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
        if ( Scaleform::GFx::AS3::Abc::Reader::Read(this, v9 + 2) )
          return 1;
      }
      goto LABEL_17;
    case MN_RTQName:
    case MN_RTQNameA:
      if ( !result )
        goto LABEL_17;
      v9[2] = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
      return 1;
    case MN_Multiname:
    case MN_MultinameA:
      if ( !result )
        goto LABEL_17;
      v9[2] = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
      v10 = Scaleform::GFx::AS3::Abc::Reader::Read(this, v9);
      goto LABEL_23;
    case MN_MultinameL:
    case MN_MultinameLA:
      if ( !result )
        goto LABEL_17;
      *v9 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
      return 1;
    case MN_Typename:
      obj = 0;
      if ( !result )
        goto LABEL_17;
      if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj) )
        goto LABEL_17;
      v11 = &cp->const_multiname.Data.Data[obj];
      *v9 = v11->Ind;
      v9[1] = v11->NextIndex;
      v9[2] = v11->NameIndex;
      v9[3] = v11->Kind;
      if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj) || obj != 1 )
        goto LABEL_17;
      v10 = Scaleform::GFx::AS3::Abc::Reader::Read(this, v9 + 1);
LABEL_23:
      if ( v10 )
        return 1;
LABEL_17:
      v9[3] = 32;
      return 0;
    default:
      if ( !result )
        v9[3] = 32;
      return result;
  }
}


bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        const Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::GFx::AS3::Abc::NamespaceInfo *obj)
{
  const unsigned __int8 *v3; // eax
  unsigned __int8 v4; // bl
  bool result; // al
  Scaleform::StringDataPtr zero_val; // [esp+8h] [ebp-8h] BYREF

  v3 = this->CP;
  v4 = *v3;
  this->CP = v3 + 1;
  zero_val.pStr = (const char *)&buf;
  zero_val.Size = 0;
  result = Scaleform::GFx::AS3::Abc::Reader::Read(this, cp, &obj->NameURI, &zero_val) != 0;
  switch ( v4 )
  {
    case 5u:
      obj->Kind = NS_Private;
      break;
    case 8u:
    case 0x16u:
      obj->Kind = NS_Public;
      break;
    case 0x17u:
      obj->Kind = NS_PackageInternal;
      break;
    case 0x18u:
      obj->Kind = NS_Protected;
      break;
    case 0x19u:
      obj->Kind = NS_Explicit;
      break;
    case 0x1Au:
      obj->Kind = NS_StaticProtected;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}


char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        const Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::StringDataPtr *obj,
        const Scaleform::StringDataPtr *zero_val)
{
  int v4; // eax
  unsigned int Size; // ecx
  Scaleform::StringDataPtr result; // [esp+0h] [ebp-8h] BYREF

  v4 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  if ( v4 )
  {
    Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(&cp->ConstStr.Data.Data[v4], &result);
    Size = result.Size;
    obj->pStr = result.pStr;
    obj->Size = Size;
  }
  else
  {
    *obj = *zero_val;
  }
  return 1;
}
