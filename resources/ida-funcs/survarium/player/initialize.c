void __userpurge survarium::player::initialize(
        survarium::player *this@<ecx>,
        long double a2@<esi:edi>,
        unsigned int time_in_ms,
        const vostok::math::float3 *position,
        unsigned int orientation,
        int look_pitch)
{
  vostok::math::float4x4 *v7; // ecx
  survarium::interactive_object *v8; // ecx
  survarium::interactive_object **p_m_current_active_object; // esi
  survarium::base_player *v10; // ecx
  int v11; // eax
  survarium::base_game_effect_presenter *m_effect_presenter; // ecx
  vostok::math::float4x4 v13; // [esp+18h] [ebp-40h] BYREF

  survarium::base_player::initialize(this, (int)this, a2, time_in_ms, position, orientation, look_pitch);
  qmemcpy((char *)this + (_DWORD)&locret_1111E + 2, vostok::math::float4x4::identity(v7, &v13), 0x40u);
  qmemcpy((char *)&loc_111A8 + (_DWORD)this, &byte_10E2C[(_DWORD)this], 0x40u);
  if ( !this->m_target_active_object )
  {
    v8 = *(survarium::interactive_object **)((char *)&dword_11418 + (_DWORD)this);
    p_m_current_active_object = &this->m_current_active_object;
    this->m_target_active_object = v8;
    this->m_current_active_object = v8;
    v8->set_user(v8, this);
    (*p_m_current_active_object)->initialize(*p_m_current_active_object);
    (*p_m_current_active_object)->activate(*p_m_current_active_object, 1);
    survarium::base_player::select_animations(v10, this, this->m_current_time_in_ms);
  }
  v11 = *(int *)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
               + (_DWORD)&loc_11403
               + 5);
  if ( v11 )
    *(_DWORD *)(v11 + 872) = 1;
  m_effect_presenter = this->m_effect_presenter;
  if ( m_effect_presenter )
    m_effect_presenter->clear(m_effect_presenter);
  *(survarium::player_vtbl **)((char *)&this->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                             + (_DWORD)&loc_11403
                             + 1) = 0;
}
