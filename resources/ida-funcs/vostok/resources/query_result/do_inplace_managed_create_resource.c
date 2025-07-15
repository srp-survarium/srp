void __thiscall vostok::resources::query_result::do_inplace_managed_create_resource(
        vostok::resources::query_result *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *cook,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> a3)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v4; // edi
  vostok::resources::managed_resource *m_object; // eax
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::resources::managed_resource *v7; // ecx
  vostok::resources::managed_resource *v8; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v9; // [esp-Ch] [ebp-24h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v10; // [esp-8h] [ebp-20h] BYREF
  vostok::resources::query_result *v11; // [esp-4h] [ebp-1Ch]
  _DWORD v12[2]; // [esp+10h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *object; // [esp+20h] [ebp+8h]

  v4 = cook + 162;
  m_object = cook[162].m_object;
  object = cook + 162;
  vostok::resources::query_result::set_is_unmovable_if_needed(m_object, 1);
  if ( vostok::resources::query_result::need_create_resource_if_no_file(v11, cook) )
  {
    ((void (__thiscall *)(vostok::resources::managed_resource *, _DWORD *))a3.m_object->__vftable[1].~vostok::resources::resource_base)(
      a3.m_object,
      v12);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      &a3,
      v4);
    v11 = (vostok::resources::query_result *)&cook[178];
    v10.m_object = v7;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      &v10,
      &a3);
    ((void (__thiscall *)(_DWORD, vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *, vostok::resources::managed_resource *, vostok::resources::query_result *))v12[1])(
      v12[0],
      cook,
      v10.m_object,
      v11);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&a3);
  }
  else
  {
    v11 = (vostok::resources::query_result *)&cook[178];
    v10.m_object = (vostok::resources::managed_resource *)vostok::resources::query_result_for_cook::get_raw_file_size(
                                                            v6,
                                                            cook);
    v9.m_object = v8;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      &v9,
      v4);
    ((void (__thiscall *)(vostok::resources::managed_resource *, vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *, vostok::resources::managed_resource *, vostok::resources::managed_resource *, vostok::resources::query_result *))a3.m_object->__vftable[1].link_child_resource)(
      a3.m_object,
      cook,
      v9.m_object,
      v10.m_object,
      v11);
  }
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    object,
    cook + 54);
  vostok::resources::query_result::set_is_unmovable_if_needed(object->m_object, 0);
}
