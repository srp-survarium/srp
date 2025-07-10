void **__userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_allocate_and_copy<void * const *>@<eax>(
        unsigned int *__n@<eax>,
        void *const *__last@<ecx>,
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this,
        void *const *__first)
{
  unsigned __int8 *v5; // edi
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v7; // [esp+0h] [ebp-Ch]

  v5 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                            *__n,
                            v7);
  stlp_std::priv::__less2<unsigned int,vostok::ai::planning::operator_pair>();
  stlp_std::priv::__less2<unsigned int,vostok::ai::planning::operator_pair>();
  if ( __last != (void *const *)this )
    memcpy(v5, (unsigned __int8 *)this, (char *)__last - (char *)this);
  return (void **)v5;
}
