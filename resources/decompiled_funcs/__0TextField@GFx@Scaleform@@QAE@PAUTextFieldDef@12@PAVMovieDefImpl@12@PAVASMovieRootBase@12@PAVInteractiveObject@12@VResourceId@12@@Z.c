void __thiscall Scaleform::GFx::TextField::TextField(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::TextFieldDef *def,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *parent,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::RefCountVImpl *v7; // eax
  Scaleform::GFx::MovieDefImpl *v8; // eax
  Scaleform::GFx::ASMovieRootBase *v9; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  Scaleform::GFx::ASMovieRootBase *TextAllocator; // eax
  Scaleform::GFx::FontManager *FontManager; // ebp
  Scaleform::Render::Text::DocView *v13; // ebx
  Scaleform::GFx::Resource *Log; // eax
  Scaleform::Render::Text::DocView *v15; // eax
  Scaleform::Render::Text::DocView *v16; // ebx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountNTSImpl **p_pObject; // ebp
  Scaleform::Render::Text::DocView *v19; // eax
  Scaleform::Render::TreeText *RenderNode; // eax
  Scaleform::Render::Text::DocView *v21; // edx
  Scaleform::Render::TreeText *v22; // eax
  signed int MaxLength; // eax
  Scaleform::Render::Text::DocView *v24; // eax
  unsigned __int16 Flags; // ax
  Scaleform::Render::Text::EditorKitBase *v27; // ecx
  bool v28; // al
  Scaleform::RefCountNTSImpl *v29; // ecx

  Scaleform::GFx::InteractiveObject::InteractiveObject(this, pbindingDefImpl, pasRoot, parent, id);
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::TextField_vtbl *)&Scaleform::GFx::TextField::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::TextField::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( def )
    Scaleform::RefCountImpl::AddRef(def);
  this->pDef.pObject = def;
  this->pDocument.pObject = 0;
  this->pFilters.pObject = 0;
  Scaleform::StringLH::StringLH(&this->OriginalTextValue);
  this->pCSSData.pObject = 0;
  this->pCSSData.Owner = 1;
  this->TextDocListener.RefCount = 1;
  this->TextDocListener.HandlersMask = 14;
  this->TextDocListener.__vftable = (Scaleform::GFx::TextField::TextDocumentListener_vtbl *)&Scaleform::GFx::TextField::TextDocumentListener::`vftable';
  v7 = (Scaleform::RefCountVImpl *)this->pASRoot->pMovieImpl->GetStateAddRef(
                                     &this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
                                     1);
  if ( v7 )
  {
    if ( v7[1].RefCount )
      this->TextDocListener.HandlersMask |= 1u;
    Scaleform::RefCountImpl::Release(v7);
  }
  v8 = pbindingDefImpl;
  this->pImageDescAssoc = 0;
  if ( v8 )
    this->pBinding = &v8->pBindData.pObject->ResourceBinding;
  else
    this->pBinding = 0;
  this->Flags = 0;
  this->FocusedControllerIdx = -1;
  this->Alignment = def->Alignment;
  this->Flags = 4 * ((LOBYTE(def->Flags) >> 2) & 1);
  if ( SLOBYTE(def->Flags) >= 0 )
    this->Flags &= ~2u;
  else
    this->Flags |= 2u;
  v9 = pasRoot;
  this->Flags |= 0x80u;
  this->pShadow = 0;
  pMovieImpl = v9->pMovieImpl;
  TextAllocator = (Scaleform::GFx::ASMovieRootBase *)Scaleform::GFx::MovieImpl::GetTextAllocator(pMovieImpl);
  pasRoot = TextAllocator;
  if ( TextAllocator )
    ++TextAllocator->RefCount;
  FontManager = Scaleform::GFx::MovieImpl::FindFontManager(pMovieImpl, pbindingDefImpl);
  if ( !FontManager && (!parent || (FontManager = parent->GetFontManager(parent)) == 0) )
    FontManager = Scaleform::GFx::MovieImpl::FindFontManager(pMovieImpl, 0);
  v13 = (Scaleform::Render::Text::DocView *)pMovieImpl->pHeap->Alloc(pMovieImpl->pHeap, 272u, 0);
  if ( v13 )
  {
    Log = (Scaleform::GFx::Resource *)Scaleform::GFx::DisplayObjectBase::GetLog(this);
    Scaleform::Render::Text::DocView::DocView(
      v13,
      (Scaleform::Render::Text::Allocator *)pasRoot,
      (Scaleform::GFx::Resource *)FontManager,
      Log);
    v16 = v15;
  }
  else
  {
    v16 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pDocument.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  p_pObject = &v16->pDocumentListener.pObject;
  this->pDocument.pObject = v16;
  if ( this != (Scaleform::GFx::TextField *)-172 )
    ++this->TextDocListener.RefCount;
  if ( *p_pObject )
    Scaleform::RefCountNTSImpl::Release(*p_pObject);
  *p_pObject = &this->TextDocListener;
  this->pDocument.pObject->pDocument.pObject->RTFlags |= 2u;
  if ( (def->Flags & 0x40) != 0 )
  {
    v19 = this->pDocument.pObject;
    *(_WORD *)((char *)&pbindingDefImpl + 1) = -1;
    LOBYTE(pbindingDefImpl) = -1;
    HIBYTE(pbindingDefImpl) = -1;
    v19->BackgroundColor = (unsigned int)pbindingDefImpl;
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
    v21 = this->pDocument.pObject;
    *(_WORD *)((char *)&pbindingDefImpl + 1) = 0;
    LOBYTE(pbindingDefImpl) = 0;
    HIBYTE(pbindingDefImpl) = -1;
    v21->BorderColor = (unsigned int)pbindingDefImpl;
    v22 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(v22);
  }
  Scaleform::GFx::TextField::SetInitialFormatsAsDefault(this);
  MaxLength = def->MaxLength;
  if ( MaxLength > 0 )
    this->pDocument.pObject->MaxLength = MaxLength;
  Scaleform::Render::Text::DocView::SetViewRect(this->pDocument.pObject, &def->TextRect, UseExternally);
  if ( (def->Flags & 0x100) != 0 )
  {
    this->pDocument.pObject->Flags |= 0x20u;
    this->pDocument.pObject->Flags |= 0x40u;
  }
  v24 = this->pDocument.pObject;
  if ( (def->Flags & 2) != 0 )
    v24->Flags |= 4u;
  else
    v24->Flags &= ~4u;
  Flags = def->Flags;
  LOBYTE(v16) = (Flags & 0x10) != 0;
  if ( (Flags & 0x10) != 0 && ((def->Flags & 1) == 0 || (Flags & 2) == 0) )
    Scaleform::Render::Text::DocView::SetAutoSizeX(this->pDocument.pObject);
  if ( (_BYTE)v16 )
    Scaleform::Render::Text::DocView::SetAutoSizeY(this->pDocument.pObject);
  if ( (def->Flags & 1) != 0 )
    Scaleform::Render::Text::DocView::SetWordWrap(this->pDocument.pObject);
  if ( (this->Flags & 4) != 0 )
    this->pDocument.pObject->Flags |= 0x10u;
  if ( (def->Flags & 0x400) != 0 )
    this->pDocument.pObject->Flags |= 0x40u;
  v27 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v27 )
    v28 = v27->IsReadOnly(v27);
  else
    v28 = (this->pDef.pObject->Flags & 8) != 0;
  if ( !v28 || (def->Flags & 0x20) != 0 )
  {
    Scaleform::GFx::TextField::CreateEditorKit(this, (int)v16, (int)&pbindingDefImpl);
    if ( pbindingDefImpl )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pbindingDefImpl);
  }
  v29 = (Scaleform::RefCountNTSImpl *)pasRoot;
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
  if ( v29 )
    Scaleform::RefCountNTSImpl::Release(v29);
}
