char __thiscall Scaleform::GFx::AS2::RefCountCollector<323>::Collect(
        Scaleform::GFx::AS2::RefCountCollector<323> *this,
        Scaleform::GFx::AS2::RefCountCollector<323>::Stats *pstat)
{
  unsigned int v3; // ebp
  Scaleform::GFx::AS2::RefCountCollector<323>::Root *p_ListRoot; // ebx
  Scaleform::GFx::AS2::RefCountCollector<323>::Root *v5; // eax
  unsigned int RefCount; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pNext; // esi
  Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *v8; // edx
  int v9; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *i; // esi
  unsigned int v11; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // esi
  Scaleform::GFx::AS2::RefCountCollector<323>::Root *pRCC; // ebp
  int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  unsigned int Size; // eax
  unsigned int v18; // eax
  unsigned int v20; // [esp+8h] [ebp-Ch]
  unsigned int initialNRoots; // [esp+Ch] [ebp-8h]
  unsigned int totalKillListSize; // [esp+10h] [ebp-4h]

  if ( (this->Flags & 1) != 0 || (v3 = 0, (v20 = this->Roots.Size) == 0) )
  {
    if ( pstat )
    {
      pstat->RootsNumber = 0;
      pstat->RootsFreedTotal = 0;
    }
    return 0;
  }
  else
  {
    initialNRoots = 0;
    totalKillListSize = 0;
    p_ListRoot = &this->ListRoot;
    do
    {
      initialNRoots += v20;
      this->pLastPtr = p_ListRoot;
      this->ListRoot.RootIndex = (unsigned int)p_ListRoot;
      this->ListRoot.pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)p_ListRoot;
      this->ListRoot.RefCount |= 0x8000000u;
      if ( v20 )
      {
        do
        {
          v5 = (Scaleform::GFx::AS2::RefCountCollector<323>::Root *)this->Roots.Pages[v3 >> 10][v3 & 0x3FF];
          if ( ((unsigned __int8)v5 & 1) == 0 )
          {
            RefCount = v5->RefCount;
            pNext = this->Roots.Pages[v3 >> 10][v3 & 0x3FF];
            if ( (RefCount & 0x70000000) == 0x30000000 )
            {
              if ( (RefCount & 0x8000000) == 0 )
              {
                v5->RootIndex = *(_DWORD *)&this->pLastPtr->pRCC->Roots.gap0;
                v5->pRCC = this->pLastPtr->pRCC;
                *(_DWORD *)&this->pLastPtr->pRCC->Roots.gap0 = v5;
                this->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v5;
                this->pLastPtr = v5;
                v5->RefCount |= 0x8000000u;
              }
              if ( v5 != p_ListRoot )
              {
                do
                {
                  if ( (pNext->RefCount & 0x70000000) != 0x10000000 )
                  {
                    v8 = pNext->__vftable;
                    pNext->RefCount = pNext->RefCount & 0x8FFFFFFF | 0x10000000;
                    v8->ExecuteForEachChild_GC(pNext, this, Operation_MarkInCycle);
                  }
                  pNext = pNext->pNext;
                }
                while ( pNext != p_ListRoot );
              }
            }
            else
            {
              v9 = RefCount & 0x7FFFFFFF;
              v5->RefCount = v9;
              if ( (v9 & 0x8000000) == 0 )
                v5->RootIndex = -1;
            }
          }
          ++v3;
        }
        while ( v3 < v20 );
      }
      this->FirstFreeRootIndex = -1;
      if ( this->Roots.Size )
        this->Roots.Size = 0;
      for ( i = this->ListRoot.pNext; i != p_ListRoot; i = i->pNext )
      {
        v11 = i->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v11) != 0 )
        {
          i->RefCount = v11 & 0x8FFFFFFF;
          this->pLastPtr = i;
          i->ExecuteForEachChild_GC(i, this, Operation_ScanInUse);
        }
        else
        {
          i->RefCount = v11 & 0x8FFFFFFF | 0x20000000;
        }
      }
      v12 = this->ListRoot.pNext;
      if ( v12 != p_ListRoot )
      {
        do
        {
          pRCC = (Scaleform::GFx::AS2::RefCountCollector<323>::Root *)v12->pRCC;
          if ( (v12->RefCount & 0x70000000) == 0x20000000 )
          {
            v12->Finalize_GC(v12);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
            ++totalKillListSize;
          }
          else
          {
            v14 = v12->RefCount & 0x77FFFFFF;
            v12->pRCC = this;
            v12->RefCount = v14;
            if ( (v14 & 0x8000000) == 0 )
              v12->RootIndex = -1;
            if ( (v14 & 0x4000000) != 0 )
            {
              v12->RefCount = v14 & 0xFBFFFFFF;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
            }
            else if ( (v14 & 0x70000000) == 0x30000000 )
            {
              Scaleform::GFx::AS2::RefCountCollector<323>::AddRoot(this, v12);
            }
            else
            {
              v15 = v14 & 0x7FFFFFFF;
              v12->RefCount = v15;
              if ( (v15 & 0x8000000) == 0 )
                v12->RootIndex = -1;
            }
          }
          v12 = pRCC;
        }
        while ( pRCC != p_ListRoot );
      }
      this->pLastPtr = p_ListRoot;
      this->ListRoot.RefCount &= 0x77FFFFFFu;
      v3 = 0;
      v16 = this->ListRoot.RefCount >> 27;
      this->ListRoot.pRCC = 0;
      if ( (v16 & 1) == 0 )
        this->ListRoot.RootIndex = -1;
      Size = this->Roots.Size;
      this->FirstFreeRootIndex = -1;
      v20 = Size;
    }
    while ( Size );
    if ( pstat )
    {
      v18 = initialNRoots;
      pstat->RootsNumber = initialNRoots;
      if ( initialNRoots >= totalKillListSize )
        v18 = totalKillListSize;
      pstat->RootsFreedTotal = v18;
    }
    return 1;
  }
}
