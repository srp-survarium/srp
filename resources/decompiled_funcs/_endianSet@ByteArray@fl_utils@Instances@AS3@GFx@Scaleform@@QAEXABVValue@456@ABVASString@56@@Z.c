void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::endianSet(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+8h] [ebp-8h] BYREF

  if ( !strcmp(value->pNode->pData, "bigEndian") )
  {
    *((_DWORD *)this + 8) &= 0xFFFFFFE7;
  }
  else if ( !strcmp(value->pNode->pData, "littleEndian") )
  {
    *((_DWORD *)this + 8) = *((_DWORD *)this + 8) & 0xFFFFFFE7 | 8;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v6, eInvalidArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v4);
    pNode = v6.Message.pNode;
    --v6.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
