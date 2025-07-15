void __thiscall vostok::vfs::soft_link_node<1>::absolute_path_to_referenced(
        vostok::vfs::soft_link_node<1> *this,
        vostok::fs_new::virtual_path_string *out_path)
{
  vostok::vfs::base_node<1> *v2; // eax
  survarium::game_camera *v3; // ecx
  _BYTE *v4; // eax
  char *in_relative_path; // [esp+Ch] [ebp-8h] BYREF
  bool append_result; // [esp+13h] [ebp-1h]

  v2 = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::hard_link_node,1>((vostok::vfs::hard_link_node<1> *)this);
  vostok::vfs::base_node<1>::get_full_path(v2, out_path);
  in_relative_path = this->relative_path.pointer;
  append_result = vostok::fs_new::append_relative_path<vostok::fs_new::virtual_path_string,char const *>(
                    out_path,
                    (const char *const *)&in_relative_path);
  survarium::weapon_user_dead_state::finalize(v3);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(unsigned __int8)*v4);
}
