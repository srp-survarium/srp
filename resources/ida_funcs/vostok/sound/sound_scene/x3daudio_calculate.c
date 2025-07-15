void __thiscall vostok::sound::sound_scene::x3daudio_calculate(
        vostok::sound::sound_scene *this,
        const vostok::sound::sound_world *__formal,
        vostok::sound::sound_voice *a3)
{
  vostok::math::float3 v4; // [esp+64h] [ebp-58h] BYREF
  vostok::math::float3 vec; // [esp+70h] [ebp-4Ch] BYREF
  vostok::math::float3 result; // [esp+7Ch] [ebp-40h] BYREF
  X3DAUDIO_LISTENER listener; // [esp+88h] [ebp-34h] BYREF

  vostok::sound::fill_x3daudio_vector(&listener.Velocity, 0.0, 0.0, 0.0);
  vostok::math::half3_pod::operator vostok::math::float3(&this->m_list_position.m_data.m_val, &result);
  vostok::sound::fill_x3daudio_vector_0(&listener.Position, &result);
  vostok::math::half3_pod::operator vostok::math::float3(&this->m_list_orient_front.m_data.m_val, &vec);
  vostok::sound::fill_x3daudio_vector_0(&listener.OrientFront, &vec);
  vostok::math::half3_pod::operator vostok::math::float3(&this->m_list_orient_top.m_data.m_val, &v4);
  vostok::sound::fill_x3daudio_vector_0(&listener.OrientTop, &v4);
}
