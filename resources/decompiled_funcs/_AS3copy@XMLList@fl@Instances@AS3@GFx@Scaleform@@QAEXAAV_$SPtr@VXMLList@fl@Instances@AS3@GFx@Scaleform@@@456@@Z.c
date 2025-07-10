void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3copy(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v2; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // esi
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v6; // [esp+8h] [ebp-4h] BYREF

  v2 = Scaleform::GFx::AS3::Instances::fl::XMLList::DeepCopy(this, &v6, 0);
  pV = v2->pV;
  pObject = result->pObject;
  if ( v2->pV != result->pObject )
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
