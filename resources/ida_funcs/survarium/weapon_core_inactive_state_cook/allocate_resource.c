vostok::mutable_buffer *__thiscall survarium::weapon_core_inactive_state_cook::allocate_resource(
        survarium::weapon_core_inactive_state_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  survarium::game_camera *v5; // ecx
  _BYTE *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // eax
  _BYTE v9[600]; // [esp-264h] [ebp-278h] BYREF
  vostok::const_buffer v10; // [esp-Ch] [ebp-20h]
  BOOL v11; // [esp-4h] [ebp-18h]
  survarium::weapon_core_inactive_state_cook *thisa; // [esp+8h] [ebp-Ch]
  char *v13; // [esp+Ch] [ebp-8h]
  char v14; // [esp+13h] [ebp-1h]

  thisa = this;
  v14 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v6 )
  {
    v11 = file_exist;
    v10 = raw_file_data;
    qmemcpy(v9, in_query, sizeof(v9));
    survarium::weapon_user_dead_state::finalize(0);
  }
  survarium::weapon_user_dead_state::finalize(v5);
  v13 = (char *)vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(v7, 0x138u);
  result->m_data = v13;
  result->m_size = 312;
  return result;
}
