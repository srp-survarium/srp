void __thiscall Scaleform::GFx::TextField::~TextField(Scaleform::GFx::TextField *this)
{
  Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pImageDescAssoc; // edi
  Scaleform::Render::Text::DocView *pObject; // ecx
  Scaleform::GFx::TextField::ShadowParams *pShadow; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::TextField::CSSHolderBase *v7; // ecx
  volatile LONG *v8; // edi
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::GFx::TextFieldDef *v11; // ecx

  pImageDescAssoc = this->pImageDescAssoc;
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::TextField_vtbl *)&Scaleform::GFx::TextField::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::TextField::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( pImageDescAssoc )
  {
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear(&pImageDescAssoc->mHash);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pImageDescAssoc);
  }
  pObject = this->pDocument.pObject;
  this->pImageDescAssoc = 0;
  Scaleform::Render::Text::DocView::Close(pObject);
  pShadow = this->pShadow;
  if ( pShadow )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pShadow->TextOffsets.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pShadow->ShadowOffsets.Data.Data);
    pNode = pShadow->ShadowStyleStr.pNode;
    if ( pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pShadow);
  }
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&this->TextDocListener);
  v7 = this->pCSSData.pObject;
  if ( v7 )
  {
    if ( this->pCSSData.Owner )
    {
      this->pCSSData.Owner = 0;
      ((void (__thiscall *)(Scaleform::GFx::TextField::CSSHolderBase *, int))v7->~Scaleform::GFx::TextField::CSSHolderBase)(
        v7,
        1);
    }
    this->pCSSData.pObject = 0;
  }
  this->pCSSData.Owner = 0;
  v8 = (volatile LONG *)(this->OriginalTextValue.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v8 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v8);
  v9 = (Scaleform::RefCountVImpl *)this->pFilters.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v10 = (Scaleform::RefCountVImpl *)this->pDocument.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v11 = this->pDef.pObject;
  if ( v11 )
    Scaleform::GFx::Resource::Release(v11);
  Scaleform::GFx::InteractiveObject::~InteractiveObject(this);
}
