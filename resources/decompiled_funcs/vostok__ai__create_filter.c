vostok::ai::planning::base_filter *__cdecl vostok::ai::create_filter(
        vostok::configs::binary_config_value *filter_options,
        survarium::weapon_core_animation_end_aware_state *world)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  bool v4; // al
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  vostok::configs::binary_config_value *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v10; // eax
  vostok::memory::doug_lea_allocator *v11; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // eax
  vostok::ai::planning::animation_filter *v14; // eax
  vostok::memory::doug_lea_allocator *v15; // eax
  vostok::ai::planning::sound_filter *v16; // eax
  vostok::memory::doug_lea_allocator *v17; // eax
  vostok::ai::planning::position_filter *v18; // eax
  vostok::ai::planning::position_filter *v20; // [esp+0h] [ebp-B4h]
  vostok::ai::planning::sound_filter *v21; // [esp+4h] [ebp-B0h]
  vostok::ai::planning::animation_filter *v22; // [esp+8h] [ebp-ACh]
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v23; // [esp+Ch] [ebp-A8h]
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v24; // [esp+10h] [ebp-A4h]
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v25; // [esp+14h] [ebp-A0h]
  bool v26; // [esp+1Bh] [ebp-99h]
  int *v27; // [esp+2Ch] [ebp-88h]
  int *v28; // [esp+34h] [ebp-80h]
  int *v29; // [esp+3Ch] [ebp-78h]
  int *v30; // [esp+44h] [ebp-70h]
  int *v31; // [esp+4Ch] [ebp-68h]
  int *_Where; // [esp+54h] [ebp-60h]
  vostok::ai::planning::position_filter *v33; // [esp+60h] [ebp-54h]
  vostok::ai::planning::sound_filter *v34; // [esp+64h] [ebp-50h]
  vostok::ai::planning::animation_filter *v35; // [esp+68h] [ebp-4Ch]
  vostok::ai::planning::cover_filter *v36; // [esp+6Ch] [ebp-48h]
  vostok::ai::planning::weapon_filter *v37; // [esp+70h] [ebp-44h]
  vostok::ai::planning::enemy_filter *v38; // [esp+74h] [ebp-40h]
  vostok::ai::planning::base_filter *subfilter; // [esp+78h] [ebp-3Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+80h] [ebp-34h]
  vostok::configs::binary_config_value *values; // [esp+84h] [ebp-30h]
  const vostok::configs::binary_config_value *it; // [esp+88h] [ebp-2Ch]
  const vostok::variant<32> **filter_type; // [esp+A4h] [ebp-10h]
  vostok::ai::planning::base_filter *result; // [esp+ACh] [ebp-8h]

  v2 = vostok::configs::binary_config_value::operator[](filter_options, "type");
  filter_type = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)v2);
  v4 = vostok::configs::binary_config_value::value_exists(filter_options, "is_inverted");
  v5 = (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v4;
  if ( v4 )
  {
    v6 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   filter_options,
                                                   "is_inverted");
    v26 = vostok::configs::binary_config_value::operator bool(v6);
  }
  else
  {
    v26 = 0;
  }
  result = 0;
  if ( filter_type )
  {
    if ( filter_type == (const vostok::variant<32> **)1 )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
      v31 = vostok::memory::doug_lea_allocator::malloc_impl(v9, 0x28u);
      v37 = (vostok::ai::planning::weapon_filter *)operator new(0x28u, v31);
      if ( v37 )
      {
        vostok::ai::planning::weapon_filter::weapon_filter(v37, v26);
        v24 = v10;
      }
      else
      {
        v24 = 0;
      }
      vostok::ai::parse_weapon_filter(filter_options, world, v24);
      v5 = v24;
      result = (vostok::ai::planning::base_filter *)v24;
    }
    else if ( filter_type == (const vostok::variant<32> **)2 )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
      v30 = vostok::memory::doug_lea_allocator::malloc_impl(v11, 0x28u);
      v36 = (vostok::ai::planning::cover_filter *)operator new(0x28u, v30);
      if ( v36 )
      {
        vostok::ai::planning::cover_filter::cover_filter(v36, v26);
        v23 = v12;
      }
      else
      {
        v23 = 0;
      }
      vostok::ai::parse_cover_filter(filter_options, world, v23);
      result = (vostok::ai::planning::base_filter *)v23;
    }
    else if ( filter_type == (const vostok::variant<32> **)3 )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
      v29 = vostok::memory::doug_lea_allocator::malloc_impl(v13, 0x28u);
      v35 = (vostok::ai::planning::animation_filter *)operator new(0x28u, v29);
      if ( v35 )
      {
        vostok::ai::planning::animation_filter::animation_filter(v35, v26);
        v22 = v14;
      }
      else
      {
        v22 = 0;
      }
      vostok::ai::parse_animation_filter(filter_options, v22);
      result = v22;
    }
    else if ( filter_type == (const vostok::variant<32> **)4 )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
      v28 = vostok::memory::doug_lea_allocator::malloc_impl(v15, 0x28u);
      v34 = (vostok::ai::planning::sound_filter *)operator new(0x28u, v28);
      if ( v34 )
      {
        vostok::ai::planning::sound_filter::sound_filter(v34, v26);
        v21 = v16;
      }
      else
      {
        v21 = 0;
      }
      vostok::ai::parse_sound_filter(filter_options, v21);
      result = v21;
    }
    else if ( filter_type == (const vostok::variant<32> **)5 )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
      v27 = vostok::memory::doug_lea_allocator::malloc_impl(v17, 0x28u);
      v33 = (vostok::ai::planning::position_filter *)operator new(0x28u, v27);
      if ( v33 )
      {
        vostok::ai::planning::position_filter::position_filter(v33, v26);
        v20 = v18;
      }
      else
      {
        v20 = 0;
      }
      vostok::ai::parse_position_filter(filter_options, v20);
      result = v20;
    }
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v7, 0x28u);
    v38 = (vostok::ai::planning::enemy_filter *)operator new(0x28u, _Where);
    if ( v38 )
    {
      vostok::ai::planning::enemy_filter::enemy_filter(v38, v26);
      v25 = v8;
    }
    else
    {
      v25 = 0;
    }
    vostok::ai::parse_enemy_filter(filter_options, world, v25);
    result = (vostok::ai::planning::base_filter *)v25;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
  if ( vostok::configs::binary_config_value::value_exists(filter_options, "filters") )
  {
    values = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                       filter_options,
                                                       "filters");
    it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)values);
    it_end = vostok::configs::binary_config_value::end(values);
    while ( it != it_end )
    {
      subfilter = vostok::ai::create_filter(it, (vostok::ai::ai_world *)world);
      vostok::ai::planning::base_filter::add_subfilter(result, (survarium::game_camera_vtbl *)subfilter);
      ++it;
    }
  }
  return result;
}
