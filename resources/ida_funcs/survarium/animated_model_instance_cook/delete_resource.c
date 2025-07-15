void __thiscall survarium::animated_model_instance_cook::delete_resource(
        survarium::animated_model_instance_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::animation::animation_player *v2; // ecx
  vostok::animation::animation_player *v3; // esi
  vostok::animation::mixing::n_ary_tree *v4; // ecx
  vostok::animation::mixing::n_ary_tree_intrusive_base *m_object; // ebx
  _BYTE *v6; // esi

  vostok::collision::delete_animated_object(
    (vostok::collision::animated_object *)resource[1].m_parent_resources.m_thread_id,
    &vostok::memory::g_resources_unmanaged_allocator);
  v3 = *(vostok::animation::animation_player **)&resource[1].m_parent_resources.gapC;
  if ( v3 )
  {
    vostok::animation::animation_player::reset(v2, v3, 1);
    vostok::animation::mixing::n_ary_tree::destroy(v4, (int)&v3->m_mixing_tree);
    m_object = v3->m_mixing_tree.m_reference_counter.m_object;
    if ( m_object )
      --m_object->m_reference_count;
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      (void *)v3);
  }
  v6 = __RTCastToVoid((void **)&resource->__vftable);
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  vostok::memory::g_resources_unmanaged_allocator.call_free(&vostok::memory::g_resources_unmanaged_allocator, v6);
}
