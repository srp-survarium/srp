void __userpurge survarium::weapon_core_cook::load_weapon_parameters(
        survarium::weapon_core_cook *this@<ecx>,
        float a2@<xmm0>,
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config_ptr,
        survarium::weapon_core *object_to_cook)
{
  const vostok::variant<32> **v4; // eax
  vostok::configs::binary_config *v5; // ecx
  survarium::game_camera *v6; // ecx
  const vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  survarium::game_camera *v10; // ecx
  vostok::configs::binary_config_value *v11; // ecx
  survarium::game_camera *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  float v14; // xmm0_4
  vostok::configs::binary_config_value *v15; // ecx
  vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // eax
  vostok::configs::binary_config_value *v18; // eax
  unsigned int v19; // eax
  vostok::configs::binary_config_value *v20; // eax
  const void *v21; // eax
  vostok::configs::binary_config_value *v22; // eax
  const void *v23; // eax
  bool v24; // [esp+Ah] [ebp-C2h]
  bool v25; // [esp+Bh] [ebp-C1h]
  vostok::memory::doug_lea_allocator *allocator; // [esp+34h] [ebp-98h]
  survarium::weapon_dispersion_params v27; // [esp+44h] [ebp-88h] BYREF
  survarium::weapon_recoil_params v28; // [esp+64h] [ebp-68h] BYREF
  char v29; // [esp+9Bh] [ebp-31h]
  const vostok::configs::binary_config_value *it_e; // [esp+9Ch] [ebp-30h]
  const vostok::configs::binary_config_value *it; // [esp+A0h] [ebp-2Ch]
  const vostok::configs::binary_config_value *weapon_fire_queue_types_cfg; // [esp+A4h] [ebp-28h]
  unsigned __int16 magazine_capacity; // [esp+A8h] [ebp-24h]
  float aim_near_plane_factor; // [esp+ACh] [ebp-20h]
  const vostok::configs::binary_config_value *parameters; // [esp+B0h] [ebp-1Ch]
  float aim_fov_factor; // [esp+B4h] [ebp-18h]
  float bullet_pierce; // [esp+B8h] [ebp-14h]
  const vostok::configs::binary_config_value *cfg_root; // [esp+BCh] [ebp-10h]
  unsigned __int8 queue_types_count; // [esp+C3h] [ebp-9h]
  unsigned __int8 *weapon_fire_queue_types; // [esp+C4h] [ebp-8h]
  float bullet_damage; // [esp+C8h] [ebp-4h]

  v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
         (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
         (int)&config_ptr);
  cfg_root = vostok::configs::binary_config::get_root(v5, (int)v4);
  v29 = 0;
  survarium::weapon_user_dead_state::finalize(v6);
  parameters = vostok::configs::binary_config_value::operator[](
                 (vostok::configs::binary_config_value *)cfg_root,
                 "parameters");
  v7 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)parameters,
         "magazine_capacity");
  magazine_capacity = vostok::configs::binary_config_value::operator unsigned short(v8, (int)v7);
  survarium::weapon_core::set_magazine_capacity(object_to_cook, magazine_capacity);
  vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)parameters, "bullet_damage");
  vostok::configs::binary_config_value::operator float(v9);
  bullet_damage = a2;
  survarium::weapon_user_dead_state::finalize(v10);
  object_to_cook->m_bullet_damage = a2;
  vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)parameters, "bullet_pierce");
  vostok::configs::binary_config_value::operator float(v11);
  bullet_pierce = a2;
  survarium::weapon_user_dead_state::finalize(v12);
  object_to_cook->m_bullet_pierce = a2;
  vostok::configs::binary_config_value::operator[](
    (vostok::configs::binary_config_value *)parameters,
    "aim_zoom_factor");
  vostok::configs::binary_config_value::operator float(v13);
  aim_fov_factor = *(float *)&clear_value / a2;
  v14 = *(float *)&clear_value / a2;
  object_to_cook->m_aim_fov_factor = v14;
  vostok::configs::binary_config_value::operator[](
    (vostok::configs::binary_config_value *)parameters,
    "aim_near_plane_factor");
  vostok::configs::binary_config_value::operator float(v15);
  aim_near_plane_factor = v14;
  object_to_cook->m_aim_near_plane_factor = v14;
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)parameters,
         "double_handed") )
  {
    v16 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)parameters,
                                                    "double_handed");
    v25 = vostok::configs::binary_config_value::operator bool(v16);
  }
  else
  {
    v25 = 1;
  }
  object_to_cook->m_is_double_handed = v25;
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)parameters,
         "chamber_a_round_on_reload") )
  {
    v17 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                    (vostok::configs::binary_config_value *)parameters,
                                                    "chamber_a_round_on_reload");
    v24 = vostok::configs::binary_config_value::operator bool(v17);
  }
  else
  {
    v24 = 0;
  }
  object_to_cook->m_chamber_a_round_on_reload = v24;
  v18 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  (vostok::configs::binary_config_value *)cfg_root,
                                                  "parameters");
  weapon_fire_queue_types_cfg = vostok::configs::binary_config_value::operator[](v18, "fire_queue_types");
  allocator = (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_;
  v19 = vostok::configs::binary_config_value::size((vostok::configs::binary_config_value *)weapon_fire_queue_types_cfg);
  weapon_fire_queue_types = vostok::memory::new_array_helper<unsigned char>::call<vostok::memory::doug_lea_allocator>(
                              allocator,
                              v19);
  queue_types_count = 0;
  it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)weapon_fire_queue_types_cfg);
  it_e = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)weapon_fire_queue_types_cfg);
  while ( it != it_e )
    weapon_fire_queue_types[queue_types_count++] = vostok::configs::binary_config_value::cast_number<signed char,__int64,int>((vostok::configs::binary_config_value *)it++);
  object_to_cook->m_weapon_fire_queue_types = weapon_fire_queue_types;
  object_to_cook->m_weapon_fire_queue_types_count = queue_types_count;
  v20 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  (vostok::configs::binary_config_value *)cfg_root,
                                                  "recoil");
  survarium::weapon_recoil_params::weapon_recoil_params(&v28, v20);
  qmemcpy(&object_to_cook->m_recoil_params, v21, sizeof(object_to_cook->m_recoil_params));
  v22 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  (vostok::configs::binary_config_value *)cfg_root,
                                                  "dispersion");
  survarium::weapon_dispersion_params::weapon_dispersion_params(&v27, v22);
  qmemcpy(&object_to_cook->m_dispersion_params, v23, sizeof(object_to_cook->m_dispersion_params));
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config_ptr);
}
