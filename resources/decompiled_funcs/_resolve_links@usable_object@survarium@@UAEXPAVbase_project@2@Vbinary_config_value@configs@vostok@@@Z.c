void __thiscall survarium::usable_object::resolve_links(
        survarium::usable_object *this,
        survarium::base_project *p,
        vostok::configs::binary_config_value cfg)
{
  vostok::configs::binary_config_value *v3; // eax
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  survarium::base_game_object *v6; // [esp+0h] [ebp-40h]
  survarium::base_game_object *v8; // [esp+1Ch] [ebp-24h]
  const char *geom_name; // [esp+20h] [ebp-20h]
  survarium::collision_geometry **i; // [esp+24h] [ebp-1Ch]
  vostok::configs::binary_config_value collision_table; // [esp+28h] [ebp-18h] BYREF

  collision_table = *vostok::configs::binary_config_value::operator[](&cfg, "collision_geometries");
  for ( i = 0; i < this->m_collision_geometries; i = (survarium::collision_geometry **)((char *)i + 1) )
  {
    v3 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   &collision_table,
                                                   (const int)i);
    v4 = vostok::configs::binary_config_value::operator[](v3, "name");
    geom_name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                v5,
                                (int)v4);
    v8 = p->get_object_by_name(p, geom_name);
    if ( v8 )
      v6 = v8 - 4;
    else
      v6 = 0;
    *((_DWORD *)&this->m_usable_object_users.m_last->owner + (_DWORD)i) = v6;
  }
}
