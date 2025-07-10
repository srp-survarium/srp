void __userpurge stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>(
        stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *this@<ecx>,
        vostok::render::shader_constant **a2@<esi>,
        const stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *__x)
{
  int v3; // ecx
  int v4; // edi
  vostok::render::shader_constant *v5; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *v6; // [esp+0h] [ebp-8h]
  const stlp_std::random_access_iterator_tag *v7; // [esp+0h] [ebp-8h]
  int *v8; // [esp+4h] [ebp-4h]

  v3 = (char *)__x->_M_finish - (char *)__x->_M_start;
  *a2 = 0;
  a2[1] = 0;
  v4 = v3 / 24;
  a2[2] = 0;
  v5 = (vostok::render::shader_constant *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::shader_constant *,vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::allocate(
                                            v3 / 24,
                                            v6);
  *a2 = v5;
  a2[1] = v5;
  a2[2] = &v5[v4];
  a2[1] = stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
            __x->_M_start,
            __x->_M_finish,
            v5,
            v7,
            v8);
}
