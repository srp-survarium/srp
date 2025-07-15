void __thiscall survarium::player::~player(survarium::player *this)
{
  survarium::player *v1; // ebx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_special_effect_material; // eax
  vostok::render::scene_renderer *v3; // ecx
  survarium::damage_sound_effect *v4; // ecx
  survarium::player_equipment_sound_properties *v5; // ecx
  survarium::stamina_sound_effect *v6; // ecx
  const char *v7; // [esp+0h] [ebp-10h]
  const char *v8; // [esp+4h] [ebp-Ch]
  unsigned int v9; // [esp+8h] [ebp-8h]

  v1 = this;
  p_m_special_effect_material = &this->m_special_effect_material;
  this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::player_vtbl *)&survarium::player::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->survarium::base_player::survarium::inventory_holder::__vftable = (survarium::inventory_holder_vtbl *)&survarium::player::`vftable'{for `survarium::inventory_holder'};
  this->survarium::base_player::survarium::collision_user::__vftable = (survarium::collision_user_vtbl *)&survarium::player::`vftable'{for `survarium::collision_user'};
  this->survarium::base_player::survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::player::`vftable'{for `survarium::hit_initiator'};
  this->survarium::base_player::survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::hit_receiver_vtbl *)&survarium::player::`vftable'{for `survarium::hit_receiver'};
  this->survarium::base_player::survarium::spottable_object::__vftable = (survarium::spottable_object_vtbl *)&survarium::player::`vftable'{for `survarium::spottable_object'};
  if ( this->m_special_effect_material.m_object )
  {
    this = (survarium::player *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::scene_renderer::remove_model_material(
        (vostok::render::scene_renderer *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
        *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int> > > **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + (_DWORD)v1) + 160) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&(*(survarium::player_vtbl **)((char *)&v1->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable + (_DWORD)&loc_1119E + 2))[3].on_player_death,
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)p_m_special_effect_material,
        0);
      vostok::render::scene_renderer::remove_model_material(
        v3,
        *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int> > > **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + (_DWORD)v1) + 160) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&(*(survarium::player_vtbl **)((char *)&v1->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable + (_DWORD)&loc_1119E + 2))[3].on_player_death,
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v1->m_special_effect_material,
        (boost::_bi::value<vostok::render::engine::world *> *)1);
    }
  }
  if ( *(int *)((char *)&dword_11420 + (_DWORD)v1) )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      *(char **)((char *)&dword_11420 + (_DWORD)v1),
      v7,
      v8,
      v9);
    *(int *)((char *)&dword_11420 + (_DWORD)v1) = 0;
  }
  if ( *(_DWORD *)((char *)vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>
                 + (_DWORD)v1) )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      *(char **)((char *)vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>
               + (_DWORD)v1),
      v7,
      v8,
      v9);
    *(_DWORD *)((char *)vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>
              + (_DWORD)v1) = 0;
  }
  if ( *(survarium::player_vtbl **)((char *)&v1->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                  + (_DWORD)&loc_11427
                                  + 1) )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      *(char **)((char *)&v1->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
               + (_DWORD)&loc_11427
               + 1),
      v7,
      v8,
      v9);
    *(survarium::player_vtbl **)((char *)&v1->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                               + (_DWORD)&loc_11427
                               + 1) = 0;
  }
  if ( *(_DWORD *)((char *)&loc_1142C + (_DWORD)v1) )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      *(char **)((char *)&loc_1142C + (_DWORD)v1),
      v7,
      v8,
      v9);
    *(_DWORD *)((char *)&loc_1142C + (_DWORD)v1) = 0;
  }
  if ( *(survarium::player_vtbl **)((char *)&v1->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                  + (_DWORD)&loc_1142E
                                  + 2) )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      *(char **)((char *)&v1->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
               + (_DWORD)&loc_1142E
               + 2),
      v7,
      v8,
      v9);
    *(survarium::player_vtbl **)((char *)&v1->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                               + (_DWORD)&loc_1142E
                               + 2) = 0;
  }
  vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&dword_11418 + (_DWORD)v1));
  survarium::damage_sound_effect::~damage_sound_effect(v4, (int)v1 + (_DWORD)&loc_11275 + 3);
  survarium::player_equipment_sound_properties::~player_equipment_sound_properties(v5, (int)&loc_11240 + (_DWORD)v1);
  survarium::stamina_sound_effect::~stamina_sound_effect(v6, (int)&v1->m_stamina_sound_effect);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v1->m_special_effect_material);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)v1 + (_DWORD)&loc_1119E + 2));
  survarium::base_player::~base_player(v1);
}
