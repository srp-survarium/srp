bool __thiscall vostok::ai::planning::goal::are_parameters_suitable(
        vostok::ai::planning::goal *this,
        const vostok::fixed_vector<void const *,4> *objects)
{
  bool v4; // [esp+33h] [ebp-5h]
  vostok::ai::planning::parameters_suitability_checker_predicate suitability_checker; // [esp+34h] [ebp-4h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&suitability_checker);
  suitability_checker.instances = objects;
  v4 = vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::find_if<vostok::ai::planning::parameters_suitability_checker_predicate>(
         &this->m_filters_set,
         &suitability_checker) != 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&suitability_checker);
  return v4;
}
