char __usercall Scaleform::GFx::ZlibDecodeRGB16@<al>(
        const Scaleform::GFx::ZlibDecodeParams *params@<edi>,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  unsigned __int8 *pReadScanline; // ebp
  unsigned int v5; // esi
  int v6; // ebx
  unsigned int v8; // esi
  _BYTE *v9; // ecx
  unsigned int v10; // eax
  unsigned __int8 *v11; // [esp+Ch] [ebp-1850h]
  unsigned int v12; // [esp+10h] [ebp-184Ch]
  Scaleform::Render::ImageScanlineBufferImpl v13; // [esp+14h] [ebp-1848h] BYREF
  unsigned __int8 tempBuffer[2048]; // [esp+38h] [ebp-1824h] BYREF
  Scaleform::Render::ImageScanlineBufferImpl v15; // [esp+838h] [ebp-1024h] BYREF
  unsigned __int8 v16[4096]; // [esp+85Ch] [ebp-1000h] BYREF

  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v13,
    Image_A8,
    2 * params->Size.Width,
    Image_A8,
    tempBuffer,
    0x800u);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v15,
    Image_R8G8B8A8,
    params->Size.Width,
    params->Format,
    v16,
    0x1000u);
  pReadScanline = v13.pReadScanline;
  v5 = (2 * params->Size.Width + 3) & 0xFFFFFFFC;
  v6 = 0;
  v12 = v5;
  v11 = v15.pReadScanline;
  if ( params->Size.Height )
  {
    while ( params->ZlibFile.pObject->Read(params->ZlibFile.pObject, pReadScanline, v5) == v5 )
    {
      v8 = 0;
      if ( params->Size.Width )
      {
        v9 = v11 + 2;
        do
        {
          v10 = *(unsigned __int16 *)&pReadScanline[2 * v8];
          *(v9 - 2) = (v10 >> 7) & 0xF8;
          *(v9 - 1) = (v10 >> 2) & 0xF8;
          *v9 = 8 * v10;
          v9[1] = -1;
          ++v8;
          v9 += 4;
        }
        while ( v8 < params->Size.Width );
      }
      Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        &v15,
        &pdest->pPlanes->pData[v6 * pdest->pPlanes->Pitch],
        0,
        copyScanline,
        arg);
      if ( ++v6 >= params->Size.Height )
        goto LABEL_2;
      v5 = v12;
    }
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v15);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v13);
    return 0;
  }
  else
  {
LABEL_2:
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v15);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v13);
    return 1;
  }
}
