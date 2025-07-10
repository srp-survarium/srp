vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *__thiscall vostok::resources::query_result_for_user::get_managed_resource(
        vostok::resources::query_result_for_user *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *result)
{
  result->m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    result,
    &this->m_managed_resource);
  return result;
}
