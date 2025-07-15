boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *__userpurge vostok::render::grass_world::add_instance@<eax>(
        vostok::render::grass_world *this@<ecx>,
        _DWORD *a2@<eax>,
        const unsigned int in_template_id,
        const vostok::math::color *in_color,
        const vostok::math::float4x4 *in_transform,
        char in_layer,
        float in_wind_scale)
{
  vostok::memory::single_size_buffer_allocator<92,vostok::threading::single_threading_policy>::node *v7; // ecx
  vostok::memory::single_size_buffer_allocator<92,vostok::threading::single_threading_policy>::node *v8; // ebx
  _DWORD *v9; // esi
  vostok::memory::single_size_buffer_allocator<92,vostok::threading::single_threading_policy>::node *v10; // eax
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v12; // [esp+14h] [ebp+8h]

  v7 = (vostok::memory::single_size_buffer_allocator<92,vostok::threading::single_threading_policy>::node *)a2[67];
  v8 = 0;
  while ( v7 != (vostok::memory::single_size_buffer_allocator<92,vostok::threading::single_threading_policy>::node *)a2[68] )
  {
    if ( *(_DWORD *)&v7->data[32] == in_template_id )
    {
      v8 = v7;
      break;
    }
    v7 = (vostok::memory::single_size_buffer_allocator<92,vostok::threading::single_threading_policy>::node *)((char *)v7 + 36);
  }
  g_instance_counter = (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)((char *)g_instance_counter + 1);
  v9 = a2 + 70;
  v12 = g_instance_counter;
  if ( a2[79] >= a2[80] && (*v9 != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      g_instance_counter,
      v9,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)v9);
  v10 = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<92,vostok::threading::single_threading_policy>::node>::allocate(
          (vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<92,vostok::threading::single_threading_policy>::node>::free_list_type *)v9
        + 8);
  ++v9[9];
  if ( v10 )
  {
    *(_DWORD *)&v10->data[4] = 0;
    *(_DWORD *)&v10->data[8] = 0;
    v10->next = v8;
    qmemcpy(&v10->data[12], in_transform, 0x40u);
    *(float *)&v10->data[76] = in_wind_scale;
    *(vostok::math::color *)&v10->data[80] = *in_color;
    *(_DWORD *)&v10->data[84] = v12;
    v10->data[88] = in_layer;
  }
  else
  {
    v10 = 0;
  }
  *(_DWORD *)&v10->data[4] = 0;
  ++v8->next;
  if ( *(_DWORD *)&v8->data[8] )
    *(_DWORD *)(*(_DWORD *)&v8->data[12] + 4) = v10;
  else
    *(_DWORD *)&v8->data[8] = v10;
  *(_DWORD *)&v8->data[12] = v10;
  return v12;
}
