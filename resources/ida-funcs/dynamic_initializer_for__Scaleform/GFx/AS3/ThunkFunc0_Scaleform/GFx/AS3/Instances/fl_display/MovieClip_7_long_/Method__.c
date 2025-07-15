void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::MovieClip_7_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *this, int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::MovieClip *, int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::MovieClip::framesLoadedGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,7,long>::Method) = Scaleform::GFx::AS3::Instances::fl_display::MovieClip::framesLoadedGet;
  dword_AAE844 = 0;
  return result;
}
