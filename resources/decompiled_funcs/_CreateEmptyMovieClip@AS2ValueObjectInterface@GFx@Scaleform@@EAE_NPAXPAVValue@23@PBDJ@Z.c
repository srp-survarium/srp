char __thiscall Scaleform::GFx::AS2ValueObjectInterface::CreateEmptyMovieClip(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value *pmc,
        char *instanceName,
        int depth)
{
  Scaleform::GFx::InteractiveObject *v6; // esi
  Scaleform::GFx::AS2::MovieRoot *pObject; // ebx
  int v8; // ecx
  Scaleform::GFx::AS2::Environment *v9; // edi
  int v10; // eax
  int LargestDepthInUse; // eax
  int v12; // eax
  Scaleform::GFx::InteractiveObject *v13; // esi
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *StringNode; // [esp+DCh] [ebp-74h] BYREF
  Scaleform::GFx::AS2::Value value; // [esp+E0h] [ebp-70h] BYREF
  Scaleform::GFx::CharPosInfo v18; // [esp+F0h] [ebp-60h] BYREF

  v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v6 || (v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    return 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v8 = (int)pObject->pMovieImpl->pMainMovie + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v9 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 124))(v8);
  v10 = depth;
  if ( depth < 0 )
  {
    LargestDepthInUse = Scaleform::GFx::DisplayList::GetLargestDepthInUse((Scaleform::GFx::DisplayList *)&v6[1]);
    v10 = LargestDepthInUse - 0x3FFF < 0 ? 0 : LargestDepthInUse - 0x3FFF;
  }
  Scaleform::GFx::CharPosInfo::CharPosInfo(
    &v18,
    (Scaleform::GFx::ResourceId)65537,
    v10 + 0x4000,
    1,
    &Scaleform::Render::Cxform::Identity,
    1,
    &Scaleform::Render::Matrix2x4<float>::Identity,
    0,
    0.0,
    0,
    0,
    Blend_None);
  if ( v18.Depth > 0x7EFFFFFDu )
  {
    if ( v18.pFilters.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v18.pFilters.pObject);
    return 0;
  }
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)v9->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 instanceName);
  ++StringNode->RefCount;
  v12 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASStringNode **, _DWORD, _DWORD, int, int, _DWORD, _DWORD))v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].~Scaleform::GFx::DisplayObjectBase)(
          v6,
          &v18,
          &StringNode,
          0,
          0,
          -1,
          1,
          0,
          0);
  v13 = (Scaleform::GFx::InteractiveObject *)v12;
  if ( v12 )
    ++*(_DWORD *)(v12 + 4);
  v14 = StringNode;
  --StringNode->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( v13 )
  {
    v13->SetAcceptAnimMoves(v13, 0);
    Scaleform::GFx::AS2::Value::Value(&value, v13);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v9, &value, pmc);
    if ( value.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&value);
    Scaleform::RefCountNTSImpl::Release(v13);
  }
  if ( v18.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v18.pFilters.pObject);
  return 1;
}
