void __usercall vostok::render::scene::update_models(vostok::render::scene *this@<ecx>, int a2@<eax>)
{
  _DWORD *v2; // esi
  _DWORD *i; // edi

  v2 = *(_DWORD **)(a2 + 932);
  for ( i = *(_DWORD **)(a2 + 936); v2 != i; ++v2 )
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v2 + 28))(*v2);
}
