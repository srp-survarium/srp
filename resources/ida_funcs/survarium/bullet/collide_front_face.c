int __userpurge survarium::bullet::collide_front_face@<eax>(
        survarium::bullet *this@<ecx>,
        float size@<xmm0>,
        survarium::material_pair *collide_point,
        const vostok::math::float3 *bullet_direction,
        const vostok::math::float3 *triangle_normal,
        float speed,
        float collision_time,
        vostok::math::float3 *start_position,
        float *start_time,
        float *current_time,
        const vostok::physics::closest_ray_result *ray_result)
{
  survarium::game_camera *v11; // ecx
  survarium::material_pair *v12; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v13; // eax
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v14; // ecx
  survarium::material_pair *v15; // ecx
  survarium::material_pair *v16; // ecx
  const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v17; // eax
  const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v18; // eax
  vostok::math::float3 *v20; // eax
  vostok::math::float3 *v21; // eax
  vostok::math::float3 *v22; // [esp+14h] [ebp-98h]
  const vostok::variant<32> **v24; // [esp+34h] [ebp-78h]
  const vostok::variant<32> **v25; // [esp+3Ch] [ebp-70h]
  char v26; // [esp+4Ch] [ebp-60h]
  vostok::math::float3 v27; // [esp+50h] [ebp-5Ch] BYREF
  vostok::math::float3 v28; // [esp+5Ch] [ebp-50h] BYREF
  vostok::math::float3 v29; // [esp+68h] [ebp-44h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+74h] [ebp-38h] BYREF
  char v31; // [esp+9Ah] [ebp-12h]
  char v32; // [esp+9Bh] [ebp-11h]
  survarium::hit_receiver *hit_target; // [esp+9Ch] [ebp-10h]
  const survarium::material_pair *mtl_pair; // [esp+A0h] [ebp-Ch]
  vostok::physics::bt_rigid_body_base *target; // [esp+A4h] [ebp-8h]
  float new_speed; // [esp+A8h] [ebp-4h] BYREF

  v26 = 0;
  v32 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v31 = 0;
  survarium::weapon_user_dead_state::finalize(v11);
  if ( this->m_bullet_manager->m_engine )
  {
    mtl_pair = survarium::game_material_manager::get_pair(
                 this->m_bullet_manager->m_game_material_manager,
                 this->m_bullet_material->m_id,
                 this->m_collided_material->m_id);
    if ( mtl_pair )
    {
      v13 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)survarium::material_pair::decal1(v12, (int)mtl_pair);
      if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
             v14,
             v13) )
      {
        survarium::material_pair::decal1_size(collide_point);
        v17 = survarium::material_pair::decal1(v16, (int)mtl_pair);
        survarium::bullet_manager::add_decal(
          this->m_bullet_manager,
          v17,
          size,
          (const vostok::math::float3 *)collide_point,
          bullet_direction,
          triangle_normal,
          1);
      }
      if ( survarium::material_pair::has_particle(v15, mtl_pair) )
      {
        v18 = survarium::material_pair::particle((survarium::material_pair *)mtl_pair);
        survarium::bullet_manager::play_particle(
          this->m_bullet_manager,
          v18,
          (const vostok::math::float3 *)collide_point,
          bullet_direction,
          triangle_normal);
      }
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game_core:", warning) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v12);
        v26 = 1;
        v25 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
                (int)this->m_collided_material);
        v24 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this->m_bullet_material,
                (int)this->m_bullet_material);
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\bullet.cpp",
          0x276u,
          "enum survarium::collision_result __thiscall survarium::bullet::collide_front_face(const class vostok::math::fl"
          "oat3 &,const class vostok::math::float3 &,const class vostok::math::float3 &,float,float,class vostok::math::f"
          "loat3 &,float &,float &,const struct vostok::physics::closest_ray_result &)",
          "game_core:",
          warning,
          "material pair not exists [%s]-[%s]",
          (const char *)v24,
          (const char *)v25);
      }
      if ( (v26 & 1) != 0 )
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v12,
          (int *)&log_callback);
    }
  }
  target = (vostok::physics::bt_rigid_body_base *)ray_result->object;
  if ( target->user_data )
  {
    hit_target = target->user_data->cast_to_hit_receiver(target->user_data);
    if ( hit_target )
    {
      if ( hit_target != this->m_ignorable_object )
        ((void (__thiscall *)(survarium::hit_receiver *, const survarium::hit_initiator *, int, const char *, _DWORD, _DWORD, survarium::bullet *))hit_target->hit)(
          hit_target,
          this->m_initiator,
          ray_result->triangle_index,
          "injury",
          this->m_weapon_bullet_damage * this->m_damage_factor,
          this->m_weapon_bullet_pierce * this->m_pierce_factor,
          this);
    }
  }
  if ( this->m_collided_material->m_material_resistance > (float)(this->m_weapon_bullet_pierce * this->m_pierce_factor) )
    return 1;
  vostok::math::max();
  vostok::math::min();
  new_speed = 0.0 * speed;
  this->m_current_resistance = this->m_collided_material->m_material_resistance;
  v22 = vostok::math::operator*(bullet_direction, &v29, &new_speed);
  v20 = vostok::math::operator*(bullet_direction, &v28, (float *)&epsilon_3_5);
  v21 = vostok::math::operator+(v20, (const vostok::math::float3_pod *)collide_point, &v27);
  survarium::bullet::change_trajectory(this, v21, v22, collision_time);
  *start_position = this->m_start_position;
  *start_time = this->m_life_time;
  *current_time = *current_time - collision_time;
  return 2;
}
