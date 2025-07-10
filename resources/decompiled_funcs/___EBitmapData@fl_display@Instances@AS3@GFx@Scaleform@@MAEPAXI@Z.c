Scaleform::GFx::AS3::Instances::fl_display::BitmapData *__thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        char a2)
{
  Scaleform::GFx::MovieDefImpl *pObject; // ecx
  Scaleform::Render::ImageBase *v4; // ecx
  Scaleform::GFx::ImageResource *v5; // ecx

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData_vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::BitmapData::`vftable';
  pObject = this->pDefImpl.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  v4 = this->pImage.pObject;
  if ( v4 )
    v4->Release(v4);
  v5 = this->pImageResource.pObject;
  if ( v5 )
    Scaleform::GFx::Resource::Release(v5);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
