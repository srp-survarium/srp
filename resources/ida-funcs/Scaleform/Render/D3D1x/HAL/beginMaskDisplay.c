void __thiscall Scaleform::Render::D3D1x::HAL::beginMaskDisplay(Scaleform::Render::D3D1x::HAL *this)
{
  this->HALState &= ~0x40u;
  this->StencilChecked = 0;
  this->StencilAvailable = 0;
  this->DepthBufferAvailable = 0;
}
