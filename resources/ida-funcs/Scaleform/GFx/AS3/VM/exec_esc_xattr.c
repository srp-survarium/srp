void __thiscall Scaleform::GFx::AS3::VM::exec_esc_xattr(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  Scaleform::GFx::AS3::Value *pCurrent; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  __m128i *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+Bh] [ebp-1Dh] BYREF
  Scaleform::GFx::ASString v; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::StringBuffer buf; // [esp+10h] [ebp-18h] BYREF

  StringManagerRef = this->StringManagerRef;
  pCurrent = this->OpStack.pCurrent;
  if ( Scaleform::GFx::AS3::Value::ToStringValue(pCurrent, &result, (Scaleform::GFx::ASStringNode *)StringManagerRef)->Result )
  {
    Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
    v.pNode = pCurrent->value.VS._1.VStr;
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(&buf, &v);
    pNode = v.pNode;
    --v.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    pData = (__m128i *)buf.pData;
    if ( !buf.pData )
      pData = (__m128i *)uri;
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, pData, buf.Size);
    ++StringNode->RefCount;
    v.pNode = StringNode;
    Scaleform::GFx::AS3::Value::Assign(pCurrent, &v);
    if ( StringNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buf);
  }
}
