void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::objectEncodingSet(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int value)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+0h] [ebp-8h] BYREF

  if ( !value || value == 3 )
  {
    *((_DWORD *)this + 8) ^= ((unsigned __int8)value ^ (unsigned __int8)*((_DWORD *)this + 8)) & 7;
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
