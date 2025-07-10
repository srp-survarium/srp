char __thiscall Scaleform::Render::HAL::shutdownHAL(Scaleform::Render::HAL *this)
{
  if ( (this->HALState & 1) != 0 )
  {
    Scaleform::Render::HAL::notifyHandlers(this, HAL_Shutdown);
    Scaleform::Render::RenderQueue::Shutdown(&this->Queue);
    this->HALState = 0;
  }
  return 1;
}
