void __thiscall survarium::bullet_manager::update_tracer_impl(
        survarium::bullet_manager *this,
        unsigned __int16 tracer_idx,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        float length)
{
  ((void (__thiscall *)(survarium::bullet_manager_engine *, _DWORD, const vostok::math::float3 *, const vostok::math::float3 *, _DWORD))this->m_engine->update_tracer)(
    this->m_engine,
    tracer_idx,
    position,
    direction,
    LODWORD(length));
}
