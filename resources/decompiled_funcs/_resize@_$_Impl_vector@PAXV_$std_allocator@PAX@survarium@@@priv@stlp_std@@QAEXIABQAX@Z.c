void __thiscall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::resize(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this,
        unsigned int __new_size,
        void *const *__x)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v3; // ecx
  void **v4; // esi
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **v6; // eax
  void **v7; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *__n; // [esp+Ch] [ebp-24h]

  if ( __new_size >= stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(this) )
  {
    __n = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)(__new_size - stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(this));
    v7 = (void **)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                    __n,
                    (int)this);
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_fill_insert(
      this,
      v7,
      (unsigned int)__n,
      __x);
  }
  else
  {
    v4 = (void **)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                    v3,
                    (int)this);
    v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v5, (int)this);
    stlp_std::vector<vostok::render::render_surface_instance *,vostok::render::std_allocator<vostok::render::render_surface_instance *>>::erase(
      (void **)&v6[__new_size],
      v4,
      this);
  }
}
