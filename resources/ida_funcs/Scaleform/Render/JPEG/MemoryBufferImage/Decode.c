char __thiscall Scaleform::Render::JPEG::MemoryBufferImage::Decode(
        Scaleform::Render::JPEG::MemoryBufferImage *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::Render::JPEG::Input *SwfJpeg2HeaderOnly; // esi
  char v6; // al
  void *v7; // esi
  char v8; // bl
  jpeg_decompress_struct *v10; // edi
  void *v11; // esi
  Scaleform::MemoryFile file; // [esp+Ch] [ebp-1Ch] BYREF

  Scaleform::MemoryFile::MemoryFile(&file, &this->FilePath, this->FileData.Data.Data, this->FileData.Data.Size);
  if ( (this->Flags & 0xFFFFFFFC) != 0 )
  {
    SwfJpeg2HeaderOnly = Scaleform::Render::JPEG::FileReader::CreateSwfJpeg2HeaderOnly(
                           &Scaleform::Render::JPEG::FileReader::Instance,
                           *(const unsigned __int8 **)((this->Flags & 0xFFFFFFFC) + 8),
                           *(_DWORD *)((this->Flags & 0xFFFFFFFC) + 12));
    v10 = (jpeg_decompress_struct *)SwfJpeg2HeaderOnly->GetCInfo(SwfJpeg2HeaderOnly);
    Scaleform::Render::JPEG::GJPEGUtil_ReplaceRwSource(v10, (Scaleform::GFx::Resource *)&file);
    goto LABEL_3;
  }
  SwfJpeg2HeaderOnly = Scaleform::Render::JPEG::FileReader::CreateSwfJpeg2HeaderOnly(
                         &Scaleform::Render::JPEG::FileReader::Instance,
                         (Scaleform::GFx::Resource *)&file);
  if ( SwfJpeg2HeaderOnly )
  {
LABEL_3:
    SwfJpeg2HeaderOnly->StartImage(SwfJpeg2HeaderOnly);
    v6 = Scaleform::Render::JPEG::DecodeHelper(SwfJpeg2HeaderOnly, this->Format, pdest, copyScanline, arg);
    v7 = (void *)(file.FilePath.HeapTypeBits & 0xFFFFFFFC);
    v8 = v6;
    if ( InterlockedExchangeAdd((volatile LONG *)((file.FilePath.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
    Scaleform::RefCountImplCore::~RefCountImplCore(&file);
    return v8;
  }
  v11 = (void *)(file.FilePath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((file.FilePath.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
  Scaleform::RefCountImplCore::~RefCountImplCore(&file);
  return 0;
}
