void __thiscall Scaleform::GFx::AMP::Server::SendFrameStats(Scaleform::GFx::AMP::Server *this)
{
  Scaleform::GFx::AMP::Server *v1; // ebp
  Scaleform::Lock *p_RecordingStateLock; // esi
  Scaleform::GFx::AMP::ProfileFrame *v3; // eax
  Scaleform::GFx::AMP::ProfileFrame *v4; // eax
  Scaleform::GFx::AMP::ProfileFrame *v5; // esi
  unsigned __int64 ProfileTicks; // rax
  unsigned __int64 v7; // kr00_8
  bool v8; // cf
  unsigned int v9; // ecx
  int v10; // eax
  unsigned int v11; // edx
  bool v12; // bl
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::TableType *pTable; // eax
  LPCRITICAL_SECTION p_HandleToSwdIdMap; // edx
  int v15; // ebx
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SwdInfo>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v17; // eax
  _RTL_CRITICAL_SECTION_DEBUG *DebugInfo; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_SwdHandles; // edi
  unsigned int v20; // esi
  unsigned int *v21; // ebp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v23; // esi
  _RTL_CRITICAL_SECTION *CriticalSection; // eax
  _LIST_ENTRY **v25; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v26; // eax
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_HandleToSourceFileMap; // edx
  unsigned int v28; // edi
  unsigned int v29; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v30; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v31; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *p_FileHandles; // ebp
  unsigned int v33; // esi
  Scaleform::GFx::DisplayObjectBase **v34; // ebx
  Scaleform::GFx::Button::CharToRec *v35; // eax
  unsigned int v36; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v37; // ecx
  Scaleform::GFx::Resource *v38; // edi
  int v39; // ebx
  Scaleform::GFx::Resource **Log; // edi
  Scaleform::GFx::AMP::MessageProfileFrame *v41; // eax
  Scaleform::RefCountVImpl *v42; // eax
  char v43; // [esp+13h] [ebp-19h]
  Scaleform::GFx::AMP::ProfileFrame *v44; // [esp+14h] [ebp-18h]
  LPCRITICAL_SECTION lpCriticalSection[2]; // [esp+1Ch] [ebp-10h] BYREF
  Scaleform::HashLH<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::Server::SourceFileInfo>,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v47; // [esp+24h] [ebp-8h]

  v1 = this;
  p_RecordingStateLock = &this->RecordingStateLock;
  v43 = 0;
  EnterCriticalSection(&this->RecordingStateLock.cs);
  if ( v1->RecordingState == Amp_Server_Recording_On )
  {
    LeaveCriticalSection(&p_RecordingStateLock->cs);
    return;
  }
  if ( v1->RecordingState == Amp_Server_Recording_Stopped )
  {
    v43 = 1;
    v1->RecordingState = Amp_Server_Recording_Off;
  }
  LeaveCriticalSection(&p_RecordingStateLock->cs);
  v3 = (Scaleform::GFx::AMP::ProfileFrame *)v1->ReportHeap->Alloc(v1->ReportHeap, 304u, 0);
  if ( v3 )
  {
    Scaleform::GFx::AMP::ProfileFrame::ProfileFrame(v3);
    v5 = v4;
    v44 = v4;
  }
  else
  {
    v44 = 0;
    v5 = 0;
  }
  if ( (_S4_0 & 1) == 0 )
  {
    _S4_0 |= 1u;
    firstTick = Scaleform::Timer::GetProfileTicks();
  }
  ProfileTicks = Scaleform::Timer::GetProfileTicks();
  v7 = ProfileTicks - firstTick;
  v8 = (int)ProfileTicks - (int)firstTick < (unsigned int)lastTick;
  v9 = ProfileTicks - firstTick - lastTick;
  v5->TimeStamp = ProfileTicks - firstTick;
  v10 = HIDWORD(v7) - (v8 + HIDWORD(lastTick));
  v11 = ++frameCounter;
  if ( v10 || v9 > (unsigned int)&loc_F4240 )
  {
    lastFps = 1000000 * v11 / __PAIR64__(v10, v9);
    frameCounter = 0;
    lastTick = v7;
  }
  v5->FramesPerSecond = lastFps;
  v5->ProfilingLevel = v1->GetProfileLevel(&v1->Scaleform::AmpServer);
  EnterCriticalSection(&v1->CurrentStateLock.cs);
  v12 = (v1->CurrentState.StateFlags & 0x20) != 0;
  LeaveCriticalSection(&v1->CurrentStateLock.cs);
  v5->DetailedMemReport = v12;
  EnterCriticalSection(&v1->SwfLock.cs);
  pTable = v1->HandleToSwdIdMap.mHash.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v15 = 0;
    v17 = pTable + 1;
    do
    {
      if ( v17->EntryCount != -2 )
        break;
      ++v15;
      v17 += 2;
    }
    while ( v15 <= SizeMask );
    lpCriticalSection[0] = (LPCRITICAL_SECTION)&v1->HandleToSwdIdMap;
    p_HandleToSwdIdMap = (LPCRITICAL_SECTION)&v1->HandleToSwdIdMap;
  }
  else
  {
    p_HandleToSwdIdMap = 0;
    lpCriticalSection[0] = 0;
    v15 = 0;
  }
  while ( p_HandleToSwdIdMap )
  {
    DebugInfo = p_HandleToSwdIdMap->DebugInfo;
    if ( !p_HandleToSwdIdMap->DebugInfo || v15 > (int)DebugInfo->CriticalSection )
      break;
    p_SwdHandles = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v5->SwdHandles;
    v20 = v5->SwdHandles.Data.Size + 1;
    v21 = &DebugInfo->EntryCount + 4 * v15;
    if ( v20 >= p_SwdHandles->Size )
    {
      if ( v20 < p_SwdHandles->Policy.Capacity )
        goto LABEL_28;
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_SwdHandles,
        p_SwdHandles,
        v20 + (v20 >> 2));
    }
    else
    {
      if ( v20 >= p_SwdHandles->Policy.Capacity >> 1 )
        goto LABEL_28;
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_SwdHandles,
        p_SwdHandles,
        v20);
    }
    p_HandleToSwdIdMap = lpCriticalSection[0];
LABEL_28:
    Data = p_SwdHandles->Data;
    p_SwdHandles->Size = v20;
    v23 = &Data[v20 - 1];
    if ( v23 )
      v23->pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)*v21;
    CriticalSection = p_HandleToSwdIdMap->DebugInfo->CriticalSection;
    if ( v15 <= (int)CriticalSection && ++v15 <= (unsigned int)CriticalSection )
    {
      v25 = &p_HandleToSwdIdMap->DebugInfo->ProcessLocksList.Flink + 4 * v15;
      do
      {
        if ( *v25 != (_LIST_ENTRY *)-2 )
          break;
        ++v15;
        v25 += 4;
      }
      while ( v15 <= (unsigned int)CriticalSection );
    }
    v1 = this;
    v5 = v44;
  }
  LeaveCriticalSection(&v1->SwfLock.cs);
  lpCriticalSection[0] = &v1->SourceFileLock.cs;
  EnterCriticalSection(&v1->SourceFileLock.cs);
  v26 = v1->HandleToSourceFileMap.mHash.pTable;
  p_HandleToSourceFileMap = &v1->HandleToSourceFileMap;
  if ( v26 )
  {
    v29 = v26->SizeMask;
    v28 = 0;
    v30 = v26 + 1;
    do
    {
      if ( v30->EntryCount != -2 )
        break;
      ++v28;
      v30 += 3;
    }
    while ( v28 <= v29 );
    v47 = &v1->HandleToSourceFileMap;
  }
  else
  {
    p_HandleToSourceFileMap = 0;
    v47 = 0;
    v28 = 0;
  }
  while ( p_HandleToSourceFileMap )
  {
    v31 = p_HandleToSourceFileMap->mHash.pTable;
    if ( !p_HandleToSourceFileMap->mHash.pTable || (signed int)v28 > (signed int)v31->SizeMask )
      break;
    p_FileHandles = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&v5->FileHandles;
    v33 = v5->FileHandles.Data.Size + 1;
    v34 = (Scaleform::GFx::DisplayObjectBase **)&v31[3 * v28 + 2];
    if ( v33 >= p_FileHandles->Size )
    {
      if ( v33 < p_FileHandles->Policy.Capacity )
        goto LABEL_52;
      Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_FileHandles,
        p_FileHandles,
        v33 + (v33 >> 2));
    }
    else
    {
      if ( v33 >= p_FileHandles->Policy.Capacity >> 1 )
        goto LABEL_52;
      Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_FileHandles,
        p_FileHandles,
        v33);
    }
    p_HandleToSourceFileMap = v47;
LABEL_52:
    v35 = &p_FileHandles->Data[v33 - 1];
    p_FileHandles->Size = v33;
    if ( v35 )
    {
      v35->Char.pObject = *v34;
      v35->Record = (const Scaleform::GFx::ButtonRecord *)v34[1];
    }
    v36 = p_HandleToSourceFileMap->mHash.pTable->SizeMask;
    if ( (int)v28 <= (int)v36 && ++v28 <= v36 )
    {
      v37 = &p_HandleToSourceFileMap->mHash.pTable[3 * v28 + 1];
      do
      {
        if ( v37->EntryCount != -2 )
          break;
        ++v28;
        v37 += 3;
      }
      while ( v28 <= v36 );
    }
    v1 = this;
    v5 = v44;
  }
  LeaveCriticalSection(lpCriticalSection[0]);
  Scaleform::GFx::AMP::Server::CollectMovieData(v1, v5);
  Scaleform::GFx::AMP::Server::CollectRendererData(v1, v5);
  Scaleform::GFx::AMP::Server::CollectTaskData(v1, v5);
  Scaleform::GFx::AMP::Server::CollectMemoryData(v1, v5);
  if ( v43 )
  {
    v38 = 0;
    EnterCriticalSection(&v1->LoaderLock.cs);
    v39 = 0;
    if ( v1->Loaders.Data.Size )
    {
      while ( 1 )
      {
        Log = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetLog(
                                             v1->Loaders.Data.Data[v39],
                                             (Scaleform::Ptr<Scaleform::Log> *)lpCriticalSection);
        if ( *Log )
          Scaleform::RefCountImpl::AddRef(*Log);
        v38 = *Log;
        if ( lpCriticalSection[0] )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)lpCriticalSection[0]);
        if ( v38 )
          break;
        if ( ++v39 >= v1->Loaders.Data.Size )
          goto LABEL_70;
      }
      Scaleform::GFx::AMP::ProfileFrame::Print(v5, (Scaleform::Log *)v38);
    }
LABEL_70:
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
    LeaveCriticalSection(&v1->LoaderLock.cs);
    if ( v38 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v38);
  }
  else
  {
    lpCriticalSection[0] = (LPCRITICAL_SECTION)580;
    v41 = (Scaleform::GFx::AMP::MessageProfileFrame *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        v1,
                                                        28,
                                                        lpCriticalSection);
    if ( v41 )
    {
      Scaleform::GFx::AMP::MessageProfileFrame::MessageProfileFrame(v41, (Scaleform::GFx::Resource *)v5);
      Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage(v1->SocketThreadMgr.pObject, v42);
    }
    else
    {
      Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage(v1->SocketThreadMgr.pObject, 0);
    }
  }
}
