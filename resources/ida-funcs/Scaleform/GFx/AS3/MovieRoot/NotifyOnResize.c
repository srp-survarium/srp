void __thiscall Scaleform::GFx::AS3::MovieRoot::NotifyOnResize(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::EventChains::QueueEvents(
    &this->mEventChains,
    (Scaleform::GFx::EventId::IdCode)&s_ui_commands_allocator.m_buffer[2035380]);
}
