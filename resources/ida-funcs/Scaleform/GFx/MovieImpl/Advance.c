double __userpurge Scaleform::GFx::MovieImpl::Advance@<st0>(
        Scaleform::GFx::MovieImpl *this@<ecx>,
        int a2@<ebp>,
        int a3@<ebx>,
        float deltaT,
        unsigned int frameCatchUpCount,
        int capture)
{
  Scaleform::AmpStats *Stats; // ebx
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::MovieDefImpl *v11; // esi
  double v12; // st7
  Scaleform::AmpStats *v13; // ebx
  void (__thiscall **v14)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v15; // rax
  Scaleform::GFx::StateBag *v16; // ecx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::UserEventHandler *v18; // ebx
  Scaleform::RefCountVImpl *v19; // ecx
  Scaleform::GFx::FSCommandHandler *v20; // ebx
  Scaleform::RefCountVImpl *v21; // ecx
  Scaleform::GFx::ExternalInterface *v22; // ebx
  Scaleform::RefCountVImpl *v23; // eax
  Scaleform::RefCountVImpl *v24; // ecx
  Scaleform::Log *GlobalLog; // eax
  Scaleform::GFx::Resource *v26; // ebx
  Scaleform::RefCountVImpl *v27; // ecx
  Scaleform::GFx::Resource *v28; // edi
  Scaleform::RefCountVImpl *v29; // edx
  Scaleform::RefCountVImpl *v30; // eax
  Scaleform::RefCountVImpl *v31; // ebx
  Scaleform::GFx::FontManagerStates *v32; // ecx
  Scaleform::RefCountVImpl *v33; // ebp
  Scaleform::GFx::AudioBase *v34; // ecx
  Scaleform::Sound::SoundRenderer *v35; // eax
  Scaleform::GFx::MovieDefRootNode *i; // edi
  Scaleform::ArrayDefaultPolicy *v37; // eax
  unsigned int j; // edi
  Scaleform::GFx::InteractiveObject *v39; // ecx
  Scaleform::RefCountVImpl *v40; // ecx
  Scaleform::RefCountVImpl *v41; // ecx
  Scaleform::AmpStats *v42; // edi
  void (__thiscall **v43)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v44; // rax
  unsigned int k; // edi
  Scaleform::GFx::InteractiveObject *v46; // ecx
  unsigned __int64 v47; // rax
  double v48; // st7
  bool v49; // cf
  unsigned __int64 v50; // rax
  unsigned int Size; // ebx
  int v52; // ebp
  unsigned int m; // edi
  Scaleform::GFx::ASIntervalTimerIntf *v54; // ecx
  Scaleform::GFx::ASIntervalTimerIntf *v55; // ecx
  unsigned __int64 v56; // rax
  unsigned int v57; // eax
  Scaleform::RefCountVImpl *v58; // ebx
  Scaleform::RefCountVImpl *v59; // edi
  Scaleform::GFx::ASIntervalTimerIntf *v60; // ecx
  Scaleform::RefCountVImpl **Data; // edi
  int v62; // ebx
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *pTable; // eax
  unsigned int v64; // ebx
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *v65; // ecx
  unsigned int v66; // edi
  Scaleform::GFx::AMP::ViewStats *v67; // edi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v69; // eax
  Scaleform::RefCountNTSImpl **v70; // ecx
  Scaleform::RefCountNTSImpl *v71; // ebp
  char v72; // al
  Scaleform::RefCountNTSImpl_vtbl *v73; // edx
  unsigned int v74; // edi
  Scaleform::RefCountNTSImpl **v75; // edi
  _DWORD *v76; // ebp
  void (__thiscall **v77)(_DWORD *, _DWORD, _DWORD); // edi
  unsigned __int64 v78; // rax
  unsigned int v79; // eax
  _DWORD *v80; // ecx
  unsigned int v81; // ebp
  Scaleform::RefCountVImpl **Capacity; // ebx
  Scaleform::Sound::SoundRenderer *pSoundRenderer; // ecx
  bool v84; // zf
  long double TimeRemainder; // st7
  long double v86; // st7
  double v87; // st7
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *v88; // eax
  unsigned int v89; // edi
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *v90; // ecx
  Scaleform::HashSet<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *p_VideoProviders; // edx
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *v92; // eax
  Scaleform::RefCountNTSImpl **v93; // ecx
  Scaleform::RefCountNTSImpl *v94; // ebx
  char v95; // al
  Scaleform::RefCountNTSImpl_vtbl *v96; // edx
  double v97; // st7
  unsigned int v98; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object **v99; // ebp
  unsigned int v100; // eax
  _DWORD *v101; // ecx
  unsigned int v102; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object **v103; // ebx
  unsigned int n; // edi
  unsigned int ForceFrameCatchUp; // eax
  int v106; // ecx
  Scaleform::GFx::ASMovieRootBase *v107; // ecx
  Scaleform::GFx::DrawingContext *pNext; // edi
  Scaleform::List<Scaleform::GFx::DrawingContext,Scaleform::GFx::DrawingContext> *p_DrawingContextList; // ebx
  unsigned int *v110; // eax
  Scaleform::AmpServer *v111; // eax
  unsigned __int64 v112; // rax
  double v113; // st7
  Scaleform::RefCountVImpl *v114; // ecx
  Scaleform::RefCountVImpl *pAudio; // ecx
  Scaleform::AmpStats *v116; // edi
  void (__thiscall **v117)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v118; // rax
  Scaleform::RefCountVImpl *v120[2]; // [esp+30h] [ebp-90h] BYREF
  float v121; // [esp+38h] [ebp-88h]
  double v122; // [esp+3Ch] [ebp-84h] BYREF
  Scaleform::RefCountVImpl *v123; // [esp+44h] [ebp-7Ch] BYREF
  unsigned __int64 v124; // [esp+48h] [ebp-78h] BYREF
  _DWORD *v125; // [esp+50h] [ebp-70h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+5Ch] [ebp-64h] BYREF
  unsigned int v127; // [esp+68h] [ebp-58h]
  unsigned int v128; // [esp+6Ch] [ebp-54h]
  unsigned __int64 v129; // [esp+70h] [ebp-50h]
  Scaleform::RefCountVImpl *v130; // [esp+78h] [ebp-48h]
  Scaleform::AmpFunctionTimer v131; // [esp+7Ch] [ebp-44h] BYREF
  Scaleform::RefCountVImpl *v132; // [esp+8Ch] [ebp-34h]
  unsigned int _CurrentState; // [esp+90h] [ebp-30h] BYREF
  Scaleform::GFx::UserEventHandler *v134; // [esp+94h] [ebp-2Ch] BYREF
  Scaleform::GFx::FSCommandHandler *v135; // [esp+98h] [ebp-28h]
  Scaleform::GFx::ExternalInterface *v136; // [esp+9Ch] [ebp-24h]
  Scaleform::RefCountVImpl *v137; // [esp+A0h] [ebp-20h]
  Scaleform::RefCountVImpl *v138; // [esp+A4h] [ebp-1Ch]
  Scaleform::GFx::FontLib *pfontLib; // [esp+A8h] [ebp-18h]
  Scaleform::GFx::FontMap *pfontMap; // [esp+ACh] [ebp-14h]
  Scaleform::GFx::FontProvider *pfontProvider; // [esp+B0h] [ebp-10h]
  Scaleform::GFx::Translator *ptranslator; // [esp+B4h] [ebp-Ch]
  Scaleform::GFx::AudioBase *v143; // [esp+B8h] [ebp-8h]
  unsigned int v144; // [esp+BCh] [ebp-4h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v131,
    this->AdvanceStats.pObject,
    "MovieImpl::Advance",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_Advance);
  if ( (this->Flags & 0x100000) != 0 )
  {
    if ( (_BYTE)capture )
      Scaleform::GFx::MovieImpl::Capture(this, 1);
    Stats = v131.Stats;
    if ( v131.Stats )
    {
      p_NativePopCallstack = &v131.Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v131.StartTicks),
        (ProfileTicks - v131.StartTicks) >> 32);
    }
    return 0.050000001;
  }
  else if ( this->pMainMovie )
  {
    Scaleform::GFx::MovieImpl::ProcessMovieDefToKillList(this);
    _controlfp_s(a3, &_CurrentState, 0, 0);
    _controlfp_s(a3, (unsigned int *)&v123, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
    if ( deltaT < 0.0 )
      deltaT = 0.0;
    this->Flags |= 0x200u;
    v16 = &this->pStateBag.pObject->Scaleform::GFx::StateBag;
    v134 = 0;
    v135 = 0;
    v136 = 0;
    v137 = 0;
    v138 = 0;
    pfontLib = 0;
    pfontMap = 0;
    pfontProvider = 0;
    ptranslator = 0;
    v143 = 0;
    v16->GetStatesAddRef(v16, &v134, stateQuery, 10u);
    pObject = (Scaleform::RefCountVImpl *)this->pUserEventHandler.pObject;
    v18 = v134;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pUserEventHandler.pObject = v18;
    v19 = (Scaleform::RefCountVImpl *)this->pFSCommandHandler.pObject;
    v20 = v135;
    if ( v19 )
      Scaleform::RefCountImpl::Release(v19);
    this->pFSCommandHandler.pObject = v20;
    v21 = (Scaleform::RefCountVImpl *)this->pExtIntfHandler.pObject;
    v22 = v136;
    if ( v21 )
      Scaleform::RefCountImpl::Release(v21);
    v23 = v138;
    v24 = v137;
    this->pExtIntfHandler.pObject = v22;
    v130 = v24;
    v132 = v23;
    if ( v23 )
    {
      GlobalLog = (Scaleform::Log *)v23[2].__vftable;
      if ( !GlobalLog )
        GlobalLog = Scaleform::Log::GetGlobalLog();
      v26 = (Scaleform::GFx::Resource *)GlobalLog;
    }
    else
    {
      v26 = 0;
    }
    if ( v26 )
      Scaleform::RefCountImpl::AddRef(v26);
    v27 = (Scaleform::RefCountVImpl *)this->pCachedLog.pObject;
    if ( v27 )
      Scaleform::RefCountImpl::Release(v27);
    v28 = (Scaleform::GFx::Resource *)ptranslator;
    v29 = (Scaleform::RefCountVImpl *)pfontMap;
    v30 = (Scaleform::RefCountVImpl *)pfontLib;
    this->pCachedLog.pObject = (Scaleform::Log *)v26;
    v31 = (Scaleform::RefCountVImpl *)pfontProvider;
    v32 = this->pFontManagerStates.pObject;
    v120[0] = v30;
    v123 = v29;
    LOBYTE(v120[1]) = Scaleform::GFx::FontManagerStates::CheckStateChange(
                        v32,
                        (Scaleform::GFx::Resource *)v30,
                        (Scaleform::GFx::Resource *)v29,
                        (Scaleform::GFx::Resource *)pfontProvider,
                        v28);
    if ( v28 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v28);
    if ( v31 )
      Scaleform::RefCountImpl::Release(v31);
    if ( v123 )
      Scaleform::RefCountImpl::Release(v123);
    if ( v120[0] )
      Scaleform::RefCountImpl::Release(v120[0]);
    this->Flags |= 2u;
    v33 = v130;
    if ( *(float *)&v130 == 0.0 )
    {
      this->Flags &= 0xFFFFFF83;
    }
    else
    {
      if ( (v130[1].RefCount & 1) != 0 )
        this->Flags |= 4u;
      else
        this->Flags &= ~4u;
      if ( (v33[1].RefCount & 2) != 0 )
        this->Flags |= 0x40u;
      else
        this->Flags &= ~0x40u;
      if ( (v33[1].RefCount & 4) != 0 )
        this->Flags |= 8u;
      else
        this->Flags &= ~8u;
      if ( (v33[1].RefCount & 0x10) != 0 )
        this->Flags |= 0x20u;
      else
        this->Flags &= ~0x20u;
      if ( (v33[1].RefCount & 8) != 0 )
        this->Flags |= 0x10u;
      else
        this->Flags &= ~0x10u;
    }
    v34 = v143;
    this->pAudio = v143;
    if ( v34 )
    {
      v35 = v34->GetRenderer(v34);
      this->pSoundRenderer = v35;
      if ( v35 )
        Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v35);
    }
    for ( i = this->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
    {
      v37 = this == (Scaleform::GFx::MovieImpl *)-56 ? 0 : &this->MovieLevels.Data.Policy;
      if ( i == (Scaleform::GFx::MovieDefRootNode *)v37 )
        break;
      if ( !i->ImportFlag )
      {
        i->BytesLoaded = i->pDefImpl->pBindData.pObject->BytesLoaded;
        i->LoadingFrame = i->pDefImpl->GetLoadingFrame(i->pDefImpl);
      }
      if ( LOBYTE(v120[1]) )
        i->pFontManager.pObject->CleanCache(i->pFontManager.pObject);
    }
    if ( LOBYTE(v120[1]) || (this->Flags2 & 2) != 0 )
    {
      for ( j = 0; j < this->MovieLevels.Data.Size; ++j )
      {
        v39 = this->MovieLevels.Data.Data[j].pSprite.pObject;
        v39->SetStateChangeFlags(v39, (unsigned __int8)v120[1]);
      }
    }
    if ( this->pMainMovie->GetLoadingFrame(this->pMainMovie) )
    {
      if ( (this->Flags & 0x100) != 0 && this->pMainMovie->GetLoadingFrame(this->pMainMovie) )
      {
        this->Flags &= ~0x100u;
        for ( k = this->MovieLevels.Data.Size; k; --k )
        {
          v46 = this->MovieLevels.Data.Data[k - 1].pSprite.pObject;
          v46->ExecuteFrame0Events(v46);
        }
        this->pASMovieRoot.pObject->DoActions(this->pASMovieRoot.pObject);
        Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
        Scaleform::GFx::MovieImpl::ProcessLoadQueue(this);
      }
      v47 = (unsigned __int64)(1000000.0 * deltaT);
      v48 = deltaT + this->TimeRemainder;
      v49 = __CFADD__((_DWORD)v47, this->TimeElapsed);
      LODWORD(this->TimeElapsed) += v47;
      this->TimeRemainder = v48;
      HIDWORD(this->TimeElapsed) += HIDWORD(v47) + v49;
      v50 = Scaleform::Timer::GetProfileTicks();
      Size = this->IntervalTimers.Data.Size;
      v120[1] = (Scaleform::RefCountVImpl *)LODWORD(this->FrameTime);
      v129 = v50;
      if ( Size )
      {
        v52 = 0;
        for ( m = 0; m < Size; ++m )
        {
          v54 = this->IntervalTimers.Data.Data[m].pObject;
          if ( v54 && v54->IsActive(v54) )
          {
            ((void (__stdcall *)(_DWORD, _DWORD))this->IntervalTimers.Data.Data[m].pObject->Invoke)(
              this,
              this->FrameTime);
            v55 = this->IntervalTimers.Data.Data[m].pObject;
            v56 = v55->GetNextInvokeTime(v55);
            v49 = (unsigned int)v56 < LODWORD(this->TimeElapsed);
            LODWORD(v56) = v56 - LODWORD(this->TimeElapsed);
            LODWORD(v124) = 0;
            HIDWORD(v56) -= v49 + HIDWORD(this->TimeElapsed);
            *(_QWORD *)&v122 = v56 & 0x7FFFFFFFFFFFFFFFLL;
            HIDWORD(v124) = HIDWORD(v56) & 0x80000000;
            *(float *)v120 = (double)v56 / 1000000.0;
            if ( *(float *)&v120[1] > (double)*(float *)v120 )
              v120[1] = v120[0];
          }
          else
          {
            ++v52;
          }
        }
        if ( v52 )
        {
          v57 = this->IntervalTimers.Data.Size;
          v58 = 0;
          v123 = 0;
          if ( v57 )
          {
            LODWORD(v124) = v57;
            while ( 1 )
            {
              v59 = (Scaleform::RefCountVImpl *)(4 * (_DWORD)v58);
              v60 = this->IntervalTimers.Data.Data[(_DWORD)v58].pObject;
              if ( v60 && v60->IsActive(v60) )
              {
                v123 = (Scaleform::RefCountVImpl *)((char *)&v58->__vftable + 1);
              }
              else
              {
                (*(void (__thiscall **)(_DWORD))(**(_DWORD **)((char *)&v59->__vftable
                                                             + (unsigned int)this->IntervalTimers.Data.Data)
                                               + 16))(*(Scaleform::RefCountVImpl_vtbl **)((char *)&v59->__vftable
                                                                                        + (unsigned int)this->IntervalTimers.Data.Data));
                if ( this->IntervalTimers.Data.Size == 1 )
                {
                  Data = (Scaleform::RefCountVImpl **)this->IntervalTimers.Data.Data;
                  v62 = 1;
                  do
                  {
                    if ( *Data )
                      Scaleform::RefCountImpl::Release(*Data);
                    --Data;
                    --v62;
                  }
                  while ( v62 );
                  if ( (this->IntervalTimers.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
                  {
                    if ( this->IntervalTimers.Data.Data )
                    {
                      Scaleform::Memory::pGlobalHeap->Free(
                        Scaleform::Memory::pGlobalHeap,
                        this->IntervalTimers.Data.Data);
                      this->IntervalTimers.Data.Data = 0;
                    }
                    this->IntervalTimers.Data.Policy.Capacity = 0;
                  }
                  this->IntervalTimers.Data.Size = 0;
                }
                else
                {
                  if ( *(Scaleform::RefCountVImpl_vtbl **)((char *)&v59->__vftable
                                                         + (unsigned int)this->IntervalTimers.Data.Data) )
                    Scaleform::RefCountImpl::Release(*(Scaleform::RefCountVImpl **)((char *)&v59->__vftable
                                                                                  + (unsigned int)this->IntervalTimers.Data.Data));
                  memmove(
                    (int)this->IntervalTimers.Data.Data + (unsigned int)v59,
                    (const __m128i *)((char *)&this->IntervalTimers.Data.Data[1] + (unsigned int)v59),
                    4 * (this->IntervalTimers.Data.Size - (_DWORD)v58) - 4);
                  --this->IntervalTimers.Data.Size;
                }
              }
              LODWORD(v124) = v124 - 1;
              if ( !(_DWORD)v124 )
                break;
              v58 = v123;
            }
          }
        }
      }
      pTable = this->VideoProviders.pTable;
      v64 = 0;
      if ( pTable && pTable->EntryCount )
      {
        pheapAddr.Policy.Capacity = 0;
        v127 = 0;
        v128 = 0;
        v65 = pTable + 1;
        do
        {
          if ( v65->EntryCount != -2 )
            break;
          ++v64;
          v65 = (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *)((char *)v65 + 12);
        }
        while ( v64 <= pTable->SizeMask );
        LODWORD(v122) = &this->VideoProviders;
        while ( 1 )
        {
          v66 = 0;
          if ( !LODWORD(v122)
            || !*(_DWORD *)LODWORD(v122)
            || (signed int)v64 > *(_DWORD *)(*(_DWORD *)LODWORD(v122) + 4) )
          {
            break;
          }
          v124 = 0;
          v67 = this->AdvanceStats.pObject;
          v125 = &v67->__vftable;
          Instance = Scaleform::AmpServer::GetInstance();
          if ( Instance->IsProfiling(Instance)
            && (v69 = Scaleform::AmpServer::GetInstance(), v69->GetProfileLevel(v69) >= Amp_Profile_Level_Medium) )
          {
            if ( v67 )
            {
              v124 = Scaleform::Timer::GetProfileTicks();
              ((void (__thiscall *)(Scaleform::GFx::AMP::ViewStats *, const char *, int, _DWORD, _DWORD))v67->NativePushCallstack)(
                v67,
                "VideoProviderNetStream::Advance",
                -1,
                v124,
                HIDWORD(v124));
            }
          }
          else
          {
            v125 = 0;
          }
          v70 = (Scaleform::RefCountNTSImpl **)(*(_DWORD *)LODWORD(v122) + 12 * v64 + 16);
          if ( *v70 )
            ++(*v70)->RefCount;
          v71 = *v70;
          (*v70)->__vftable[2].~Scaleform::RefCountNTSImpl(*v70);
          v72 = ((int (__thiscall *)(Scaleform::RefCountNTSImpl *))v71->__vftable[5].~Scaleform::RefCountNTSImpl)(v71);
          v73 = v71->__vftable;
          if ( v72 )
          {
            if ( *(float *)&v120[1] > ((double (__thiscall *)(Scaleform::RefCountNTSImpl *))v73[6].~Scaleform::RefCountNTSImpl)(v71) )
              *(float *)&v120[1] = ((double (__thiscall *)(Scaleform::RefCountNTSImpl *))v71->__vftable[6].~Scaleform::RefCountNTSImpl)(v71);
          }
          else
          {
            v73[4].~Scaleform::RefCountNTSImpl(v71);
            v74 = v127 + 1;
            if ( v127 + 1 >= v127 )
            {
              if ( v74 >= v128 )
                Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Policy,
                  &pheapAddr.Policy,
                  v74 + (v74 >> 2));
            }
            else if ( v74 < v128 >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Policy,
                &pheapAddr.Policy,
                v127 + 1);
            }
            v127 = v74;
            v75 = (Scaleform::RefCountNTSImpl **)(pheapAddr.Policy.Capacity + 4 * v74 - 4);
            if ( v75 )
              *v75 = v71;
          }
          Scaleform::RefCountNTSImpl::Release(v71);
          if ( v125 )
          {
            v76 = v125;
            v77 = (void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*v125 + 8);
            v78 = Scaleform::Timer::GetProfileTicks();
            (*v77)(v76, v78 - v124, (v78 - v124) >> 32);
          }
          v79 = *(_DWORD *)(*(_DWORD *)LODWORD(v122) + 4);
          if ( (int)v64 <= (int)v79 && ++v64 <= v79 )
          {
            v80 = (_DWORD *)(*(_DWORD *)LODWORD(v122) + 12 * v64 + 8);
            do
            {
              if ( *v80 != -2 )
                break;
              ++v64;
              v80 += 3;
            }
            while ( v64 <= v79 );
          }
        }
        v81 = v127;
        Capacity = (Scaleform::RefCountVImpl **)pheapAddr.Policy.Capacity;
        if ( v127 )
        {
          do
          {
            v120[0] = Capacity[v66];
            Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>>>::RemoveAlt<Scaleform::GFx::Video::VideoProvider *>(
              &this->VideoProviders,
              (Scaleform::RefCountNTSImpl **)v120);
            ++v66;
          }
          while ( v66 < v81 );
        }
        if ( Capacity )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Capacity);
      }
      pSoundRenderer = this->pSoundRenderer;
      if ( pSoundRenderer )
      {
        *(float *)v120 = pSoundRenderer->Update(pSoundRenderer);
        if ( *(float *)&v120[1] > (double)*(float *)v120 )
          v120[1] = v120[0];
      }
      Scaleform::GFx::MovieImpl::ProcessInput(this);
      if ( this->FrameTime > (double)this->TimeRemainder )
      {
        *(float *)v120 = this->TimeRemainder / this->FrameTime;
        Scaleform::GFx::MovieImpl::AdvanceFrame(this, 0, *(float *)v120);
        *(float *)&v120[1] = fmod(this->TimeRemainder, this->FrameTime);
        v107 = this->pASMovieRoot.pObject;
        this->TimeRemainder = *(float *)&v120[1];
        v107->DoActions(v107);
        Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
        Scaleform::GFx::MovieImpl::ProcessLoadQueue(this);
        this->pASMovieRoot.pObject->AdvanceFrame(this->pASMovieRoot.pObject, 0);
      }
      else
      {
        ((void (__thiscall *)(Scaleform::GFx::ASMovieRootBase *, int))this->pASMovieRoot.pObject->DoActions)(
          this->pASMovieRoot.pObject,
          a2);
        if ( capture || (v84 = this->ForceFrameCatchUp == 0, BYTE3(v122) = 0, !v84) )
          BYTE3(v122) = 1;
        do
        {
          TimeRemainder = this->TimeRemainder;
          if ( BYTE3(v122) )
          {
            v86 = TimeRemainder - this->FrameTime;
          }
          else
          {
            *(float *)&v120[1] = fmod(TimeRemainder, this->FrameTime);
            v86 = *(float *)&v120[1];
          }
          this->TimeRemainder = v86;
          if ( this->FrameTime > (double)this->TimeRemainder )
            v87 = this->TimeRemainder / this->FrameTime;
          else
            v87 = 0.0;
          *(float *)&v120[1] = v87;
          Scaleform::GFx::MovieImpl::AdvanceFrame(this, 1, *(float *)&v120[1]);
          v88 = this->VideoProviders.pTable;
          if ( v88 && v88->EntryCount )
          {
            v89 = 0;
            memset(&pheapAddr, 0, sizeof(pheapAddr));
            v90 = v88 + 1;
            do
            {
              if ( v90->EntryCount != -2 )
                break;
              ++v89;
              v90 = (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *)((char *)v90 + 12);
            }
            while ( v89 <= v88->SizeMask );
            p_VideoProviders = &this->VideoProviders;
            HIDWORD(v122) = &this->VideoProviders;
            while ( p_VideoProviders )
            {
              v92 = p_VideoProviders->pTable;
              if ( !p_VideoProviders->pTable || (signed int)v89 > (signed int)v92->SizeMask )
                break;
              v93 = (Scaleform::RefCountNTSImpl **)&v92[2] + 3 * v89;
              if ( *v93 )
                ++(*v93)->RefCount;
              v94 = *v93;
              (*v93)->__vftable[2].~Scaleform::RefCountNTSImpl(*v93);
              v95 = ((int (__thiscall *)(Scaleform::RefCountNTSImpl *))v94->__vftable[5].~Scaleform::RefCountNTSImpl)(v94);
              v96 = v94->__vftable;
              if ( v95 )
              {
                v97 = ((double (__thiscall *)(Scaleform::RefCountNTSImpl *))v96[6].~Scaleform::RefCountNTSImpl)(v94);
                if ( v121 > v97 )
                  v121 = ((double (__thiscall *)(Scaleform::RefCountNTSImpl *))v94->__vftable[6].~Scaleform::RefCountNTSImpl)(v94);
              }
              else
              {
                v96[4].~Scaleform::RefCountNTSImpl(v94);
                v98 = pheapAddr.Size + 1;
                if ( pheapAddr.Size + 1 >= pheapAddr.Size )
                {
                  if ( v98 >= pheapAddr.Policy.Capacity )
                    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                      &pheapAddr,
                      &pheapAddr,
                      v98 + (v98 >> 2));
                }
                else if ( v98 < pheapAddr.Policy.Capacity >> 1 )
                {
                  Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                    &pheapAddr,
                    &pheapAddr,
                    pheapAddr.Size + 1);
                }
                pheapAddr.Size = v98;
                v99 = &pheapAddr.Data[v98 - 1];
                if ( v99 )
                  *v99 = (Scaleform::GFx::AS3::Instances::fl::Object *)v94;
              }
              Scaleform::RefCountNTSImpl::Release(v94);
              p_VideoProviders = (Scaleform::HashSet<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *)HIDWORD(v122);
              v100 = *(_DWORD *)(*(_DWORD *)HIDWORD(v122) + 4);
              if ( (int)v89 <= (int)v100 && ++v89 <= v100 )
              {
                v101 = (_DWORD *)(*(_DWORD *)HIDWORD(v122) + 12 * v89 + 8);
                do
                {
                  if ( *v101 != -2 )
                    break;
                  ++v89;
                  v101 += 3;
                }
                while ( v89 <= v100 );
              }
            }
            v102 = pheapAddr.Size;
            v103 = pheapAddr.Data;
            for ( n = 0; n < v102; ++n )
            {
              HIDWORD(v124) = v103[n];
              Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>>>::RemoveAlt<Scaleform::GFx::Video::VideoProvider *>(
                &this->VideoProviders,
                (Scaleform::RefCountNTSImpl **)&v124 + 1);
            }
            if ( v103 )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v103);
          }
          this->pASMovieRoot.pObject->DoActions(this->pASMovieRoot.pObject);
          Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
          Scaleform::GFx::MovieImpl::ProcessLoadQueue(this);
          ForceFrameCatchUp = this->ForceFrameCatchUp;
          if ( ForceFrameCatchUp )
            this->ForceFrameCatchUp = ForceFrameCatchUp - 1;
          v106 = capture--;
        }
        while ( v106 && this->FrameTime <= (double)this->TimeRemainder || this->ForceFrameCatchUp );
        this->Flags |= 0x80u;
        this->pASMovieRoot.pObject->AdvanceFrame(this->pASMovieRoot.pObject, 1);
      }
      pNext = this->DrawingContextList.Root.pNext;
      p_DrawingContextList = &this->DrawingContextList;
      while ( 1 )
      {
        v110 = this == (Scaleform::GFx::MovieImpl *)-16272 ? 0 : &this->RegisteredFonts.Data.Size;
        if ( pNext == (Scaleform::GFx::DrawingContext *)v110 )
          break;
        if ( (pNext->States & 0x80u) != 0 )
          Scaleform::GFx::DrawingContext::UpdateRenderNode(pNext, (int)p_DrawingContextList);
        pNext = pNext->pNext;
      }
      if ( this->FocusRectChanged )
        Scaleform::GFx::MovieImpl::UpdateFocusRectRenderNodes(this);
      Scaleform::GFx::MovieImpl::ResetTabableArrays(this);
      this->Flags &= ~2u;
      v111 = Scaleform::AmpServer::GetInstance();
      v111->MovieAdvance(v111, this);
      v122 = *(float *)&v120[1];
      v112 = Scaleform::Timer::GetProfileTicks() - v129;
      v129 = __PAIR64__(HIDWORD(v112) & 0x80000000, 0);
      *(float *)&v120[1] = v122 - (double)v112 / 1000000.0;
      if ( *(float *)&v120[1] < 0.0 )
        *(float *)&v120[1] = 0.0;
      if ( (_BYTE)capture )
        Scaleform::GFx::MovieImpl::Capture(this, 1);
      *(float *)v120 = this->FrameTime - this->TimeRemainder;
      v113 = *(float *)&v120[1];
      if ( *(float *)v120 <= (double)*(float *)&v120[1] )
        v113 = *(float *)v120;
      v114 = (Scaleform::RefCountVImpl *)this->pSoundRenderer;
      *(float *)&v124 = v113;
      if ( v114 )
      {
        Scaleform::RefCountImpl::Release(v114);
        this->pSoundRenderer = 0;
      }
      pAudio = (Scaleform::RefCountVImpl *)this->pAudio;
      if ( pAudio )
      {
        Scaleform::RefCountImpl::Release(pAudio);
        this->pAudio = 0;
      }
      if ( v132 )
        Scaleform::RefCountImpl::Release(v132);
      if ( *(float *)&v130 != 0.0 )
        Scaleform::RefCountImpl::Release(v130);
      _controlfp_s((int)p_DrawingContextList, &v144, _CurrentState, (unsigned int)&loc_30000);
      v116 = v131.Stats;
      if ( v131.Stats )
      {
        v117 = &v131.Stats->NativePopCallstack;
        v118 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v117)(
          v116,
          v118 - LODWORD(v131.StartTicks),
          (v118 - v131.StartTicks) >> 32);
      }
      return *(float *)&v124;
    }
    else
    {
      if ( (_BYTE)capture )
        Scaleform::GFx::MovieImpl::Capture(this, 1);
      this->Flags &= ~2u;
      v40 = (Scaleform::RefCountVImpl *)this->pSoundRenderer;
      if ( v40 )
      {
        Scaleform::RefCountImpl::Release(v40);
        this->pSoundRenderer = 0;
      }
      v41 = (Scaleform::RefCountVImpl *)this->pAudio;
      if ( v41 )
      {
        Scaleform::RefCountImpl::Release(v41);
        this->pAudio = 0;
      }
      if ( v132 )
        Scaleform::RefCountImpl::Release(v132);
      if ( v33 )
        Scaleform::RefCountImpl::Release(v33);
      _controlfp_s(0, (unsigned int *)&v122, _CurrentState, (unsigned int)&loc_30000);
      v42 = v131.Stats;
      if ( v131.Stats )
      {
        v43 = &v131.Stats->NativePopCallstack;
        v44 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v43)(
          v42,
          v44 - LODWORD(v131.StartTicks),
          (v44 - v131.StartTicks) >> 32);
      }
      return 0.0;
    }
  }
  else
  {
    if ( (_BYTE)capture )
      Scaleform::GFx::MovieImpl::Capture(this, 1);
    v11 = this->pMainMovieDef.pObject;
    if ( v11 )
      v12 = 1.0 / ((double (__thiscall *)(Scaleform::GFx::MovieDefImpl *))v11->GetFrameRate)(v11);
    else
      v12 = 0.0;
    v13 = v131.Stats;
    *(float *)&v130 = v12;
    if ( v131.Stats )
    {
      v14 = &v131.Stats->NativePopCallstack;
      v15 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v14)(
        v13,
        v15 - LODWORD(v131.StartTicks),
        (v15 - v131.StartTicks) >> 32);
    }
    return *(float *)&v130;
  }
}
