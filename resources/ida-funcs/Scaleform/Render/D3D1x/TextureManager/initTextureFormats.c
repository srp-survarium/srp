void __thiscall Scaleform::Render::D3D1x::TextureManager::initTextureFormats(
        Scaleform::Render::D3D1x::TextureManager *this,
        unsigned int formatSupport)
{
  unsigned int v2; // ebx
  Scaleform::Render::D3D1x::TextureFormat::Mapping *i; // edi
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  _DWORD *v5; // eax
  _DWORD *v6; // ebp
  int v7; // ecx
  int v8; // edx
  Scaleform::Render::ImageFormat Format; // ecx
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v2 = formatSupport;
  for ( i = Scaleform::Render::D3D1x::TextureFormatMapping; i->Format; ++i )
  {
    if ( (*(int (__stdcall **)(_DWORD, DXGI_FORMAT, unsigned int *))(**(_DWORD **)(v2 + 88) + 116))(
           *(_DWORD *)(v2 + 88),
           i->D3DFormat,
           &formatSupport) >= 0
      && (formatSupport & 0x20) != 0 )
    {
      AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
      v10 = 75;
      v5 = (_DWORD *)AllocAutoHeap(
                       Scaleform::Memory::pGlobalHeap,
                       (const void *)v2,
                       12u,
                       (const Scaleform::AllocInfo *)&v10);
      if ( v5 )
      {
        *v5 = &Scaleform::Render::D3D1x::TextureFormat::`vftable';
        v5[1] = i;
        v5[2] = 0;
        v6 = v5;
      }
      else
      {
        v6 = 0;
      }
      Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy> *)(v2 + 52),
        (const void *)(v2 + 52),
        *(_DWORD *)(v2 + 56) + 1);
      v7 = *(_DWORD *)(v2 + 56);
      v8 = *(_DWORD *)(v2 + 52);
      if ( v8 + 4 * v7 != 4 )
        *(_DWORD *)(v8 + 4 * v7 - 4) = v6;
      if ( i[1].Format == i->Format )
      {
        do
        {
          Format = i[2].Format;
          ++i;
        }
        while ( Format == i->Format );
      }
    }
  }
}
