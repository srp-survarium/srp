void __thiscall Scaleform::GFx::AS3::Instances::CheckTypeTF::Execute(
        Scaleform::GFx::AS3::Instances::CheckTypeTF *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        Scaleform::GFx::ASStringNode *discard_result)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // eax
  Scaleform::GFx::AS3::Traits *v8; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v9; // ebp
  const char *pData; // eax
  const char *v11; // eax
  unsigned int v12; // eax
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::StringDataPtr v16; // [esp-10h] [ebp-28h]
  Scaleform::StringDataPtr v17; // [esp-8h] [ebp-20h]
  Scaleform::GFx::AS3::VM::Error v18; // [esp+10h] [ebp-8h] BYREF

  pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->DataTypeClass->pTraits.pObject;
  ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this->pTraits.pObject->pVM, _this);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(pObject, ClassTraits) )
  {
    Scaleform::GFx::AS3::Instances::ThunkFunction::Execute(this, _this, argc, argv, (bool)discard_result);
  }
  else
  {
    v8 = this->DataTypeClass->pTraits.pObject;
    v9 = Scaleform::GFx::AS3::VM::GetClassTraits(this->pTraits.pObject->pVM, _this);
    pData = v8->GetName(v8, (Scaleform::GFx::ASString *)&discard_result)->pNode->pData;
    v17.Size = (unsigned int)pData;
    if ( pData )
      strlen(pData);
    v17.pStr = (const char *)&argc;
    v11 = **(const char ***)((int (__thiscall *)(const Scaleform::GFx::AS3::ClassTraits::Traits *))v9->GetName)(v9);
    v16.pStr = v11;
    if ( v11 )
      v12 = strlen(v11);
    else
      v12 = 0;
    v16.Size = v12;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eCheckTypeFailedError, this->pTraits.pObject->pVM, v16, v17);
    Scaleform::GFx::AS3::VM::ThrowTypeError(this->pTraits.pObject->pVM, v13);
    pNode = v18.Message.pNode;
    --v18.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( !--_this->value.VS._2.VObj )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)_this);
    v15 = discard_result;
    --discard_result->RefCount;
    if ( !v15->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  }
}
