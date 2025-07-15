char __thiscall Scaleform::GFx::AS2ValueObjectInterface::AttachMovie(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value *pmc,
        const __m128i *symbolName,
        __m128i *instanceName,
        int depth,
        const Scaleform::GFx::MemberValueSet *initArgs)
{
  Scaleform::GFx::AMP::ViewStats *v8; // eax
  Scaleform::GFx::InteractiveObject *v9; // ebx
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  int v11; // ecx
  Scaleform::GFx::AS2::Environment *v12; // edi
  Scaleform::GFx::MovieImpl *v13; // esi
  Scaleform::GFx::MovieDefImpl *v14; // eax
  void *v15; // esi
  Scaleform::GFx::CharacterHandle *CharacterHandle; // eax
  Scaleform::AmpStats *Stats; // edi
  bool v18; // zf
  Scaleform::GFx::CharacterHandle *v19; // eax
  int v21; // eax
  int LargestDepthInUse; // eax
  const Scaleform::GFx::MemberValueSet *v23; // esi
  char *v24; // esi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::AS2::MovieRoot *v26; // ecx
  void (__thiscall *ExecuteForEachChild_GC)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC); // edx
  Scaleform::GFx::ASStringNode *v28; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v29; // esi
  int v30; // eax
  Scaleform::GFx::InteractiveObject *v31; // esi
  Scaleform::GFx::ASStringNode *v32; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v33; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::CharacterHandle *v35; // eax
  void (__thiscall **p_NativePopCallstack)(_DWORD, _DWORD, _DWORD); // esi
  unsigned __int64 ProfileTicks; // rax
  bool v38; // [esp+27h] [ebp-ADh] BYREF
  Scaleform::String v39; // [esp+28h] [ebp-ACh] BYREF
  Scaleform::GFx::ASStringNode *v40; // [esp+2Ch] [ebp-A8h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v41; // [esp+30h] [ebp-A4h]
  Scaleform::GFx::ResourceBindData chId; // [esp+34h] [ebp-A0h] BYREF
  Scaleform::GFx::AS2::MovieRoot *pObject; // [esp+3Ch] [ebp-98h]
  Scaleform::GFx::ASStringNode *v44; // [esp+40h] [ebp-94h] BYREF
  Scaleform::AmpFunctionTimer v45; // [esp+44h] [ebp-90h] BYREF
  Scaleform::GFx::AS2::Value pdestVal; // [esp+58h] [ebp-7Ch] BYREF
  Scaleform::GFx::Resource *v47; // [esp+68h] [ebp-6Ch] BYREF
  Scaleform::GFx::Resource *pOwnerDefRes; // [esp+6Ch] [ebp-68h]
  int v49; // [esp+70h] [ebp-64h]
  Scaleform::GFx::CharPosInfo v50; // [esp+74h] [ebp-60h] BYREF

  v8 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v45,
    v8,
    "ObjectInterface::AttachMovie",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_AttachMovie);
  v9 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v9 || (v9->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
  {
    Stats = v45.Stats;
    v18 = v45.Stats == 0;
LABEL_57:
    if ( !v18 )
    {
      p_NativePopCallstack = (void (__thiscall **)(_DWORD, _DWORD, _DWORD))&Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      (*p_NativePopCallstack)(Stats, ProfileTicks - LODWORD(v45.StartTicks), (ProfileTicks - v45.StartTicks) >> 32);
    }
    return 0;
  }
  pMovieImpl = this->pMovieRoot->pASMovieRoot.pObject->pMovieImpl;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v11 = (int)pMovieImpl->pMainMovie + 4 * pMovieImpl->pMainMovie->AvmObjOffset;
  v12 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 124))(v11);
  chId.pResource.pObject = 0;
  chId.pBinding = 0;
  Scaleform::String::String(&v39, symbolName);
  v13 = v9->pASRoot->pMovieImpl;
  v14 = v9->GetResourceMovieDef(v9);
  v38 = Scaleform::GFx::MovieImpl::FindExportedResource(v13, v14, &chId, &v39) == 0;
  v15 = (void *)(v39.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v39.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
  if ( v38 )
  {
    CharacterHandle = v9->pNameHandle.pObject;
    if ( !CharacterHandle )
      CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v9);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &v9->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie() failed - export name \"%s\" is not found.",
      CharacterHandle->NamePath.pNode->pData,
      symbolName->m128i_i8);
    if ( chId.pResource.pObject )
      Scaleform::GFx::Resource::Release(chId.pResource.pObject);
    Stats = v45.Stats;
    v18 = v45.Stats == 0;
    goto LABEL_57;
  }
  if ( (chId.pResource.pObject->GetResourceTypeCode(chId.pResource.pObject) & 0x8000) == 0 )
  {
    v19 = v9->pNameHandle.pObject;
    if ( !v19 )
      v19 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v9);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &v9->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie() failed - \"%s\" is not a movieclip.",
      v19->NamePath.pNode->pData,
      symbolName->m128i_i8);
    if ( chId.pResource.pObject )
      Scaleform::GFx::Resource::Release(chId.pResource.pObject);
LABEL_16:
    Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v45);
    return 0;
  }
  pOwnerDefRes = 0;
  v49 = 0;
  v47 = chId.pResource.pObject;
  pOwnerDefRes = chId.pBinding->pOwnerDefRes;
  v21 = depth;
  if ( depth < 0 )
  {
    LargestDepthInUse = Scaleform::GFx::DisplayList::GetLargestDepthInUse((Scaleform::GFx::DisplayList *)&v9[1]);
    v21 = LargestDepthInUse - 0x3FFF < 0 ? 0 : LargestDepthInUse - 0x3FFF;
  }
  Scaleform::GFx::CharPosInfo::CharPosInfo(
    &v50,
    (Scaleform::GFx::ResourceId)v47[1].__vftable,
    v21 + 0x4000,
    1,
    &Scaleform::Render::Cxform::Identity,
    1,
    &Scaleform::Render::Matrix2x4<float>::Identity,
    0,
    0.0,
    0,
    0,
    Blend_None);
  if ( v50.Depth > 0x7EFFFFFDu )
  {
    v35 = v9->pNameHandle.pObject;
    if ( !v35 )
      v35 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v9);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &v9->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie(\"%s\") failed - depth (%d) must be >= 0",
      v35->NamePath.pNode->pData,
      symbolName->m128i_i8,
      v50.Depth);
    if ( v50.pFilters.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v50.pFilters.pObject);
    if ( chId.pResource.pObject )
      Scaleform::GFx::Resource::Release(chId.pResource.pObject);
    goto LABEL_16;
  }
  v41 = 0;
  v23 = initArgs;
  if ( !initArgs )
    goto LABEL_31;
  v41 = Scaleform::GFx::AS2::Environment::OperatorNew(
          v12,
          v12->StringContext.pContext->pGlobal.pObject,
          (const Scaleform::GFx::ASString *)&v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pMovieImpl,
          0,
          -1);
  v40 = 0;
  if ( initArgs->Data.Size )
  {
    v39.pData = 0;
    while ( 1 )
    {
      v24 = (char *)v39.pData + (unsigned int)v23->Data.Data;
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                     (Scaleform::GFx::ASStringManager *)v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                     (__m128i *)((*(_DWORD *)v24 & 0xFFFFFFFC) + 8),
                     *(_DWORD *)(*(_DWORD *)v24 & 0xFFFFFFFC) & 0x7FFFFFFF);
      v26 = pObject;
      v44 = StringNode;
      ++StringNode->RefCount;
      pdestVal.T.Type = 0;
      Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v26, (const Scaleform::GFx::Value *)(v24 + 8), &pdestVal);
      ExecuteForEachChild_GC = v41[1].__vftable[1].ExecuteForEachChild_GC;
      v38 = 0;
      ((void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *, bool *))ExecuteForEachChild_GC)(
        &v41[1],
        v12,
        &v44,
        &pdestVal,
        &v38);
      if ( pdestVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
      v28 = v44;
      --v44->RefCount;
      if ( !v28->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      v39.pData = (Scaleform::String::DataDesc *)((char *)v39.pData + 32);
      v40 = (Scaleform::GFx::ASStringNode *)((char *)v40 + 1);
      if ( (unsigned int)v40 >= initArgs->Data.Size )
        break;
      v23 = initArgs;
    }
  }
  if ( v41 )
    v29 = v41 + 1;
  else
LABEL_31:
    v29 = 0;
  v40 = Scaleform::GFx::ASStringManager::CreateStringNode(
          (Scaleform::GFx::ASStringManager *)v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          instanceName);
  ++v40->RefCount;
  v30 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASStringNode **, _DWORD, Scaleform::GFx::AS2::RefCountBaseGC<323> *, int, int, Scaleform::GFx::Resource **, _DWORD))v9->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].~Scaleform::GFx::DisplayObjectBase)(
          v9,
          &v50,
          &v40,
          0,
          v29,
          -1,
          1,
          &v47,
          0);
  v31 = (Scaleform::GFx::InteractiveObject *)v30;
  if ( v30 )
    ++*(_DWORD *)(v30 + 4);
  v32 = v40;
  --v40->RefCount;
  if ( !v32->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v32);
  if ( v31 )
  {
    v31->SetAcceptAnimMoves(v31, 0);
    if ( (unsigned int)Scaleform::GFx::DisplayObjectBase::GetVersion(v9) >= 6 )
    {
      Scaleform::GFx::AS2::Value::Value(&pdestVal, v31);
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v12, &pdestVal, pmc);
      if ( pdestVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
    }
    Scaleform::RefCountNTSImpl::Release(v31);
  }
  v33 = v41;
  if ( v41 )
  {
    RefCount = v41->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v41->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v33);
    }
  }
  if ( v50.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v50.pFilters.pObject);
  if ( chId.pResource.pObject )
    Scaleform::GFx::Resource::Release(chId.pResource.pObject);
  Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v45);
  return 1;
}
