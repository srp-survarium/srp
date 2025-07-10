void __thiscall Scaleform::Render::RenderEvent::Begin(
        Scaleform::Render::RenderEvent *this,
        Scaleform::String eventName)
{
  if ( InterlockedExchangeAdd((volatile LONG *)((eventName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)(eventName.HeapTypeBits & 0xFFFFFFFC));
}
