void __thiscall Scaleform::Render::HAL::RenderTargetEntry::~RenderTargetEntry(
        Scaleform::Render::HAL::RenderTargetEntry *this)
{
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->OldMatrixState);
  if ( this->pRenderTarget.pObject )
    this->pRenderTarget.pObject->Release(this->pRenderTarget.pObject);
}
