unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        int x,
        int y)
{
  int v3; // ebx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v6; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v8; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v9; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v10; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v11; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v12; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v13; // edi
  const Scaleform::MemoryHeap *pHeap; // ecx
  unsigned __int8 v15; // al
  unsigned int v16; // esi
  unsigned __int8 *v17; // ecx
  unsigned __int8 *v18; // esi
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v19; // edi
  const Scaleform::MemoryHeap *v20; // ecx
  int v21; // eax
  unsigned int v22; // esi
  unsigned __int8 *v23; // ecx
  unsigned __int8 *v24; // esi
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v25; // edi
  const Scaleform::MemoryHeap *v26; // ecx
  int v27; // eax
  unsigned int v28; // esi
  unsigned __int8 *v29; // ecx
  unsigned __int8 *v30; // esi
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v31; // edi
  const Scaleform::MemoryHeap *v32; // ecx
  int v33; // eax
  unsigned int v34; // esi
  unsigned __int8 *v35; // ecx
  unsigned __int8 *v36; // esi
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v37; // edi
  const Scaleform::MemoryHeap *v38; // eax
  unsigned int v39; // esi
  unsigned __int8 v40; // bl
  unsigned __int8 *v41; // eax
  unsigned __int8 *v42; // esi
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v43; // edi
  const Scaleform::MemoryHeap *v44; // eax
  unsigned int v45; // esi
  int v46; // ebx
  unsigned __int8 *v47; // eax
  unsigned __int8 *v48; // esi
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v49; // edi
  const Scaleform::MemoryHeap *v50; // eax
  unsigned int v51; // esi
  int v52; // ebx
  unsigned __int8 *v53; // eax
  unsigned __int8 *v54; // esi
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v55; // edi
  const Scaleform::MemoryHeap *v56; // eax
  unsigned int v57; // esi
  int v58; // ebx
  unsigned __int8 *v59; // eax
  unsigned __int8 *v60; // esi

  v3 = x;
  if ( (unsigned int)(x + 32) <= 0x3F && (unsigned int)(y + 32) <= 0x3F )
  {
    Data = this->Data;
    LOBYTE(x) = (16 * x) | 4;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      Data,
      (unsigned __int8 *)&x);
    v6 = this->Data;
    LOBYTE(y) = (4 * y) | (v3 >> 4) & 3;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v6,
      (unsigned __int8 *)&y);
    return 2;
  }
  if ( (unsigned int)(x + 512) <= 0x3FF && (unsigned int)(y + 512) <= 0x3FF )
  {
    LOBYTE(x) = (16 * x) | 5;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      this->Data,
      (unsigned __int8 *)&x);
    v8 = this->Data;
    LOBYTE(x) = ((_BYTE)y << 6) | (v3 >> 4) & 0x3F;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v8,
      (unsigned __int8 *)&x);
    v9 = this->Data;
    LOBYTE(y) = y >> 2;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v9,
      (unsigned __int8 *)&y);
    return 3;
  }
  if ( (unsigned int)(x + 0x2000) <= 0x3FFF && (unsigned int)(y + 0x2000) <= 0x3FFF )
  {
    v10 = this->Data;
    LOBYTE(x) = (16 * x) | 6;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v10,
      (unsigned __int8 *)&x);
    LOBYTE(x) = v3 >> 4;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      this->Data,
      (unsigned __int8 *)&x);
    v11 = this->Data;
    LOBYTE(x) = (4 * y) | (v3 >> 12) & 3;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v11,
      (unsigned __int8 *)&x);
    v12 = this->Data;
    LOBYTE(y) = y >> 6;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v12,
      (unsigned __int8 *)&y);
    return 4;
  }
  v13 = this->Data;
  pHeap = this->Data->Data.pHeap;
  v15 = (16 * x) | 7;
  v16 = this->Data->Data.Size + 1;
  LOBYTE(x) = v15;
  if ( v16 >= v13->Data.Size )
  {
    if ( v16 < v13->Data.Policy.Capacity )
      goto LABEL_16;
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v13->Data,
      pHeap,
      v16 + (v16 >> 2));
  }
  else
  {
    if ( v16 >= v13->Data.Policy.Capacity >> 1 )
      goto LABEL_16;
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v13->Data,
      pHeap,
      v16);
  }
  v15 = x;
LABEL_16:
  v17 = v13->Data.Data;
  v13->Data.Size = v16;
  v18 = &v17[v16 - 1];
  if ( v18 )
    *v18 = v15;
  v19 = this->Data;
  v20 = this->Data->Data.pHeap;
  v21 = v3 >> 4;
  v22 = this->Data->Data.Size + 1;
  LOBYTE(x) = v3 >> 4;
  if ( v22 >= v19->Data.Size )
  {
    if ( v22 < v19->Data.Policy.Capacity )
      goto LABEL_24;
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v19->Data,
      v20,
      v22 + (v22 >> 2));
  }
  else
  {
    if ( v22 >= v19->Data.Policy.Capacity >> 1 )
      goto LABEL_24;
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v19->Data,
      v20,
      v22);
  }
  LOBYTE(v21) = x;
LABEL_24:
  v23 = v19->Data.Data;
  v19->Data.Size = v22;
  v24 = &v23[v22 - 1];
  if ( v24 )
    *v24 = v21;
  v25 = this->Data;
  v26 = this->Data->Data.pHeap;
  v27 = v3 >> 12;
  v28 = this->Data->Data.Size + 1;
  LOBYTE(x) = v3 >> 12;
  if ( v28 >= v25->Data.Size )
  {
    if ( v28 < v25->Data.Policy.Capacity )
      goto LABEL_32;
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v25->Data,
      v26,
      v28 + (v28 >> 2));
  }
  else
  {
    if ( v28 >= v25->Data.Policy.Capacity >> 1 )
      goto LABEL_32;
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v25->Data,
      v26,
      v28);
  }
  LOBYTE(v27) = x;
LABEL_32:
  v29 = v25->Data.Data;
  v25->Data.Size = v28;
  v30 = &v29[v28 - 1];
  if ( v30 )
    *v30 = v27;
  v31 = this->Data;
  v32 = this->Data->Data.pHeap;
  v33 = v3 >> 20;
  v34 = this->Data->Data.Size + 1;
  LOBYTE(x) = v3 >> 20;
  if ( v34 >= v31->Data.Size )
  {
    if ( v34 >= v31->Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v31->Data,
        v32,
        v34 + (v34 >> 2));
      goto LABEL_39;
    }
  }
  else if ( v34 < v31->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v31->Data,
      v32,
      v34);
LABEL_39:
    LOBYTE(v33) = x;
  }
  v35 = v31->Data.Data;
  v31->Data.Size = v34;
  v36 = &v35[v34 - 1];
  if ( v36 )
    *v36 = v33;
  v37 = this->Data;
  v38 = this->Data->Data.pHeap;
  v39 = this->Data->Data.Size + 1;
  v40 = (4 * y) | (v3 >> 28) & 3;
  if ( v39 >= this->Data->Data.Size )
  {
    if ( v39 >= v37->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v37->Data,
        v38,
        v39 + (v39 >> 2));
  }
  else if ( v39 < v37->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v37->Data,
      v38,
      this->Data->Data.Size + 1);
  }
  v41 = v37->Data.Data;
  v37->Data.Size = v39;
  v42 = &v41[v39 - 1];
  if ( v42 )
    *v42 = v40;
  v43 = this->Data;
  v44 = this->Data->Data.pHeap;
  v45 = this->Data->Data.Size + 1;
  v46 = y >> 6;
  if ( v45 >= this->Data->Data.Size )
  {
    if ( v45 >= v43->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v43->Data,
        v44,
        v45 + (v45 >> 2));
  }
  else if ( v45 < v43->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v43->Data,
      v44,
      this->Data->Data.Size + 1);
  }
  v47 = v43->Data.Data;
  v43->Data.Size = v45;
  v48 = &v47[v45 - 1];
  if ( v48 )
    *v48 = v46;
  v49 = this->Data;
  v50 = this->Data->Data.pHeap;
  v51 = this->Data->Data.Size + 1;
  v52 = y >> 14;
  if ( v51 >= this->Data->Data.Size )
  {
    if ( v51 >= v49->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v49->Data,
        v50,
        v51 + (v51 >> 2));
  }
  else if ( v51 < v49->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v49->Data,
      v50,
      this->Data->Data.Size + 1);
  }
  v53 = v49->Data.Data;
  v49->Data.Size = v51;
  v54 = &v53[v51 - 1];
  if ( v54 )
    *v54 = v52;
  v55 = this->Data;
  v56 = this->Data->Data.pHeap;
  v57 = this->Data->Data.Size + 1;
  v58 = y >> 22;
  if ( v57 >= this->Data->Data.Size )
  {
    if ( v57 >= v55->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v55->Data,
        v56,
        v57 + (v57 >> 2));
  }
  else if ( v57 < v55->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v55->Data,
      v56,
      this->Data->Data.Size + 1);
  }
  v59 = v55->Data.Data;
  v55->Data.Size = v57;
  v60 = &v59[v57 - 1];
  if ( v60 )
    *v60 = v58;
  return 8;
}


unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        int x,
        int y)
{
  int v3; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v6; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v8; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v9; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v10; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v11; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v12; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v13; // ebp
  char v14; // al
  unsigned int v15; // edi
  bool *v16; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v17; // ebp
  int v18; // eax
  unsigned int v19; // edi
  bool *v20; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v21; // ebp
  int v22; // eax
  unsigned int v23; // edi
  bool *v24; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v25; // ebp
  int v26; // eax
  unsigned int v27; // edi
  bool *v28; // ecx
  char v29; // dl
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v30; // ebp
  unsigned int v31; // edi
  char v32; // bl
  bool *v33; // edx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v34; // ebp
  unsigned int v35; // edi
  int v36; // ebx
  bool *v37; // edx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v38; // ebp
  unsigned int v39; // edi
  int v40; // ebx
  bool *v41; // edx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v42; // esi
  unsigned int v43; // edi
  int v44; // ebx
  bool *v45; // edx

  v3 = x;
  if ( (unsigned int)(x + 32) <= 0x3F && (unsigned int)(y + 32) <= 0x3F )
  {
    Data = this->Data;
    LOBYTE(x) = (16 * x) | 4;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      Data,
      (const unsigned __int8 *)&x);
    v6 = this->Data;
    LOBYTE(y) = (4 * y) | (v3 >> 4) & 3;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v6,
      (const unsigned __int8 *)&y);
    return 2;
  }
  if ( (unsigned int)(x + 512) <= 0x3FF && (unsigned int)(y + 512) <= 0x3FF )
  {
    LOBYTE(x) = (16 * x) | 5;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      this->Data,
      (const unsigned __int8 *)&x);
    v8 = this->Data;
    LOBYTE(x) = ((_BYTE)y << 6) | (v3 >> 4) & 0x3F;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v8,
      (const unsigned __int8 *)&x);
    v9 = this->Data;
    LOBYTE(y) = y >> 2;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v9,
      (const unsigned __int8 *)&y);
    return 3;
  }
  if ( (unsigned int)(x + 0x2000) <= 0x3FFF && (unsigned int)(y + 0x2000) <= 0x3FFF )
  {
    v10 = this->Data;
    LOBYTE(x) = (16 * x) | 6;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v10,
      (const unsigned __int8 *)&x);
    LOBYTE(x) = v3 >> 4;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      this->Data,
      (const unsigned __int8 *)&x);
    v11 = this->Data;
    LOBYTE(x) = (4 * y) | (v3 >> 12) & 3;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v11,
      (const unsigned __int8 *)&x);
    v12 = this->Data;
    LOBYTE(y) = y >> 6;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v12,
      (const unsigned __int8 *)&y);
    return 4;
  }
  v13 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v14 = (16 * x) | 7;
  v15 = this->Data->Data.Size + 1;
  LOBYTE(x) = v14;
  if ( v15 >= v13->Size )
  {
    if ( v15 < v13->Policy.Capacity )
      goto LABEL_16;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v13,
      v13,
      v15 + (v15 >> 2));
  }
  else
  {
    if ( v15 >= v13->Policy.Capacity >> 1 )
      goto LABEL_16;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v13, v13, v15);
  }
  v14 = x;
LABEL_16:
  v16 = v13->Data;
  v13->Size = v15;
  v16[v15 - 1] = v14;
  v17 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v18 = v3 >> 4;
  v19 = this->Data->Data.Size + 1;
  LOBYTE(x) = v3 >> 4;
  if ( v19 >= v17->Size )
  {
    if ( v19 < v17->Policy.Capacity )
      goto LABEL_22;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v17,
      v17,
      v19 + (v19 >> 2));
  }
  else
  {
    if ( v19 >= v17->Policy.Capacity >> 1 )
      goto LABEL_22;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v17, v17, v19);
  }
  LOBYTE(v18) = x;
LABEL_22:
  v20 = v17->Data;
  v17->Size = v19;
  v20[v19 - 1] = v18;
  v21 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v22 = v3 >> 12;
  v23 = this->Data->Data.Size + 1;
  LOBYTE(x) = v3 >> 12;
  if ( v23 >= v21->Size )
  {
    if ( v23 < v21->Policy.Capacity )
      goto LABEL_28;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v21,
      v21,
      v23 + (v23 >> 2));
  }
  else
  {
    if ( v23 >= v21->Policy.Capacity >> 1 )
      goto LABEL_28;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v21, v21, v23);
  }
  LOBYTE(v22) = x;
LABEL_28:
  v24 = v21->Data;
  v21->Size = v23;
  v24[v23 - 1] = v22;
  v25 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v26 = v3 >> 20;
  v27 = this->Data->Data.Size + 1;
  LOBYTE(x) = v3 >> 20;
  if ( v27 >= v25->Size )
  {
    if ( v27 >= v25->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v25,
        v25,
        v27 + (v27 >> 2));
      goto LABEL_33;
    }
  }
  else if ( v27 < v25->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v25, v25, v27);
LABEL_33:
    LOBYTE(v26) = x;
  }
  v28 = v25->Data;
  v29 = y;
  v25->Size = v27;
  v28[v27 - 1] = v26;
  v30 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v31 = this->Data->Data.Size + 1;
  v32 = (4 * v29) | (v3 >> 28) & 3;
  if ( v31 >= this->Data->Data.Size )
  {
    if ( v31 >= v30->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v30,
        v30,
        v31 + (v31 >> 2));
  }
  else if ( v31 < v30->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v30,
      v30,
      this->Data->Data.Size + 1);
  }
  v33 = v30->Data;
  v30->Size = v31;
  v33[v31 - 1] = v32;
  v34 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v35 = this->Data->Data.Size + 1;
  v36 = y >> 6;
  if ( v35 >= this->Data->Data.Size )
  {
    if ( v35 >= v34->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v34,
        v34,
        v35 + (v35 >> 2));
  }
  else if ( v35 < v34->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v34,
      v34,
      this->Data->Data.Size + 1);
  }
  v37 = v34->Data;
  v34->Size = v35;
  v37[v35 - 1] = v36;
  v38 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v39 = this->Data->Data.Size + 1;
  v40 = y >> 14;
  if ( v39 >= this->Data->Data.Size )
  {
    if ( v39 >= v38->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v38,
        v38,
        v39 + (v39 >> 2));
  }
  else if ( v39 < v38->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v38,
      v38,
      this->Data->Data.Size + 1);
  }
  v41 = v38->Data;
  v38->Size = v39;
  v41[v39 - 1] = v40;
  v42 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v43 = v42->Size + 1;
  v44 = y >> 22;
  if ( v43 >= v42->Size )
  {
    if ( v43 >= v42->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v42,
        v42,
        v43 + (v43 >> 2));
  }
  else if ( v43 < v42->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v42,
      v42,
      v42->Size + 1);
  }
  v45 = v42->Data;
  v42->Size = v43;
  v45[v43 - 1] = v44;
  return 8;
}
