void __thiscall vostok::sound::sound_environment::sound_environment(
        vostok::sound::sound_environment *this,
        unsigned int env_params_id)
{
  unsigned __int8 dst[64]; // [esp+Ch] [ebp-90h] BYREF
  vostok::math::float4x4 matrix; // [esp+4Ch] [ebp-50h] BYREF
  float v5; // [esp+8Ch] [ebp-10h]
  float v6; // [esp+90h] [ebp-Ch]
  float v7; // [esp+94h] [ebp-8h]
  vostok::collision::geometry_instance *instance; // [esp+98h] [ebp-4h]

  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  this->__vftable = (vostok::sound::sound_environment_vtbl *)&vostok::sound::sound_environment::`vftable';
  this->m_env_params_id = env_params_id;
  v5 = FLOAT_1_0;
  v6 = FLOAT_1_0;
  v7 = FLOAT_1_0;
  memset(dst, 0, sizeof(dst));
  *(float *)dst = FLOAT_1_0;
  *(float *)&dst[20] = FLOAT_1_0;
  *(float *)&dst[40] = FLOAT_1_0;
  *(float *)&dst[60] = FLOAT_1_0;
  qmemcpy((void *)&matrix, dst, sizeof(matrix));
  instance = vostok::collision::new_box_geometry_instance(
               (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
               &matrix);
  this->m_collision = vostok::collision::new_collision_object(
                        (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
                        1u,
                        instance,
                        this);
}
