char __userpurge survarium::lobby_menu::on_mouse_key_action@<al>(
        survarium::lobby_menu *this@<ecx>,
        float a2@<edi>,
        vostok::input::world *input_world,
        vostok::input::mouse_button button,
        survarium::flash_movie *action)
{
  float m_last_queries_count; // xmm1_4
  float m_level_loading_progress_low; // xmm0_4
  survarium::flash_movie *v8; // edx
  int *p_m_last_queries_count; // ebx
  unsigned int v10; // ecx
  float z; // ecx
  float y; // xmm0_4
  float w; // eax
  float v15; // [esp+8h] [ebp-28h]
  float v16; // [esp+Ch] [ebp-24h]
  struct survarium::flash_movie *v17; // [esp+10h] [ebp-20h]
  survarium::flash_value v; // [esp+18h] [ebp-18h] BYREF

  m_last_queries_count = (float)(int)this[-1].m_last_queries_count;
  m_level_loading_progress_low = (float)SLODWORD(this[-1].m_level_loading_progress);
  v8 = *(survarium::flash_movie **)(*(_DWORD *)(*(_DWORD *)(this[-1].m_match_stats.last_match_r2_delta + 892) + 28) + 264);
  p_m_last_queries_count = (int *)&this[-1].m_last_queries_count;
  v10 = 0;
  switch ( button )
  {
    case mouse_button_left:
      v10 = 0;
      break;
    case mouse_button_right:
      v10 = 1;
      break;
    case mouse_button_middle:
      v10 = 2;
      break;
  }
  survarium::flash_movie::HandleMouseBtn(action, m_level_loading_progress_low, v8, v10, m_last_queries_count, a2);
  if ( BYTE2(this->m_inverted_view_matrix.lines[2].elements[1]) )
  {
    z = this->m_inverted_view_matrix.i.z;
    *(_DWORD *)v.body = 0;
    *(_DWORD *)&v.body[4] = 0;
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(LODWORD(z) + 264) + 4),
      "root.anyMessage",
      (Scaleform::GFx::Value *)&v,
      0,
      0);
    y = (float)*p_m_last_queries_count;
    if ( v.body[8] )
    {
      survarium::swf_input_translator::process_mouse_btn(
        *(survarium::swf_input_translator **)(LODWORD(this->m_inverted_view_matrix.i.z) + 264),
        (vostok::input::enum_mouse_key_action)action,
        SLODWORD(y),
        *(enum vostok::input::enum_mouse_key_action *)(LODWORD(this->m_inverted_view_matrix.i.z) + 264),
        v15,
        v16,
        v17);
      if ( (v.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)v.body + 8))(
          *(_DWORD *)v.body,
          &v,
          *(_DWORD *)&v.body[8]);
        return 1;
      }
    }
    else
    {
      if ( BYTE1(this->m_inverted_view_matrix.lines[2].elements[1]) )
        w = this->m_inverted_view_matrix.i.w;
      else
        w = this->m_inverted_view_matrix.i.y;
      survarium::swf_input_translator::process_mouse_btn(
        *(survarium::swf_input_translator **)(LODWORD(w) + 264),
        (vostok::input::enum_mouse_key_action)action,
        SLODWORD(y),
        *(enum vostok::input::enum_mouse_key_action *)(LODWORD(w) + 264),
        v15,
        v16,
        v17);
      survarium::flash_value::~flash_value(&v);
    }
  }
  return 1;
}
