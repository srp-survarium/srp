char __cdecl Scaleform::SysFile::GetFileStat(Scaleform::FileStat *pfileStat, const Scaleform::String *path)
{
  int Length; // eax
  wchar_t *v3; // esi
  int v4; // edi
  int st_atime_high; // edx
  int st_mtime; // ecx
  int st_mtime_high; // edx
  int st_size; // ecx
  int st_size_high; // edx
  _stat64 fileStat; // [esp+8h] [ebp-38h] BYREF

  Length = Scaleform::UTF8Util::GetLength((const char *)((path->HeapTypeBits & 0xFFFFFFFC) + 8), -1);
  v3 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 2 * Length + 2, 0);
  Scaleform::UTF8Util::DecodeString(v3, (const char *)((path->HeapTypeBits & 0xFFFFFFFC) + 8), -1);
  v4 = _wstat64(v3, &fileStat);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  if ( v4 )
    return 0;
  st_atime_high = HIDWORD(fileStat.st_atime);
  LODWORD(pfileStat->AccessTime) = fileStat.st_atime;
  st_mtime = fileStat.st_mtime;
  HIDWORD(pfileStat->AccessTime) = st_atime_high;
  st_mtime_high = HIDWORD(fileStat.st_mtime);
  LODWORD(pfileStat->ModifyTime) = st_mtime;
  st_size = fileStat.st_size;
  HIDWORD(pfileStat->ModifyTime) = st_mtime_high;
  st_size_high = HIDWORD(fileStat.st_size);
  LODWORD(pfileStat->FileSize) = st_size;
  HIDWORD(pfileStat->FileSize) = st_size_high;
  return 1;
}
