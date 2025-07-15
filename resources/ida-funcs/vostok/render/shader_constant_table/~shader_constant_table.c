void __thiscall vostok::render::shader_constant_table::~shader_constant_table(
        vostok::render::shader_constant_table *this,
        int a2)
{
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::destroy(
    *(vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 784),
    (vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *const *)(a2 + 788));
  *(_DWORD *)(a2 + 788) = *(_DWORD *)(a2 + 784);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a2 + 4);
}
