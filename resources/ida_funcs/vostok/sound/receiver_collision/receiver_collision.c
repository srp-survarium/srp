void __thiscall vostok::sound::receiver_collision::receiver_collision(
        vostok::sound::receiver_collision *this,
        vostok::sound::sound_receiver *receiver,
        vostok::sound::atomic_half3 *pos)
{
  vostok::math::float3 result; // [esp+2Ch] [ebp-1Ch] BYREF
  vostok::math::float3 epsilon; // [esp+38h] [ebp-10h] BYREF
  float r; // [esp+44h] [ebp-4h]

  this->m_position = pos;
  this->m_receiver = receiver;
  this->m_next = 0;
  r = FLOAT_0_30000001;
  vostok::math::half3_pod::operator vostok::math::float3(&this->m_position->m_data.m_val, &result);
  epsilon.x = r;
  epsilon.y = r;
  epsilon.z = r;
  this->m_collision = vostok::collision::new_aabb_object(
                        (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
                        1u,
                        &result,
                        &epsilon,
                        this);
}
