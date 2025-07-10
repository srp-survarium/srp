stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > **__thiscall survarium::damage_model::get_body_part(
        survarium::damage_model *this,
        const char *part_name)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > **body_part_by_name; // [esp+20h] [ebp-8h]
  survarium::find_body_part_by_name_predicate find_predicate; // [esp+24h] [ebp-4h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&find_predicate);
  find_predicate.body_part_name = part_name;
  body_part_by_name = vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::find_if<survarium::find_body_part_by_name_predicate>(
                        &this->m_body_parts,
                        &find_predicate);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&find_predicate);
  return body_part_by_name;
}
