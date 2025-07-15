double __thiscall vostok::resources::resource_quality::update_satisfaction(
        vostok::resources::resource_quality *this,
        unsigned __int64 update_tick)
{
  vostok::resources::resource_quality *m_current_satisfaction_update_tick; // ecx
  bool v5; // zf
  vostok::threading::simple_lock *v6; // eax
  vostok::resources::resource_link *no_dying; // edi
  unsigned int quality_value; // eax
  vostok::resources::resource_quality *resource; // ecx
  double updated; // st7
  vostok::threading::simple_lock::mutex_raii v11; // [esp+10h] [ebp-10h] BYREF
  float v12; // [esp+18h] [ebp-8h]
  float v13; // [esp+1Ch] [ebp-4h]

  m_current_satisfaction_update_tick = (vostok::resources::resource_quality *)this->m_current_satisfaction_update_tick;
  if ( m_current_satisfaction_update_tick == (vostok::resources::resource_quality *)update_tick )
  {
    m_current_satisfaction_update_tick = (vostok::resources::resource_quality *)HIDWORD(this->m_current_satisfaction_update_tick);
    if ( m_current_satisfaction_update_tick == (vostok::resources::resource_quality *)HIDWORD(update_tick) )
      return this->m_current_satisfaction;
  }
  v5 = this->m_quality_levels_count == 1;
  this->m_current_satisfaction_update_tick = update_tick;
  if ( !v5 )
    return vostok::resources::resource_quality::update_satisfaction_for_resource_with_quality(
             m_current_satisfaction_update_tick,
             this);
  if ( this == (vostok::resources::resource_quality *)-60 )
    v6 = 0;
  else
    v6 = &this->m_parent_resources.vostok::threading::simple_lock;
  v11.lock = v6;
  vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)m_current_satisfaction_update_tick, (int)v6);
  v11.locked = 1;
  no_dying = vostok::resources::resource_link_list_front_no_dying(&this->m_parent_resources);
  v13 = FLOAT_2048_0;
  if ( !no_dying )
    goto LABEL_17;
  do
  {
    quality_value = no_dying->quality_value;
    resource = no_dying->resource;
    if ( quality_value == -1 )
      updated = vostok::resources::resource_quality::update_satisfaction(resource, update_tick);
    else
      updated = vostok::resources::resource_quality::satisfaction(resource, quality_value, 0, 0);
    v12 = updated;
    if ( v13 > (double)v12 )
      v13 = v12;
    no_dying = vostok::resources::resource_link_list_next_no_dying(no_dying);
  }
  while ( no_dying );
  if ( v13 >= 1024.0 )
LABEL_17:
    v13 = vostok::resources::resource_quality::calculate_best_satisfaction_based_on_size(this);
  this->m_current_satisfaction = v13;
  vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v11);
  return v13;
}
