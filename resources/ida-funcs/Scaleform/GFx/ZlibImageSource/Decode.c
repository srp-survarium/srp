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
  Scaleform::GFx::ZlibDecodeParams v14; // [esp+Ch] [ebp-18h] BYREF

  Format = this->Format;
  BitmapFormatId = this->BitmapFormatId;
  Width = this->Size.Width;
  v14.Format = Format;
  Height = this->Size.Height;
  v14.SrcFormat = BitmapFormatId;
  pObject = this->Zlib.pObject;
  v14.Size.Height = Height;
  v10 = this->pFile.pObject;
  v14.Size.Width = Width;
  v11 = pObject->CreateZlibFile(pObject, v10);
  v14.ColorTableSize = this->ColorTableSize;
  v14.ZlibFile.pObject = v11;
  v12 = Scaleform::GFx::ZlibDecodeHelper(copyScanline, arg, &v14, pdest);
  if ( v11 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v11);
  return v12;
}
