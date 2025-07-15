void __userpurge vostok::resources::query_result::on_refered_query_ended(
        vostok::resources::query_result *refered_query@<eax>,
        vostok::resources::query_result *this)
{
  vostok::resources::query_result *v3; // ecx
  int v4; // eax
  bool v5; // al
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::resources::query_result *v7; // [esp-4h] [ebp-14h]
  vostok::resources::query_result_for_cook *v8; // [esp-4h] [ebp-14h]
  vostok::resources::query_result_for_user::error_type_enum v9; // [esp+0h] [ebp-10h]

  this->m_error_type = refered_query->m_error_type;
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    &refered_query->m_raw_managed_resource,
    &this->m_raw_managed_resource);
  this->m_raw_unmanaged_buffer = refered_query->m_raw_unmanaged_buffer;
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    &refered_query->m_managed_resource,
    &this->m_managed_resource);
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&refered_query->m_unmanaged_resource,
    &this->m_unmanaged_resource);
  vostok::resources::query_result::set_create_resource_result(
    (vostok::resources::query_result *)refered_query->m_create_resource_result,
    this,
    (vostok::resources::cook_base::result_enum)refered_query->m_error_type,
    v9);
  _InterlockedOr(&this->m_flags, 0x2000u);
  vostok::resources::query_result::clear_reference(this);
  if ( refered_query->m_error_type )
    goto LABEL_10;
  v4 = vostok::resources::cook_base::reuse_type(this->m_class_id);
  v3 = v7;
  if ( v4 != 2 )
  {
    _InterlockedOr(&this->m_flags, (unsigned int)&loc_3FFFF + 1);
LABEL_10:
    vostok::resources::query_result::end_query_might_destroy_this(v3, (int)this);
    return;
  }
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    &this->m_unmanaged_resource,
    0);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    &this->m_managed_resource,
    0);
  v5 = vostok::resources::cook_base::cooks_inplace(this->m_class_id);
  v6 = v8;
  if ( v5 )
  {
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
      &this->m_raw_managed_resource,
      0);
    v6 = 0;
    this->m_raw_unmanaged_buffer.m_data = 0;
    this->m_raw_unmanaged_buffer.m_size = 0;
  }
  if ( this->m_raw_managed_resource.m_object || this->m_raw_unmanaged_buffer.m_data )
  {
    _InterlockedOr(&this->m_flags, (unsigned int)&loc_7FFFE + 2);
    vostok::resources::query_result::prepare_final_resource(
      (vostok::resources::query_result *)((char *)&loc_7FFFE + 2),
      this);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v6,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)this,
      result_cannot_lock,
      assert_on_fail_true,
      result_fail);
  }
}
