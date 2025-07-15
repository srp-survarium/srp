void __thiscall Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::buttonDownGet(
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *this,
        bool *result)
{
  *result = this->ButtonsMask & 1;
}
