const vostok::vectora<vostok::render::effect_compiler::shader_cache_info> *__usercall vostok::render::effect_compiler::get_cached_shaders_info@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        stlp_std::priv::_Vector_base<vostok::render::effect_compiler::shader_cache_info,vostok::vectora_allocator<vostok::render::effect_compiler::shader_cache_info> > *a2@<eax>,
        int a3@<edi>)
{
  int v3; // ecx
  vostok::vectora_allocator<vostok::render::effect_compiler::shader_cache_info> __a; // [esp+0h] [ebp-4h] BYREF

  __a.m_allocator = (vostok::memory::base_allocator *)this;
  v3 = *(_DWORD *)(a3 + 12) - *(_DWORD *)(a3 + 8);
  __a.m_allocator = *(vostok::memory::base_allocator **)(a3 + 16);
  stlp_std::priv::_Vector_base<vostok::render::effect_compiler::shader_cache_info,vostok::vectora_allocator<vostok::render::effect_compiler::shader_cache_info>>::_Vector_base<vostok::render::effect_compiler::shader_cache_info,vostok::vectora_allocator<vostok::render::effect_compiler::shader_cache_info>>(
    a2,
    v3 / 848,
    &__a);
  a2->_M_finish = stlp_std::priv::__ucopy<vostok::render::effect_compiler::shader_cache_info const *,vostok::render::effect_compiler::shader_cache_info *,int>(
                    *(const vostok::render::effect_compiler::shader_cache_info **)(a3 + 8),
                    *(const vostok::render::effect_compiler::shader_cache_info **)(a3 + 12),
                    a2->_M_start);
  return (const vostok::vectora<vostok::render::effect_compiler::shader_cache_info> *)a2;
}
