void __usercall Scaleform::GFx::AddSearchInfo(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo@<edi>,
        Scaleform::String::DataDesc *a2@<ecx>,
        const __m128i *line)
{
  int i; // esi
  void *v4; // esi
  Scaleform::String v5; // [esp+0h] [ebp-4h] BYREF

  v5.pData = a2;
  if ( psearchInfo )
  {
    Scaleform::String::String(&v5, (const __m128i *)"   ");
    for ( i = 0; i < psearchInfo->Indent; ++i )
      Scaleform::StringBuffer::AppendString(
        &psearchInfo->Info,
        (const __m128i *)((v5.HeapTypeBits & 0xFFFFFFFC) + 8),
        *(_DWORD *)(v5.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    Scaleform::StringBuffer::AppendString(&psearchInfo->Info, line, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&psearchInfo->Info, (const __m128i *)"\n", 0xFFFFFFFF);
    v4 = (void *)(v5.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v5.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
  }
}
