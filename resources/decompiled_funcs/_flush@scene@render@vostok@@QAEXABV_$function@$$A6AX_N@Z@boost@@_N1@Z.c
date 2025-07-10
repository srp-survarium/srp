void __userpurge vostok::render::scene::flush(
        vostok::render::scene *this@<ecx>,
        int a2@<esi>,
        const boost::function<void __cdecl(bool)> *on_draw_scene,
        bool all_depth_used,
        bool all_depth_unused)
{
  const char *m_conflicted_key_name; // eax
  int v6; // ecx
  bool v7; // zf
  const char *v8; // eax
  int v9; // ecx
  vostok::render::system_renderer *v10; // ecx

  if ( all_depth_used )
  {
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v6 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
    v7 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == v6;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v6;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v7;
    boost::function1<void,bool>::operator()(&on_draw_scene->boost::function1<void,bool>, 1);
    vostok::render::scene::render_lines((vostok::render::scene *)a2, 0);
    vostok::render::scene::render_triangles((vostok::render::scene *)a2);
  }
  if ( all_depth_unused )
  {
    v8 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v9 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
    v7 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) == v9;
    *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) = v9;
    *((_BYTE *)v8 + 167) |= !v7;
    if ( s_debug_enabled_ds_clearing_value )
    {
      if ( v9 )
        (*(void (__stdcall **)(int, int, int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                             + 212))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          v9,
          3,
          1.0,
          0);
    }
    vostok::render::system_renderer::draw_render_models_selection(
      (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
      (vostok::render::vector<vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> > *)(a2 + 804));
    vostok::render::system_renderer::draw_particle_system_instance_selections(
      v10,
      (const vostok::render::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x);
    vostok::render::system_renderer::draw_speedtree_instance_selections(
      (vostok::render::system_renderer *)(a2 + 828),
      (const vostok::render::vector<vostok::resources::resource_ptr<vostok::render::speedtree_instance,vostok::resources::unmanaged_intrusive_base> > *)(a2 + 828));
    boost::function1<void,bool>::operator()(&on_draw_scene->boost::function1<void,bool>, 0);
    vostok::render::scene::render_lines((vostok::render::scene *)a2, 1);
    vostok::render::scene::render_triangles((vostok::render::scene *)a2);
  }
}
