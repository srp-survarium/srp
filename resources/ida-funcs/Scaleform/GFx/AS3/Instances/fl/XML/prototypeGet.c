void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::prototypeGet(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *XMLListInstance; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // esi
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v6; // [esp+8h] [ebp-4h] BYREF

  XMLListInstance = Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(this, &v6);
  pV = XMLListInstance->pV;
  pObject = result->pObject;
  if ( XMLListInstance->pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
        result->pObject = pV;
        return;
      }
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    result->pObject = pV;
  }
}
