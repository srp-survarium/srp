char __usercall Scaleform::GFx::ZlibDecodeColorMappedAlpha@<al>(
        const Scaleform::GFx::ZlibDecodeParams *params@<esi>,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  int v4; // edi
  int v5; // ebx
  unsigned int v6; // edi
  Scaleform::Render::ImageScanlineBuffer<2048> **v7; // eax
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // ebp
  unsigned int v10; // edi
  _BYTE *v11; // eax
  unsigned __int8 *v12; // ecx
  Scaleform::Render::ImageScanlineBuffer<2048> *v13; // ecx
  unsigned int v15; // [esp+10h] [ebp-392Ch]
  int v16; // [esp+14h] [ebp-3928h]
  int v17; // [esp+18h] [ebp-3924h]
  unsigned int v18; // [esp+1Ch] [ebp-3920h]
  unsigned __int8 *pReadScanline; // [esp+20h] [ebp-391Ch]
  Scaleform::Render::ImageScanlineBufferImpl v20; // [esp+24h] [ebp-3918h] BYREF
  unsigned __int8 tempBuffer[1024]; // [esp+48h] [ebp-38F4h] BYREF
  Scaleform::GFx::Params v22; // [esp+448h] [ebp-34F4h] BYREF

  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v20,
    Image_R8G8B8A8,
    params->ColorTableSize,
    Image_R8G8B8A8,
    tempBuffer,
    0x400u);
  Scaleform::GFx::`anonymous namespace'::Params::Params(&v22, 0, params->Size.Width, params->Format);
  v4 = 4 * params->ColorTableSize;
  v18 = (params->Size.Width + 3) & 0xFFFFFFFC;
  pReadScanline = v20.pReadScanline;
  v5 = 1;
  v17 = 1;
  v16 = 0;
  if ( params->ZlibFile.pObject->Read(params->ZlibFile.pObject, v20.pReadScanline, v4) == v4 )
  {
    v6 = 0;
    v15 = 0;
    if ( params->Size.Height != -1 )
    {
      do
      {
        v7 = &v22.ScanlineWithAlphas[v5];
        v8 = (*v7)->pReadScanline;
        *(_DWORD *)v8 = 0;
        *(_DWORD *)&v8[4 * params->Size.Width + 4] = 0;
        if ( v6 >= params->Size.Height )
        {
          memset((int)v8, 0, (*v7)->ReadScanlineSize);
        }
        else
        {
          v9 = v22.AlphaScanline.pReadScanline;
          if ( params->ZlibFile.pObject->Read(params->ZlibFile.pObject, v22.AlphaScanline.pReadScanline, v18) != v18 )
            goto LABEL_19;
          v10 = 0;
          if ( params->Size.Width )
          {
            v11 = v8 + 6;
            do
            {
              v12 = &pReadScanline[4 * v9[v10]];
              *(v11 - 2) = *v12;
              *(v11 - 1) = v12[1];
              *v11 = v12[2];
              v11[1] = v12[3];
              ++v10;
              v11 += 4;
            }
            while ( v10 < params->Size.Width );
          }
          v6 = v15;
        }
        if ( (unsigned int)++v16 >= 2 )
        {
          Scaleform::GFx::UndoPremultiplyAlphaScanline(&v22);
          Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
            &v22.FinalScanline,
            &pdest->pPlanes->pData[pdest->pPlanes->Pitch * (v6 - 1)],
            0,
            copyScanline,
            arg);
        }
        v5 = v17;
        if ( v17 == 2 )
        {
          v13 = v22.ScanlineWithAlphas[2];
          v22.ScanlineWithAlphas[2] = v22.ScanlineWithAlphas[0];
          v22.ScanlineWithAlphas[0] = v22.ScanlineWithAlphas[1];
          v22.ScanlineWithAlphas[1] = v13;
        }
        else
        {
          v5 = ++v17;
        }
        v15 = ++v6;
      }
      while ( v6 < params->Size.Height + 1 );
    }
    if ( v22.ZlibFile.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v22.ZlibFile.pObject);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v22.FinalScanline);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v22.ScanlineWithAlpha2);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v22.ScanlineWithAlpha1);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v22.ScanlineWithAlpha0);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v22.AlphaScanline);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v22.SourceScanline);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v20);
    return 1;
  }
  else
  {
LABEL_19:
    Scaleform::GFx::`anonymous namespace'::Params::~Params(&v22);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v20);
    return 0;
  }
}
