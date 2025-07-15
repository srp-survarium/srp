void __userpurge survarium::player::on_landing(
        survarium::player *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        float vertical_speed)
{
  survarium::player *v6; // ecx
  char v7; // bl
  const vostok::math::float4x4 *v8; // eax
  survarium::player_vtbl *m_current_time_in_ms; // ecx
  const vostok::math::float3 *v10; // eax
  float v11; // xmm1_4
  int v12; // edi
  vostok::math::float4_pod *foot_material; // [esp+18h] [ebp-8h]
  const vostok::math::float3 *v15; // [esp+1Ch] [ebp-4h]

  if ( vertical_speed > this->m_fall_params.harmless_vertical_speed )
    survarium::base_player::on_physical_controller_landing(this, vertical_speed);
  if ( (*(int (__thiscall **)(_DWORD, int, int, int))(**(_DWORD **)((char *)&dword_11410 + (_DWORD)this) + 52))(
         *(int *)((char *)&dword_11410 + (_DWORD)this),
         a3,
         a4,
         a2) )
  {
    v7 = !survarium::player::is_first_view(v6, (int)this);
    LOBYTE(v15) = v7;
    foot_material = &this->transform(&this->survarium::collision_user)->k;
    v8 = this->transform(&this->survarium::collision_user);
    m_current_time_in_ms = (survarium::player_vtbl *)this->m_current_time_in_ms;
    v10 = (const vostok::math::float3 *)&v8->lines[3];
    if ( vertical_speed > *(float *)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                   + (_DWORD)&loc_113F9
                                   + 3)
      && (unsigned int)((char *)m_current_time_in_ms
                      - *(char **)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                 + (_DWORD)&loc_11403
                                 + 1)) > 0x32 )
    {
      v11 = *(float *)((char *)&loc_11400 + (_DWORD)this);
      *(survarium::player_vtbl **)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                 + (_DWORD)&loc_11403
                                 + 1) = m_current_time_in_ms;
      if ( v11 <= vertical_speed )
        v12 = 4;
      else
        v12 = 0;
      survarium::step_manager::on_step(
        (survarium::step_manager *)*((unsigned __int16 *)&(*(survarium::player_vtbl **)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                                                      + (_DWORD)&loc_113F6
                                                                                      + 2))->~survarium::player
                                   + 2 * v12
                                   + (v7 != 0)),
        v15,
        v10,
        (int)foot_material,
        *((_WORD *)&(*(survarium::player_vtbl **)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                + (_DWORD)&loc_113F6
                                                + 2))->~survarium::player
        + 2 * v12
        + (v7 != 0)),
        v7);
    }
  }
}
