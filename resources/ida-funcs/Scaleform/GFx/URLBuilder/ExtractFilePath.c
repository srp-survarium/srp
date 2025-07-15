BOOL __cdecl Scaleform::GFx::URLBuilder::ExtractFilePath(Scaleform::String *ppath)
{
  int v1; // esi
  unsigned int CharAt; // eax
  const Scaleform::String *v4; // eax
  void *v5; // edi
  Scaleform::String result; // [esp+8h] [ebp-4h] BYREF

  v1 = Scaleform::String::GetLength(ppath) - 1;
  if ( v1 >= 0 )
  {
    while ( 1 )
    {
      CharAt = Scaleform::String::GetCharAt(ppath, v1);
      if ( CharAt == 47 || CharAt == 92 )
        break;
      if ( --v1 < 0 )
        return 0;
    }
    v4 = Scaleform::String::Substring(ppath, &result, 0, v1 + 1);
    Scaleform::String::operator=(ppath, v4);
    v5 = (void *)(result.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((result.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  }
  return v1 >= 0;
}
