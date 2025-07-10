void __userpurge vostok::render::render_cc::render_cc(
        vostok::render::render_cc *this@<ecx>,
        _DWORD *a2@<eax>,
        const char *define_name,
        vostok::render::enum_options_changes_result changed_result)
{
  survarium::game_action_id *M_start; // ecx

  a2[2] = this;
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  *a2 = &vostok::render::render_cc::`vftable';
  a2[3] = define_name;
  a2[1] = *M_start;
  *M_start = (survarium::game_action_id)a2;
}
