void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3descendants(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Object *argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  char v4; // bl
  const Scaleform::GFx::AS3::Value *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v8; // edi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // ecx
  Scaleform::GFx::AS3::Value v11; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+20h] [ebp-18h] BYREF

  v4 = 0;
  if ( argc )
  {
    v6 = argv;
  }
  else
  {
    v4 = 3;
    argc = (Scaleform::GFx::AS3::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                            this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                                            "*",
                                            1u,
                                            0);
    ++argc->pPrev;
    Scaleform::GFx::AS3::Value::Value(&v11, (const Scaleform::GFx::ASString *)&argc);
  }
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, this->pTraits.pObject->pVM->PublicNamespace.pObject, v6);
  if ( (v4 & 2) != 0 )
  {
    v4 &= ~2u;
    if ( (v11.Flags & 0x1F) > 9 )
    {
      if ( (v11.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v11);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
    }
  }
  if ( (v4 & 1) != 0 )
  {
    v7 = (Scaleform::GFx::ASStringNode *)argc;
    --argc->pPrev;
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(
    this,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&argc);
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)argc;
  Scaleform::GFx::AS3::Value::Pick(result, argc);
  Scaleform::GFx::AS3::Instances::fl::XMLList::GetDescendants(this, v8, &mn);
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
    pObject = mn.Obj.pObject;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      mn.Obj.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
