void __usercall vostok::render::res_texture::desc_update(vostok::render::res_texture *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  D3D11_RESOURCE_DIMENSION type; // [esp+10h] [ebp-4h] BYREF

  type = (D3D11_RESOURCE_DIMENSION)this;
  v2 = *(_DWORD *)(a2 + 420);
  *(_DWORD *)(a2 + 424) = v2;
  if ( v2 )
  {
    (*(void (__stdcall **)(int, D3D11_RESOURCE_DIMENSION *))(*(_DWORD *)v2 + 28))(v2, &type);
    if ( type == D3D11_RESOURCE_DIMENSION_TEXTURE2D )
    {
      (*(void (__stdcall **)(_DWORD, int))(**(_DWORD **)(a2 + 424) + 40))(*(_DWORD *)(a2 + 424), a2 + 64);
      *(_BYTE *)(a2 + 436) = 1;
    }
    if ( type == D3D11_RESOURCE_DIMENSION_TEXTURE3D )
    {
      (*(void (__stdcall **)(_DWORD, int))(**(_DWORD **)(a2 + 424) + 40))(*(_DWORD *)(a2 + 424), a2 + 108);
      *(_BYTE *)(a2 + 437) = 1;
    }
  }
}
