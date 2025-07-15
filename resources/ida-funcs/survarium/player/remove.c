void __thiscall survarium::player::remove(
        survarium::player *this,
        vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> real_remove)
{
  survarium::player *v3; // ecx
  bool v4; // zf
  survarium::base_network_client *v5; // ecx
  bool is_player_current; // al
  survarium::player *v7; // ecx
  unsigned int v8; // ebx
  unsigned int i; // edi
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // eax
  survarium::game_effect *v13; // eax

  survarium::base_player::remove(this, (BOOL)real_remove.m_object);
  if ( *((_BYTE *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
       + (_DWORD)&loc_11437
       + 1) )
  {
    v4 = LOBYTE(real_remove.m_object) == 0;
    *((_BYTE *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
    + (_DWORD)&loc_11437
    + 1) = 0;
    if ( v4 )
      return;
    survarium::player::remove_models_from_scene(v3, (int)this);
    is_player_current = survarium::base_network_client::is_player_current(
                          v5,
                          *(_DWORD *)(*(int *)((char *)&dword_11414 + (_DWORD)this) + 13912),
                          this->id);
    survarium::player::render_name(v7, (int)this, is_player_current);
  }
  if ( LOBYTE(real_remove.m_object) )
  {
    v8 = *(_DWORD *)(*(int *)((char *)&dword_11414 + (_DWORD)this) + 1328);
    for ( i = 0; i < v8; ++i )
    {
      v10 = *(int *)((char *)&dword_11414 + (_DWORD)this);
      v11 = *(_DWORD *)(v10 + 13968);
      v12 = *(_DWORD *)(v10 + 1324);
      real_remove.m_object = 0;
      v13 = *(survarium::game_effect **)(v12 + 4 * i);
      if ( v13 )
      {
        ++v13->m_reference_count;
        real_remove.m_object = v13;
      }
      survarium::game_effect_player::remove(
        &this->m_effect_player,
        &real_remove,
        (const survarium::game_effect_transited_to_zero_predicate *)this,
        v11);
      vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>(&real_remove);
    }
  }
}
