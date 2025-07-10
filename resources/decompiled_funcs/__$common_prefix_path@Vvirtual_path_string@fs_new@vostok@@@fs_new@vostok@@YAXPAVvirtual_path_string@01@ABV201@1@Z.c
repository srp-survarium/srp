void __cdecl vostok::fs_new::common_prefix_path<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::virtual_path_string *out_common_path,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *first_path,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *second_path)
{
  const char *v3; // esi
  const char *v4; // eax
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // ecx
  survarium::game_camera *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  char v11; // [esp+5h] [ebp-1Bh]
  char v12; // [esp+15h] [ebp-Bh]
  unsigned int last_slash_pos; // [esp+18h] [ebp-8h]
  unsigned int common_path_length; // [esp+1Ch] [ebp-4h]

  v3 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(second_path);
  v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(first_path);
  vostok::get_common_prefix(&out_common_path->m_string, v4, v3);
  common_path_length = vostok::fs_new::path_string_impl::length(out_common_path);
  survarium::weapon_user_dead_state::finalize(v5);
  survarium::weapon_user_dead_state::finalize(v6);
  v12 = *((_BYTE *)&first_path->m_object->__vftable + common_path_length);
  v7 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v12;
  if ( v12 )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v12);
    survarium::weapon_user_dead_state::finalize(v8);
    v7 = first_path;
    LOBYTE(v7) = *((_BYTE *)&first_path->m_object->__vftable + common_path_length);
    if ( (char)v7 != 47 )
      goto LABEL_5;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v7);
  survarium::weapon_user_dead_state::finalize(v9);
  if ( *((_BYTE *)&second_path->m_object->__vftable + common_path_length) )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)common_path_length);
    survarium::weapon_user_dead_state::finalize(v10);
    if ( *((_BYTE *)&second_path->m_object->__vftable + common_path_length) != 47 )
    {
LABEL_5:
      last_slash_pos = vostok::fs_new::path_string_impl::rfind(out_common_path, 47);
      if ( last_slash_pos == -1 )
        vostok::fs_new::path_string_impl::operator=<char const [1]>(out_common_path, (const char (*)[1])&buf);
      else
        vostok::fs_new::path_string_impl::set_length(out_common_path, last_slash_pos);
    }
  }
  if ( out_common_path->m_string.m_end == out_common_path->m_string.m_begin )
    v11 = 0;
  else
    v11 = *(out_common_path->m_string.m_end - 1);
  if ( v11 == 47 )
    vostok::buffer_string::rtrim(&out_common_path->m_string);
}
