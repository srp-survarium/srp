void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::BlurFilter(
        Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::Render::BlurFilterImpl *v3; // eax
  Scaleform::Render::BlurFilterImpl *v4; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  this->FilterData.pObject = 0;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter_vtbl *)&Scaleform::GFx::AS3::Instances::fl_filters::BlurFilter::`vftable';
  v3 = (Scaleform::Render::BlurFilterImpl *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 60, 0);
  v4 = v3;
  if ( v3 )
  {
    Scaleform::Render::BlurFilterImpl::BlurFilterImpl(v3, Filter_Blur);
    v4->Params.BlurX = 80.0;
    v4->__vftable = (Scaleform::Render::BlurFilterImpl_vtbl *)&Scaleform::Render::BlurFilter::`vftable';
    v4->Params.BlurY = 80.0;
    v4->Params.Passes = 1;
  }
  else
  {
    v4 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->FilterData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->FilterData.pObject = v4;
}
