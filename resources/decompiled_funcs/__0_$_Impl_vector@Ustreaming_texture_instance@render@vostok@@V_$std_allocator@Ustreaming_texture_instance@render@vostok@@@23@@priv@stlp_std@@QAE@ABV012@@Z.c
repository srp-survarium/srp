void __userpurge stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>(
        stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        const stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *__x)
{
  int v3; // ecx
  int v4; // edi
  unsigned __int8 *v5; // eax
  vostok::render::streaming_texture_instance *M_finish; // edi
  unsigned __int8 *M_start; // ebx
  unsigned int v8; // edi
  int v9; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *v10; // [esp+0h] [ebp-8h]

  v3 = (char *)__x->_M_finish - (char *)__x->_M_start;
  *a2 = 0;
  a2[1] = 0;
  v4 = v3 / 24;
  a2[2] = 0;
  v5 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::shader_constant *,vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::allocate(
                            v3 / 24,
                            v10);
  *a2 = v5;
  a2[1] = v5;
  a2[2] = &v5[24 * v4];
  M_finish = __x->_M_finish;
  M_start = (unsigned __int8 *)__x->_M_start;
  if ( M_finish != __x->_M_start )
  {
    v8 = (char *)M_finish - (char *)M_start;
    memcpy(v5, M_start, v8);
    v5 = (unsigned __int8 *)(v8 + v9);
  }
  a2[1] = v5;
}
