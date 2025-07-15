void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::ColorMatrixFilter(
        Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::Render::ColorMatrixFilter *v3; // eax
  Scaleform::Render::Filter *v4; // eax
  Scaleform::Render::Filter *v5; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Catch *)this, t);
  this->FilterData.pObject = 0;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter_vtbl *)&Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::`vftable';
  v3 = (Scaleform::Render::ColorMatrixFilter *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 96,
                                                 0);
  if ( v3 )
  {
    Scaleform::Render::ColorMatrixFilter::ColorMatrixFilter(v3);
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
