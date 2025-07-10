void __thiscall vostok::vfs::base_node<1>::get_full_path(
        vostok::vfs::base_node<1> *this,
        vostok::fs_new::native_path_string *out_string)
{
  void *v2; // esp
  vostok::vfs::base_node_list_node<1> *v3; // eax
  _DWORD v4[3]; // [esp-8h] [ebp-3Ch] BYREF
  const vostok::vfs::base_node<1> *p_base; // [esp+4h] [ebp-30h]
  const vostok::vfs::base_node<1> *thisa; // [esp+8h] [ebp-2Ch]
  vostok::vfs::base_folder_node<1> *pointer; // [esp+14h] [ebp-20h]
  char s; // [esp+1Fh] [ebp-15h] BYREF
  char *c_string; // [esp+20h] [ebp-14h]
  vostok::vfs::base_node_list_node<1> *it_list_node; // [esp+24h] [ebp-10h]
  vostok::vfs::base_node_list_node<1> *new_root; // [esp+28h] [ebp-Ch]
  const vostok::vfs::base_node<1> *it_node; // [esp+2Ch] [ebp-8h]
  vostok::vfs::base_node_list_node<1> *root; // [esp+30h] [ebp-4h]

  thisa = this;
  vostok::fs_new::path_string_impl::clear(&out_string->m_string);
  root = 0;
  for ( it_node = thisa; it_node && it_node->m_name[0]; it_node = p_base )
  {
    v2 = alloca(8);
    v4[2] = v4;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)it_node);
    new_root = v3;
    v3->next = root;
    new_root->node = it_node;
    root = new_root;
    if ( it_node->m_parent.pointer )
    {
      pointer = it_node->m_parent.pointer;
      p_base = &pointer->base;
    }
    else
    {
      p_base = 0;
    }
  }
  for ( it_list_node = root; it_list_node; it_list_node = it_list_node->next )
  {
    c_string = it_list_node->node->m_name;
    vostok::buffer_string::append(&out_string->m_string, c_string);
    if ( it_list_node->next )
    {
      s = 47;
      vostok::fs_new::path_string_impl::operator+=<char>(out_string, &s);
    }
  }
}
