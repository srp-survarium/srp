void __thiscall survarium::animation_analysis_result::~animation_analysis_result(
        survarium::animation_analysis_result *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  survarium::leg_key_times *j; // [esp+Ch] [ebp-Ch]
  survarium::leg_key_times *i; // [esp+14h] [ebp-4h]

  this->__vftable = (survarium::animation_analysis_result_vtbl *)&survarium::animation_analysis_result::`vftable';
  for ( i = this->m_leg_key_times.m_begin; i != this->m_leg_key_times.m_end; ++i )
    ;
  this->m_leg_key_times.m_end = this->m_leg_key_times.m_begin;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_leg_key_times);
  ___free_helper_Vdoug_lea_allocator_memory_vostok____CBX_memory_vostok__YAXAAVdoug_lea_allocator_01_AAPBX_Z(
    v1,
    &this->m_buffer);
  for ( j = this->m_leg_key_times.m_begin; j != this->m_leg_key_times.m_end; ++j )
    ;
  this->m_leg_key_times.m_end = this->m_leg_key_times.m_begin;
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
