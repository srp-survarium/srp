void __thiscall vostok::vfs::query_notification_operation::query_hot_mount(
        vostok::vfs::query_notification_operation *this,
        bool only_update_size)
{
  const char *v2; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  const char *v4; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  const char *v6; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v7; // ecx
  survarium::game_camera *v8; // ecx
  survarium::game_camera *v9; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  const char *v11; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v12; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // ecx
  bool has_passed_filters; // al
  const char *v15; // eax
  const char *v16; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v17; // ecx
  vostok::vfs::base_node<1> *v18; // eax
  vostok::vfs::mount_result v19[2]; // [esp-8h] [ebp-1268h] BYREF
  int v20; // [esp+8h] [ebp-1258h]
  int v21; // [esp+Ch] [ebp-1254h]
  vostok::vfs::query_notification_operation *v22; // [esp+10h] [ebp-1250h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v23; // [esp+258h] [ebp-1008h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v24; // [esp+25Ch] [ebp-1004h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v25; // [esp+260h] [ebp-1000h] BYREF
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_on_node_hides; // [esp+374h] [ebp-EECh]
  unsigned __int64 file_size; // [esp+378h] [ebp-EE8h]
  char v28; // [esp+383h] [ebp-EDDh]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v29; // [esp+4A0h] [ebp-DC0h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v30; // [esp+4A4h] [ebp-DBCh]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v31; // [esp+4A8h] [ebp-DB8h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v32; // [esp+5C4h] [ebp-C9Ch]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v33; // [esp+5C8h] [ebp-C98h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v34; // [esp+5CCh] [ebp-C94h] BYREF
  bool m_out_of_memory; // [esp+5D3h] [ebp-C8Dh]
  vostok::platform_pointer_selector<vostok::memory::base_allocator,1>::helper *p_allocator; // [esp+5D4h] [ebp-C8Ch]
  vostok::platform_pointer_selector<vostok::fs_new::device_file_system_interface,1>::helper *p_device; // [esp+5D8h] [ebp-C88h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v38; // [esp+6F4h] [ebp-B6Ch]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v39; // [esp+6F8h] [ebp-B68h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v40; // [esp+6FCh] [ebp-B64h] BYREF
  vostok::platform_pointer_selector<vostok::vfs::vfs_mount,1>::helper *v41; // [esp+700h] [ebp-B60h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v42; // [esp+81Ch] [ebp-A44h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v43; // [esp+820h] [ebp-A40h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v44; // [esp+824h] [ebp-A3Ch] BYREF
  vostok::fs_new::path_string_impl *v45; // [esp+828h] [ebp-A38h]
  vostok::fs_new::path_string_impl *v46; // [esp+82Ch] [ebp-A34h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v47; // [esp+948h] [ebp-918h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v48; // [esp+94Ch] [ebp-914h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> other; // [esp+950h] [ebp-910h] BYREF
  vostok::platform_pointer_selector<vostok::vfs::vfs_mount,1>::helper *p_mount; // [esp+954h] [ebp-90Ch]
  int v51; // [esp+9BCh] [ebp-8A4h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v52; // [esp+9C4h] [ebp-89Ch] BYREF
  int v53; // [esp+9C8h] [ebp-898h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v54; // [esp+9D0h] [ebp-890h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v55; // [esp+9F0h] [ebp-870h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v56; // [esp+A10h] [ebp-850h] BYREF
  char v57; // [esp+A37h] [ebp-829h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v58; // [esp+A3Ch] [ebp-824h] BYREF
  int v59; // [esp+A40h] [ebp-820h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v60; // [esp+A48h] [ebp-818h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+A68h] [ebp-7F8h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v62; // [esp+A90h] [ebp-7D0h] BYREF
  int v63; // [esp+A94h] [ebp-7CCh]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v64; // [esp+AA0h] [ebp-7C0h] BYREF
  int v65; // [esp+AA4h] [ebp-7BCh]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v66; // [esp+AB0h] [ebp-7B0h] BYREF
  int v67; // [esp+AB4h] [ebp-7ACh]
  vostok::fs_new::native_path_string v68; // [esp+ABCh] [ebp-7A4h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v69; // [esp+BD4h] [ebp-68Ch] BYREF
  int v70; // [esp+BD8h] [ebp-688h]
  vostok::vfs::vfs_iterator v71; // [esp+BE0h] [ebp-680h] BYREF
  __int64 v72; // [esp+BF0h] [ebp-670h]
  int value; // [esp+BF8h] [ebp-668h]
  volatile int *target; // [esp+BFCh] [ebp-664h]
  vostok::vfs::base_node<1> *node; // [esp+C00h] [ebp-660h]
  stlp_std::pair<vostok::vfs::overlapped_node_initializer,vostok::vfs::overlapped_node_initializer> result; // [esp+C04h] [ebp-65Ch] BYREF
  vostok::fs_new::synchronous_device_interface sync_device; // [esp+C24h] [ebp-63Ch] BYREF
  vostok::vfs::overlapped_node_iterator it_end; // [esp+C30h] [ebp-630h] BYREF
  vostok::vfs::query_mount_arguments args; // [esp+C40h] [ebp-620h] BYREF
  vostok::vfs::overlapped_node_iterator it; // [esp+1118h] [ebp-148h] BYREF
  vostok::fs_new::physical_path_info v81; // [esp+1128h] [ebp-138h] BYREF

  v22 = this;
  v51 = 0;
  if ( vostok::vfs::query_notification_operation::try_convert_to_virtual_path(this, this->m_physical_path) )
  {
    v19[0].result = result_error;
    v2 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v22->m_virtual_path);
    vostok::vfs::vfs_hashset::equal_range(&v22->m_file_system->hashset, &result, v2, lock_type_read);
    vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it, &result.first);
    vostok::vfs::overlapped_node_iterator::overlapped_node_iterator(&it_end, &result.second);
    node = vostok::vfs::query_notification_operation::find_node_on_virtual_path(v22, &it, &it_end);
    if ( only_update_size && !node )
    {
      p_mount = &v22->m_mount_root->mount;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &other,
        p_mount->pointer);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v69,
        &other);
      v70 = 1;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&other);
      v47 = &v69;
      v48 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v19;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v19[0].mount,
        &v69);
      v48[1].m_object = v47[1].m_object;
      boost::function1<void,vostok::vfs::mount_result>::operator()(
        &v22->m_callback->boost::function1<void,vostok::vfs::mount_result>,
        v19[0]);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v69);
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      return;
    }
    if ( !node )
      goto LABEL_10;
    v45 = &v22->m_physical_path->vostok::fs_new::path_string_impl;
    v46 = vostok::vfs::get_node_physical_path<vostok::vfs::base_node,1>(&v68, node);
    if ( !vostok::fs_new::path_string_impl::operator==(v46, v45) )
    {
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v44,
        &v22->m_mount);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v66,
        &v44);
      v67 = 0;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v44);
      v42 = &v66;
      v43 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v19;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v19[0].mount,
        &v66);
      v43[1].m_object = v42[1].m_object;
      boost::function1<void,vostok::vfs::mount_result>::operator()(
        &v22->m_callback->boost::function1<void,vostok::vfs::mount_result>,
        v19[0]);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v66);
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      return;
    }
    if ( (node->m_flags & 1) == 1 )
    {
      v41 = &v22->m_mount_root->mount;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v40,
        v41->pointer);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v64,
        &v40);
      v65 = 1;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v40);
      v38 = &v64;
      v39 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v19;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v19[0].mount,
        &v64);
      v39[1].m_object = v38[1].m_object;
      boost::function1<void,vostok::vfs::mount_result>::operator()(
        &v22->m_callback->boost::function1<void,vostok::vfs::mount_result>,
        v19[0]);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v64);
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
      vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
    }
    else
    {
LABEL_10:
      p_device = &v22->m_mount_root->device;
      p_allocator = &v22->m_mount_root->allocator;
      vostok::fs_new::synchronous_device_interface::synchronous_device_interface(
        &sync_device,
        v22->m_mount_root->async_device.pointer,
        p_allocator->pointer,
        p_device->pointer,
        v22->m_mount_root->watcher_enabled);
      m_out_of_memory = sync_device.m_out_of_memory;
      if ( sync_device.m_out_of_memory )
      {
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          &v34,
          0);
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          &v62,
          &v34);
        v63 = 3;
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v34);
        v32 = &v62;
        v33 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v19;
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          &v19[0].mount,
          &v62);
        v33[1].m_object = v32[1].m_object;
        boost::function1<void,vostok::vfs::mount_result>::operator()(
          &v22->m_callback->boost::function1<void,vostok::vfs::mount_result>,
          v19[0]);
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v62);
        vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&sync_device);
        vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
        vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
      }
      else
      {
        vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(
          &sync_device.m_device,
          &v81,
          v22->m_physical_path);
        if ( v81.data.type )
        {
          if ( node )
          {
            target = (volatile int *)vostok::vfs::cast_physical_file<1>(node);
            v57 = 0;
            survarium::weapon_user_dead_state::finalize(v8);
            v28 = 0;
            survarium::weapon_user_dead_state::finalize(v9);
            file_size = v81.data.file_size;
            value = v81.data.file_size;
            v72 = vostok::threading::interlocked_exchange_pointer(target, v81.data.file_size);
            p_on_node_hides = (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v22->m_file_system->on_node_hides;
            if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(p_on_node_hides)
                ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
                : 0) != 0 )
            {
              vostok::vfs::vfs_iterator::vfs_iterator(&v71, node, 0, &v22->m_file_system->hashset, type_non_recursive);
              boost::function1<void,vostok::ai::sensors::sensed_object const &>::operator()(
                (boost::function1<void,vostok::ai::sensors::sensed_object const &> *)&v22->m_file_system->on_node_hides,
                (const vostok::ai::sensors::sensed_object *)&v71);
            }
            if ( !only_update_size )
            {
              if ( !vostok::core::g_log_filter_tree
                || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "watcher:", info) )
              {
                boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v10);
                v51 |= 4u;
                v19[0].result = value;
                v11 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v22->m_physical_path);
                vostok::logging::append(
                  &v56,
                  (void *const)vostok::core::g_log_flags,
                  &vostok::core::g_log_format,
                  ".\\handle_notifications.cpp",
                  0xE2u,
                  "void __thiscall vostok::vfs::query_notification_operation::query_hot_mount(bool)",
                  "watcher:",
                  info,
                  "hot_mount '%s' already mounted, only updating size",
                  v11);
              }
              v12 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v51 & 4);
              if ( (v51 & 4) != 0 )
              {
                v51 &= ~4u;
                boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(v12);
              }
            }
            v20 = value;
            v21 = 0;
            v13 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v72;
            if ( v72 == value )
            {
              if ( !vostok::core::g_log_filter_tree
                || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "watcher:", info) )
              {
                boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v13);
                v51 |= 0x10u;
                v19[0].result = value;
                v16 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v22->m_physical_path);
                vostok::logging::append(
                  &v54,
                  (void *const)vostok::core::g_log_flags,
                  &vostok::core::g_log_format,
                  ".\\handle_notifications.cpp",
                  0xE7u,
                  "void __thiscall vostok::vfs::query_notification_operation::query_hot_mount(bool)",
                  "watcher:",
                  info,
                  "no need of updating size for '%s' (%db)",
                  v16,
                  v19[0].result);
              }
              v17 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v51 & 0x10);
              if ( (v51 & 0x10) != 0 )
              {
                v51 &= ~0x10u;
                boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(v17);
              }
            }
            else
            {
              if ( !vostok::core::g_log_filter_tree
                || (has_passed_filters = vostok::logging::has_passed_filters(
                                           vostok::core::g_log_filter_tree,
                                           "watcher:",
                                           info),
                    (v13 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)has_passed_filters) != 0) )
              {
                boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v13);
                v51 |= 8u;
                v19[0].result = value;
                v15 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v22->m_physical_path);
                vostok::logging::append(
                  &v55,
                  (void *const)vostok::core::g_log_flags,
                  &vostok::core::g_log_format,
                  ".\\handle_notifications.cpp",
                  0xE5u,
                  "void __thiscall vostok::vfs::query_notification_operation::query_hot_mount(bool)",
                  "watcher:",
                  info,
                  "updated size of '%s' to (%db)",
                  v15,
                  v19[0].result);
              }
              if ( (v51 & 8) != 0 )
              {
                v51 &= ~8u;
                boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>((boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v13);
              }
            }
            vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
              &v25,
              &v22->m_mount);
            vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
              &v52,
              &v25);
            v53 = 1;
            vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v25);
            v23 = &v52;
            v24 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v19;
            vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
              &v19[0].mount,
              &v52);
            v24[1].m_object = v23[1].m_object;
            boost::function1<void,vostok::vfs::mount_result>::operator()(
              &v22->m_callback->boost::function1<void,vostok::vfs::mount_result>,
              v19[0]);
            vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v52);
            vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&sync_device);
            vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
            vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
          }
          else
          {
            vostok::vfs::overlapped_node_iterator::clear(&it);
            if ( vostok::vfs::query_notification_operation::try_write_lock(v22) )
            {
              vostok::vfs::query_mount_arguments::query_mount_arguments(&args);
              v19[0].result = (vostok::vfs::result_enum)v22->m_physical_path;
              v19[0].mount.m_object = (vostok::vfs::vfs_mount *)4;
              v18 = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_root_node_base,1>(v22->m_mount_root);
              vostok::vfs::query_notification_operation::fill_mount_arguments(
                v22,
                &args,
                &sync_device,
                v18,
                submount_type_hot_mount,
                (const vostok::fs_new::native_path_string *)v19[0].result);
              vostok::vfs::virtual_file_system::query_mount(v22->m_file_system, &args);
              boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&args.callback);
            }
            vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&sync_device);
            vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
            vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
          }
        }
        else
        {
          v3 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)only_update_size;
          if ( only_update_size )
          {
            if ( !vostok::core::g_log_filter_tree
              || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "watcher:", info) )
            {
              boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v3);
              v51 |= 1u;
              v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v22->m_physical_path);
              vostok::logging::append(
                &log_callback,
                (void *const)vostok::core::g_log_flags,
                &vostok::core::g_log_format,
                ".\\handle_notifications.cpp",
                0xCCu,
                "void __thiscall vostok::vfs::query_notification_operation::query_hot_mount(bool)",
                "watcher:",
                info,
                "no file to update file size: '%s'",
                v4);
            }
            v5 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v51 & 1);
            if ( (v51 & 1) != 0 )
            {
              v51 &= ~1u;
              boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(v5);
            }
          }
          else
          {
            if ( !vostok::core::g_log_filter_tree
              || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "watcher:", info) )
            {
              boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v3);
              v51 |= 2u;
              v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v22->m_physical_path);
              vostok::logging::append(
                &v60,
                (void *const)vostok::core::g_log_flags,
                &vostok::core::g_log_format,
                ".\\handle_notifications.cpp",
                0xCEu,
                "void __thiscall vostok::vfs::query_notification_operation::query_hot_mount(bool)",
                "watcher:",
                info,
                "no file to hot mount: '%s'",
                v6);
            }
            v7 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v51 & 2);
            if ( (v51 & 2) != 0 )
            {
              v51 &= ~2u;
              boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(v7);
            }
          }
          vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
            &v31,
            &v22->m_mount);
          vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
            &v58,
            &v31);
          v59 = 1;
          vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v31);
          v29 = &v58;
          v30 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v19;
          vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
            &v19[0].mount,
            &v58);
          v30[1].m_object = v29[1].m_object;
          boost::function1<void,vostok::vfs::mount_result>::operator()(
            &v22->m_callback->boost::function1<void,vostok::vfs::mount_result>,
            v19[0]);
          vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v58);
          vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(&sync_device);
          vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it_end);
          vostok::vfs::overlapped_node_iterator::~overlapped_node_iterator(&it);
        }
      }
    }
  }
}
