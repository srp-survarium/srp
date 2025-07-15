void __userpurge vostok::render::clouds::generate_cloud_right(
        vostok::render::clouds *this@<ecx>,
        const vostok::render::cloud_key_parameters *a2@<edi>,
        unsigned int key_index)
{
  unsigned int v3; // eax
  const vostok::render::cloud_key_parameters *v4; // eax
  float z; // xmm1_4
  vostok::render::cloud_simulation *m_variable; // ecx
  vostok::math::float3 sun_direction; // [esp+4h] [ebp-Ch] BYREF

  v3 = key_index + 1 < this->m_num_keys ? key_index + 1 : 0;
  sun_direction.x = -this->m_sun_direction.x;
  v4 = &this->m_keys[v3];
  sun_direction.y = -this->m_sun_direction.y;
  z = this->m_sun_direction.z;
  m_variable = this->m_cloud_simulation_2.m_variable;
  sun_direction.z = -z;
  vostok::render::cloud_simulation::generate(m_variable, &sun_direction, a2, v4);
}
