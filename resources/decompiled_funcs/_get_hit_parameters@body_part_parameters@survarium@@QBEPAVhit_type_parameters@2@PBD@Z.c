stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > **__thiscall survarium::body_part_parameters::get_hit_parameters(
        survarium::body_part_parameters *this,
        const char *hit_type)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > **hit_parameters_by_type; // [esp+20h] [ebp-8h]
  survarium::find_hit_parameters_by_type_predicate find_predicate; // [esp+24h] [ebp-4h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&find_predicate);
  find_predicate.hit_type = hit_type;
  hit_parameters_by_type = vostok::intrusive_list<survarium::hit_type_parameters,survarium::hit_type_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::find_if<survarium::find_hit_parameters_by_type_predicate>(
                             &this->m_hit_types,
                             &find_predicate);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&find_predicate);
  return hit_parameters_by_type;
}
