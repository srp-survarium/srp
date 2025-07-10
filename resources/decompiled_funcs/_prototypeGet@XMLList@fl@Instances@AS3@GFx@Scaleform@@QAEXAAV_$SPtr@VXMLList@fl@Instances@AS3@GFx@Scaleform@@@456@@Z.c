void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::prototypeGet(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *Instance; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // esi
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v6; // [esp+8h] [ebp-4h] BYREF

  Instance = Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(this, &v6);
  pV = Instance->pV;
  pObject = result->pObject;
  if ( Instance->pV != result->pObject )
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
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    result->pObject = pV;
  }
}
