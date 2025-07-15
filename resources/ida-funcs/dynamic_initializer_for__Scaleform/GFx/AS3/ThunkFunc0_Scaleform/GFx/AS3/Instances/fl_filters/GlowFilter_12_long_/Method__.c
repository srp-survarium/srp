void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter_12_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this, int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::qualityGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,12,long>::Method) = Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::qualityGet;
  dword_8F26A4 = 0;
  return result;
}
