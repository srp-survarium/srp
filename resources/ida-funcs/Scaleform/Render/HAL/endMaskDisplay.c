void __thiscall Scaleform::Render::HAL::endMaskDisplay(Scaleform::Render::HAL *this)
{
  this->MaskStackTop = 0;
  Scaleform::ArrayData<Scaleform::Render::HAL::MaskStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->MaskStack.Data,
    0);
}
