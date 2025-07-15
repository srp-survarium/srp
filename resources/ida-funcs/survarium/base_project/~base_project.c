void __thiscall survarium::base_project::~base_project(survarium::base_project *this)
{
  bool v2; // zf
  survarium::static_collision *m_static_collision_objects; // eax
  char *p_shape; // esi
  vostok::physics::bt_static_rigid_body *physics_rigid_body; // ecx
  survarium::static_collision *v6; // edi
  const char *v7; // [esp+0h] [ebp-18h]
  const char *v8; // [esp+4h] [ebp-14h]
  unsigned int v9; // [esp+8h] [ebp-10h]
  vostok::memory::doug_lea_allocator *v10; // [esp+Ch] [ebp-Ch]
  vostok::physics::bt_static_rigid_body *v11; // [esp+10h] [ebp-8h]
  survarium::static_collision *v12; // [esp+14h] [ebp-4h]

  v2 = this->m_static_collision_objects == 0;
  this->__vftable = (survarium::base_project_vtbl *)&survarium::base_project::`vftable';
  if ( !v2 )
  {
    v10 = survarium::g_allocator;
    m_static_collision_objects = this->m_static_collision_objects;
    if ( m_static_collision_objects )
    {
      p_shape = (char *)&m_static_collision_objects[-1].shape_;
      physics_rigid_body = m_static_collision_objects[-1].physics_rigid_body_;
      v11 = physics_rigid_body;
      v6 = (survarium::static_collision *)((char *)m_static_collision_objects
                                         + (_DWORD)physics_rigid_body
                                         * (int)m_static_collision_objects[-1].shape_.m_object);
      while ( 1 )
      {
        v12 = m_static_collision_objects;
        if ( m_static_collision_objects == v6 )
          break;
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_static_collision_objects->shape_);
        m_static_collision_objects = (survarium::static_collision *)((char *)v12 + (_DWORD)v11);
      }
      vostok::memory::doug_lea_allocator::free_impl(
        (vostok::memory::doug_lea_allocator *)physics_rigid_body,
        (int)v10,
        p_shape,
        v7,
        v8,
        v9);
    }
  }
  if ( this->m_objects_to_resolve._M_impl._M_start )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)this->m_objects_to_resolve._M_impl._M_start,
      v7,
      v8,
      v9);
  if ( this->m_objects_registry._M_t._M_node_count )
  {
    stlp_std::priv::_Rb_tree<vostok::fixed_string<260>,stlp_std::less<vostok::fixed_string<260>>,stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *>>>::_M_erase(
      &this->m_objects_registry._M_t,
      this->m_objects_registry._M_t._M_header._M_data._M_parent);
    this->m_objects_registry._M_t._M_header._M_data._M_parent = 0;
    this->m_objects_registry._M_t._M_node_count = 0;
    this->m_objects_registry._M_t._M_header._M_data._M_left = &this->m_objects_registry._M_t._M_header._M_data;
    this->m_objects_registry._M_t._M_header._M_data._M_right = &this->m_objects_registry._M_t._M_header._M_data;
  }
}
