void __thiscall Scaleform::GFx::ZlibImageSource::CreateCompatibleImage(
        Scaleform::GFx::ZlibImageSource *this,
        const Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::MemoryBufferZlibImage *v4; // ebp
  Scaleform::Render::ImageUpdateSync *pUpdateSync; // eax
  Scaleform::Render::TextureManager *pManager; // eax
  Scaleform::GFx::Resource *pObject; // ebx
  int v8; // eax
  Scaleform::Render::ImageFormat v9; // eax
  Scaleform::GFx::ZlibImageSource::SourceBitmapDataFormat BitmapFormatId; // [esp-24h] [ebp-38h]
  unsigned __int16 ColorTableSize; // [esp-20h] [ebp-34h]
  unsigned int Use; // [esp-1Ch] [ebp-30h]
  Scaleform::Render::ImageUpdateSync *v13; // [esp-18h] [ebp-2Ch]
  Scaleform::File *v14; // [esp-14h] [ebp-28h]
  __int64 FilePos; // [esp-10h] [ebp-24h]
  unsigned int FileLen; // [esp-8h] [ebp-1Ch]
  int v17; // [esp+4h] [ebp-10h]
  int v18; // [esp+8h] [ebp-Ch]
  Scaleform::Render::Size<unsigned long> v19; // [esp+Ch] [ebp-8h] BYREF

  if ( this->IsDecodeOnlyImageCompatible(this, args) )
  {
    pHeap = args->pHeap;
    if ( !pHeap )
      pHeap = Scaleform::Memory::pGlobalHeap;
    v4 = (Scaleform::GFx::MemoryBufferZlibImage *)pHeap->Alloc(pHeap, 68u, 0);
    if ( v4 )
    {
      pUpdateSync = args->pUpdateSync;
      if ( !pUpdateSync )
      {
        pManager = args->pManager;
        if ( pManager )
          pUpdateSync = &pManager->Scaleform::Render::ImageUpdateSync;
        else
          pUpdateSync = 0;
      }
      FileLen = this->FileLen;
      pObject = (Scaleform::GFx::Resource *)this->Zlib.pObject;
      FilePos = this->FilePos;
      v14 = this->pFile.pObject;
      v13 = pUpdateSync;
      Use = args->Use;
      ColorTableSize = this->ColorTableSize;
      BitmapFormatId = this->BitmapFormatId;
      v8 = ((int (__thiscall *)(Scaleform::GFx::ZlibImageSource *))this->GetSize)(this);
      v9 = ((int (__thiscall *)(Scaleform::GFx::ZlibImageSource *, int))this->GetFormat)(this, v8);
      Scaleform::GFx::MemoryBufferZlibImage::MemoryBufferZlibImage(
        v4,
        pObject,
        v9,
        &v19,
        BitmapFormatId,
        ColorTableSize,
        Use,
        v13,
        v14,
        FilePos,
        FileLen);
    }
  }
  else
  {
    Scaleform::Render::ImageSource::CreateCompatibleImage(this, args, v17, v18, v19.Width);
  }
}
