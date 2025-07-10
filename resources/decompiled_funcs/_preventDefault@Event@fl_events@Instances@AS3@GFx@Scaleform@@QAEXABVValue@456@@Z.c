void __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::preventDefault(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this,
        const Scaleform::GFx::AS3::Value *result)
{
  char v2; // al

  v2 = *((_BYTE *)this + 48);
  if ( (v2 & 2) != 0 )
    *((_BYTE *)this + 48) = v2 | 4;
}
