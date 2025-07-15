void __thiscall vostok::render::effect_compiler::shader_cache_info::shader_cache_info(
        vostok::render::effect_compiler::shader_cache_info *this,
        const vostok::render::effect_compiler::shader_cache_info *__that,
        int a3)
{
  vostok::fixed_string<260>::fixed_string<260>(
    &__that->vertex_shader_name.m_string,
    (const vostok::fixed_string<260> *)a3);
  __that->vertex_shader_name.m_separator = 47;
  vostok::fixed_string<260>::fixed_string<260>(
    &__that->pixel_shader_name.m_string,
    (const vostok::fixed_string<260> *)(a3 + 276));
  __that->pixel_shader_name.m_separator = 47;
  vostok::fixed_string<260>::fixed_string<260>(
    &__that->geometry_shader_name.m_string,
    (const vostok::fixed_string<260> *)(a3 + 552));
  __that->geometry_shader_name.m_separator = 47;
  __that->vs_configuration = *(vostok::render::shader_configuration *)(a3 + 832);
  __that->ps_configuration = *(vostok::render::shader_configuration *)(a3 + 848);
  __that->gs_configuration = *(vostok::render::shader_configuration *)(a3 + 864);
}


void __usercall vostok::render::effect_compiler::shader_cache_info::shader_cache_info(
        vostok::render::effect_compiler::shader_cache_info *this@<ecx>,
        int a2@<esi>)
{
  vostok::fs_new::virtual_path_string *v2; // ecx
  vostok::fs_new::virtual_path_string *v3; // ecx
  char v4; // dl
  char v5; // dl

  vostok::fs_new::virtual_path_string::virtual_path_string(&this->vertex_shader_name, a2);
  vostok::fs_new::virtual_path_string::virtual_path_string(v2, a2 + 276);
  vostok::fs_new::virtual_path_string::virtual_path_string(v3, a2 + 552);
  *(_DWORD *)(a2 + 840) = 0;
  v4 = *(_BYTE *)(a2 + 842);
  *(_DWORD *)(a2 + 832) = 0;
  *(_DWORD *)(a2 + 836) = 0;
  *(_DWORD *)(a2 + 844) = 0;
  *(_BYTE *)(a2 + 842) = v4 & 0xF1 | 8;
  *(_DWORD *)(a2 + 856) = 0;
  v5 = *(_BYTE *)(a2 + 858);
  *(_DWORD *)(a2 + 848) = 0;
  *(_DWORD *)(a2 + 852) = 0;
  *(_DWORD *)(a2 + 860) = 0;
  *(_BYTE *)(a2 + 858) = v5 & 0xF1 | 8;
  *(_DWORD *)(a2 + 872) = 0;
  *(_DWORD *)(a2 + 864) = 0;
  *(_DWORD *)(a2 + 868) = 0;
  *(_DWORD *)(a2 + 876) = 0;
  *(_BYTE *)(a2 + 874) = *(_BYTE *)(a2 + 874) & 0xF1 | 8;
}
