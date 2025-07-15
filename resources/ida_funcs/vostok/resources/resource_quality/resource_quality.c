void __userpurge vostok::resources::resource_quality::resource_quality(
        vostok::resources::resource_quality *this@<eax>,
        volatile int flags@<edi>,
        vostok::resources::class_id_enum class_id,
        unsigned int quality_levels_count)
{
  vostok::resources::resource_children::resource_children(this, flags);
  this->__vftable = (vostok::resources::resource_quality_vtbl *)&vostok::resources::resource_quality::`vftable';
  this->m_memory_usage_self.type = 0;
  this->m_memory_usage_self.size = 0;
  this->m_current_satisfaction_update_tick = 0;
  this->m_next_in_increase_quality_queue = 0;
  this->m_quality_levels_count = quality_levels_count;
  this->m_current_quality_level = -1;
  this->m_target_quality_level = -1;
  this->m_current_satisfaction = 0.0;
  this->m_target_satisfaction = 0.0;
  this->m_last_fail_of_increasing_quality = 0.0;
  this->m_class_id = class_id;
}
