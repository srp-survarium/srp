void __usercall Scaleform::GFx::AddSearchInfo(
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *psearchInfo@<edi>,
        Scaleform::String::DataDesc *a2@<ecx>,
        char *line)
{
  int i; // esi
  void *v4; // esi
  Scaleform::String sindent; // [esp+0h] [ebp-4h] BYREF

  sindent.pData = a2;
  if ( psearchInfo )
  {
    Scaleform::String::String(&sindent, "   ");
    for ( i = 0; i < psearchInfo->Indent; ++i )
      Scaleform::StringBuffer::AppendString(
        &psearchInfo->Info,
        (char *)((sindent.HeapTypeBits & 0xFFFFFFFC) + 8),
        *(_DWORD *)(sindent.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    Scaleform::StringBuffer::AppendString(&psearchInfo->Info, line, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(&psearchInfo->Info, "\n", 0xFFFFFFFF);
    v4 = (void *)(sindent.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((sindent.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
  }
}
