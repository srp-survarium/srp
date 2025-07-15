void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3children(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *Instance; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v4; // ebx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // ecx
  unsigned int RefCount; // eax
  unsigned int v8; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v9; // ecx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v10; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::Multiname prop_name; // [esp+10h] [ebp-18h] BYREF

  Instance = Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(this, &v10);
  v4 = result;
  pV = Instance->pV;
  pObject = result->pObject;
  if ( Instance->pV != result->pObject )
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
    v4->pObject = pV;
  }
  Scaleform::GFx::AS3::Multiname::Multiname(&prop_name, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::Instances::fl::XMLList::GetProperty(
    this,
    (Scaleform::GFx::AS3::CheckResult *)&result,
    &prop_name,
    v4->pObject);
  if ( (prop_name.Name.Flags & 0x1F) > 9 )
  {
    if ( (prop_name.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop_name.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_name.Name);
  }
  if ( prop_name.Obj.pObject && ((int)prop_name.Obj.pObject & 1) == 0 )
  {
    v8 = prop_name.Obj.pObject->RefCount;
    v9 = prop_name.Obj.pObject;
    if ( ((unsigned int)&byte_3FFFFF & v8) != 0 )
    {
      prop_name.Obj.pObject->RefCount = v8 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
    }
  }
}
