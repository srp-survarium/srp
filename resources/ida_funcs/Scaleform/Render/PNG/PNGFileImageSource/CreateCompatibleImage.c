Scaleform::Render::MemoryBufferImage *__thiscall Scaleform::Render::PNG::PNGFileImageSource::CreateCompatibleImage(
        Scaleform::Render::PNG::PNGFileImageSource *this,
        const Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::Render::MemoryBufferImage *v4; // edi
  Scaleform::Render::TextureManager *pManager; // ebx
  unsigned int FilePos; // ebx
  unsigned int FilePos_high; // ebp
  Scaleform::Render::ImageFormat v8; // eax
  Scaleform::Render::ImageUpdateSync *sync; // [esp+10h] [ebp-14h]
  Scaleform::File *file; // [esp+14h] [ebp-10h]
  Scaleform::Render::Size<unsigned long> *size; // [esp+18h] [ebp-Ch]
  int v13; // [esp+1Ch] [ebp-8h] BYREF
  const Scaleform::Render::ImageCreateArgs *argsa; // [esp+28h] [ebp+4h]

  if ( !this->IsDecodeOnlyImageCompatible(this, args) )
    return (Scaleform::Render::MemoryBufferImage *)Scaleform::Render::ImageSource::CreateCompatibleImage(this, args);
  pHeap = args->pHeap;
  if ( !pHeap )
    pHeap = Scaleform::Memory::pGlobalHeap;
  v4 = (Scaleform::Render::MemoryBufferImage *)pHeap->Alloc(pHeap, 52u, 0);
  if ( !v4 )
    return 0;
  file = this->pFile.pObject;
  if ( args->pUpdateSync )
  {
    sync = args->pUpdateSync;
  }
  else
  {
    pManager = args->pManager;
    if ( pManager )
      sync = &pManager->Scaleform::Render::ImageUpdateSync;
    else
      sync = 0;
  }
  FilePos = this->FilePos;
  FilePos_high = HIDWORD(this->FilePos);
  argsa = (const Scaleform::Render::ImageCreateArgs *)args->Use;
  size = this->GetSize(this, &v13);
  v8 = this->GetFormat(this);
  Scaleform::Render::MemoryBufferImage::MemoryBufferImage(
    v4,
    v8,
    size,
    (unsigned int)argsa,
    sync,
    file,
    __SPAIR64__(FilePos_high, FilePos),
    0);
  v4->__vftable = (Scaleform::Render::MemoryBufferImage_vtbl *)&Scaleform::Render::PNG::MemoryBufferImage::`vftable';
  return v4;
}
