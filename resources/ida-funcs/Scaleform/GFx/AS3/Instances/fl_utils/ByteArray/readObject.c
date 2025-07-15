void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readObject(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::Value *result)
{
  const Scaleform::GFx::AS3::VM::Error *v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v5; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v6; // [esp+4h] [ebp-8h] BYREF

  v5.pStr = "ByteArray::readObject()";
  v5.Size = 23;
  Scaleform::GFx::AS3::VM::Error::Error(&v6, eNotImplementedError, this->pTraits.pObject->pVM, v5);
  Scaleform::GFx::AS3::VM::ThrowError(this->pTraits.pObject->pVM, v3);
  pNode = v6.Message.pNode;
  --v6.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
