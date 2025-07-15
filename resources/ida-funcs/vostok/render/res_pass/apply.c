void __usercall vostok::render::res_pass::apply(vostok::render::res_pass *this@<ecx>, _DWORD *a2@<eax>)
{
  vostok::render::res_xs<vostok::render::gs_data> *v3; // ecx
  vostok::render::res_xs<vostok::render::ps_data> *v4; // ecx
  _DWORD *v5; // ecx
  int v6; // esi
  float z; // eax
  bool v8; // zf
  int v9; // esi
  int v10; // esi
  int v11; // ecx

  vostok::render::res_xs<vostok::render::vs_data>::apply((vostok::render::res_xs<vostok::render::vs_data> *)this, a2[2]);
  vostok::render::res_xs<vostok::render::gs_data>::apply(v3, a2[3]);
  vostok::render::res_xs<vostok::render::ps_data>::apply(v4, a2[4]);
  v5 = (_DWORD *)a2[1];
  v6 = v5[1];
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  v8 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 328) == v6;
  *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 328) = v6;
  *(_BYTE *)(LODWORD(z) + 94) |= !v8;
  v9 = v5[2];
  v8 = *(_DWORD *)(LODWORD(z) + 332) == v9;
  *(_DWORD *)(LODWORD(z) + 332) = v9;
  *(_BYTE *)(LODWORD(z) + 95) |= !v8;
  v10 = v5[3];
  v8 = *(_DWORD *)(LODWORD(z) + 336) == v10;
  *(_DWORD *)(LODWORD(z) + 336) = v10;
  *(_BYTE *)(LODWORD(z) + 96) |= !v8;
  v11 = v5[4];
  *(_BYTE *)(LODWORD(z) + 95) |= *(_DWORD *)(LODWORD(z) + 340) != v11;
  *(_DWORD *)(LODWORD(z) + 340) = v11;
}
