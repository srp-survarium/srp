void __thiscall vostok::render::render_model_instance_impl::set_transform(
        vostok::render::render_model_instance_impl *this,
        const vostok::math::float4x4 *transform)
{
  qmemcpy((void *)&this->m_transform, transform, sizeof(this->m_transform));
}
