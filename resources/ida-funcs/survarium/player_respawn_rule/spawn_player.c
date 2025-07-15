void __userpurge survarium::player_respawn_rule::spawn_player(
        survarium::player_respawn_rule *this@<ecx>,
        int a2@<eax>,
        survarium::base_player *player,
        unsigned int current_time_in_ms)
{
  survarium::base_player *v4; // ebx
  stlp_std::priv::_Rb_tree_node_base **p_M_left; // esi
  stlp_std::priv::_Rb_tree_node_base **v7; // eax
  _DWORD v8[3]; // [esp+14h] [ebp-10h] BYREF
  stlp_std::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *v9; // [esp+20h] [ebp-4h]

  v4 = player;
  player = (survarium::base_player *)survarium::player_respawn_rule::get_available_spawn_point(
                                       this,
                                       (_DWORD *)a2,
                                       (stlp_std::priv::_Rb_tree_node_base *)(*(survarium::base_player_vtbl **)((char *)&player->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable + (_DWORD)&loc_11066 + 2))[6].deserialize);
  v9 = (stlp_std::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)(a2 + 272);
  p_M_left = &(*stlp_std::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>::operator[]<unsigned int>(
                  (stlp_std::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)(a2 + 272),
                  (unsigned int *)&player))->_M_left;
  v8[0] = *p_M_left++;
  v8[1] = *p_M_left;
  v8[2] = p_M_left[1];
  v7 = stlp_std::map<unsigned int,survarium::respawn_point_core *,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>::operator[]<unsigned int>(
         v9,
         (unsigned int *)&player);
  ((void (__thiscall *)(survarium::base_player *, unsigned int, _DWORD *, _DWORD, _DWORD))v4->initialize)(
    v4,
    current_time_in_ms,
    v8,
    *(float *)&(*v7)[1]._M_parent,
    0.0);
  v4->insert(v4, 1);
  v4->transform(&v4->survarium::collision_user);
}
