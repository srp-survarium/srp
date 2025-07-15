void __thiscall survarium::collision_sensor::resolve_links(
        survarium::collision_sensor *this,
        survarium::base_project *p,
        vostok::configs::binary_config_value cfg)
{
  survarium::collision_geometry **v4; // esi
  const char **v5; // eax
  survarium::base_game_object *v6; // eax
  vostok::physics::loose_ptr_data *v7; // eax
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *M_data; // ecx
  _DWORD v9[6]; // [esp+Ch] [ebp-1Ch] BYREF
  vostok::configs::binary_config_value *v10; // [esp+24h] [ebp-4h]

  qmemcpy(v9, vostok::configs::binary_config_value::operator[](&cfg, "collision_geometries"), sizeof(v9));
  v4 = 0;
  if ( this->m_collision_geometries )
  {
    v10 = (vostok::configs::binary_config_value *)v9[0];
    do
    {
      v5 = (const char **)vostok::configs::binary_config_value::operator[](v10, "name");
      v6 = p->get_object_by_name(p, *v5);
      if ( v6 )
        v7 = (vostok::physics::loose_ptr_data *)&v6[-4];
      else
        v7 = 0;
      M_data = this->m_old_objects._M_impl._M_end_of_storage._M_data;
      ++v10;
      M_data[(_DWORD)v4].m_object = v7;
      v4 = (survarium::collision_geometry **)((char *)v4 + 1);
    }
    while ( v4 < this->m_collision_geometries );
  }
}
