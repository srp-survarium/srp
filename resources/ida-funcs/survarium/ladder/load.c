void __userpurge survarium::ladder::load(
        survarium::ladder *this@<ecx>,
        const char *a2@<esi>,
        const vostok::configs::binary_config_value *cfg_val)
{
  const vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  survarium::usable_object *v10; // ecx
  vostok::resources::resource_base *v11; // eax
  void (__thiscall **p_decrease_quality)(vostok::resources::resource_base *, const vostok::configs::binary_config_value *); // esi
  const vostok::configs::binary_config_value *v13; // eax
  const char *v15; // [esp+0h] [ebp-Ch]
  unsigned int v16; // [esp+4h] [ebp-8h]

  v4 = vostok::configs::binary_config_value::operator[](cfg_val, "collision_geometries");
  survarium::usable_object::load((survarium::usable_object *)this, v4);
  if ( vostok::configs::binary_config_value::value_exists(v5, (int)cfg_val, (unsigned int)"occlusion_geometries") )
  {
    v6 = survarium::g_allocator;
    v7 = type_info::raw_name(&survarium::ladder::ladder_occluder `RTTI Type Descriptor');
    v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 0x44u, v7, a2, v15, v16);
    if ( v9 )
    {
      survarium::usable_object::usable_object(v10, (int)v9, 1);
      v11->__vftable = (vostok::resources::resource_base_vtbl *)&survarium::ladder::ladder_occluder::`vftable'{for `survarium::collision_geometry_subscriber'};
      v11->type = (unsigned int)&survarium::ladder::ladder_occluder::`vftable'{for `survarium::link_resolver'};
    }
    else
    {
      v11 = 0;
    }
    this->m_next_in_increase_quality_queue = v11;
    p_decrease_quality = (void (__thiscall **)(vostok::resources::resource_base *, const vostok::configs::binary_config_value *))&v11->decrease_quality;
    v13 = vostok::configs::binary_config_value::operator[](cfg_val, "occlusion_geometries");
    (*p_decrease_quality)(this->m_next_in_increase_quality_queue, v13);
  }
}
