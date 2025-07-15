void __userpurge vostok::physics::bt_character_controller::bt_character_controller(
        vostok::physics::bullet_physics_world *w@<eax>,
        vostok::physics::bt_character_controller *this,
        vostok::math::float2 *group,
        vostok::physics::character_controller_can_stand_tester *mask,
        const vostok::math::float2 *stand_dimensions,
        const vostok::math::float2 *crouch_dimensions)
{
  vostok::memory::base_allocator *v6; // esi
  char *v7; // eax
  unsigned int v8; // eax
  vostok::physics::bullet_character_controller *v9; // ecx
  vostok::physics::bullet_character_controller *v10; // eax
  vostok::memory::base_allocator *v11; // esi
  char *v12; // eax
  int v13; // eax
  vostok::physics::old_bullet_character_controller *v14; // ecx
  vostok::physics::old_bullet_character_controller *v15; // eax
  __int16 v16; // [esp+0h] [ebp-Ch]
  vostok::memory::base_allocator *v17; // [esp+4h] [ebp-8h]
  vostok::memory::base_allocator *v18; // [esp+8h] [ebp-4h]

  v6 = vostok::physics::g_allocator;
  this->m_bt_physics_world = w;
  v7 = type_info::raw_name(&vostok::physics::bullet_character_controller `RTTI Type Descriptor');
  v8 = (unsigned int)v6->call_malloc(
                       v6,
                       1264u,
                       v7,
                       "vostok::physics::bt_character_controller::bt_character_controller",
                       ".\\character_controller.cpp",
                       39u);
  if ( v8 )
    vostok::physics::bullet_character_controller::bullet_character_controller(
      v9,
      v8,
      (unsigned int)group,
      mask,
      v16,
      v17);
  else
    v10 = 0;
  v11 = vostok::physics::g_allocator;
  this->m_bt_controller = v10;
  v12 = type_info::raw_name(&vostok::physics::old_bullet_character_controller `RTTI Type Descriptor');
  v13 = (int)v11->call_malloc(
               v11,
               4976u,
               v12,
               "vostok::physics::bt_character_controller::bt_character_controller",
               ".\\character_controller.cpp",
               40u);
  if ( v13 )
    vostok::physics::old_bullet_character_controller::old_bullet_character_controller(
      v14,
      v13,
      group,
      (btPairCachingGhostObject *)mask,
      v16,
      (__int16)v17,
      v18);
  else
    v15 = 0;
  this->m_old_controller = v15;
}
