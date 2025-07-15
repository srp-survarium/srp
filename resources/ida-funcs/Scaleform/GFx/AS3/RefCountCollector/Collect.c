char __thiscall Scaleform::GFx::AS3::RefCountCollector<328>::Collect(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        unsigned int uptoGeneration,
        const Scaleform::GFx::AS3::RefCountBaseGC<328> *upgradeGen,
        Scaleform::GFx::AS3::RefCountCollector<328>::Stats *pstat)
{
  unsigned int *p_totalObjsProcessed; // eax
  char v6; // dl
  bool v7; // zf
  Scaleform::RefCountVImpl *v8; // ecx
  unsigned __int8 Flags; // al
  unsigned int v10; // eax
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *Roots; // ecx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328> *i; // esi
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pRootHead; // eax
  int v15; // ecx
  unsigned int v16; // eax
  unsigned int nRoots; // ecx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>_vtbl *v19; // edx
  Scaleform::GFx::AS3::RefCountCollector<328> *v20; // edx
  int v21; // eax
  int v22; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v24; // eax
  unsigned int v25; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v26; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328> *pNext; // esi
  Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *p_ListRoot; // ebp
  unsigned int v29; // ebx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v30; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v31; // esi
  unsigned int RefCount; // eax
  int v33; // ecx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v34; // esi
  Scaleform::GFx::AS3::RefCountCollector<328> *v35; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *pTable; // ebp
  int v37; // ecx
  int v38; // eax
  int v39; // edx
  signed int v40; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v41; // eax
  _DWORD *SizeMask; // eax
  unsigned int v43; // eax
  int v44; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v45; // eax
  int v46; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v47; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v48; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v49; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v50; // ebp
  int v51; // ecx
  int v52; // eax
  int v53; // edx
  signed int v54; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v55; // eax
  _DWORD *v56; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *j; // esi
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v58; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *v59; // edx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pPrev; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v61; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v62; // ecx
  int v63; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v64; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v65; // eax
  Scaleform::GFx::AS3::RefCountCollector<328>::Stats *v66; // esi
  unsigned int v67; // eax
  Scaleform::AmpStats *v68; // ebp
  unsigned int v69; // eax
  unsigned int v70; // ecx
  bool hasFinalize; // [esp+19h] [ebp-21h]
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v73; // [esp+1Ah] [ebp-20h]
  unsigned int totalKillListSize; // [esp+1Eh] [ebp-1Ch]
  unsigned int rootsIterated; // [esp+22h] [ebp-18h]
  unsigned int initialNRoots; // [esp+26h] [ebp-14h]
  unsigned int totalObjsProcessed; // [esp+2Ah] [ebp-10h] BYREF
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *next; // [esp+2Eh] [ebp-Ch] BYREF
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v79; // [esp+32h] [ebp-8h]
  Scaleform::AmpStats *ampStats; // [esp+36h] [ebp-4h]

  p_totalObjsProcessed = (unsigned int *)pstat;
  this->Flags &= ~0x10u;
  v6 = 0;
  v7 = (this->Flags & 6) == 0;
  ampStats = 0;
  if ( v7 )
  {
    if ( p_totalObjsProcessed )
    {
      v8 = (Scaleform::RefCountVImpl *)totalObjsProcessed;
    }
    else
    {
      v8 = 0;
      v6 = 1;
      totalObjsProcessed = 0;
      p_totalObjsProcessed = &totalObjsProcessed;
    }
    ampStats = (Scaleform::AmpStats *)*p_totalObjsProcessed;
    if ( (v6 & 1) != 0 && v8 )
      Scaleform::RefCountImpl::Release(v8);
    this->Flags |= 4u;
    Flags = this->Flags;
    initialNRoots = 0;
    totalKillListSize = 0;
    totalObjsProcessed = 0;
    if ( (Flags & 0x20) != 0 )
    {
      v10 = 2;
      LOBYTE(upgradeGen) = 0;
      uptoGeneration = 2;
    }
    else
    {
      v10 = uptoGeneration;
    }
    this->CurrentMaxGen = v10;
    v79 = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v10 + 1);
    Roots = this->Roots;
    while ( 1 )
    {
      do
      {
        this->Flags |= 1u;
        v73 = Roots;
        v12 = v79;
        this->pLastPtr = &this->ListRoot;
        this->ListRoot.pPrev = &this->ListRoot;
        this->ListRoot.pNext = &this->ListRoot;
        this->ListRoot.RefCount |= (unsigned int)&vostok::memory::s_CRT_arena[5574200];
        this->Flags |= 8u;
        rootsIterated = 0;
        next = v12;
        do
        {
          for ( i = (Scaleform::GFx::AS3::RefCountCollector<328> *)v73->pRootHead; v73->pRootHead; ++rootsIterated )
          {
            pRootHead = i->Roots[0].pRootHead;
            v73->pRootHead = pRootHead;
            if ( pRootHead )
              pRootHead->pPrev = 0;
            i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                     & ~0x80000000);
            --v73->nRoots;
            v15 = (int)i->Roots[1].pRootHead;
            if ( (v15 & 0x70000000) == 0x30000000 )
            {
              v16 = i->RefCount & 3;
              if ( v16 > this->CurrentMaxGen )
              {
                i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v15 & 0x8FFFFFFF);
                i->Roots[0].pRootHead = this->Roots[v16].pRootHead;
                i->Roots[0].nRoots = 0;
                v26 = this->Roots[v16].pRootHead;
                if ( v26 )
                  v26->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                ++this->Roots[v16].nRoots;
                this->Roots[v16].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                         & 0xFFFFFFF
                                                                                         | 0xB0000000);
              }
              else
              {
                if ( v15 < 0 && (v15 & 0x1000000) == 0 )
                {
                  nRoots = i->Roots[0].nRoots;
                  if ( nRoots )
                    *(_DWORD *)(nRoots + 8) = i->Roots[0].pRootHead;
                  else
                    this->Roots[v16].pRootHead = i->Roots[0].pRootHead;
                  v18 = i->Roots[0].pRootHead;
                  if ( v18 )
                    v18->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i->Roots[0].nRoots;
                  i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                           & ~0x80000000);
                  i->Roots[0].pRootHead = 0;
                  i->Roots[0].nRoots = 0;
                  --this->Roots[v16].nRoots;
                }
                if ( (HIBYTE(i->Roots[1].pRootHead) & 1) == 0 )
                {
                  i->Roots[0].nRoots = (unsigned int)this->pLastPtr->pNext->pPrev;
                  i->Roots[0].pRootHead = this->pLastPtr->pNext;
                  this->pLastPtr->pNext->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                  this->pLastPtr->pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                  this->pLastPtr = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                  i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                           | (unsigned int)&vostok::memory::s_CRT_arena[5574200]);
                }
                if ( i != (Scaleform::GFx::AS3::RefCountCollector<328> *)&this->ListRoot )
                {
                  do
                  {
                    if ( (i->RefCount & 3u) > this->CurrentMaxGen )
                    {
                      v20 = (Scaleform::GFx::AS3::RefCountCollector<328> *)i->Roots[0].pRootHead;
                      if ( (HIBYTE(i->Roots[1].pRootHead) & 1) != 0 )
                      {
                        if ( (Scaleform::GFx::AS3::RefCountCollector<328> *)this->pLastPtr == i )
                          this->pLastPtr = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i->Roots[0].nRoots;
                        *(_DWORD *)(i->Roots[0].nRoots + 8) = i->Roots[0].pRootHead;
                        i->Roots[0].pRootHead->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i->Roots[0].nRoots;
                        i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                                 & ~0x1000000u);
                      }
                      v21 = (int)i->Roots[1].pRootHead;
                      if ( v21 < 0 )
                      {
                        v25 = v21 & 0x8FFFFFFF | 0x30000000;
                      }
                      else
                      {
                        i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v21 & 0x8FFFFFFF);
                        v22 = i->RefCount & 3;
                        v23 = this->Roots[v22].pRootHead;
                        v24 = &this->Roots[v22];
                        i->Roots[0].pRootHead = v23;
                        i->Roots[0].nRoots = 0;
                        if ( v24->pRootHead )
                          v24->pRootHead->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                        ++v24->nRoots;
                        v24->pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                        v25 = (int)i->Roots[1].pRootHead & 0xFFFFFFF | 0xB0000000;
                      }
                      i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)v25;
                    }
                    else
                    {
                      if ( ((int)i->Roots[1].pRootHead & 0x70000000) != 0x10000000 )
                      {
                        v19 = i->__vftable;
                        i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                                 & 0x8FFFFFFF
                                                                                                 | 0x10000000);
                        ((void (__thiscall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountCollector<328> *, void (__cdecl *)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **)))v19->~Scaleform::GFx::AS3::RefCountCollector<328>)(
                          i,
                          this,
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::MarkInCycleCall);
                      }
                      v20 = (Scaleform::GFx::AS3::RefCountCollector<328> *)i->Roots[0].pRootHead;
                    }
                    i = v20;
                  }
                  while ( v20 != (Scaleform::GFx::AS3::RefCountCollector<328> *)&this->ListRoot );
                }
              }
            }
            i = (Scaleform::GFx::AS3::RefCountCollector<328> *)v73->pRootHead;
          }
          ++v73;
          next = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)next - 1);
        }
        while ( next );
        this->Flags &= ~8u;
        if ( !rootsIterated )
        {
LABEL_133:
          v66 = pstat;
          if ( pstat )
          {
            pstat->RootsNumber = initialNRoots;
            v67 = initialNRoots;
            if ( initialNRoots >= totalKillListSize )
              v67 = totalKillListSize;
            v68 = ampStats;
            v66->RootsFreedTotal = v67;
            v69 = totalObjsProcessed;
            v66->ObjectsFreedTotal = totalKillListSize;
            v70 = (unsigned int)v79;
            v66->ObjectsIteratedNumber = v69;
            v66->GensNumber = v70;
            if ( v68 )
            {
              v68->AddGcRoots(v68, initialNRoots);
              v68->AddGcFreedRoots(v68, v66->RootsFreedTotal);
            }
          }
          else
          {
            v68 = ampStats;
          }
          this->Flags &= 0xDBu;
          Scaleform::GFx::AS3::RefCountCollector<328>::CleanDelayedReleaseProxies(this, v68);
          return 1;
        }
        pNext = (Scaleform::GFx::AS3::RefCountCollector<328> *)this->ListRoot.pNext;
        initialNRoots += rootsIterated;
        p_ListRoot = &this->ListRoot;
        hasFinalize = 0;
        if ( pNext != (Scaleform::GFx::AS3::RefCountCollector<328> *)&this->ListRoot )
        {
          v29 = totalObjsProcessed;
          do
          {
            v30 = pNext->Roots[1].pRootHead;
            ++v29;
            if ( ((unsigned int)&byte_3FFFFF & (unsigned int)v30) != 0 )
            {
              pNext->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((unsigned int)v30
                                                                                           & 0x8FFFFFFF);
              this->pLastPtr = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)pNext;
              ((void (__thiscall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountCollector<328> *, void (__cdecl *)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **)))pNext->~Scaleform::GFx::AS3::RefCountCollector<328>)(
                pNext,
                this,
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanInUseCall);
            }
            else
            {
              if ( ((unsigned int)v30 & 0x2000000) != 0 )
                hasFinalize = 1;
              pNext->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((unsigned int)v30
                                                                                           & 0x8FFFFFFF
                                                                                           | 0x20000000);
            }
            pNext = (Scaleform::GFx::AS3::RefCountCollector<328> *)pNext->Roots[0].pRootHead;
          }
          while ( pNext != (Scaleform::GFx::AS3::RefCountCollector<328> *)p_ListRoot );
          totalObjsProcessed = v29;
          if ( hasFinalize )
          {
            v31 = this->ListRoot.pNext;
            for ( this->pLastPtr = p_ListRoot; v31 != p_ListRoot; v31 = v31->pNext )
            {
              RefCount = v31->RefCount;
              v33 = (RefCount >> 28) & 7;
              if ( v33 == 2 )
              {
                if ( (RefCount & 0x2000000) != 0 )
                {
                  v31->RefCount = RefCount & 0x8FFFFFFF;
                  this->pLastPtr = v31;
                  v31->ForEachChild_GC(v31, this, Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanTempInUseCall);
                  v31->RefCount |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
                }
              }
              else if ( v33 == 5 )
              {
                v31->RefCount = RefCount & 0x8FFFFFFF;
                this->pLastPtr = v31;
                v31->ForEachChild_GC(v31, this, Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanTempInUseCall);
              }
            }
          }
        }
        v34 = this->ListRoot.pNext;
        this->pLastPtr = p_ListRoot;
        if ( v34 != p_ListRoot )
        {
          do
          {
            v35 = (Scaleform::GFx::AS3::RefCountCollector<328> *)v34->pNext;
            if ( (v34->RefCount & 0x70000000) == 0x20000000 )
            {
              if ( (v34->RefCount & 0x8000000) == 0 )
              {
                v34->pPrev->pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)v35;
                v34->pNext->pPrev = v34->pPrev;
                v34->RefCount &= ~0x1000000u;
                if ( (v34->RefCount & 0x4000000) != 0 )
                {
                  v34->RefCount &= ~0x4000000u;
                  pTable = this->WProxyHash.mHash.pTable;
                  next = v34;
                  if ( pTable )
                  {
                    v37 = 5381;
                    v38 = 4;
                    do
                    {
                      v39 = *((unsigned __int8 *)&totalObjsProcessed + v38-- + 3);
                      v37 = v39 + 65599 * v37;
                    }
                    while ( v38 );
                    v40 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::findIndexCore<Scaleform::GFx::ResourceId>(
                            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&this->WProxyHash,
                            (const unsigned int *)&next,
                            v37 & pTable->SizeMask);
                    if ( v40 >= 0 )
                    {
                      v41 = &pTable[2 * v40 + 2];
                      if ( v41 )
                      {
                        SizeMask = (_DWORD *)v41->SizeMask;
                        if ( SizeMask )
                        {
                          v7 = (*SizeMask)-- == 1;
                          SizeMask[1] = 0;
                          if ( v7 )
                            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, SizeMask);
                          next = v34;
                          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::GASRefCountBase *>(
                            &this->WProxyHash.mHash,
                            (Scaleform::GFx::AS3::GASRefCountBase **)&next);
                        }
                      }
                    }
                  }
                }
                v34->ForEachChild_GC(v34, this, Scaleform::GFx::AS3::RefCountBaseGC<328>::DisableCall);
                ((void (__thiscall *)(const Scaleform::GFx::AS3::RefCountBaseGC<328> *, int))v34->~Scaleform::GFx::AS3::RefCountBaseGC<328>)(
                  v34,
                  1);
                ++totalKillListSize;
              }
            }
            else
            {
              if ( (_BYTE)upgradeGen )
              {
                v43 = v34->pRCCRaw & 3;
                if ( v43 < 2 )
                  v34->pRCCRaw ^= ((unsigned __int8)v34->_pRCC ^ (unsigned __int8)(v43 + 1)) & 3;
              }
              v34->pPrev->pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)v35;
              v34->pNext->pPrev = v34->pPrev;
              v34->RefCount &= ~0x1000000u;
              v44 = v34->RefCount;
              if ( (v44 & 0x800000) != 0 )
              {
                v34->RefCount = v44 & 0xFF7FFFFF;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v34);
              }
              else if ( (v44 & 0x400000) != 0 )
              {
                v34->pNext = this->FinalizeRoots.pRootHead;
                v34->pPrev = 0;
                v45 = this->FinalizeRoots.pRootHead;
                if ( v45 )
                  v45->pPrev = v34;
                ++this->FinalizeRoots.nRoots;
                this->FinalizeRoots.pRootHead = v34;
                v34->RefCount |= 0x80000000;
              }
              else if ( (v44 & 0x70000000) == 0x30000000 && v44 >= 0 )
              {
                v34->RefCount = v44 & 0x8FFFFFFF;
                if ( (this->Flags & 8) == 0 )
                {
                  v46 = v34->pRCCRaw & 3;
                  v47 = this->Roots[v46].pRootHead;
                  v48 = &this->Roots[v46];
                  v34->pNext = v47;
                  v34->pPrev = 0;
                  if ( v48->pRootHead )
                    v48->pRootHead->pPrev = v34;
                  ++v48->nRoots;
                  v48->pRootHead = v34;
                  v34->RefCount = v34->RefCount & 0xFFFFFFF | 0xB0000000;
                }
              }
            }
            p_ListRoot = &this->ListRoot;
            v34 = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)v35;
          }
          while ( v35 != (Scaleform::GFx::AS3::RefCountCollector<328> *)&this->ListRoot );
        }
        v49 = this->ListRoot.pNext;
        if ( v49 != p_ListRoot )
        {
          do
          {
            next = v49->pNext;
            if ( (v49->RefCount & 0x4000000) != 0 )
            {
              v49->RefCount &= ~0x4000000u;
              v50 = this->WProxyHash.mHash.pTable;
              upgradeGen = v49;
              if ( v50 )
              {
                v51 = 5381;
                v52 = 4;
                do
                {
                  v53 = *((unsigned __int8 *)&uptoGeneration + v52-- + 3);
                  v51 = v53 + 65599 * v51;
                }
                while ( v52 );
                v54 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::findIndexCore<Scaleform::GFx::ResourceId>(
                        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&this->WProxyHash,
                        (const unsigned int *)&upgradeGen,
                        v51 & v50->SizeMask);
                if ( v54 >= 0 )
                {
                  v55 = &v50[2 * v54 + 2];
                  if ( v55 )
                  {
                    v56 = (_DWORD *)v55->SizeMask;
                    if ( v56 )
                    {
                      v7 = (*v56)-- == 1;
                      v56[1] = 0;
                      if ( v7 )
                        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v56);
                      upgradeGen = v49;
                      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::GASRefCountBase *>(
                        &this->WProxyHash.mHash,
                        (Scaleform::GFx::AS3::GASRefCountBase **)&upgradeGen);
                    }
                  }
                }
              }
            }
            v49->ForEachChild_GC(v49, this, Scaleform::GFx::AS3::RefCountBaseGC<328>::DisableCall);
            ((void (__thiscall *)(const Scaleform::GFx::AS3::RefCountBaseGC<328> *, int))v49->~Scaleform::GFx::AS3::RefCountBaseGC<328>)(
              v49,
              1);
            v49 = next;
            ++totalKillListSize;
            p_ListRoot = &this->ListRoot;
          }
          while ( next != &this->ListRoot );
        }
        this->pLastPtr = p_ListRoot;
        p_ListRoot->RefCount &= ~0x1000000u;
        this->Flags &= ~1u;
        if ( hasFinalize )
        {
          for ( j = this->FinalizeRoots.pRootHead; j; j = this->FinalizeRoots.pRootHead )
          {
            v58 = j->pNext;
            this->FinalizeRoots.pRootHead = v58;
            if ( v58 )
              v58->pPrev = 0;
            j->RefCount &= ~0x80000000;
            if ( (j->RefCount & 0x400000) != 0 )
            {
              v59 = j->__vftable;
              j->RefCount = (j->RefCount & 0xFDBFFFFF) + 1;
              v59->Finalize_GC(j);
              if ( (--j->RefCount & 0x80000000) != 0 && (j->RefCount & 0x1000000) == 0 )
              {
                pPrev = j->pPrev;
                v61 = &this->Roots[j->pRCCRaw & 3];
                if ( pPrev )
                  pPrev->pNext = j->pNext;
                else
                  v61->pRootHead = j->pNext;
                v62 = j->pNext;
                if ( v62 )
                  v62->pPrev = j->pPrev;
                j->RefCount &= ~0x80000000;
                j->pNext = 0;
                j->pPrev = 0;
                --v61->nRoots;
              }
              j->pRCCRaw &= 0xFFFFFFFC;
              j->RefCount &= 0x8FFFFFFF;
              if ( (this->Flags & 8) == 0 )
              {
                v63 = j->pRCCRaw & 3;
                v64 = this->Roots[v63].pRootHead;
                v65 = &this->Roots[v63];
                j->pNext = v64;
                j->pPrev = 0;
                if ( v65->pRootHead )
                  v65->pRootHead->pPrev = j;
                ++v65->nRoots;
                v65->pRootHead = j;
                j->RefCount = j->RefCount & 0xFFFFFFF | 0xB0000000;
              }
            }
          }
        }
        Roots = this->Roots;
        LOBYTE(upgradeGen) = 0;
      }
      while ( this->Roots[0].pRootHead );
      if ( uptoGeneration != 2 )
        break;
      if ( !this->Roots[2].pRootHead )
      {
LABEL_132:
        if ( !this->Roots[1].pRootHead )
          goto LABEL_133;
      }
    }
    if ( !uptoGeneration )
      goto LABEL_133;
    goto LABEL_132;
  }
  if ( p_totalObjsProcessed )
  {
    p_totalObjsProcessed[5] = 0;
    p_totalObjsProcessed[4] = 0;
    p_totalObjsProcessed[3] = 0;
    p_totalObjsProcessed[2] = 0;
    p_totalObjsProcessed[1] = 0;
  }
  return 0;
}
