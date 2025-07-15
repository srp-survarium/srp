void __userpurge vostok::logging::log_file::log_file(
        vostok::logging::log_file *this@<edi>,
        vostok::threading::mutex_tasks_unaware *log_file_usage@<ecx>,
        vostok::logging::base_fs_device *device@<eax>,
        vostok::logging::base_allocator *allocator,
        char *file_name)
{
  unsigned int v6; // kr00_4
  char *v7; // eax
  vostok::logging::base_fs_file *v8; // eax
  vostok::buffer_vector<int> *v9; // ecx
  int value; // [esp+Ch] [ebp-4h] BYREF

  this->m_device = device;
  this->m_file = 0;
  this->m_line_groups.m_begin = (int *)this->m_line_groups.m_buffer;
  this->m_line_groups.m_end = (int *)this->m_line_groups.m_buffer;
  this->m_line_groups.m_max_end = (int *)&this->m_log_mutex;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    log_file_usage,
    (_RTL_CRITICAL_SECTION *)&this->m_log_mutex);
  LODWORD(this->m_cache_start) = -1;
  this->m_transaction_thread_id = -1;
  this->m_transaction_entered_count = 0;
  this->m_last_line = 0;
  this->m_current_pos = 0;
  HIDWORD(this->m_cache_start) = 0;
  this->m_file_size = 0;
  this->m_cache_size = 0;
  this->m_allocator = allocator;
  v6 = strlen(file_name);
  v7 = (char *)allocator->allocate(allocator, v6 + 1);
  this->m_file_name = v7;
  vostok::strings::copy(v7, v6 + 1, file_name);
  this->m_device->create_folder_r(this->m_device, file_name, dont_create_last);
  v8 = this->m_device->open_file(
         this->m_device,
         this->m_file_name,
         log_file_usage != (vostok::threading::mutex_tasks_unaware *)1 ? append_or_create_mode : create_always_mode,
         read_write_access);
  if ( v8 )
    v9 = (vostok::buffer_vector<int> *)_InterlockedExchange((volatile __int32 *)&this->m_file, (__int32)v8);
  value = 0;
  vostok::buffer_vector<int>::push_back(v9, (int)&this->m_line_groups, &value);
}
