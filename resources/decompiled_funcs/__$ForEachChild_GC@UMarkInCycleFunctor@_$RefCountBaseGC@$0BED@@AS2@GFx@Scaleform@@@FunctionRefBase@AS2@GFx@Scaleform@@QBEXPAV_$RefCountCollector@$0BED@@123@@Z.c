void __thiscall Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        Scaleform::GFx::AS2::FunctionRefBase *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  Function = this->Function;
  if ( this->Function )
  {
    if ( (--Function->RefCount & 0x8000000) == 0 )
    {
      Function->RootIndex = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
      Function->pRCC = prcc->pLastPtr->pRCC;
      *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = Function;
      prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)Function;
      prcc->pLastPtr = Function;
      Function->RefCount |= 0x8000000u;
    }
  }
  pLocalFrame = this->pLocalFrame;
  if ( pLocalFrame )
  {
    if ( (--pLocalFrame->RefCount & 0x8000000) == 0 )
    {
      pLocalFrame->RootIndex = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
      pLocalFrame->pRCC = prcc->pLastPtr->pRCC;
      *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = pLocalFrame;
      prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pLocalFrame;
      prcc->pLastPtr = pLocalFrame;
      pLocalFrame->RefCount |= 0x8000000u;
    }
  }
}
