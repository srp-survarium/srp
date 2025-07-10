char __thiscall Scaleform::GFx::AS2::IMEManager::Invoke(
        Scaleform::GFx::AS2::IMEManager *this,
        Scaleform::String ppathToMethod,
        Scaleform::GFx::Value *presult,
        const Scaleform::GFx::Value *pargs,
        unsigned int numArgs)
{
  Scaleform::String *p_CandListPath; // esi
  Scaleform::String *v7; // eax
  void *v8; // esi
  Scaleform::GFx::Movie *pMovie; // ecx
  char v10; // bl
  void *v11; // esi
  char *pData; // [esp-Ch] [ebp-18h]
  Scaleform::String result; // [esp+8h] [ebp-4h] BYREF

  p_CandListPath = &this->CandListPath;
  if ( !Scaleform::String::GetLength(&this->CandListPath) )
    return 0;
  pData = (char *)ppathToMethod.pData;
  v7 = Scaleform::String::operator+(
         p_CandListPath,
         &result,
         (char *)&stru_957BE0.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags);
  Scaleform::String::operator+(v7, &ppathToMethod, pData);
  v8 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  pMovie = this->pMovie;
  v10 = 0;
  if ( pMovie )
    v10 = Scaleform::GFx::Movie::Invoke(
            pMovie,
            (const char *)((ppathToMethod.HeapTypeBits & 0xFFFFFFFC) + 8),
            presult,
            pargs,
            numArgs);
  v11 = (void *)(ppathToMethod.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((ppathToMethod.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
  return v10;
}
