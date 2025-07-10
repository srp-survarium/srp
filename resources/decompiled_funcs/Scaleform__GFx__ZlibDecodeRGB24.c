char __usercall Scaleform::GFx::ZlibDecodeRGB24@<al>(
        const Scaleform::GFx::ZlibDecodeParams *params@<esi>,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  unsigned __int8 *pReadScanline; // ebx
  int v5; // edi
  unsigned int v6; // ebp
  unsigned int v7; // ecx
  _BYTE *v8; // eax
  Scaleform::Render::ImageScanlineBufferImpl v10; // [esp+Ch] [ebp-1024h] BYREF
  unsigned __int8 tempBuffer[4096]; // [esp+30h] [ebp-1000h] BYREF

  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v10,
    Image_R8G8B8A8,
    params->Size.Width,
    params->Format,
    tempBuffer,
    0x1000u);
  pReadScanline = v10.pReadScanline;
  v5 = 0;
  v6 = (4 * params->Size.Width + 3) & 0xFFFFFFFC;
  if ( params->Size.Height )
  {
    while ( params->ZlibFile.pObject->Read(params->ZlibFile.pObject, pReadScanline, v6) == v6 )
    {
      v7 = 0;
      if ( params->Size.Width )
      {
        v8 = pReadScanline + 2;
        do
        {
          *(v8 - 2) = *(v8 - 1);
          *(v8 - 1) = *v8;
          *v8 = v8[1];
          v8[1] = -1;
          ++v7;
          v8 += 4;
        }
        while ( v7 < params->Size.Width );
      }
      Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        &v10,
        &pdest->pPlanes->pData[v5 * pdest->pPlanes->Pitch],
        0,
        copyScanline,
        arg);
      if ( ++v5 >= params->Size.Height )
        goto LABEL_7;
    }
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v10);
    return 0;
  }
  else
  {
LABEL_7:
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v10);
    return 1;
  }
}
