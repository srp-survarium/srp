Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *__thiscall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>::operator=(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // ecx
  unsigned int RefCount; // eax

  pObject = this->pObject;
  if ( v.pV != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
        this->pObject = v.pV;
        return this;
      }
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->pObject = v.pV;
  }
  return this;
}
