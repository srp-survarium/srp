void __userpurge vostok::render::decal_instance::set_materail_effects(
        vostok::render::decal_instance *this@<ecx>,
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<eax>,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *in_ptr)
{
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v3; // esi
  char *other; // [esp+4h] [ebp-118h] BYREF
  vostok::fs_new::virtual_path_string in_material_name; // [esp+8h] [ebp-114h] BYREF

  v3 = a2 + 17;
  vostok::render::material_manager::remove_material_effects(
    (vostok::render::material_manager *)this,
    (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    v3,
    in_ptr);
  other = (char *)LODWORD(v3->m_object[4].m_last_fail_of_increasing_quality);
  vostok::fs_new::virtual_path_string::virtual_path_string(&in_material_name, (const char **)&other);
  vostok::render::material_manager::add_material_effects(
    (vostok::render::material_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y,
    (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)v3,
    &in_material_name);
}
