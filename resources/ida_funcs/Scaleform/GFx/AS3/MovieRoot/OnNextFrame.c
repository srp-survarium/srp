void __thiscall Scaleform::GFx::AS3::MovieRoot::OnNextFrame(Scaleform::GFx::AS3::MovieRoot *this)
{
  Scaleform::GFx::AS3::EventChains::QueueEvents(&this->mEventChains, Event_EnterFrame);
}
