void __thiscall Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::~AttrGetFirst(
        Scaleform::GFx::AS3::Instances::fl::AttrGetFirst *this)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  unsigned int RefCount; // eax

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::AttrGetFirst_vtbl *)&Scaleform::GFx::AS3::Instances::fl::AttrGetFirst::`vftable';
  pObject = this->First.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->First.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
      this->__vftable = (Scaleform::GFx::AS3::Instances::fl::AttrGetFirst_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      return;
    }
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::AttrGetFirst_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
}
