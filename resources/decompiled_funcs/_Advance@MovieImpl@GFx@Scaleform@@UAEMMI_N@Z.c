// local variable allocation has failed, the output may be wrong!
double __userpurge Scaleform::GFx::MovieImpl::Advance@<st0>(
        Scaleform::GFx::MovieImpl *this@<ecx>,
        int a2@<ebp>,
        float deltaT,
        unsigned int frameCatchUpCount,
        int capture)
{
  Scaleform::GFx::MovieDefImpl *v7; // esi
  Scaleform::GFx::StateBag *v8; // ecx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::UserEventHandler *Capacity; // ebx
  Scaleform::RefCountVImpl *v11; // ecx
  Scaleform::GFx::FSCommandHandler *v12; // ebx
  Scaleform::RefCountVImpl *v13; // ecx
  Scaleform::GFx::ExternalInterface *v14; // ebx
  Scaleform::GFx::LogState *v15; // eax
  Scaleform::Ptr<Scaleform::GFx::ActionControl> v16; // ecx
  Scaleform::Log *GlobalLog; // eax
  Scaleform::GFx::Resource *v18; // ebx
  Scaleform::Log *v19; // ecx
  Scaleform::GFx::Translator *v20; // edi
  Scaleform::GFx::FontMap *v21; // edx
  Scaleform::GFx::FontLib *v22; // eax
  Scaleform::GFx::FontManagerStates *v23; // ecx
  unsigned __int8 v24; // bl
  Scaleform::GFx::ActionControl *v25; // eax
  Scaleform::GFx::AudioBase *v26; // ecx
  Scaleform::Sound::SoundRenderer *v27; // eax
  Scaleform::GFx::MovieDefRootNode *i; // edi
  Scaleform::ArrayDefaultPolicy *v29; // eax
  _DWORD *v30; // ecx
  unsigned int v31; // edi
  int v32; // ebx
  Scaleform::GFx::InteractiveObject *v33; // ecx
  Scaleform::RefCountVImpl *v34; // ecx
  Scaleform::RefCountVImpl *v35; // ecx
  unsigned int k; // edi
  Scaleform::GFx::InteractiveObject *v37; // ecx
  unsigned __int64 v38; // rax
  double v39; // st7
  bool v40; // cf
  unsigned __int64 ProfileTicks; // rax
  unsigned int Size; // ebx
  int v43; // ebp
  unsigned int m; // edi
  Scaleform::GFx::ASIntervalTimerIntf *v45; // ecx
  Scaleform::GFx::ASIntervalTimerIntf *v46; // ecx
  unsigned __int64 v47; // rax
  const Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *v48; // eax
  int v49; // ebx
  int v50; // edi
  Scaleform::GFx::ASIntervalTimerIntf *v51; // ecx
  Scaleform::RefCountVImpl **Data; // edi
  int v53; // ebx
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *pTable; // eax
  unsigned int v55; // edi
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *v56; // ecx
  Scaleform::HashSet<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *p_VideoProviders; // edx
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *v58; // eax
  Scaleform::RefCountNTSImpl **v59; // ecx
  Scaleform::RefCountNTSImpl *v60; // ebp
  bool v61; // zf
  Scaleform::RefCountNTSImpl_vtbl *v62; // eax
  double v63; // st7
  unsigned int v64; // ebx
  Scaleform::GFx::Video::VideoProvider **v65; // ebx
  unsigned int v66; // eax
  _DWORD *v67; // ecx
  unsigned int v68; // ebp
  Scaleform::GFx::Video::VideoProvider **v69; // ebx
  unsigned int n; // edi
  Scaleform::Sound::SoundRenderer *pSoundRenderer; // ecx
  long double TimeRemainder; // st7
  long double v73; // st7
  double v74; // st7
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *v75; // eax
  unsigned int v76; // edi
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *v77; // ecx
  Scaleform::HashSet<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *Index; // edx
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *v79; // eax
  Scaleform::RefCountNTSImpl **v80; // ecx
  Scaleform::RefCountNTSImpl *v81; // ebx
  char v82; // al
  Scaleform::RefCountNTSImpl_vtbl *v83; // edx
  double v84; // st7
  unsigned int v85; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object **v86; // ebp
  unsigned int v87; // eax
  _DWORD *v88; // ecx
  unsigned int v89; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object **v90; // ebx
  unsigned int ii; // edi
  unsigned int ForceFrameCatchUp; // eax
  int v93; // ecx
  Scaleform::GFx::ASMovieRootBase *v94; // ecx
  Scaleform::GFx::DrawingContext *jj; // edi
  unsigned int *v96; // eax
  double v97; // st7
  unsigned __int64 v98; // rax
  double v99; // st7
  Scaleform::RefCountVImpl *v100; // ecx
  Scaleform::RefCountVImpl *pAudio; // ecx
  Scaleform::Ptr<Scaleform::GFx::FontLib> fl; // [esp+34h] [ebp-74h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ActionControl> pac; // [esp+38h] [ebp-70h]
  __int64 j; // [esp+3Ch] [ebp-6Ch] BYREF
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::Iterator it; // [esp+44h] [ebp-64h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> logState; // [esp+4Ch] [ebp-5Ch]
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+50h] [ebp-58h] BYREF
  double delta; // [esp+54h] [ebp-54h] OVERLAPPED
  unsigned __int64 advanceStart; // [esp+5Ch] [ebp-4Ch] BYREF
  unsigned int _CurrentState; // [esp+64h] [ebp-44h] BYREF
  Scaleform::Array<Scaleform::GFx::Video::VideoProvider *,2,Scaleform::ArrayDefaultPolicy> remove_list; // [esp+68h] [ebp-40h] BYREF
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+78h] [ebp-30h] BYREF
  Scaleform::GFx::FSCommandHandler *v114; // [esp+84h] [ebp-24h]
  Scaleform::GFx::ExternalInterface *v115; // [esp+88h] [ebp-20h]
  Scaleform::GFx::ActionControl *v116; // [esp+8Ch] [ebp-1Ch]
  Scaleform::GFx::LogState *v117; // [esp+90h] [ebp-18h]
  Scaleform::GFx::FontLib *v118; // [esp+94h] [ebp-14h]
  Scaleform::GFx::FontMap *v119; // [esp+98h] [ebp-10h]
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *v120; // [esp+9Ch] [ebp-Ch]
  Scaleform::GFx::Translator *v121; // [esp+A0h] [ebp-8h]
  Scaleform::GFx::AudioBase *v122; // [esp+A4h] [ebp-4h]

  if ( (this->Flags & 0x100000) != 0 )
  {
    if ( (_BYTE)capture )
      Scaleform::GFx::MovieImpl::Capture(this, 1);
    return 0.050000001;
  }
  else if ( this->pMainMovie )
  {
    Scaleform::GFx::MovieImpl::ProcessMovieDefToKillList(this);
    _controlfp_s(&dpg.fpc, 0, 0);
    _controlfp_s((unsigned int *)&fl, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
    if ( deltaT < 0.0 )
      deltaT = 0.0;
    this->Flags |= 0x200u;
    v8 = &this->pStateBag.pObject->Scaleform::GFx::StateBag;
    pheapAddr.Policy.Capacity = 0;
    v114 = 0;
    v115 = 0;
    v116 = 0;
    v117 = 0;
    v118 = 0;
    v119 = 0;
    v120 = 0;
    v121 = 0;
    v122 = 0;
    v8->GetStatesAddRef(v8, (Scaleform::GFx::State **)&pheapAddr.Policy, stateQuery, 10u);
    pObject = (Scaleform::RefCountVImpl *)this->pUserEventHandler.pObject;
    Capacity = (Scaleform::GFx::UserEventHandler *)pheapAddr.Policy.Capacity;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pUserEventHandler.pObject = Capacity;
    v11 = (Scaleform::RefCountVImpl *)this->pFSCommandHandler.pObject;
    v12 = v114;
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    this->pFSCommandHandler.pObject = v12;
    v13 = (Scaleform::RefCountVImpl *)this->pExtIntfHandler.pObject;
    v14 = v115;
    if ( v13 )
      Scaleform::RefCountImpl::Release(v13);
    v15 = v117;
    v16.pObject = v116;
    this->pExtIntfHandler.pObject = v14;
    pac.pObject = v16.pObject;
    logState.pObject = v15;
    if ( v15 )
    {
      GlobalLog = v15->pLog.pObject;
      if ( !GlobalLog )
        GlobalLog = Scaleform::Log::GetGlobalLog();
      v18 = (Scaleform::GFx::Resource *)GlobalLog;
    }
    else
    {
      v18 = 0;
    }
    if ( v18 )
      Scaleform::RefCountImpl::AddRef(v18);
    v19 = this->pCachedLog.pObject;
    if ( v19 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v19);
    v20 = v121;
    v21 = v119;
    v22 = v118;
    this->pCachedLog.pObject = (Scaleform::Log *)v18;
    v23 = this->pFontManagerStates.pObject;
    fl.pObject = v22;
    LODWORD(j) = v21;
    it.pHash = v120;
    v24 = Scaleform::GFx::FontManagerStates::CheckStateChange(v23, v22, v21, (Scaleform::GFx::FontProvider *)v120, v20);
    LOBYTE(delta) = v24;
    if ( v20 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v20);
    if ( it.pHash )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)it.pHash);
    if ( (_DWORD)j )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)j);
    if ( *(float *)&fl.pObject != 0.0 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)fl.pObject);
    v25 = pac.pObject;
    this->Flags |= 2u;
    if ( v25 )
    {
      if ( (v25->ActionFlags & 1) != 0 )
        this->Flags |= 4u;
      else
        this->Flags &= ~4u;
      if ( (v25->ActionFlags & 2) != 0 )
        this->Flags |= 0x40u;
      else
        this->Flags &= ~0x40u;
      if ( (v25->ActionFlags & 4) != 0 )
        this->Flags |= 8u;
      else
        this->Flags &= ~8u;
      if ( (v25->ActionFlags & 0x10) != 0 )
        this->Flags |= 0x20u;
      else
        this->Flags &= ~0x20u;
      if ( (v25->ActionFlags & 8) != 0 )
        this->Flags |= 0x10u;
      else
        this->Flags &= ~0x10u;
    }
    else
    {
      this->Flags &= 0xFFFFFF83;
    }
    v26 = v122;
    this->pAudio = v122;
    if ( v26 )
    {
      v27 = v26->GetRenderer(v26);
      this->pSoundRenderer = v27;
      if ( v27 )
        Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v27);
    }
    for ( i = this->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
    {
      v29 = this == (Scaleform::GFx::MovieImpl *)-56 ? 0 : &this->MovieLevels.Data.Policy;
      if ( i == (Scaleform::GFx::MovieDefRootNode *)v29 )
        break;
      if ( !i->ImportFlag )
      {
        v30 = &i->pDefImpl->__vftable;
        i->BytesLoaded = *(_DWORD *)(v30[7] + 132);
        i->LoadingFrame = (*(int (__thiscall **)(_DWORD *))(*v30 + 20))(v30);
      }
      if ( v24 )
        i->pFontManager.pObject->CleanCache(i->pFontManager.pObject);
    }
    if ( v24 || (this->Flags2 & 2) != 0 )
    {
      v31 = 0;
      if ( this->MovieLevels.Data.Size )
      {
        v32 = LODWORD(delta);
        do
        {
          v33 = this->MovieLevels.Data.Data[v31].pSprite.pObject;
          v33->SetStateChangeFlags(v33, v32);
          ++v31;
        }
        while ( v31 < this->MovieLevels.Data.Size );
      }
    }
    if ( this->pMainMovie->GetLoadingFrame(this->pMainMovie) )
    {
      if ( (this->Flags & 0x100) != 0 && this->pMainMovie->GetLoadingFrame(this->pMainMovie) )
      {
        this->Flags &= ~0x100u;
        for ( k = this->MovieLevels.Data.Size; k; --k )
        {
          v37 = this->MovieLevels.Data.Data[k - 1].pSprite.pObject;
          v37->ExecuteFrame0Events(v37);
        }
        this->pASMovieRoot.pObject->DoActions(this->pASMovieRoot.pObject);
        Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
        Scaleform::GFx::MovieImpl::ProcessLoadQueue(this);
      }
      v38 = (unsigned __int64)(1000000.0 * deltaT);
      v39 = deltaT + this->TimeRemainder;
      v40 = __CFADD__((_DWORD)v38, this->TimeElapsed);
      LODWORD(this->TimeElapsed) += v38;
      this->TimeRemainder = v39;
      HIDWORD(this->TimeElapsed) += HIDWORD(v38) + v40;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      Size = this->IntervalTimers.Data.Size;
      fl.pObject = (Scaleform::GFx::FontLib *)LODWORD(this->FrameTime);
      advanceStart = ProfileTicks;
      if ( Size )
      {
        v43 = 0;
        for ( m = 0; m < Size; ++m )
        {
          v45 = this->IntervalTimers.Data.Data[m].pObject;
          if ( v45 && v45->IsActive(v45) )
          {
            ((void (__stdcall *)(_DWORD, _DWORD))this->IntervalTimers.Data.Data[m].pObject->Invoke)(
              this,
              this->FrameTime);
            v46 = this->IntervalTimers.Data.Data[m].pObject;
            v47 = v46->GetNextInvokeTime(v46);
            v40 = (unsigned int)v47 < LODWORD(this->TimeElapsed);
            LODWORD(v47) = v47 - LODWORD(this->TimeElapsed);
            LODWORD(j) = 0;
            HIDWORD(v47) -= v40 + HIDWORD(this->TimeElapsed);
            it = (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::Iterator)(v47 & 0x7FFFFFFFFFFFFFFFLL);
            HIDWORD(j) = HIDWORD(v47) & 0x80000000;
            *(float *)&delta = (double)v47 / 1000000.0;
            if ( *(float *)&fl.pObject > (double)*(float *)&delta )
              fl.pObject = (Scaleform::GFx::FontLib *)LODWORD(delta);
          }
          else
          {
            ++v43;
          }
        }
        if ( v43 )
        {
          v48 = (const Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *)this->IntervalTimers.Data.Size;
          v49 = 0;
          LODWORD(j) = 0;
          if ( v48 )
          {
            it.pHash = v48;
            while ( 1 )
            {
              v50 = v49;
              v51 = this->IntervalTimers.Data.Data[v49].pObject;
              if ( v51 && v51->IsActive(v51) )
              {
                LODWORD(j) = v49 + 1;
              }
              else
              {
                this->IntervalTimers.Data.Data[v50].pObject->Clear(this->IntervalTimers.Data.Data[v50].pObject);
                if ( this->IntervalTimers.Data.Size == 1 )
                {
                  Data = (Scaleform::RefCountVImpl **)this->IntervalTimers.Data.Data;
                  v53 = 1;
                  do
                  {
                    if ( *Data )
                      Scaleform::RefCountImpl::Release(*Data);
                    --Data;
                    --v53;
                  }
                  while ( v53 );
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
                  if ( this->IntervalTimers.Data.Data[v50].pObject )
                    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->IntervalTimers.Data.Data[v50].pObject);
                  memmove(
                    (unsigned __int8 *)&this->IntervalTimers.Data.Data[v50],
                    (unsigned __int8 *)&this->IntervalTimers.Data.Data[v50 + 1],
                    4 * (this->IntervalTimers.Data.Size - v49) - 4);
                  --this->IntervalTimers.Data.Size;
                }
              }
              if ( !--it.pHash )
                break;
              v49 = j;
            }
          }
        }
      }
      pTable = this->VideoProviders.pTable;
      v55 = 0;
      if ( pTable && pTable->EntryCount )
      {
        memset(&remove_list, 0, sizeof(remove_list));
        v56 = pTable + 1;
        do
        {
          if ( v56->EntryCount != -2 )
            break;
          ++v55;
          v56 = (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *)((char *)v56 + 12);
        }
        while ( v55 <= pTable->SizeMask );
        p_VideoProviders = &this->VideoProviders;
        LODWORD(delta) = &this->VideoProviders;
        while ( p_VideoProviders )
        {
          v58 = p_VideoProviders->pTable;
          if ( !p_VideoProviders->pTable || (signed int)v55 > (signed int)v58->SizeMask )
            break;
          v59 = (Scaleform::RefCountNTSImpl **)&v58[2] + 3 * v55;
          if ( *v59 )
            ++(*v59)->RefCount;
          v60 = *v59;
          (*v59)->__vftable[2].~Scaleform::RefCountNTSImpl(*v59);
          v61 = ((unsigned __int8 (__thiscall *)(Scaleform::RefCountNTSImpl *))v60->__vftable[5].~Scaleform::RefCountNTSImpl)(v60) == 0;
          v62 = v60->__vftable;
          if ( v61 )
          {
            v62[4].~Scaleform::RefCountNTSImpl(v60);
            v64 = remove_list.Data.Size + 1;
            if ( remove_list.Data.Size + 1 >= remove_list.Data.Size )
            {
              if ( v64 >= remove_list.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&remove_list,
                  &remove_list,
                  v64 + (v64 >> 2));
            }
            else if ( v64 < remove_list.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&remove_list,
                &remove_list,
                remove_list.Data.Size + 1);
            }
            remove_list.Data.Size = v64;
            v65 = &remove_list.Data.Data[v64 - 1];
            if ( v65 )
              *v65 = (Scaleform::GFx::Video::VideoProvider *)v60;
          }
          else
          {
            v63 = ((double (__thiscall *)(Scaleform::RefCountNTSImpl *))v62[6].~Scaleform::RefCountNTSImpl)(v60);
            if ( *(float *)&fl.pObject > v63 )
              *(float *)&fl.pObject = ((double (__thiscall *)(Scaleform::RefCountNTSImpl *))v60->__vftable[6].~Scaleform::RefCountNTSImpl)(v60);
          }
          Scaleform::RefCountNTSImpl::Release(v60);
          p_VideoProviders = (Scaleform::HashSet<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *)LODWORD(delta);
          v66 = *(_DWORD *)(*(_DWORD *)LODWORD(delta) + 4);
          if ( (int)v55 <= (int)v66 && ++v55 <= v66 )
          {
            v67 = (_DWORD *)(*(_DWORD *)LODWORD(delta) + 12 * v55 + 8);
            do
            {
              if ( *v67 != -2 )
                break;
              ++v55;
              v67 += 3;
            }
            while ( v55 <= v66 );
          }
        }
        v68 = remove_list.Data.Size;
        v69 = remove_list.Data.Data;
        for ( n = 0; n < v68; ++n )
        {
          it.pHash = (const Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *)v69[n];
          Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>>>::RemoveAlt<Scaleform::GFx::Video::VideoProvider *>(
            &this->VideoProviders,
            (Scaleform::RefCountNTSImpl **)&it);
        }
        if ( v69 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v69);
      }
      pSoundRenderer = this->pSoundRenderer;
      if ( pSoundRenderer )
      {
        *(float *)&delta = pSoundRenderer->Update(pSoundRenderer);
        if ( *(float *)&fl.pObject > (double)*(float *)&delta )
          fl.pObject = (Scaleform::GFx::FontLib *)LODWORD(delta);
      }
      Scaleform::GFx::MovieImpl::ProcessInput(this);
      if ( this->FrameTime > (double)this->TimeRemainder )
      {
        *(float *)&delta = this->TimeRemainder / this->FrameTime;
        Scaleform::GFx::MovieImpl::AdvanceFrame(this, 0, *(float *)&delta);
        *(float *)&delta = fmod(this->TimeRemainder, this->FrameTime);
        v94 = this->pASMovieRoot.pObject;
        this->TimeRemainder = *(float *)&delta;
        v94->DoActions(v94);
        Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
        Scaleform::GFx::MovieImpl::ProcessLoadQueue(this);
        this->pASMovieRoot.pObject->AdvanceFrame(this->pASMovieRoot.pObject, 0);
      }
      else
      {
        ((void (__thiscall *)(Scaleform::GFx::ASMovieRootBase *, int))this->pASMovieRoot.pObject->DoActions)(
          this->pASMovieRoot.pObject,
          a2);
        if ( capture || (HIBYTE(fl.pObject) = 0, this->ForceFrameCatchUp) )
          HIBYTE(fl.pObject) = 1;
        do
        {
          TimeRemainder = this->TimeRemainder;
          if ( HIBYTE(fl.pObject) )
          {
            v73 = TimeRemainder - this->FrameTime;
          }
          else
          {
            *((float *)&delta + 1) = fmod(TimeRemainder, this->FrameTime);
            v73 = *((float *)&delta + 1);
          }
          this->TimeRemainder = v73;
          if ( this->FrameTime > (double)this->TimeRemainder )
            v74 = this->TimeRemainder / this->FrameTime;
          else
            v74 = 0.0;
          *((float *)&delta + 1) = v74;
          Scaleform::GFx::MovieImpl::AdvanceFrame(this, 1, *((float *)&delta + 1));
          v75 = this->VideoProviders.pTable;
          if ( v75 && v75->EntryCount )
          {
            v76 = 0;
            memset(&pheapAddr, 0, sizeof(pheapAddr));
            v77 = v75 + 1;
            do
            {
              if ( v77->EntryCount != -2 )
                break;
              ++v76;
              v77 = (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > >::TableType *)((char *)v77 + 12);
            }
            while ( v76 <= v75->SizeMask );
            Index = &this->VideoProviders;
            it.Index = (int)&this->VideoProviders;
            while ( Index )
            {
              v79 = Index->pTable;
              if ( !Index->pTable || (signed int)v76 > (signed int)v79->SizeMask )
                break;
              v80 = (Scaleform::RefCountNTSImpl **)&v79[2] + 3 * v76;
              if ( *v80 )
                ++(*v80)->RefCount;
              v81 = *v80;
              (*v80)->__vftable[2].~Scaleform::RefCountNTSImpl(*v80);
              v82 = ((int (__thiscall *)(Scaleform::RefCountNTSImpl *))v81->__vftable[5].~Scaleform::RefCountNTSImpl)(v81);
              v83 = v81->__vftable;
              if ( v82 )
              {
                v84 = ((double (__thiscall *)(Scaleform::RefCountNTSImpl *))v83[6].~Scaleform::RefCountNTSImpl)(v81);
                if ( *(float *)&pac.pObject > v84 )
                  *(float *)&pac.pObject = ((double (__thiscall *)(Scaleform::RefCountNTSImpl *))v81->__vftable[6].~Scaleform::RefCountNTSImpl)(v81);
              }
              else
              {
                v83[4].~Scaleform::RefCountNTSImpl(v81);
                v85 = pheapAddr.Size + 1;
                if ( pheapAddr.Size + 1 >= pheapAddr.Size )
                {
                  if ( v85 >= pheapAddr.Policy.Capacity )
                    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                      &pheapAddr,
                      &pheapAddr,
                      v85 + (v85 >> 2));
                }
                else if ( v85 < pheapAddr.Policy.Capacity >> 1 )
                {
                  Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                    &pheapAddr,
                    &pheapAddr,
                    pheapAddr.Size + 1);
                }
                pheapAddr.Size = v85;
                v86 = &pheapAddr.Data[v85 - 1];
                if ( v86 )
                  *v86 = (Scaleform::GFx::AS3::Instances::fl::Object *)v81;
              }
              Scaleform::RefCountNTSImpl::Release(v81);
              Index = (Scaleform::HashSet<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > > *)it.Index;
              v87 = *(_DWORD *)(*(_DWORD *)it.Index + 4);
              if ( (int)v76 <= (int)v87 && ++v76 <= v87 )
              {
                v88 = (_DWORD *)(*(_DWORD *)it.Index + 12 * v76 + 8);
                do
                {
                  if ( *v88 != -2 )
                    break;
                  ++v76;
                  v88 += 3;
                }
                while ( v76 <= v87 );
              }
            }
            v89 = pheapAddr.Size;
            v90 = pheapAddr.Data;
            for ( ii = 0; ii < v89; ++ii )
            {
              HIDWORD(j) = v90[ii];
              Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>>>::RemoveAlt<Scaleform::GFx::Video::VideoProvider *>(
                &this->VideoProviders,
                (Scaleform::RefCountNTSImpl **)&j + 1);
            }
            if ( v90 )
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v90);
          }
          this->pASMovieRoot.pObject->DoActions(this->pASMovieRoot.pObject);
          Scaleform::GFx::MovieImpl::ProcessUnloadQueue(this);
          Scaleform::GFx::MovieImpl::ProcessLoadQueue(this);
          ForceFrameCatchUp = this->ForceFrameCatchUp;
          if ( ForceFrameCatchUp )
            this->ForceFrameCatchUp = ForceFrameCatchUp - 1;
          v93 = capture--;
        }
        while ( v93 && this->FrameTime <= (double)this->TimeRemainder || this->ForceFrameCatchUp );
        this->Flags |= 0x80u;
        this->pASMovieRoot.pObject->AdvanceFrame(this->pASMovieRoot.pObject, 1);
      }
      for ( jj = this->DrawingContextList.Root.pNext; ; jj = jj->pNext )
      {
        v96 = this == (Scaleform::GFx::MovieImpl *)-16272 ? 0 : &this->RegisteredFonts.Data.Size;
        if ( jj == (Scaleform::GFx::DrawingContext *)v96 )
          break;
        if ( (jj->States & 0x80u) != 0 )
          Scaleform::GFx::DrawingContext::UpdateRenderNode(jj);
      }
      if ( this->FocusRectChanged )
        Scaleform::GFx::MovieImpl::UpdateFocusRectRenderNodes(this);
      Scaleform::GFx::MovieImpl::ResetTabableArrays(this);
      v97 = *(float *)&fl.pObject;
      this->Flags &= ~2u;
      delta = v97;
      v98 = Scaleform::Timer::GetProfileTicks() - advanceStart;
      advanceStart = __PAIR64__(HIDWORD(v98) & 0x80000000, 0);
      *(float *)&fl.pObject = delta - (double)v98 / 1000000.0;
      if ( *(float *)&fl.pObject < 0.0 )
        *(float *)&fl.pObject = 0.0;
      if ( (_BYTE)capture )
        Scaleform::GFx::MovieImpl::Capture(this, 1);
      *(float *)&delta = this->FrameTime - this->TimeRemainder;
      v99 = *(float *)&fl.pObject;
      if ( *(float *)&delta <= (double)*(float *)&fl.pObject )
        v99 = *(float *)&delta;
      v100 = (Scaleform::RefCountVImpl *)this->pSoundRenderer;
      *(float *)&it.pHash = v99;
      if ( v100 )
      {
        Scaleform::RefCountImpl::Release(v100);
        this->pSoundRenderer = 0;
      }
      pAudio = (Scaleform::RefCountVImpl *)this->pAudio;
      if ( pAudio )
      {
        Scaleform::RefCountImpl::Release(pAudio);
        this->pAudio = 0;
      }
      if ( logState.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)logState.pObject);
      if ( *(float *)&pac.pObject != 0.0 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pac.pObject);
      _controlfp_s(&_CurrentState, dpg.fpc, 0x30000u);
      return *(float *)&it.pHash;
    }
    else
    {
      if ( (_BYTE)capture )
        Scaleform::GFx::MovieImpl::Capture(this, 1);
      this->Flags &= ~2u;
      v34 = (Scaleform::RefCountVImpl *)this->pSoundRenderer;
      if ( v34 )
      {
        Scaleform::RefCountImpl::Release(v34);
        this->pSoundRenderer = 0;
      }
      v35 = (Scaleform::RefCountVImpl *)this->pAudio;
      if ( v35 )
      {
        Scaleform::RefCountImpl::Release(v35);
        this->pAudio = 0;
      }
      if ( logState.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)logState.pObject);
      if ( *(float *)&pac.pObject != 0.0 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pac.pObject);
      _controlfp_s((unsigned int *)&advanceStart, dpg.fpc, 0x30000u);
      return 0.0;
    }
  }
  else
  {
    if ( (_BYTE)capture )
      Scaleform::GFx::MovieImpl::Capture(this, 1);
    v7 = this->pMainMovieDef.pObject;
    if ( v7 )
    {
      *(float *)&dpg.fpc = 1.0 / ((double (__thiscall *)(Scaleform::GFx::MovieDefImpl *))v7->GetFrameRate)(v7);
      return *(float *)&dpg.fpc;
    }
    else
    {
      *(float *)&dpg.fpc = 0.0;
      return (float)0.0;
    }
  }
}
