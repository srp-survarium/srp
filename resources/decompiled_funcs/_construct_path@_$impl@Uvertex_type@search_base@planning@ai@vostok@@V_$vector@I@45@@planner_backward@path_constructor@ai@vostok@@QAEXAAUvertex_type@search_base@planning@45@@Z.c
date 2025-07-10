void __thiscall vostok::ai::path_constructor::planner_backward::impl<vostok::ai::planning::search_base::vertex_type,vostok::ai::vector<unsigned int>>::construct_path(
        vostok::ai::path_constructor::planner_backward::impl<vostok::ai::planning::search_base::vertex_type,vostok::ai::vector<unsigned int> > *this,
        vostok::ai::planning::search_base::vertex_type *best)
{
  survarium::game_camera *v2; // ecx
  const unsigned int *v3; // eax
  unsigned int *v4; // eax
  unsigned int *v5; // eax
  unsigned int __new_size; // [esp+14h] [ebp-3Ch]
  vostok::ai::vector<unsigned int> *m_path; // [esp+18h] [ebp-38h]
  vostok::ai::planning::search_base::vertex_type *i; // [esp+48h] [ebp-8h]
  unsigned int *iter; // [esp+4Ch] [ebp-4h]

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
    iter = v4;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_path->_M_impl._M_finish);
    while ( iter != v5 )
    {
      *iter = i->m_edge_id;
      i = i->m_back;
      ++iter;
    }
  }
}
