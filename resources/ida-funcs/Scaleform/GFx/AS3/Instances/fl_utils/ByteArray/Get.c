void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Get(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        void *dest,
        unsigned int destSz)
{
  this->Position = 0;
  if ( destSz <= this->Data.Data.Size )
  {
    memcpy((int)dest, (const __m128i *)this->Data.Data.Data, destSz);
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
  unsigned int Length; // eax
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v7; // [esp-14h] [ebp-20h]
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  Length = this->Length;
  if ( ind < Length )
    return this->Data.Data.Data[ind];
  v7.pStr = "ByteArray::Get";
  v7.Size = 14;
  Scaleform::GFx::AS3::VM::Error::Error(&v8, eInvalidArgumentError, this->pTraits.pObject->pVM, v7, ind, 0, Length - 1);
  Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v5);
  pNode = v8.Message.pNode;
  --v8.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return 0;
}
