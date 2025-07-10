void __usercall vostok::render::renderer::set_target_context(
        vostok::render::renderer *this@<ecx>,
        const vostok::render::renderer_context_targets *targets_context@<eax>)
{
  vostok::render::renderer_context::set_target_context(this->m_renderer_context, targets_context, 1);
}
