void __userpurge survarium::bullet_manager::bullet_manager(
        survarium::bullet_manager *this@<ecx>,
        int a2@<eax>,
        unsigned int a3@<edi>,
        survarium::game_material_manager *material_manager,
        vostok::physics::world *physics_world,
        survarium::bullet_manager_engine *engine)
{
  vostok::tasks::task_type *new_task_type; // eax
  float v8; // xmm0_4
  const char *v9; // eax
  unsigned __int8 *unmanaged_memory; // eax
  survarium::bullet_manager *v11; // [esp-Ch] [ebp-Ch]

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(float *)(a2 + 24) = FLOAT_N9_8100004;
  *(_DWORD *)(a2 + 28) = 0;
  survarium::bullet_manager::bullet_functor_mt_allocator::bullet_functor_mt_allocator(
    0,
    0,
    (survarium::bullet_manager::bullet_functor_mt_allocator *)(a2 + 32));
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 120) = a2 + 64;
  *(_DWORD *)(a2 + 124) = 0;
  *(_DWORD *)(a2 + 128) = 0;
  *(_DWORD *)(a2 + 136) = engine;
  *(_DWORD *)(a2 + 140) = material_manager;
  *(_DWORD *)(a2 + 144) = physics_world;
  new_task_type = vostok::tasks::create_new_task_type(
                    "bullet",
                    (vostok::enum_flags<enum vostok::tasks::task_type_flags_enum>)1);
  v8 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 172) = -1;
  *(float *)(a2 + 164) = v8;
  *(_DWORD *)(a2 + 148) = new_task_type;
  *(_DWORD *)(a2 + 156) = 64;
  *(_DWORD *)(a2 + 160) = 0;
  *(float *)(a2 + 168) = FLOAT_0_1;
  *(_DWORD *)(a2 + 152) = 192;
  v9 = type_info::name(&unsigned char `RTTI Type Descriptor', &__type_info_root_node);
  unmanaged_memory = (unsigned __int8 *)vostok::resources::allocate_unmanaged_memory(0x21C00u, v9);
  survarium::bullet_manager::construct_bullets_memory_allocator(v11, a2, unmanaged_memory, a3);
}
