void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::getText(
        Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this,
        Scaleform::GFx::ASString *result,
        int beginIndex,
        Scaleform::String endIndex,
        bool includeLineEndings)
{
  unsigned int HeapTypeBits; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v9; // zf
  void *v10; // esi

  HeapTypeBits = endIndex.HeapTypeBits;
  if ( (int)endIndex.pData <= beginIndex )
    HeapTypeBits = beginIndex + 1;
  Scaleform::GFx::StaticTextSnapshotData::GetSubString(
    &this->SnapshotData,
    &endIndex,
    beginIndex,
    HeapTypeBits,
    includeLineEndings);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (char *)((endIndex.HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(endIndex.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = result->pNode;
  v9 = result->pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  v9 = StringNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v10 = (void *)(endIndex.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((endIndex.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
}
