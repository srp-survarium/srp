int __thiscall vostok::render::renderer::do_stages_profiling(vostok::render::renderer *this)
{
  int result; // eax

  result = 0;
  if ( this->m_show_render_stage_statistics || s_do_stages_profiling )
    return 1;
  return result;
}
