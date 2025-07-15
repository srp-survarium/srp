void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::DropShadowFilter(
        Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::Render::ShadowFilter *v3; // eax
  Scaleform::Render::Filter *v4; // eax
  Scaleform::Render::Filter *v5; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  this->FilterData.pObject = 0;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter_vtbl *)&Scaleform::GFx::AS3::Instances::fl_filters::DropShadowFilter::`vftable';
  v3 = (Scaleform::Render::ShadowFilter *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 60, 0);
  if ( v3 )
  {
    Scaleform::Render::ShadowFilter::ShadowFilter(v3, 0.78539819, 4.0, 4.0, 4.0, 1u);
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
