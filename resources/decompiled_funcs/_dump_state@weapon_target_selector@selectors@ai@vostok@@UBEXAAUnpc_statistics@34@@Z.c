void __thiscall vostok::ai::selectors::weapon_target_selector::dump_state(
        vostok::ai::selectors::weapon_target_selector *this,
        vostok::ai::npc_statistics *stats)
{
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *m_begin; // edx
  BOOL v3; // ecx
  unsigned int v5[5]; // [esp+20h] [ebp-4A4h] BYREF
  char *src; // [esp+34h] [ebp-490h]
  unsigned int max_count[6]; // [esp+38h] [ebp-48Ch] BYREF
  vostok::fixed_string<46> v8; // [esp+50h] [ebp-474h] BYREF
  vostok::fixed_string<46> v9; // [esp+8Ch] [ebp-438h] BYREF
  unsigned int i; // [esp+C8h] [ebp-3FCh]
  vostok::ai::statistics_item<46,16> new_stats_item; // [esp+CCh] [ebp-3F8h] BYREF

  vostok::fixed_string<32>::fixed_string<32>(&new_stats_item.caption);
  vostok::fixed_vector<vostok::fixed_string<46>,16>::fixed_vector<vostok::fixed_string<46>,16>(&new_stats_item.content);
  vostok::buffer_string::operator=(&this->m_name, &new_stats_item.caption);
  vostok::buffer_string::append(&new_stats_item.caption, " selector state:");
  for ( i = 0; ; ++i )
  {
    max_count[1] = (unsigned int)&this->m_selected_weapons;
    if ( i >= this->m_selected_weapons.m_end - this->m_selected_weapons.m_begin )
      break;
    src = (char *)this->get_target_caption(this, i);
    max_count[0] = 46;
    vostok::buffer_string::buffer_string(&v9, v9.m_buffer, max_count, src);
    vostok::buffer_vector<vostok::fixed_string<46>>::push_back(&new_stats_item.content, &v9);
  }
  v5[1] = (unsigned int)&this->m_selected_weapons;
  m_begin = this->m_selected_weapons.m_begin;
  v3 = m_begin == this->m_selected_weapons.m_end;
  if ( m_begin == this->m_selected_weapons.m_end )
  {
    v5[0] = 46;
    vostok::buffer_string::buffer_string(&v8, v8.m_buffer, v5, "none");
    vostok::buffer_vector<vostok::fixed_string<46>>::push_back(&new_stats_item.content, &v8);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
  vostok::buffer_vector<vostok::ai::statistics_item<46,16>>::construct(stats->selectors_state.m_end, &new_stats_item);
  ++stats->selectors_state.m_end;
  vostok::ai::statistics_item<46,16>::~statistics_item<46,16>(
    (vostok::ai::statistics_item<46,16> *)&stats->selectors_state,
    (int)&new_stats_item);
}
