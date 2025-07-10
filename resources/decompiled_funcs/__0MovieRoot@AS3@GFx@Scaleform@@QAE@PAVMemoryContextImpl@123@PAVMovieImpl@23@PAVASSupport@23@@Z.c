void __thiscall Scaleform::GFx::AS3::MovieRoot::MovieRoot(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Resource *memContext,
        Scaleform::GFx::MovieImpl *pmovie,
        Scaleform::GFx::Resource *pas)
{
  Scaleform::GFx::ASStringManager *pObject; // ebp
  Scaleform::GFx::AS3::MovieRoot::MouseState *mMouseState; // edi
  int i; // ebp
  Scaleform::GFx::Value::ObjectInterface *v8; // eax

  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AS3::MovieRoot_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AS3::MovieRoot_vtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable';
  this->pMovieImpl = 0;
  if ( pas )
    Scaleform::RefCountImpl::AddRef(pas);
  this->pASSupport.pObject = (Scaleform::GFx::ASSupport *)pas;
  this->AVMVersion = pas->__vftable[1].GetResourceTypeCode(pas);
  this->Scaleform::GFx::AS3::FlashUI::__vftable = (Scaleform::GFx::AS3::FlashUI_vtbl *)&Scaleform::GFx::AMP::SocketImplFactory::`vftable';
  this->State = sError;
  this->NeedToCheck = 0;
  this->Scaleform::GFx::KeyboardState::IListener::__vftable = (Scaleform::GFx::KeyboardState::IListener_vtbl *)&Scaleform::GFx::Text::CSSHandler<wchar_t>::`vftable';
  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AS3::MovieRoot_vtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable'{for `Scaleform::GFx::ASMovieRootBase'};
  this->Scaleform::GFx::AS3::FlashUI::__vftable = (Scaleform::GFx::AS3::FlashUI_vtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable'{for `Scaleform::GFx::AS3::FlashUI'};
  this->Scaleform::GFx::KeyboardState::IListener::__vftable = (Scaleform::GFx::KeyboardState::IListener_vtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable'{for `Scaleform::GFx::KeyboardState::IListener'};
  if ( memContext )
    Scaleform::RefCountImpl::AddRef(memContext);
  this->MemContext.pObject = (Scaleform::GFx::AS3::MemoryContextImpl *)memContext;
  this->pAVM.pObject = 0;
  this->pAVM.Owner = 1;
  this->ExternalIntfRetVal.Flags = 0;
  this->ExternalIntfRetVal.Bonus.pWeakProxy = 0;
  this->NumAdvancesSinceCollection = 0;
  this->LastCollectionFrame = 0;
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType::ActionQueueType(
    &this->ActionQueue,
    (Scaleform::MemoryHeap *)memContext->pLib);
  this->mEventChains.Chains.mHash.pTable = 0;
  this->pStage.pObject = 0;
  pObject = this->MemContext.pObject->StringMgr.pObject;
  memset(&this->BuiltinsMgr, 0, 0xF8u);
  this->BuiltinsMgr.pStringManager = pObject;
  this->BuiltinsMgr.pStaticStrings = AS3BuiltinTable;
  Scaleform::GFx::ASStringManager::InitBuiltinArray(pObject, this->BuiltinsMgr.Builtins, AS3BuiltinTable, 0x3Eu);
  mMouseState = this->mMouseState;
  for ( i = 5; i >= 0; --i )
  {
    mMouseState->RolloverStack.Data.Data = 0;
    mMouseState->RolloverStack.Data.Size = 0;
    mMouseState->RolloverStack.Data.Policy.Capacity = 0;
    mMouseState->LastMouseOverObj.pObject = 0;
    `vector constructor iterator'(
      (char *)mMouseState->DblClick,
      0xCu,
      16,
      (void *(__thiscall *)(void *))Scaleform::GFx::AS3::MovieRoot::MouseState::DoubleClickInfo::DoubleClickInfo);
    ++mMouseState;
  }
  this->StageInvalidated = 0;
  this->LoadedMovieDefs.mHash.pTable = 0;
  this->Flags = 0;
  this->Sockets.Data.Data = 0;
  this->Sockets.Data.Size = 0;
  this->Sockets.Data.Policy.Capacity = 0;
  this->ASFramesToExecute = 0;
  this->pMovieImpl = pmovie;
  Scaleform::GFx::MovieImpl::SetASMovieRoot(pmovie, (Scaleform::GFx::Resource *)this);
  v8 = (Scaleform::GFx::Value::ObjectInterface *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 8, 0);
  if ( v8 )
  {
    v8->pMovieRoot = pmovie;
    v8->__vftable = (Scaleform::GFx::Value::ObjectInterface_vtbl *)&Scaleform::GFx::AS3ValueObjectInterface::`vftable';
  }
  else
  {
    v8 = 0;
  }
  pmovie->pObjectInterface = v8;
  Scaleform::GFx::MovieImpl::SetKeyboardListener(
    pmovie,
    (Scaleform::GFx::MovieImpl *)&this->Scaleform::GFx::KeyboardState::IListener);
  this->pInvokeAliases = 0;
  pmovie->Flags = (unsigned int)Scaleform::GFx::AS2::CreateShadow & 0xDFFFFFFF | pmovie->Flags & 0xDF7FFFFF | 0x10000000;
  this->MainLoaderInfoEventsState = 0;
}
