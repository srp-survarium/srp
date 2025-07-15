void __thiscall Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  unsigned __int8 Type; // dl
  Scaleform::GFx::ASStringNode *pStringNode; // eax

  Type = this->T.Type;
  if ( this->T.Type == 8 )
  {
    Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
      &this->V.FunctionValue,
      prcc);
    return;
  }
  if ( Type != 6 || (pStringNode = this->V.pStringNode) == 0 )
  {
    if ( Type != 9 )
      return;
    pStringNode = this->V.pStringNode;
  }
  if ( (--pStringNode->RefCount & 0x8000000) == 0 )
  {
    pStringNode->pLower = *(Scaleform::GFx::ASStringNode **)&prcc->pLastPtr->pRCC->Roots.gap0;
    pStringNode->pManager = (Scaleform::GFx::ASStringManager *)prcc->pLastPtr->pRCC;
    *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = pStringNode;
    prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pStringNode;
    prcc->pLastPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode;
    pStringNode->RefCount |= 0x8000000u;
  }
}


void __thiscall Scaleform::GFx::AS2::Value::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObjectValue; // esi

  Type = this->T.Type;
  if ( this->T.Type == 8 )
  {
    Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      &this->V.FunctionValue,
      prcc);
    return;
  }
  if ( Type != 6 || (pObjectValue = this->V.pObjectValue) == 0 )
  {
    if ( Type != 9 )
      return;
    pObjectValue = this->V.pObjectValue;
  }
  if ( (--pObjectValue->RefCount & 0x3FFFFFF) != 0 )
  {
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObjectValue);
  }
  else
  {
    Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, pObjectValue);
    pObjectValue->RefCount |= 0x4000000u;
    if ( (pObjectValue->RefCount & 0x8000000) == 0 )
    {
      pObjectValue->RootIndex = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
      pObjectValue->pRCC = prcc->pLastPtr->pRCC;
      *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = pObjectValue;
      prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pObjectValue;
      prcc->pLastPtr = pObjectValue;
      pObjectValue->RefCount |= 0x8000000u;
    }
  }
}
