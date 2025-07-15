char __thiscall Scaleform::GFx::AS2::MovieRoot::Init(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::MovieDefImpl *pmovieDef)
{
  Scaleform::GFx::AS2::GlobalContext *v3; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::AS2::GlobalContext *pObject; // ecx
  Scaleform::Render::ContextImpl::Context *p_RenderContext; // ebp
  Scaleform::Render::TreeNode::NodeData *v7; // eax
  Scaleform::Render::TreeNode::NodeData *v8; // edi
  Scaleform::Render::ContextImpl::Entry *EntryHelper; // eax
  Scaleform::Render::TreeContainer *v10; // ecx
  Scaleform::Render::TreeContainer *v11; // edi
  Scaleform::GFx::ASSupport *v13; // ecx
  Scaleform::GFx::Sprite *v14; // edi
  _DWORD v16[3]; // [esp+40h] [ebp-Ch] BYREF

  v3 = (Scaleform::GFx::AS2::GlobalContext *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 60, 0);
  if ( v3 )
  {
    pMovieImpl = this->pMovieImpl;
    v3->RefCount = 1;
    v3->__vftable = (Scaleform::GFx::AS2::GlobalContext_vtbl *)&Scaleform::GFx::AS2::GlobalContext::`vftable';
    v3->Prototypes.mHash.pTable = 0;
    v3->RegisteredClasses.mHash.pTable = 0;
    v3->BuiltinClassesRegistry.mHash.pTable = 0;
    v3->pGlobal.pObject = 0;
    v3->GFxExtensions.Value = 0;
    v3->StandardMemberMap.mHash.pTable = 0;
    Scaleform::GFx::AS2::GlobalContext::Init(v3, pMovieImpl);
  }
  else
  {
    v3 = 0;
  }
  pObject = this->pGlobalContext.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pGlobalContext.pObject = v3;
  p_RenderContext = &this->pMovieImpl->RenderContext;
  v7 = (Scaleform::Render::TreeNode::NodeData *)p_RenderContext->pHeap->Alloc(p_RenderContext->pHeap, 160u, 0);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::Render::TreeNode::NodeData::NodeData(v7, ET_Container);
    v8->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable';
    *(_DWORD *)&v8[1].Type = 0;
    v8[1].__vftable = 0;
  }
  EntryHelper = Scaleform::Render::ContextImpl::Context::createEntryHelper(
                  p_RenderContext,
                  &v8->Scaleform::Render::ContextImpl::EntryData);
  v10 = this->TopNode.pObject;
  v11 = (Scaleform::Render::TreeContainer *)EntryHelper;
  if ( v10 )
  {
    if ( v10->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v10);
  }
  this->TopNode.pObject = v11;
  Scaleform::Render::TreeContainer::Insert(this->pMovieImpl->pRenderRoot.pObject, 0, v11);
  v16[0] = pmovieDef->pBindData.pObject->pDataDef.pObject;
  v13 = this->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
  v16[1] = pmovieDef;
  v16[2] = 0;
  v14 = (Scaleform::GFx::Sprite *)((int (__thiscall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, _DWORD *, _DWORD, int, int))v13->CreateCharacterInstance)(
                                    v13,
                                    this->pMovieImpl,
                                    v16,
                                    0,
                                    0x40000,
                                    3);
  Scaleform::GFx::Sprite::SetLoadedSeparately(v14, 0, (int)v14, 1);
  Scaleform::GFx::AS2::AvmSprite::SetLevel(
    (Scaleform::GFx::AS2::AvmSprite *)(&v14->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + v14->AvmObjOffset),
    0);
  Scaleform::GFx::MovieImpl::SetLevelMovie(this->pMovieImpl, 0, v14);
  this->RegisterAuxASClasses(this);
  this->ResolveStickyVariables(this, v14);
  ((void (__thiscall *)(Scaleform::GFx::Sprite *, _DWORD, _DWORD))v14->SetFOV)(
    v14,
    COERCE_UNSIGNED_INT64(55.0),
    HIDWORD(COERCE_UNSIGNED_INT64(55.0)));
  Scaleform::RefCountNTSImpl::Release(v14);
  return 1;
}
