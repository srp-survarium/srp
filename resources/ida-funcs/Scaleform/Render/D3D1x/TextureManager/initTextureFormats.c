void __thiscall Scaleform::Render::D3D1x::TextureManager::initTextureFormats(
        Scaleform::Render::D3D1x::TextureManager *this,
        int a2)
{
  Scaleform::Render::D3D1x::TextureFormat::Mapping *i; // edi
  _DWORD *v4; // eax
  _BYTE v5[4]; // [esp+8h] [ebp-4h] BYREF
  _DWORD *v6; // [esp+14h] [ebp+8h]

  for ( i = Scaleform::Render::D3D1x::TextureFormatMapping; i->Format; ++i )
  {
    if ( (*(int (__stdcall **)(_DWORD, DXGI_FORMAT, _BYTE *))(**(_DWORD **)(a2 + 88) + 116))(
           *(_DWORD *)(a2 + 88),
           i->D3DFormat,
           v5) >= 0
      && (v5[0] & 0x20) != 0 )
    {
      v4 = Scaleform::NewOverrideBase<75>::operator new(0xCu, (Scaleform::MemAddressStub *)a2);
      if ( v4 )
      {
        v4[2] = 0;
        *v4 = &Scaleform::Render::D3D1x::TextureFormat::`vftable';
        v4[1] = i;
        v6 = v4;
      }
      else
      {
        v6 = 0;
      }
      Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy> *)(a2 + 52),
        (void *)(a2 + 52),
        *(_DWORD *)(a2 + 56) + 1);
      if ( *(_DWORD *)(a2 + 52) + 4 * *(_DWORD *)(a2 + 56) != 4 )
        *(_DWORD *)(*(_DWORD *)(a2 + 52) + 4 * *(_DWORD *)(a2 + 56) - 4) = v6;
      while ( i[1].Format == i->Format )
        ++i;
    }
  }
}
