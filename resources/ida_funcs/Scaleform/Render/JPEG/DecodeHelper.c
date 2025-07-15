char __usercall Scaleform::Render::JPEG::DecodeHelper@<al>(
        Scaleform::Render::JPEG::Input *jin@<edi>,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  int v5; // esi
  char v7; // [esp+Dh] [ebp-102Dh]
  unsigned int width; // [esp+Eh] [ebp-102Ch] BYREF
  unsigned int v9; // [esp+12h] [ebp-1028h]
  Scaleform::Render::ImageScanlineBufferImpl v10; // [esp+16h] [ebp-1024h] BYREF
  unsigned __int8 tempBuffer[4096]; // [esp+3Ah] [ebp-1000h] BYREF

  jin->GetSize(jin, (Scaleform::Render::Size<unsigned long> *)&width);
  v7 = 0;
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v10,
    Image_R8G8B8,
    width,
    format,
    tempBuffer,
    0x1000u);
  if ( v10.ReadFormat )
  {
    if ( v10.Width )
    {
      if ( v10.pReadScanline )
      {
        if ( !jin->HasError(jin) )
        {
          v5 = 0;
          v7 = 1;
          if ( v9 )
          {
            while ( jin->ReadScanline(jin, v10.pReadScanline) )
            {
              Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
                &v10,
                &pdest->pPlanes->pData[v5 * pdest->pPlanes->Pitch],
                0,
                copyScanline,
                arg);
              if ( ++v5 >= v9 )
                goto LABEL_10;
            }
            v7 = 0;
          }
        }
      }
    }
  }
LABEL_10:
  ((void (__thiscall *)(Scaleform::Render::JPEG::Input *, int))jin->~Scaleform::Render::JPEG::Input)(jin, 1);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v10);
  return v7;
}
