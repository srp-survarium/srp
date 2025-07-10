Scaleform::Render::MemoryBufferImage *__thiscall Scaleform::Render::JPEG::FileReader::CreateMemoryBufferImage(
        Scaleform::Render::JPEG::FileReader *this,
        Scaleform::File *file,
        const Scaleform::Render::ImageCreateArgs *args,
        const Scaleform::Render::Size<unsigned long> *sz,
        unsigned __int64 length)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::Render::MemoryBufferImage *v6; // esi
  Scaleform::Render::ImageUpdateSync *pUpdateSync; // ebx
  Scaleform::Render::TextureManager *pManager; // eax
  __int64 v9; // rax

  pHeap = args->pHeap;
  if ( !pHeap )
    pHeap = Scaleform::Memory::pGlobalHeap;
  v6 = (Scaleform::Render::MemoryBufferImage *)pHeap->Alloc(pHeap, 56u, 0);
  if ( !v6 )
    return 0;
  pUpdateSync = args->pUpdateSync;
  if ( !pUpdateSync )
  {
    pManager = args->pManager;
    if ( pManager )
      pUpdateSync = &pManager->Scaleform::Render::ImageUpdateSync;
    else
      pUpdateSync = 0;
  }
  v9 = file->LTell(file);
  Scaleform::Render::MemoryBufferImage::MemoryBufferImage(v6, Image_None, sz, args->Use, pUpdateSync, file, v9, length);
  v6->__vftable = (Scaleform::Render::MemoryBufferImage_vtbl *)&Scaleform::Render::JPEG::MemoryBufferImage::`vftable';
  v6[1].__vftable = 0;
  return v6;
}
