vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *__userpurge vostok::animation::mixing::animation_interval::`scalar deleting destructor'@<eax>(
        vostok::animation::mixing::animation_interval *this@<ecx>,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *a2@<esi>,
        char a3)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(a2);
  if ( (a3 & 1) != 0 )
    operator delete(a2);
  return a2;
}
