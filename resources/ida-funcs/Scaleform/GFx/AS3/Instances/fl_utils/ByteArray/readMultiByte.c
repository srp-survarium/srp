void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::readMultiByte(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::ASString *result,
        unsigned int length,
        const Scaleform::GFx::ASString *charSet)
{
  const char *v5; // ecx
  int v6; // esi
  const char *v7; // ecx
  int v8; // esi
  unsigned int v9; // edi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v11; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v13; // zf
  const char *v14; // ecx
  int v15; // esi
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::StringDataPtr v19; // [esp-8h] [ebp-20h]
  Scaleform::GFx::AS3::VM::Error v20; // [esp+10h] [ebp-8h] BYREF

  v5 = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ASCII_Names[0];
  v6 = 0;
  if ( Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ASCII_Names[0] )
  {
    while ( strcmp(charSet->pNode->pData, v5) )
    {
      v5 = off_876574[v6++];
      if ( !v5 )
        goto LABEL_4;
    }
    v9 = length;
    if ( length >= this->Length )
      v9 = this->Length;
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                   (__m128i *)&this->Data.Data.Data[this->Position],
                   v9);
LABEL_9:
    v11 = StringNode;
    StringNode->RefCount += 2;
    pNode = result->pNode;
    v13 = result->pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = v11;
    v13 = v11->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    this->Position += v9;
    return;
  }
LABEL_4:
  v7 = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::UTF8_Names[0];
  v8 = 0;
  if ( !Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::UTF8_Names[0] )
  {
LABEL_16:
    v14 = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::UTF16_Names[0];
    v15 = 0;
    if ( !Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::UTF16_Names[0] )
    {
LABEL_21:
      pVM = this->pTraits.pObject->pVM;
      v19.pStr = "charSet";
      v19.Size = 7;
      Scaleform::GFx::AS3::VM::Error::Error(&v20, eInvalidArgumentError, pVM, v19);
      Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v17);
      v18 = v20.Message.pNode;
      --v20.Message.pNode->RefCount;
      if ( !v18->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      return;
    }
    while ( strcmp(charSet->pNode->pData, v14) )
    {
      v14 = (&off_8765B4)[v15++];
      if ( !v14 )
        goto LABEL_21;
    }
    v9 = length;
    if ( length >= this->Length )
      v9 = this->Length;
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                   (wchar_t *)&this->Data.Data.Data[this->Position],
                   v9);
    goto LABEL_9;
  }
  while ( strcmp(charSet->pNode->pData, v7) )
  {
    v7 = off_8765A0[v8++];
    if ( !v7 )
      goto LABEL_16;
  }
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ReadUTFBytes(
    this,
    (Scaleform::GFx::AS3::CheckResult *)&length,
    result,
    length);
}
