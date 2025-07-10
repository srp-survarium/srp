void __thiscall vostok::ai::behaviour_cook::on_animations_loaded(
        vostok::ai::behaviour_cook *this,
        vostok::resources::queries_result *data,
        vostok::configs::binary_config_value *behaviour_value,
        vostok::ai::behaviour *const new_behaviour)
{
  survarium::game_camera *v4; // ecx
  unsigned int v5; // eax
  vostok::resources::query_result *v6; // eax
  vostok::resources::query_result *v7; // eax
  vostok::resources::query_result_for_user *v8; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  const char *requested_path; // [esp-4h] [ebp-3Ch]
  int v12; // [esp+1Ch] [ebp-1Ch]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v13; // [esp+20h] [ebp-18h] BYREF
  vostok::ai::animation_item *v14; // [esp+24h] [ebp-14h]
  char v15; // [esp+2Ah] [ebp-Eh]
  char v16; // [esp+2Bh] [ebp-Dh]
  unsigned int i; // [esp+2Ch] [ebp-Ch]
  vostok::ai::animation_item *it_animations; // [esp+30h] [ebp-8h]
  vostok::resources::query_result_for_cook *parent; // [esp+34h] [ebp-4h]

  v12 = 0;
  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)data);
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    it_animations = (vostok::ai::animation_item *)&new_behaviour[1];
    v15 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&new_behaviour[1]);
    for ( i = 0; ; ++i )
    {
      v5 = vostok::resources::queries_result::size(data);
      if ( i >= v5 )
        break;
      v14 = (vostok::ai::animation_item *)operator new(0x118u, (void *)it_animations++);
      if ( v14 )
      {
        v12 |= 1u;
        v6 = vostok::resources::queries_result::operator[](data, i);
        requested_path = vostok::resources::query_result_for_user::get_requested_path(v6);
        v7 = vostok::resources::queries_result::operator[](data, i);
        unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                               v8,
                               (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v7,
                               (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13);
        vostok::ai::animation_item::animation_item(
          v14,
          (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
          requested_path);
      }
      if ( (v12 & 1) != 0 )
      {
        v12 &= ~1u;
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
      }
    }
  }
  else
  {
    v16 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
  }
  vostok::ai::behaviour_cook::load_sounds(this, parent, behaviour_value, new_behaviour);
}
