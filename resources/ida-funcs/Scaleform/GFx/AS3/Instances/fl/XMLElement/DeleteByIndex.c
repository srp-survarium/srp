void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeleteByIndex(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        unsigned int ind)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // esi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_Children; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // ecx
  unsigned int RefCount; // eax

  if ( ind < this->Children.Data.Size )
  {
    pObject = this->Children.Data.Data[ind].pObject;
    p_Children = &this->Children;
    if ( pObject )
    {
      v4 = pObject->Parent.pObject;
      if ( v4 )
      {
        if ( ((unsigned __int8)v4 & 1) != 0 )
        {
          pObject->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v4 - 1);
        }
        else
        {
          RefCount = v4->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v4->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
          }
        }
        pObject->Parent.pObject = 0;
      }
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)p_Children,
      ind);
  }
}
