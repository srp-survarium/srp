void __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener::Listener(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *this,
        const Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *__that)
{
  Scaleform::GFx::AS3::Value *p_mFunction; // ecx
  unsigned int Flags; // eax

  this->Priority = __that->Priority;
  p_mFunction = &__that->mFunction;
  this->mFunction = __that->mFunction;
  Flags = __that->mFunction.Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(p_mFunction);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(p_mFunction);
  }
}
