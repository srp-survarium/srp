void __userpurge survarium::victory_item_core::load(
        survarium::victory_item_core *this@<ecx>,
        const char *a2@<edi>,
        const vostok::configs::binary_config_value *cfg)
{
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  survarium::collision_geometry *v9; // ecx
  int v10; // eax
  vostok::configs::binary_config_value **v11; // eax
  survarium::collision_geometry *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  const vostok::configs::binary_config_value *v14; // eax
  vostok::configs::binary_config_value *v15; // ecx
  vostok::configs::binary_config_value *v16; // eax
  const vostok::configs::binary_config_value *v17; // eax
  float pointer; // xmm0_4
  const char *v19; // [esp+0h] [ebp-Ch]
  unsigned int v20; // [esp+4h] [ebp-8h]

  survarium::usable_object::load((survarium::usable_object *)this, cfg);
  v5 = survarium::g_allocator;
  v6 = type_info::raw_name(&survarium::collision_geometry `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, 0x20u, v6, a2, v19, v20);
  if ( v8 )
    survarium::collision_geometry::collision_geometry(v9, (int)v8);
  else
    v10 = 0;
  **(_DWORD **)this->m_deserialized_users.m_buffer[16].m_store = v10;
  v11 = (vostok::configs::binary_config_value **)vostok::configs::binary_config_value::operator[](
                                                   cfg,
                                                   "collision_geometries");
  survarium::collision_geometry::load(
    v12,
    **(const vostok::configs::binary_config_value ***)this->m_deserialized_users.m_buffer[16].m_store,
    *v11);
  if ( vostok::configs::binary_config_value::value_exists(v13, (int)cfg, (unsigned int)"parameters") )
  {
    v14 = vostok::configs::binary_config_value::operator[](cfg, "parameters");
    if ( vostok::configs::binary_config_value::value_exists(v15, (int)v14, (unsigned int)"movement_speed_modifier") )
    {
      v16 = vostok::configs::binary_config_value::operator[](cfg, "parameters");
      v17 = vostok::configs::binary_config_value::operator[](v16, "movement_speed_modifier");
      if ( v17->type == 2 )
        pointer = *(float *)&v17->data.pointer;
      else
        pointer = (float)(int)v17->data.pointer;
      *(float *)&this->m_skeleton.m_object = pointer;
    }
  }
}
