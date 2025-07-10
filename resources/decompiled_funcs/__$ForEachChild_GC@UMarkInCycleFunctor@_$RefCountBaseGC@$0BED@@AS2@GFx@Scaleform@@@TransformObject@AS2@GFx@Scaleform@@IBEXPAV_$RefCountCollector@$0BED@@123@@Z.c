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
