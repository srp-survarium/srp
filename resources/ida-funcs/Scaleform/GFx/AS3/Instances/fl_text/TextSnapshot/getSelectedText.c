void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::getSelectedText(
        Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this,
        Scaleform::GFx::ASString *result,
        Scaleform::String includeLineEndings)
{
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v6; // zf
  void *v7; // esi

  Scaleform::GFx::StaticTextSnapshotData::GetSelectedText(
    &this->SnapshotData,
    &includeLineEndings,
    (bool)includeLineEndings.pData);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (__m128i *)((includeLineEndings.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(includeLineEndings.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = result->pNode;
  v6 = result->pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  v6 = StringNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v7 = (void *)(includeLineEndings.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((includeLineEndings.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
}
