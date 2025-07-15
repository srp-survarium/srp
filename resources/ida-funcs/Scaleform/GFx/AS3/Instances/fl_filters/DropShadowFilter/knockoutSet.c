void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::knockoutSet(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  this->FilterData.pObject[1].__vftable = (Scaleform::Render::Filter_vtbl *)((int)this->FilterData.pObject[1].__vftable
                                                                           | (value ? 0x10 : 0));
}
