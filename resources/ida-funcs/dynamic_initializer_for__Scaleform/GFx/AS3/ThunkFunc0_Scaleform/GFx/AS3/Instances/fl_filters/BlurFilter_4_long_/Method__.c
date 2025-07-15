void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter_4_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this, int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::qualityGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter,4,long>::Method) = Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::qualityGet;
  dword_8F2564 = 0;
  return result;
}
