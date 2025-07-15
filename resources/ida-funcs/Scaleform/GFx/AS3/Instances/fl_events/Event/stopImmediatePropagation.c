void __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::stopImmediatePropagation(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this,
        const Scaleform::GFx::AS3::Value *result)
{
  *((_BYTE *)this + 48) |= 0x10u;
}
