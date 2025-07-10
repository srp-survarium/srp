Scaleform::Render::Palette *__stdcall Scaleform::Render::Palette::Create(
        unsigned int colorCount,
        bool hasAlpha,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v3; // ecx
  volatile LONG *v4; // eax
  volatile LONG *v5; // esi

  v3 = pheap;
  if ( !pheap )
    v3 = Scaleform::Memory::pGlobalHeap;
  v4 = (volatile LONG *)v3->Alloc(v3, 4 * colorCount + 8, 0);
  v5 = v4;
  if ( v4 )
  {
    InterlockedExchange(v4, 1);
    *((_WORD *)v5 + 2) = colorCount;
    *((_BYTE *)v5 + 6) = hasAlpha;
    memset((int)(v5 + 2), 0, 4 * colorCount);
  }
  return (Scaleform::Render::Palette *)v5;
}
