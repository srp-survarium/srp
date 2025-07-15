void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Get(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned __int8 *dest,
        unsigned int destSz)
{
  this->Position = 0;
  if ( destSz <= this->Data.Data.Size )
  {
    memcpy(dest, this->Data.Data.Data, destSz);
    this->Position += destSz;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
  }
  this->Position = 0;
}


unsigned __int8 __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Get(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned int ind)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+0h] [ebp-8h] BYREF

  if ( ind < this->Length )
    return this->Data.Data.Data[ind];
  pVM = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error(&v6, eInvalidArgumentError, pVM);
  Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v4);
  pNode = v6.Message.pNode;
  --v6.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return 0;
}
