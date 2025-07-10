void __thiscall Scaleform::GFx::DrawingContext::~DrawingContext(Scaleform::GFx::DrawingContext *this)
{
  bool v2; // zf
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::Render::TreeContainer *v8; // ecx

  v2 = this->pPrev == 0;
  this->__vftable = (Scaleform::GFx::DrawingContext_vtbl *)&Scaleform::GFx::DrawingContext::`vftable';
  if ( !v2 && this->pNext )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
  }
  pObject = (Scaleform::RefCountVImpl *)this->mLineStyle.pDashes.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->mLineStyle.pFill.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::RefCountVImpl *)this->mFillStyle.pFill.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::RefCountVImpl *)this->Shapes.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v7 = (Scaleform::RefCountVImpl *)this->ImgCreator.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = this->pTreeContainer.pObject;
  if ( v8 )
  {
    v2 = v8->RefCount-- == 1;
    if ( v2 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
  }
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}
