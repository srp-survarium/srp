void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::highlightColorGet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        unsigned int *result)
{
  *result = (unsigned int)&vostok::memory::s_CRT_arena[5574199] & this->GetBevelFilterData(this)->Params.Colors[1].Raw;
}
