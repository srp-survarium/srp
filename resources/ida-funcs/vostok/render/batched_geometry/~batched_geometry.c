void __usercall vostok::render::batched_geometry<vostok::render::lpv_vertex>::~batched_geometry<vostok::render::lpv_vertex>(
        vostok::render::batched_geometry<vostok::render::lpv_vertex> *this@<ecx>,
        int a2@<esi>)
{
  vostok::buffer_vector<vostok::render::geometry_batch> *v2; // ecx

  *(_DWORD *)a2 = &vostok::render::batched_geometry<vostok::render::lpv_vertex>::`vftable';
  vostok::render::batched_geometry<vostok::render::lpv_vertex>::invalidate(this, (_DWORD *)a2);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&loc_162945 + a2 + 3));
  *(_DWORD *)(a2 + 1321256) = *(_DWORD *)(a2 + 1321252);
  *(_DWORD *)(a2 + 10524) = *(_DWORD *)(a2 + 10520);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 10480));
  `vector destructor iterator'(
    (char *)(a2 + 1168),
    0x48Cu,
    8,
    (void (__thiscall *)(void *))vostok::fixed_vector<vostok::render::geometry_batch,32>::~fixed_vector<vostok::render::geometry_batch,32>);
  vostok::buffer_vector<vostok::render::geometry_batch>::clear(v2, (int *)(a2 + 4));
}


void __usercall vostok::render::batched_geometry<vostok::render::shadow_vertex>::~batched_geometry<vostok::render::shadow_vertex>(
        vostok::render::batched_geometry<vostok::render::shadow_vertex> *this@<ecx>,
        int a2@<esi>)
{
  vostok::buffer_vector<vostok::render::geometry_batch> *v2; // ecx

  *(_DWORD *)a2 = &vostok::render::batched_geometry<vostok::render::shadow_vertex>::`vftable';
  vostok::render::batched_geometry<vostok::render::shadow_vertex>::invalidate(this, (_DWORD *)a2);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 2238792));
  *(_DWORD *)((char *)&loc_202924 + a2 + 4) = *(_DWORD *)((char *)&loc_202924 + a2);
  *(_DWORD *)(a2 + 10524) = *(_DWORD *)(a2 + 10520);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 10480));
  `vector destructor iterator'(
    (char *)(a2 + 1168),
    0x48Cu,
    8,
    (void (__thiscall *)(void *))vostok::fixed_vector<vostok::render::geometry_batch,32>::~fixed_vector<vostok::render::geometry_batch,32>);
  vostok::buffer_vector<vostok::render::geometry_batch>::clear(v2, (int *)(a2 + 4));
}
