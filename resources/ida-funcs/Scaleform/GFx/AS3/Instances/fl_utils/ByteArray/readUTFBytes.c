Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ReadUTFBytes(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASString *resulta,
        unsigned int len)
{
  unsigned int v4; // ebx
  unsigned int Position; // ecx
  Scaleform::GFx::AS3::CheckResult *v7; // eax
  unsigned __int8 *v8; // eax
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v11; // zf

  v4 = len;
  Position = this->Position;
  if ( Position + len <= this->Data.Data.Size )
  {
    if ( len > 2 )
    {
      v8 = &this->Data.Data.Data[Position];
      if ( *v8 == 0xEF && v8[1] == 0xBB && v8[2] == 0xBF )
      {
        v4 = len - 3;
        this->Position = Position + 3;
      }
    }
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                   (char *)&this->Data.Data.Data[this->Position],
                   v4);
    StringNode->RefCount += 2;
    pNode = resulta->pNode;
    v11 = resulta->pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    resulta->pNode = StringNode;
    v11 = StringNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    this->Position += v4;
    v7 = result;
    result->Result = 1;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
    v7 = result;
    result->Result = 0;
  }
  return v7;
}
