void __thiscall Scaleform::Render::Text::DocView::DocView(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Text::Allocator *pallocator,
        Scaleform::GFx::Resource *pfontMgr,
        Scaleform::GFx::Resource *plog)
{
  Scaleform::Render::Text::DocView::DocumentText *v5; // edi
  Scaleform::Render::Text::DocView::DocumentText *pObject; // ecx
  int v7; // [esp+20h] [ebp-4h] BYREF
  float pfontMgra; // [esp+2Ch] [ebp+8h]

  this->__vftable = (Scaleform::Render::Text::DocView_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::Text::DocView_vtbl *)&Scaleform::Render::Text::DocView::`vftable';
  this->pDocument.pObject = 0;
  if ( pfontMgr )
    Scaleform::RefCountImpl::AddRef(pfontMgr);
  this->pFontManager.pObject = (Scaleform::Render::Text::FontManagerBase *)pfontMgr;
  this->pDocumentListener.pObject = 0;
  this->pHighlight = 0;
  Scaleform::Render::Text::LineBuffer::LineBuffer(&this->mLineBuffer);
  this->ViewRect.x1 = 0.0;
  this->ViewRect.y1 = 0.0;
  this->ViewRect.x2 = 0.0;
  this->ViewRect.y2 = 0.0;
  this->MaxVScroll.FormatCounter = 0;
  this->pEditorKit.pObject = 0;
  Scaleform::Render::Text::TextFilter::TextFilter(&this->Filter);
  if ( plog )
    Scaleform::RefCountImpl::AddRef(plog);
  this->pLog.pObject = (Scaleform::Log *)plog;
  this->BorderColor = 0;
  this->BackgroundColor = 0;
  v7 = 78;
  v5 = (Scaleform::Render::Text::DocView::DocumentText *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this,
                                                           40,
                                                           &v7);
  if ( v5 )
  {
    Scaleform::Render::Text::StyledText::StyledText(v5, pallocator);
    v5->__vftable = (Scaleform::Render::Text::DocView::DocumentText_vtbl *)&Scaleform::Render::Text::DocView::DocumentText::`vftable';
    v5->pDocument = this;
  }
  else
  {
    v5 = 0;
  }
  pObject = this->pDocument.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pDocument.pObject = v5;
  this->AlignProps &= 0xC0u;
  this->Outline = 0.0;
  this->FormatCounter = 1;
  this->EndSelection = -1;
  this->BeginSelection = -1;
  this->RTFlags = 0;
  this->FlagsEx = 0;
  this->Flags = 0;
  this->ViewRect.x1 = 0.0;
  this->ViewRect.y1 = 0.0;
  pfontMgra = 0.0 + 0.0;
  this->ViewRect.x2 = pfontMgra;
  this->ViewRect.y2 = pfontMgra;
  this->pImageSubstitutor = 0;
  Scaleform::Render::Text::DocView::SetFontScaleFactor(this, 1.0);
  this->Flags |= 0x80u;
  this->MaxLength = 0;
  Scaleform::Render::Text::TextFilter::SetDefaultShadow(&this->Filter);
  this->TextHeight = 0;
  this->TextWidth = 0;
}
