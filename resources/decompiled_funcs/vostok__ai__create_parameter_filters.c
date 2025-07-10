vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *__cdecl vostok::ai::create_parameter_filters(
        vostok::configs::binary_config_value *options,
        survarium::weapon_core_animation_end_aware_state *world,
        char *parameter_number)
{
  bool v3; // al
  vostok::memory::doug_lea_allocator *v4; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // eax
  survarium::game_camera *v9; // [esp+0h] [ebp-54h]
  vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v10; // [esp+4h] [ebp-50h]
  int *v11; // [esp+14h] [ebp-40h]
  int *_Where; // [esp+2Ch] [ebp-28h]
  vostok::ai::planning::base_filter **v13; // [esp+34h] [ebp-20h]
  vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v14; // [esp+38h] [ebp-1Ch]
  vostok::configs::binary_config_value *filters; // [esp+44h] [ebp-10h]
  const vostok::configs::binary_config_value *it_end; // [esp+48h] [ebp-Ch]
  survarium::game_camera *it; // [esp+4Ch] [ebp-8h]
  vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *result; // [esp+50h] [ebp-4h]

  result = 0;
  v3 = vostok::configs::binary_config_value::value_exists(options, parameter_number);
  if ( v3 )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v4, 0x10u);
    v14 = (vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)operator new(0x10u, _Where);
    if ( v14 )
    {
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5, v14);
      survarium::weapon_user_dead_state::finalize(v6);
      v14->m_first = 0;
      v14->m_last = 0;
      v10 = v14;
    }
    else
    {
      v10 = 0;
    }
    result = (vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)v10;
    filters = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        options,
                                                        parameter_number);
    it = (survarium::game_camera *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)filters);
    it_end = vostok::configs::binary_config_value::end(filters);
    while ( it != (survarium::game_camera *)it_end )
    {
      survarium::weapon_user_dead_state::finalize(it);
      v11 = vostok::memory::doug_lea_allocator::malloc_impl(v7, 8u);
      v13 = (vostok::ai::planning::base_filter **)operator new(8u, v11);
      if ( v13 )
      {
        *v13 = vostok::ai::create_filter((vostok::configs::binary_config_value *)it, world);
        v9 = (survarium::game_camera *)v13;
      }
      else
      {
        v9 = 0;
      }
      vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        v10,
        v9,
        0);
      it = (survarium::game_camera *)((char *)it + 24);
    }
  }
  return result;
}
