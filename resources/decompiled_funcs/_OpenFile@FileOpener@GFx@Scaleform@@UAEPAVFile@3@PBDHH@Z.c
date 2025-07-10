Scaleform::File *__thiscall Scaleform::GFx::FileOpener::OpenFile(
        Scaleform::GFx::FileOpener *this,
        const char *purl,
        int flags,
        int modes)
{
  char v4; // bl
  Scaleform::SysFile *v5; // esi
  int v6; // eax
  int v7; // edi
  void *v8; // esi
  Scaleform::String path; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  path.pData = 0;
  v5 = (Scaleform::SysFile *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12, 0);
  if ( v5 )
  {
    Scaleform::String::String(&path, purl);
    v4 = 1;
    Scaleform::SysFile::SysFile(v5, &path, flags, modes);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  if ( (v4 & 1) != 0 )
  {
    v8 = (void *)(path.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((path.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  }
  return (Scaleform::File *)v7;
}
