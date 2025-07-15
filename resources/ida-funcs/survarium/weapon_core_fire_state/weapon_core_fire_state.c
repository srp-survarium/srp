void __userpurge survarium::weapon_core_fire_state::weapon_core_fire_state(
        survarium::weapon_core_fire_state *this@<ecx>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *a2@<eax>,
        survarium::weapon_core *weapon,
        float animation_timescale,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animations,
        const unsigned int animations_count)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v7; // ebx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v8; // eax
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v9; // edi
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v10; // ebx
  int v11; // [esp+14h] [ebp-10h]
  int v12; // [esp+18h] [ebp-Ch]
  int v13; // [esp+1Ch] [ebp-8h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v14; // [esp+20h] [ebp-4h]
  survarium::weapon_core *weapona; // [esp+2Ch] [ebp+8h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v16; // [esp+30h] [ebp+Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *object; // [esp+34h] [ebp+10h]

  v7 = a2 + 81;
  survarium::weapon_core_fire_state_base::weapon_core_fire_state_base(
    this,
    (int)a2,
    weapon,
    animation_timescale,
    a2 + 81);
  a2->m_object = (vostok::resources::managed_resource *)&survarium::weapon_core_fire_state::`vftable'{for `vostok::ai::fsm_state'};
  a2[6].m_object = (vostok::resources::managed_resource *)&survarium::weapon_core_fire_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  memset(v7, 0, 0x20u);
  a2[89].m_object = 0;
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    animations,
    a2 + 89);
  object = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&animations[1];
  v14 = v7;
  v11 = 2;
  do
  {
    v8 = object;
    object += 4;
    v16 = v8;
    weapona = (survarium::weapon_core *)v14;
    v12 = 2;
    do
    {
      v9 = v16;
      v10 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)weapona;
      v16 += 2;
      v13 = 2;
      do
      {
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
          v9++,
          v10);
        v10 += 4;
        --v13;
      }
      while ( v13 );
      weapona = (survarium::weapon_core *)((char *)weapona + 8);
      --v12;
    }
    while ( v12 );
    ++v14;
    --v11;
  }
  while ( v11 );
}
