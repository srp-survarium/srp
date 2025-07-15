char __thiscall Scaleform::GFx::ZlibImageSource::Decode(
        Scaleform::GFx::ZlibImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::Render::ImageFormat Format; // eax
  Scaleform::GFx::ZlibImageSource::SourceBitmapDataFormat BitmapFormatId; // ecx
  unsigned int Width; // edx
  unsigned int Height; // eax
  Scaleform::GFx::ZlibSupportBase *pObject; // ecx
  Scaleform::File *v10; // eax
  Scaleform::File *v11; // edi
  char v12; // bl
  Scaleform::GFx::ZlibDecodeParams params; // [esp+Ch] [ebp-18h] BYREF

  Format = this->Format;
  BitmapFormatId = this->BitmapFormatId;
  Width = this->Size.Width;
  params.Format = Format;
  Height = this->Size.Height;
  params.SrcFormat = BitmapFormatId;
  pObject = this->Zlib.pObject;
  params.Size.Height = Height;
  v10 = this->pFile.pObject;
  params.Size.Width = Width;
  v11 = pObject->CreateZlibFile(pObject, v10);
  params.ColorTableSize = this->ColorTableSize;
  params.ZlibFile.pObject = v11;
  v12 = Scaleform::GFx::ZlibDecodeHelper(copyScanline, arg, &params, pdest);
  if ( v11 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v11);
  return v12;
}
