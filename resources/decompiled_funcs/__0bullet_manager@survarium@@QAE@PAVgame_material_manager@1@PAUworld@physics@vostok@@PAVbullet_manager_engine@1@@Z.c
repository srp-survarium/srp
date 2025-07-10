void __thiscall survarium::bullet_manager::bullet_manager(
        survarium::bullet_manager *this,
        survarium::game_material_manager *material_manager,
        vostok::physics::world *physics_world,
        survarium::bullet_manager_engine *engine)
{
  vostok::tasks::task_type *new_task_type; // eax
  vostok::enum_flags<enum vostok::tasks::task_type_flags_enum> other_z; // [esp+8h] [ebp-3Ch] BYREF
  survarium::bullet_manager *thisa; // [esp+Ch] [ebp-38h]
  vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> > *p_m_bullets_allocator_ref; // [esp+10h] [ebp-34h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> *p_m_bullets_memory_ptr; // [esp+14h] [ebp-30h]
  vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,72> *p_m_functors; // [esp+18h] [ebp-2Ch]
  char v10; // [esp+3Fh] [ebp-5h]

  thisa = this;
  this->m_bullets.m_begin = 0;
  thisa->m_bullets.m_end = 0;
  v10 = 0;
  survarium::weapon_user_dead_state::finalize(0);
  vostok::math::float3::float3(&thisa->m_gravity, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(-9.8100004), 0.0);
  survarium::bullet_manager::bullet_functor_mt_allocator::bullet_functor_mt_allocator(
    &thisa->m_mt_stack_allocator,
    0,
    0);
  p_m_functors = &thisa->m_functors;
  thisa->m_functors.m_top.whole = 0;
  p_m_bullets_memory_ptr = &thisa->m_bullets_memory_ptr;
  thisa->m_bullets_memory_ptr.m_object = 0;
  p_m_bullets_allocator_ref = &thisa->m_bullets_allocator_ref;
  thisa->m_bullets_allocator_ref.m_variable = (vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *)&thisa->m_bullets_allocator_ref;
  p_m_bullets_allocator_ref->m_initialized = 0;
  p_m_bullets_allocator_ref->m_construction_started = 0;
  thisa->m_engine = engine;
  thisa->m_game_material_manager = material_manager;
  thisa->m_physics_world = physics_world;
  other_z.m_flags = (unsigned int)material_manager;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)1,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&other_z);
  new_task_type = vostok::tasks::create_new_task_type("bullet", other_z);
  thisa->m_task_type = new_task_type;
  thisa->m_max_bullets_count = 0;
  thisa->m_max_bullets_decals_count = 64;
  thisa->m_current_decal_id = 0;
  LODWORD(thisa->m_bullet_time_factor) = clear_value;
  thisa->m_air_resistance_epsilon = FLOAT_0_1;
  survarium::bullet_manager::initialize(thisa);
  survarium::bullet_manager::register_console_commands(thisa);
}
