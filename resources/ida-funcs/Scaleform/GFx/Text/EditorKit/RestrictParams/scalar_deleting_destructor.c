Scaleform::GFx::Text::EditorKit::RestrictParams *__thiscall Scaleform::GFx::Text::EditorKit::RestrictParams::`scalar deleting destructor'(
        Scaleform::GFx::Text::EditorKit::RestrictParams *this,
        char a2)
{
  volatile LONG *v3; // esi

  v3 = (volatile LONG *)(this->RestrictString.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->RestrictRanges.Ranges.Data.Data);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
