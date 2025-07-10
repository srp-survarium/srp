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
