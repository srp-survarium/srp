void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::endianSet(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value)
{
  unsigned int v4; // eax
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v7; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v8; // [esp+Ch] [ebp-8h] BYREF

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
    if ( value->pNode->pData )
      v4 = strlen(value->pNode->pData);
    else
      v4 = 0;
    v7.Size = v4;
    v7.pStr = value->pNode->pData;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eInvalidArgumentError, this->pTraits.pObject->pVM, v7);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v5);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
