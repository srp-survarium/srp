void __thiscall vostok::vfs::mounter::free_mount_branch(
        vostok::vfs::mounter *this,
        survarium::game_camera *helper_nodes)
{
  vostok::memory::base_allocator *v2; // eax
  void **v4; // [esp+Ch] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-4h]

  for ( i = 0;
        i < (signed int)(LODWORD(helper_nodes->m_inverted_view_matrix.i.x) - (unsigned int)helper_nodes->__vftable) >> 2;
        ++i )
  {
    survarium::weapon_user_dead_state::finalize(helper_nodes);
    if ( *((_DWORD *)&helper_nodes->get_projection_matrix + i) )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)i);
      v4 = (void **)(&helper_nodes->get_projection_matrix + i);
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
      if ( *v4 )
      {
        vostok::memory::base_allocator::free_impl(v2, *v4);
        *v4 = 0;
      }
    }
  }
}
