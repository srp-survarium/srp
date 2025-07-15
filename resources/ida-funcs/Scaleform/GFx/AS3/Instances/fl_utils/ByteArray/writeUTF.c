void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeUTF(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  unsigned int Size; // eax
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned __int16 v7; // di
  unsigned int Position; // ecx
  const __m128i *pData; // ebx
  unsigned int v10; // eax
  Scaleform::StringDataPtr v11; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v12; // [esp+Ch] [ebp-8h] BYREF

  Size = value->pNode->Size;
  if ( Size <= 0xFFFF )
  {
    v7 = value->pNode->Size;
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Write(this, Size);
    Position = this->Position;
    pData = (const __m128i *)value->pNode->pData;
    v10 = Position + v7;
    if ( v10 < this->Data.Data.Size )
    {
      if ( v10 >= this->Length )
        this->Length = v10;
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, Position + v7);
    }
    memcpy((int)&this->Data.Data.Data[this->Position], pData, v7);
    this->Position += v7;
  }
  else
  {
    v11.pStr = "ByteArray::writeUTF";
    v11.Size = 19;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eNotImplementedError, this->pTraits.pObject->pVM, v11);
    Scaleform::GFx::AS3::VM::ThrowRangeError(this->pTraits.pObject->pVM, v5);
    pNode = v12.Message.pNode;
    --v12.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
