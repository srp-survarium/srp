void __thiscall vostok::ai::path_constructor::edge::impl<vostok::ai::planning::search_base::vertex_type,vostok::ai::vector<unsigned int>>::construct_path(
        vostok::ai::path_constructor::edge::impl<vostok::ai::planning::search_base::vertex_type,vostok::ai::vector<unsigned int> > *this,
        vostok::ai::planning::search_base::vertex_type *best)
{
  survarium::game_camera *v2; // ecx
  const unsigned int *v3; // eax
  boost::_bi::list1<vostok::network_core::packet_reader &> *v4; // eax
  boost::_bi::list1<vostok::network_core::packet_reader &> *v5; // eax
  stlp_std::reverse_iterator<unsigned int *> *v6; // ecx
  unsigned int *v7; // eax
  unsigned int __new_size; // [esp+18h] [ebp-34h]
  vostok::ai::vector<unsigned int> *m_path; // [esp+1Ch] [ebp-30h]
  stlp_std::reverse_iterator<unsigned int *> iter_end; // [esp+40h] [ebp-Ch] BYREF
  vostok::ai::planning::search_base::vertex_type *i; // [esp+44h] [ebp-8h]
  stlp_std::reverse_iterator<unsigned int *> iter; // [esp+48h] [ebp-4h] BYREF

  if ( this->m_path )
  {
    __new_size = vostok::ai::path_constructor::base::impl<vostok::ai::planning::search_base::vertex_type>::length(best)
               - 1;
    m_path = this->m_path;
    survarium::weapon_user_dead_state::finalize(v2);
    stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::resize(
      &m_path->_M_impl,
      __new_size,
      v3);
    i = best;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_path);
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v4,
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter);
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_path->_M_impl._M_start);
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v5,
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter_end);
    while ( vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator!=(
              &iter,
              &iter_end) )
    {
      v7 = stlp_std::reverse_iterator<unsigned int *>::operator*(v6, &iter);
      *v7 = i->m_edge_id;
      i = i->m_back;
      stlp_std::reverse_iterator<unsigned int *>::operator++((stlp_std::reverse_iterator<unsigned int *> *)i, &iter);
    }
  }
}
