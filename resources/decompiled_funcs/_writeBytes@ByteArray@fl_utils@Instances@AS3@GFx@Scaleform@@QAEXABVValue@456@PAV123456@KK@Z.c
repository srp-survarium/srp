void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeBytes(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *bytes,
        unsigned int offset,
        unsigned int length)
{
  unsigned int v5; // edx
  unsigned int v6; // esi
  unsigned int v7; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v11; // [esp+4h] [ebp-8h] BYREF

  if ( bytes )
  {
    v5 = bytes->Length;
    v6 = offset;
    if ( v5 < offset )
      v6 = bytes->Length;
    v7 = length;
    if ( !length )
      v7 = v5 - v6;
    if ( v7 <= v5 - v6 )
    {
      if ( v7 )
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Write(this, &bytes->Data.Data.Data[v6], v7);
    }
    else
    {
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v11, eParamRangeError, pVM);
      Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v9);
      pNode = v11.Message.pNode;
      --v11.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}
