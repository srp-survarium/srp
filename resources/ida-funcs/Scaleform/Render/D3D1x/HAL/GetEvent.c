Scaleform::Render::D3D1x::RenderEvent *__thiscall Scaleform::Render::D3D1x::HAL::GetEvent(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::EventType eventType)
{
  if ( (_S6_0 & 1) == 0 )
  {
    _S6_0 |= 1u;
    memset32(D3D1xEvents, (int)&Scaleform::Render::D3D1x::RenderEvent::`vftable', 0x16u);
    atexit((int (__cdecl *)())Scaleform::Render::D3D1x::HAL::GetEvent_::_2_::_dynamic_atexit_destructor_for__D3D1xEvents__);
  }
  return &D3D1xEvents[eventType];
}
