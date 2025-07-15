void __userpurge vostok::render::shader_constant_table::shader_constant_table(
        vostok::render::shader_constant_table *this@<ecx>,
        int a2@<edi>,
        const vostok::render::shader_constant_table *other)
{
  signed int v3; // esi
  unsigned int *v4; // eax
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v5; // [esp+0h] [ebp-10h]

  *(_DWORD *)a2 = 0;
  stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>(
    (stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *)this,
    &other->m_table._M_impl);
  v3 = (char *)other->m_const_buffers._M_impl._M_finish - (char *)other->m_const_buffers._M_impl._M_start;
  *(_DWORD *)(a2 + 16) = 0;
  v3 >>= 2;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  v4 = stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
         v3,
         v5);
  *(_DWORD *)(a2 + 16) = v4;
  *(_DWORD *)(a2 + 20) = v4;
  *(_DWORD *)(a2 + 24) = &v4[v3];
  *(_DWORD *)(a2 + 20) = stlp_std::priv::__ucopy<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,int>(
                           other->m_const_buffers._M_impl._M_finish,
                           (vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v4,
                           other->m_const_buffers._M_impl._M_start);
  *(_BYTE *)(a2 + 28) = 0;
}
