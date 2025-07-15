void __thiscall vostok::sound::encoded_sound_with_qualities::~encoded_sound_with_qualities(
        vostok::sound::encoded_sound_with_qualities *this)
{
  int v2; // ebp
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *v3; // esi

  this->__vftable = (vostok::sound::encoded_sound_with_qualities_vtbl *)&vostok::sound::encoded_sound_with_qualities::`vftable';
  v2 = 1;
  v3 = (vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *)&this->m_qualities[1];
  do
  {
    if ( v3->m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::unlink_with_parent_if_needed(
        (vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)this,
        v3);
      vostok::resources::resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::operator=(
        v3,
        0);
    }
    --v2;
    v3 -= 2;
  }
  while ( v2 >= 0 );
  `vector destructor iterator'(
    (char *)this->m_qualities,
    8u,
    2,
    (void (__thiscall *)(void *))vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::~child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
