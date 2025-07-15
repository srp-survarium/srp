void __thiscall survarium::booby_trap_set_core::load(
        survarium::booby_trap_set_core *this,
        const vostok::configs::binary_config_value *config,
        vostok::configs::binary_config_value *amount,
        unsigned __int8 a4)
{
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  const vostok::configs::binary_config_value *v9; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v11; // eax
  float v12; // xmm0_4
  const vostok::configs::binary_config_value *v13; // eax
  float v14; // xmm0_4
  const vostok::configs::binary_config_value *v15; // eax
  float v16; // xmm0_4
  const vostok::configs::binary_config_value *v17; // eax
  float v18; // xmm0_4
  const vostok::configs::binary_config_value *v19; // eax
  float v20; // xmm0_4
  vostok::memory::doug_lea_allocator *v21; // esi
  char *v22; // eax
  char *v23; // eax
  unsigned int v24; // esi
  char **v25; // eax
  char **v26; // eax
  const vostok::configs::binary_config_value *v27; // eax
  float v28; // xmm0_4
  const vostok::configs::binary_config_value *v29; // eax
  float v30; // xmm0_4
  bool v31; // zf
  long double v32; // [esp+4h] [ebp-2Ch]
  const char *v33; // [esp+4h] [ebp-2Ch]
  const char *v34; // [esp+8h] [ebp-28h]
  unsigned int v35; // [esp+Ch] [ebp-24h]
  _BYTE v36[28]; // [esp+10h] [ebp-20h] BYREF
  const vostok::configs::binary_config_value *v37; // [esp+2Ch] [ebp-4h]
  int v38; // [esp+38h] [ebp+8h]
  int v39; // [esp+3Ch] [ebp+Ch]
  int v40; // [esp+40h] [ebp+10h]
  vostok::configs::binary_config_value *v41; // [esp+40h] [ebp+10h]

  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>>::~buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>>(
    (vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> > *)this,
    (vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&config[12]);
  if ( a4 )
  {
    v5 = survarium::g_allocator;
    v6 = type_info::raw_name(&vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> `RTTI Type Descriptor');
    v8 = vostok::memory::doug_lea_allocator::malloc_impl(
           v7,
           (int)v5,
           4 * a4,
           v6,
           (const char *const)LODWORD(v32),
           (const char *const)HIDWORD(v32),
           v35);
  }
  else
  {
    v8 = 0;
  }
  HIDWORD(config[14].data.max_storage) = v8;
  if ( config != (const vostok::configs::binary_config_value *)-288 )
  {
    config[12].data.pointer = v8;
    HIDWORD(config[12].data.max_storage) = v8;
    config[12].id.pointer = &v8[4 * a4];
  }
  v9 = vostok::configs::binary_config_value::operator[](amount, "max_deploy_distance");
  if ( v9->type == 2 )
    pointer = *(float *)&v9->data.pointer;
  else
    pointer = (float)(int)v9->data.pointer;
  *((float *)&config[13].data.max_storage + 1) = pointer;
  v11 = vostok::configs::binary_config_value::operator[](amount, "max_slope_angle");
  if ( v11->type == 2 )
    v12 = *(float *)&v11->data.pointer;
  else
    v12 = (float)(int)v11->data.pointer;
  __libm_sse2_cos(v32);
  *(float *)&config[13].data.pointer = (float)(v12 * 0.0055555557) * 3.1415927;
  v13 = vostok::configs::binary_config_value::operator[](amount, "armed_life_time");
  if ( v13->type == 2 )
    v14 = *(float *)&v13->data.pointer;
  else
    v14 = (float)(int)v13->data.pointer;
  config[13].id.pointer = (const char *)vostok::math::floor(v14 * 1000.0);
  v15 = vostok::configs::binary_config_value::operator[](amount, "fired_life_time");
  if ( v15->type == 2 )
    v16 = *(float *)&v15->data.pointer;
  else
    v16 = (float)(int)v15->data.pointer;
  HIDWORD(config[13].id.max_storage) = vostok::math::floor(v16 * 1000.0);
  v17 = vostok::configs::binary_config_value::operator[](amount, "disarmed_life_time");
  if ( v17->type == 2 )
    v18 = *(float *)&v17->data.pointer;
  else
    v18 = (float)(int)v17->data.pointer;
  config[13].id_crc = vostok::math::floor(v18 * 1000.0);
  v19 = vostok::configs::binary_config_value::operator[](amount, "defuse_time");
  if ( v19->type == 2 )
    v20 = *(float *)&v19->data.pointer;
  else
    v20 = (float)(int)v19->data.pointer;
  *(_DWORD *)&config[13].type = vostok::math::floor(v20 * 1000.0);
  LOBYTE(config[14].data.pointer) = vostok::configs::binary_config_value::operator[](amount, "defuse_by_hit")->data.pointer != 0;
  BYTE1(config[14].data.pointer) = vostok::configs::binary_config_value::operator[](amount, "material_can_place_test")->data.pointer != 0;
  BYTE2(config[14].data.max_storage) = vostok::configs::binary_config_value::operator[](
                                         amount,
                                         "material_can_stick_test")->data.pointer != 0;
  v37 = vostok::configs::binary_config_value::operator[](amount, "damage_parameters");
  v40 = 24 * v37->count / 24;
  config[12].id_crc = HIDWORD(config[12].id.max_storage);
  if ( config != (const vostok::configs::binary_config_value *)-300 )
  {
    v21 = survarium::g_allocator;
    v22 = type_info::raw_name(&survarium::booby_trap_set_core::apply_damage `RTTI Type Descriptor');
    v23 = vostok::memory::doug_lea_allocator::malloc_impl(
            (vostok::memory::doug_lea_allocator *)(28 * v40),
            (int)v21,
            28 * v40,
            v22,
            v33,
            v34,
            v35);
    HIDWORD(config[12].id.max_storage) = v23;
    config[12].id_crc = (unsigned int)v23;
    *(_DWORD *)&config[12].type = &v23[28 * v40];
  }
  if ( v40 )
  {
    v38 = 0;
    v39 = v40;
    do
    {
      v41 = (vostok::configs::binary_config_value *)((char *)v37->data.pointer + v38);
      memset(v36, 0, sizeof(v36));
      vostok::buffer_vector<survarium::booby_trap_set_core::apply_damage>::push_back(
        0,
        (const survarium::booby_trap_set_core::apply_damage *)((char *)&config[12].id.max_storage + 4),
        v36);
      v24 = config[12].id_crc - 28;
      v25 = (char **)vostok::configs::binary_config_value::operator[](v41, "body_part");
      vostok::strings::copy<16>((char (*)[16])v24, *v25);
      v26 = (char **)vostok::configs::binary_config_value::operator[](v41, "hit_type");
      *(_DWORD *)(v24 + 16) = survarium::hit_type(*v26);
      v27 = vostok::configs::binary_config_value::operator[](v41, "amount");
      if ( v27->type == 2 )
        v28 = *(float *)&v27->data.pointer;
      else
        v28 = (float)(int)v27->data.pointer;
      *(float *)(v24 + 20) = v28;
      v29 = vostok::configs::binary_config_value::operator[](v41, "armor_piercing");
      if ( v29->type == 2 )
        v30 = *(float *)&v29->data.pointer;
      else
        v30 = (float)(int)v29->data.pointer;
      v38 += 24;
      v31 = v39-- == 1;
      *(float *)(v24 + 24) = v30;
    }
    while ( !v31 );
  }
}
