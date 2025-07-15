Scaleform::String *__cdecl Scaleform::operator+(
        Scaleform::String *result,
        const __m128i *l,
        const Scaleform::String *r)
{
  Scaleform::String::String(result, l, (const __m128i *)((r->HeapTypeBits & 0xFFFFFFFC) + 8), 0);
  return result;
}


Scaleform::String *__cdecl Scaleform::operator+(
        Scaleform::String *result,
        const __m128i *l,
        const Scaleform::GFx::ASString *r)
{
  const Scaleform::String *v3; // eax
  Scaleform::String *v4; // eax
  void *v5; // esi
  void *v6; // esi
  const Scaleform::String *v8; // [esp-4h] [ebp-14h]
  Scaleform::String v9; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(&v9, (const __m128i *)r->pNode->pData, r->pNode->Size);
  v8 = v3;
  Scaleform::String::String((Scaleform::String *)&r, l);
  Scaleform::String::operator+(v4, result, v8);
  v5 = (void *)((unsigned int)r & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)r & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  v6 = (void *)(v9.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v9.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
  return result;
}
