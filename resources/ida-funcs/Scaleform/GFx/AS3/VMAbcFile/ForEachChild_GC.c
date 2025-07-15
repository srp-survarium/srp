void __thiscall Scaleform::GFx::AS3::VMAbcFile::ForEachChild_GC(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  _DWORD *p_EntryCount; // eax
  unsigned int v5; // ecx
  unsigned int v6; // edx
  _DWORD *v7; // eax
  _DWORD *v8; // edi
  signed int v9; // esi
  int v10; // eax
  bool v11; // zf
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **v12; // eax
  unsigned int v13; // eax
  _DWORD *v14; // ecx
  _DWORD *p_pTable; // ecx
  unsigned int v16; // eax
  unsigned int v17; // edx
  _DWORD *v18; // ecx
  _DWORD *v19; // edi
  signed int v20; // esi
  int v21; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **v22; // eax
  unsigned int v23; // eax
  _DWORD *v24; // ecx
  unsigned int Size; // edi
  unsigned int i; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *Data; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **p_pObject; // eax
  _DWORD *v29; // ecx
  unsigned int v30; // eax
  unsigned int v31; // edx
  _DWORD *v32; // ecx
  _DWORD *v33; // edi
  signed int v34; // esi
  int v35; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **v36; // eax
  unsigned int v37; // eax
  _DWORD *v38; // ecx
  unsigned int v39; // edi
  unsigned int j; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v41; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **v42; // eax

  Scaleform::GFx::AS3::VMFile::ForEachChild_GC(this, prcc, op);
  p_EntryCount = &this->AbsObjects.pTable->EntryCount;
  if ( p_EntryCount )
  {
    v6 = p_EntryCount[1];
    v5 = 0;
    v7 = p_EntryCount + 2;
    do
    {
      if ( *v7 != -2 )
        break;
      ++v5;
      v7 += 3;
    }
    while ( v5 <= v6 );
    p_EntryCount = &this->AbsObjects.pTable;
  }
  else
  {
    v5 = 0;
  }
  v8 = p_EntryCount;
  v9 = v5;
  while ( v8 )
  {
    v10 = *v8;
    if ( !*v8 || v9 > *(_DWORD *)(v10 + 4) )
      break;
    v11 = *(_DWORD *)(v10 + 12 * v9 + 16) == 0;
    v12 = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v10 + 12 * v9 + 16);
    if ( !v11 )
      op(prcc, v12, this);
    v13 = *(_DWORD *)(*v8 + 4);
    if ( v9 <= (int)v13 && ++v9 <= v13 )
    {
      v14 = (_DWORD *)(*v8 + 12 * v9 + 8);
      do
      {
        if ( *v14 != -2 )
          break;
        ++v9;
        v14 += 3;
      }
      while ( v9 <= v13 );
    }
  }
  p_pTable = &this->GlobalObjects.pTable->EntryCount;
  if ( p_pTable )
  {
    v17 = p_pTable[1];
    v16 = 0;
    v18 = p_pTable + 2;
    do
    {
      if ( *v18 != -2 )
        break;
      ++v16;
      v18 += 3;
    }
    while ( v16 <= v17 );
    p_pTable = &this->GlobalObjects.pTable;
  }
  else
  {
    v16 = 0;
  }
  v19 = p_pTable;
  v20 = v16;
  while ( v19 )
  {
    v21 = *v19;
    if ( !*v19 || v20 > *(_DWORD *)(v21 + 4) )
      break;
    v11 = *(_DWORD *)(v21 + 12 * v20 + 16) == 0;
    v22 = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v21 + 12 * v20 + 16);
    if ( !v11 )
      op(prcc, v22, this);
    v23 = *(_DWORD *)(*v19 + 4);
    if ( v20 <= (int)v23 && ++v20 <= v23 )
    {
      v24 = (_DWORD *)(*v19 + 12 * v20 + 8);
      do
      {
        if ( *v24 != -2 )
          break;
        ++v20;
        v24 += 3;
      }
      while ( v20 <= v23 );
    }
  }
  Size = this->Children.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    Data = this->Children.Data.Data;
    v11 = Data[i].pObject == 0;
    p_pObject = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&Data[i].pObject;
    if ( !v11 )
      op(prcc, p_pObject, this);
  }
  v29 = &this->FunctionTraitsCache.mHash.pTable->EntryCount;
  if ( v29 )
  {
    v31 = v29[1];
    v30 = 0;
    v32 = v29 + 2;
    do
    {
      if ( *v32 != -2 )
        break;
      ++v30;
      v32 += 4;
    }
    while ( v30 <= v31 );
    v29 = &this->FunctionTraitsCache.mHash.pTable;
  }
  else
  {
    v30 = 0;
  }
  v33 = v29;
  v34 = v30;
  while ( v33 )
  {
    v35 = *v33;
    if ( !*v33 || v34 > *(_DWORD *)(v35 + 4) )
      break;
    v11 = *(_DWORD *)(16 * v34 + v35 + 20) == 0;
    v36 = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)(16 * v34 + v35 + 20);
    if ( !v11 )
      op(prcc, v36, this);
    v37 = *(_DWORD *)(*v33 + 4);
    if ( v34 <= (int)v37 && ++v34 <= v37 )
    {
      v38 = (_DWORD *)(16 * v34 + *v33 + 8);
      do
      {
        if ( *v38 != -2 )
          break;
        ++v34;
        v38 += 4;
      }
      while ( v34 <= v37 );
    }
  }
  v39 = this->LoadedClasses.Data.Size;
  for ( j = 0; j < v39; ++j )
  {
    v41 = this->LoadedClasses.Data.Data;
    v11 = v41[j].pObject == 0;
    v42 = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v41[j].pObject;
    if ( !v11 )
      op(prcc, v42, this);
  }
}
