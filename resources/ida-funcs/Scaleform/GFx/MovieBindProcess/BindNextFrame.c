Scaleform::GFx::MovieDefImpl::BindStateType __thiscall Scaleform::GFx::MovieBindProcess::BindNextFrame(
        Scaleform::GFx::MovieBindProcess *this)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // eax
  Scaleform::GFx::MovieDefImpl::BindStateType result; // eax
  Scaleform::GFx::FrameBindData *pFrameBindData; // eax
  Scaleform::GFx::FrameBindData *volatile Value; // ebx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // edi
  Scaleform::Mutex *p_mMutex; // ebp
  Scaleform::GFx::FrameBindData *v8; // eax
  Scaleform::GFx::FrameBindData *v9; // eax
  Scaleform::GFx::LoadStates *v10; // eax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v11; // ecx
  Scaleform::GFx::MovieDefImpl *MovieDefImplAddRef; // eax
  Scaleform::GFx::Resource *v13; // eax
  Scaleform::RefCountVImpl *v14; // edi
  const Scaleform::String *p_SourceUrl; // ebx
  const __m128i *DefaultFontLibName; // eax
  const Scaleform::String *v17; // eax
  void *v18; // edi
  void *v19; // edi
  Scaleform::GFx::LoaderImpl::LoadStackItem *pLoadStack; // eax
  unsigned int v21; // ebp
  unsigned int v22; // ecx
  Scaleform::GFx::MovieDefImpl *v23; // edi
  Scaleform::GFx::LoaderImpl::LoadStackItem *v24; // eax
  Scaleform::GFx::LoaderImpl::LoadStackItem *pNext; // ecx
  unsigned int FileAttributes; // ebp
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v27; // eax
  Scaleform::GFx::ImportVisitor *v28; // ebx
  Scaleform::GFx::MovieDefImpl *v29; // ebp
  Scaleform::GFx::MovieDefImpl::BindTaskData *v30; // eax
  Scaleform::GFx::ResourceDataNode *pResourceData; // edi
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // ebp
  Scaleform::GFx::MovieDefImpl::BindTaskData *v33; // eax
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v34; // eax
  Scaleform::GFx::Resource *pFontData; // edx
  volatile bool Frozen; // cl
  volatile unsigned int pLib; // eax
  Scaleform::GFx::ResourceBindData *v38; // edi
  Scaleform::GFx::FontResource *v39; // ecx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v40; // ecx
  Scaleform::GFx::LoadUpdateSync *v41; // edi
  Scaleform::RefCountVImpl *v42; // ecx
  Scaleform::GFx::FontResource *v43; // ebp
  unsigned int v44; // edi
  Scaleform::GFx::AS3::Instances::fl::Object **v45; // edi
  bool v46; // di
  Scaleform::GFx::LogState *v47; // eax
  Scaleform::Log *GlobalLog; // eax
  Scaleform::GFx::Resource *v49; // ecx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v50; // edi
  int v51; // ebx
  Scaleform::GFx::LoadUpdateSync *v52; // eax
  Scaleform::Mutex *v53; // ebp
  Scaleform::WaitCondition *p_WC; // ecx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v55; // edi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v56; // ebx
  unsigned int v57; // edi
  Scaleform::GFx::LoadUpdateSync *v58; // eax
  Scaleform::Mutex *v59; // ebp
  Scaleform::WaitCondition *v60; // ecx
  Scaleform::GFx::ProgressHandler *v61; // ebx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v62; // edi
  _DWORD *v63; // ecx
  const Scaleform::String *v64; // ebp
  volatile unsigned int BindingFrame; // eax
  volatile unsigned int BytesLoaded; // edi
  void (__thiscall *ProgressUpdate)(Scaleform::GFx::ProgressHandler *, const Scaleform::GFx::ProgressHandler::Info *); // edx
  void *v68; // edi
  int v69; // ebx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v70; // eax
  Scaleform::GFx::LoadUpdateSync *v71; // edi
  Scaleform::RefCountVImpl *v72; // ecx
  bool v73; // [esp+17h] [ebp-85h]
  int v74; // [esp+18h] [ebp-84h]
  Scaleform::GFx::LoadStates *v75; // [esp+1Ch] [ebp-80h]
  unsigned int v76; // [esp+20h] [ebp-7Ch]
  int v77; // [esp+20h] [ebp-7Ch]
  unsigned int v78; // [esp+20h] [ebp-7Ch]
  Scaleform::GFx::Resource *v79; // [esp+24h] [ebp-78h]
  Scaleform::GFx::Resource *v80; // [esp+24h] [ebp-78h]
  Scaleform::GFx::FrameBindData *volatile v81; // [esp+28h] [ebp-74h]
  Scaleform::RefCountVImpl *v82; // [esp+2Ch] [ebp-70h]
  Scaleform::MemoryHeap *pHeap; // [esp+2Ch] [ebp-70h]
  Scaleform::GFx::ImportData *pimport; // [esp+30h] [ebp-6Ch]
  Scaleform::GFx::LoadStates *pls; // [esp+34h] [ebp-68h]
  Scaleform::GFx::ResourceBinding *v86; // [esp+38h] [ebp-64h]
  Scaleform::GFx::ResourceBinding *v87; // [esp+38h] [ebp-64h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+3Ch] [ebp-60h] BYREF
  Scaleform::GFx::ResourceBindData bd; // [esp+48h] [ebp-54h] BYREF
  int LoadFlags; // [esp+50h] [ebp-4Ch]
  Scaleform::GFx::ResourceBindData pdata; // [esp+54h] [ebp-48h] BYREF
  bool recursive[4]; // [esp+5Ch] [ebp-40h]
  Scaleform::String v93; // [esp+60h] [ebp-3Ch] BYREF
  _DWORD v94[2]; // [esp+64h] [ebp-38h] BYREF
  Scaleform::String v95; // [esp+6Ch] [ebp-30h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+70h] [ebp-2Ch] BYREF
  Scaleform::String v97; // [esp+7Ch] [ebp-20h] BYREF
  volatile unsigned int v98; // [esp+80h] [ebp-1Ch]
  Scaleform::GFx::ResourceBinding *v99; // [esp+84h] [ebp-18h]
  int v100; // [esp+88h] [ebp-14h]
  int v101; // [esp+8Ch] [ebp-10h]
  Scaleform::GFx::URLBuilder::LocationInfo v102; // [esp+90h] [ebp-Ch] BYREF

  pObject = this->pBindData.pObject;
  v74 = 0;
  if ( !pObject )
    return 3;
  result = pObject->BindState & 0xF;
  if ( result != BS_InProgress )
  {
    if ( result )
      return result;
    Scaleform::GFx::MovieBindProcess::SetBindState(this, this->pBindData.pObject->BindState & 0xFFFFFFF0 | 1);
  }
  pFrameBindData = this->pFrameBindData;
  if ( pFrameBindData )
    Value = pFrameBindData->pNextFrame.Value;
  else
    Value = this->pDataDef->pData.pObject->BindData.pFrameData.Value;
  v81 = Value;
  if ( !Value )
  {
    v6 = this->pDataDef->pData.pObject;
    p_mMutex = &v6->pFrameUpdate.pObject->mMutex;
    Scaleform::Mutex::DoLock(p_mMutex);
    v8 = this->pFrameBindData;
    if ( v8 )
      Value = v8->pNextFrame.Value;
    else
      Value = this->pDataDef->pData.pObject->BindData.pFrameData.Value;
    v81 = Value;
    if ( !Value )
    {
      do
      {
        if ( v6->LoadState != LS_LoadingFrames || this->pBindData.pObject->BindingCanceled )
          break;
        Scaleform::WaitCondition::Wait(&v6->pFrameUpdate.pObject->WC, &v6->pFrameUpdate.pObject->mMutex, 0xFFFFFFFF);
        v9 = this->pFrameBindData;
        Value = v9 ? v9->pNextFrame.Value : this->pDataDef->pData.pObject->BindData.pFrameData.Value;
      }
      while ( !Value );
      v81 = Value;
    }
    if ( v6->LoadState == LS_LoadCanceled )
      this->pBindData.pObject->BindingCanceled = 1;
    Scaleform::Mutex::Unlock(p_mMutex);
    if ( !Value )
      goto LABEL_156;
  }
  if ( this->pBindData.pObject->BindingCanceled )
  {
LABEL_156:
    Scaleform::GFx::MovieBindProcess::FinishBinding(this);
    v69 = !this->pBindData.pObject->BindingCanceled + 3;
    Scaleform::GFx::MovieBindProcess::SetBindState(this, v69 | this->pBindData.pObject->BindState & 0xFFFFFFF0);
    v70 = this->pBindData.pObject;
    v71 = v70->pBindUpdate.pObject;
    if ( v71 )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v70->pBindUpdate.pObject);
    v72 = (Scaleform::RefCountVImpl *)this->pBindData.pObject;
    if ( v72 )
      Scaleform::RefCountImpl::Release(v72);
    this->pBindData.pObject = 0;
    Scaleform::Mutex::DoLock(&v71->mMutex);
    v71->LoadFinished = 1;
    Scaleform::WaitCondition::NotifyAll(&v71->WC);
    Scaleform::Mutex::Unlock(&v71->mMutex);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v71);
    return v69;
  }
  v10 = this->pLoadStates.pObject;
  v11 = this->pBindData.pObject;
  this->pFrameBindData = Value;
  v75 = v10;
  LoadFlags = v11->LoadFlags;
  if ( ((unsigned int)&loc_100000 & LoadFlags) == 0 )
  {
    pimport = Value->pImportData;
    v82 = 0;
    MovieDefImplAddRef = Scaleform::GFx::MovieDefImpl::BindTaskData::GetMovieDefImplAddRef(v11);
    v79 = MovieDefImplAddRef;
    if ( MovieDefImplAddRef )
    {
      v13 = (Scaleform::GFx::Resource *)MovieDefImplAddRef->GetStateAddRef(
                                          &MovieDefImplAddRef->Scaleform::GFx::StateBag,
                                          State_FontLib);
      v14 = (Scaleform::RefCountVImpl *)v13;
      if ( v13 )
        Scaleform::RefCountImpl::AddRef(v13);
      v82 = v14;
      if ( v14 )
        Scaleform::RefCountImpl::Release(v14);
    }
    v76 = 0;
    if ( Value->ImportCount )
    {
      do
      {
        p_SourceUrl = &pimport->SourceUrl;
        v73 = 1;
        if ( !pimport->Imports.Data.Size
          || !Scaleform::String::operator==(&pimport->Imports.Data.Data->SymbolName, "$IMECandidateListFont") )
        {
          if ( !v82
            || (!v79
             || (DefaultFontLibName = (const __m128i *)Scaleform::GFx::StateBag::GetDefaultFontLibName((Scaleform::GFx::StateBag *)&v79[1]),
                 Scaleform::String::String(&v93, DefaultFontLibName),
                 v74 |= 1u,
                 !Scaleform::GFx::MatchFileNames(p_SourceUrl, &v93)))
            && (v74 |= 2u,
                Scaleform::String::String(&v95, (const __m128i *)"gfxfontlib.swf"),
                !Scaleform::GFx::MatchFileNames(p_SourceUrl, v17)) )
          {
            v73 = 0;
          }
        }
        if ( (v74 & 2) != 0 )
        {
          v74 &= ~2u;
          v18 = (void *)(v95.HeapTypeBits & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd((volatile LONG *)((v95.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
        }
        if ( (v74 & 1) != 0 )
        {
          v74 &= ~1u;
          v19 = (void *)(v93.HeapTypeBits & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd((volatile LONG *)((v93.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
        }
        if ( v73 )
        {
          Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImportThroughFontLib(this->pBindData.pObject, pimport);
        }
        else
        {
          pls = Scaleform::GFx::LoadStates::CloneForImport(v75);
          v94[0] = this->pBindData.pObject->pDefImpl_Unsafe;
          pLoadStack = this->pLoadStack;
          v21 = LoadFlags | 1;
          v94[1] = 0;
          if ( pLoadStack )
          {
            for ( ; pLoadStack->pNext; pLoadStack = pLoadStack->pNext )
              ;
            pLoadStack->pNext = (Scaleform::GFx::LoaderImpl::LoadStackItem *)v94;
          }
          else
          {
            this->pLoadStack = (Scaleform::GFx::LoaderImpl::LoadStackItem *)v94;
          }
          if ( !this->Stripped
            || (v22 = *(_DWORD *)(p_SourceUrl->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF, v22 <= 4)
            || Scaleform::String::CompareNoCase((char *)((p_SourceUrl->HeapTypeBits & 0xFFFFFFFC) + v22 + 4), ".swf")
            || (Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(
                  &loc,
                  File_Import,
                  p_SourceUrl,
                  &v75->RelativePath),
                Scaleform::String::Clear(&loc.FileName),
                Scaleform::String::AppendString(
                  &loc.FileName,
                  (const __m128i *)((p_SourceUrl->HeapTypeBits & 0xFFFFFFFC) + 8),
                  (*(_DWORD *)(p_SourceUrl->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) - 4),
                Scaleform::String::AppendString(&loc.FileName, (const __m128i *)".gfx", 0xFFFFFFFF),
                v23 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(pls, &loc, v21, this->pLoadStack, 0),
                Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc),
                !v23) )
          {
            Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(&v102, File_Import, p_SourceUrl, &v75->RelativePath);
            v23 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(pls, &v102, v21, this->pLoadStack, 0);
            Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&v102);
          }
          v24 = this->pLoadStack;
          if ( v24 == (Scaleform::GFx::LoaderImpl::LoadStackItem *)v94 )
          {
            this->pLoadStack = 0;
          }
          else if ( v24->pNext )
          {
            while ( 1 )
            {
              pNext = v24->pNext;
              if ( pNext == (Scaleform::GFx::LoaderImpl::LoadStackItem *)v94 )
                break;
              v24 = v24->pNext;
              if ( !pNext->pNext )
                goto LABEL_64;
            }
            v24->pNext = pNext->pNext;
          }
LABEL_64:
          if ( !v23 )
            goto LABEL_90;
          FileAttributes = this->pDataDef->pData.pObject->FileAttributes;
          if ( (((unsigned __int8)FileAttributes ^ (unsigned __int8)v23->GetFileAttributesA(v23)) & 8) != 0 )
          {
            Scaleform::GFx::Resource::Release(v23);
            v34 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v75->pLog.pObject;
            if ( v34 )
              Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
                v34 + 3,
                "ActionScript version mismatched between main and import '%s' files",
                (const char *)((p_SourceUrl->HeapTypeBits & 0xFFFFFFFC) + 8));
LABEL_90:
            Scaleform::GFx::MovieBindProcess::FinishBinding(this);
            Scaleform::GFx::MovieBindProcess::SetBindState(this, this->pBindData.pObject->BindState & 0xFFFFFFF0 | 4);
            if ( pls )
              Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pls);
            if ( v79 )
              Scaleform::GFx::Resource::Release(v79);
            if ( v82 )
              Scaleform::RefCountImpl::Release(v82);
            return 4;
          }
          recursive[0] = v23->pBindData.pObject == this->pBindData.pObject;
          if ( recursive[0] )
          {
            v27 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v75->pLog.pObject;
            if ( v27 )
              Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
                v27 + 3,
                "Self recursive import detected in '%s'",
                (const char *)((p_SourceUrl->HeapTypeBits & 0xFFFFFFFC) + 8));
          }
          Scaleform::GFx::MovieDefImpl::BindTaskData::ResolveImport(
            this->pBindData.pObject,
            pimport,
            v23,
            v75,
            recursive[0]);
          v28 = v75->pBindStates.pObject->pImportVisitor.pObject;
          if ( v28 )
          {
            v29 = Scaleform::GFx::MovieDefImpl::BindTaskData::GetMovieDefImplAddRef(this->pBindData.pObject);
            if ( v29 )
            {
              v28->Visit(
                &v28->Scaleform::GFx::MovieDef::ImportVisitor,
                v29,
                v23,
                (const char *)((pimport->SourceUrl.HeapTypeBits & 0xFFFFFFFC) + 8));
              Scaleform::GFx::Resource::Release(v29);
            }
          }
          Scaleform::GFx::Resource::Release(v23);
          if ( pls )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pls);
        }
        Value = v81;
        ++v76;
        pimport = pimport->pNext.Value;
      }
      while ( v76 < v81->ImportCount );
    }
    if ( v79 )
      Scaleform::GFx::Resource::Release(v79);
    if ( v82 )
      Scaleform::RefCountImpl::Release(v82);
  }
  v30 = this->pBindData.pObject;
  pResourceData = Value->pResourceData;
  p_ResourceBinding = &v30->ResourceBinding;
  v86 = &v30->ResourceBinding;
  pHeap = v30->pHeap;
  v77 = 0;
  if ( !Value->ResourceCount )
  {
LABEL_101:
    if ( Value->FontCount )
    {
      pFontData = (Scaleform::GFx::Resource *)Value->pFontData;
      memset(&pheapAddr, 0, sizeof(pheapAddr));
      v80 = pFontData;
      v78 = 0;
      do
      {
        Frozen = v86->Frozen;
        pLib = (volatile unsigned int)v80->pLib;
        pdata.pResource.pObject = 0;
        pdata.pBinding = 0;
        if ( Frozen && pLib < v86->ResourceCount )
        {
          v38 = &v86->pResources[pLib];
          if ( v38->pResource.pObject )
          {
            Scaleform::RefCountImpl::AddRef(v38->pResource.pObject);
            if ( pdata.pResource.pObject )
              Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
          }
          v39 = (Scaleform::GFx::FontResource *)v38->pResource.pObject;
          pdata = *v38;
        }
        else
        {
          Scaleform::GFx::ResourceBinding::GetResourceData_Locked(v86, &pdata, pLib);
          v39 = (Scaleform::GFx::FontResource *)pdata.pResource.pObject;
        }
        if ( v39 )
        {
          v43 = v39;
          Scaleform::GFx::FontResource::ResolveTextureGlyphs(v39);
          v44 = pheapAddr.Size + 1;
          if ( pheapAddr.Size + 1 >= pheapAddr.Size )
          {
            if ( v44 >= pheapAddr.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                &pheapAddr,
                &pheapAddr,
                v44 + (v44 >> 2));
          }
          else if ( v44 < pheapAddr.Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &pheapAddr,
              &pheapAddr,
              pheapAddr.Size + 1);
          }
          pheapAddr.Size = v44;
          v45 = &pheapAddr.Data[v44 - 1];
          if ( v45 )
            *v45 = (Scaleform::GFx::AS3::Instances::fl::Object *)v43;
          if ( pdata.pResource.pObject )
            Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
        }
        ++v78;
        v80 = (Scaleform::GFx::Resource *)v80[1].__vftable;
      }
      while ( v78 < Value->FontCount );
      if ( pheapAddr.Size && v75->pBindStates.pObject->pFontPackParams.pObject )
      {
        v46 = v75->ThreadedLoading || v75->pTaskManager.pObject;
        v47 = v75->pLog.pObject;
        if ( v47 )
        {
          GlobalLog = v47->pLog.pObject;
          if ( !GlobalLog )
            GlobalLog = Scaleform::Log::GetGlobalLog();
          v49 = (Scaleform::GFx::Resource *)GlobalLog;
        }
        else
        {
          v49 = 0;
        }
        Scaleform::GFx::GFx_GenerateFontBitmaps(
          v75->pBindStates.pObject->pFontPackParams.pObject,
          (const Scaleform::Array<Scaleform::GFx::FontResource *,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
          (Scaleform::GFx::Resource *)v75->pBindStates.pObject->pImageCreator.pObject,
          v49,
          &this->GlyphTextureIdGen,
          pHeap,
          v46);
      }
      if ( pheapAddr.Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
    }
    this->pBindData.pObject->BytesLoaded = Value->BytesLoaded;
    InterlockedExchange(
      (volatile LONG *)&this->pBindData.pObject->BindingFrame,
      this->pBindData.pObject->BindingFrame + 1);
    if ( this->pBindData.pObject->BindingFrame == 1 )
    {
      v50 = this->pBindData.pObject;
      v51 = v50->BindState | 0x100;
      if ( v50 )
      {
        v52 = v50->pBindUpdate.pObject;
        if ( v52 )
        {
          v53 = &v52->mMutex;
          Scaleform::Mutex::DoLock(&v52->mMutex);
          p_WC = &v50->pBindUpdate.pObject->WC;
          v50->BindState = v51;
          Scaleform::WaitCondition::NotifyAll(p_WC);
          Scaleform::Mutex::Unlock(v53);
        }
        else
        {
          v50->BindState = v51;
        }
      }
    }
    v55 = this->pBindData.pObject;
    if ( v55->BindingFrame == this->pDataDef->GetFrameCount(this->pDataDef) )
    {
      this->pBindData.pObject->BytesLoaded = this->pDataDef->pData.pObject->Header.FileLength;
      Scaleform::GFx::MovieBindProcess::FinishBinding(this);
      v56 = this->pBindData.pObject;
      v57 = v56->BindState & 0xFFFFFDF0 | 0x202;
      if ( v56 )
      {
        v58 = v56->pBindUpdate.pObject;
        if ( v58 )
        {
          v59 = &v58->mMutex;
          Scaleform::Mutex::DoLock(&v58->mMutex);
          v60 = &v56->pBindUpdate.pObject->WC;
          v56->BindState = v57;
          Scaleform::WaitCondition::NotifyAll(v60);
          Scaleform::Mutex::Unlock(v59);
        }
        else
        {
          v56->BindState = v57;
        }
      }
    }
    v61 = v75->pProgressHandler.pObject;
    if ( v61 )
    {
      v62 = this->pBindData.pObject;
      v63 = &v62->pDataDef.pObject->__vftable;
      v64 = (const Scaleform::String *)v63[8];
      v87 = (Scaleform::GFx::ResourceBinding *)v64[12].pData;
      LoadFlags = (*(int (__thiscall **)(_DWORD *))(*v63 + 40))(v63);
      BindingFrame = v62->BindingFrame;
      BytesLoaded = v62->BytesLoaded;
      *(_DWORD *)recursive = BindingFrame;
      Scaleform::String::String(&v97, v64 + 9);
      v100 = *(_DWORD *)recursive;
      ProgressUpdate = v61->ProgressUpdate;
      v101 = LoadFlags;
      v99 = v87;
      v98 = BytesLoaded;
      ProgressUpdate(v61, (const Scaleform::GFx::ProgressHandler::Info *)&v97);
      v68 = (void *)(v97.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v97.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v68);
    }
    return this->pBindData.pObject->BindState & 0xF;
  }
  while ( !pResourceData->Data.pInterface )
  {
LABEL_100:
    pResourceData = pResourceData->pNext.Value;
    if ( ++v77 >= Value->ResourceCount )
      goto LABEL_101;
  }
  v33 = this->pBindData.pObject;
  bd.pBinding = p_ResourceBinding;
  bd.pResource.pObject = 0;
  if ( !v33->BindingCanceled
    && pResourceData->Data.pInterface
    && pResourceData->Data.pInterface->CreateResource(
         pResourceData->Data.pInterface,
         pResourceData->Data.hData,
         &bd,
         v75,
         pHeap) )
  {
    if ( this->pImagePacker.pObject
      && (bd.pResource.pObject->GetResourceTypeCode(bd.pResource.pObject) & 0xFF00) == 0x100
      && (unsigned __int8)bd.pResource.pObject->GetResourceTypeCode(bd.pResource.pObject) == 1 )
    {
      this->pImagePacker.pObject->AddResource(
        this->pImagePacker.pObject,
        pResourceData,
        (Scaleform::GFx::ImageResource *)bd.pResource.pObject);
    }
    goto LABEL_98;
  }
  if ( !this->pBindData.pObject->BindingCanceled )
  {
LABEL_98:
    Scaleform::GFx::ResourceBinding::SetBindData(
      p_ResourceBinding,
      (int)p_ResourceBinding,
      pResourceData->BindIndex,
      &bd);
    if ( bd.pResource.pObject )
      Scaleform::GFx::Resource::Release(bd.pResource.pObject);
    goto LABEL_100;
  }
  Scaleform::GFx::MovieBindProcess::FinishBinding(this);
  Scaleform::GFx::MovieBindProcess::SetBindState(this, this->pBindData.pObject->BindState & 0xFFFFFFF0 | 3);
  v40 = this->pBindData.pObject;
  v41 = v40->pBindUpdate.pObject;
  if ( v41 )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v40->pBindUpdate.pObject);
  v42 = (Scaleform::RefCountVImpl *)this->pBindData.pObject;
  if ( v42 )
    Scaleform::RefCountImpl::Release(v42);
  this->pBindData.pObject = 0;
  Scaleform::Mutex::DoLock(&v41->mMutex);
  v41->LoadFinished = 1;
  Scaleform::WaitCondition::NotifyAll(&v41->WC);
  Scaleform::Mutex::Unlock(&v41->mMutex);
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v41);
  if ( bd.pResource.pObject )
    Scaleform::GFx::Resource::Release(bd.pResource.pObject);
  return 3;
}
