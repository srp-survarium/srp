void __thiscall survarium::collision_sensor::resolve_links(
        survarium::collision_sensor *this,
        survarium::base_project *p,
        vostok::configs::binary_config_value cfg)
{
  vostok::configs::binary_config_value *v3; // eax
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  survarium::base_game_object *v6; // [esp+0h] [ebp-40h]
  survarium::base_game_object *v8; // [esp+1Ch] [ebp-24h]
  const char *geom_name; // [esp+20h] [ebp-20h]
  unsigned int i; // [esp+24h] [ebp-1Ch]
  vostok::configs::binary_config_value collision_table; // [esp+28h] [ebp-18h] BYREF

  collision_table = *vostok::configs::binary_config_value::operator[](&cfg, "collision_geometries");
  for ( i = 0; (survarium::collision_geometry **)i < this->m_collision_geometries; ++i )
  {
    v3 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&collision_table, i);
    v4 = vostok::configs::binary_config_value::operator[](v3, "name");
    geom_name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                v5,
                                (int)v4);
    v8 = p->get_object_by_name(p, geom_name);
    if ( v8 )
      v6 = v8 - 4;
    else
      v6 = 0;
    this->m_old_objects._M_impl._M_end_of_storage._M_data[i] = v6;
  }
}
