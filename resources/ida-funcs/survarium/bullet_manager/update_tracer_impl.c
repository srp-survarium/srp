void __thiscall survarium::bullet_manager::update_tracer_impl(
        survarium::bullet_manager *this,
        survarium::bullet *bullet,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        const float length)
{
  ((void (__stdcall *)(survarium::bullet *, const vostok::math::float3 *, const vostok::math::float3 *, _DWORD))this->m_engine->update_tracer)(
    bullet,
    position,
    direction,
    LODWORD(length));
}
