_DWORD *__userpurge vostok::render::render_cc_float::render_cc_float@<eax>(
        vostok::render::render_cc_float *this@<ecx>,
        int a2@<eax>,
        float *a3@<edx>,
        _DWORD *a4@<esi>,
        int a5@<xmm0>,
        const char *name,
        float *prev_value,
        const char *max,
        float *a9,
        float *a10,
        float a11,
        float a12,
        bool a13,
        enum vostok::console_commands::command_type a14)
{
  survarium::game_action_id *M_start; // eax

  a4[3] = a2;
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  *a4 = &vostok::render::render_cc::`vftable';
  a4[2] = 0;
  a4[1] = *M_start;
  *M_start = (survarium::game_action_id)a4;
  vostok::console_commands::cc_value<float>::cc_value<float>(
    (int)(a4 + 4),
    a5,
    name,
    a3,
    *(float *)&max,
    1,
    command_type_user_specific,
    execution_filter_general);
  a4[4] = &stru_95AF78.m_key_bindings[48];
  a4[4] = &vostok::render::render_cc_float::`vftable'{for `vostok::console_commands::cc_float'};
  *a4 = &vostok::render::render_cc_float::`vftable'{for `vostok::render::render_cc'};
  a4[24] = prev_value;
  return a4;
}
