void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3text(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // ebx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> list; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::GFx::AS3::Instances::fl::XML::MakeXMLListInstance(this, &list);
  pObject = result->pObject;
  pV = list.pV;
  if ( list.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = pV;
  }
  this->GetChildren(this, pV, kText, 0);
}
