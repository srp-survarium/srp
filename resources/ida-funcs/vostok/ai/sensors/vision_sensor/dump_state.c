void __thiscall vostok::ai::sensors::vision_sensor::dump_state(
        vostok::ai::sensors::vision_sensor *this,
        vostok::ai::npc_statistics *stats)
{
  BOOL v2; // ecx
  vostok::ai::statistics_item<46,16> *v3; // ecx
  unsigned int v5[4]; // [esp+34h] [ebp-498h] BYREF
  char *src; // [esp+44h] [ebp-488h]
  unsigned int max_count[4]; // [esp+48h] [ebp-484h] BYREF
  vostok::fixed_string<46> v8; // [esp+58h] [ebp-474h] BYREF
  vostok::fixed_string<46> v9; // [esp+94h] [ebp-438h] BYREF
  vostok::ai::sensed_visual_object *iter; // [esp+D0h] [ebp-3FCh]
  vostok::ai::statistics_item<46,16> new_stats_item; // [esp+D4h] [ebp-3F8h] BYREF

  vostok::fixed_string<32>::fixed_string<32>(&new_stats_item.caption);
  vostok::fixed_vector<vostok::fixed_string<46>,16>::fixed_vector<vostok::fixed_string<46>,16>(&new_stats_item.content);
  vostok::fixed_string<16>::operator=(&stru_9803D4, &new_stats_item.caption);
  for ( iter = this->m_visible_objects.m_first; iter; iter = iter->next )
  {
    src = (char *)iter->object->get_name((vostok::ai::game_object *)iter->object);
    max_count[0] = 46;
    vostok::buffer_string::buffer_string(&v9, v9.m_buffer, max_count, src);
    vostok::buffer_vector<vostok::fixed_string<46>>::push_back(&new_stats_item.content, &v9);
  }
  v2 = this->m_visible_objects.m_first == 0;
  if ( !this->m_visible_objects.m_first )
  {
    v5[0] = 46;
    vostok::buffer_string::buffer_string(&v8, v8.m_buffer, v5, "none");
    vostok::buffer_vector<vostok::fixed_string<46>>::push_back(&new_stats_item.content, &v8);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v2);
  vostok::buffer_vector<vostok::ai::statistics_item<46,16>>::construct(stats->sensors_state.m_end, &new_stats_item);
  v3 = stats->sensors_state.m_end + 1;
  stats->sensors_state.m_end = v3;
  vostok::ai::statistics_item<46,16>::~statistics_item<46,16>(v3, (int)&new_stats_item);
}
