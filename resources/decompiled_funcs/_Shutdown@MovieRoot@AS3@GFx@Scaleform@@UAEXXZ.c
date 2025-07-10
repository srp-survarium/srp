void __usercall Scaleform::GFx::AS3::MovieRoot::Shutdown(
        Scaleform::GFx::AS3::MovieRoot *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>)
{
  Scaleform::GFx::AS3::Stage *pObject; // ecx
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS3::Value> *pInvokeAliases; // esi
  Scaleform::GFx::AS3::Value *p_ExternalIntfRetVal; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::MovieRoot::MouseState *mMouseState; // esi
  unsigned int Size; // eax
  Scaleform::RefCountNTSImpl **p_pObject; // edi
  unsigned int v12; // ebp
  Scaleform::RefCountNTSImpl *v13; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *pNext; // edi
  Scaleform::ArrayDefaultPolicy *v15; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> **v16; // esi
  Scaleform::GFx::AS3::ASVM *v17; // ecx
  int v18; // [esp+14h] [ebp+4h]

  Scaleform::GFx::MovieImpl::ClearPlayList(this->pMovieImpl);
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType::Clear(&this->ActionQueue);
  pObject = this->pStage.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pStage.pObject = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::MovieRoot *, int, int, int))this->ForceCollect)(this, 2, a2, a3);
  pInvokeAliases = this->pInvokeAliases;
  if ( pInvokeAliases )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Clear(&this->pInvokeAliases->mHash);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pInvokeAliases);
  }
  p_ExternalIntfRetVal = &this->ExternalIntfRetVal;
  this->pInvokeAliases = 0;
  if ( (this->ExternalIntfRetVal.Flags & 0x1F) > 9 )
  {
    if ( (this->ExternalIntfRetVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->ExternalIntfRetVal.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      p_ExternalIntfRetVal->Flags &= 0xFFFFFDE0;
      this->ExternalIntfRetVal.Bonus.pWeakProxy = 0;
      this->ExternalIntfRetVal.value.VS._1.VInt = 0;
      this->ExternalIntfRetVal.value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->ExternalIntfRetVal);
    }
  }
  p_ExternalIntfRetVal->Flags &= 0xFFFFFFE0;
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::Clear(&this->mEventChains.Chains.mHash);
  mMouseState = this->mMouseState;
  v18 = 6;
  do
  {
    Size = mMouseState->RolloverStack.Data.Size;
    if ( Size )
    {
      p_pObject = &mMouseState->RolloverStack.Data.Data[Size - 1].pObject;
      v12 = mMouseState->RolloverStack.Data.Size;
      do
      {
        if ( *p_pObject )
          Scaleform::RefCountNTSImpl::Release(*p_pObject);
        --p_pObject;
        --v12;
      }
      while ( v12 );
      if ( (mMouseState->RolloverStack.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( mMouseState->RolloverStack.Data.Data )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, mMouseState->RolloverStack.Data.Data);
          mMouseState->RolloverStack.Data.Data = 0;
        }
        mMouseState->RolloverStack.Data.Policy.Capacity = 0;
      }
    }
    else if ( !mMouseState->RolloverStack.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &mMouseState->RolloverStack.Data,
        mMouseState,
        0);
    }
    mMouseState->RolloverStack.Data.Size = 0;
    v13 = mMouseState->LastMouseOverObj.pObject;
    if ( v13 )
      Scaleform::RefCountNTSImpl::Release(v13);
    mMouseState->LastMouseOverObj.pObject = 0;
    ++mMouseState;
    --v18;
  }
  while ( v18 );
  pNext = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)this->pMovieImpl->RootMovieDefNodes.Root.pNext;
  while ( 1 )
  {
    v15 = this->pMovieImpl == (Scaleform::GFx::MovieImpl *)-56 ? 0 : &this->pMovieImpl->MovieLevels.Data.Policy;
    if ( pNext == (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)v15 )
      break;
    v16 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> **)&pNext[3];
    if ( pNext[3].Size )
    {
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
        *v16,
        pNext[3].Size);
      if ( (pNext[3].Policy.Capacity & 0xFFFFFFFE) == 0 )
        goto LABEL_38;
      if ( *v16 )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *v16);
        *v16 = 0;
      }
      pNext[3].Policy.Capacity = 0;
      pNext[3].Size = 0;
      pNext = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)pNext->Policy.Capacity;
    }
    else
    {
      if ( !pNext[3].Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          pNext + 3,
          &pNext[3],
          0);
LABEL_38:
      pNext[3].Size = 0;
      pNext = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)pNext->Policy.Capacity;
    }
  }
  this->ForceCollect(this, 2u);
  Scaleform::GFx::AS3::VM::UnregisterAllAbcFiles(this->pAVM.pObject);
  this->ForceCollect(this, 2u);
  v17 = this->pAVM.pObject;
  if ( v17 )
  {
    if ( this->pAVM.Owner )
    {
      this->pAVM.Owner = 0;
      ((void (__thiscall *)(Scaleform::GFx::AS3::ASVM *, int))v17->~Scaleform::GFx::AS3::ASVM)(v17, 1);
    }
    this->pAVM.pObject = 0;
  }
  this->pAVM.Owner = 0;
}
