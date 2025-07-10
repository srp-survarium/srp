char *__cdecl vostok::ai::get_name_by_id(const vostok::fixed_vector<char *,32> *objects, unsigned int index)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx

  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  return objects->m_begin[index];
}
