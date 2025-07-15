char __thiscall Scaleform::GFx::StaticTextSnapshotData::IsSelected(
        Scaleform::GFx::StaticTextSnapshotData *this,
        unsigned int start,
        unsigned int end)
{
  unsigned int v4; // esi
  int v5; // edi
  Scaleform::GFx::StaticTextCharacter::HighlightDesc *pHighlight; // ecx
  void *v7; // esi
  void *v9; // esi
  Scaleform::String v10; // [esp+10h] [ebp-4h] BYREF

  Scaleform::String::String(&v10);
  v4 = 0;
  v5 = 0;
  if ( !this->StaticTextCharRefs.Data.Size )
  {
LABEL_10:
    v7 = (void *)(v10.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v10.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
    return 0;
  }
  while ( 1 )
  {
    pHighlight = this->StaticTextCharRefs.Data.Data[v5].pChar.pObject->pHighlight;
    if ( pHighlight )
      break;
LABEL_9:
    if ( ++v5 >= this->StaticTextCharRefs.Data.Size )
      goto LABEL_10;
  }
  if ( v4 <= start )
  {
    if ( start < v4 + this->StaticTextCharRefs.Data.Data[v5].CharCount )
      goto LABEL_7;
    if ( v4 < start )
      goto LABEL_8;
  }
  if ( v4 >= end )
  {
LABEL_8:
    v4 += this->StaticTextCharRefs.Data.Data[v5].CharCount;
    goto LABEL_9;
  }
LABEL_7:
  if ( !Scaleform::Render::Text::Highlighter::IsAnyCharSelected(&pHighlight->HighlightManager, start - v4, end - v4) )
    goto LABEL_8;
  v9 = (void *)(v10.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v10.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  return 1;
}
