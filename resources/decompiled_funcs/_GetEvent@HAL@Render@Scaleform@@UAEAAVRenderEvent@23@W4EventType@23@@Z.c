Scaleform::Render::RenderEvent *__thiscall Scaleform::Render::HAL::GetEvent(
        Scaleform::Render::HAL *this,
        Scaleform::Render::EventType __formal)
{
  if ( (`Scaleform::Render::HAL::GetEvent'::`2'::`local static guard' & 1) == 0 )
  {
    `Scaleform::Render::HAL::GetEvent'::`2'::`local static guard' |= 1u;
    `Scaleform::Render::HAL::GetEvent'::`2'::defaultEvent.__vftable = (Scaleform::Render::RenderEvent_vtbl *)&Scaleform::Render::RenderEvent::`vftable';
    atexit(`Scaleform::Render::HAL::GetEvent'::`2'::`dynamic atexit destructor for 'defaultEvent'');
  }
  return &`Scaleform::Render::HAL::GetEvent'::`2'::defaultEvent;
}
