void __thiscall Scaleform::GFx::AS3::VMFile::ForEachChild_GC(
        Scaleform::GFx::AS3::VMFile *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  unsigned int Size; // edi
  unsigned int i; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet> *Data; // ecx
  _DWORD *p_EntryCount; // ecx
  unsigned int v8; // eax
  unsigned int v9; // edx
  _DWORD *v10; // ecx
  _DWORD *v11; // edi
  signed int v12; // esi
  int v13; // eax
  bool v14; // zf
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **v15; // eax
  unsigned int v16; // eax
  _DWORD *v17; // ecx

  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::ForEachChild_GC(
    &this->IntNamespaces,
    prcc,
    op,
    this);
  Size = this->IntNamespaceSets.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    Data = this->IntNamespaceSets.Data.Data;
    if ( Data[i].pObject )
      op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&Data[i].pObject, this);
  }
  p_EntryCount = &this->ActivationTraitsCache.mHash.pTable->EntryCount;
  if ( p_EntryCount )
  {
    v9 = p_EntryCount[1];
    v8 = 0;
    v10 = p_EntryCount + 2;
    do
    {
      if ( *v10 != -2 )
        break;
      ++v8;
      v10 += 4;
    }
    while ( v8 <= v9 );
    p_EntryCount = &this->ActivationTraitsCache.mHash.pTable;
  }
  else
  {
    v8 = 0;
  }
  v11 = p_EntryCount;
  v12 = v8;
  while ( v11 )
  {
    v13 = *v11;
    if ( !*v11 || v12 > *(_DWORD *)(v13 + 4) )
      break;
    v14 = *(_DWORD *)(16 * v12 + v13 + 20) == 0;
    v15 = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)(16 * v12 + v13 + 20);
    if ( !v14 )
      op(prcc, v15, this);
    v16 = *(_DWORD *)(*v11 + 4);
    if ( v12 <= (int)v16 && ++v12 <= v16 )
    {
      v17 = (_DWORD *)(16 * v12 + *v11 + 8);
      do
      {
        if ( *v17 != -2 )
          break;
        ++v12;
        v17 += 4;
      }
      while ( v12 <= v16 );
    }
  }
}
