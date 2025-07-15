void __userpurge vostok::resources::query_result::query_result(
        vostok::resources::query_result *this@<esi>,
        vostok::resources::queries_result *parent@<eax>,
        vostok::resources::query_result_for_cook *a3@<ecx>,
        unsigned __int16 flags,
        vostok::memory::base_allocator *allocator,
        unsigned int user_thread_id,
        float target_satisfaction,
        bool disable_cache,
        unsigned int quality_index,
        vostok::resources::query_type_enum query_type,
        vostok::resources::autoselect_quality_bool autoselect_quality)
{
  vostok::resources::query_result_for_cook::query_result_for_cook(a3, (int)this, parent);
  this->__vftable = (vostok::resources::query_result_vtbl *)&vostok::resources::query_result::`vftable';
  this->m_next_out_of_memory = 0;
  this->m_sub_fat.m_object = 0;
  this->m_next_in_device_manager = 0;
  this->m_next_in_generate_if_no_file_queue = 0;
  this->m_prev_in_generate_if_no_file_queue = 0;
  this->m_data_to_save_generator = 0;
  this->m_compressed_resource.m_object = 0;
  this->m_raw_managed_resource.m_object = 0;
  vostok::const_buffer::const_buffer(&this->m_raw_unmanaged_buffer);
  vostok::const_buffer::const_buffer(&this->m_unmanaged_buffer);
  this->m_name_registry_entry.class_id = unknown_data_class;
  this->m_name_registry_entry.associated = 0;
  this->m_name_registry_entry.name = 0;
  this->m_name_registry_entry.next_to_delete = 0;
  this->m_offset_to_file = 0;
  this->m_loaded_bytes = 0;
  this->m_quality_index = quality_index;
  this->m_query_end_guard = 1;
  this->m_flags = flags;
  this->m_observed_resource_destructions_left = 0;
  this->m_final_resource_size = 0;
  this->m_user_thread_id = user_thread_id;
  this->m_resource_for_grm_cache = 0;
  this->m_ready_to_retry_action_that_caused_out_of_memory = 1;
  this->m_on_created_resource_guard = 1;
  if ( disable_cache )
    vostok::threading::interlocked_or(&this->m_flags, (unsigned int)&vostok::memory::s_CRT_arena[55905848]);
  if ( query_type == query_type_helper_for_mount )
    vostok::threading::interlocked_or(&this->m_flags, 0x8000000u);
  if ( autoselect_quality == autoselect_quality_true )
    vostok::threading::interlocked_or(&this->m_flags, 0x10000000u);
  this->m_user_allocator = allocator;
  this->m_next_referer = this;
  this->m_target_satisfaction = target_satisfaction;
  vostok::threading::interlocked_or(&this->m_flags, (unsigned int)&loc_20000);
}
