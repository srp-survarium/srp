survarium::animations_registry::animations_tuple *__userpurge survarium::animations_registry::animations_tuple::operator=@<eax>(
        survarium::animations_registry::animations_tuple *this@<ecx>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *a2@<esi>,
        const survarium::animations_registry::animations_tuple *__that)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    &__that->first_view,
    a2);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    &__that->third_view,
    a2 + 1);
  a2[2].m_object = (vostok::resources::managed_resource *)__that->id;
  return (survarium::animations_registry::animations_tuple *)a2;
}
