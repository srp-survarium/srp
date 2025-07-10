void __thiscall Scaleform::GFx::AS2::LocalFrame::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
        Scaleform::GFx::AS2::LocalFrame *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  _DWORD *p_EntryCount; // ecx
  unsigned int v4; // eax
  unsigned int v5; // edx
  _DWORD *v6; // ecx
  _DWORD *v7; // edi
  signed int v8; // esi
  int v9; // eax
  unsigned int v10; // eax
  _DWORD *v11; // ecx
  Scaleform::GFx::AS2::LocalFrame *pObject; // esi

  p_EntryCount = &this->Variables.mHash.pTable->EntryCount;
  if ( p_EntryCount )
  {
    v5 = p_EntryCount[1];
    v4 = 0;
    v6 = p_EntryCount + 2;
    do
    {
      if ( *v6 != -2 )
        break;
      ++v4;
      v6 += 6;
    }
    while ( v4 <= v5 );
    p_EntryCount = &this->Variables.mHash.pTable;
  }
  else
  {
    v4 = 0;
  }
  v7 = p_EntryCount;
  v8 = v4;
  while ( v7 )
  {
    v9 = *v7;
    if ( !*v7 || v8 > *(_DWORD *)(v9 + 4) )
      break;
    Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      (Scaleform::GFx::AS2::Value *)(v9 + 24 * v8 + 16),
      prcc);
    v10 = *(_DWORD *)(*v7 + 4);
    if ( v8 <= (int)v10 && ++v8 <= v10 )
    {
      v11 = (_DWORD *)(*v7 + 24 * v8 + 8);
      do
      {
        if ( *v11 != -2 )
          break;
        ++v8;
        v11 += 6;
      }
      while ( v8 <= v10 );
    }
  }
  pObject = this->PrevFrame.pObject;
  if ( pObject )
  {
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & --pObject->RefCount) != 0 )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, pObject);
      pObject->RefCount |= (unsigned int)&vostok::memory::s_CRT_arena[55905848];
      if ( (pObject->RefCount & 0x8000000) == 0 )
      {
        pObject->RootIndex = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
        pObject->pRCC = prcc->pLastPtr->pRCC;
        *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = pObject;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pObject;
        prcc->pLastPtr = pObject;
        pObject->RefCount |= 0x8000000u;
      }
    }
  }
  Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
    &this->Callee,
    prcc);
  Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
    &this->Caller,
    prcc);
}
