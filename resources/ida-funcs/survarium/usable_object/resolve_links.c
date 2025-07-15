void __thiscall survarium::usable_object::resolve_links(
        survarium::usable_object *this,
        survarium::base_project *p,
        vostok::configs::binary_config_value cfg)
{
  survarium::collision_geometry **v4; // esi
  const char **v5; // eax
  survarium::base_game_object *v6; // eax
  survarium::base_game_object *v7; // eax
  survarium::usable_object_user_data *m_last; // ecx
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
        v7 = v6 - 4;
      else
        v7 = 0;
      m_last = this->m_usable_object_users.m_last;
      ++v10;
      *((_DWORD *)&m_last->owner + (_DWORD)v4) = v7;
      v4 = (survarium::collision_geometry **)((char *)v4 + 1);
    }
    while ( v4 < this->m_collision_geometries );
  }
}
