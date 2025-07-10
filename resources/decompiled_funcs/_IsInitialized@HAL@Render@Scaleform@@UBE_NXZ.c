unsigned int __thiscall Scaleform::Render::HAL::IsInitialized(Scaleform::Render::HAL *this)
{
  return this->HALState & 1;
}
