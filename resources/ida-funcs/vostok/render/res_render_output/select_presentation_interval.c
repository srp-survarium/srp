BOOL __thiscall vostok::render::res_render_output::select_presentation_interval(
        vostok::render::res_render_output *this,
        bool force_vsync)
{
  return vostok::quasi_singleton<vostok::render::options>::pinst->current.m_vsync || force_vsync;
}
