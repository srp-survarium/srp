void __thiscall vostok::sound::proxy_statistic::fill_text_tree(
        vostok::sound::proxy_statistic *this,
        vostok::strings::text_tree_item *item,
        bool draw_propagators_stats)
{
  vostok::sound::emitter_type m_emitter_type; // [esp+20h] [ebp-9Ch]
  unsigned int max_count; // [esp+58h] [ebp-64h] BYREF
  vostok::sound::propagator_statistic *prop; // [esp+5Ch] [ebp-60h]
  vostok::strings::text_tree_item *detail; // [esp+60h] [ebp-5Ch]
  vostok::fixed_string<64> temp; // [esp+64h] [ebp-58h] BYREF
  vostok::strings::text_tree_item *stats; // [esp+B8h] [ebp-4h]

  max_count = 64;
  vostok::buffer_string::buffer_string(&temp, temp.m_buffer, &max_count);
  temp.m_buffer[0] = 0;
  stats = vostok::strings::text_tree_item::new_child(item, "proxy id", 0);
  vostok::buffer_string::assignf(&temp, "%d", this->m_id);
  vostok::strings::text_tree_item::add_column_impl(stats, temp.m_begin);
  detail = vostok::strings::text_tree_item::new_child(stats, "emitter type", 0);
  m_emitter_type = this->m_emitter_type;
  switch ( m_emitter_type )
  {
    case single:
      goto LABEL_4;
    case composite:
      vostok::strings::text_tree_item::add_column_impl(detail, "composite");
      break;
    case collection:
      vostok::strings::text_tree_item::add_column_impl(detail, "collection");
      break;
    default:
LABEL_4:
      vostok::strings::text_tree_item::add_column_impl(detail, "single");
      break;
  }
  detail = vostok::strings::text_tree_item::new_child(stats, "sound type", 0);
  switch ( this->m_sound_type )
  {
    case point:
      vostok::strings::text_tree_item::add_column_impl(detail, "point");
      detail = vostok::strings::text_tree_item::new_child(stats, "position", 0);
      vostok::buffer_string::assignf(
        &temp,
        "%.2f, %.2f, %.2f",
        this->m_position.x,
        this->m_position.y,
        this->m_position.z);
      vostok::strings::text_tree_item::add_column_impl(detail, temp.m_begin);
      break;
    case cone:
      vostok::strings::text_tree_item::add_column_impl(detail, "cone");
      detail = vostok::strings::text_tree_item::new_child(stats, "position", 0);
      vostok::buffer_string::assignf(
        &temp,
        "%.2f, %.2f, %.2f",
        this->m_position.x,
        this->m_position.y,
        this->m_position.z);
      vostok::strings::text_tree_item::add_column_impl(detail, temp.m_begin);
      detail = vostok::strings::text_tree_item::new_child(
                 stats,
                 (const char *)&stru_96A440.m_inverted_view.lines[2].elements[2],
                 0);
      vostok::buffer_string::assignf(
        &temp,
        "%.2f, %.2f, %.2f",
        this->m_direction.x,
        this->m_direction.y,
        this->m_direction.z);
      vostok::strings::text_tree_item::add_column_impl(detail, temp.m_begin);
      detail = vostok::strings::text_tree_item::new_child(stats, "cone type", 0);
      vostok::strings::text_tree_item::add_column_impl(detail, "human");
      break;
    case volumetric:
      vostok::strings::text_tree_item::add_column_impl(detail, "volumetric");
      detail = vostok::strings::text_tree_item::new_child(stats, "position", 0);
      vostok::buffer_string::assignf(
        &temp,
        "%.2f, %.2f, %.2f",
        this->m_position.x,
        this->m_position.y,
        this->m_position.z);
      vostok::strings::text_tree_item::add_column_impl(detail, temp.m_begin);
      break;
    case hud:
      vostok::strings::text_tree_item::add_column_impl(detail, "hud");
      detail = vostok::strings::text_tree_item::new_child(stats, "position", 0);
      vostok::buffer_string::assignf(
        &temp,
        "%.2f, %.2f, %.2f",
        this->m_position.x,
        this->m_position.y,
        this->m_position.z);
      vostok::strings::text_tree_item::add_column_impl(detail, temp.m_begin);
      break;
  }
  if ( draw_propagators_stats )
  {
    for ( prop = this->m_propagator_statistics.m_first; prop; prop = prop->next )
      vostok::sound::propagator_statistic::fill_text_tree(prop, detail);
  }
}
