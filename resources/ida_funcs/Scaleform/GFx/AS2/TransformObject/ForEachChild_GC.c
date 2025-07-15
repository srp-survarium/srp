void __thiscall Scaleform::GFx::AS2::TransformObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        Scaleform::GFx::AS2::TransformObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::MatrixObject *pObject; // eax
  Scaleform::GFx::AS2::ColorTransformObject *v4; // eax
  Scaleform::GFx::AS2::RectangleObject *v5; // eax

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(this, prcc);
  pObject = this->Matrix.pObject;
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
  v4 = this->pColorTransform.pObject;
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
  v5 = this->PixelBounds.pObject;
  if ( v5 )
  {
    if ( (--v5->RefCount & 0x8000000) == 0 )
    {
      v5->RootIndex = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
      v5->pRCC = prcc->pLastPtr->pRCC;
      *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v5;
      prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v5;
      prcc->pLastPtr = v5;
      v5->RefCount |= 0x8000000u;
    }
  }
}


void __thiscall Scaleform::GFx::AS2::TransformObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
        Scaleform::GFx::AS2::TransformObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::MatrixObject *pObject; // esi
  Scaleform::GFx::AS2::ColorTransformObject *v4; // esi
  Scaleform::GFx::AS2::RectangleObject *v5; // esi

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(this, prcc);
  pObject = this->Matrix.pObject;
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
  v4 = this->pColorTransform.pObject;
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
      }
    }
  }
  v5 = this->PixelBounds.pObject;
  if ( v5 )
  {
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & --v5->RefCount) != 0 )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, v5);
      v5->RefCount |= (unsigned int)&vostok::memory::s_CRT_arena[55905848];
      if ( (v5->RefCount & 0x8000000) == 0 )
      {
        v5->RootIndex = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
        v5->pRCC = prcc->pLastPtr->pRCC;
        *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = v5;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v5;
        prcc->pLastPtr = v5;
        v5->RefCount |= 0x8000000u;
      }
    }
  }
}


void __thiscall Scaleform::GFx::AS2::TransformObject::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::TransformObject *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::MatrixObject *pObject; // eax
  unsigned int v4; // ecx
  Scaleform::GFx::AS2::ColorTransformObject *v5; // eax
  unsigned int v6; // ecx
  Scaleform::GFx::AS2::RectangleObject *v7; // eax
  unsigned int v8; // ecx

  Scaleform::GFx::AS2::Object::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(this, prcc);
  pObject = this->Matrix.pObject;
  if ( pObject )
  {
    v4 = ++pObject->RefCount;
    if ( (v4 & 0x70000000) != 0 )
    {
      pObject->RefCount = v4 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, pObject);
    }
  }
  v5 = this->pColorTransform.pObject;
  if ( v5 )
  {
    v6 = ++v5->RefCount;
    if ( (v6 & 0x70000000) != 0 )
    {
      v5->RefCount = v6 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, v5);
    }
  }
  v7 = this->PixelBounds.pObject;
  if ( v7 )
  {
    v8 = ++v7->RefCount;
    if ( (v8 & 0x70000000) != 0 )
    {
      v7->RefCount = v8 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, v7);
    }
  }
}
