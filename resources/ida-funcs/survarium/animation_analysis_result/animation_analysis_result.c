void __thiscall survarium::animation_analysis_result::animation_analysis_result(
        survarium::animation_analysis_result *this,
        unsigned int legs_count)
{
  survarium::game_camera *v2; // ecx
  vostok::memory::doug_lea_allocator *v3; // eax
  survarium::game_camera *m_buffer; // [esp+8h] [ebp-Ch]

  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  this->__vftable = (survarium::animation_analysis_result_vtbl *)&survarium::animation_analysis_result::`vftable';
  survarium::weapon_user_dead_state::finalize(v2);
  this->m_buffer = vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>(v3, 28 * legs_count);
  m_buffer = (survarium::game_camera *)this->m_buffer;
  this->m_leg_key_times.m_begin = (survarium::leg_key_times *)m_buffer;
  this->m_leg_key_times.m_end = (survarium::leg_key_times *)((char *)m_buffer + 28 * legs_count);
  survarium::weapon_user_dead_state::finalize(m_buffer);
}
