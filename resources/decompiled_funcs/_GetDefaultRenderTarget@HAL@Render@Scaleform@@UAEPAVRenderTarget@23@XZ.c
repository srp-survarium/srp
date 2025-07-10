Scaleform::Render::RenderTarget *__thiscall Scaleform::Render::HAL::GetDefaultRenderTarget(
        Scaleform::Render::HAL *this)
{
  if ( this->RenderTargetStack.Data.Size )
    return this->RenderTargetStack.Data.Data->pRenderTarget.pObject;
  else
    return 0;
}
