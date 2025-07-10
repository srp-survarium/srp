void __thiscall vostok::sound::sound_instance_proxy_internal::set_quality_for_resource(
        vostok::sound::sound_instance_proxy_internal *this,
        const vostok::math::float3 *position)
{
  vostok::math::float4x4 result; // [esp+98h] [ebp-40h] BYREF

  qmemcpy((void *)this->matrix_storage, vostok::math::create_translation(&result, position), 0x40u);
  this->m_propagator_emitter->get_quality_for_resource(this->m_propagator_emitter);
}
