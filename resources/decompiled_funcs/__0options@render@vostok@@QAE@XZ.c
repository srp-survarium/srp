void __usercall vostok::render::options::options(vostok::render::options *this@<ecx>, int a2@<eax>)
{
  vostok::render::options *v3; // ecx

  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start = (survarium::game_action_id *)a2;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  vostok::render::options::register_console_commands(this);
  vostok::render::options::set_default_values(v3, a2);
}
