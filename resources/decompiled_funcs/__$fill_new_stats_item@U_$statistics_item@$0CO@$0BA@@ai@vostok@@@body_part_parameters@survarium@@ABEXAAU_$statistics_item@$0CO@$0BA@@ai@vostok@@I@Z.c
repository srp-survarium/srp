void __thiscall survarium::body_part_parameters::fill_new_stats_item<vostok::ai::statistics_item<46,16>>(
        survarium::body_part_parameters *this,
        vostok::ai::statistics_item<46,16> *new_stats_item,
        unsigned int current_time_in_ms)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *second; // ecx
  survarium::game_camera *v5; // [esp+1Ch] [ebp-E0h]
  unsigned int max_count[5]; // [esp+30h] [ebp-CCh] BYREF
  char v8; // [esp+44h] [ebp-B8h]
  char v9; // [esp+45h] [ebp-B7h]
  char v10; // [esp+46h] [ebp-B6h]
  vostok::fixed_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>,8> *p_m_affects; // [esp+48h] [ebp-B4h]
  vostok::fixed_string<46> v12; // [esp+7Ch] [ebp-80h] BYREF
  unsigned int remaining_time_in_ms; // [esp+B8h] [ebp-44h]
  unsigned int i; // [esp+BCh] [ebp-40h]
  vostok::fixed_string<46> new_item; // [esp+C0h] [ebp-3Ch] BYREF

  vostok::buffer_string::operator=((vostok::fixed_string<32> *)&this->m_name, &new_stats_item->caption);
  vostok::buffer_string::append(&new_stats_item->caption, (char *)&stru_977D0C.m_end);
  vostok::fixed_string<46>::fixed_string<46>(&new_item);
  vostok::buffer_string::appendf(
    (vostok::buffer_string *)&stru_977D18,
    (const char *)COERCE_UNSIGNED_INT64(this->m_health),
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(this->m_health)),
    this->m_max_health);
  vostok::buffer_vector<vostok::fixed_string<46>>::push_back(&new_stats_item->content, &new_item);
  vostok::fs_new::path_string_impl::clear(&new_item);
  vostok::buffer_string::append(&new_item, "affects: ");
  vostok::buffer_vector<vostok::fixed_string<46>>::push_back(&new_stats_item->content, &new_item);
  for ( i = 0; ; ++i )
  {
    p_m_affects = &this->m_affects;
    if ( i >= this->m_affects.m_end - this->m_affects.m_begin )
      break;
    vostok::fs_new::path_string_impl::clear(&new_item);
    v10 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    second = (survarium::game_camera *)this->m_affects.m_begin[i].second;
    if ( (unsigned int)second < current_time_in_ms )
    {
      v5 = 0;
    }
    else
    {
      v9 = 0;
      survarium::weapon_user_dead_state::finalize(second);
      v5 = (survarium::game_camera *)(this->m_affects.m_begin[i].second - current_time_in_ms);
    }
    remaining_time_in_ms = (unsigned int)v5;
    v8 = 0;
    survarium::weapon_user_dead_state::finalize(v5);
    vostok::buffer_string::appendf(
      (vostok::buffer_string *)&stru_977D34,
      affects_captions_16[this->m_affects.m_begin[i].first],
      (double)(unsigned int)v5 / 1000.0);
    vostok::buffer_vector<vostok::fixed_string<46>>::push_back(&new_stats_item->content, &new_item);
  }
  max_count[1] = (unsigned int)&this->m_affects;
  if ( this->m_affects.m_begin == this->m_affects.m_end )
  {
    max_count[0] = 46;
    vostok::buffer_string::buffer_string(&v12, v12.m_buffer, max_count, "none");
    vostok::buffer_vector<vostok::fixed_string<46>>::push_back(&new_stats_item->content, &v12);
  }
}
