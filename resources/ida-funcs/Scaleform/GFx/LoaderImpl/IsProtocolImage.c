char __cdecl Scaleform::GFx::LoaderImpl::IsProtocolImage(Scaleform::String *url, bool *bilinear, bool *sync)
{
  int v3; // eax
  unsigned int v4; // ebp
  bool v5; // bl
  void *v6; // esi
  void *v7; // esi
  Scaleform::String *v9; // eax
  bool v10; // al
  void *v11; // esi
  bool v12; // bl
  Scaleform::String result; // [esp+10h] [ebp-8h] BYREF
  Scaleform::String v14; // [esp+14h] [ebp-4h] BYREF

  if ( (unsigned int)Scaleform::String::GetLength(url) <= 6 )
    return 0;
  v3 = *(char *)((url->HeapTypeBits & 0xFFFFFFFC) + 8);
  if ( (unsigned int)(v3 - 65) <= 0x19 )
    v3 += 32;
  if ( v3 != 105 && v3 != 115 )
    return 0;
  v4 = v3 == 115;
  Scaleform::String::ToLower(url, &result);
  v5 = strcmp(
         (const char *)((Scaleform::String::Substring(&result, &v14, v4, v4 + 6)->HeapTypeBits & 0xFFFFFFFC) + 8),
         "img://") == 0;
  v6 = (void *)(v14.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v14.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
  if ( v5 )
  {
    if ( bilinear )
      *bilinear = 1;
    if ( sync )
      *sync = v4 != 0;
    v7 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
    return 1;
  }
  v9 = Scaleform::String::Substring(&result, &v14, v4, v4 + 8);
  v10 = Scaleform::String::operator==(v9, "imgps://");
  v11 = (void *)(v14.HeapTypeBits & 0xFFFFFFFC);
  v12 = v10;
  if ( InterlockedExchangeAdd((volatile LONG *)((v14.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
  if ( !v12 )
  {
    Scaleform::String::~String(&result);
    return 0;
  }
  if ( bilinear )
    *bilinear = 0;
  if ( sync )
    *sync = v4 != 0;
  Scaleform::String::~String(&result);
  return 1;
}
