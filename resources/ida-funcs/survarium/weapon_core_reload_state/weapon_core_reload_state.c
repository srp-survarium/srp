void __userpurge survarium::weapon_core_reload_state::weapon_core_reload_state(
        survarium::weapon_core_reload_state *this@<ecx>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *a2@<eax>,
        survarium::weapon_core *weapon,
        float animation_time_scale,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animations,
        const unsigned int animations_count)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v7; // ebx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v8; // ebx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v9; // edi
  int v10; // [esp+18h] [ebp-4h]
  survarium::weapon_core *weapona; // [esp+24h] [ebp+8h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v12; // [esp+28h] [ebp+Ch]
  int object; // [esp+2Ch] [ebp+10h]

  v7 = a2 + 85;
  survarium::weapon_core_reload_state_base::weapon_core_reload_state_base(
    this,
    (int)a2,
    weapon,
    animation_time_scale,
    a2 + 85);
  a2->m_object = (vostok::resources::managed_resource *)&survarium::weapon_core_reload_state::`vftable'{for `vostok::ai::fsm_state'};
  a2[6].m_object = (vostok::resources::managed_resource *)&survarium::weapon_core_reload_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  a2[81].m_object = 0;
  a2[82].m_object = 0;
  a2[83].m_object = 0;
  a2[84].m_object = 0;
  v7->m_object = 0;
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    animations,
    v7);
  v8 = animations + 1;
  weapona = (survarium::weapon_core *)&a2[81];
  v10 = 2;
  do
  {
    v9 = v8;
    v12 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)weapona;
    object = 2;
    v8 += 2;
    do
    {
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        v9,
        v12);
      v12 += 2;
      ++v9;
      --object;
    }
    while ( object );
    weapona = (survarium::weapon_core *)((char *)weapona + 4);
    --v10;
  }
  while ( v10 );
}
