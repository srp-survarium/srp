void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::shadowColorSet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::Render::BevelFilter_vtbl *value)
{
  Scaleform::Render::BevelFilter *v3; // eax
  unsigned __int8 Alpha; // cl

  v3 = this->GetBevelFilterData(this);
  Alpha = v3->Params.Colors[0].Channels.Alpha;
  v3 = (Scaleform::Render::BevelFilter *)((char *)v3 + 44);
  v3->__vftable = value;
  HIBYTE(v3->__vftable) = Alpha;
}
