void __thiscall Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(
        Scaleform::Render::HAL::RenderTargetEntry *this,
        const Scaleform::Render::HAL::RenderTargetEntry *__that)
{
  if ( __that->pRenderTarget.pObject )
    __that->pRenderTarget.pObject->AddRef(__that->pRenderTarget.pObject);
  this->pRenderTarget.pObject = __that->pRenderTarget.pObject;
  Scaleform::Render::MatrixState::MatrixState(&this->OldMatrixState, &__that->OldMatrixState);
  Scaleform::Render::Rect<int>::SetRect(&this->OldViewRect, &__that->OldViewRect);
  Scaleform::Render::Viewport::Viewport(&this->OldViewport, &__that->OldViewport);
}


void __thiscall Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(
        Scaleform::Render::HAL::RenderTargetEntry *this)
{
  this->pRenderTarget.pObject = 0;
  Scaleform::Render::MatrixState::MatrixState(&this->OldMatrixState);
  this->OldViewRect.x1 = 0;
  this->OldViewRect.y1 = 0;
  this->OldViewRect.x2 = 0;
  this->OldViewRect.y2 = 0;
  Scaleform::Render::Viewport::Viewport(&this->OldViewport);
}
