void __thiscall vostok::render::batched_geometry<vostok::render::lpv_vertex>::invalidate(
        vostok::render::batched_geometry<vostok::render::lpv_vertex> *this,
        _DWORD *a2)
{
  int *v3; // edi
  int v4; // ebp
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v5; // ecx
  int i; // [esp+14h] [ebp+4h]

  v3 = a2 + 1;
  v4 = a2[1];
  for ( i = a2[2]; v4 != i; v4 += 36 )
  {
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v4 + 28),
      0);
    vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
      v5,
      (vostok::particle::particle_system_instance_impl **)(v4 + 24));
  }
  vostok::buffer_vector<vostok::render::geometry_batch>::clear(
    (vostok::buffer_vector<vostok::render::geometry_batch> *)this,
    v3);
  a2[330314] = a2[330313];
  a2[2631] = a2[2630];
}


void __thiscall vostok::render::batched_geometry<vostok::render::shadow_vertex>::invalidate(
        vostok::render::batched_geometry<vostok::render::shadow_vertex> *this,
        _DWORD *a2)
{
  int *v3; // edi
  int v4; // ebp
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v5; // ecx
  int i; // [esp+14h] [ebp+4h]

  v3 = a2 + 1;
  v4 = a2[1];
  for ( i = a2[2]; v4 != i; v4 += 36 )
  {
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v4 + 28),
      0);
    vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
      v5,
      (vostok::particle::particle_system_instance_impl **)(v4 + 24));
  }
  vostok::buffer_vector<vostok::render::geometry_batch>::clear(
    (vostok::buffer_vector<vostok::render::geometry_batch> *)this,
    v3);
  *(_DWORD *)((char *)&loc_202924 + (_DWORD)a2 + 4) = *(_DWORD *)((char *)&loc_202924 + (_DWORD)a2);
  a2[2631] = a2[2630];
}
