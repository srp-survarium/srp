void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeObject(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::Value *object)
{
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v6; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v7; // [esp+4h] [ebp-8h] BYREF

  v6.pStr = "ByteArray::writeObject()";
  v6.Size = 24;
  Scaleform::GFx::AS3::VM::Error::Error(&v7, eNotImplementedError, this->pTraits.pObject->pVM, v6);
  Scaleform::GFx::AS3::VM::ThrowError(this->pTraits.pObject->pVM, v4);
  pNode = v7.Message.pNode;
  --v7.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
