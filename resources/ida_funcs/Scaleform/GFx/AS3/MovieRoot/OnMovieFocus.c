void __thiscall Scaleform::GFx::AS3::MovieRoot::OnMovieFocus(Scaleform::GFx::AS3::MovieRoot *this, bool set)
{
  Scaleform::GFx::AS3::EventChains *p_mEventChains; // ecx

  p_mEventChains = &this->mEventChains;
  if ( set )
    Scaleform::GFx::AS3::EventChains::Dispatch(
      p_mEventChains,
      (Scaleform::GFx::EventId::IdCode)&vostok::memory::s_CRT_arena[5574217]);
  else
    Scaleform::GFx::AS3::EventChains::Dispatch(
      p_mEventChains,
      (Scaleform::GFx::EventId::IdCode)&vostok::memory::s_CRT_arena[5574218]);
}
