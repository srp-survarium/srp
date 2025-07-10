void __thiscall Scaleform::Render::HAL::endMaskDisplay(Scaleform::Render::HAL *this)
{
  this->MaskStackTop = 0;
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::MaskStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::MaskStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    &this->MaskStack.Data,
    &this->MaskStack,
    0);
}
