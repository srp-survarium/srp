void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3toString(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM *pVM; // edi
  char *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v7; // zf
  Scaleform::StringBuffer buf; // [esp+8h] [ebp-18h] BYREF

  pVM = this->pTraits.pObject->pVM;
  Scaleform::StringBuffer::StringBuffer(&buf, pVM->MHeap);
  this->ToString(this, &buf, 0);
  pData = buf.pData;
  if ( !buf.pData )
    pData = (char *)&::buf;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(pVM->StringManagerRef->pStringManager, pData, buf.Size);
  StringNode->RefCount += 2;
  pNode = result->pNode;
  v7 = result->pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  v7 = StringNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buf);
}
