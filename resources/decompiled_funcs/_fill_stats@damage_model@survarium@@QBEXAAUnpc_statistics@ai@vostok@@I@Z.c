void __thiscall survarium::damage_model::fill_stats(
        survarium::damage_model *this,
        vostok::ai::npc_statistics *stats,
        unsigned int current_time_in_ms)
{
  survarium::game_camera *v3; // ecx
  vostok::ai::statistics_item<46,16> *v4; // ecx
  survarium::game_camera v6[12]; // [esp+18h] [ebp-420h] BYREF

  vostok::ai::statistics_item<46,16>::statistics_item<46,16>((vostok::ai::statistics_item<46,16> *)&v6[0].m_inverted_view_matrix.lines[2].elements[1]);
  vostok::fixed_string<16>::operator=(
    &stru_975580,
    (vostok::buffer_string *)&v6[0].m_inverted_view_matrix.lines[2].elements[1]);
  LODWORD(v6[0].m_inverted_view_matrix.i.x) = &stats->body_state;
  BYTE2(v6[0].m_inverted_view_matrix.lines[0].elements[2]) = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  vostok::buffer_vector<vostok::ai::statistics_item<46,16>>::construct(
    stats->body_state.m_end,
    (const vostok::ai::statistics_item<46,16> *)&v6[0].m_inverted_view_matrix.lines[2].elements[1]);
  ++stats->body_state.m_end;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v6[0].m_inverted_view_matrix.lines[1].elements[3]);
  *(_QWORD *)&v6[0].m_inverted_view_matrix.lines[1].elements[3] = __PAIR64__(current_time_in_ms, (unsigned int)stats);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)v6);
  v6[0].__vftable = (survarium::game_camera_vtbl *)&v6[0].m_inverted_view_matrix.lines[1].elements[3];
  vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::dump_npc_body_part_state_predicate>>(
    &this->m_body_parts,
    (const vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::dump_npc_body_part_state_predicate> *)v6);
  survarium::weapon_user_dead_state::finalize(v6);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v6[0].m_inverted_view_matrix.lines[1].elements[3]);
  vostok::ai::statistics_item<46,16>::~statistics_item<46,16>(v4, (int)&v6[0].m_inverted_view_matrix.k.y);
}
