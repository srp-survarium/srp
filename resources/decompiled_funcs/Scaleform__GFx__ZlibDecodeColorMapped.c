char __usercall Scaleform::GFx::ZlibDecodeColorMapped@<al>(
        const Scaleform::GFx::ZlibDecodeParams *params@<esi>,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  int v4; // ebx
  unsigned int v5; // edi
  unsigned __int8 *pReadScanline; // ebx
  unsigned __int8 *v7; // ebp
  unsigned int v9; // edi
  _BYTE *v10; // eax
  unsigned __int8 *v11; // ecx
  unsigned int y; // [esp+8h] [ebp-F78h]
  unsigned __int8 *outRow; // [esp+Ch] [ebp-F74h]
  int pitch; // [esp+10h] [ebp-F70h]
  Scaleform::Render::ImageScanlineBuffer<768> colorMap; // [esp+14h] [ebp-F6Ch] BYREF
  Scaleform::Render::ImageScanlineBuffer<1024> sourceScanline; // [esp+338h] [ebp-C48h] BYREF
  Scaleform::Render::ImageScanlineBuffer<2048> finalScanline; // [esp+75Ch] [ebp-824h] BYREF

  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &colorMap,
    Image_R8G8B8,
    params->ColorTableSize,
    Image_R8G8B8,
    colorMap.TempBuffer,
    0x300u);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &sourceScanline,
    Image_A8,
    params->Size.Width,
    Image_A8,
    sourceScanline.TempBuffer,
    0x400u);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &finalScanline,
    Image_R8G8B8,
    params->Size.Width,
    params->Format,
    finalScanline.TempBuffer,
    0x800u);
  v4 = 3 * params->ColorTableSize;
  v5 = (params->Size.Width + 3) & 0xFFFFFFFC;
  pitch = v5;
  if ( params->ZlibFile.pObject->Read(params->ZlibFile.pObject, colorMap.pReadScanline, v4) == v4 )
  {
    pReadScanline = colorMap.pReadScanline;
    v7 = sourceScanline.pReadScanline;
    outRow = finalScanline.pReadScanline;
    y = 0;
    if ( !params->Size.Height )
    {
LABEL_3:
      Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&finalScanline);
      Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&sourceScanline);
      Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&colorMap);
      return 1;
    }
    while ( params->ZlibFile.pObject->Read(params->ZlibFile.pObject, v7, v5) == v5 )
    {
      v9 = 0;
      if ( params->Size.Width )
      {
        v10 = outRow + 2;
        do
        {
          v11 = &pReadScanline[2 * v7[v9] + v7[v9]];
          *(v10 - 2) = *v11;
          *(v10 - 1) = v11[1];
          *v10 = v11[2];
          ++v9;
          v10 += 3;
        }
        while ( v9 < params->Size.Width );
      }
      Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        &finalScanline,
        &pdest->pPlanes->pData[y * pdest->pPlanes->Pitch],
        0,
        copyScanline,
        arg);
      if ( ++y >= params->Size.Height )
        goto LABEL_3;
      v5 = pitch;
    }
  }
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&finalScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&sourceScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&colorMap);
  return 0;
}
