void __thiscall Scaleform::GFx::AS3::Classes::fl_utils::ByteArray::defaultObjectEncodingSet(
        Scaleform::GFx::AS3::Classes::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::EncodingType value)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+0h] [ebp-8h] BYREF

  if ( value == encAMF0 || value == encAMF3 )
  {
    this->DefEncoding = value;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v6, eIllegalOperandTypeError, pVM);
    Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v4);
    pNode = v6.Message.pNode;
    --v6.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
