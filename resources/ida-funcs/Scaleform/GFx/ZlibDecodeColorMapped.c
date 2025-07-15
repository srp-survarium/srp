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
  int v12; // [esp+8h] [ebp-F78h]
  unsigned __int8 *v13; // [esp+Ch] [ebp-F74h]
  unsigned int v14; // [esp+10h] [ebp-F70h]
  Scaleform::Render::ImageScanlineBufferImpl v15; // [esp+14h] [ebp-F6Ch] BYREF
  unsigned __int8 tempBuffer[768]; // [esp+38h] [ebp-F48h] BYREF
  Scaleform::Render::ImageScanlineBufferImpl v17; // [esp+338h] [ebp-C48h] BYREF
  unsigned __int8 v18[1024]; // [esp+35Ch] [ebp-C24h] BYREF
  Scaleform::Render::ImageScanlineBufferImpl v19; // [esp+75Ch] [ebp-824h] BYREF
  unsigned __int8 v20[2048]; // [esp+780h] [ebp-800h] BYREF

  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v15,
    Image_R8G8B8,
    params->ColorTableSize,
    Image_R8G8B8,
    tempBuffer,
    0x300u);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v17,
    Image_A8,
    params->Size.Width,
    Image_A8,
    v18,
    0x400u);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v19,
    Image_R8G8B8,
    params->Size.Width,
    params->Format,
    v20,
    0x800u);
  v4 = 3 * params->ColorTableSize;
  v5 = (params->Size.Width + 3) & 0xFFFFFFFC;
  v14 = v5;
  if ( params->ZlibFile.pObject->Read(params->ZlibFile.pObject, v15.pReadScanline, v4) == v4 )
  {
    pReadScanline = v15.pReadScanline;
    v7 = v17.pReadScanline;
    v13 = v19.pReadScanline;
    v12 = 0;
    if ( !params->Size.Height )
    {
LABEL_3:
      Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v19);
      Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17);
      Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v15);
      return 1;
    }
    while ( params->ZlibFile.pObject->Read(params->ZlibFile.pObject, v7, v5) == v5 )
    {
      v9 = 0;
      if ( params->Size.Width )
      {
        v10 = v13 + 2;
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
        &v19,
        &pdest->pPlanes->pData[v12 * pdest->pPlanes->Pitch],
        0,
        copyScanline,
        arg);
      if ( ++v12 >= params->Size.Height )
        goto LABEL_3;
      v5 = v14;
    }
  }
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v19);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v15);
  return 0;
}
