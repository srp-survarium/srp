void __userpurge survarium::animation_space_vertex::animation_space_vertex(
        survarium::animation_space_vertex *this@<edi>,
        vostok::resources::managed_resource *animation_vertex@<eax>,
        const char *animation_caption)
{
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v3; // ecx
  const unsigned __int8 *v4; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v5; // [esp-4h] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+8h] [ebp-10h] BYREF
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> v7; // [esp+Ch] [ebp-Ch] BYREF

  v5.m_object = animation_vertex;
  this->animation.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &this->animation,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)v5.m_object);
  vostok::fs_new::virtual_path_string::virtual_path_string(&this->caption, &animation_caption);
  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    &this->animation);
  v5.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v5,
    &object);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v3,
    &v7.m_resource,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v5.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  v4 = &v7.m_data[*((_DWORD *)v7.m_data + 5)];
  this->length = (float)(*(float *)&v4[20 * *(_DWORD *)v4 - 4 + *((_DWORD *)v4 + 1)]
                       - *(float *)&v4[16 * *(_DWORD *)v4 + *((_DWORD *)v4 + 1)])
               * 0.033333335;
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>(&v7);
  this->group_id = -1;
  this->intervals_count = -1;
}
