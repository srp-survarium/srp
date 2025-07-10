char __usercall Scaleform::GFx::AS2::IMEManager::AcquireCandidateList@<al>(
        Scaleform::GFx::AS2::IMEManager *this@<ecx>,
        int a2@<ebp>)
{
  Scaleform::GFx::Movie *pMovie; // eax
  Scaleform::GFx::AS2::MovieRoot *pObject; // edi
  Scaleform::GFx::Movie *v5; // ecx
  Scaleform::GFx::IMEManagerBase *pimeManager; // eax
  Scaleform::RefCountVImpl *v8; // ebp
  Scaleform::RefCountVImpl *v9; // edi
  Scaleform::GFx::URLBuilder *v10; // eax
  Scaleform::RefCountVImpl *v11; // eax
  int v12; // eax
  char *v13; // eax
  const Scaleform::String *v14; // eax
  __int64 v15; // rax
  Scaleform::GFx::Movie *v16; // ecx
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v17; // eax
  int v18; // eax
  int v19; // ebp
  Scaleform::GFx::AS2::CandidateListLoader *v20; // edi
  Scaleform::GFx::Sprite *LevelMovie; // eax
  Scaleform::GFx::AS2::Environment *v22; // eax
  Scaleform::GFx::AS2::Object *v23; // eax
  Scaleform::GFx::AS2::Object *v24; // esi
  unsigned int RefCount; // eax
  Scaleform::String path; // [esp+1Ch] [ebp-150h] BYREF
  Scaleform::String parentPath; // [esp+20h] [ebp-14Ch] BYREF
  Scaleform::GFx::Value v; // [esp+24h] [ebp-148h] BYREF
  Scaleform::GFx::AS2::MovieRoot *pmovieRoot; // [esp+3Ch] [ebp-130h]
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+40h] [ebp-12Ch] BYREF
  Scaleform::GFx::Value v32; // [esp+50h] [ebp-11Ch] BYREF
  char workingDir[260]; // [esp+68h] [ebp-104h] BYREF

  pMovie = this->pMovie;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovie->pASMovieRoot.pObject;
  pmovieRoot = pObject;
  if ( !pMovie || !Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 0) )
    return 0;
  v5 = this->pMovie;
  v.pObjectInterface = 0;
  v.Type = VT_Undefined;
  if ( !(unsigned __int8)Scaleform::GFx::Movie::GetVariable(v5, &v, "_global.gfx_ime_candidate_list_state") )
  {
    if ( (v.Type & 0x40) != 0 )
    {
      v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
      v.pObjectInterface = 0;
    }
    v.Type = VT_Number;
    v.mValue.NValue = 0.0;
  }
  if ( v.mValue.NValue < 0.0 )
  {
    if ( (v.Type & 0x40) != 0 )
    {
      v.pObjectInterface->ObjectRelease(v.pObjectInterface, &v, (void *)v.mValue.IValue);
      return 0;
    }
    return 0;
  }
  if ( !Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 9999) && 1.0 != v.mValue.NValue )
  {
    pimeManager = this->pimeManager;
    if ( !pimeManager || !pimeManager->bCheckIMEExists )
    {
LABEL_36:
      v32.mValue.NValue = 1.0;
      v16 = this->pMovie;
      v32.pObjectInterface = 0;
      v32.Type = VT_Number;
      Scaleform::GFx::Movie::SetVariable(v16, "_global.gfx_ime_candidate_list_state", &v32, SV_Sticky);
      v17 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x6Cu);
      if ( v17 )
      {
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
          v17,
          9999,
          &this->CandidateSwfPath,
          LM_None,
          0,
          1);
        v19 = v18;
      }
      else
      {
        v19 = 0;
      }
      v20 = (Scaleform::GFx::AS2::CandidateListLoader *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::operator new(0x3Cu);
      if ( v20 )
      {
        LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pmovieRoot, 0);
        v22 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&LevelMovie->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                               + LevelMovie->AvmObjOffset)
                                                                             + 124))((int)LevelMovie + 4 * LevelMovie->AvmObjOffset);
        Scaleform::GFx::AS2::`anonymous namespace'::CandidateListLoader::CandidateListLoader(
          v20,
          (Scaleform::GFx::AS2::LocalFrame **)v19,
          (Scaleform::GFx::Resource *)this,
          v22);
        v24 = v23;
      }
      else
      {
        v24 = 0;
      }
      Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)(v19 + 36), v24);
      Scaleform::GFx::AS2::MovieRoot::AddMovieLoadQueueEntry(
        pmovieRoot,
        0,
        (int)v24,
        (Scaleform::GFx::LoadQueueEntry *)v19);
      if ( v24 )
      {
        RefCount = v24->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v24->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
        }
      }
      Scaleform::GFx::Value::~Value(&v32);
      goto LABEL_29;
    }
    v8 = (Scaleform::RefCountVImpl *)pimeManager->pLoader->GetStateAddRef(pimeManager->pLoader, State_FileOpener);
    v9 = (Scaleform::RefCountVImpl *)this->pimeManager->pLoader->GetStateAddRef(this->pimeManager->pLoader, 10);
    if ( !v9 )
    {
      v10 = (Scaleform::GFx::URLBuilder *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(0xCu);
      if ( v10 )
        Scaleform::GFx::URLBuilder::URLBuilder(v10);
      else
        v11 = 0;
      v9 = v11;
    }
    if ( !v8 )
    {
LABEL_32:
      if ( v9 )
        Scaleform::RefCountImpl::Release(v9);
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
      goto LABEL_36;
    }
    Scaleform::String::String(&parentPath);
    v12 = ((int (__thiscall *)(Scaleform::GFx::Movie *, int))this->pMovie->GetMovieDef)(this->pMovie, a2);
    v13 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 48))(v12);
    Scaleform::String::operator=((Scaleform::String *)&v, v13);
    Scaleform::GFx::URLBuilder::ExtractFilePath((Scaleform::String *)&v);
    if ( Scaleform::GFx::URLBuilder::IsPathAbsolute((const char *)(((int)v.pObjectInterface & 0xFFFFFFFC) + 8)) )
    {
      Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(
        (Scaleform::GFx::URLBuilder::LocationInfo *)&loc.FileName,
        File_Regular,
        &this->CandidateSwfPath,
        (const Scaleform::String *)&v);
      Scaleform::String::String(&parentPath);
      if ( !v9 )
      {
        Scaleform::GFx::URLBuilder::DefaultBuildURL(
          &parentPath,
          (const Scaleform::GFx::URLBuilder::LocationInfo *)&loc.FileName);
LABEL_25:
        v15 = ((__int64 (__thiscall *)(Scaleform::RefCountVImpl *, unsigned int))v8->Release)(
                v8,
                (parentPath.HeapTypeBits & 0xFFFFFFFC) + 8);
        if ( (HIDWORD(v15) & (unsigned int)v15) == 0xFFFFFFFF )
        {
          Scaleform::String::~String(&path);
          Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc);
          Scaleform::String::~String(&parentPath);
          if ( v9 )
            Scaleform::RefCountImpl::Release(v9);
          Scaleform::RefCountImpl::Release(v8);
LABEL_29:
          Scaleform::GFx::Value::~Value(&v);
          return 0;
        }
        Scaleform::String::~String(&path);
        Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc);
        Scaleform::String::~String(&parentPath);
        goto LABEL_32;
      }
    }
    else
    {
      GetCurrentDirectoryA(0x104u, &workingDir[4]);
      Scaleform::String::String((Scaleform::String *)&v32, &workingDir[4]);
      Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(
        (Scaleform::GFx::URLBuilder::LocationInfo *)&loc.FileName,
        File_Regular,
        &this->CandidateSwfPath,
        v14);
      Scaleform::String::~String((Scaleform::String *)&v32);
      Scaleform::String::String(&parentPath);
      if ( !v9 )
        goto LABEL_25;
    }
    ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::String *, Scaleform::String *))v9->AddRef)(
      v9,
      &parentPath,
      &loc.FileName);
    goto LABEL_25;
  }
  Scaleform::GFx::Value::~Value(&v);
  return 1;
}
