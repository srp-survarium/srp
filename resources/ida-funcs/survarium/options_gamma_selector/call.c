void __thiscall survarium::options_gamma_selector::call(
        survarium::options_gamma_selector *this,
        survarium::flash_function_handler_params *params)
{
  float v3; // xmm0_4
  survarium::flash_value *pRetVal; // esi
  vostok::render::scene_renderer *m_game; // ecx

  v3 = *(double *)&params->pArgs->body[8];
  this->m_current_value = v3;
  pRetVal = params->pRetVal;
  if ( (*(_DWORD *)&params->pRetVal->body[4] & 0x40) != 0 )
  {
    (*(void (__stdcall **)(survarium::flash_value *, _DWORD))(**(_DWORD **)pRetVal->body + 8))(
      pRetVal,
      *(_DWORD *)&pRetVal->body[8]);
    *(_DWORD *)pRetVal->body = 0;
  }
  *(_DWORD *)&pRetVal->body[4] = 5;
  *(double *)&pRetVal->body[8] = v3;
  m_game = (vostok::render::scene_renderer *)this->m_parent_tab->m_game->m_active_scene->m_game;
  vostok::render::scene_renderer::set_gamma_correction_factor(
    m_game,
    *(const float *)&m_game[1].m_channel->m_channel.m_forward_queue.m_cache_line_pad[4]);
}
