void __thiscall Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas::MemoryBufferJpegImageWithZlibAlphas(
        Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *this,
        Scaleform::GFx::Resource *zlib,
        Scaleform::Render::JPEG::AbstractReader *reader,
        unsigned int alphaPos,
        Scaleform::Render::ImageFormat format,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned int use,
        Scaleform::Render::ImageUpdateSync *sync,
        Scaleform::File *file,
        unsigned int length)
{
  Scaleform::MemoryHeap *v11; // eax
  Scaleform::Render::MemoryBufferImage *(__thiscall *CreateMemoryBufferImage)(Scaleform::Render::JPEG::AbstractReader *, Scaleform::File *, const Scaleform::Render::ImageCreateArgs *, const Scaleform::Render::Size<unsigned long> *, unsigned __int64); // edx
  int v13; // eax
  Scaleform::Render::Image *pObject; // ecx
  Scaleform::Render::Image *v15; // edi
  Scaleform::Render::ImageCreateArgs args; // [esp+Ch] [ebp-14h] BYREF

  this->__vftable = (Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas_vtbl *)&Scaleform::Render::Image::`vftable';
  InterlockedExchange((volatile LONG *)&this->pTexture, 0);
  this->pUpdateSync = 0;
  this->pInverseMatrix = 0;
  this->pImage.pObject = 0;
  this->__vftable = (Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas_vtbl *)&Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas::`vftable';
  if ( zlib )
    Scaleform::RefCountImpl::AddRef(zlib);
  this->ZLib.pObject = (Scaleform::GFx::ZlibSupportBase *)zlib;
  this->ZlibAlphaOffset = alphaPos;
  this->JpegReader = reader;
  this->Format = format;
  args.pUpdateSync = sync;
  args.Use = use;
  args.pHeap = 0;
  args.pManager = 0;
  args.Format = Image_R8G8B8;
  v11 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  CreateMemoryBufferImage = reader->CreateMemoryBufferImage;
  args.pHeap = v11;
  v13 = ((int (__thiscall *)(Scaleform::Render::JPEG::AbstractReader *, Scaleform::File *, Scaleform::Render::ImageCreateArgs *, const Scaleform::Render::Size<unsigned long> *, unsigned int, _DWORD))CreateMemoryBufferImage)(
          reader,
          file,
          &args,
          size,
          length,
          0);
  pObject = this->pImage.pObject;
  v15 = (Scaleform::Render::Image *)v13;
  if ( pObject )
    pObject->Release(pObject);
  this->pImage.pObject = v15;
}
