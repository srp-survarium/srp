char __thiscall Scaleform::Render::PNG::MemoryBufferImage::Decode(
        Scaleform::Render::PNG::MemoryBufferImage *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::Render::PNG::LibPNGInput *v5; // eax
  int v6; // eax
  void (__thiscall ***v7)(_DWORD, int); // esi
  void (__thiscall **v8)(int, int); // edx
  void *v9; // esi
  char v11; // bl
  void *v12; // esi
  Scaleform::MemoryFile v13; // [esp+20h] [ebp-1Ch] BYREF

  Scaleform::MemoryFile::MemoryFile(&v13, &this->FilePath, this->FileData.Data.Data, this->FileData.Data.Size);
  if ( !v13.IsValid(&v13)
    || (v5 = (Scaleform::Render::PNG::LibPNGInput *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      400,
                                                      0)) == 0
    || (Scaleform::Render::PNG::LibPNGInput::LibPNGInput(v5, (Scaleform::GFx::Resource *)&v13),
        (v7 = (void (__thiscall ***)(_DWORD, int))v6) == 0) )
  {
LABEL_6:
    v9 = (void *)(v13.FilePath.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v13.FilePath.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
    Scaleform::RefCountImplCore::~RefCountImplCore(&v13);
    return 0;
  }
  v8 = *(void (__thiscall ***)(int, int))v6;
  if ( !*(_BYTE *)(v6 + 396) )
  {
    (*v8)(v6, 1);
    goto LABEL_6;
  }
  v11 = ((int (__thiscall *)(int, Scaleform::Render::ImageFormat, Scaleform::Render::ImageData *, void (__stdcall *)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *), void *))v8[3])(
          v6,
          this->Format,
          pdest,
          copyScanline,
          arg);
  (**v7)(v7, 1);
  v12 = (void *)(v13.FilePath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v13.FilePath.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
  Scaleform::RefCountImplCore::~RefCountImplCore(&v13);
  return v11;
}
