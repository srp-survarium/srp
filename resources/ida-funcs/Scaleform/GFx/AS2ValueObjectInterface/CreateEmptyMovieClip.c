char __thiscall Scaleform::GFx::AS2ValueObjectInterface::CreateEmptyMovieClip(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::GFx::Value *pmc,
        __m128i *instanceName,
        int depth)
{
  Scaleform::GFx::AMP::ViewStats *v6; // eax
  Scaleform::GFx::InteractiveObject *v7; // esi
  Scaleform::GFx::AS2::MovieRoot *pObject; // ebx
  int v9; // ecx
  Scaleform::GFx::AS2::Environment *v10; // edi
  int v11; // eax
  int LargestDepthInUse; // eax
  int v13; // eax
  Scaleform::GFx::InteractiveObject *v14; // esi
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::AmpStats *v17; // edi
  void (__thiscall **v18)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v19; // rax
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::ASStringNode *StringNode; // [esp+20h] [ebp-84h] BYREF
  Scaleform::AmpFunctionTimer v24; // [esp+24h] [ebp-80h] BYREF
  Scaleform::GFx::AS2::Value value; // [esp+34h] [ebp-70h] BYREF
  Scaleform::GFx::CharPosInfo v26; // [esp+44h] [ebp-60h] BYREF

  v6 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v24,
    v6,
    "ObjectInterface::CreateEmptyMovieClip",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_CreateEmptyMovieClip);
  v7 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v7 || (v7->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
  {
    Stats = v24.Stats;
    if ( v24.Stats )
    {
      p_NativePopCallstack = &v24.Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v24.StartTicks),
        (ProfileTicks - v24.StartTicks) >> 32);
    }
    return 0;
  }
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v9 = (int)pObject->pMovieImpl->pMainMovie + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v10 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 124))(v9);
  v11 = depth;
  if ( depth < 0 )
  {
    LargestDepthInUse = Scaleform::GFx::DisplayList::GetLargestDepthInUse((Scaleform::GFx::DisplayList *)&v7[1]);
    v11 = LargestDepthInUse - 0x3FFF < 0 ? 0 : LargestDepthInUse - 0x3FFF;
  }
  Scaleform::GFx::CharPosInfo::CharPosInfo(
    &v26,
    (Scaleform::GFx::ResourceId)65537,
    v11 + 0x4000,
    1,
    &Scaleform::Render::Cxform::Identity,
    1,
    &Scaleform::Render::Matrix2x4<float>::Identity,
    0,
    0.0,
    0,
    0,
    Blend_None);
  if ( v26.Depth > 0x7EFFFFFDu )
  {
    if ( v26.pFilters.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v26.pFilters.pObject);
    v17 = v24.Stats;
    if ( v24.Stats )
    {
      v18 = &v24.Stats->NativePopCallstack;
      v19 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v18)(
        v17,
        v19 - LODWORD(v24.StartTicks),
        (v19 - v24.StartTicks) >> 32);
      return 0;
    }
    return 0;
  }
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)v10->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 instanceName);
  ++StringNode->RefCount;
  v13 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASStringNode **, _DWORD, _DWORD, int, int, _DWORD, _DWORD))v7->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].~Scaleform::GFx::DisplayObjectBase)(
          v7,
          &v26,
          &StringNode,
          0,
          0,
          -1,
          1,
          0,
          0);
  v14 = (Scaleform::GFx::InteractiveObject *)v13;
  if ( v13 )
    ++*(_DWORD *)(v13 + 4);
  v15 = StringNode;
  --StringNode->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v14 )
  {
    v14->SetAcceptAnimMoves(v14, 0);
    Scaleform::GFx::AS2::Value::Value(&value, v14);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v10, &value, pmc);
    if ( value.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&value);
    Scaleform::RefCountNTSImpl::Release(v14);
  }
  if ( v26.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v26.pFilters.pObject);
  Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v24);
  return 1;
}
