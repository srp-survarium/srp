void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::getLineText(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        Scaleform::GFx::ASString *result,
        unsigned int lineIndex)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  wchar_t *LineText; // edi
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v8; // zf
  void *v9; // esi
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  Scaleform::GFx::ASStringNode *v11; // ecx
  unsigned int len; // [esp+8h] [ebp-4h] BYREF

  pObject = this->pDispObj.pObject;
  len = 0;
  LineText = Scaleform::Render::Text::DocView::GetLineText(
               (Scaleform::Render::Text::DocView *)pObject[1].pRenNode.pObject,
               lineIndex,
               (unsigned int)&len);
  if ( LineText )
  {
    Scaleform::String::String((Scaleform::String *)&lineIndex);
    Scaleform::String::AppendString((Scaleform::String *)&lineIndex, LineText, len);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                   (__m128i *)((lineIndex & 0xFFFFFFFC) + 8),
                   *(_DWORD *)(lineIndex & 0xFFFFFFFC) & 0x7FFFFFFF);
    StringNode->RefCount += 2;
    pNode = result->pNode;
    v8 = result->pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = StringNode;
    v8 = StringNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
    v9 = (void *)(lineIndex & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((lineIndex & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
  else
  {
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                        (char *)uri,
                        0,
                        0);
    ConstStringNode->RefCount += 2;
    v11 = result->pNode;
    v8 = result->pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    result->pNode = ConstStringNode;
    v8 = ConstStringNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  }
}
