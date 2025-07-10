void __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::bubblesGet(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this,
        bool *result)
{
  *result = *((_BYTE *)this + 48) & 1;
}
