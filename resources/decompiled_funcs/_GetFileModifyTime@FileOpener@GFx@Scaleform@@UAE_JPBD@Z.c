__int64 __thiscall Scaleform::GFx::FileOpener::GetFileModifyTime(Scaleform::GFx::FileOpener *this, const char *purl)
{
  bool v2; // bl
  void *v3; // esi
  Scaleform::FileStat fileStat; // [esp+8h] [ebp-18h] BYREF

  Scaleform::String::String((Scaleform::String *)&purl, purl);
  v2 = Scaleform::SysFile::GetFileStat(&fileStat, (const Scaleform::String *)&purl);
  v3 = (void *)((unsigned int)purl & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)purl & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  if ( v2 )
    return fileStat.ModifyTime;
  else
    return -1;
}
