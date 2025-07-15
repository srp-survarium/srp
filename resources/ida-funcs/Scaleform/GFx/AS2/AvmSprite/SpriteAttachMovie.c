void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteAttachMovie(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // esi
  Scaleform::GFx::AS2::Environment *Env; // ebx
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  Scaleform::GFx::MovieDefImpl *v7; // eax
  void *v8; // ebx
  Scaleform::GFx::ASStringNode *v9; // ebx
  const char *pData; // edi
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v13; // ecx
  const char *v14; // edi
  Scaleform::GFx::ASString *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::AS2::ObjectInterface *v17; // ebx
  Scaleform::GFx::AS2::Environment *v18; // ecx
  Scaleform::GFx::AS2::Value *v19; // eax
  int v20; // eax
  Scaleform::GFx::AS2::Value *v21; // eax
  Scaleform::GFx::AS2::Value *v22; // eax
  int v23; // eax
  Scaleform::GFx::InteractiveObject *v24; // ebx
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // ecx
  bool v27; // zf
  const char *v28; // edi
  Scaleform::GFx::ASString *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  Scaleform::GFx::AS2::Environment *v31; // [esp-14h] [ebp-B8h]
  Scaleform::GFx::AS2::Environment *v32; // [esp+8h] [ebp-9Ch]
  Scaleform::GFx::AS2::Environment *v33; // [esp+10h] [ebp-94h]
  bool v34; // [esp+27h] [ebp-7Dh]
  Scaleform::GFx::ASStringNode *v35; // [esp+28h] [ebp-7Ch] BYREF
  Scaleform::GFx::ASString result; // [esp+2Ch] [ebp-78h] BYREF
  Scaleform::GFx::ResourceBindData v37; // [esp+30h] [ebp-74h] BYREF
  Scaleform::GFx::Resource *pObject; // [esp+38h] [ebp-6Ch] BYREF
  Scaleform::GFx::Resource *pOwnerDefRes; // [esp+3Ch] [ebp-68h]
  int v40; // [esp+40h] [ebp-64h]
  Scaleform::GFx::CharPosInfo v41; // [esp+44h] [ebp-60h] BYREF

  v1 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v1);
  v1->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      Target = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    else
      Target = 0;
  }
  else
  {
    Target = fn->Env->Target;
  }
  if ( !Target || fn->NArgs < 3 )
    return;
  Env = fn->Env;
  v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
  Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&v35, Env, -1, 0);
  v37.pResource.pObject = 0;
  v37.pBinding = 0;
  Scaleform::String::String((Scaleform::String *)&result, (const __m128i *)v35->pData);
  pMovieImpl = Target->pASRoot->pMovieImpl;
  v7 = Target->GetResourceMovieDef(Target);
  v34 = Scaleform::GFx::MovieImpl::FindExportedResource(pMovieImpl, v7, &v37, (const Scaleform::String *)&result) == 0;
  v8 = (void *)((unsigned int)result.pNode & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)result.pNode & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  if ( v34 )
  {
    v9 = v35;
    pData = v35->pData;
    Name = Scaleform::GFx::DisplayObject::GetName(Target, &result);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &Target->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie() failed - export name \"%s\" is not found.",
      Name->pNode->pData,
      pData);
    pNode = result.pNode;
    --result.pNode->RefCount;
    v13 = pNode;
    if ( pNode->RefCount )
    {
LABEL_37:
      if ( v37.pResource.pObject )
        Scaleform::GFx::Resource::Release(v37.pResource.pObject);
      v27 = v9->RefCount-- == 1;
      if ( v27 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      return;
    }
LABEL_12:
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    goto LABEL_37;
  }
  if ( (v37.pResource.pObject->GetResourceTypeCode(v37.pResource.pObject) & 0x8000) == 0 )
  {
    v9 = v35;
    v14 = v35->pData;
    v15 = Scaleform::GFx::DisplayObject::GetName(Target, &result);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &Target->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie() failed - \"%s\" is not a movieclip.",
      v15->pNode->pData,
      v14);
    v16 = result.pNode;
    --result.pNode->RefCount;
    v13 = v16;
    if ( v16->RefCount )
      goto LABEL_37;
    goto LABEL_12;
  }
  v17 = 0;
  pObject = v37.pResource.pObject;
  v18 = fn->Env;
  pOwnerDefRes = 0;
  v31 = v18;
  v40 = 0;
  pOwnerDefRes = v37.pBinding->pOwnerDefRes;
  v19 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
  v20 = (int)Scaleform::GFx::AS2::Value::ToNumber(v19, v31);
  Scaleform::GFx::CharPosInfo::CharPosInfo(
    &v41,
    (Scaleform::GFx::ResourceId)pObject[1].__vftable,
    v20 + 0x4000,
    1,
    &Scaleform::Render::Cxform::Identity,
    1,
    &Scaleform::Render::Matrix2x4<float>::Identity,
    0,
    0.0,
    0,
    0,
    Blend_None);
  if ( v41.Depth > 0x7EFFFFFDu )
  {
    v9 = v35;
    v28 = v35->pData;
    v29 = Scaleform::GFx::DisplayObject::GetName(Target, &result);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &Target->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.attachMovie(\"%s\") failed - depth (%d) must be >= 0",
      v29->pNode->pData,
      v28,
      v41.Depth);
    v30 = result.pNode;
    --result.pNode->RefCount;
    if ( !v30->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v30);
    if ( v41.pFilters.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v41.pFilters.pObject);
    goto LABEL_37;
  }
  if ( fn->NArgs == 4 )
  {
    v33 = fn->Env;
    v21 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
    v17 = Scaleform::GFx::AS2::Value::ToObjectInterface(v21, v33);
  }
  v32 = fn->Env;
  v22 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
  Scaleform::GFx::AS2::Value::ToStringImpl(v22, &result, v32, -1, 0);
  v23 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASString *, _DWORD, Scaleform::GFx::AS2::ObjectInterface *, int, int, Scaleform::GFx::Resource **, _DWORD))Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].~Scaleform::GFx::DisplayObjectBase)(
          Target,
          &v41,
          &result,
          0,
          v17,
          -1,
          1,
          &pObject,
          0);
  v24 = (Scaleform::GFx::InteractiveObject *)v23;
  if ( v23 )
    ++*(_DWORD *)(v23 + 4);
  v25 = result.pNode;
  --result.pNode->RefCount;
  if ( !v25->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( v24 )
  {
    v24->SetAcceptAnimMoves(v24, 0);
    if ( (unsigned int)Scaleform::GFx::DisplayObjectBase::GetVersion(Target) >= 6 )
      Scaleform::GFx::AS2::Value::SetAsCharacter(
        fn->Result,
        LOBYTE(v24->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0 ? v24 : 0);
    Scaleform::RefCountNTSImpl::Release(v24);
  }
  if ( v41.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v41.pFilters.pObject);
  if ( v37.pResource.pObject )
    Scaleform::GFx::Resource::Release(v37.pResource.pObject);
  v26 = v35;
  v27 = v35->RefCount-- == 1;
  if ( v27 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
}
