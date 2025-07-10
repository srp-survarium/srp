void __cdecl Scaleform::Render::Text::TextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__()
{
  void *v0; // esi

  v0 = (void *)(emptyStr.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((emptyStr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v0);
}
