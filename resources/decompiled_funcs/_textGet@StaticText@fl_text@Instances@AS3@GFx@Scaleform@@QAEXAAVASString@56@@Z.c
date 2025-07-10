void __thiscall Scaleform::GFx::AS3::Instances::fl_text::StaticText::textGet(
        Scaleform::GFx::AS3::Instances::fl_text::StaticText *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::MemoryHeap *MHeap; // ecx
  Scaleform::GFx::StaticTextCharacter *pObject; // ebx
  Scaleform::GFx::StaticTextSnapshotData *v5; // eax
  Scaleform::GFx::StaticTextSnapshotData *v6; // eax
  Scaleform::GFx::StaticTextSnapshotData *v7; // edi
  unsigned int CharCount; // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  Scaleform::String *SubString; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v13; // zf
  void *v14; // esi
  volatile LONG *v15; // esi
  Scaleform::String v16; // [esp+Ch] [ebp-4h] BYREF

  MHeap = this->pTraits.pObject->pVM->MHeap;
  pObject = (Scaleform::GFx::StaticTextCharacter *)this->pDispObj.pObject;
  v5 = (Scaleform::GFx::StaticTextSnapshotData *)MHeap->Alloc(MHeap, 20u, 0);
  if ( v5 )
  {
    Scaleform::GFx::StaticTextSnapshotData::StaticTextSnapshotData(v5);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  Scaleform::GFx::StaticTextSnapshotData::Add(v7, pObject);
  CharCount = Scaleform::GFx::StaticTextSnapshotData::GetCharCount(v7);
  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  SubString = Scaleform::GFx::StaticTextSnapshotData::GetSubString(v7, &v16, 0, CharCount, 1);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManagerRef->pStringManager,
                 (char *)((SubString->HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(SubString->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  StringNode->RefCount += 2;
  pNode = result->pNode;
  v13 = result->pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  v13 = StringNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  v14 = (void *)(v16.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v16.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
  if ( v7 )
  {
    v15 = (volatile LONG *)(v7->SnapshotString.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd(v15 + 1, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v15);
    Scaleform::ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::StaticTextSnapshotData::CharRef,Scaleform::AllocatorLH<Scaleform::GFx::StaticTextSnapshotData::CharRef,2>,Scaleform::ArrayDefaultPolicy>(&v7->StaticTextCharRefs.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  }
}
