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
