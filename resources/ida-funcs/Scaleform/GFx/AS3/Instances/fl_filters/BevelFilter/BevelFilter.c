void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::BevelFilter(
        Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::Render::BevelFilter *v3; // eax
  Scaleform::Render::Filter *v4; // eax
  Scaleform::Render::Filter *v5; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Catch *)this, t);
  this->FilterData.pObject = 0;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter_vtbl *)&Scaleform::GFx::AS3::Instances::fl_filters::BevelFilter::`vftable';
  v3 = (Scaleform::Render::BevelFilter *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 60, 0);
  if ( v3 )
  {
    Scaleform::Render::BevelFilter::BevelFilter(v3, 4.0, 4.0, 1u);
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
