void __userpurge vostok::render::render_output_window::set_size(
        unsigned int width@<eax>,
        BOOL a2@<ecx>,
        vostok::render::render_output_window *this,
        vostok::render::renderer_context_targets *height,
        bool fullscreen,
        unsigned int force_resize,
        bool modify_style)
{
  float z; // esi
  vostok::render::backend *v9; // ecx
  bool v10; // [esp+0h] [ebp-10h]

  if ( width )
  {
    if ( height )
    {
      if ( (_BYTE)force_resize
        || width != this->m_current_size.x
        || height != (vostok::render::renderer_context_targets *)this->m_current_size.y
        || (a2 = !fullscreen, this->m_windowed != a2) )
      {
        this->m_windowed = !fullscreen;
        this->m_current_size.y = (unsigned int)height;
        this->m_current_size.x = width;
        this->m_windowed_changed = 1;
        vostok::render::renderer_context_targets::resize(
          (vostok::render::renderer_context_targets *)a2,
          (vostok::render::enum_render_target_index)&this->m_targets,
          (vostok::math::uint2)__PAIR64__(width, force_resize),
          height);
        vostok::render::res_render_output::set_size(
          this->m_output.m_object,
          (unsigned int)height,
          width,
          fullscreen,
          force_resize,
          v10);
        if ( this->m_flash_renderer )
        {
          z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
          vostok::render::backend::set_render_targets(
            (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            this->m_targets.m_family[51].target.m_object,
            this->m_targets.m_family[50].target.m_object,
            0,
            0);
          vostok::render::backend::flush(v9, LODWORD(z));
          survarium::flash_renderer::on_reset_device(
            this->m_flash_renderer,
            this->m_current_size.x,
            this->m_current_size.y,
            vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
        }
      }
    }
  }
}
