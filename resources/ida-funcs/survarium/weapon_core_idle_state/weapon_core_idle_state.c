void __thiscall survarium::weapon_core_idle_state::weapon_core_idle_state(
        survarium::weapon_core_idle_state *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *weapon,
        survarium::weapon_core *animations,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animations_count)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v4; // esi
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v5; // edi
  int v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v9; // [esp+18h] [ebp-4h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v10; // [esp+24h] [ebp+8h]
  survarium::weapon_core *weapona; // [esp+28h] [ebp+Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *object; // [esp+2Ch] [ebp+10h]

  survarium::weapon_core_idle_state_base::weapon_core_idle_state_base(this, weapon, animations);
  weapon->m_object = (vostok::resources::managed_resource *)&survarium::weapon_core_idle_state::`vftable'{for `vostok::ai::fsm_state'};
  weapon[6].m_object = (vostok::resources::managed_resource *)&survarium::weapon_core_idle_state::`vftable'{for `vostok::resources::unmanaged_resource'};
  memset(&weapon[76], 0, 0x20u);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    weapon + 84,
    animations_count);
  v4 = animations_count + 1;
  v9 = weapon + 76;
  v6 = 2;
  do
  {
    object = v4;
    weapona = (survarium::weapon_core *)v9;
    v7 = 2;
    v4 += 4;
    do
    {
      v5 = object;
      object += 2;
      v10 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)weapona;
      v8 = 2;
      do
      {
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
          v5,
          v10);
        v10 += 4;
        ++v5;
        --v8;
      }
      while ( v8 );
      weapona = (survarium::weapon_core *)((char *)weapona + 8);
      --v7;
    }
    while ( v7 );
    ++v9;
    --v6;
  }
  while ( v6 );
}
