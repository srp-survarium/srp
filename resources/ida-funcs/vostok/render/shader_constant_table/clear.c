void __usercall vostok::render::shader_constant_table::clear(
        vostok::render::shader_constant_table *this@<ecx>,
        int a2@<esi>)
{
  vostok::render::shader_constant *v2; // eax
  vostok::render::shader_constant *v3; // ecx
  const vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // eax
  vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // ecx
  vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // ebx

  v2 = *(vostok::render::shader_constant **)(a2 + 8);
  v3 = *(vostok::render::shader_constant **)(a2 + 4);
  if ( v3 != v2 )
    *(_DWORD *)(a2 + 8) = stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
                            v2,
                            v3,
                            v2);
  v4 = *(const vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 20);
  v5 = *(vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 16);
  if ( v5 != v4 )
  {
    v6 = stlp_std::priv::__copy<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> const *,vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,int>(
           v4,
           v5,
           *(const vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 20));
    stlp_std::_Destroy_Range<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>(
      v6,
      *(vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 20));
    *(_DWORD *)(a2 + 20) = v6;
  }
}
