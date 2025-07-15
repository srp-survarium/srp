char __userpurge vostok::render::renderer::is_ready_for_render@<al>(
        vostok::render::render_output_window *current_output_window@<edi>,
        vostok::render::renderer *this,
        int scene,
        const boost::function<void __cdecl(bool)> *on_draw_scene)
{
  vostok::render::res_render_output *m_object; // ecx
  int v5; // ebx
  vostok::render::scene *v6; // ecx
  unsigned int v7; // eax

  m_object = current_output_window->m_output.m_object;
  v5 = 0;
  if ( !m_object->m_valid_previous_present )
  {
LABEL_2:
    vostok::render::res_render_output::present(m_object, v5);
    return 0;
  }
  if ( !s_enable_rendering )
  {
    vostok::render::scene::flush((vostok::render::scene *)m_object, scene, on_draw_scene, 1, 1);
    if ( !s_force_no_vsync )
      v5 = (unsigned __int8)byte_8B967B[scene];
    m_object = current_output_window->m_output.m_object;
    goto LABEL_2;
  }
  if ( vostok::render::renderer::is_effects_ready((vostok::render::renderer *)m_object, (int)this) )
  {
    v7 = 0;
    while ( 1 )
    {
      v6 = *(vostok::render::scene **)&s_system_renderer_buffer.m_family[2].orig_name.m_buffer[v7 + 4];
      if ( !v6->m_children_resources.m_thread_id )
        break;
      v7 += 4;
      if ( v7 >= 0x3C )
        return 1;
    }
  }
  vostok::render::scene::flush(v6, scene, on_draw_scene, 1, 1);
  return 0;
}
