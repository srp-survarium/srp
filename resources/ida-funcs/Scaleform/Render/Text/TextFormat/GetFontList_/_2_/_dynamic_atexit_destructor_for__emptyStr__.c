int Scaleform::Render::Text::TextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__()
{
  unsigned int v0; // esi
  int result; // eax

  v0 = emptyStr.HeapTypeBits & 0xFFFFFFFC;
  result = InterlockedExchangeAdd((volatile LONG *)((emptyStr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) - 1;
  if ( !result )
    return ((int (__thiscall *)(Scaleform::MemoryHeap *, unsigned int))Scaleform::Memory::pGlobalHeap->Free)(
             Scaleform::Memory::pGlobalHeap,
             v0);
  return result;
}
