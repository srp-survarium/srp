void __thiscall Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(
        Scaleform::GFx::AS2::RefCountBaseGC<323> *this)
{
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pNext; // ecx
  unsigned int v5; // eax
  int v6; // eax
  Scaleform::GFx::AS2::RefCountCollector<323> *v7; // eax
  unsigned int v8; // edx
  Scaleform::GFx::AS2::RefCountCollector<323>::Root *p_ListRoot; // eax
  int v10; // eax

  RefCount = this->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) == 0 )
  {
    if ( (RefCount & 0x8000000) != 0 )
    {
      this->RefCount = (unsigned int)&vostok::memory::s_CRT_arena[55905848] | RefCount;
      return;
    }
    pRCC = this->pRCC;
    if ( (pRCC->ListRoot.RefCount & 0x8000000) != 0 )
    {
      this->ExecuteForEachChild_GC(this, pRCC, Operation_Release);
    }
    else
    {
      pRCC->pLastPtr = &pRCC->ListRoot;
      this->pRCC->ListRoot.RootIndex = (unsigned int)&this->pRCC->ListRoot;
      this->pRCC->ListRoot.pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)this->pRCC->ListRoot.RootIndex;
      this->pRCC->ListRoot.RefCount |= 0x8000000u;
      this->ExecuteForEachChild_GC(this, this->pRCC, Operation_Release);
      while ( this->pRCC->ListRoot.pRCC != (Scaleform::GFx::AS2::RefCountCollector<323> *)&this->pRCC->ListRoot )
      {
        pNext = this->pRCC->ListRoot.pNext;
        *(_DWORD *)(pNext->RootIndex + 4) = pNext->pRCC;
        *(_DWORD *)&pNext->pRCC->Roots.gap0 = pNext->RootIndex;
        pNext->RefCount &= 0x77FFFFFFu;
        v5 = pNext->RefCount;
        pNext->pRCC = 0;
        if ( (v5 & 0x8000000) == 0 )
          pNext->RootIndex = -1;
        v6 = v5 & 0x77FFFFFF;
        pNext->pRCC = this->pRCC;
        pNext->RefCount = v6;
        if ( (v6 & 0x8000000) == 0 )
          pNext->RootIndex = -1;
        pNext->RefCount = v6 & 0xFBFFFFFF;
        this->pRCC->pLastPtr = this->pRCC->ListRoot.pPrev;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pNext);
      }
      v7 = this->pRCC;
      v7->ListRoot.RefCount &= 0x77FFFFFFu;
      v8 = v7->ListRoot.RefCount;
      p_ListRoot = &v7->ListRoot;
      p_ListRoot->pRCC = 0;
      if ( (v8 & 0x8000000) == 0 )
        p_ListRoot->RootIndex = -1;
    }
    this->RefCount &= 0x8FFFFFFF;
    if ( (this->RefCount & 0x80000000) != 0 )
    {
      if ( (this->RefCount & 0x8000000) == 0 )
      {
        Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(this->pRCC, this);
        goto LABEL_17;
      }
    }
    else if ( (this->RefCount & 0x8000000) == 0 )
    {
LABEL_17:
      this->Finalize_GC(this);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
      return;
    }
    Scaleform::GFx::AS2::RefCountBaseGC<323>::RemoveFromList(this);
    goto LABEL_17;
  }
  if ( (RefCount & 0x70000000) != 0x30000000 )
  {
    v10 = RefCount & 0x8FFFFFFF | 0x30000000;
    this->RefCount = v10;
    if ( (v10 & 0x8000000) == 0 && v10 >= 0 )
      Scaleform::GFx::AS2::RefCountCollector<323>::AddRoot(this->pRCC, this);
  }
}
