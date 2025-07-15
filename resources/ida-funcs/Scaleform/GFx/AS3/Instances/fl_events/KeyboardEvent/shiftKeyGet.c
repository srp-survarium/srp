void __thiscall Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::shiftKeyGet(
        Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *this,
        bool *result)
{
  *result = this->EvtId.KeysState.States & 1;
}
