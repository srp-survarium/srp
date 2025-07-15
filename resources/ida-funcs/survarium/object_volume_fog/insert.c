void __usercall survarium::object_volume_fog::insert(
        survarium::object_volume_fog *this@<ecx>,
        int a2@<ebx>,
        long double a3@<esi:edi>)
{
  float x; // xmm0_4
  double y; // xmm0_8
  double z; // xmm0_8
  vostok::math::float2 *v7; // eax
  float v8; // ecx
  float v9; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_game_scene; // eax
  vostok::render::scene_renderer *v11; // [esp-18h] [ebp-A4h]
  unsigned int m_volume_fog_id; // [esp-14h] [ebp-A0h]
  long double v13; // [esp-Ch] [ebp-98h]
  long double v14; // [esp-Ch] [ebp-98h]
  __int128 v15; // [esp-4h] [ebp-90h] BYREF
  vostok::math::float2 v16; // [esp+Ch] [ebp-80h] BYREF
  vostok::render::volume_fog_parameters v17; // [esp+14h] [ebp-78h] BYREF

  LODWORD(v15) = a2;
  x = this->m_color.x;
  qmemcpy(&v17, &this->m_transform, 0x40u);
  __libm_sse2_pow(a3, *(long double *)&v15);
  *((float *)&v15 + 1) = x;
  y = this->m_color.y;
  __libm_sse2_pow(v13, *(long double *)&v15);
  *(float *)&y = y;
  DWORD2(v15) = LODWORD(y);
  z = this->m_color.z;
  __libm_sse2_pow(v14, *(long double *)&v15);
  *(float *)&z = z;
  HIDWORD(v15) = LODWORD(z);
  *(float *)&z = this->m_density;
  v17.fog_color = *(vostok::math::float3 *)((char *)&v15 + 4);
  v17.density = *(float *)&z;
  v17.speed = this->m_speed;
  v16 = 0;
  v7 = vostok::math::normalize_safe(&this->m_direction, &v16, (vostok::math::float2 *)((char *)&v15 + 4));
  v8 = v7->x;
  v9 = v7->y;
  v17.noise_scale = this->m_noise_scale;
  *(float *)&z = this->m_wave_length;
  v17.direction.y = v9;
  m_game_scene = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_game_scene;
  v17.wave_length = *(float *)&z;
  *(float *)&z = this->m_near_density;
  v17.direction.x = v8;
  v17.near_density = *(float *)&z;
  m_volume_fog_id = this->m_volume_fog_id;
  v11 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + m_game_scene[40].m_object->m_fat_it.m_type);
  v17.transparency_multiplier = this->m_transparency_multiplier;
  v17.density_offset = this->m_density_offset;
  v17.height_falloff_offset = this->m_height_falloff_offset;
  vostok::render::scene_renderer::update_volume_fog(m_game_scene + 1, v11, m_volume_fog_id, &v17);
}
