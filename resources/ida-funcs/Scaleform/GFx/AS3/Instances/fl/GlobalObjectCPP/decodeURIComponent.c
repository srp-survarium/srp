void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::decodeURIComponent(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::ASString *uri)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v7; // ecx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *v9; // ecx
  bool v10; // zf
  void *v11; // esi
  Scaleform::StringDataPtr v12; // [esp-8h] [ebp-1Ch]
  Scaleform::String unescapedStr; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v14; // [esp+Ch] [ebp-8h] BYREF

  Scaleform::String::String(&unescapedStr);
  if ( !Scaleform::GFx::ASUtils::AS3::Unescape((char *)uri->pNode->pData, (char *)uri->pNode->Size, &unescapedStr, 1) )
  {
    pVM = this->pTraits.pObject->pVM;
    v12.pStr = "decodeURI";
    v12.Size = 9;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eInvalidURIError, pVM, v12);
    Scaleform::GFx::AS3::VM::ThrowURIError(pVM, v5);
    pNode = v14.Message.pNode;
    --v14.Message.pNode->RefCount;
    v7 = pNode;
    if ( pNode->RefCount )
      goto LABEL_9;
    goto LABEL_8;
  }
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (__m128i *)((unescapedStr.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(unescapedStr.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  v9 = result->pNode;
  v10 = result->pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  result->pNode = StringNode;
  v10 = StringNode->RefCount-- == 1;
  if ( v10 )
  {
    v7 = StringNode;
LABEL_8:
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
LABEL_9:
  v11 = (void *)(unescapedStr.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((unescapedStr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
}
