void __thiscall Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent::altKeyGet(
        Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *this,
        bool *result)
{
  *result = (this->EvtId.KeysState.States & 4) != 0;
}
