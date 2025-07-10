char __thiscall Scaleform::GFx::AS2ValueObjectInterface::AttachMovie(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value *pmc,
        char *symbolName,
        char *instanceName,
        int depth,
        const Scaleform::GFx::MemberValueSet *initArgs)
{
  Scaleform::GFx::InteractiveObject *v8; // ebx
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  int v10; // ecx
  Scaleform::GFx::AS2::Environment *v11; // edi
  Scaleform::GFx::MovieImpl *v12; // esi
  Scaleform::GFx::MovieDefImpl *v13; // eax
  void *v14; // esi
  Scaleform::GFx::CharacterHandle *CharacterHandle; // eax
  Scaleform::GFx::Resource *v16; // ecx
  bool v17; // zf
  Scaleform::GFx::CharacterHandle *v18; // eax
  int v19; // eax
  int LargestDepthInUse; // eax
  const Scaleform::GFx::MemberValueSet *v21; // esi
  char *v22; // esi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::AS2::MovieRoot *v24; // ecx
  void (__thiscall *ExecuteForEachChild_GC)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC); // edx
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v27; // esi
  int v28; // eax
  Scaleform::GFx::InteractiveObject *v29; // esi
  Scaleform::GFx::ASStringNode *v30; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v31; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::CharacterHandle *v34; // eax
  bool v35; // [esp+48Fh] [ebp-99h] BYREF
  Scaleform::String symbol; // [esp+490h] [ebp-98h] BYREF
  Scaleform::GFx::ASStringNode *v37; // [esp+494h] [ebp-94h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v38; // [esp+498h] [ebp-90h]
  Scaleform::GFx::ResourceBindData presBindData; // [esp+49Ch] [ebp-8Ch] BYREF
  Scaleform::GFx::ASStringNode *v40; // [esp+4A4h] [ebp-84h] BYREF
  Scaleform::GFx::AS2::MovieRoot *pObject; // [esp+4A8h] [ebp-80h]
  Scaleform::GFx::AS2::Value pdestVal; // [esp+4ACh] [ebp-7Ch] BYREF
  Scaleform::GFx::Resource *v43; // [esp+4BCh] [ebp-6Ch] BYREF
  Scaleform::GFx::Resource *pOwnerDefRes; // [esp+4C0h] [ebp-68h]
  int v45; // [esp+4C4h] [ebp-64h]
  Scaleform::GFx::CharPosInfo v46; // [esp+4C8h] [ebp-60h] BYREF

  v8 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v8 || (v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    return 0;
  pMovieImpl = this->pMovieRoot->pASMovieRoot.pObject->pMovieImpl;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v10 = (int)pMovieImpl->pMainMovie + 4 * pMovieImpl->pMainMovie->AvmObjOffset;
  v11 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 124))(v10);
  presBindData.pResource.pObject = 0;
  presBindData.pBinding = 0;
  Scaleform::String::String(&symbol, symbolName);
  v12 = v8->pASRoot->pMovieImpl;
  v13 = v8->GetResourceMovieDef(v8);
  v35 = Scaleform::GFx::MovieImpl::FindExportedResource(v12, v13, &presBindData, &symbol) == 0;
  v14 = (void *)(symbol.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((symbol.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
  if ( v35 )
  {
    CharacterHandle = v8->pNameHandle.pObject;
    if ( !CharacterHandle )
      CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v8);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &v8->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie() failed - export name \"%s\" is not found.",
      CharacterHandle->NamePath.pNode->pData,
      symbolName);
LABEL_9:
    v16 = presBindData.pResource.pObject;
    v17 = presBindData.pResource.pObject == 0;
LABEL_51:
    if ( !v17 )
      Scaleform::GFx::Resource::Release(v16);
    return 0;
  }
  if ( (presBindData.pResource.pObject->GetResourceTypeCode(presBindData.pResource.pObject) & 0x8000) == 0 )
  {
    v18 = v8->pNameHandle.pObject;
    if ( !v18 )
      v18 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v8);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &v8->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie() failed - \"%s\" is not a movieclip.",
      v18->NamePath.pNode->pData,
      symbolName);
    goto LABEL_9;
  }
  pOwnerDefRes = 0;
  v45 = 0;
  v43 = presBindData.pResource.pObject;
  pOwnerDefRes = presBindData.pBinding->pOwnerDefRes;
  v19 = depth;
  if ( depth < 0 )
  {
    LargestDepthInUse = Scaleform::GFx::DisplayList::GetLargestDepthInUse((Scaleform::GFx::DisplayList *)&v8[1]);
    v19 = LargestDepthInUse - 0x3FFF < 0 ? 0 : LargestDepthInUse - 0x3FFF;
  }
  Scaleform::GFx::CharPosInfo::CharPosInfo(
    &v46,
    (Scaleform::GFx::ResourceId)v43[1].__vftable,
    v19 + 0x4000,
    1,
    &Scaleform::Render::Cxform::Identity,
    1,
    &Scaleform::Render::Matrix2x4<float>::Identity,
    0,
    0.0,
    0,
    0,
    Blend_None);
  if ( v46.Depth > 0x7EFFFFFDu )
  {
    v34 = v8->pNameHandle.pObject;
    if ( !v34 )
      v34 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v8);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &v8->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie(\"%s\") failed - depth (%d) must be >= 0",
      v34->NamePath.pNode->pData,
      symbolName,
      v46.Depth);
    if ( v46.pFilters.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v46.pFilters.pObject);
    v16 = presBindData.pResource.pObject;
    v17 = presBindData.pResource.pObject == 0;
    goto LABEL_51;
  }
  v38 = 0;
  v21 = initArgs;
  if ( !initArgs )
    goto LABEL_28;
  v38 = Scaleform::GFx::AS2::Environment::OperatorNew(
          v11,
          v11->StringContext.pContext->pGlobal.pObject,
          (const Scaleform::GFx::ASString *)&v11->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pMovieImpl,
          0,
          -1);
  v37 = 0;
  if ( initArgs->Data.Size )
  {
    symbol.pData = 0;
    while ( 1 )
    {
      v22 = (char *)symbol.pData + (unsigned int)v21->Data.Data;
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                     (Scaleform::GFx::ASStringManager *)v11->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                     (char *)((*(_DWORD *)v22 & 0xFFFFFFFC) + 8),
                     *(_DWORD *)(*(_DWORD *)v22 & 0xFFFFFFFC) & 0x7FFFFFFF);
      v24 = pObject;
      v40 = StringNode;
      ++StringNode->RefCount;
      pdestVal.T.Type = 0;
      Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v24, (const Scaleform::GFx::Value *)(v22 + 8), &pdestVal);
      ExecuteForEachChild_GC = v38[1].__vftable[1].ExecuteForEachChild_GC;
      v35 = 0;
      ((void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *, bool *))ExecuteForEachChild_GC)(
        &v38[1],
        v11,
        &v40,
        &pdestVal,
        &v35);
      if ( pdestVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
      v26 = v40;
      --v40->RefCount;
      if ( !v26->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v26);
      symbol.pData = (Scaleform::String::DataDesc *)((char *)symbol.pData + 32);
      v37 = (Scaleform::GFx::ASStringNode *)((char *)v37 + 1);
      if ( (unsigned int)v37 >= initArgs->Data.Size )
        break;
      v21 = initArgs;
    }
  }
  if ( v38 )
    v27 = v38 + 1;
  else
LABEL_28:
    v27 = 0;
  v37 = Scaleform::GFx::ASStringManager::CreateStringNode(
          (Scaleform::GFx::ASStringManager *)v11->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          instanceName);
  ++v37->RefCount;
  v28 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASStringNode **, _DWORD, Scaleform::GFx::AS2::RefCountBaseGC<323> *, int, int, Scaleform::GFx::Resource **, _DWORD))v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].~Scaleform::GFx::DisplayObjectBase)(
          v8,
          &v46,
          &v37,
          0,
          v27,
          -1,
          1,
          &v43,
          0);
  v29 = (Scaleform::GFx::InteractiveObject *)v28;
  if ( v28 )
    ++*(_DWORD *)(v28 + 4);
  v30 = v37;
  --v37->RefCount;
  if ( !v30->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  if ( v29 )
  {
    v29->SetAcceptAnimMoves(v29, 0);
    if ( (unsigned int)Scaleform::GFx::DisplayObjectBase::GetVersion(v8) >= 6 )
    {
      Scaleform::GFx::AS2::Value::Value(&pdestVal, v29);
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v11, &pdestVal, pmc);
      if ( pdestVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
    }
    Scaleform::RefCountNTSImpl::Release(v29);
  }
  v31 = v38;
  if ( v38 )
  {
    RefCount = v38->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v38->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v31);
    }
  }
  if ( v46.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v46.pFilters.pObject);
  if ( presBindData.pResource.pObject )
    Scaleform::GFx::Resource::Release(presBindData.pResource.pObject);
  return 1;
}
