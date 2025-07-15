void __thiscall Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::Object *pObject; // eax
  Scaleform::GFx::AS2::Object *v4; // eax

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(this, prcc);
  pObject = this->SuperProto.pObject;
  if ( pObject )
  {
    if ( (--pObject->RefCount & 0x8000000) == 0 )
    {
      pObject->RootIndex = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
      pObject->pRCC = prcc->pLastPtr->pRCC;
      *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = pObject;
      prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pObject;
      prcc->pLastPtr = pObject;
      pObject->RefCount |= 0x8000000u;
    }
  }
  v4 = this->SavedProto.pObject;
  if ( v4 )
  {
    if ( (--v4->RefCount & 0x8000000) == 0 )
    {
      v4->RootIndex = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
      v4->pRCC = prcc->pLastPtr->pRCC;
      *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v4;
      prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v4;
      prcc->pLastPtr = v4;
      v4->RefCount |= 0x8000000u;
    }
  }
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
    &this->Constructor,
    prcc);
}


void __thiscall Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::Object *pObject; // esi
  Scaleform::GFx::AS2::Object *v4; // esi

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(this, prcc);
  pObject = this->SuperProto.pObject;
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
  v4 = this->SavedProto.pObject;
  if ( v4 )
  {
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & --v4->RefCount) != 0 )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, v4);
      v4->RefCount |= (unsigned int)&vostok::memory::s_CRT_arena[55905848];
      if ( (v4->RefCount & 0x8000000) == 0 )
      {
        v4->RootIndex = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
        v4->pRCC = prcc->pLastPtr->pRCC;
        *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v4;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v4;
        prcc->pLastPtr = v4;
        v4->RefCount |= 0x8000000u;
        Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
          &this->Constructor,
          prcc);
        return;
      }
    }
  }
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
    &this->Constructor,
    prcc);
}


void __thiscall Scaleform::GFx::AS2::SuperObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::Object *pObject; // eax
  unsigned int v4; // ecx
  Scaleform::GFx::AS2::Object *v5; // eax
  unsigned int v6; // ecx

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(this, prcc);
  pObject = this->SuperProto.pObject;
  if ( pObject )
  {
    v4 = ++pObject->RefCount;
    if ( (v4 & 0x70000000) != 0 )
    {
      pObject->RefCount = v4 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, pObject);
    }
  }
  v5 = this->SavedProto.pObject;
  if ( v5 )
  {
    v6 = ++v5->RefCount;
    if ( (v6 & 0x70000000) != 0 )
    {
      v5->RefCount = v6 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, v5);
    }
  }
  Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
    &this->Constructor,
    prcc);
}
