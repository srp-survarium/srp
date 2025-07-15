bool __thiscall Scaleform::Render::DDS::DDSFileImageSource::Decode(
        Scaleform::Render::DDS::DDSFileImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  bool result; // al
  unsigned int Height; // ebx
  Scaleform::Render::ImageData *v7; // edi
  unsigned int v8; // ebp
  bool v9; // zf
  unsigned int FormatPlaneCount; // eax
  unsigned int ReadScanlineSize; // edi
  int v12; // ebp
  Scaleform::Render::ImageFormat Format; // edx
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int width; // [esp+8h] [ebp-1044h]
  unsigned int v17; // [esp+Ch] [ebp-1040h]
  unsigned int v18; // [esp+10h] [ebp-103Ch]
  Scaleform::Render::ImagePlane pplane; // [esp+14h] [ebp-1038h] BYREF
  Scaleform::Render::ImageScanlineBufferImpl v20; // [esp+28h] [ebp-1024h] BYREF
  unsigned __int8 tempBuffer[4096]; // [esp+4Ch] [ebp-1000h] BYREF

  result = Scaleform::Render::FileImageSource::seekFileToDecodeStart(this);
  if ( result )
  {
    Height = this->Size.Height;
    v7 = pdest;
    width = this->Size.Width;
    v8 = 0;
    v17 = 0;
    if ( pdest->LevelCount )
    {
      while ( 1 )
      {
        v9 = (v7->Flags & 1) == 0;
        memset(&pplane, 0, sizeof(pplane));
        if ( v9 )
        {
          Scaleform::Render::ImagePlane::GetMipLevel(v7->pPlanes, v7->Format, v8, &pplane, 0);
        }
        else
        {
          FormatPlaneCount = Scaleform::Render::ImageData::GetFormatPlaneCount(v7->Format);
          Scaleform::Render::ImageData::GetPlane(v7, v8 * FormatPlaneCount, &pplane);
        }
        Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
          &v20,
          this->HeaderInfo.Format,
          width,
          this->Format,
          tempBuffer,
          0x1000u);
        ReadScanlineSize = v20.ReadScanlineSize;
        v18 = v20.ReadScanlineSize;
        if ( v20.ReadFormat == Image_None || !v20.Width || !v20.pReadScanline )
          break;
        v12 = 0;
        if ( Scaleform::Render::ImageData::GetFormatScanlineCount(this->Format, Height, 0) )
        {
          while ( this->pFile.pObject->Read(this->pFile.pObject, v20.pReadScanline, ReadScanlineSize) == ReadScanlineSize )
          {
            Format = this->Format;
            if ( Format == Image_R8G8B8A8 || Format == Image_R8G8B8 )
            {
              Scaleform::Render::DDS::ProcessUDDSData(v18, Format, &this->HeaderInfo.DDSFmt, v20.pReadScanline);
              ReadScanlineSize = v18;
            }
            Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
              &v20,
              &pplane.pData[v12 * pplane.Pitch],
              0,
              copyScanline,
              arg);
            if ( ++v12 >= Scaleform::Render::ImageData::GetFormatScanlineCount(this->Format, Height, 0) )
              goto LABEL_15;
          }
          break;
        }
LABEL_15:
        v14 = width >> 1;
        width = 1;
        if ( v14 )
          width = v14;
        Height >>= 1;
        if ( !Height )
          Height = 1;
        Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v20);
        v15 = v17 + 1;
        v17 = v15;
        if ( v15 >= pdest->LevelCount )
          return 1;
        v8 = v15;
        v7 = pdest;
      }
      Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v20);
      return 0;
    }
    else
    {
      return 1;
    }
  }
  return result;
}
