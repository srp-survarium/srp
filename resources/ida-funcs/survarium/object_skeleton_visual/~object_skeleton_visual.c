void __usercall survarium::object_skeleton_visual::~object_skeleton_visual(
        survarium::object_skeleton_visual *this@<ecx>,
        const char *a2@<esi>)
{
  vostok::math::float4x4 **p_m_animation_bone_matrices; // edi
  char *m_animation_bone_matrices; // eax
  const char *v5; // [esp+0h] [ebp-8h]
  unsigned int v6; // [esp+4h] [ebp-4h]

  p_m_animation_bone_matrices = &this->m_animation_bone_matrices;
  this->__vftable = (survarium::object_skeleton_visual_vtbl *)&survarium::object_skeleton_visual::`vftable';
  m_animation_bone_matrices = (char *)this->m_animation_bone_matrices;
  if ( m_animation_bone_matrices )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      m_animation_bone_matrices,
      a2,
      v5,
      v6);
    *p_m_animation_bone_matrices = 0;
  }
  vostok::animation::animation_player::~animation_player(
    (vostok::animation::animation_player *)this,
    (BOOL)&this->m_animation_player);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_animation_scene);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_fingers_corrector.m_item_model);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
