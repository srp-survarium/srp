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


void __thiscall Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(
        Scaleform::Render::HAL::RenderTargetEntry *this)
{
  this->pRenderTarget.pObject = 0;
  Scaleform::Render::MatrixState::MatrixState(&this->OldMatrixState);
  this->OldViewRect.x1 = 0;
  this->OldViewRect.y1 = 0;
  this->OldViewRect.x2 = 0;
  this->OldViewRect.y2 = 0;
  this->OldViewport.BufferWidth = 0;
  this->OldViewport.BufferHeight = 0;
  this->OldViewport.Top = 0;
  this->OldViewport.Left = 0;
  this->OldViewport.ScissorHeight = 0;
  this->OldViewport.ScissorWidth = 0;
  this->OldViewport.ScissorTop = 0;
  this->OldViewport.ScissorLeft = 0;
  this->OldViewport.Flags = 0;
  this->OldViewport.Height = 1;
  this->OldViewport.Width = 1;
}
