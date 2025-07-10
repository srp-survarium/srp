char __usercall Scaleform::GFx::ZlibDecodeRGBA@<al>(
        const Scaleform::GFx::ZlibDecodeParams *params@<esi>,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  unsigned int v4; // ebp
  int v5; // edx
  unsigned __int8 *pReadScanline; // eax
  Scaleform::Render::ImageScanlineBuffer<2048> **v7; // edx
  int v8; // edi
  unsigned __int8 *v9; // ebx
  unsigned int v10; // ecx
  _BYTE *v11; // eax
  char v12; // dl
  Scaleform::Render::ImageScanlineBuffer<2048> *v13; // ecx
  int v15; // [esp+Ch] [ebp-34FCh]
  int v16; // [esp+10h] [ebp-34F8h]
  Scaleform::GFx::Params v17; // [esp+14h] [ebp-34F4h] BYREF

  v4 = 0;
  Scaleform::GFx::`anonymous namespace'::Params::Params(&v17, 0, params->Size.Width, params->Format);
  v5 = 1;
  v15 = 1;
  v16 = 0;
  if ( params->Size.Height == -1 )
  {
LABEL_15:
    if ( v17.ZlibFile.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v17.ZlibFile.pObject);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.FinalScanline);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.ScanlineWithAlpha2);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.ScanlineWithAlpha1);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.ScanlineWithAlpha0);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.AlphaScanline);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.SourceScanline);
    return 1;
  }
  while ( 1 )
  {
    pReadScanline = v17.ScanlineWithAlphas[v5]->pReadScanline;
    v7 = &v17.ScanlineWithAlphas[v5];
    *(_DWORD *)pReadScanline = 0;
    *(_DWORD *)&pReadScanline[4 * params->Size.Width + 4] = 0;
    if ( v4 < params->Size.Height )
      break;
    memset((int)pReadScanline, 0, (*v7)->ReadScanlineSize);
LABEL_9:
    if ( (unsigned int)++v16 >= 2 )
    {
      Scaleform::GFx::UndoPremultiplyAlphaScanline(&v17);
      Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        &v17.FinalScanline,
        &pdest->pPlanes->pData[pdest->pPlanes->Pitch * (v4 - 1)],
        0,
        copyScanline,
        arg);
    }
    v5 = v15;
    if ( v15 == 2 )
    {
      v13 = v17.ScanlineWithAlphas[2];
      v17.ScanlineWithAlphas[2] = v17.ScanlineWithAlphas[0];
      v17.ScanlineWithAlphas[0] = v17.ScanlineWithAlphas[1];
      v17.ScanlineWithAlphas[1] = v13;
    }
    else
    {
      v5 = ++v15;
    }
    if ( ++v4 >= params->Size.Height + 1 )
      goto LABEL_15;
  }
  v8 = 4 * params->Size.Width;
  v9 = pReadScanline + 4;
  if ( params->ZlibFile.pObject->Read(params->ZlibFile.pObject, pReadScanline + 4, v8) == v8 )
  {
    v10 = 0;
    if ( params->Size.Width )
    {
      v11 = v9 + 2;
      do
      {
        v12 = *(v11 - 2);
        *(v11 - 2) = *(v11 - 1);
        *(v11 - 1) = *v11;
        *v11 = v11[1];
        v11[1] = v12;
        ++v10;
        v11 += 4;
      }
      while ( v10 < params->Size.Width );
    }
    goto LABEL_9;
  }
  if ( v17.ZlibFile.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v17.ZlibFile.pObject);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.FinalScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.ScanlineWithAlpha2);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.ScanlineWithAlpha1);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.ScanlineWithAlpha0);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.AlphaScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v17.SourceScanline);
  return 0;
}
