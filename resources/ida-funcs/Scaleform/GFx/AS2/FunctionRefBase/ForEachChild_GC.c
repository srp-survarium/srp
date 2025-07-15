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
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & --Function->RefCount) != 0 )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, Function);
      Function->RefCount |= (unsigned int)&vostok::memory::s_CRT_arena[55905848];
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
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & --pLocalFrame->RefCount) != 0 )
    {
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
    }
    else
    {
      Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(prcc, pLocalFrame);
      pLocalFrame->RefCount |= (unsigned int)&vostok::memory::s_CRT_arena[55905848];
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
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  unsigned int v4; // ecx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  unsigned int v6; // ecx

  Function = this->Function;
  if ( this->Function )
  {
    v4 = ++Function->RefCount;
    if ( (v4 & 0x70000000) != 0 )
    {
      Function->RefCount = v4 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, Function);
    }
  }
  pLocalFrame = this->pLocalFrame;
  if ( pLocalFrame )
  {
    v6 = ++pLocalFrame->RefCount;
    if ( (v6 & 0x70000000) != 0 )
    {
      pLocalFrame->RefCount = v6 & 0x8FFFFFFF;
      Scaleform::GFx::AS2::RefCountCollector<323>::ReinsertToList(prcc, pLocalFrame);
    }
  }
}
