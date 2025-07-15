Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *__thiscall Scaleform::GFx::AS3::Instances::fl_filters::BitmapFilter::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_filters::GlowFilter *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->FilterData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
