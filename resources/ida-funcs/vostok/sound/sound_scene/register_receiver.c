void __thiscall vostok::sound::sound_scene::register_receiver(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_receiver *receiver,
        vostok::sound::atomic_half3 *position)
{
  const vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::sound::compare_receivers_predicate> *v3; // eax
  vostok::sound::receiver_collision *v4; // eax
  vostok::collision::object *collision_object; // eax
  vostok::sound::receiver_collision *v6; // [esp+8h] [ebp-24Ch]
  vostok::math::float3 v8; // [esp+94h] [ebp-1C0h] BYREF
  char v9; // [esp+A3h] [ebp-1B1h]
  vostok::math::float3 *v10; // [esp+A4h] [ebp-1B0h]
  unsigned __int8 dst[64]; // [esp+A8h] [ebp-1ACh] BYREF
  vostok::collision::object *m_collision; // [esp+FCh] [ebp-158h]
  char v13; // [esp+103h] [ebp-151h]
  vostok::sound::receiver_collision *v14; // [esp+110h] [ebp-144h]
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *v15; // [esp+114h] [ebp-140h]
  char v16; // [esp+11Bh] [ebp-139h]
  void (__cdecl *f)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // [esp+11Ch] [ebp-138h]
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *v18; // [esp+120h] [ebp-134h]
  char v19; // [esp+127h] [ebp-12Dh]
  int v20; // [esp+128h] [ebp-12Ch]
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *m_variable; // [esp+12Ch] [ebp-128h]
  char v22; // [esp+133h] [ebp-121h]
  vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::sound::compare_receivers_predicate> v23; // [esp+134h] [ebp-120h] BYREF
  vostok::sound::receiver_collision *v24; // [esp+138h] [ebp-11Ch]
  int v25; // [esp+13Ch] [ebp-118h]
  vostok::math::float3 v26; // [esp+140h] [ebp-114h] BYREF
  vostok::math::float3 result; // [esp+14Ch] [ebp-108h] BYREF
  vostok::sound::receiver_collision *v28; // [esp+158h] [ebp-FCh]
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v29; // [esp+15Ch] [ebp-F8h] BYREF
  char v30; // [esp+183h] [ebp-D1h]
  vostok::math::float4x4 translation; // [esp+184h] [ebp-D0h] BYREF
  vostok::sound::compare_receivers_predicate pred; // [esp+1C8h] [ebp-8Ch] BYREF
  vostok::math::float4x4 local_to_world; // [esp+1CCh] [ebp-88h] BYREF
  vostok::sound::receiver_collision *new_receiver; // [esp+210h] [ebp-44h]
  vostok::math::float4x4 scale; // [esp+214h] [ebp-40h] BYREF

  v25 = 0;
  pred.m_receiver = receiver;
  boost::_bi::list1<vostok::fs_new::synchronous_device_interface &>::list1<vostok::fs_new::synchronous_device_interface &>(
    &v23,
    &pred);
  v24 = vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::find_if<vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::sound::compare_receivers_predicate>>(
          &this->m_receivers,
          v3);
  new_receiver = v24;
  v30 = 0;
  v22 = 0;
  m_variable = this->m_receiver_collisions_allocator.m_variable;
  v20 = 16 * m_variable->m_max_count;
  v19 = 0;
  v18 = this->m_receiver_collisions_allocator.m_variable;
  if ( v20 == 16 * v18->m_allocated_count )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", error) )
    {
      f = vostok::core::g_log_callback;
      v29.vtable = 0;
      boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        &v29,
        vostok::core::g_log_callback);
      v25 |= 1u;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v29,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_scene.cpp",
        0x341u,
        "void __thiscall vostok::sound::sound_scene::register_receiver(class vostok::sound::sound_receiver *,class vostok"
        "::sound::atomic_half3 *)",
        "sound:",
        error,
        "can't allocate receiver_collision, memory is full");
    }
    if ( (v25 & 1) != 0 )
    {
      v25 &= ~1u;
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v29);
    }
  }
  else
  {
    v16 = 0;
    v15 = this->m_receiver_collisions_allocator.m_variable;
    v14 = (vostok::sound::receiver_collision *)vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::malloc_impl(
                                                 v15,
                                                 0x10u);
    v28 = v14;
    if ( v14 )
    {
      vostok::sound::receiver_collision::receiver_collision(v28, receiver, position);
      v6 = v4;
    }
    else
    {
      v6 = 0;
    }
    new_receiver = v6;
    vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &this->m_receivers,
      v6,
      0);
    v13 = 0;
    m_collision = new_receiver->m_collision;
    v10 = vostok::math::aabb::extents(&m_collision->m_aabb, &result);
    memset(dst, 0, sizeof(dst));
    *(float *)dst = v10->x;
    *(float *)&dst[20] = v10->y;
    *(float *)&dst[40] = v10->z;
    *(float *)&dst[60] = FLOAT_1_0;
    qmemcpy((void *)&scale, dst, sizeof(scale));
    v9 = 0;
    vostok::math::half3_pod::operator vostok::math::float3(&new_receiver->m_position->m_data.m_val, &v8);
    v26 = v8;
    vostok::math::create_translation(&translation, &v26);
    vostok::math::operator*(&local_to_world, &scale, &translation);
    collision_object = vostok::sound::receiver_collision::get_collision_object(new_receiver);
    this->m_spatial_tree->insert(this->m_spatial_tree, collision_object, &local_to_world);
  }
}
