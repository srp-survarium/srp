void __thiscall Scaleform::Render::Text::DocView::~DocView(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::ImageSubstitutor *pImageSubstitutor; // edi
  Scaleform::Render::Text::DocView::HighlightDescLoc *pHighlight; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::Render::Text::DocView::DocumentListener *v6; // ecx
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::Render::Text::DocView::DocumentText *v8; // ecx

  this->__vftable = (Scaleform::Render::Text::DocView_vtbl *)&Scaleform::Render::Text::DocView::`vftable';
  Scaleform::Render::Text::DocView::Close(this);
  pImageSubstitutor = this->pImageSubstitutor;
  if ( pImageSubstitutor )
  {
    Scaleform::ConstructorMov<Scaleform::Render::Text::DocView::ImageSubstitutor::Element>::DestructArray(
      pImageSubstitutor->Elements.Data.Data,
      pImageSubstitutor->Elements.Data.Size);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pImageSubstitutor->Elements.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pImageSubstitutor);
  }
  pHighlight = this->pHighlight;
  this->pImageSubstitutor = 0;
  if ( pHighlight )
  {
    Scaleform::Memory::pGlobalHeap->Free(
      Scaleform::Memory::pGlobalHeap,
      pHighlight->HighlightManager.Highlighters.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pHighlight);
  }
  pObject = (Scaleform::RefCountVImpl *)this->pLog.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&this->Filter);
  v5 = (Scaleform::RefCountVImpl *)this->pEditorKit.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  Scaleform::Render::Text::LineBuffer::~LineBuffer(&this->mLineBuffer);
  v6 = this->pDocumentListener.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  v7 = (Scaleform::RefCountVImpl *)this->pFontManager.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = this->pDocument.pObject;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
