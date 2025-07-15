void __thiscall Scaleform::GFx::AS3::MovieRoot::OnMovieFocus(Scaleform::GFx::AS3::MovieRoot *this, bool set)
{
  Scaleform::GFx::AS3::EventChains *p_mEventChains; // ecx

  p_mEventChains = &this->mEventChains;
  if ( set )
    Scaleform::GFx::AS3::EventChains::Dispatch(p_mEventChains, Event_Activate);
  else
    Scaleform::GFx::AS3::EventChains::Dispatch(p_mEventChains, Event_Deactivate);
}
