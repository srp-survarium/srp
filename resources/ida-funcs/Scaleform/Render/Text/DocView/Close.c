void __thiscall Scaleform::Render::Text::DocView::Close(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // ecx
  Scaleform::Render::Text::DocView::DocumentListener *v3; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  if ( this->pDocument.pObject )
  {
    pObject = this->pDocument.pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    this->pDocument.pObject = 0;
    v3 = this->pDocumentListener.pObject;
    if ( v3 )
      Scaleform::RefCountNTSImpl::Release(v3);
    this->pDocumentListener.pObject = 0;
    v4 = (Scaleform::RefCountVImpl *)this->pEditorKit.pObject;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
    this->pEditorKit.pObject = 0;
    this->mLineBuffer.Geom.Flags |= 1u;
    Scaleform::Render::Text::LineBuffer::RemoveLines(&this->mLineBuffer, 0, this->mLineBuffer.Lines.Data.Size);
  }
}
