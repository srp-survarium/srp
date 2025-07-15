void __userpurge vostok::render::renderer::toggle_render_stage(
        vostok::render::renderer *this@<eax>,
        vostok::render::enum_render_stage_type stage_type@<edx>,
        bool toggle)
{
  vostok::render::stage **v3; // eax

  v3 = &this->m_stages.m_begin[stage_type];
  if ( *v3 )
    (*v3)->m_enabled = toggle;
}
