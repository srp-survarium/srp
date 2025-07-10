void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3attributes(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // ebp
  unsigned int RefCount; // eax
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v8; // ecx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> list; // [esp+10h] [ebp-4h] BYREF

  Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(this, &list);
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
  Size = this->List.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    v8 = this->List.Data.Data[i].pObject;
    v8->GetAttributes(v8, pV);
  }
}
