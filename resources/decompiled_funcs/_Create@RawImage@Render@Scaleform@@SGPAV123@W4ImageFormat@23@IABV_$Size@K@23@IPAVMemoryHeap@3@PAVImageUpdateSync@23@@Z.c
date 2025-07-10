Scaleform::Render::RawImage *__stdcall Scaleform::Render::RawImage::Create(
        Scaleform::Render::ImageFormat format,
        unsigned int mipLevelCount,
        const Scaleform::Render::Size<unsigned long> *size,
        unsigned __int16 use,
        Scaleform::MemoryHeap *pheap,
        Scaleform::Render::ImageUpdateSync *pupdateSync)
{
  Scaleform::MemoryHeap *v6; // ecx
  Scaleform::Render::RawImage *v8; // eax
  int v9; // eax
  int v10; // ebp
  Scaleform::Render::ImageFormat v11; // ebx
  unsigned int v12; // esi
  unsigned int Width; // edi
  unsigned int MipLevelsSize; // ebx
  unsigned int *v15; // ecx
  unsigned int FormatPitch; // eax
  _DWORD *v17; // ecx
  int v18; // edx
  Scaleform::Render::Size<unsigned long> planeSize; // [esp+Ch] [ebp-8h] BYREF
  unsigned int usea; // [esp+24h] [ebp+10h]

  v6 = pheap;
  if ( !pheap )
  {
    pheap = Scaleform::Memory::pGlobalHeap;
    v6 = Scaleform::Memory::pGlobalHeap;
  }
  if ( (use & 2) != 0 && mipLevelCount != 1 )
    return 0;
  v8 = (Scaleform::Render::RawImage *)v6->Alloc(v6, 60u, 0);
  if ( v8 )
  {
    Scaleform::Render::RawImage::RawImage(v8);
    v10 = v9;
    if ( v9 )
    {
      Scaleform::Render::ImageData::Clear((Scaleform::Render::ImageData *)(v9 + 20));
      v11 = format;
      if ( Scaleform::Render::ImageData::allocPlanes(
             (Scaleform::Render::ImageData *)(v10 + 20),
             format,
             mipLevelCount,
             0) )
      {
        v12 = 0;
        *(_DWORD *)(v10 + 24) = use;
        *(_DWORD *)(v10 + 12) = pupdateSync;
        if ( !*(_WORD *)(v10 + 30) )
          return (Scaleform::Render::RawImage *)v10;
        usea = 0;
        while ( 1 )
        {
          if ( (format & 0xFFFu) - 200 <= 1 && (v12 == 1 || v12 == 2) )
          {
            Width = size->Width >> 1;
            planeSize.Height = size->Height >> 1;
          }
          else
          {
            Width = size->Width;
            planeSize.Height = size->Height;
          }
          planeSize.Width = Width;
          MipLevelsSize = Scaleform::Render::ImageData::GetMipLevelsSize(v11, &planeSize, mipLevelCount, v12);
          if ( !pheap->Alloc(pheap, MipLevelsSize, 0) )
            break;
          v15 = (unsigned int *)(usea + *(_DWORD *)(v10 + 32));
          v15[1] = planeSize.Height;
          *v15 = Width;
          FormatPitch = Scaleform::Render::ImageData::GetFormatPitch(format, Width, v12);
          usea += 20;
          v17[2] = FormatPitch;
          v17[3] = MipLevelsSize;
          v17[4] = v18;
          if ( ++v12 >= *(unsigned __int16 *)(v10 + 30) )
            return (Scaleform::Render::RawImage *)v10;
          v11 = format;
        }
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(v10);
    }
  }
  return 0;
}
