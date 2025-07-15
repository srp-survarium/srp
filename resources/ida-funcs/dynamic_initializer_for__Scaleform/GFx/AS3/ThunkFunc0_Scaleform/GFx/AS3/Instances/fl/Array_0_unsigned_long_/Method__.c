void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::Array_0_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *this, int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::FrameLabel *, int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::FrameLabel::frameGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,0,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_display::FrameLabel::frameGet;
  dword_8F198C = 0;
  return result;
}
