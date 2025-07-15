char __thiscall Scaleform::Render::HAL::initHAL(
        Scaleform::Render::HAL *this,
        const Scaleform::Render::HALInitParams *params)
{
  void *RenderThreadId; // eax

  this->VMCFlags = params->ConfigFlags;
  RenderThreadId = params->RenderThreadId;
  this->RenderThreadID = RenderThreadId;
  if ( !RenderThreadId )
    this->RenderThreadID = (void *)Scaleform::GetCurrentThreadId();
  return Scaleform::Render::RenderQueue::Initialize(&this->Queue, params->RenderQueueSize);
}
