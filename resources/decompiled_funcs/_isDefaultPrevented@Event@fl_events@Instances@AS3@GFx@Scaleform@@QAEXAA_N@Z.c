void __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::isDefaultPrevented(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this,
        bool *result)
{
  *result = (*((_BYTE *)this + 48) & 4) != 0;
}
