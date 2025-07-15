void __thiscall vostok::render::grass_patch::grass_patch(
        vostok::render::grass_patch *this,
        const vostok::render::grass_patch *__that,
        int a3)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &__that->m_movement_rt,
    (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a3);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &__that->m_movement_texture,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a3 + 4));
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &__that->m_instance_vb,
    (const vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a3 + 8));
  __that->m_instances.m_size = 0;
  __that->m_instances.m_first = 0;
  __that->m_instances.m_last = 0;
  `vector copy constructor iterator'(
    (char *)__that->m_geometry,
    (char *)(a3 + 28),
    4u,
    3,
    (void *(__thiscall *)(void *, void *))vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
  `vector copy constructor iterator'(
    (char *)__that->m_vb_stream_1,
    (char *)(a3 + 40),
    4u,
    3,
    (void *(__thiscall *)(void *, void *))vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
  __that->m_merged_indices[0] = *(unsigned __int16 **)(a3 + 52);
  __that->m_merged_indices[1] = *(unsigned __int16 **)(a3 + 56);
  __that->m_merged_indices[2] = *(unsigned __int16 **)(a3 + 60);
  __that->m_sort_info[0] = *(vostok::render::grass_patch::sort_info **)(a3 + 64);
  __that->m_sort_info[1] = *(vostok::render::grass_patch::sort_info **)(a3 + 68);
  __that->m_sort_info[2] = *(vostok::render::grass_patch::sort_info **)(a3 + 72);
  __that->m_template = *(vostok::render::grass_template **)(a3 + 76);
  __that->m_collision_tree = *(vostok::collision::space_partitioning_tree *const *)(a3 + 80);
  __that->m_collision_geometry = *(vostok::collision::geometry_instance **)(a3 + 84);
  __that->m_collision_object = *(vostok::collision::object **)(a3 + 88);
  qmemcpy(&__that->m_aabb, (const void *)(a3 + 92), sizeof(__that->m_aabb));
  memcpy((unsigned __int8 *)__that->m_movement_data, (unsigned __int8 *)(a3 + 116), 0x4042u);
}


void __thiscall vostok::render::grass_patch::grass_patch(
        vostok::render::grass_patch *this,
        vostok::collision::space_partitioning_tree *const in_collision_tree,
        vostok::collision::space_partitioning_tree_vtbl *templ,
        vostok::collision::space_partitioning_tree_vtbl *in_origin,
        vostok::collision::space_partitioning_tree *in_size)
{
  vostok::collision::space_partitioning_tree *v5; // eax
  int v6; // esi
  vostok::math::aabb v7; // [esp+Ch] [ebp-24h] BYREF
  vostok::math::float3 v8; // [esp+24h] [ebp-Ch] BYREF

  in_collision_tree->__vftable = 0;
  in_collision_tree[1].__vftable = 0;
  in_collision_tree[2].__vftable = 0;
  in_collision_tree[3].__vftable = 0;
  in_collision_tree[5].__vftable = 0;
  in_collision_tree[6].__vftable = 0;
  in_collision_tree[7].__vftable = 0;
  in_collision_tree[8].__vftable = 0;
  in_collision_tree[9].__vftable = 0;
  in_collision_tree[10].__vftable = 0;
  in_collision_tree[11].__vftable = 0;
  in_collision_tree[12].__vftable = 0;
  in_collision_tree[19].__vftable = in_origin;
  in_collision_tree[20].__vftable = templ;
  in_collision_tree[21].__vftable = 0;
  in_collision_tree[22].__vftable = 0;
  vostok::math::create_identity_aabb((vostok::math::aabb *)&in_collision_tree[23]);
  in_collision_tree[4125].__vftable = 0;
  in_collision_tree[4126].__vftable = 0;
  in_collision_tree[4127].__vftable = 0;
  in_collision_tree[4128].__vftable = in_size->__vftable;
  in_collision_tree[4129].__vftable = in_size[1].__vftable;
  in_collision_tree[4130].__vftable = in_size[2].__vftable;
  in_collision_tree[4132].__vftable = (vostok::collision::space_partitioning_tree_vtbl *)-1;
  in_collision_tree[4131].__vftable = (vostok::collision::space_partitioning_tree_vtbl *)LODWORD(vostok::render::grass_patch_size);
  in_collision_tree[4133].__vftable = 0;
  LOBYTE(in_collision_tree[4141].__vftable) = 1;
  BYTE1(in_collision_tree[4141].__vftable) = 0;
  v5 = in_collision_tree + 16;
  v6 = 3;
  do
  {
    v5[-3].__vftable = 0;
    v5->__vftable = 0;
    ++v5;
    --v6;
  }
  while ( v6 );
  v8.x = *(float *)&in_collision_tree[4131].__vftable * 0.5;
  *(_QWORD *)&v8.elements[1] = __PAIR64__(LODWORD(v8.x), LODWORD(FLOAT_0_1));
  qmemcpy(
    &in_collision_tree[23],
    vostok::math::create_aabb_center_radius(&v8, (const vostok::math::float3 *)&in_collision_tree[4128], &v7),
    0x18u);
}
