void __userpurge stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>(
        stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *this@<ecx>,
        vostok::fs_new::virtual_path_string **a2@<edi>,
        const stlp_std::priv::_Impl_vector<vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string> > *__x)
{
  int v3; // ecx
  int v4; // esi
  vostok::fs_new::virtual_path_string *v5; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::texture_named_instance *,vostok::render::texture_named_instance,vostok::render::std_allocator<vostok::render::texture_named_instance> > *v6; // [esp+0h] [ebp-8h]
  const stlp_std::random_access_iterator_tag *v7; // [esp+0h] [ebp-8h]
  int *v8; // [esp+4h] [ebp-4h]

  v3 = (char *)__x->_M_finish - (char *)__x->_M_start;
  *a2 = 0;
  a2[1] = 0;
  v4 = v3 / 276;
  a2[2] = 0;
  v5 = (vostok::fs_new::virtual_path_string *)stlp_std::priv::_STLP_alloc_proxy<vostok::fs_new::virtual_path_string *,vostok::fs_new::virtual_path_string,vostok::render::std_allocator<vostok::fs_new::virtual_path_string>>::allocate(
                                                v3 / 276,
                                                v6);
  *a2 = v5;
  a2[1] = v5;
  a2[2] = &v5[v4];
  a2[1] = stlp_std::priv::__ucopy<vostok::fs_new::virtual_path_string const *,vostok::fs_new::virtual_path_string *,int>(
            __x->_M_start,
            __x->_M_finish,
            v5,
            v7,
            v8);
}
