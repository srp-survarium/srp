void __userpurge vostok::render::engine::world::world(
        vostok::render::engine::world *this@<ecx>,
        int a2@<esi>,
        const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *in_config,
        bool is_editor)
{
  vostok::render::options *v4; // ecx
  vostok::render::options *v5; // ecx
  vostok::render *v6; // [esp+0h] [ebp-Ch]

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_BYTE *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 9) = 0;
  if ( !vostok::render::does_os_support_dx11() )
    vostok::debug::terminate(
      "Your operating system doesn't support DirectX 11.\r\n"
      "Please upgrade your OS to Windows Vista Service Pack 2 + Platform Update or later.");
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start = (survarium::game_action_id *)&s_options;
  *(_DWORD *)s_options.m_static_memory = 0;
  *(_DWORD *)&s_options.m_static_memory[4] = 0;
  *(_DWORD *)&s_options.m_static_memory[8] = 0;
  vostok::render::options::register_console_commands(v4);
  vostok::render::options::set_default_values(v5, (int)&s_options);
  _InterlockedExchange(&s_options.m_initialized, 1);
  vostok::render::initialize_speedtree(v6);
  vostok::render::register_cooks();
  singletons_on_preinitialize::singletons_on_preinitialize(
    (singletons_on_preinitialize *)&s_singletons_on_preinitialize,
    is_editor);
  _InterlockedExchange(&s_singletons_on_preinitialize.m_initialized, 1);
}
