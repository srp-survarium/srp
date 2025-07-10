void __thiscall Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(
        Scaleform::Render::HAL::RenderTargetEntry *this,
        const Scaleform::Render::HAL::RenderTargetEntry *__that)
{
  int y2; // eax
  int x2; // ecx
  int y1; // edx

  if ( __that->pRenderTarget.pObject )
    __that->pRenderTarget.pObject->AddRef(__that->pRenderTarget.pObject);
  this->pRenderTarget.pObject = __that->pRenderTarget.pObject;
  Scaleform::Render::MatrixState::MatrixState(&this->OldMatrixState, &__that->OldMatrixState);
  y2 = __that->OldViewRect.y2;
  x2 = __that->OldViewRect.x2;
  y1 = __that->OldViewRect.y1;
  this->OldViewRect.x1 = __that->OldViewRect.x1;
  this->OldViewRect.y2 = y2;
  this->OldViewRect.y1 = y1;
  this->OldViewRect.x2 = x2;
  this->OldViewport = __that->OldViewport;
}
