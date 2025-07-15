char __thiscall survarium::lobby_menu::on_mouse_move(
        survarium::lobby_menu *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  vostok::resources::unmanaged_resource *v6; // eax
  float m_level_loading_progress; // ecx
  survarium::flash_movie *type; // ecx
  int m_last_queries_count; // eax
  survarium::flash_movie *v10; // ecx
  float m_level_loading_progress_low; // [esp+0h] [ebp-14h]
  float v13; // [esp+4h] [ebp-10h]
  int xa; // [esp+1Ch] [ebp+8h]

  LODWORD(this[-1].m_level_loading_progress) += x;
  this[-1].m_last_queries_count += y;
  v6 = survarium::base_game_scene::output_window_size(
         (survarium::base_game_scene *)y,
         (int)&this[-1].m_projection_matrix.j.w);
  m_level_loading_progress = this[-1].m_level_loading_progress;
  if ( SLODWORD(m_level_loading_progress) > 0 )
  {
    if ( SLODWORD(m_level_loading_progress) > (int)v6->__vftable )
      m_level_loading_progress = *(float *)&v6->__vftable;
  }
  else
  {
    m_level_loading_progress = 0.0;
  }
  this[-1].m_level_loading_progress = m_level_loading_progress;
  type = (survarium::flash_movie *)v6->type;
  m_last_queries_count = this[-1].m_last_queries_count;
  if ( m_last_queries_count > 0 )
  {
    if ( m_last_queries_count > (int)type )
      m_last_queries_count = (int)type;
  }
  else
  {
    m_last_queries_count = 0;
  }
  this[-1].m_last_queries_count = m_last_queries_count;
  *(float *)&xa = (double)z * 0.0083333338;
  survarium::flash_movie::HandleMouseMove(
    type,
    *(_DWORD *)(LODWORD(this->m_inverted_view_matrix.i.x) + 264),
    (float)SLODWORD(this[-1].m_level_loading_progress),
    (float)m_last_queries_count,
    xa);
  survarium::flash_movie::HandleMouseMove(
    *(survarium::flash_movie **)(this[-1].m_match_stats.last_match_r2_delta + 892),
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this[-1].m_match_stats.last_match_r2_delta + 892) + 28) + 264),
    (float)SLODWORD(this[-1].m_level_loading_progress),
    (float)(int)this[-1].m_last_queries_count,
    xa);
  if ( BYTE2(this->m_inverted_view_matrix.lines[2].elements[1]) )
  {
    v13 = (float)(int)this[-1].m_last_queries_count;
    m_level_loading_progress_low = (float)SLODWORD(this[-1].m_level_loading_progress);
    if ( BYTE1(this->m_inverted_view_matrix.lines[2].elements[1]) )
    {
      survarium::flash_movie::HandleMouseMove(
        v10,
        *(_DWORD *)(LODWORD(this->m_inverted_view_matrix.i.w) + 264),
        m_level_loading_progress_low,
        v13,
        xa);
      return 1;
    }
    survarium::flash_movie::HandleMouseMove(
      (survarium::flash_movie *)LODWORD(this->m_inverted_view_matrix.i.y),
      *(_DWORD *)(LODWORD(this->m_inverted_view_matrix.i.y) + 264),
      m_level_loading_progress_low,
      v13,
      xa);
  }
  return 1;
}
