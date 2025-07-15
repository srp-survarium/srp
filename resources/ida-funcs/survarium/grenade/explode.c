void __thiscall survarium::grenade::explode(
        survarium::grenade *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  survarium::base_game_scene *m_game_world; // ecx
  int v7; // eax
  survarium::game_material_manager *v8; // ecx
  const survarium::material_pair *pair; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_collision_decal; // edi
  double v11; // st7
  survarium::base_game_scene *v12; // ecx
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v19; // ecx
  float v20; // [esp+0h] [ebp-88h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v21; // [esp+4h] [ebp-84h] BYREF
  float v22; // [esp+8h] [ebp-80h]
  vostok::math::float4x4 *v23; // [esp+Ch] [ebp-7Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_material_id; // [esp+10h] [ebp-78h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *material_id; // [esp+14h] [ebp-74h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v26; // [esp+28h] [ebp-60h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v27; // [esp+2Ch] [ebp-5Ch] BYREF
  _DWORD v28[3]; // [esp+30h] [ebp-58h] BYREF
  _DWORD v29[3]; // [esp+3Ch] [ebp-4Ch] BYREF
  vostok::math::float4x4 v30; // [esp+48h] [ebp-40h] BYREF

  survarium::grenade_core::explode(this, time_delta_ms, current_time_ms);
  if ( !this->m_effects_played )
  {
    v4 = this->m_render_transform.c.y - this->m_last_contact.position.y;
    v5 = this->m_render_transform.c.z - this->m_last_contact.position.z;
    if ( fsqrt(
           (float)((float)((float)(this->m_render_transform.c.x - this->m_last_contact.position.x)
                         * (float)(this->m_render_transform.c.x - this->m_last_contact.position.x))
                 + (float)(v4 * v4))
         + (float)(v5 * v5)) < 0.5 )
    {
      m_game_world = this->m_game_world;
      material_id = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_last_contact.material_id;
      m_material_id = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_material_id;
      v7 = (int)m_game_world->get_game_material_manager(m_game_world);
      pair = survarium::game_material_manager::get_pair(
               v8,
               v7,
               (unsigned __int16)m_material_id,
               (unsigned __int16)material_id);
      if ( pair )
      {
        p_m_collision_decal = &pair->m_collision_decal;
        if ( pair->m_collision_decal.m_object )
        {
          if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          {
            v11 = survarium::material_pair::collision_decal_size(
                    (survarium::material_pair *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
                    (int)pair);
            v12 = this->m_game_world;
            x = this->m_last_contact.normal.x;
            y = this->m_last_contact.normal.y;
            z = this->m_last_contact.normal.z;
            material_id = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_last_contact.normal;
            v28[0] = 0;
            v28[1] = 0;
            m_material_id = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v28;
            *(float *)&v28[2] = s_bm_current_air_resistance;
            v23 = (vostok::math::float4x4 *)v29;
            v22 = 0.5;
            *(float *)&v21.m_object = v11;
            v20 = v11;
            v16 = this->m_last_contact.position.x + (float)(x * 0.2);
            v17 = this->m_last_contact.position.y + (float)(y * 0.2);
            v18 = this->m_last_contact.position.z + (float)(z * 0.2);
            *(float *)v29 = v16;
            *(float *)&v29[1] = v17;
            *(float *)&v29[2] = v18;
            ((void (__thiscall *)(survarium::base_game_scene *, vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *, _DWORD, _DWORD, survarium::pure_game_effect_emitter_base *, _DWORD, _DWORD *, _DWORD *, vostok::math::float3 *))v12->add_decal)(
              v12,
              p_m_collision_decal,
              0,
              LODWORD(v20),
              v21.m_object,
              0.5,
              v29,
              v28,
              &this->m_last_contact.normal);
          }
        }
      }
    }
    vostok::math::create_translation((const vostok::math::float3 *)&this->m_render_transform.lines[3], &v30);
    v27.m_object = 0;
    v26.m_object = 0;
    material_id = &v27;
    m_material_id = &v26;
    v23 = &v30;
    v22 = COERCE_FLOAT(&v30);
    v21.m_object = v19.m_object;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v21,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_particle_explosion);
    vostok::render::scene_renderer::play_particle_system(
      (vostok::render::scene_renderer *)&this->m_game_world->m_render_scene,
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene,
      (const vostok::math::float4x4 *)v21.m_object,
      (const vostok::math::float4x4 *)LODWORD(v22),
      v23,
      m_material_id,
      material_id);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v27);
    this->m_game_world->play_sound(
      this->m_game_world,
      &this->m_sound_explosion,
      (const vostok::math::float3 *)&v30.lines[3]);
    this->m_effects_played = 1;
  }
}
