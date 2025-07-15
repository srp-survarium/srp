void __thiscall vostok::resources::query_result::do_managed_create_resource(
        vostok::resources::query_result *this,
        vostok::resources::query_result *cook,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> a3)
{
  vostok::resources::managed_resource *m_object; // ebx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_managed_resource; // edi
  vostok::resources::managed_resource *v5; // eax
  vostok::resources::query_result *v6; // ecx
  vostok::resources::managed_resource *v7; // ecx
  vostok::resources::managed_resource *v8; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v9[4]; // [esp-4h] [ebp-1Ch] BYREF
  vostok::resources::query_result_for_cook *v10; // [esp+Ch] [ebp-Ch] BYREF
  void (__thiscall *v11)(vostok::resources::query_result_for_cook *, vostok::resources::query_result *, vostok::resources::managed_resource *); // [esp+10h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v12; // [esp+14h] [ebp-4h]

  m_object = a3.m_object;
  p_m_managed_resource = &cook->m_managed_resource;
  v5 = cook->m_managed_resource.m_object;
  v12 = &cook->m_managed_resource;
  vostok::resources::query_result::set_is_unmovable_if_needed(v5, 1);
  if ( vostok::resources::query_result::need_create_resource_if_no_file(
         (vostok::resources::query_result *)v9[0].m_object,
         cook) )
  {
    ((void (__thiscall *)(vostok::resources::managed_resource *, vostok::resources::query_result_for_cook **))m_object->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable[1].~vostok::resources::resource_base)(
      m_object,
      &v10);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      &a3,
      p_m_managed_resource);
    v9[0].m_object = v7;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      v9,
      &a3);
    v11(v10, cook, v9[0].m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&a3);
  }
  else
  {
    vostok::resources::query_result::pin_raw_file(v6, &v10, cook);
    v9[0].m_object = v8;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      v9,
      p_m_managed_resource);
    ((void (__thiscall *)(vostok::resources::managed_resource *, vostok::resources::query_result *, vostok::resources::query_result_for_cook *, void (__thiscall *)(vostok::resources::query_result_for_cook *, vostok::resources::query_result *, vostok::resources::managed_resource *), vostok::resources::managed_resource *))m_object->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable[1].link_child_resource)(
      m_object,
      cook,
      v10,
      v11,
      v9[0].m_object);
    vostok::resources::query_result::unpin_raw_file((vostok::resources::query_result *)&v10, (int)cook);
  }
  vostok::resources::query_result::set_is_unmovable_if_needed(v12->m_object, 0);
}
