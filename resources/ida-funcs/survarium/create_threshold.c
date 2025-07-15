vostok::particle::particle_system_instance_impl *__cdecl survarium::create_threshold(
        vostok::memory::stack_allocator *allocator,
        const vostok::configs::binary_config_value *threshold_value,
        vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *const emitters)
{
  __int64 pointer; // rax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // edi
  vostok::memory::stack_allocator *v5; // esi
  char *m_arena_current_position; // ebx
  const vostok::configs::binary_config_value *v7; // eax
  float v8; // xmm0_4
  __int64 v9; // rax
  int v10; // eax
  int *v11; // ebx
  int v12; // edi
  _DWORD *v13; // eax
  _DWORD v15[6]; // [esp+10h] [ebp-3Ch] BYREF
  int v16; // [esp+2Ch] [ebp-20h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v17; // [esp+34h] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v18; // [esp+3Ch] [ebp-10h] BYREF
  int v19; // [esp+44h] [ebp-8h]
  int v20; // [esp+54h] [ebp+8h]

  v19 = 0;
  qmemcpy(v15, vostok::configs::binary_config_value::operator[](threshold_value, "affects"), sizeof(v15));
  v16 = 24 * HIWORD(v15[5]) / 24;
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)0x18,
         (int)threshold_value,
         (unsigned int)"effect") )
  {
    pointer = (int)vostok::configs::binary_config_value::operator[](threshold_value, "effect")->data.pointer;
    v17.m_object = (vostok::particle::particle_system_instance_impl *)HIDWORD(pointer);
    v4 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&emitters[pointer];
  }
  else
  {
    v18.m_object = 0;
    v19 = 1;
    v4 = &v18;
  }
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v17,
    v4);
  if ( (v19 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
  type_info::raw_name(&survarium::affects_threshold `RTTI Type Descriptor');
  v5 = allocator;
  m_arena_current_position = (char *)allocator->m_arena_current_position;
  allocator->m_arena_current_position = m_arena_current_position + 20;
  if ( m_arena_current_position )
  {
    v7 = vostok::configs::binary_config_value::operator[](threshold_value, "value");
    if ( v7->type == 2 )
    {
      v8 = *(float *)&v7->data.pointer;
    }
    else
    {
      v9 = (int)v7->data.pointer;
      v18.m_object = (vostok::particle::particle_system_instance_impl *)HIDWORD(v9);
      v8 = (float)(int)v9;
    }
    v10 = v16;
    *(_DWORD *)m_arena_current_position = 0;
    *((float *)m_arena_current_position + 1) = v8;
    *((_DWORD *)m_arena_current_position + 2) = v10;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)m_arena_current_position
    + 3,
      &v17);
    *((_DWORD *)m_arena_current_position + 4) = 0;
    v5 = allocator;
    v18.m_object = (vostok::particle::particle_system_instance_impl *)m_arena_current_position;
  }
  else
  {
    v18.m_object = 0;
  }
  v11 = (int *)v15[0];
  v12 = v15[0] + 24 * HIWORD(v15[5]);
  while ( v11 != (int *)v12 )
  {
    v20 = *v11;
    type_info::raw_name(&enum survarium::hit_affects_type_enum `RTTI Type Descriptor');
    v13 = v5->m_arena_current_position;
    v5->m_arena_current_position = v13 + 1;
    if ( v13 )
      *v13 = v20;
    v11 += 6;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v17);
  return v18.m_object;
}
