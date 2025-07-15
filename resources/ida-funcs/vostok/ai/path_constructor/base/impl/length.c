unsigned int __cdecl vostok::ai::path_constructor::base::impl<vostok::ai::planning::search_base::vertex_type>::length(
        survarium::game_camera *vertex)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *m_back; // ecx
  vostok::ai::planning::search_base::vertex_type *j; // [esp+4h] [ebp-8h]
  unsigned int result; // [esp+8h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize(v1);
  result = 1;
  m_back = vertex;
  for ( j = (vostok::ai::planning::search_base::vertex_type *)LODWORD(vertex->m_inverted_view_matrix.i.y);
        j;
        j = (vostok::ai::planning::search_base::vertex_type *)m_back )
  {
    ++result;
    m_back = (survarium::game_camera *)j->m_back;
  }
  survarium::weapon_user_dead_state::finalize(m_back);
  return result;
}


unsigned int __cdecl vostok::ai::path_constructor::base::impl<vostok::sound::search::search_service::vertex_type>::length(
        const vostok::sound::search::search_service::vertex_type *vertex)
{
  vostok::sound::search::search_service::vertex_type *j; // [esp+4h] [ebp-8h]
  unsigned int result; // [esp+8h] [ebp-4h]

  result = 1;
  for ( j = vertex->m_back; j; j = j->m_back )
    ++result;
  return result;
}
