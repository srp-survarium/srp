void __thiscall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *this)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // eax
  unsigned int RefCount; // ecx

  pObject = this->pObject;
  if ( this->pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}
