void __thiscall vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_with_qualities,vostok::resources::unmanaged_intrusive_base>::unlink_with_parent_if_needed(
        vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *this)
{
  if ( this->m_parent )
  {
    this->m_parent->unlink_child_resource(this->m_parent, this->m_object);
    vostok::resources::resource_children::unlink_parent_resource(this->m_object, this->m_parent);
    this->m_parent = 0;
  }
}
