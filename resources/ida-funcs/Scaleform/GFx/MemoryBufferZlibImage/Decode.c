char __thiscall Scaleform::GFx::MemoryBufferZlibImage::Decode(
        Scaleform::GFx::MemoryBufferZlibImage *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  unsigned int Width; // edx
  Scaleform::Render::ImageFormat Format; // eax
  unsigned __int8 *Data; // edx
  Scaleform::File *v8; // edi
  char v9; // bl
  void *v10; // esi
  unsigned int Size; // [esp-4h] [ebp-44h]
  Scaleform::GFx::ZlibDecodeParams v13; // [esp+Ch] [ebp-34h] BYREF
  Scaleform::MemoryFile v14; // [esp+24h] [ebp-1Ch] BYREF

  Width = this->Size.Width;
  Format = this->Format;
  v13.SrcFormat = this->BitmapFormatId;
  Size = this->FileData.Data.Size;
  v13.Size.Width = Width;
  Data = this->FileData.Data.Data;
  v13.Format = Format;
  v13.Size.Height = this->Size.Height;
  Scaleform::MemoryFile::MemoryFile(&v14, (char *)uri, Data, Size);
  v8 = this->Zlib.pObject->CreateZlibFile(this->Zlib.pObject, &v14);
  v13.ColorTableSize = this->ColorTableSize;
  v13.ZlibFile.pObject = v8;
  v9 = Scaleform::GFx::ZlibDecodeHelper(copyScanline, arg, &v13, pdest);
  if ( v8 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
  v10 = (void *)(v14.FilePath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v14.FilePath.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
  Scaleform::RefCountImplCore::~RefCountImplCore(&v14);
  return v9;
}
