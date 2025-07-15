void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObject::Call(
        Scaleform::GFx::AS3::Instances::fl::GlobalObject *this,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const char *pData; // eax
  unsigned int v8; // eax
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::StringDataPtr v12; // [esp-8h] [ebp-18h]
  Scaleform::GFx::AS3::VM::Error v13; // [esp+8h] [ebp-8h] BYREF

  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, _this);
  pData = ValueTraits->GetName(ValueTraits, (Scaleform::GFx::ASString *)&_this)->pNode->pData;
  v12.pStr = pData;
  if ( pData )
    v8 = strlen(pData);
  else
    v8 = 0;
  v12.Size = v8;
  Scaleform::GFx::AS3::VM::Error::Error(&v13, eCallOfNonFunctionError, this->pTraits.pObject->pVM, v12);
  Scaleform::GFx::AS3::VM::ThrowTypeError(this->pTraits.pObject->pVM, v9);
  pNode = v13.Message.pNode;
  --v13.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v11 = (Scaleform::GFx::ASStringNode *)_this;
  --_this->value.VS._2.VObj;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
}
