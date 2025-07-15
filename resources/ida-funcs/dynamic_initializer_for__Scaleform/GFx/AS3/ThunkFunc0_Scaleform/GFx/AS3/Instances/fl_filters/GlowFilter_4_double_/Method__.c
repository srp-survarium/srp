void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter_4_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::blurYGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter,4,double>::Method) = Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::blurYGet;
  dword_8F2724 = 0;
  return result;
}
