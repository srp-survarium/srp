void __thiscall Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::~ChildGetFirst(
        Scaleform::GFx::AS3::Instances::fl::ChildGetFirst *this)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  unsigned int RefCount; // eax

  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::ChildGetFirst_vtbl *)&Scaleform::GFx::AS3::Instances::fl::ChildGetFirst::`vftable';
  pObject = this->First.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->First.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
      this->__vftable = (Scaleform::GFx::AS3::Instances::fl::ChildGetFirst_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      return;
    }
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::ChildGetFirst_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
}
