char __thiscall Scaleform::GFx::AS3::IMEManager::AcquireCandidateList(Scaleform::GFx::AS3::IMEManager *this)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // ebx
  Scaleform::GFx::IMEManagerBase *pimeManager; // eax
  Scaleform::RefCountVImpl *v4; // ebp
  Scaleform::RefCountVImpl *v5; // edi
  Scaleform::GFx::URLBuilder *v6; // eax
  Scaleform::RefCountVImpl *v7; // eax
  Scaleform::GFx::MovieDef *v8; // eax
  char *v9; // eax
  __int64 v10; // rax
  const Scaleform::String *v12; // eax
  Scaleform::GFx::AS3::VM *v13; // edi
  Scaleform::GFx::AS3::Instances::fl_display::Loader *VInt; // ebp
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v15; // edi
  Scaleform::GFx::AS3::LoadQueueEntry *v16; // eax
  Scaleform::GFx::AS3::LoadQueueEntry *v17; // eax
  Scaleform::GFx::AS3::LoadQueueEntry *v18; // edi
  Scaleform::GFx::AS3::NotifyLoadInitCandidateList *v19; // eax
  Scaleform::GFx::Resource *v20; // eax
  Scaleform::GFx::Resource *v21; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::String path; // [esp+1Ch] [ebp-154h] BYREF
  Scaleform::GFx::AS3::CheckResult v24[4]; // [esp+20h] [ebp-150h] BYREF
  Scaleform::String parentPath; // [esp+24h] [ebp-14Ch] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+28h] [ebp-148h] BYREF
  Scaleform::GFx::AS3::Value result2; // [esp+38h] [ebp-138h] BYREF
  Scaleform::GFx::AS3::Value tmp; // [esp+48h] [ebp-128h] BYREF
  Scaleform::GFx::ASString imeFile; // [esp+58h] [ebp-118h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+5Ch] [ebp-114h] BYREF
  Scaleform::String v31; // [esp+68h] [ebp-108h] BYREF
  char workingDir[260]; // [esp+6Ch] [ebp-104h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovie->pASMovieRoot.pObject;
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0;
  result2.Flags = 0;
  result2.Bonus.pWeakProxy = 0;
  tmp.Flags = 0;
  tmp.Bonus.pWeakProxy = 0;
  if ( this->CandidateListState )
    return 1;
  pimeManager = this->pimeManager;
  if ( !pimeManager || !pimeManager->bCheckIMEExists )
    goto LABEL_26;
  v4 = (Scaleform::RefCountVImpl *)pimeManager->pLoader->GetStateAddRef(pimeManager->pLoader, State_FileOpener);
  v5 = (Scaleform::RefCountVImpl *)this->pimeManager->pLoader->GetStateAddRef(this->pimeManager->pLoader, 10);
  if ( !v5 )
  {
    v6 = (Scaleform::GFx::URLBuilder *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12, 0);
    if ( v6 )
      Scaleform::GFx::URLBuilder::URLBuilder(v6);
    else
      v7 = 0;
    v5 = v7;
  }
  if ( v4 )
  {
    Scaleform::String::String(&parentPath);
    v8 = this->pMovie->GetMovieDef(this->pMovie);
    v9 = (char *)v8->GetFileURL(v8);
    Scaleform::String::operator=(&parentPath, v9);
    Scaleform::GFx::URLBuilder::ExtractFilePath(&parentPath);
    if ( Scaleform::GFx::URLBuilder::IsPathAbsolute((const char *)((parentPath.HeapTypeBits & 0xFFFFFFFC) + 8)) )
    {
      Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(&loc, File_Regular, &this->CandidateSwfPath, &parentPath);
      Scaleform::String::String(&path);
      if ( !v5 )
      {
        Scaleform::GFx::URLBuilder::DefaultBuildURL(&path, &loc);
        goto LABEL_14;
      }
    }
    else
    {
      GetCurrentDirectoryA(0x104u, workingDir);
      Scaleform::String::String(&v31, workingDir);
      Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(&loc, File_Regular, &this->CandidateSwfPath, v12);
      Scaleform::String::~String(&v31);
      Scaleform::String::String(&path);
      if ( !v5 )
        goto LABEL_14;
    }
    ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::String *, Scaleform::GFx::URLBuilder::LocationInfo *))v5->AddRef)(
      v5,
      &path,
      &loc);
LABEL_14:
    v10 = ((__int64 (__thiscall *)(Scaleform::RefCountVImpl *, unsigned int))v4->Release)(
            v4,
            (path.HeapTypeBits & 0xFFFFFFFC) + 8);
    if ( (HIDWORD(v10) & (unsigned int)v10) == 0xFFFFFFFF )
    {
      Scaleform::String::~String(&path);
      Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc);
      Scaleform::String::~String(&parentPath);
      if ( v5 )
        Scaleform::RefCountImpl::Release(v5);
      Scaleform::RefCountImpl::Release(v4);
      Scaleform::GFx::AS3::Value::~Value(&tmp);
      Scaleform::GFx::AS3::Value::~Value(&result2);
      Scaleform::GFx::AS3::Value::~Value(&result);
      return 0;
    }
    Scaleform::String::~String(&path);
    Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc);
    Scaleform::String::~String(&parentPath);
  }
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
LABEL_26:
  this->CandidateListState = 1;
  v13 = pObject->pAVM.pObject;
  if ( Scaleform::GFx::AS3::VM::ConstructBuiltinValue(v13, &v24[3], &result, "flash.display.Loader", 0, 0)->Result )
  {
    if ( !Scaleform::GFx::AS3::VM::ConstructBuiltinValue(v13, &v24[3], &result2, "flash.net.URLRequest", 0, 0)->Result )
    {
      if ( (tmp.Flags & 0x1F) <= 9 )
        goto LABEL_31;
      if ( (tmp.Flags & 0x200) != 0 )
        goto LABEL_29;
      goto LABEL_30;
    }
    VInt = (Scaleform::GFx::AS3::Instances::fl_display::Loader *)result.value.VS._1.VInt;
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)result.value.VS._1.VInt + 40))(0);
    v15 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)result2.value.VS._1.VInt;
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
      &pObject->BuiltinsMgr,
      &imeFile,
      &this->CandidateSwfPath);
    Scaleform::GFx::AS3::Instances::fl_net::URLRequest::urlSet(v15, &tmp, &imeFile);
    v16 = (Scaleform::GFx::AS3::LoadQueueEntry *)pObject->pMovieImpl->pHeap->Alloc(pObject->pMovieImpl->pHeap, 56u, 0);
    if ( v16 )
    {
      Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(v16, v15, VInt, LM_None, 0);
      v18 = v17;
    }
    else
    {
      v18 = 0;
    }
    v19 = (Scaleform::GFx::AS3::NotifyLoadInitCandidateList *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                20,
                                                                0);
    if ( v19 )
    {
      Scaleform::GFx::AS3::NotifyLoadInitCandidateList::NotifyLoadInitCandidateList(
        v19,
        pObject,
        VInt,
        (Scaleform::GFx::Resource *)this);
      v21 = v20;
    }
    else
    {
      v21 = 0;
    }
    if ( v21 )
      Scaleform::RefCountImpl::AddRef(v21);
    Scaleform::GFx::AS3::LoadQueueEntry::SetNotifyLoadInitCInterface(
      v18,
      (Scaleform::Ptr<Scaleform::GFx::AS3::NotifyLoadInitC>)v21);
    Scaleform::GFx::MovieImpl::AddLoadQueueEntry(pObject->pMovieImpl, v18);
    if ( v21 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v21);
    pNode = imeFile.pNode;
    --imeFile.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( (tmp.Flags & 0x1F) > 9 )
    {
      if ( (tmp.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&tmp);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&tmp);
    }
    if ( (result2.Flags & 0x1F) > 9 )
    {
      if ( (result2.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result2);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result2);
    }
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
        return 1;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
    return 1;
  }
  if ( (tmp.Flags & 0x1F) > 9 )
  {
    if ( (tmp.Flags & 0x200) != 0 )
    {
LABEL_29:
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&tmp);
      goto LABEL_31;
    }
LABEL_30:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&tmp);
  }
LABEL_31:
  if ( (result2.Flags & 0x1F) > 9 )
  {
    if ( (result2.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result2);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result2);
  }
  if ( (result.Flags & 0x1F) <= 9 )
    return 0;
  if ( (result.Flags & 0x200) != 0 )
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
  else
    Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
  return 0;
}
