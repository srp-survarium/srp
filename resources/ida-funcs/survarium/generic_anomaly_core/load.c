void __thiscall survarium::generic_anomaly_core::load(
        survarium::generic_anomaly_core *this,
        const vostok::configs::binary_config_value *config)
{
  vostok::configs::binary_config_value *v2; // esi
  const vostok::configs::binary_config_value *v4; // eax
  float pointer; // xmm0_4
  bool v6; // zf
  int v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  float v9; // xmm0_4
  unsigned int v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // esi
  char *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // ecx
  char *v15; // eax
  _BYTE *v16; // esi
  const vostok::configs::binary_config_value *v17; // eax
  vostok::memory::doug_lea_allocator *v18; // esi
  char *v19; // eax
  vostok::memory::doug_lea_allocator *v20; // ecx
  char *v21; // eax
  char *v22; // esi
  unsigned int v23; // edi
  const char *v24; // [esp+0h] [ebp-50h]
  const char *v25; // [esp+4h] [ebp-4Ch]
  unsigned int v26; // [esp+8h] [ebp-48h]
  vostok::configs::binary_config_value *v27; // [esp+Ch] [ebp-44h]
  char *v28; // [esp+10h] [ebp-40h]
  unsigned int v29; // [esp+14h] [ebp-3Ch]
  unsigned int v30; // [esp+18h] [ebp-38h]
  int v31; // [esp+1Ch] [ebp-34h]
  unsigned int __new_size; // [esp+20h] [ebp-30h]
  void *v33; // [esp+24h] [ebp-2Ch] BYREF
  void *__x; // [esp+28h] [ebp-28h] BYREF
  void *v35; // [esp+2Ch] [ebp-24h] BYREF
  void *v36[2]; // [esp+30h] [ebp-20h] BYREF
  vostok::configs::binary_config_value v37; // [esp+38h] [ebp-18h] BYREF

  v2 = config;
  this->artefacts_enabled = vostok::configs::binary_config_value::operator[](config, "artefacts_enabled")->data.pointer != 0;
  this->artefacts_respawn_time_sec = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                     config,
                                                     "artefacts_respawn_time_sec")->data.pointer;
  v4 = vostok::configs::binary_config_value::operator[](config, "artefacts_respawn_chance");
  if ( v4->type == 2 )
    pointer = *(float *)&v4->data.pointer;
  else
    pointer = (float)(int)v4->data.pointer;
  v6 = !this->artefacts_enabled;
  this->artefacts_respawn_chance = pointer;
  if ( !v6 )
  {
    v7 = 24 * vostok::configs::binary_config_value::operator[](config, "artefact_containers")->count;
    __x = 0;
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::resize(
      &this->m_artefact_containers._M_impl,
      v7 / 24,
      &__x);
  }
  this->energy_enabled = vostok::configs::binary_config_value::operator[](config, "energy_enabled")->data.pointer != 0;
  v8 = vostok::configs::binary_config_value::operator[](config, "energy_initial");
  if ( v8->type == 2 )
    v9 = *(float *)&v8->data.pointer;
  else
    v9 = (float)(int)v8->data.pointer;
  this->m_energy_current = v9;
  this->energy_decrease_speed = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                config,
                                                "energy_decrease_speed")->data.pointer;
  this->energy_af_container_use = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                  config,
                                                  "energy_af_container_use")->data.pointer;
  this->energy_on_walk = (unsigned int)vostok::configs::binary_config_value::operator[](config, "energy_on_walk")->data.pointer;
  this->energy_on_run = (unsigned int)vostok::configs::binary_config_value::operator[](config, "energy_on_run")->data.pointer;
  this->energy_on_sprint = (unsigned int)vostok::configs::binary_config_value::operator[](config, "energy_on_sprint")->data.pointer;
  this->energy_on_jump = (unsigned int)vostok::configs::binary_config_value::operator[](config, "energy_on_jump")->data.pointer;
  this->energy_on_shoot = (unsigned int)vostok::configs::binary_config_value::operator[](config, "energy_on_shoot")->data.pointer;
  this->energy_on_character_hit = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                  config,
                                                  "energy_on_character_hit")->data.pointer;
  this->energy_on_explosion = (unsigned int)vostok::configs::binary_config_value::operator[](
                                              config,
                                              "energy_on_explosion")->data.pointer;
  this->energy_on_character_kill = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                   config,
                                                   "energy_on_character_kill")->data.pointer;
  v10 = 24 * vostok::configs::binary_config_value::operator[](config, "states")->count / 24;
  v33 = 0;
  __x = (void *)v10;
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::resize(&this->m_states._M_impl, v10, &v33);
  v30 = 0;
  if ( __x )
  {
    v35 = 0;
    v33 = 0;
    while ( 1 )
    {
      v11 = vostok::configs::binary_config_value::operator[](v2, "states");
      qmemcpy((void *)&v37, (char *)v33 + (unsigned int)v11->data.pointer, sizeof(v37));
      v12 = survarium::g_allocator;
      v13 = type_info::raw_name(&survarium::anomaly_state `RTTI Type Descriptor');
      v15 = vostok::memory::doug_lea_allocator::malloc_impl(v14, (int)v12, 0x30u, v13, v24, v25, v26);
      if ( v15 )
      {
        *((_DWORD *)v15 + 7) = 0;
        *((_DWORD *)v15 + 8) = 0;
        v16 = v15;
        *((_DWORD *)v15 + 9) = 0;
        *((_DWORD *)v15 + 10) = this;
        v28 = v15;
      }
      else
      {
        v28 = 0;
        v16 = 0;
      }
      this->m_states._M_impl._M_start[v30] = v16;
      *((_DWORD *)v16 + 1) = v30;
      *v16 = vostok::configs::binary_config_value::operator[](&v37, "enabled")->data.pointer != 0;
      *((_DWORD *)v16 + 2) = vostok::configs::binary_config_value::operator[](&v37, "energy_threshold")->data.pointer;
      v16[12] = vostok::configs::binary_config_value::operator[](&v37, "shoot_trigger")->data.pointer != 0;
      v16[13] = vostok::configs::binary_config_value::operator[](&v37, "zone_activity_trigger")->data.pointer != 0;
      *((_DWORD *)v16 + 4) = vostok::configs::binary_config_value::operator[](&v37, "active_time_sec")->data.pointer;
      *((_DWORD *)v16 + 5) = vostok::configs::binary_config_value::operator[](&v37, "energy_on_exit")->data.pointer;
      *((_DWORD *)v16 + 6) = vostok::configs::binary_config_value::operator[](&v37, "select_priority")->data.pointer;
      __new_size = 24 * vostok::configs::binary_config_value::operator[](&v37, "groups")->count / 24;
      stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::resize(
        (stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)(v16 + 28),
        __new_size,
        &v35);
      v29 = 0;
      if ( __new_size )
      {
        v36[0] = 0;
        v31 = 0;
        do
        {
          v17 = vostok::configs::binary_config_value::operator[](&v37, "groups");
          v18 = survarium::g_allocator;
          v27 = (vostok::configs::binary_config_value *)((char *)v17->data.pointer + v31);
          v19 = type_info::raw_name(&survarium::zone_group `RTTI Type Descriptor');
          v21 = vostok::memory::doug_lea_allocator::malloc_impl(v20, (int)v18, 0x28u, v19, v24, v25, v26);
          v22 = 0;
          if ( v21 )
          {
            *((_DWORD *)v21 + 5) = 0;
            *((_DWORD *)v21 + 6) = 0;
            *((_DWORD *)v21 + 7) = 0;
            *((_DWORD *)v21 + 8) = v28;
            v22 = v21;
          }
          *(_DWORD *)(*((_DWORD *)v28 + 7) + 4 * v29) = v22;
          *v22 = vostok::configs::binary_config_value::operator[](v27, "enabled")->data.pointer != 0;
          v22[1] = vostok::configs::binary_config_value::operator[](v27, "keep_all_zones_active")->data.pointer != 0;
          v22[2] = vostok::configs::binary_config_value::operator[](v27, "sequential_activation")->data.pointer != 0;
          *((_DWORD *)v22 + 1) = vostok::configs::binary_config_value::operator[](v27, "min_active_time_sec")->data.pointer;
          *((_DWORD *)v22 + 2) = vostok::configs::binary_config_value::operator[](v27, "max_active_time_sec")->data.pointer;
          *((_DWORD *)v22 + 3) = vostok::configs::binary_config_value::operator[](v27, "max_charged_count")->data.pointer;
          v36[1] = v22 + 12;
          *((_DWORD *)v22 + 4) = vostok::configs::binary_config_value::operator[](v27, "recharge_time_sec")->data.pointer;
          v23 = 24 * vostok::configs::binary_config_value::operator[](v27, "zones")->count / 24;
          stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::resize(
            (stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)(v22 + 20),
            v23,
            v36);
          vostok::math::clamp<unsigned int>(0, v23);
          ++v29;
          v31 += 24;
        }
        while ( v29 < __new_size );
      }
      ++v30;
      v33 = (char *)v33 + 24;
      if ( v30 >= (unsigned int)__x )
        break;
      v2 = config;
    }
  }
}
