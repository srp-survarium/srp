void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readObject(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v5; // [esp+4h] [ebp-8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error(&v5, eNotImplementedError, pVM);
  Scaleform::GFx::AS3::VM::ThrowError(pVM, v3);
  pNode = v5.Message.pNode;
  --v5.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
