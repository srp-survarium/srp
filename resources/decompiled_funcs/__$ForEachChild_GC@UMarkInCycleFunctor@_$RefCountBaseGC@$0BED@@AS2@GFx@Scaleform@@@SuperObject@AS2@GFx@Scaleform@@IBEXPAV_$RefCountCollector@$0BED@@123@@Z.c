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
