void __thiscall vostok::logging::log_file::log_file(
        vostok::logging::log_file *this,
        vostok::memory::base_allocator *allocator,
        vostok::logging::log_file_usage_enum log_file_usage,
        const char *file_name,
        vostok::fs_new::device_file_system_no_watcher_proxy device)
{
  vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *v5; // ecx
  survarium::game_camera *v6; // ecx
  void *v7; // eax
  vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *v8; // ecx
  vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *v9; // ecx
  survarium::game_camera *v10; // ecx
  vostok::fixed_vector<int,4096> *v12; // [esp+Ch] [ebp-170h]
  int v13; // [esp+3Ch] [ebp-140h] BYREF
  vostok::fixed_vector<int,4096> *v14; // [esp+40h] [ebp-13Ch]
  vostok::fs_new::native_path_string physical_path; // [esp+44h] [ebp-138h] BYREF
  char v16; // [esp+15Bh] [ebp-21h]
  void **file; // [esp+15Ch] [ebp-20h] BYREF
  vostok::fs_new::open_file_params params; // [esp+160h] [ebp-1Ch] BYREF
  vostok::fs_new::file_mode::mode_enum mode; // [esp+178h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_file = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_device);
  this->m_device.m_synchronize_query = 0;
  this->m_device.m_device = device;
  this->m_device.m_out_of_memory = 0;
  vostok::fs_new::native_path_string::native_path_string(&this->m_file_name);
  vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::uninitialized_reference<vostok::fixed_vector<int,4096>>(
    v5,
    this->m_line_groups.m_static_memory);
  vostok::threading::mutex::mutex(&this->m_log_mutex);
  this->m_allocator = allocator;
  this->m_transaction_thread_id = -1;
  v16 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)allocator);
  vostok::fs_new::path_string_impl::operator=<char const *>(&this->m_file_name, (char **)&file_name);
  mode = log_file_usage != create_log ? append_or_create : create_always;
  vostok::fs_new::create_folder_r(&this->m_device, file_name, 0);
  file = (void **)this->m_file_pointer_storage;
  params.mode = mode;
  params.access = read_write;
  params.assert_on_fail = assert_on_fail_false;
  params.notify_watcher = notify_watcher_true;
  params.use_buffering = use_buffering_true;
  params.file_type_allocated_by_user = 1;
  vostok::fs_new::native_path_string::native_path_string(&physical_path, &file_name);
  if ( vostok::fs_new::device_file_system_no_watcher_proxy::open(
         &this->m_device.m_device,
         &file,
         &physical_path,
         &params) )
  {
    vostok::threading::interlocked_exchange_pointer((volatile int *)&this->m_file, (int)file);
  }
  survarium::weapon_user_dead_state::finalize(v6);
  v14 = (vostok::fixed_vector<int,4096> *)operator new(0x4008u, v7);
  if ( v14 )
    vostok::fixed_vector<int,4096>::fixed_vector<int,4096>(v14);
  vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::operator+(
    v8,
    (int)this->m_line_groups.m_static_memory);
  v13 = 0;
  v12 = vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::operator->(
          v9,
          (int)this->m_line_groups.m_static_memory);
  survarium::weapon_user_dead_state::finalize(v10);
  vostok::buffer_vector<int>::construct(v12->m_end, &v13);
  ++v12->m_end;
  this->m_last_line = 0;
  this->m_file_size = 0;
  this->m_cache_start = -1;
  this->m_cache_size = 0;
  this->m_current_pos = 0;
}
