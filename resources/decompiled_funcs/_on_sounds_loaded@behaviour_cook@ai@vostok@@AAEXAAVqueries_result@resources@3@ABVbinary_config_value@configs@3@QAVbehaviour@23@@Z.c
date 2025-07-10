void __thiscall vostok::ai::behaviour_cook::on_sounds_loaded(
        vostok::ai::behaviour_cook *this,
        vostok::resources::queries_result *data,
        vostok::configs::binary_config_value *behaviour_value,
        vostok::ai::behaviour *const new_behaviour)
{
  survarium::game_camera *v4; // ecx
  vostok::ai::sound_item *v5; // eax
  unsigned int v6; // eax
  vostok::resources::query_result *v7; // eax
  vostok::resources::query_result *v8; // eax
  vostok::resources::query_result_for_user *v9; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  const char *requested_path; // [esp-4h] [ebp-48h]
  int v13; // [esp+28h] [ebp-1Ch]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v14; // [esp+2Ch] [ebp-18h] BYREF
  vostok::ai::sound_item *v15; // [esp+30h] [ebp-14h]
  char v16; // [esp+36h] [ebp-Eh]
  char v17; // [esp+37h] [ebp-Dh]
  unsigned int i; // [esp+38h] [ebp-Ch]
  vostok::ai::sound_item *it_sound; // [esp+3Ch] [ebp-8h]
  vostok::resources::query_result_for_cook *parent; // [esp+40h] [ebp-4h]

  v13 = 0;
  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)data);
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)new_behaviour->m_animations_count);
    it_sound = v5;
    v16 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
    for ( i = 0; ; ++i )
    {
      v6 = vostok::resources::queries_result::size(data);
      if ( i >= v6 )
        break;
      v15 = (vostok::ai::sound_item *)operator new(0x118u, (void *)it_sound++);
      if ( v15 )
      {
        v13 |= 1u;
        v7 = vostok::resources::queries_result::operator[](data, i);
        requested_path = vostok::resources::query_result_for_user::get_requested_path(v7);
        v8 = vostok::resources::queries_result::operator[](data, i);
        unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                               v9,
                               (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v8,
                               (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v14);
        vostok::ai::sound_item::sound_item(
          v15,
          (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
          requested_path);
      }
      if ( (v13 & 1) != 0 )
      {
        v13 &= ~1u;
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v14);
      }
    }
  }
  else
  {
    v17 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
  }
  vostok::ai::behaviour_cook::load_movement_targets(this, parent, behaviour_value, new_behaviour);
}
