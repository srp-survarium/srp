void __usercall vostok::render::vs_data::vs_data(vostok::render::vs_data *this@<ecx>, int a2@<esi>)
{
  *(_DWORD *)(a2 + 4) = 0;
  *(_WORD *)a2 = 0;
  vostok::render::shader_constant_table::shader_constant_table((vostok::render::shader_constant_table *)this, a2 + 8);
  *(_DWORD *)(a2 + 936) = a2 + 948;
  *(_DWORD *)(a2 + 940) = a2 + 948;
  *(_DWORD *)(a2 + 944) = a2 + 2292;
  *(_DWORD *)(a2 + 2292) = a2 + 2304;
  *(_DWORD *)(a2 + 2296) = a2 + 2304;
  *(_DWORD *)(a2 + 2300) = a2 + 13056;
  *(_DWORD *)(a2 + 13056) = a2 + 13068;
  *(_DWORD *)(a2 + 13060) = a2 + 13068;
  *(_DWORD *)(a2 + 13064) = a2 + 23820;
  *(_DWORD *)(a2 + 23820) = 0;
}
