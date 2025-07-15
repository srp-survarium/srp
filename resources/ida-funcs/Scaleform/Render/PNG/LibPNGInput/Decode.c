bool __thiscall Scaleform::Render::PNG::LibPNGInput::Decode(
        Scaleform::Render::PNG::LibPNGInput *this,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::Render::PNG::LibPNGInput *v5; // esi
  int v6; // edi
  bool result; // al
  Scaleform::Render::ImageFormat v8; // eax
  unsigned int ulRowBytes; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // edi
  unsigned int v13; // edi
  _DWORD *v14; // ebx
  unsigned int v15; // eax
  unsigned int j; // edi
  png_struct_def *png_ptr; // [esp-Ch] [ebp-2074h]
  Scaleform::Render::ImageScanlineBuffer<4096> v18; // [esp+Ch] [ebp-205Ch] BYREF
  Scaleform::Render::ImageScanlineBufferImpl v19; // [esp+1030h] [ebp-1038h] BYREF
  unsigned __int8 tempBuffer[4096]; // [esp+1054h] [ebp-1014h] BYREF
  unsigned int v21; // [esp+2054h] [ebp-14h]
  Scaleform::Render::PNG::LibPNGInput *v22; // [esp+2058h] [ebp-10h]
  void *i; // [esp+205Ch] [ebp-Ch]
  Scaleform::Render::ImageFormat readFormat; // [esp+2060h] [ebp-8h]
  bool v25; // [esp+2067h] [ebp-1h]

  v5 = this;
  v22 = this;
  v6 = 0;
  v25 = 1;
  result = Scaleform::Render::PNG::LibPNGInput::StartImage(this);
  if ( !result )
  {
    v5->IsInitialized = 0;
    return result;
  }
  if ( v5->Context.colorType == 2 )
  {
    v8 = Image_R8G8B8;
    v6 = 3 * v5->Context.width;
  }
  else if ( v5->Context.colorType == 6 )
  {
    v8 = Image_R8G8B8A8;
    v6 = 4 * v5->Context.width;
  }
  else
  {
    v8 = Image_None;
  }
  ulRowBytes = v5->Context.ulRowBytes;
  readFormat = v8;
  if ( ulRowBytes )
    v6 = ulRowBytes;
  v21 = (v6 + 3) & 0xFFFFFFFC;
  if ( v8 )
  {
    Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
      &v19,
      v8,
      v5->Context.width,
      format,
      tempBuffer,
      0x1000u);
    png_ptr = v5->Context.png_ptr;
    i = 0;
    v10 = png_set_longjmp_fn(png_ptr, longjmp, 64);
    v11 = _setjmp3(v10, 0);
    v5 = v22;
    if ( v11 )
    {
      png_destroy_read_struct(&v22->Context, &v22->Context.info_ptr, 0);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, i);
LABEL_13:
      v5->IsInitialized = 0;
      Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v19);
      return 0;
    }
    if ( v22->Context.interlaceType )
    {
      v13 = v21;
      v14 = Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, v22->Context.height * (v21 + 4), 0);
      v15 = 1;
      *v14 = &v14[v5->Context.height];
      for ( i = v14; v15 < v5->Context.height; ++v15 )
        v14[v15] = v13 + v14[v15 - 1];
      if ( !v5->ReadData(v5, (void **)v14) )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
        png_destroy_read_struct(&v5->Context, &v5->Context.info_ptr, 0);
        goto LABEL_13;
      }
      Scaleform::Render::ImageScanlineBuffer<4096>::ImageScanlineBuffer<4096>(
        &v18,
        readFormat,
        v5->Context.width,
        format);
      for ( j = 0; j < v5->Context.height; ++j )
      {
        memcpy((int)v18.pReadScanline, (const __m128i *)v14[j], v18.ReadScanlineSize);
        Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
          &v18,
          &pdest->pPlanes->pData[j * pdest->pPlanes->Pitch],
          0,
          copyScanline,
          arg);
      }
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
      Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v18);
    }
    else
    {
      v12 = 0;
      if ( v22->Context.height )
      {
        while ( v5->ReadScanline(v5, v19.pReadScanline) )
        {
          Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
            &v19,
            &pdest->pPlanes->pData[v12 * pdest->pPlanes->Pitch],
            0,
            copyScanline,
            arg);
          if ( ++v12 >= v5->Context.height )
            goto LABEL_27;
        }
        v25 = 0;
      }
    }
LABEL_27:
    png_read_end(v5->Context.png_ptr, 0);
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v19);
  }
  png_destroy_read_struct(&v5->Context, &v5->Context.info_ptr, 0);
  result = v25;
  v5->IsInitialized = 0;
  return result;
}
