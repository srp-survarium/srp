void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::findText(
        Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this,
        int *result,
        int beginIndex,
        Scaleform::String textToFind,
        char *caseSensitive)
{
  int TextA; // eax
  void *v7; // esi
  volatile LONG *v8; // [esp-8h] [ebp-Ch]

  Scaleform::String::String(
    &textToFind,
    *(const __m128i **)textToFind.pData->Size,
    *(_DWORD *)(*(_DWORD *)textToFind.HeapTypeBits + 20));
  TextA = Scaleform::GFx::StaticTextSnapshotData::FindTextA(
            &this->SnapshotData,
            beginIndex,
            (char *)((textToFind.HeapTypeBits & 0xFFFFFFFC) + 8),
            caseSensitive);
  v7 = (void *)(textToFind.HeapTypeBits & 0xFFFFFFFC);
  v8 = (volatile LONG *)((textToFind.HeapTypeBits & 0xFFFFFFFC) + 4);
  *result = TextA;
  if ( InterlockedExchangeAdd(v8, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
}
