__int64 __thiscall Scaleform::GFx::FileOpener::GetFileModifyTime(
        Scaleform::GFx::FileOpener *this,
        Scaleform::String purl)
{
  char FileStat; // bl
  void *v3; // esi
  Scaleform::FileStat pfileStat; // [esp+8h] [ebp-18h] BYREF

  Scaleform::String::String(&purl, (char *)purl.pData);
  FileStat = Scaleform::SysFile::GetFileStat(&pfileStat, &purl);
  v3 = (void *)(purl.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((purl.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  if ( FileStat )
    return pfileStat.ModifyTime;
  else
    return -1;
}
