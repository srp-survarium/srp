void __thiscall survarium::grenade_set_core::load(
        survarium::grenade_set_core *this,
        const vostok::configs::binary_config_value *config,
        vostok::configs::binary_config_value *amount,
        unsigned __int8 a4)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v10; // eax
  float v11; // xmm0_4
  const vostok::configs::binary_config_value *v12; // eax
  float v13; // xmm0_4
  const vostok::configs::binary_config_value *v14; // eax
  float v15; // xmm0_4
  const vostok::configs::binary_config_value *v16; // eax
  float v17; // xmm0_4
  char **v18; // eax
  int v19; // eax
  unsigned int *p_id_crc; // ebx
  const vostok::configs::binary_config_value *i; // ecx
  int v22; // esi
  const char *v23; // [esp+0h] [ebp-Ch]
  const char *v24; // [esp+4h] [ebp-8h]
  unsigned int v25; // [esp+8h] [ebp-4h]
  int v26; // [esp+1Ch] [ebp+10h]

  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>>::~buffer_vector<vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>>(
    (vostok::buffer_vector<vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> > *)this,
    (vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&config[12]);
  if ( a4 )
  {
    v4 = survarium::g_allocator;
    v5 = type_info::raw_name(&vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> `RTTI Type Descriptor');
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 4 * a4, v5, v23, v24, v25);
  }
  else
  {
    v7 = 0;
  }
  HIDWORD(config[12].id.max_storage) = v7;
  if ( config != (const vostok::configs::binary_config_value *)-288 )
  {
    config[12].data.pointer = v7;
    HIDWORD(config[12].data.max_storage) = v7;
    config[12].id.pointer = &v7[4 * a4];
  }
  WORD2(config[15].data.max_storage) = vostok::configs::binary_config_value::operator[](amount, "ttl_ms")->data.pointer;
  v8 = vostok::configs::binary_config_value::operator[](amount, "throw_power");
  if ( v8->type == 2 )
    pointer = *(float *)&v8->data.pointer;
  else
    pointer = (float)(int)v8->data.pointer;
  *(float *)&config[15].data.pointer = pointer;
  v10 = vostok::configs::binary_config_value::operator[](amount, "splash_radius");
  if ( v10->type == 2 )
    v11 = *(float *)&v10->data.pointer;
  else
    v11 = (float)(int)v10->data.pointer;
  *(float *)&config[14].id.pointer = v11;
  v12 = vostok::configs::binary_config_value::operator[](amount, "splash_max_damage");
  if ( v12->type == 2 )
    v13 = *(float *)&v12->data.pointer;
  else
    v13 = (float)(int)v12->data.pointer;
  *(float *)&config[14].id_crc = v13;
  v14 = vostok::configs::binary_config_value::operator[](amount, "splash_min_damage");
  if ( v14->type == 2 )
    v15 = *(float *)&v14->data.pointer;
  else
    v15 = (float)(int)v14->data.pointer;
  *((float *)&config[14].id.max_storage + 1) = v15;
  v16 = vostok::configs::binary_config_value::operator[](amount, "splash_pierce");
  if ( v16->type == 2 )
    v17 = *(float *)&v16->data.pointer;
  else
    v17 = (float)(int)v16->data.pointer;
  *(float *)&config[14].type = v17;
  v18 = (char **)vostok::configs::binary_config_value::operator[](amount, "splash_damage_type");
  config[14].data.pointer = (const void *)survarium::hit_type(*v18);
  v19 = 24 * vostok::configs::binary_config_value::operator[](amount, "splash_affected_bodies")->count / 24;
  p_id_crc = &config[12].id_crc;
  for ( i = (const vostok::configs::binary_config_value *)((char *)config + 304);
        i != &config[14];
        i = (const vostok::configs::binary_config_value *)((char *)i + 4) )
  {
    i->data.pointer = (const void *)-1;
  }
  if ( v19 )
  {
    v22 = 0;
    v26 = v19;
    do
    {
      *p_id_crc++ = *(_DWORD *)((char *)vostok::configs::binary_config_value::operator[](
                                          amount,
                                          "splash_affected_bodies")->data.pointer
                              + v22);
      v22 += 24;
      --v26;
    }
    while ( v26 );
  }
}
