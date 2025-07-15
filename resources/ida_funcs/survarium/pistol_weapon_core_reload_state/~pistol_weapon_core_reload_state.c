void __thiscall survarium::pistol_weapon_core_reload_state::~pistol_weapon_core_reload_state(
        survarium::double_barreled_weapon_core_reload_state *this,
        survarium::double_barreled_weapon_core_reload_state *thisa)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v2; // esi
  int i; // edi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v4; // esi
  int j; // edi

  v2 = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&thisa[1];
  for ( i = 7; i >= 0; --i )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(--v2);
  v4 = &thisa->m_user_animations[0][0][0];
  for ( j = 7; j >= 0; --j )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(--v4);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&thisa->m_animation_to_wait_for);
  vostok::resources::unmanaged_resource::~unmanaged_resource(&thisa->vostok::resources::unmanaged_resource);
}
