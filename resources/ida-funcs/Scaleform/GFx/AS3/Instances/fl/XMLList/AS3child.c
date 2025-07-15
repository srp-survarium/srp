void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3child(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Value *propertyName)
{
  const Scaleform::GFx::AS3::Value *v3; // ebx
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v8; // ebp
  unsigned int RefCount; // eax
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v12; // ecx
  unsigned int v13; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v14; // ecx
  Scaleform::StringDataPtr v15; // [esp-8h] [ebp-38h]
  Scaleform::GFx::AS3::VM::Error v16; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+18h] [ebp-18h] BYREF

  v3 = propertyName;
  if ( (propertyName->Flags & 0x1F) != 0 && ((propertyName->Flags & 0x1F) - 12 > 3 || propertyName->value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(
      this,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&propertyName);
    pObject = result->pObject;
    v8 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)propertyName;
    if ( propertyName != (Scaleform::GFx::AS3::Value *)result->pObject )
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
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
          }
        }
      }
      result->pObject = v8;
    }
    Scaleform::GFx::AS3::Multiname::Multiname(&mn, this->pTraits.pObject->pVM->PublicNamespace.pObject, v3);
    Size = this->List.Data.Size;
    for ( i = 0; i < Size; ++i )
    {
      v12 = this->List.Data.Data[i].pObject;
      v12->GetChildren(v12, v8, &mn);
    }
    if ( (mn.Name.Flags & 0x1F) > 9 )
    {
      if ( (mn.Name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&mn.Name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
    if ( mn.Obj.pObject )
    {
      if ( ((int)mn.Obj.pObject & 1) == 0 )
      {
        v13 = mn.Obj.pObject->RefCount;
        v14 = mn.Obj.pObject;
        if ( (v13 & 0x3FFFFF) != 0 )
        {
          mn.Obj.pObject->RefCount = v13 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
        }
      }
    }
  }
  else
  {
    v15.pStr = "propertyName";
    v15.Size = 12;
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eInvalidArgumentError, this->pTraits.pObject->pVM, v15);
    Scaleform::GFx::AS3::VM::ThrowTypeError(this->pTraits.pObject->pVM, v5);
    pNode = v16.Message.pNode;
    --v16.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
