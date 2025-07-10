void __thiscall survarium::body_part_parameters::dump_state(
        survarium::body_part_parameters *this,
        vostok::ai::npc_statistics *stats,
        unsigned int current_time_in_ms)
{
  vostok::ai::statistics_item<46,16> *v3; // ecx
  vostok::ai::statistics_item<46,16> new_stats_item; // [esp+44h] [ebp-3F8h] BYREF

  vostok::fixed_string<32>::fixed_string<32>(&new_stats_item.caption);
  vostok::fixed_vector<vostok::fixed_string<46>,16>::fixed_vector<vostok::fixed_string<46>,16>(&new_stats_item.content);
  survarium::body_part_parameters::fill_new_stats_item<vostok::ai::statistics_item<46,16>>(
    this,
    &new_stats_item,
    current_time_in_ms);
  vostok::buffer_vector<vostok::ai::statistics_item<46,16>>::push_back(&stats->body_state, &new_stats_item);
  vostok::ai::statistics_item<46,16>::~statistics_item<46,16>(v3, (int)&new_stats_item);
}
