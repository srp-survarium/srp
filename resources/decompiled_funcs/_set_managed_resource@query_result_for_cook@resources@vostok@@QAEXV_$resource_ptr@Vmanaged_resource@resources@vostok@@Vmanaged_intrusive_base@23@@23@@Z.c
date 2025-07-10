void __thiscall vostok::resources::query_result_for_cook::set_managed_resource(
        vostok::resources::query_result_for_cook *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::resources::managed_resource *v3; // edx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v4; // [esp+4h] [ebp-4h] BYREF

  m_object = 0;
  if ( ptr.m_object )
  {
    m_object = ptr.m_object;
    _InterlockedExchangeAdd(&ptr.m_object->m_reference_count, 1u);
  }
  v3 = this->m_managed_resource.m_object;
  this->m_managed_resource.m_object = m_object;
  v4.m_object = v3;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v4);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&ptr);
}
