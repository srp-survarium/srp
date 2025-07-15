fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)> *__thiscall vostok::resources::unmanaged_cook::get_create_resource_if_no_file_delegate(
        vostok::resources::managed_cook *this,
        fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)> *result)
{
  fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)> *v2; // eax

  v2 = result;
  result->m_Closure.m_pFunction = 0;
  result->m_Closure.m_pthis = 0;
  return v2;
}
