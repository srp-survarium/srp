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
