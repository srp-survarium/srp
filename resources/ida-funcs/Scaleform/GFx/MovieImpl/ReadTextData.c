char __usercall Scaleform::GFx::MovieImpl::ReadTextData@<al>(
        int a1@<esi>,
        Scaleform::String *pdata,
        Scaleform::String pfile,
        Scaleform::String pfileLen,
        bool urlEncoded,
        char a6)
{
  Scaleform::String::DataDesc *v6; // ebx
  int v7; // eax
  Scaleform::String::DataDesc *v8; // edi
  int v10; // esi
  int Size; // eax
  int v12; // eax
  int i; // ecx
  int j; // ecx
  void *v15; // esi

  v6 = pfile.pData;
  v7 = (*(int (__thiscall **)(Scaleform::String::DataDesc *))(*(_DWORD *)pfile.HeapTypeBits + 24))(pfile.pData);
  v8 = pfileLen.pData;
  *(_DWORD *)pfileLen.HeapTypeBits = v7;
  if ( !v7 )
    return 0;
  Scaleform::String::String(&pfile);
  v10 = ((int (__thiscall *)(Scaleform::MemoryHeap *, unsigned int, _DWORD, int))Scaleform::Memory::pGlobalHeap->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          v8->Size,
          0,
          a1);
  (*(void (__thiscall **)(Scaleform::String::DataDesc *, int, unsigned int))(v6->Size + 40))(v6, v10, v8->Size);
  Size = v8->Size;
  if ( *(_WORD *)v10 == 0xFEFF )
  {
    v12 = Size / 2 - 1;
    for ( i = 0; i < v12; ++i )
      ;
  }
  else
  {
    if ( *(_WORD *)v10 != 0xFFFE )
    {
      if ( Size > 2 && *(_BYTE *)v10 == 0xEF && *(_BYTE *)(v10 + 1) == 0xBB && *(_BYTE *)(v10 + 2) == 0xBF )
        Scaleform::String::AppendString(&pfileLen, (const __m128i *)(v10 + 3), Size - 3);
      else
        Scaleform::String::AppendString(&pfileLen, (const __m128i *)v10, v8->Size);
      goto LABEL_17;
    }
    v12 = Size / 2 - 1;
    for ( j = 0; j < v12; ++j )
      *(_WORD *)(v10 + 2 + 2 * j) = __ROL2__(*(_WORD *)(v10 + 2 + 2 * j), 8);
  }
  Scaleform::String::AppendString(&pfileLen, (wchar_t *)(v10 + 2), v12);
LABEL_17:
  if ( a6 )
    Scaleform::GFx::ASUtils::Unescape(
      (const char *)((pfileLen.HeapTypeBits & 0xFFFFFFFC) + 8),
      *(_DWORD *)(pfileLen.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
      (Scaleform::String *)pfile.pData);
  else
    Scaleform::String::operator=((Scaleform::String *)pfile.pData, &pfileLen);
  ((void (__thiscall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->Free)(Scaleform::Memory::pGlobalHeap);
  v15 = (void *)(pfile.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pfile.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
  return 1;
}
