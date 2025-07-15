void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter_2_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::blurXGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,2,double>::Method) = Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::blurXGet;
  dword_AADEFC = 0;
  return result;
}
