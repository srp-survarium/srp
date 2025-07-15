void __thiscall Scaleform::Render::HAL::destroyRenderBuffers(Scaleform::Render::HAL *this)
{
  Scaleform::ArrayData<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->RenderTargetStack.Data,
    0);
}
