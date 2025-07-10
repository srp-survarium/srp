char __thiscall vostok::vfs::base_folder_node<1>::unlink_child(
        vostok::vfs::base_folder_node<1> *this,
        vostok::vfs::base_node<1> *in_child,
        bool assert_if_not_child)
{
  survarium::game_camera *v3; // ecx
  vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *v5; // ecx
  vostok::vfs::base_node<1> *v7; // [esp+Ch] [ebp-24h] BYREF
  int v8; // [esp+10h] [ebp-20h]
  vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper *p_m_next; // [esp+14h] [ebp-1Ch]
  vostok::vfs::base_node<1> **v10; // [esp+18h] [ebp-18h]
  vostok::vfs::base_node<1> *pointer; // [esp+1Ch] [ebp-14h]
  char v12; // [esp+27h] [ebp-9h]
  vostok::vfs::base_node<1> *prev_node; // [esp+28h] [ebp-8h] BYREF
  vostok::vfs::base_node<1> *child; // [esp+2Ch] [ebp-4h]

  prev_node = 0;
  child = vostok::vfs::base_folder_node<1>::find_child(this, in_child->m_name, &prev_node);
  if ( child != in_child )
  {
    if ( !assert_if_not_child )
      return 0;
    v12 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
  }
  if ( prev_node )
  {
    pointer = child->m_next.pointer;
    v10 = &v7;
    v8 = 0;
    v7 = pointer;
    p_m_next = &prev_node->m_next;
    v5 = &prev_node->m_next;
    prev_node->m_next.pointer = pointer;
    HIDWORD(v5->max_storage) = v8;
  }
  else
  {
    this->m_first_child.pointer = child->m_next.pointer;
  }
  return 1;
}
