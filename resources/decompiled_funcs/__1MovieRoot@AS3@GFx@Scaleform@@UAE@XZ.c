void __thiscall Scaleform::GFx::AS3::MovieRoot::~MovieRoot(Scaleform::GFx::AS3::MovieRoot *this)
{
  bool *p_StageInvalidated; // ebp
  Scaleform::RefCountNTSImpl *v3; // ecx
  int v4; // eax
  Scaleform::RefCountNTSImpl **v5; // edi
  int v6; // ebx
  Scaleform::GFx::AS3::Stage *pObject; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::ASVM *v10; // ecx
  Scaleform::RefCountVImpl *v11; // ecx
  Scaleform::RefCountVImpl *v12; // ecx
  int i; // [esp+10h] [ebp-4h]

  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AS3::MovieRoot_vtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable'{for `Scaleform::GFx::ASMovieRootBase'};
  this->Scaleform::GFx::AS3::FlashUI::__vftable = (Scaleform::GFx::AS3::FlashUI_vtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable'{for `Scaleform::GFx::AS3::FlashUI'};
  this->Scaleform::GFx::KeyboardState::IListener::__vftable = (Scaleform::GFx::KeyboardState::IListener_vtbl *)&Scaleform::GFx::AS3::MovieRoot::`vftable'{for `Scaleform::GFx::KeyboardState::IListener'};
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>(&this->Sockets.Data);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF>>::Clear(&this->LoadedMovieDefs.mHash);
  p_StageInvalidated = &this->StageInvalidated;
  for ( i = 5; i >= 0; --i )
  {
    v3 = (Scaleform::RefCountNTSImpl *)*((_DWORD *)p_StageInvalidated - 49);
    p_StageInvalidated -= 208;
    if ( v3 )
      Scaleform::RefCountNTSImpl::Release(v3);
    v4 = *((_DWORD *)p_StageInvalidated + 1);
    v5 = (Scaleform::RefCountNTSImpl **)(*(_DWORD *)p_StageInvalidated + 4 * v4 - 4);
    if ( v4 )
    {
      v6 = *((_DWORD *)p_StageInvalidated + 1);
      do
      {
        if ( *v5 )
          Scaleform::RefCountNTSImpl::Release(*v5);
        --v5;
        --v6;
      }
      while ( v6 );
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *(void **)p_StageInvalidated);
  }
  Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(
    this->BuiltinsMgr.pStringManager,
    this->BuiltinsMgr.Builtins,
    0x3Eu);
  pObject = this->pStage.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::Clear(&this->mEventChains.Chains.mHash);
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType::~ActionQueueType(&this->ActionQueue);
  if ( (this->ExternalIntfRetVal.Flags & 0x1F) > 9 )
  {
    if ( (this->ExternalIntfRetVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->ExternalIntfRetVal.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      this->ExternalIntfRetVal.Flags &= 0xFFFFFDE0;
      this->ExternalIntfRetVal.Bonus.pWeakProxy = 0;
      this->ExternalIntfRetVal.value.VS._1.VInt = 0;
      this->ExternalIntfRetVal.value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->ExternalIntfRetVal);
    }
  }
  v10 = this->pAVM.pObject;
  if ( v10 )
  {
    if ( this->pAVM.Owner )
    {
      this->pAVM.Owner = 0;
      ((void (__thiscall *)(Scaleform::GFx::AS3::ASVM *, int))v10->~Scaleform::GFx::AS3::ASVM)(v10, 1);
    }
    this->pAVM.pObject = 0;
  }
  this->pAVM.Owner = 0;
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(this->MemContext.pObject->ASGC.pObject, 0, 1u);
  v11 = (Scaleform::RefCountVImpl *)this->MemContext.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  this->Scaleform::GFx::KeyboardState::IListener::__vftable = (Scaleform::GFx::KeyboardState::IListener_vtbl *)&Scaleform::GFx::Text::CSSHandler<wchar_t>::`vftable';
  this->Scaleform::GFx::AS3::FlashUI::__vftable = (Scaleform::GFx::AS3::FlashUI_vtbl *)&Scaleform::GFx::AMP::SocketImplFactory::`vftable';
  this->Scaleform::GFx::ASMovieRootBase::Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AS3::MovieRoot_vtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable';
  v12 = (Scaleform::RefCountVImpl *)this->pASSupport.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
