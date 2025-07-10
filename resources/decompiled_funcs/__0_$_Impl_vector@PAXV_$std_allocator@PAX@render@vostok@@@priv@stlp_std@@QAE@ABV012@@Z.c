void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_Impl_vector<void *,vostok::render::std_allocator<void *>>(
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        const stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *__x)
{
  signed int v3; // edi
  unsigned __int8 *v4; // eax
  void **M_finish; // edi
  unsigned __int8 *M_start; // ebx
  unsigned int v7; // edi
  int v8; // eax
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v9; // [esp+0h] [ebp-8h]

  v3 = (char *)__x->_M_finish - (char *)__x->_M_start;
  *a2 = 0;
  a2[1] = 0;
  v3 >>= 2;
  a2[2] = 0;
  v4 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                            v3,
                            v9);
  *a2 = v4;
  a2[1] = v4;
  a2[2] = &v4[4 * v3];
  M_finish = __x->_M_finish;
  M_start = (unsigned __int8 *)__x->_M_start;
  if ( M_finish != __x->_M_start )
  {
    v7 = (char *)M_finish - (char *)M_start;
    memcpy(v4, M_start, v7);
    v4 = (unsigned __int8 *)(v7 + v8);
  }
  a2[1] = v4;
}
