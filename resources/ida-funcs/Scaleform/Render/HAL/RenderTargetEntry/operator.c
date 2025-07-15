Scaleform::Render::HAL::RenderTargetEntry *__userpurge Scaleform::Render::HAL::RenderTargetEntry::operator=@<eax>(
        const Scaleform::Render::HAL::RenderTargetEntry *__that@<eax>,
        Scaleform::Render::HAL::RenderTargetEntry *this)
{
  Scaleform::Render::RenderTarget *pObject; // ecx

  if ( __that->pRenderTarget.pObject )
    __that->pRenderTarget.pObject->AddRef(__that->pRenderTarget.pObject);
  pObject = this->pRenderTarget.pObject;
  if ( this->pRenderTarget.pObject )
    pObject->Release(pObject);
  this->pRenderTarget.pObject = __that->pRenderTarget.pObject;
  Scaleform::Render::MatrixState::operator=(
    (Scaleform::Render::MatrixState *)pObject,
    &this->OldMatrixState,
    (int)&__that->OldMatrixState);
  Scaleform::Render::Rect<int>::SetRect(&this->OldViewRect, &__that->OldViewRect);
  qmemcpy(&this->OldViewport, &__that->OldViewport, sizeof(this->OldViewport));
  return this;
}
