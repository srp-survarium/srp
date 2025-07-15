void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3child(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        Scaleform::GFx::AS3::Value *propertyName)
{
  const Scaleform::GFx::AS3::Value *v3; // ebx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v9; // ebp
  unsigned int RefCount; // eax
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v13; // ecx
  unsigned int v14; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v15; // ecx
  Scaleform::GFx::AS3::VM::Error v16; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+14h] [ebp-18h] BYREF

  v3 = propertyName;
  if ( (propertyName->Flags & 0x1F) != 0 && ((propertyName->Flags & 0x1F) - 12 > 3 || propertyName->value.VS._1.VInt) )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(
      this,
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&propertyName);
    pObject = result->pObject;
    v9 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)propertyName;
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
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
          }
        }
      }
      result->pObject = v9;
    }
    Scaleform::GFx::AS3::Multiname::Multiname(&mn, this->pTraits.pObject->pVM->PublicNamespace.pObject, v3);
    Size = this->List.Data.Size;
    for ( i = 0; i < Size; ++i )
    {
      v13 = this->List.Data.Data[i].pObject;
      v13->GetChildren(v13, v9, &mn);
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
        v14 = mn.Obj.pObject->RefCount;
        v15 = mn.Obj.pObject;
        if ( ((unsigned int)&byte_3FFFFF & v14) != 0 )
        {
          mn.Obj.pObject->RefCount = v14 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
        }
      }
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eInvalidArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v6);
    pNode = v16.Message.pNode;
    --v16.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
