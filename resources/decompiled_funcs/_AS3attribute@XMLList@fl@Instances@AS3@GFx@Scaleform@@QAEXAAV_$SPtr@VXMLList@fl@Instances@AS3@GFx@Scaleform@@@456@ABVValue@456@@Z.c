void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3attribute(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result,
        const Scaleform::GFx::AS3::Value *arg)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *Instance; // eax
  unsigned int Size; // ebp
  int v9; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v12; // ecx
  Scaleform::GFx::AS3::VM::Error v13; // [esp+8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Multiname prop_name; // [esp+10h] [ebp-18h] BYREF

  pVM = this->pTraits.pObject->pVM;
  if ( (arg->Flags & 0x1F) == 0 || (arg->Flags & 0x1F) - 12 <= 3 && !arg->value.VS._1.VInt )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eInvalidArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v13.Message.pNode;
    --v13.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  Scaleform::GFx::AS3::Multiname::Multiname(&prop_name, pVM, arg);
  prop_name.Kind |= 8u;
  if ( pVM->HandleException )
  {
LABEL_7:
    Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
    return;
  }
  Instance = Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(
               this,
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&arg,
               (Scaleform::GFx::AS3::SoundObject *)&prop_name);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>::operator=(
    result,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)Instance->pV);
  Size = this->List.Data.Size;
  v9 = 0;
  if ( Size )
  {
    do
    {
      pObject = this->List.Data.Data[v9].pObject;
      if ( !pObject->GetProperty(pObject, (Scaleform::GFx::AS3::CheckResult *)&arg, &prop_name, result->pObject)->Result )
        goto LABEL_7;
    }
    while ( ++v9 < Size );
  }
  if ( (prop_name.Name.Flags & 0x1F) > 9 )
  {
    if ( (prop_name.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop_name.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_name.Name);
  }
  if ( prop_name.Obj.pObject )
  {
    if ( ((int)prop_name.Obj.pObject & 1) == 0 )
    {
      RefCount = prop_name.Obj.pObject->RefCount;
      v12 = prop_name.Obj.pObject;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        prop_name.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
      }
    }
  }
}
