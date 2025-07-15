void __thiscall Scaleform::GFx::AS3::Object::ForEachChild_GC(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  _DWORD *p_EntryCount; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // ecx
  _DWORD *v8; // edi
  signed int v9; // esi
  int v10; // eax
  const Scaleform::GFx::AS3::Value *v11; // eax
  unsigned int v12; // eax
  _DWORD *v13; // ecx
  Scaleform::GFx::AS3::Traits *pObject; // ecx

  p_EntryCount = &this->DynAttrs.mHash.pTable->EntryCount;
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
      v7 += 8;
    }
    while ( v5 <= v6 );
    p_EntryCount = &this->DynAttrs.mHash.pTable;
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
    v11 = (const Scaleform::GFx::AS3::Value *)(32 * v9 + v10 + 24);
    if ( (v11->Flags & 0x1F) > 0xA && (v11->Flags & 0x200) == 0 )
      Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, v11, op, this);
    v12 = *(_DWORD *)(*v8 + 4);
    if ( v9 <= (int)v12 && ++v9 <= v12 )
    {
      v13 = (_DWORD *)(32 * v9 + *v8 + 8);
      do
      {
        if ( *v13 != -2 )
          break;
        ++v9;
        v13 += 8;
      }
      while ( v9 <= v12 );
    }
  }
  pObject = this->pTraits.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::Traits::ForEachChild_GC_Slot(pObject, prcc, this, op);
  if ( this->pTraits.pObject )
    op(prcc, &this->pTraits.pObject, this);
}
