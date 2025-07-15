void __thiscall vostok::animation::animation_collection::~animation_collection(
        vostok::animation::animation_collection *this)
{
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> > *p_m_animations; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // edi

  p_m_animations = &this->m_animations;
  this->__vftable = (vostok::animation::animation_collection_vtbl *)&vostok::animation::animation_collection::`vftable';
  for ( i = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_animations.m_begin;
        i != (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_animations->m_end;
        ++i )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  }
  p_m_animations->m_end = p_m_animations->m_begin;
  this->__vftable = (vostok::animation::animation_collection_vtbl *)&vostok::animation::animation_expression_emitter::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
