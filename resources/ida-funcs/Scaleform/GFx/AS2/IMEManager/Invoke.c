bool __thiscall Scaleform::GFx::AS2::IMEManager::Invoke(
        Scaleform::GFx::AS2::IMEManager *this,
        const __m128i *ppathToMethod,
        Scaleform::GFx::Value *presult,
        const Scaleform::GFx::Value *pargs,
        unsigned int numArgs)
{
  Scaleform::String *p_CandListPath; // esi
  Scaleform::String *v7; // eax
  void *v8; // esi
  Scaleform::GFx::Movie *pMovie; // ecx
  bool v10; // bl
  void *v11; // esi
  const __m128i *v13; // [esp-Ch] [ebp-18h]
  Scaleform::String v14; // [esp+8h] [ebp-4h] BYREF

  p_CandListPath = &this->CandListPath;
  if ( !Scaleform::String::GetLength(&this->CandListPath) )
    return 0;
  v13 = ppathToMethod;
  v7 = Scaleform::String::operator+(p_CandListPath, &v14, (const __m128i *)".");
  Scaleform::String::operator+(v7, (Scaleform::String *)&ppathToMethod, v13);
  v8 = (void *)(v14.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v14.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  pMovie = this->pMovie;
  v10 = 0;
  if ( pMovie )
    v10 = Scaleform::GFx::Movie::Invoke(
            pMovie,
            (const char *)(((unsigned int)ppathToMethod & 0xFFFFFFFC) + 8),
            presult,
            pargs,
            numArgs);
  v11 = (void *)((unsigned int)ppathToMethod & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)ppathToMethod & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
  return v10;
}
