void __userpurge Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::shadowAlphaSet(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this@<ecx>,
        int a2@<ebx>,
        const Scaleform::GFx::AS3::Value *result,
        long double value)
{
  *(_BYTE *)(((int (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *, int, int))this->GetBevelFilterData)(
               this,
               a2,
               (int)(value * 255.0))
           + 47) = (int)(value * 255.0);
}
