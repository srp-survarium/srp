Scaleform::Render::HAL::RenderTargetEntry *__thiscall Scaleform::Render::HAL::RenderTargetEntry::operator=(
        Scaleform::Render::HAL::RenderTargetEntry *this,
        const Scaleform::Render::HAL::RenderTargetEntry *__that,
        const Scaleform::Render::HAL::RenderTargetEntry *__thata)
{
  int x2; // ecx
  int x1; // esi
  int y1; // edx

  if ( __thata->pRenderTarget.pObject )
    __thata->pRenderTarget.pObject->AddRef(__thata->pRenderTarget.pObject);
  if ( __that->pRenderTarget.pObject )
    __that->pRenderTarget.pObject->Release(__that->pRenderTarget.pObject);
  __that->pRenderTarget.pObject = __thata->pRenderTarget.pObject;
  Scaleform::Render::MatrixState::operator=(&__that->OldMatrixState, &__thata->OldMatrixState);
  x2 = __thata->OldViewRect.x2;
  x1 = __thata->OldViewRect.x1;
  y1 = __thata->OldViewRect.y1;
  __that->OldViewRect.y2 = __thata->OldViewRect.y2;
  __that->OldViewRect.x1 = x1;
  __that->OldViewRect.y1 = y1;
  __that->OldViewRect.x2 = x2;
  __that->OldViewport = __thata->OldViewport;
  return (Scaleform::Render::HAL::RenderTargetEntry *)__that;
}
