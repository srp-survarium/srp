void __usercall vostok::render::game::renderer::draw_scene_params::draw_scene_params(
        vostok::render::game::renderer::draw_scene_params *this@<eax>,
        const vostok::render::game::renderer::draw_scene_params *__that@<edx>)
{
  vostok::render::base_scene *m_object; // ecx
  vostok::render::base_scene_view *v3; // ecx
  vostok::render::base_output_window *v4; // ecx

  this->scene.m_object = 0;
  m_object = __that->scene.m_object;
  if ( __that->scene.m_object )
  {
    this->scene.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  this->scene_view.m_object = 0;
  v3 = __that->scene_view.m_object;
  if ( v3 )
  {
    this->scene_view.m_object = v3;
    _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
  this->render_output_window.m_object = 0;
  v4 = __that->render_output_window.m_object;
  if ( v4 )
  {
    this->render_output_window.m_object = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  this->viewport = __that->viewport;
  this->default_font = __that->default_font;
}
