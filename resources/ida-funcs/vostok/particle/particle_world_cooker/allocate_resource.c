vostok::mutable_buffer *__thiscall vostok::particle::particle_world_cooker::allocate_resource(
        vostok::particle::particle_world_cooker *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  _BYTE *v5; // eax
  const char *v6; // eax
  char *out_buffer; // [esp+1Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v5 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)file_exist);
  v6 = type_info::name(&unsigned char `RTTI Type Descriptor', &__type_info_root_node);
  out_buffer = (char *)vostok::resources::allocate_unmanaged_memory(raw_file_data.m_size + 392, v6);
  if ( !out_buffer )
    vostok::resources::query_result_for_cook::set_out_of_memory(
      (vostok::resources::query_result_for_cook *)&vostok::resources::unmanaged_memory,
      (int)in_query,
      (vostok::resources::memory_type *)(raw_file_data.m_size + 392),
      (unsigned int)this);
  result->m_data = out_buffer;
  result->m_size = raw_file_data.m_size + 392;
  return result;
}
