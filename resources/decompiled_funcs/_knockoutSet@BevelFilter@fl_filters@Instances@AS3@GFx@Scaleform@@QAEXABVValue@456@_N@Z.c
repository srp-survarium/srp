void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::knockoutSet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::Render::BevelFilter *v3; // eax

  v3 = this->GetBevelFilterData(this);
  v3->Params.Mode |= value ? 0x10 : 0;
}
