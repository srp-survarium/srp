bool __cdecl Scaleform::GFx::JpegAlphaDecodeHelper(
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::JPEG::Input *jin,
        const unsigned __int8 *alphaZlibData,
        int alphaZlibDataSize,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  int v7; // ecx
  int v8; // esi
  Scaleform::File *v9; // esi
  bool (__thiscall *HasError)(Scaleform::Render::JPEG::Input *); // edx
  int v11; // ebx
  unsigned int v12; // esi
  unsigned __int8 *pReadScanline; // eax
  Scaleform::Render::ImageScanlineBuffer<2048> *v14; // ecx
  bool Success; // bl
  void *v16; // esi
  unsigned int width; // [esp+10h] [ebp-351Ch] BYREF
  unsigned int v19; // [esp+14h] [ebp-3518h]
  int v20; // [esp+18h] [ebp-3514h]
  Scaleform::MemoryFile v21; // [esp+1Ch] [ebp-3510h] BYREF
  Scaleform::GFx::Params params; // [esp+38h] [ebp-34F4h] BYREF

  v8 = v7;
  jin->GetSize(jin, (Scaleform::Render::Size<unsigned long> *)&width);
  Scaleform::MemoryFile::MemoryFile(&v21, (char *)uri, alphaZlibData, alphaZlibDataSize);
  Scaleform::GFx::`anonymous namespace'::Params::Params(&params, jin, width, format);
  v9 = (Scaleform::File *)(*(int (__thiscall **)(int, Scaleform::MemoryFile *))(*(_DWORD *)v8 + 4))(v8, &v21);
  if ( params.ZlibFile.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)params.ZlibFile.pObject);
  HasError = jin->HasError;
  params.ZlibFile.pObject = v9;
  if ( HasError(jin) )
  {
    params.Success = 0;
  }
  else
  {
    v11 = 1;
    v12 = 0;
    v20 = 0;
    if ( v19 != -1 )
    {
      do
      {
        pReadScanline = params.ScanlineWithAlphas[v11]->pReadScanline;
        *(_DWORD *)pReadScanline = 0;
        *(_DWORD *)&pReadScanline[4 * width + 4] = 0;
        if ( v12 >= v19 )
        {
          memset((int)pReadScanline, 0, params.ScanlineWithAlphas[v11]->ReadScanlineSize);
        }
        else if ( !Scaleform::GFx::ReadAndUniteScanline(&params, pReadScanline + 4) )
        {
          break;
        }
        if ( (unsigned int)++v20 >= 2 )
        {
          Scaleform::GFx::UndoPremultiplyAlphaScanline(&params);
          Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
            &params.FinalScanline,
            &pdest->pPlanes->pData[pdest->pPlanes->Pitch * (v12 - 1)],
            0,
            copyScanline,
            arg);
        }
        if ( v11 == 2 )
        {
          v14 = params.ScanlineWithAlphas[2];
          params.ScanlineWithAlphas[2] = params.ScanlineWithAlphas[0];
          params.ScanlineWithAlphas[0] = params.ScanlineWithAlphas[1];
          params.ScanlineWithAlphas[1] = v14;
        }
        else
        {
          ++v11;
        }
        ++v12;
      }
      while ( v12 < v19 + 1 );
    }
  }
  ((void (__thiscall *)(Scaleform::Render::JPEG::Input *, int))jin->~Scaleform::Render::JPEG::Input)(jin, 1);
  Success = params.Success;
  if ( params.ZlibFile.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)params.ZlibFile.pObject);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&params.FinalScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&params.ScanlineWithAlpha2);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&params.ScanlineWithAlpha1);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&params.ScanlineWithAlpha0);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&params.AlphaScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&params.SourceScanline);
  v16 = (void *)(v21.FilePath.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v21.FilePath.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
  Scaleform::RefCountImplCore::~RefCountImplCore(&v21);
  return Success;
}
