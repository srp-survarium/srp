void __thiscall survarium::network_client::draw_stats(
        survarium::network_client *this,
        survarium::network_client *current_time_in_ms,
        unsigned int current_time_in_msa)
{
  survarium::flash_text_manager *m_text_manager; // edi
  survarium::flash_text_manager *v4; // ecx
  survarium::flash_text *v5; // eax
  survarium::flash_text *p_m_max_local_sequence_difference_caption; // esi
  int v7; // ecx
  Scaleform::GFx::DrawText *text_impl; // ecx
  survarium::flash_text *v9; // ecx
  survarium::flash_text_manager *v10; // ecx
  survarium::flash_text *v11; // eax
  survarium::flash_text *p_m_max_local_sequence_difference_value; // esi
  int v13; // ecx
  Scaleform::GFx::DrawText *v14; // ecx
  survarium::flash_text *v15; // ecx
  survarium::flash_text_manager *v16; // ecx
  survarium::flash_text *v17; // eax
  survarium::flash_text *p_m_unacknowledged_packets_caption; // esi
  int v19; // ecx
  Scaleform::GFx::DrawText *v20; // ecx
  survarium::flash_text *v21; // ecx
  survarium::flash_text_manager *v22; // ecx
  survarium::flash_text *v23; // eax
  survarium::flash_text *p_m_unacknowledged_packets_value; // esi
  int v25; // ecx
  Scaleform::GFx::DrawText *v26; // ecx
  survarium::flash_text_manager *owner; // ecx
  survarium::stats_row *v28; // ecx
  survarium::stats_row *v29; // ecx
  survarium::stats_row *v30; // ecx
  survarium::stats_row *v31; // ecx
  survarium::stats_row *v32; // ecx
  bool v33; // al
  Scaleform::GFx::DrawText *v34; // ecx
  Scaleform::GFx::DrawText *v35; // ecx
  Scaleform::GFx::DrawText *v36; // ecx
  Scaleform::GFx::DrawText *v37; // ecx
  float v38; // [esp+48h] [ebp-1A4h]
  float v39; // [esp+48h] [ebp-1A4h]
  float v40; // [esp+48h] [ebp-1A4h]
  float v41; // [esp+48h] [ebp-1A4h]
  float v42; // [esp+48h] [ebp-1A4h]
  float v43; // [esp+48h] [ebp-1A4h]
  const char *v44; // [esp+48h] [ebp-1A4h]
  const char *v45; // [esp+48h] [ebp-1A4h]
  const char *v46; // [esp+48h] [ebp-1A4h]
  const char *v47; // [esp+48h] [ebp-1A4h]
  float v48; // [esp+4Ch] [ebp-1A0h]
  float v49; // [esp+4Ch] [ebp-1A0h]
  float v50; // [esp+4Ch] [ebp-1A0h]
  float v51; // [esp+4Ch] [ebp-1A0h]
  float v52; // [esp+4Ch] [ebp-1A0h]
  float v53; // [esp+4Ch] [ebp-1A0h]
  float v54; // [esp+50h] [ebp-19Ch]
  float v55; // [esp+50h] [ebp-19Ch]
  float v56; // [esp+50h] [ebp-19Ch]
  float v57; // [esp+50h] [ebp-19Ch]
  float v58; // [esp+50h] [ebp-19Ch]
  float v59; // [esp+50h] [ebp-19Ch]
  float v60; // [esp+54h] [ebp-198h]
  float v61; // [esp+54h] [ebp-198h]
  float v62; // [esp+54h] [ebp-198h]
  float v63; // [esp+54h] [ebp-198h]
  float v64; // [esp+54h] [ebp-198h]
  float v65; // [esp+54h] [ebp-198h]
  survarium::flash_text *column3_width; // [esp+58h] [ebp-194h] BYREF
  const vostok::math::color *v67[3]; // [esp+5Ch] [ebp-190h] BYREF
  char text[256]; // [esp+68h] [ebp-184h] BYREF
  vostok::network_core::udp_match_stats difference; // [esp+168h] [ebp-84h] BYREF

  if ( first_time_0 )
  {
    m_text_manager = current_time_in_ms->m_game->m_game_world.m_text_manager;
    if ( !m_text_manager )
      return;
    first_time_0 = 0;
    survarium::stats_row::create(
      &current_time_in_ms->m_sent,
      m_text_manager,
      "sent :",
      200.0,
      COERCE_CONST_FLOAT(&column3_width),
      v38,
      v48,
      v54,
      v60,
      NAN,
      v67[0]);
    survarium::stats_row::create(
      &current_time_in_ms->m_sent_low_level,
      m_text_manager,
      "sent (low level) :",
      240.0,
      COERCE_CONST_FLOAT(&column3_width),
      v39,
      v49,
      v55,
      v61,
      -1.7147039e38,
      v67[0]);
    survarium::stats_row::create(
      &current_time_in_ms->m_resent,
      m_text_manager,
      "re-sent :",
      280.0,
      COERCE_CONST_FLOAT(&column3_width),
      v40,
      v50,
      v56,
      v62,
      NAN,
      v67[0]);
    survarium::stats_row::create(
      &current_time_in_ms->m_received,
      m_text_manager,
      "received :",
      220.0,
      COERCE_CONST_FLOAT(&column3_width),
      v41,
      v51,
      v57,
      v63,
      -1.7147039e38,
      v67[0]);
    survarium::stats_row::create(
      &current_time_in_ms->m_received_low_level,
      m_text_manager,
      "received (low level) :",
      260.0,
      COERCE_CONST_FLOAT(&column3_width),
      v42,
      v52,
      v58,
      v64,
      NAN,
      v67[0]);
    survarium::stats_row::create(
      &current_time_in_ms->m_received_duplicated,
      m_text_manager,
      "received (duplicates) :",
      300.0,
      COERCE_CONST_FLOAT(&column3_width),
      v43,
      v53,
      v59,
      v65,
      -1.7147039e38,
      v67[0]);
    v5 = survarium::flash_text_manager::create_text(
           v4,
           (int)m_text_manager,
           (int)v67,
           (survarium::flash_text *)&stru_96CBB8,
           v44);
    p_m_max_local_sequence_difference_caption = &current_time_in_ms->m_max_local_sequence_difference_caption;
    *(_QWORD *)&current_time_in_ms->m_max_local_sequence_difference_caption.text_impl = *(_QWORD *)&v5->text_impl;
    v7 = *(_DWORD *)&v5->visible;
    *(_DWORD *)&current_time_in_ms->m_max_local_sequence_difference_caption.visible = v7;
    if ( (_BYTE)v7 != 1 )
    {
      text_impl = p_m_max_local_sequence_difference_caption->text_impl;
      current_time_in_ms->m_max_local_sequence_difference_caption.visible = 1;
      text_impl->SetVisible(text_impl, 1);
      current_time_in_ms->m_max_local_sequence_difference_caption.owner->need_capture = 1;
    }
    ((void (__thiscall *)(Scaleform::GFx::DrawText *, int, _DWORD, int))p_m_max_local_sequence_difference_caption->text_impl->SetColor)(
      p_m_max_local_sequence_difference_caption->text_impl,
      -16711681,
      0,
      -1);
    current_time_in_ms->m_max_local_sequence_difference_caption.owner->need_capture = 1;
    survarium::flash_text::set_position(v9, p_m_max_local_sequence_difference_caption, 150.0, 320.0);
    v11 = survarium::flash_text_manager::create_text(
            v10,
            (int)m_text_manager,
            (int)v67,
            (survarium::flash_text *)&buf,
            v45);
    p_m_max_local_sequence_difference_value = &current_time_in_ms->m_max_local_sequence_difference_value;
    *(_QWORD *)&current_time_in_ms->m_max_local_sequence_difference_value.text_impl = *(_QWORD *)&v11->text_impl;
    v13 = *(_DWORD *)&v11->visible;
    *(_DWORD *)&current_time_in_ms->m_max_local_sequence_difference_value.visible = v13;
    if ( (_BYTE)v13 != 1 )
    {
      v14 = p_m_max_local_sequence_difference_value->text_impl;
      current_time_in_ms->m_max_local_sequence_difference_value.visible = 1;
      v14->SetVisible(v14, 1);
      current_time_in_ms->m_max_local_sequence_difference_value.owner->need_capture = 1;
    }
    ((void (__thiscall *)(Scaleform::GFx::DrawText *, int, _DWORD, int))p_m_max_local_sequence_difference_value->text_impl->SetColor)(
      p_m_max_local_sequence_difference_value->text_impl,
      -16711681,
      0,
      -1);
    current_time_in_ms->m_max_local_sequence_difference_value.owner->need_capture = 1;
    survarium::flash_text::set_position(v15, p_m_max_local_sequence_difference_value, 325.0, 320.0);
    v17 = survarium::flash_text_manager::create_text(
            v16,
            (int)m_text_manager,
            (int)v67,
            (survarium::flash_text *)&stru_96CBC8,
            v46);
    p_m_unacknowledged_packets_caption = &current_time_in_ms->m_unacknowledged_packets_caption;
    *(_QWORD *)&current_time_in_ms->m_unacknowledged_packets_caption.text_impl = *(_QWORD *)&v17->text_impl;
    v19 = *(_DWORD *)&v17->visible;
    *(_DWORD *)&current_time_in_ms->m_unacknowledged_packets_caption.visible = v19;
    if ( (_BYTE)v19 != 1 )
    {
      v20 = p_m_unacknowledged_packets_caption->text_impl;
      current_time_in_ms->m_unacknowledged_packets_caption.visible = 1;
      v20->SetVisible(v20, 1);
      current_time_in_ms->m_unacknowledged_packets_caption.owner->need_capture = 1;
    }
    ((void (__thiscall *)(Scaleform::GFx::DrawText *, int, _DWORD, int))p_m_unacknowledged_packets_caption->text_impl->SetColor)(
      p_m_unacknowledged_packets_caption->text_impl,
      -256,
      0,
      -1);
    current_time_in_ms->m_unacknowledged_packets_caption.owner->need_capture = 1;
    survarium::flash_text::set_position(v21, p_m_unacknowledged_packets_caption, 150.0, 340.0);
    v23 = survarium::flash_text_manager::create_text(
            v22,
            (int)m_text_manager,
            (int)v67,
            (survarium::flash_text *)&buf,
            v47);
    p_m_unacknowledged_packets_value = &current_time_in_ms->m_unacknowledged_packets_value;
    *(_QWORD *)&current_time_in_ms->m_unacknowledged_packets_value.text_impl = *(_QWORD *)&v23->text_impl;
    v25 = *(_DWORD *)&v23->visible;
    *(_DWORD *)&current_time_in_ms->m_unacknowledged_packets_value.visible = v25;
    if ( (_BYTE)v25 != 1 )
    {
      v26 = p_m_unacknowledged_packets_value->text_impl;
      current_time_in_ms->m_unacknowledged_packets_value.visible = 1;
      v26->SetVisible(v26, 1);
      current_time_in_ms->m_unacknowledged_packets_value.owner->need_capture = 1;
    }
    ((void (__thiscall *)(Scaleform::GFx::DrawText *, int, _DWORD, int))p_m_unacknowledged_packets_value->text_impl->SetColor)(
      p_m_unacknowledged_packets_value->text_impl,
      -256,
      0,
      -1);
    owner = current_time_in_ms->m_unacknowledged_packets_value.owner;
    owner->need_capture = 1;
    survarium::flash_text::set_position((survarium::flash_text *)owner, p_m_unacknowledged_packets_value, 325.0, 340.0);
  }
  survarium::stats_row::set_visible((survarium::stats_row *)this, (int *)&current_time_in_ms->m_sent);
  survarium::stats_row::set_visible(v28, (int *)&current_time_in_ms->m_sent_low_level);
  survarium::stats_row::set_visible(v29, (int *)&current_time_in_ms->m_resent);
  survarium::stats_row::set_visible(v30, (int *)&current_time_in_ms->m_received);
  survarium::stats_row::set_visible(v31, (int *)&current_time_in_ms->m_received_low_level);
  survarium::stats_row::set_visible(v32, (int *)&current_time_in_ms->m_received_duplicated);
  v33 = s_show_network_statistics;
  if ( current_time_in_ms->m_max_local_sequence_difference_caption.visible != s_show_network_statistics )
  {
    v34 = current_time_in_ms->m_max_local_sequence_difference_caption.text_impl;
    current_time_in_ms->m_max_local_sequence_difference_caption.visible = s_show_network_statistics;
    v34->SetVisible(v34, s_show_network_statistics);
    current_time_in_ms->m_max_local_sequence_difference_caption.owner->need_capture = 1;
    v33 = s_show_network_statistics;
  }
  if ( current_time_in_ms->m_max_local_sequence_difference_value.visible != v33 )
  {
    v35 = current_time_in_ms->m_max_local_sequence_difference_value.text_impl;
    current_time_in_ms->m_max_local_sequence_difference_value.visible = v33;
    v35->SetVisible(v35, s_show_network_statistics);
    current_time_in_ms->m_max_local_sequence_difference_value.owner->need_capture = 1;
    v33 = s_show_network_statistics;
  }
  if ( current_time_in_ms->m_unacknowledged_packets_caption.visible != v33 )
  {
    v36 = current_time_in_ms->m_unacknowledged_packets_caption.text_impl;
    current_time_in_ms->m_unacknowledged_packets_caption.visible = v33;
    v36->SetVisible(v36, s_show_network_statistics);
    current_time_in_ms->m_unacknowledged_packets_caption.owner->need_capture = 1;
    v33 = s_show_network_statistics;
  }
  column3_width = &current_time_in_ms->m_unacknowledged_packets_value;
  if ( current_time_in_ms->m_unacknowledged_packets_value.visible != v33 )
  {
    v37 = current_time_in_ms->m_unacknowledged_packets_value.text_impl;
    current_time_in_ms->m_unacknowledged_packets_value.visible = v33;
    v37->SetVisible(v37, s_show_network_statistics);
    current_time_in_ms->m_unacknowledged_packets_value.owner->need_capture = 1;
  }
  survarium::stats_row::set_text(
    &current_time_in_ms->m_sent,
    current_time_in_msa,
    &current_time_in_ms->m_match_client.m_client.m_stats.sent,
    &current_time_in_ms->m_previous_stats.sent);
  survarium::stats_row::set_text(
    &current_time_in_ms->m_sent_low_level,
    current_time_in_msa,
    &current_time_in_ms->m_match_client.m_client.m_stats.sent_low_level,
    &current_time_in_ms->m_previous_stats.sent_low_level);
  survarium::stats_row::set_text(
    &current_time_in_ms->m_resent,
    current_time_in_msa,
    &current_time_in_ms->m_match_client.m_client.m_stats.resent,
    &current_time_in_ms->m_previous_stats.resent);
  survarium::stats_row::set_text(
    &current_time_in_ms->m_received,
    current_time_in_msa,
    &current_time_in_ms->m_match_client.m_client.m_stats.received,
    &current_time_in_ms->m_previous_stats.received);
  survarium::stats_row::set_text(
    &current_time_in_ms->m_received_low_level,
    current_time_in_msa,
    &current_time_in_ms->m_match_client.m_client.m_stats.received_low_level,
    &current_time_in_ms->m_previous_stats.received_low_level);
  survarium::stats_row::set_text(
    &current_time_in_ms->m_received_duplicated,
    current_time_in_msa,
    &current_time_in_ms->m_match_client.m_client.m_stats.received_duplicated,
    &current_time_in_ms->m_previous_stats.received_duplicated);
  qmemcpy(
    &current_time_in_ms->m_previous_stats,
    &current_time_in_ms->m_match_client.m_client.m_stats,
    sizeof(current_time_in_ms->m_previous_stats));
  vostok::network_core::operator-(
    &current_time_in_ms->m_match_client.m_client.m_stats,
    &current_time_in_ms->m_previous_stats,
    0,
    (int)&difference);
  vostok::sprintf<256>(
    (char (*)[256])text,
    "%3d packets",
    current_time_in_ms->m_previous_stats.max_local_sequence_difference);
  survarium::flash_text::set_text(&current_time_in_ms->m_max_local_sequence_difference_value, text);
  vostok::sprintf<256>((char (*)[256])text, "%3d packets", current_time_in_ms->m_previous_stats.unacknowledged_packets);
  survarium::flash_text::set_text(column3_width, text);
}
