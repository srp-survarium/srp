void __userpurge vostok::render::stage::stage(
        vostok::render::stage *this@<eax>,
        vostok::render::renderer_context *in_context@<ecx>,
        vostok::render::renderer *in_renderer)
{
  this->m_context = in_context;
  this->__vftable = (vostok::render::stage_vtbl *)&vostok::render::stage::`vftable';
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
}
