void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeUTF(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  unsigned int Size; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned __int16 v8; // di
  unsigned __int8 *pData; // ebx
  unsigned int v10; // eax
  Scaleform::GFx::AS3::VM::Error v11; // [esp+8h] [ebp-8h] BYREF

  Size = value->pNode->Size;
  if ( Size <= 0xFFFF )
  {
    v8 = value->pNode->Size;
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Write(this, Size);
    pData = (unsigned __int8 *)value->pNode->pData;
    v10 = v8 + this->Position;
    if ( v10 < this->Data.Data.Size )
    {
      if ( v10 >= this->Length )
        this->Length = v10;
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, v8 + this->Position);
    }
    memcpy(&this->Data.Data.Data[this->Position], pData, v8);
    this->Position += v8;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eNotImplementedError, pVM);
    Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v6);
    pNode = v11.Message.pNode;
    --v11.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
