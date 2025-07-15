void __thiscall Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::altKeySet(
        Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  if ( value )
    this->EvtId.KeysState.States |= 4u;
  else
    this->EvtId.KeysState.States &= ~4u;
}
