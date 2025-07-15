vostok::physics::old_bullet_character_controller *__thiscall vostok::physics::old_bullet_character_controller::`scalar deleting destructor'(
        vostok::physics::old_bullet_character_controller *this,
        char a2)
{
  vostok::physics::old_bullet_character_controller::sweep_test_cache_item **m_begin; // ecx
  vostok::physics::loose_ptr_base *v4; // ecx

  this->btActionInterface::__vftable = (vostok::physics::old_bullet_character_controller_vtbl *)&vostok::physics::old_bullet_character_controller::`vftable'{for `btActionInterface'};
  this->vostok::physics::base_physics_object::__vftable = (vostok::physics::base_physics_object_vtbl *)&vostok::physics::old_bullet_character_controller::`vftable'{for `vostok::physics::base_physics_object'};
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>>>::~circular_buffer<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>>>(
    (boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type> > > *)this,
    (int)&this->m_can_stand_tester);
  m_begin = this->m_convex_test_cache.m_begin;
  this->m_convex_test_cache.m_end = m_begin;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_begin,
    (int *)&this->m_landing_callback);
  this->m_shape.__vftable = (btCapsuleShape_vtbl *)&btCollisionShape::`vftable';
  btPairCachingGhostObject::~btPairCachingGhostObject(&this->m_ghost_object);
  vostok::physics::loose_ptr_base::~loose_ptr_base(v4, &this->vostok::physics::loose_ptr_base_a);
  this->btActionInterface::__vftable = (vostok::physics::old_bullet_character_controller_vtbl *)&btActionInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
