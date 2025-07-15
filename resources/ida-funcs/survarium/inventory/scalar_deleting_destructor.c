survarium::inventory *__thiscall survarium::inventory::`scalar deleting destructor'(
        survarium::inventory *this,
        char a2)
{
  `vector destructor iterator'(
    (char *)&this->m_slots,
    4u,
    23,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
