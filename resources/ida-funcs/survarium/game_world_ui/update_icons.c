void __thiscall survarium::game_world_ui::update_icons(
        survarium::game_world_ui *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  bool v3; // zf
  int v4; // ecx
  int v5; // eax
  survarium::game_world_ui *v6; // ecx
  vostok::math::float3 v7; // [esp-14h] [ebp-68h]
  _BYTE v8[64]; // [esp+Ch] [ebp-48h] BYREF
  const survarium::game_match_rule_base *v9; // [esp+4Ch] [ebp-8h]

  m_object = a2.m_object;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &a2,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(a2.m_object->m_reconstruction_info_actuality_tick) + 13604));
  v9 = survarium::game_world_core::game_rule((survarium::game_world_core *)a2.m_object->m_lods[1].m_emitter_instance_list.m_last);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  if ( v9 )
  {
    v3 = *(_BYTE *)(m_object->m_reconstruction_size + 29783) == 0;
    HIBYTE(a2.m_object) = 0;
    if ( !v3 )
    {
      do
      {
        v4 = *((_DWORD *)&v9[1].~survarium::game_match_rule_base + HIBYTE(a2.m_object));
        if ( *(_DWORD *)(v4 + 8) || (((LODWORD(m_object->m_transform.i.x) != 0) + 1) & *(_DWORD *)(v4 + 436)) == 0 )
        {
          survarium::game_world_ui::set_hud_icon_visible(
            (survarium::game_world_ui *)v4,
            (int)m_object,
            HIBYTE(a2.m_object) + 22,
            0);
        }
        else
        {
          v5 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v4 + 24))(v4, v8);
          *(_QWORD *)&v7.elements[1] = *(_QWORD *)(v5 + 48);
          LODWORD(v7.x) = (unsigned __int8)(HIBYTE(a2.m_object) + 22);
          survarium::game_world_ui::draw_object_icon(v6, (int)m_object, v7, *(float *)(v5 + 56), 0.0);
        }
        ++HIBYTE(a2.m_object);
      }
      while ( HIBYTE(a2.m_object) < *(_BYTE *)(m_object->m_reconstruction_size + 29783) );
    }
  }
}
