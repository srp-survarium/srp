const vostok::fixed_vector<vostok::render::effect_compiler::shader_cache_info,32> *__usercall vostok::render::effect_compiler::get_cached_shaders_info@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<edx>,
        _DWORD *a3@<esi>)
{
  vostok::render::effect_compiler::shader_cache_info *v3; // ecx
  int v4; // ebx
  int v6; // [esp+Ch] [ebp-8h]
  const vostok::render::effect_compiler::shader_cache_info *v7; // [esp+10h] [ebp-4h]

  v3 = (vostok::render::effect_compiler::shader_cache_info *)(a3 + 3);
  a3[2] = a3 + 7043;
  a3[1] = a3 + 3;
  *a3 = a3 + 3;
  v6 = *(_DWORD *)(a2 + 16);
  v4 = *(_DWORD *)(a2 + 12);
  v7 = (const vostok::render::effect_compiler::shader_cache_info *)(a3 + 3);
  a3[1] = &a3[220 * ((v6 - v4) / 880) + 3];
  while ( v4 != v6 )
  {
    if ( v7 )
      vostok::render::effect_compiler::shader_cache_info::shader_cache_info(v3, v7, v4);
    v4 += 880;
    ++v7;
  }
  return (const vostok::fixed_vector<vostok::render::effect_compiler::shader_cache_info,32> *)a3;
}
