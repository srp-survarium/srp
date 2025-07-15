void __usercall vostok::render::res_texture::desc_update(vostok::render::res_texture *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  vostok::render::res_texture *v3; // [esp+0h] [ebp-4h] BYREF

  v3 = this;
  v2 = *(_DWORD *)(a2 + 440);
  *(_DWORD *)(a2 + 444) = v2;
  if ( v2 )
  {
    (*(void (__stdcall **)(int, vostok::render::res_texture **))(*(_DWORD *)v2 + 28))(v2, &v3);
    if ( v3 == (vostok::render::res_texture *)3 )
    {
      (*(void (__stdcall **)(_DWORD, int))(**(_DWORD **)(a2 + 444) + 40))(*(_DWORD *)(a2 + 444), a2 + 84);
      *(_BYTE *)(a2 + 456) = 1;
    }
    if ( v3 == (vostok::render::res_texture *)4 )
    {
      (*(void (__stdcall **)(_DWORD, int))(**(_DWORD **)(a2 + 444) + 40))(*(_DWORD *)(a2 + 444), a2 + 128);
      *(_BYTE *)(a2 + 457) = 1;
    }
  }
}
