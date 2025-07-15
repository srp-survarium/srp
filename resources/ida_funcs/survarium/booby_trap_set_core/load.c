void __userpurge survarium::booby_trap_set_core::load(
        survarium::booby_trap_set_core *this@<ecx>,
        float angle@<xmm0>,
        vostok::configs::binary_config_value *config)
{
  survarium::inventory_item *v3; // ecx
  unsigned __int16 v4; // ax
  unsigned int v5; // esi
  survarium::game_camera *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // eax
  survarium::inventory_item *v8; // ecx
  survarium::game_camera *m_traps_buffer; // ecx
  survarium::game_camera *v10; // ecx
  survarium::game_camera *v11; // ecx
  survarium::game_camera *v12; // ecx
  survarium::game_camera *v13; // ecx
  survarium::game_camera *v14; // ecx
  survarium::game_camera *v15; // ecx
  survarium::game_camera *v16; // ecx
  survarium::game_camera *v17; // ecx
  survarium::game_camera *v18; // ecx
  vostok::configs::binary_config_value *v19; // ecx
  vostok::configs::binary_config_value *v20; // ecx
  vostok::configs::binary_config_value *v21; // ecx
  float v22; // xmm0_4
  vostok::configs::binary_config_value *v23; // ecx
  float v24; // xmm0_4
  vostok::configs::binary_config_value *v25; // ecx
  float v26; // xmm0_4
  vostok::configs::binary_config_value *v27; // ecx
  float v28; // xmm0_4
  vostok::configs::binary_config_value *v29; // eax
  vostok::configs::binary_config_value *v30; // eax
  vostok::configs::binary_config_value *v31; // eax
  survarium::game_camera *v32; // ecx
  vostok::memory::doug_lea_allocator *v33; // eax
  survarium::game_camera *v34; // eax
  survarium::game_camera *v35; // ecx
  survarium::game_camera *v36; // ecx
  survarium::game_camera *v37; // ecx
  survarium::game_camera *v38; // ecx
  const vostok::configs::binary_config_value *v39; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v40; // ecx
  const vostok::configs::binary_config_value *v41; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v42; // ecx
  vostok::configs::binary_config_value *v43; // ecx
  vostok::configs::binary_config_value *v44; // ecx
  survarium::game_camera *v45; // ecx
  survarium::game_camera *v46; // ecx
  survarium::game_camera *v47; // ecx
  survarium::game_camera *v48; // ecx
  survarium::game_camera *v49; // ecx
  survarium::game_camera *v50; // ecx
  survarium::game_camera *v51; // ecx
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *v52; // [esp+10h] [ebp-124h]
  char *v54; // [esp+1Ch] [ebp-118h]
  char *source; // [esp+28h] [ebp-10Ch]
  survarium::booby_trap_set_core::apply_damage *j; // [esp+58h] [ebp-DCh]
  survarium::booby_trap_set_core::apply_damage value; // [esp+CCh] [ebp-68h] BYREF
  char v58; // [esp+F4h] [ebp-40h]
  char v59; // [esp+F5h] [ebp-3Fh]
  char v60; // [esp+F6h] [ebp-3Eh]
  char v61; // [esp+F7h] [ebp-3Dh]
  survarium::game_camera **v62; // [esp+F8h] [ebp-3Ch]
  char v63; // [esp+FEh] [ebp-36h]
  char v64; // [esp+FFh] [ebp-35h]
  char v65; // [esp+100h] [ebp-34h]
  char v66; // [esp+101h] [ebp-33h]
  char v67; // [esp+102h] [ebp-32h]
  char v68; // [esp+103h] [ebp-31h]
  char v69; // [esp+104h] [ebp-30h]
  char v70; // [esp+105h] [ebp-2Fh]
  char v71; // [esp+106h] [ebp-2Eh]
  char v72; // [esp+107h] [ebp-2Dh]
  survarium::game_camera **v73; // [esp+108h] [ebp-2Ch]
  char v74; // [esp+10Fh] [ebp-25h]
  const vostok::configs::binary_config_value *conf_entry; // [esp+110h] [ebp-24h]
  survarium::booby_trap_set_core::apply_damage *ad; // [esp+114h] [ebp-20h]
  unsigned int i; // [esp+118h] [ebp-1Ch]
  float defuse_time; // [esp+11Ch] [ebp-18h]
  const vostok::configs::binary_config_value *apply_dmg; // [esp+120h] [ebp-14h]
  float disarmed_life_time; // [esp+124h] [ebp-10h]
  float fired_life_time; // [esp+128h] [ebp-Ch]
  float armed_life_time; // [esp+12Ch] [ebp-8h]
  unsigned int count; // [esp+130h] [ebp-4h]

  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>>::clear(&this->m_traps);
  v74 = 0;
  survarium::weapon_user_dead_state::finalize(0);
  v4 = survarium::inventory_item::amount(v3, (int)this);
  if ( v4 )
  {
    v5 = 4 * survarium::inventory_item::amount((survarium::inventory_item *)v4, (int)this);
    survarium::weapon_user_dead_state::finalize(v6);
    v52 = (vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> *)vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(v7, v5);
  }
  else
  {
    v52 = 0;
  }
  this->m_traps_buffer = v52;
  v73 = (survarium::game_camera **)operator new(8u, &this->m_traps);
  if ( v73 )
  {
    survarium::inventory_item::amount(v8, (int)this);
    m_traps_buffer = (survarium::game_camera *)this->m_traps_buffer;
    *v73 = m_traps_buffer;
    v73[1] = m_traps_buffer;
    survarium::weapon_user_dead_state::finalize(m_traps_buffer);
  }
  v72 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v8);
  v71 = 0;
  survarium::weapon_user_dead_state::finalize(v10);
  v70 = 0;
  survarium::weapon_user_dead_state::finalize(v11);
  v69 = 0;
  survarium::weapon_user_dead_state::finalize(v12);
  v68 = 0;
  survarium::weapon_user_dead_state::finalize(v13);
  v67 = 0;
  survarium::weapon_user_dead_state::finalize(v14);
  v66 = 0;
  survarium::weapon_user_dead_state::finalize(v15);
  v65 = 0;
  survarium::weapon_user_dead_state::finalize(v16);
  v64 = 0;
  survarium::weapon_user_dead_state::finalize(v17);
  v63 = 0;
  survarium::weapon_user_dead_state::finalize(v18);
  vostok::configs::binary_config_value::operator[](config, "max_deploy_distance");
  vostok::configs::binary_config_value::operator float(v19);
  this->m_config.max_distance = angle;
  vostok::configs::binary_config_value::operator[](config, "max_slope_angle");
  vostok::configs::binary_config_value::operator float(v20);
  vostok::math::deg2rad();
  this->m_config.max_slope_cos = vostok::math::cos(angle);
  vostok::configs::binary_config_value::operator[](config, "armed_life_time");
  vostok::configs::binary_config_value::operator float(v21);
  armed_life_time = angle;
  v22 = angle * 1000.0;
  this->m_config.armed_life_time = vostok::math::floor(v22);
  vostok::configs::binary_config_value::operator[](config, "fired_life_time");
  vostok::configs::binary_config_value::operator float(v23);
  fired_life_time = v22;
  v24 = v22 * 1000.0;
  this->m_config.fired_life_time = vostok::math::floor(v24);
  vostok::configs::binary_config_value::operator[](config, "disarmed_life_time");
  vostok::configs::binary_config_value::operator float(v25);
  disarmed_life_time = v24;
  v26 = v24 * 1000.0;
  this->m_config.disarmed_life_time = vostok::math::floor(v26);
  vostok::configs::binary_config_value::operator[](config, "defuse_time");
  vostok::configs::binary_config_value::operator float(v27);
  defuse_time = v26;
  v28 = v26 * 1000.0;
  this->m_config.defuse_time = vostok::math::floor(v28);
  v29 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  config,
                                                  "defuse_by_hit");
  this->m_config.defuse_by_hit = vostok::configs::binary_config_value::operator bool(v29);
  v30 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  config,
                                                  "material_can_place_test");
  this->m_config.material_can_place_test = vostok::configs::binary_config_value::operator bool(v30);
  v31 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  config,
                                                  "material_can_stick_test");
  this->m_config.material_can_stick_test = vostok::configs::binary_config_value::operator bool(v31);
  apply_dmg = vostok::configs::binary_config_value::operator[](config, "damage_parameters");
  count = vostok::configs::binary_config_value::size((vostok::configs::binary_config_value *)apply_dmg);
  for ( j = this->m_damage_parameters.m_begin; j != this->m_damage_parameters.m_end; ++j )
    ;
  this->m_damage_parameters.m_end = this->m_damage_parameters.m_begin;
  v62 = (survarium::game_camera **)operator new(8u, &this->m_damage_parameters);
  if ( v62 )
  {
    survarium::weapon_user_dead_state::finalize(v32);
    v34 = (survarium::game_camera *)vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(v33, 40 * count);
    *v62 = v34;
    v62[1] = v34;
    survarium::weapon_user_dead_state::finalize(v34);
  }
  for ( i = 0; i < count; ++i )
  {
    v61 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)i);
    v60 = 0;
    survarium::weapon_user_dead_state::finalize(v35);
    v59 = 0;
    survarium::weapon_user_dead_state::finalize(v36);
    v58 = 0;
    survarium::weapon_user_dead_state::finalize(v37);
    conf_entry = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)apply_dmg, i);
    memset(&value, 0, sizeof(value));
    vostok::buffer_vector<survarium::booby_trap_set_core::apply_damage>::push_back(&this->m_damage_parameters, &value);
    survarium::weapon_user_dead_state::finalize(v38);
    ad = this->m_damage_parameters.m_end - 1;
    v39 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)conf_entry,
            "body_part");
    source = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                       v40,
                       (int)v39);
    vostok::strings::copy(ad->body_part, 0x10u, source);
    v41 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)conf_entry,
            "hit_type");
    v54 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v42, (int)v41);
    vostok::strings::copy(ad->hit_type, 0x10u, v54);
    vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)conf_entry, "amount");
    vostok::configs::binary_config_value::operator float(v43);
    ad->amount = v28;
    vostok::configs::binary_config_value::operator[](
      (vostok::configs::binary_config_value *)conf_entry,
      "armor_piercing");
    vostok::configs::binary_config_value::operator float(v44);
    ad->armor_piercing = v28;
    survarium::weapon_user_dead_state::finalize(v45);
    survarium::weapon_user_dead_state::finalize(v46);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)i);
  survarium::weapon_user_dead_state::finalize(v47);
  survarium::weapon_user_dead_state::finalize(v48);
  survarium::weapon_user_dead_state::finalize(v49);
  survarium::weapon_user_dead_state::finalize(v50);
  survarium::weapon_user_dead_state::finalize(v51);
}
