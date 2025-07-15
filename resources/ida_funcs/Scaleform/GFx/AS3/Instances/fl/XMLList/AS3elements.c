void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3elements(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  char v4; // bl
  Scaleform::GFx::AS3::Instances::fl::XMLList *pV; // ebp
  const Scaleform::GFx::AS3::Value *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v13; // ecx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> list; // [esp+10h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::Value v15; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+24h] [ebp-18h] BYREF

  v4 = 0;
  list.pV = 0;
  Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(this, &list);
  pV = list.pV;
  Scaleform::GFx::AS3::Value::Pick(result, list.pV);
  if ( argc )
  {
    v7 = argv;
  }
  else
  {
    v4 = 3;
    result = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                             this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                                             "*",
                                             1u,
                                             0);
    ++result->value.VS._2.VObj;
    Scaleform::GFx::AS3::Value::Value(&v15, (const Scaleform::GFx::ASString *)&result);
  }
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, this->pTraits.pObject->pVM->PublicNamespace.pObject, v7);
  if ( (v4 & 2) != 0 )
  {
    v4 &= ~2u;
    if ( (v15.Flags & 0x1F) > 9 )
    {
      if ( (v15.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v15);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
    }
  }
  if ( (v4 & 1) != 0 )
  {
    v8 = (Scaleform::GFx::ASStringNode *)result;
    --result->value.VS._2.VObj;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  Size = this->List.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    pObject = this->List.Data.Data[i].pObject;
    pObject->GetChildren(pObject, pV, &mn);
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&mn.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
  }
  if ( mn.Obj.pObject && ((int)mn.Obj.pObject & 1) == 0 )
  {
    RefCount = mn.Obj.pObject->RefCount;
    v13 = mn.Obj.pObject;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      mn.Obj.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
    }
  }
}
