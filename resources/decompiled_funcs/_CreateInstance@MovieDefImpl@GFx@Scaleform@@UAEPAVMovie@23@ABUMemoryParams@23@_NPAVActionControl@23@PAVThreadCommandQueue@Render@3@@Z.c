Scaleform::GFx::Movie *__thiscall Scaleform::GFx::MovieDefImpl::CreateInstance(
        Scaleform::GFx::MovieDefImpl *this,
        const Scaleform::GFx::MemoryParams *memParams,
        BOOL initFirstFrame,
        Scaleform::GFx::ActionControl *actionControl,
        Scaleform::Render::ThreadCommandQueue *queue)
{
  const char *v6; // eax
  char *ShortFilename; // eax
  Scaleform::GFx::MemoryContext *v8; // edi
  Scaleform::GFx::Movie *v9; // ebx
  char *v11; // [esp+14h] [ebp-Ch]
  Scaleform::String heapName; // [esp+1Ch] [ebp-4h]
  Scaleform::String retaddr; // [esp+20h] [ebp+0h] BYREF

  v6 = (const char *)((int (__thiscall *)(Scaleform::GFx::MovieDefImpl *, const char *))this->GetFileURL)(this, "\"");
  ShortFilename = (char *)Scaleform::GetShortFilename(v6);
  Scaleform::String::String(&retaddr, "MovieView \"", ShortFilename, v11);
  v8 = (Scaleform::GFx::MemoryContext *)((int (__thiscall *)(Scaleform::GFx::MovieDefImpl *, unsigned int, BOOL))this->CreateMemoryContext)(
                                          this,
                                          (retaddr.HeapTypeBits & 0xFFFFFFFC) + 8,
                                          initFirstFrame);
  if ( v8 )
  {
    v9 = this->CreateInstance(this, v8, initFirstFrame, actionControl, queue);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
    if ( InterlockedExchangeAdd((volatile LONG *)((heapName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)(heapName.HeapTypeBits & 0xFFFFFFFC));
    return v9;
  }
  else
  {
    if ( InterlockedExchangeAdd((volatile LONG *)((heapName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)(heapName.HeapTypeBits & 0xFFFFFFFC));
    return 0;
  }
}
