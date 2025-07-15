void __thiscall vostok::sound::sound_scene_statistic::fill_text_tree(
        vostok::sound::sound_scene_statistic *this,
        vostok::strings::text_tree_item *item)
{
  vostok::fixed_string<64> temp; // [esp+24h] [ebp-58h] BYREF
  vostok::strings::text_tree_item *stats; // [esp+78h] [ebp-4h]

  vostok::fixed_string<64>::fixed_string<64>(&temp);
  stats = 0;
  stats = vostok::strings::text_tree_item::new_child(item, "voices count(mono:st)", 0);
  vostok::buffer_string::assignf(
    &temp,
    "%d:%d",
    this->values.m_active_voices_count[0],
    this->values.m_active_voices_count[1]);
  vostok::strings::text_tree_item::add_column_impl(stats, temp.m_begin);
  stats = vostok::strings::text_tree_item::new_child(item, "proxies count", 0);
  vostok::buffer_string::assignf(&temp, "%d", this->values.m_active_proxies_count);
  vostok::strings::text_tree_item::add_column_impl(stats, temp.m_begin);
  stats = vostok::strings::text_tree_item::new_child(item, "propagators count", 0);
  vostok::buffer_string::assignf(&temp, "%d", this->values.m_propagators_count);
  vostok::strings::text_tree_item::add_column_impl(stats, temp.m_begin);
  stats = vostok::strings::text_tree_item::new_child(item, "proxy types", 0);
  vostok::buffer_string::assignf(
    &temp,
    "point:[%d] hud:[%d]",
    this->values.m_sound_types[0],
    this->values.m_sound_types[3]);
  vostok::strings::text_tree_item::add_column_impl(stats, temp.m_begin);
}
