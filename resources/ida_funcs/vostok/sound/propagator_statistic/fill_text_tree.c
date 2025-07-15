void __thiscall vostok::sound::propagator_statistic::fill_text_tree(
        vostok::sound::propagator_statistic *this,
        vostok::strings::text_tree_item *item)
{
  vostok::fixed_string<64> temp; // [esp+24h] [ebp-58h] BYREF
  vostok::strings::text_tree_item *stats; // [esp+78h] [ebp-4h]

  vostok::fixed_string<64>::fixed_string<64>(&temp);
  stats = vostok::strings::text_tree_item::new_child(item, this->m_filename.m_begin, 0);
  stats = vostok::strings::text_tree_item::new_child(item, "length", 0);
  vostok::buffer_string::assignf(&temp, "%d", this->m_length);
  vostok::strings::text_tree_item::add_column_impl(stats, temp.m_begin);
  stats = vostok::strings::text_tree_item::new_child(item, "current_playing_time", 0);
  vostok::buffer_string::assignf(&temp, "%d", this->m_current_playing_time);
  vostok::strings::text_tree_item::add_column_impl(stats, temp.m_begin);
  stats = vostok::strings::text_tree_item::new_child(item, "playback_mode", 0);
  if ( this->m_playback_mode == looped )
    vostok::strings::text_tree_item::add_column_impl(stats, "looped");
  else
    vostok::strings::text_tree_item::add_column_impl(stats, "once");
}
