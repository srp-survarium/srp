void __usercall vostok::resources::query_result_for_cook::set_managed_resource(
        vostok::resources::query_result_for_cook *this@<esi>,
        vostok::resources::managed_resource *ptr@<eax>)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v3; // [esp+0h] [ebp-4h] BYREF

  v3.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v3,
    ptr);
  m_object = v3.m_object;
  v3.m_object = this->m_managed_resource.m_object;
  this->m_managed_resource.m_object = m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v3);
}
