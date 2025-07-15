void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::objectEncodingSet(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v6; // [esp-10h] [ebp-1Ch]
  Scaleform::StringDataPtr v7; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  if ( !value || value == 3 )
  {
    *((_DWORD *)this + 8) ^= ((unsigned __int8)value ^ (unsigned __int8)*((_DWORD *)this + 8)) & 7;
  }
  else
  {
    v7.pStr = "encAMF0 or encAMF3";
    v7.Size = 18;
    v6.pStr = "some type";
    v6.Size = 9;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eIllegalOperandTypeError, this->pTraits.pObject->pVM, v6, v7);
    Scaleform::GFx::AS3::VM::ThrowRangeError(this->pTraits.pObject->pVM, v4);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
