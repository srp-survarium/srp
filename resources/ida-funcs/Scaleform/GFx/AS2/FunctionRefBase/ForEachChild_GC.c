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


void __thiscall Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
        Scaleform::GFx::AS2::FunctionRefBase *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // esi

  Function = this->Function;
  if ( this->Function )
  {
    if ( (--Function->RefCount & 0x3FFFFFF) != 0 )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, Function);
      Function->RefCount |= 0x4000000u;
      if ( (Function->RefCount & 0x8000000) == 0 )
      {
        Function->RootIndex = *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0;
        Function->pRCC = prcc->pLastPtr->pRCC;
        *(_DWORD *)&prcc->pLastPtr->pRCC->Roots.gap0 = Function;
        prcc->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)Function;
        prcc->pLastPtr = Function;
        Function->RefCount |= 0x8000000u;
      }
    }
  }
  pLocalFrame = this->pLocalFrame;
  if ( pLocalFrame )
  {
    if ( (--pLocalFrame->RefCount & 0x3FFFFFF) != 0 )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, pLocalFrame);
      pLocalFrame->RefCount |= 0x4000000u;
      if ( (pLocalFrame->RefCount & 0x8000000) == 0 )
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
}


void __thiscall Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
        Scaleform::GFx::AS2::FunctionRefBase *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc)
{
  Scaleform::GFx::AS2::RefCountCollector<323> *Function; // eax
  unsigned int v4; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323> *pLocalFrame; // eax
  unsigned int v6; // ecx

  Function = (Scaleform::GFx::AS2::RefCountCollector<323> *)this->Function;
  if ( this->Function )
  {
    v4 = ++Function->Roots.Size;
    if ( (v4 & 0x70000000) != 0 )
    {
      Function->Roots.Size = v4 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, Function);
    }
  }
  pLocalFrame = (Scaleform::GFx::AS2::RefCountCollector<323> *)this->pLocalFrame;
  if ( pLocalFrame )
  {
    v6 = ++pLocalFrame->Roots.Size;
    if ( (v6 & 0x70000000) != 0 )
    {
      pLocalFrame->Roots.Size = v6 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, pLocalFrame);
    }
  }
}
