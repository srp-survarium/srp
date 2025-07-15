void __usercall vostok::physics::bullet_character_controller::~bullet_character_controller(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<edi>)
{
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type> > > *v2; // ecx
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type> > > *v3; // ecx
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type> > > *v4; // ecx
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type> > > *v5; // ecx
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type> > > *v6; // ecx
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_move_step_tester::key_type,vostok::physics::character_controller_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_move_step_tester::key_type,vostok::physics::character_controller_move_step_tester::value_type> > > *v7; // ecx
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_move_step_tester::key_type,vostok::physics::character_controller_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_move_step_tester::key_type,vostok::physics::character_controller_move_step_tester::value_type> > > *v8; // ecx
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_step_down_tester::key_type,vostok::physics::character_controller_step_down_tester::value_type> > > *v9; // ecx
  vostok::physics::loose_ptr_base *v10; // ecx

  *(_DWORD *)a2 = &vostok::physics::bullet_character_controller::`vftable'{for `btActionInterface'};
  *(_DWORD *)(a2 + 4) = &vostok::physics::bullet_character_controller::`vftable'{for `vostok::physics::base_physics_object'};
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)(a2 + 1192));
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>>>::~circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>>>(
    v2,
    a2 + 1088);
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>>>::~circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>>>(
    v3,
    a2 + 1024);
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>>>::~circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>>>(
    v4,
    a2 + 976);
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>>>::~circular_buffer<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>>>(
    v5,
    a2 + 912);
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>>>::~circular_buffer<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_straighten_tester::key_type,vostok::physics::character_controller_straighten_tester::value_type>>>(
    v6,
    a2 + 848);
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>>>::~circular_buffer<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>>>(
    v7,
    a2 + 784);
  *(_DWORD *)(a2 + 688) = &btCollisionShape::`vftable';
  *(_DWORD *)(a2 + 608) = &btCollisionShape::`vftable';
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>>>::~circular_buffer<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_capsule_move_step_tester::key_type,vostok::physics::character_controller_capsule_move_step_tester::value_type>>>(
    v8,
    a2 + 576);
  boost::circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>>>::~circular_buffer<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>,stlp_std::allocator<stlp_std::pair<vostok::physics::character_controller_jump_tester::key_type,vostok::physics::character_controller_jump_tester::value_type>>>(
    v9,
    a2 + 512);
  *(_DWORD *)(a2 + 416) = &btCollisionShape::`vftable';
  btPairCachingGhostObject::~btPairCachingGhostObject((btPairCachingGhostObject *)(a2 + 96));
  vostok::physics::loose_ptr_base::~loose_ptr_base(v10, (_DWORD **)(a2 + 8));
  *(_DWORD *)a2 = &btActionInterface::`vftable';
}
