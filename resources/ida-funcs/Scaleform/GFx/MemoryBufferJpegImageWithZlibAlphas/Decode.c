bool __thiscall Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas::Decode(
        Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::Render::Image *pObject; // eax
  const unsigned __int8 *pInverseMatrix; // ebp
  unsigned int v7; // edi
  Scaleform::Render::JPEG::Input *v8; // ebx

  pObject = this->pImage.pObject;
  pInverseMatrix = (const unsigned __int8 *)pObject[1].pInverseMatrix;
  v7 = (unsigned int)pObject[2].__vftable;
  v8 = this->JpegReader->CreateSwfJpeg2HeaderOnly(this->JpegReader, pInverseMatrix, v7);
  if ( !v8 )
    return 0;
  v8->StartImage(v8);
  return Scaleform::GFx::JpegAlphaDecodeHelper(
           this->Format,
           v8,
           &pInverseMatrix[this->ZlibAlphaOffset],
           v7 - this->ZlibAlphaOffset,
           pdest,
           copyScanline,
           arg);
}
