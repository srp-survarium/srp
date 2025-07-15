void __usercall vostok::render::shader_macro::shader_macro(vostok::render::shader_macro *this@<ecx>, int a2@<esi>)
{
  vostok::fs_new::virtual_path_string::virtual_path_string(&this->name, a2);
  *(_DWORD *)(a2 + 276) = a2 + 288;
  *(_DWORD *)(a2 + 280) = a2 + 288;
  *(_DWORD *)(a2 + 284) = a2 + 544;
  *(_BYTE *)(a2 + 288) = 0;
  *(_BYTE *)(a2 + 288) = 0;
}
