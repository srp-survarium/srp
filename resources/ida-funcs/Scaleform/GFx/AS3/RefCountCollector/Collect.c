char __thiscall Scaleform::GFx::AS3::RefCountCollector<328>::Collect(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        unsigned int uptoGeneration,
        bool upgradeGen,
        Scaleform::GFx::AS3::RefCountCollector<328>::Stats *pstat)
{
  char v5; // dl
  bool v6; // zf
  Scaleform::GFx::AS3::RefCountCollector<328>::Stats *p_totalObjsProcessed; // eax
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::AmpStats *pObject; // esi
  unsigned __int8 Flags; // al
  unsigned int v11; // eax
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *Roots; // esi
  Scaleform::AmpStats *v13; // ebp
  unsigned int v14; // ebx
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v16; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v17; // eax
  Scaleform::GFx::AS3::RefCountCollector<328> *i; // esi
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pRootHead; // eax
  int v20; // ecx
  unsigned int v21; // eax
  unsigned int nRoots; // ecx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>_vtbl *v24; // edx
  Scaleform::GFx::AS3::RefCountCollector<328> *v25; // edx
  int v26; // eax
  int v27; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v28; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v29; // eax
  unsigned int v30; // eax
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pNext; // esi
  Scaleform::AmpServer *v34; // eax
  Scaleform::AmpServer *v35; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v36; // ecx
  unsigned __int64 v37; // rax
  Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *j; // ebp
  unsigned int RefCount; // eax
  void (__thiscall **v40)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v41; // rax
  Scaleform::AmpServer *v42; // eax
  Scaleform::AmpServer *v43; // eax
  unsigned __int64 v44; // rax
  Scaleform::AmpStats_vtbl *v45; // ebx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v46; // esi
  unsigned int v47; // eax
  int v48; // ecx
  Scaleform::GFx::AS3::GASRefCountBase *v49; // esi
  Scaleform::GFx::AS3::RefCountCollector<328> *v50; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *pTable; // ebp
  int v52; // ecx
  int v53; // eax
  int v54; // edx
  signed int v55; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v56; // eax
  _DWORD *SizeMask; // eax
  unsigned int v58; // eax
  int v59; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v60; // eax
  int v61; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v62; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v63; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v64; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v65; // ebp
  int v66; // ecx
  int v67; // eax
  int v68; // edx
  signed int v69; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v70; // eax
  _DWORD *v71; // eax
  void (__thiscall **v72)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v73; // rax
  Scaleform::AmpServer *v74; // eax
  Scaleform::AmpServer *v75; // eax
  unsigned __int64 v76; // rax
  Scaleform::AmpStats_vtbl *v77; // esi
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *k; // esi
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v79; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *v80; // edx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pPrev; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v82; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v83; // ecx
  int v84; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v85; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v86; // eax
  Scaleform::AmpStats *v87; // ebp
  void (__thiscall **v88)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v89; // rax
  unsigned int v90; // eax
  unsigned int v91; // eax
  unsigned int v92; // ecx
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **v94)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v95; // rax
  unsigned __int64 v97; // [esp+5Ch] [ebp-8Ch]
  unsigned __int64 v98; // [esp+5Ch] [ebp-8Ch]
  bool hasFinalize; // [esp+77h] [ebp-71h]
  Scaleform::AmpStats *ampStats; // [esp+78h] [ebp-70h]
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v101; // [esp+7Ch] [ebp-6Ch]
  unsigned int totalKillListSize; // [esp+80h] [ebp-68h]
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *next; // [esp+84h] [ebp-64h]
  Scaleform::GFx::AS3::RefCountCollector<328> *nexta; // [esp+84h] [ebp-64h]
  unsigned int initialNRoots; // [esp+88h] [ebp-60h]
  unsigned int totalObjsProcessed; // [esp+8Ch] [ebp-5Ch] BYREF
  Scaleform::GFx::AS3::GASRefCountBase *key; // [esp+90h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::GASRefCountBase *v108; // [esp+94h] [ebp-54h]
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_GcMarkInCycle; // [esp+98h] [ebp-50h]
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_GcFreeGarbage; // [esp+A8h] [ebp-40h]
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_GcFinalize; // [esp+B8h] [ebp-30h]
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_GcScanInUse; // [esp+C8h] [ebp-20h]
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_GcCollect; // [esp+D8h] [ebp-10h] BYREF

  this->Flags &= ~0x10u;
  v5 = 0;
  v6 = (this->Flags & 6) == 0;
  p_totalObjsProcessed = pstat;
  v108 = 0;
  if ( v6 )
  {
    if ( pstat )
    {
      v8 = (Scaleform::RefCountVImpl *)totalObjsProcessed;
    }
    else
    {
      v8 = 0;
      v5 = 1;
      totalObjsProcessed = 0;
      p_totalObjsProcessed = (Scaleform::GFx::AS3::RefCountCollector<328>::Stats *)&totalObjsProcessed;
    }
    pObject = p_totalObjsProcessed->AdvanceStats.pObject;
    ampStats = p_totalObjsProcessed->AdvanceStats.pObject;
    if ( (v5 & 1) != 0 && v8 )
      Scaleform::RefCountImpl::Release(v8);
    Scaleform::AmpFunctionTimer::AmpFunctionTimer(
      &_amp_timer_Amp_Native_Function_Id_GcCollect,
      pObject,
      "GC::Collect",
      Amp_Profile_Level_Low,
      Amp_Native_Function_Id_GcCollect);
    this->Flags |= 4u;
    Flags = this->Flags;
    initialNRoots = 0;
    totalKillListSize = 0;
    totalObjsProcessed = 0;
    if ( (Flags & 0x20) != 0 )
    {
      v11 = 2;
      upgradeGen = 0;
      uptoGeneration = 2;
    }
    else
    {
      v11 = uptoGeneration;
    }
    this->CurrentMaxGen = v11;
    v108 = (Scaleform::GFx::AS3::GASRefCountBase *)(v11 + 1);
    Roots = this->Roots;
    while ( 1 )
    {
      do
      {
        this->Flags |= 1u;
        v13 = ampStats;
        v14 = 0;
        this->pLastPtr = &this->ListRoot;
        this->ListRoot.pPrev = &this->ListRoot;
        this->ListRoot.pNext = &this->ListRoot;
        this->ListRoot.RefCount |= 0x1000000u;
        next = 0;
        _amp_timer_Amp_Native_Function_Id_GcMarkInCycle.StartTicks = 0;
        _amp_timer_Amp_Native_Function_Id_GcMarkInCycle.Stats = ampStats;
        Instance = Scaleform::AmpServer::GetInstance();
        if ( Instance->IsProfiling(Instance)
          && (v16 = Scaleform::AmpServer::GetInstance(), v16->GetProfileLevel(v16) >= Amp_Profile_Level_Low) )
        {
          if ( ampStats )
          {
            _amp_timer_Amp_Native_Function_Id_GcMarkInCycle.StartTicks = Scaleform::Timer::GetProfileTicks();
            ((void (__thiscall *)(Scaleform::AmpStats *, const char *, int, _DWORD, _DWORD))ampStats->NativePushCallstack)(
              ampStats,
              "GC::MarkInCycle",
              6,
              _amp_timer_Amp_Native_Function_Id_GcMarkInCycle.StartTicks,
              HIDWORD(_amp_timer_Amp_Native_Function_Id_GcMarkInCycle.StartTicks));
          }
        }
        else
        {
          _amp_timer_Amp_Native_Function_Id_GcMarkInCycle.Stats = 0;
        }
        v17 = v108;
        this->Flags |= 8u;
        v101 = Roots;
        key = v17;
        do
        {
          for ( i = (Scaleform::GFx::AS3::RefCountCollector<328> *)v101->pRootHead;
                v101->pRootHead;
                next = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)next + 1) )
          {
            pRootHead = i->Roots[0].pRootHead;
            v101->pRootHead = pRootHead;
            if ( pRootHead )
              pRootHead->pPrev = 0;
            i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                     & ~0x80000000);
            --v101->nRoots;
            v20 = (int)i->Roots[1].pRootHead;
            if ( (v20 & 0x70000000) == 0x30000000 )
            {
              v21 = i->RefCount & 3;
              if ( v21 > this->CurrentMaxGen )
              {
                i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v20 & 0x8FFFFFFF);
                i->Roots[0].pRootHead = this->Roots[v21].pRootHead;
                i->Roots[0].nRoots = 0;
                v36 = this->Roots[v21].pRootHead;
                if ( v36 )
                  v36->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                ++this->Roots[v21].nRoots;
                this->Roots[v21].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                         & 0xFFFFFFF
                                                                                         | 0xB0000000);
              }
              else
              {
                if ( v20 < 0 && (v20 & 0x1000000) == 0 )
                {
                  nRoots = i->Roots[0].nRoots;
                  if ( nRoots )
                    *(_DWORD *)(nRoots + 8) = i->Roots[0].pRootHead;
                  else
                    this->Roots[v21].pRootHead = i->Roots[0].pRootHead;
                  v23 = i->Roots[0].pRootHead;
                  if ( v23 )
                    v23->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i->Roots[0].nRoots;
                  i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                           & ~0x80000000);
                  i->Roots[0].pRootHead = 0;
                  i->Roots[0].nRoots = 0;
                  --this->Roots[v21].nRoots;
                }
                if ( (HIBYTE(i->Roots[1].pRootHead) & 1) == 0 )
                {
                  i->Roots[0].nRoots = (unsigned int)this->pLastPtr->pNext->pPrev;
                  i->Roots[0].pRootHead = this->pLastPtr->pNext;
                  this->pLastPtr->pNext->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                  this->pLastPtr->pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                  this->pLastPtr = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                  i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                           | 0x1000000);
                }
                if ( i != (Scaleform::GFx::AS3::RefCountCollector<328> *)&this->ListRoot )
                {
                  do
                  {
                    if ( (i->RefCount & 3u) > this->CurrentMaxGen )
                    {
                      v25 = (Scaleform::GFx::AS3::RefCountCollector<328> *)i->Roots[0].pRootHead;
                      if ( (HIBYTE(i->Roots[1].pRootHead) & 1) != 0 )
                      {
                        if ( (Scaleform::GFx::AS3::RefCountCollector<328> *)this->pLastPtr == i )
                          this->pLastPtr = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i->Roots[0].nRoots;
                        *(_DWORD *)(i->Roots[0].nRoots + 8) = i->Roots[0].pRootHead;
                        i->Roots[0].pRootHead->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i->Roots[0].nRoots;
                        i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                                 & ~0x1000000u);
                      }
                      v26 = (int)i->Roots[1].pRootHead;
                      if ( v26 < 0 )
                      {
                        v30 = v26 & 0x8FFFFFFF | 0x30000000;
                      }
                      else
                      {
                        i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v26 & 0x8FFFFFFF);
                        v27 = i->RefCount & 3;
                        v28 = this->Roots[v27].pRootHead;
                        v29 = &this->Roots[v27];
                        i->Roots[0].pRootHead = v28;
                        i->Roots[0].nRoots = 0;
                        if ( v29->pRootHead )
                          v29->pRootHead->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                        ++v29->nRoots;
                        v29->pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)i;
                        v30 = (int)i->Roots[1].pRootHead & 0xFFFFFFF | 0xB0000000;
                      }
                      i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)v30;
                    }
                    else
                    {
                      if ( ((int)i->Roots[1].pRootHead & 0x70000000) != 0x10000000 )
                      {
                        v24 = i->__vftable;
                        i->Roots[1].pRootHead = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((int)i->Roots[1].pRootHead
                                                                                                 & 0x8FFFFFFF
                                                                                                 | 0x10000000);
                        ((void (__thiscall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountCollector<328> *, void (__cdecl *)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **)))v24->~Scaleform::GFx::AS3::RefCountCollector<328>)(
                          i,
                          this,
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::MarkInCycleCall);
                      }
                      v25 = (Scaleform::GFx::AS3::RefCountCollector<328> *)i->Roots[0].pRootHead;
                    }
                    i = v25;
                  }
                  while ( v25 != (Scaleform::GFx::AS3::RefCountCollector<328> *)&this->ListRoot );
                }
                v13 = ampStats;
              }
            }
            i = (Scaleform::GFx::AS3::RefCountCollector<328> *)v101->pRootHead;
          }
          ++v101;
          key = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)key - 1);
        }
        while ( key );
        this->Flags &= ~8u;
        if ( _amp_timer_Amp_Native_Function_Id_GcMarkInCycle.Stats )
        {
          p_NativePopCallstack = &_amp_timer_Amp_Native_Function_Id_GcMarkInCycle.Stats->NativePopCallstack;
          ProfileTicks = Scaleform::Timer::GetProfileTicks();
          ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
            _amp_timer_Amp_Native_Function_Id_GcMarkInCycle.Stats,
            ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_GcMarkInCycle.StartTicks),
            (ProfileTicks - _amp_timer_Amp_Native_Function_Id_GcMarkInCycle.StartTicks) >> 32);
        }
        if ( !next )
        {
LABEL_161:
          if ( pstat )
          {
            pstat->RootsNumber = initialNRoots;
            v90 = initialNRoots;
            if ( initialNRoots >= totalKillListSize )
              v90 = totalKillListSize;
            pstat->RootsFreedTotal = v90;
            v91 = totalObjsProcessed;
            pstat->ObjectsFreedTotal = totalKillListSize;
            v92 = (unsigned int)v108;
            pstat->ObjectsIteratedNumber = v91;
            pstat->GensNumber = v92;
            if ( v13 )
            {
              v13->AddGcRoots(v13, initialNRoots);
              v13->AddGcFreedRoots(v13, pstat->RootsFreedTotal);
            }
          }
          this->Flags &= 0xDBu;
          Scaleform::GFx::AS3::RefCountCollector<328>::CleanDelayedReleaseProxies(this, v13);
          Stats = _amp_timer_Amp_Native_Function_Id_GcCollect.Stats;
          if ( _amp_timer_Amp_Native_Function_Id_GcCollect.Stats )
          {
            v94 = &_amp_timer_Amp_Native_Function_Id_GcCollect.Stats->NativePopCallstack;
            v95 = Scaleform::Timer::GetProfileTicks();
            ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v94)(
              Stats,
              v95 - LODWORD(_amp_timer_Amp_Native_Function_Id_GcCollect.StartTicks),
              (v95 - _amp_timer_Amp_Native_Function_Id_GcCollect.StartTicks) >> 32);
          }
          return 1;
        }
        initialNRoots += (unsigned int)next;
        pNext = this->ListRoot.pNext;
        hasFinalize = 0;
        HIDWORD(_amp_timer_Amp_Native_Function_Id_GcScanInUse.StartTicks) = 0;
        _amp_timer_Amp_Native_Function_Id_GcScanInUse.Stats = v13;
        v34 = Scaleform::AmpServer::GetInstance();
        if ( v34->IsProfiling(v34)
          && (v35 = Scaleform::AmpServer::GetInstance(), v35->GetProfileLevel(v35) >= Amp_Profile_Level_Low) )
        {
          if ( v13 )
          {
            v37 = Scaleform::Timer::GetProfileTicks();
            v14 = v37;
            LODWORD(v37) = v13->__vftable;
            HIDWORD(_amp_timer_Amp_Native_Function_Id_GcScanInUse.StartTicks) = HIDWORD(v37);
            (*(void (__thiscall **)(Scaleform::AmpStats *, const char *, int, unsigned int, _DWORD))(v37 + 4))(
              v13,
              "GC::ScanInUse",
              7,
              v14,
              HIDWORD(v37));
          }
        }
        else
        {
          _amp_timer_Amp_Native_Function_Id_GcScanInUse.Stats = 0;
        }
        for ( j = &this->ListRoot; pNext != j; pNext = pNext->pNext )
        {
          RefCount = pNext->RefCount;
          ++totalObjsProcessed;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            pNext->RefCount = RefCount & 0x8FFFFFFF;
            this->pLastPtr = pNext;
            pNext->ForEachChild_GC(
              pNext,
              this,
              (void (__cdecl *)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanInUseCall);
          }
          else
          {
            if ( (RefCount & 0x2000000) != 0 )
              hasFinalize = 1;
            pNext->RefCount = RefCount & 0x8FFFFFFF | 0x20000000;
          }
        }
        if ( _amp_timer_Amp_Native_Function_Id_GcScanInUse.Stats )
        {
          v40 = &_amp_timer_Amp_Native_Function_Id_GcScanInUse.Stats->NativePopCallstack;
          v41 = Scaleform::Timer::GetProfileTicks();
          ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v40)(
            _amp_timer_Amp_Native_Function_Id_GcScanInUse.Stats,
            v41 - v14,
            (v41 - __PAIR64__(HIDWORD(_amp_timer_Amp_Native_Function_Id_GcScanInUse.StartTicks), v14)) >> 32);
        }
        _amp_timer_Amp_Native_Function_Id_GcFreeGarbage.StartTicks = 0;
        _amp_timer_Amp_Native_Function_Id_GcFreeGarbage.Stats = ampStats;
        v42 = Scaleform::AmpServer::GetInstance();
        if ( v42->IsProfiling(v42)
          && (v43 = Scaleform::AmpServer::GetInstance(), v43->GetProfileLevel(v43) >= Amp_Profile_Level_Low) )
        {
          if ( ampStats )
          {
            v44 = Scaleform::Timer::GetProfileTicks();
            v45 = ampStats->__vftable;
            v97 = v44;
            HIDWORD(_amp_timer_Amp_Native_Function_Id_GcFreeGarbage.StartTicks) = HIDWORD(v44);
            HIDWORD(v44) = v45->NativePushCallstack;
            LODWORD(_amp_timer_Amp_Native_Function_Id_GcFreeGarbage.StartTicks) = v44;
            ((void (__thiscall *)(Scaleform::AmpStats *, const char *, int, _DWORD, _DWORD))HIDWORD(v44))(
              ampStats,
              "GC::FreeGarbage",
              8,
              v97,
              HIDWORD(v97));
          }
        }
        else
        {
          _amp_timer_Amp_Native_Function_Id_GcFreeGarbage.Stats = 0;
        }
        if ( hasFinalize )
        {
          v46 = this->ListRoot.pNext;
          for ( this->pLastPtr = j; v46 != j; v46 = v46->pNext )
          {
            v47 = v46->RefCount;
            v48 = (v47 >> 28) & 7;
            if ( v48 == 2 )
            {
              if ( (v47 & 0x2000000) != 0 )
              {
                v46->RefCount = v47 & 0x8FFFFFFF;
                this->pLastPtr = v46;
                v46->ForEachChild_GC(
                  v46,
                  this,
                  (void (__cdecl *)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanTempInUseCall);
                v46->RefCount |= (unsigned int)&loc_400000;
              }
            }
            else if ( v48 == 5 )
            {
              v46->RefCount = v47 & 0x8FFFFFFF;
              this->pLastPtr = v46;
              v46->ForEachChild_GC(
                v46,
                this,
                (void (__cdecl *)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanTempInUseCall);
            }
          }
        }
        v49 = (Scaleform::GFx::AS3::GASRefCountBase *)this->ListRoot.pNext;
        this->pLastPtr = j;
        if ( v49 != (Scaleform::GFx::AS3::GASRefCountBase *)j )
        {
          do
          {
            v50 = (Scaleform::GFx::AS3::RefCountCollector<328> *)v49->pNext;
            if ( (v49->RefCount & 0x70000000) == 0x20000000 )
            {
              if ( (v49->RefCount & 0x8000000) == 0 )
              {
                v49->pPrev->pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)v50;
                v49->pNext->pPrev = v49->pPrev;
                v49->RefCount &= ~0x1000000u;
                if ( (v49->RefCount & 0x4000000) != 0 )
                {
                  v49->RefCount &= ~0x4000000u;
                  pTable = this->WProxyHash.mHash.pTable;
                  key = v49;
                  if ( pTable )
                  {
                    v52 = 5381;
                    v53 = 4;
                    do
                    {
                      v54 = *((unsigned __int8 *)&totalObjsProcessed + v53-- + 3);
                      v52 = v54 + 65599 * v52;
                    }
                    while ( v53 );
                    v55 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::findIndexCore<Scaleform::GFx::ResourceId>(
                            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&this->WProxyHash,
                            (const unsigned int *)&key,
                            v52 & pTable->SizeMask);
                    if ( v55 >= 0 )
                    {
                      v56 = &pTable[2 * v55 + 2];
                      if ( v56 )
                      {
                        SizeMask = (_DWORD *)v56->SizeMask;
                        if ( SizeMask )
                        {
                          v6 = (*SizeMask)-- == 1;
                          SizeMask[1] = 0;
                          if ( v6 )
                            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, SizeMask);
                          key = v49;
                          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::GASRefCountBase *>(
                            &this->WProxyHash.mHash,
                            &key);
                        }
                      }
                    }
                  }
                }
                v49->ForEachChild_GC(
                  v49,
                  this,
                  (void (__cdecl *)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))Scaleform::GFx::AS3::RefCountBaseGC<328>::DisableCall);
                ((void (__thiscall *)(Scaleform::GFx::AS3::GASRefCountBase *, int))v49->~Scaleform::GFx::AS3::GASRefCountBase)(
                  v49,
                  1);
                ++totalKillListSize;
              }
            }
            else
            {
              if ( upgradeGen )
              {
                v58 = v49->pRCCRaw & 3;
                if ( v58 < 2 )
                  v49->pRCCRaw ^= ((unsigned __int8)v49->_pRCC ^ (unsigned __int8)(v58 + 1)) & 3;
              }
              v49->pPrev->pNext = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)v50;
              v49->pNext->pPrev = v49->pPrev;
              v49->RefCount &= ~0x1000000u;
              v59 = v49->RefCount;
              if ( (v59 & 0x800000) != 0 )
              {
                v49->RefCount = v59 & 0xFF7FFFFF;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v49);
              }
              else if ( (v59 & 0x400000) != 0 )
              {
                v49->pNext = this->FinalizeRoots.pRootHead;
                v49->pPrev = 0;
                v60 = this->FinalizeRoots.pRootHead;
                if ( v60 )
                  v60->pPrev = v49;
                ++this->FinalizeRoots.nRoots;
                this->FinalizeRoots.pRootHead = v49;
                v49->RefCount |= 0x80000000;
              }
              else if ( (v59 & 0x70000000) == 0x30000000 && v59 >= 0 )
              {
                v49->RefCount = v59 & 0x8FFFFFFF;
                if ( (this->Flags & 8) == 0 )
                {
                  v61 = v49->pRCCRaw & 3;
                  v62 = this->Roots[v61].pRootHead;
                  v63 = &this->Roots[v61];
                  v49->pNext = v62;
                  v49->pPrev = 0;
                  if ( v63->pRootHead )
                    v63->pRootHead->pPrev = v49;
                  ++v63->nRoots;
                  v63->pRootHead = v49;
                  v49->RefCount = v49->RefCount & 0xFFFFFFF | 0xB0000000;
                }
              }
            }
            j = &this->ListRoot;
            v49 = (Scaleform::GFx::AS3::GASRefCountBase *)v50;
          }
          while ( v50 != (Scaleform::GFx::AS3::RefCountCollector<328> *)&this->ListRoot );
        }
        v64 = (Scaleform::GFx::AS3::GASRefCountBase *)this->ListRoot.pNext;
        if ( v64 != (Scaleform::GFx::AS3::GASRefCountBase *)j )
        {
          do
          {
            nexta = (Scaleform::GFx::AS3::RefCountCollector<328> *)v64->pNext;
            if ( (v64->RefCount & 0x4000000) != 0 )
            {
              v64->RefCount &= ~0x4000000u;
              v65 = this->WProxyHash.mHash.pTable;
              key = v64;
              if ( v65 )
              {
                v66 = 5381;
                v67 = 4;
                do
                {
                  v68 = *((unsigned __int8 *)&totalObjsProcessed + v67-- + 3);
                  v66 = v68 + 65599 * v66;
                }
                while ( v67 );
                v69 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::StringLH,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::findIndexCore<Scaleform::GFx::ResourceId>(
                        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *)&this->WProxyHash,
                        (const unsigned int *)&key,
                        v66 & v65->SizeMask);
                if ( v69 >= 0 )
                {
                  v70 = &v65[2 * v69 + 2];
                  if ( v70 )
                  {
                    v71 = (_DWORD *)v70->SizeMask;
                    if ( v71 )
                    {
                      v6 = (*v71)-- == 1;
                      v71[1] = 0;
                      if ( v6 )
                        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v71);
                      key = v64;
                      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::GASRefCountBase *>(
                        &this->WProxyHash.mHash,
                        &key);
                    }
                  }
                }
              }
            }
            v64->ForEachChild_GC(
              v64,
              this,
              (void (__cdecl *)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))Scaleform::GFx::AS3::RefCountBaseGC<328>::DisableCall);
            ((void (__thiscall *)(Scaleform::GFx::AS3::GASRefCountBase *, int))v64->~Scaleform::GFx::AS3::GASRefCountBase)(
              v64,
              1);
            v64 = (Scaleform::GFx::AS3::GASRefCountBase *)nexta;
            ++totalKillListSize;
            j = &this->ListRoot;
          }
          while ( nexta != (Scaleform::GFx::AS3::RefCountCollector<328> *)&this->ListRoot );
        }
        if ( _amp_timer_Amp_Native_Function_Id_GcFreeGarbage.Stats )
        {
          v72 = &_amp_timer_Amp_Native_Function_Id_GcFreeGarbage.Stats->NativePopCallstack;
          v73 = Scaleform::Timer::GetProfileTicks();
          ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v72)(
            _amp_timer_Amp_Native_Function_Id_GcFreeGarbage.Stats,
            v73 - LODWORD(_amp_timer_Amp_Native_Function_Id_GcFreeGarbage.StartTicks),
            (v73 - _amp_timer_Amp_Native_Function_Id_GcFreeGarbage.StartTicks) >> 32);
        }
        this->pLastPtr = j;
        j->RefCount &= ~0x1000000u;
        this->Flags &= ~1u;
        _amp_timer_Amp_Native_Function_Id_GcFinalize.StartTicks = 0;
        _amp_timer_Amp_Native_Function_Id_GcFinalize.Stats = ampStats;
        v74 = Scaleform::AmpServer::GetInstance();
        if ( v74->IsProfiling(v74)
          && (v75 = Scaleform::AmpServer::GetInstance(), v75->GetProfileLevel(v75) >= Amp_Profile_Level_Low) )
        {
          if ( ampStats )
          {
            v76 = Scaleform::Timer::GetProfileTicks();
            v77 = ampStats->__vftable;
            v98 = v76;
            HIDWORD(_amp_timer_Amp_Native_Function_Id_GcFinalize.StartTicks) = HIDWORD(v76);
            HIDWORD(v76) = v77->NativePushCallstack;
            LODWORD(_amp_timer_Amp_Native_Function_Id_GcFinalize.StartTicks) = v76;
            ((void (__thiscall *)(Scaleform::AmpStats *, const char *, int, _DWORD, _DWORD))HIDWORD(v76))(
              ampStats,
              "GC::Finalize",
              9,
              v98,
              HIDWORD(v98));
          }
        }
        else
        {
          _amp_timer_Amp_Native_Function_Id_GcFinalize.Stats = 0;
        }
        if ( hasFinalize )
        {
          for ( k = this->FinalizeRoots.pRootHead; k; k = this->FinalizeRoots.pRootHead )
          {
            v79 = k->pNext;
            this->FinalizeRoots.pRootHead = v79;
            if ( v79 )
              v79->pPrev = 0;
            k->RefCount &= ~0x80000000;
            if ( (k->RefCount & 0x400000) != 0 )
            {
              v80 = k->__vftable;
              k->RefCount = (k->RefCount & 0xFDBFFFFF) + 1;
              v80->Finalize_GC(k);
              if ( (--k->RefCount & 0x80000000) != 0 && (k->RefCount & 0x1000000) == 0 )
              {
                pPrev = k->pPrev;
                v82 = &this->Roots[k->pRCCRaw & 3];
                if ( pPrev )
                  pPrev->pNext = k->pNext;
                else
                  v82->pRootHead = k->pNext;
                v83 = k->pNext;
                if ( v83 )
                  v83->pPrev = k->pPrev;
                k->RefCount &= ~0x80000000;
                k->pNext = 0;
                k->pPrev = 0;
                --v82->nRoots;
              }
              k->pRCCRaw &= 0xFFFFFFFC;
              k->RefCount &= 0x8FFFFFFF;
              if ( (this->Flags & 8) == 0 )
              {
                v84 = k->pRCCRaw & 3;
                v85 = this->Roots[v84].pRootHead;
                v86 = &this->Roots[v84];
                k->pNext = v85;
                k->pPrev = 0;
                if ( v86->pRootHead )
                  v86->pRootHead->pPrev = k;
                ++v86->nRoots;
                v86->pRootHead = k;
                k->RefCount = k->RefCount & 0xFFFFFFF | 0xB0000000;
              }
            }
          }
        }
        if ( _amp_timer_Amp_Native_Function_Id_GcFinalize.Stats )
        {
          v87 = _amp_timer_Amp_Native_Function_Id_GcFinalize.Stats;
          v88 = &_amp_timer_Amp_Native_Function_Id_GcFinalize.Stats->NativePopCallstack;
          v89 = Scaleform::Timer::GetProfileTicks();
          ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v88)(
            v87,
            v89 - LODWORD(_amp_timer_Amp_Native_Function_Id_GcFinalize.StartTicks),
            (v89 - _amp_timer_Amp_Native_Function_Id_GcFinalize.StartTicks) >> 32);
        }
        Roots = this->Roots;
        upgradeGen = 0;
      }
      while ( this->Roots[0].pRootHead );
      if ( uptoGeneration != 2 )
        break;
      if ( !this->Roots[2].pRootHead )
      {
LABEL_159:
        if ( !this->Roots[1].pRootHead )
        {
LABEL_160:
          v13 = ampStats;
          goto LABEL_161;
        }
      }
    }
    if ( !uptoGeneration )
      goto LABEL_160;
    goto LABEL_159;
  }
  if ( pstat )
  {
    pstat->GensNumber = 0;
    pstat->ObjectsFreedTotal = 0;
    pstat->ObjectsIteratedNumber = 0;
    pstat->RootsFreedTotal = 0;
    pstat->RootsNumber = 0;
  }
  return 0;
}
