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
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & --pObjectValue->RefCount) != 0 )
  {
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObjectValue);
  }
  else
  {
    Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, pObjectValue);
    pObjectValue->RefCount |= (unsigned int)&vostok::memory::s_CRT_arena[55905848];
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
