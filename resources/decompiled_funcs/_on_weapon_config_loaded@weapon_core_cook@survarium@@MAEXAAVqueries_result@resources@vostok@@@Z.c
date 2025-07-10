void __userpurge survarium::weapon_core_cook::on_weapon_config_loaded(
        survarium::weapon_core_cook *this@<ecx>,
        float a2@<xmm0>,
        vostok::resources::queries_result *data)
{
  survarium::game_camera *v3; // ecx
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // eax
  vostok::resources::query_result_for_user *v5; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // eax
  survarium::game_camera *v7; // ecx
  vostok::memory::doug_lea_allocator *v8; // eax
  vostok::configs::binary_config *v9; // ecx
  survarium::weapon_core *v10; // eax
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v11; // [esp-8h] [ebp-44h] BYREF
  survarium::weapon_core *v12; // [esp-4h] [ebp-40h]
  survarium::weapon_core *v13; // [esp+4h] [ebp-38h]
  survarium::weapon_core_cook *thisa; // [esp+8h] [ebp-34h]
  void *_Where; // [esp+10h] [ebp-2Ch]
  vostok::memory::doug_lea_allocator *v16; // [esp+14h] [ebp-28h]
  survarium::weapon_core *v17; // [esp+24h] [ebp-18h]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v18; // [esp+28h] [ebp-14h] BYREF
  char v19; // [esp+2Fh] [ebp-Dh]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config_ptr; // [esp+30h] [ebp-Ch] BYREF
  survarium::weapon_core *object_to_cook; // [esp+34h] [ebp-8h]
  vostok::resources::query_result_for_cook *parent; // [esp+38h] [ebp-4h]

  thisa = this;
  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)data);
  v19 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  v4 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, 0);
  unmanaged_resource = vostok::resources::query_result_for_user::get_unmanaged_resource(
                         v5,
                         v4,
                         (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v18);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)unmanaged_resource,
    &config_ptr);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
  survarium::weapon_user_dead_state::finalize(v7);
  v16 = v8;
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v8, 0x498u);
  v17 = (survarium::weapon_core *)operator new(0x498u, _Where);
  if ( v17 )
  {
    survarium::weapon_core::weapon_core(v17);
    v13 = v10;
  }
  else
  {
    v13 = 0;
  }
  object_to_cook = v13;
  v12 = v13;
  v11.m_object = v9;
  boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
    &v11,
    &config_ptr);
  survarium::weapon_core_cook::process_loading_weapon_core(thisa, a2, (btTriangleShape *)parent, v11, v12);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config_ptr);
}
