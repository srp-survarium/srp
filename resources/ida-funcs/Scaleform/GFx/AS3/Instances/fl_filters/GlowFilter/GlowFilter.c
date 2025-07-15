void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter::GlowFilter(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::Render::GlowFilter *v3; // eax
  Scaleform::Render::Filter *v4; // eax
  Scaleform::Render::Filter *v5; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  this->FilterData.pObject = 0;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter_vtbl *)&Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter::`vftable';
  v3 = (Scaleform::Render::GlowFilter *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 60, 0);
  if ( v3 )
  {
    Scaleform::Render::GlowFilter::GlowFilter(v3, 6.0, 6.0, 1u);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->FilterData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->FilterData.pObject = v5;
}
