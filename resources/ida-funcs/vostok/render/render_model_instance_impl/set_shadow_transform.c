void __thiscall vostok::render::render_model_instance_impl::set_shadow_transform(
        vostok::render::render_model_instance_impl *this,
        const vostok::math::float4x4 *transform)
{
  qmemcpy(&this->m_shadow_transform, transform, sizeof(this->m_shadow_transform));
}
