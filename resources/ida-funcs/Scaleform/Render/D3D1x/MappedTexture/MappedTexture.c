void __usercall Scaleform::Render::D3D1x::MappedTexture::MappedTexture(
        Scaleform::Render::D3D1x::MappedTexture *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax
  int i; // ecx

  *(_DWORD *)a2 = &Scaleform::Render::MappedTextureBase::`vftable';
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  Scaleform::Render::ImageData::ImageData((Scaleform::Render::ImageData *)(a2 + 16));
  v2 = (_DWORD *)(a2 + 56);
  for ( i = 3; i >= 0; --i )
  {
    *v2 = 0;
    v2[1] = 0;
    v2[2] = 0;
    v2[3] = 0;
    v2[4] = 0;
    v2 += 5;
  }
  *(_DWORD *)a2 = &Scaleform::Render::D3D1x::MappedTexture::`vftable';
}
