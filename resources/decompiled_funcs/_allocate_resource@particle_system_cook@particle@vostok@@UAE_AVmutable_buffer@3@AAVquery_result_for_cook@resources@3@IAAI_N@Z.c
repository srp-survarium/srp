vostok::mutable_buffer *__thiscall vostok::particle::particle_system_cook::allocate_resource(
        vostok::particle::particle_system_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        unsigned int file_size,
        unsigned int *out_offset_to_file,
        bool file_exist)
{
  _BYTE *v6; // eax
  const char *v7; // eax
  _BYTE v9[600]; // [esp-25Ch] [ebp-274h] BYREF
  BOOL v10; // [esp-4h] [ebp-1Ch]
  vostok::particle::particle_system_cook *thisa; // [esp+8h] [ebp-10h]
  char *unmanaged_memory; // [esp+Ch] [ebp-Ch]
  char v13; // [esp+13h] [ebp-5h]
  unsigned int size; // [esp+14h] [ebp-4h]

  thisa = this;
  v13 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v6 )
  {
    v10 = file_exist;
    qmemcpy(v9, in_query, sizeof(v9));
    survarium::weapon_user_dead_state::finalize(0);
  }
  *out_offset_to_file = 280;
  size = file_size + 280;
  v7 = type_info::name(&char `RTTI Type Descriptor', &__type_info_root_node);
  unmanaged_memory = (char *)vostok::resources::allocate_unmanaged_memory(size, v7);
  result->m_data = unmanaged_memory;
  result->m_size = size;
  return result;
}
