void __thiscall survarium::booby_trap_core::load(
        survarium::booby_trap_core *this,
        const vostok::configs::binary_config_value *config)
{
  const vostok::configs::binary_config_value *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  survarium::collision_geometry *v9; // ecx
  void (__thiscall *v10)(survarium::link_resolver *, survarium::base_project *, vostok::configs::binary_config_value); // eax
  vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value **v12; // eax
  survarium::collision_geometry *v13; // ecx
  const vostok::configs::binary_config_value *v14; // eax
  vostok::memory::doug_lea_allocator *v15; // esi
  char *v16; // eax
  vostok::memory::doug_lea_allocator *v17; // ecx
  char *v18; // eax
  survarium::collision_geometry *v19; // ecx
  int v20; // eax
  vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value **v22; // eax
  survarium::collision_geometry *v23; // ecx
  vostok::configs::binary_config_value *v24; // ecx
  vostok::configs::binary_config_value *v25; // eax
  survarium::hittable_object *v26; // ecx
  const char *v27; // [esp+0h] [ebp-10h]
  const char *v28; // [esp+0h] [ebp-10h]
  const char *v29; // [esp+4h] [ebp-Ch]
  const char *v30; // [esp+4h] [ebp-Ch]
  unsigned int v31; // [esp+8h] [ebp-8h]
  unsigned int v32; // [esp+8h] [ebp-8h]

  v4 = vostok::configs::binary_config_value::operator[](config, "collision_sensor");
  survarium::collision_sensor::load((survarium::collision_sensor *)this, v4);
  v5 = survarium::g_allocator;
  v6 = type_info::raw_name(&survarium::collision_geometry `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, 0x20u, v6, v27, v29, v31);
  if ( v8 )
    survarium::collision_geometry::collision_geometry(v9, (int)v8);
  else
    v10 = 0;
  this->resolve_links = v10;
  v11 = vostok::configs::binary_config_value::operator[](config, "collision_sensor");
  v12 = (vostok::configs::binary_config_value **)vostok::configs::binary_config_value::operator[](
                                                   v11,
                                                   "collision_geometries");
  survarium::collision_geometry::load(v13, (const vostok::configs::binary_config_value *)this->resolve_links, *v12);
  v14 = vostok::configs::binary_config_value::operator[](config, "usable_object");
  survarium::usable_object::load(
    (survarium::usable_object *)&this->survarium::collision_sensor::m_collision_geometries,
    v14);
  v15 = survarium::g_allocator;
  v16 = type_info::raw_name(&survarium::collision_geometry `RTTI Type Descriptor');
  v18 = vostok::memory::doug_lea_allocator::malloc_impl(v17, (int)v15, 0x20u, v16, v28, v30, v32);
  if ( v18 )
    survarium::collision_geometry::collision_geometry(v19, (int)v18);
  else
    v20 = 0;
  *(_DWORD *)this->m_usable_object_users.m_size = v20;
  v21 = vostok::configs::binary_config_value::operator[](config, "usable_object");
  v22 = (vostok::configs::binary_config_value **)vostok::configs::binary_config_value::operator[](
                                                   v21,
                                                   "collision_geometries");
  survarium::collision_geometry::load(
    v23,
    *(const vostok::configs::binary_config_value **)this->m_usable_object_users.m_size,
    *v22);
  if ( vostok::configs::binary_config_value::value_exists(v24, (int)config, (unsigned int)"hittable_object") )
  {
    v25 = vostok::configs::binary_config_value::operator[](config, "hittable_object");
    survarium::hittable_object::load(v26, (const vostok::configs::binary_config_value *)&this[-1].m_physics_world, v25);
  }
}


void __userpurge survarium::booby_trap_core::load(
        int a1@<ecx>,
        float a2@<xmm10>,
        const vostok::configs::binary_config_value *a3)
{
  survarium::booby_trap_core::load((survarium::booby_trap_core *)(a1 - 36), a2, a3);
}
