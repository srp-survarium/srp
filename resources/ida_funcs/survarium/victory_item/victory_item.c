void __thiscall survarium::victory_item::victory_item(
        survarium::victory_item *this,
        survarium::victory_item *w,
        vostok::resources::query_result *wa)
{
  const vostok::math::float4x4 *v3; // eax
  const vostok::math::float4x4 *v4; // eax
  vostok::math::float3 angles; // [esp+10h] [ebp-118h] BYREF
  vostok::math::float3 position; // [esp+1Ch] [ebp-10Ch] BYREF
  vostok::math::float4x4 dst; // [esp+28h] [ebp-100h] BYREF
  vostok::math::float4x4 left; // [esp+68h] [ebp-C0h] BYREF
  vostok::math::float4x4 result; // [esp+A8h] [ebp-80h] BYREF
  vostok::math::float4x4 v10; // [esp+E8h] [ebp-40h] BYREF

  survarium::victory_item_core::victory_item_core(w);
  w->survarium::victory_item_core::survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::victory_item_vtbl *)&survarium::victory_item::`vftable'{for `survarium::collision_geometry_subscriber'};
  w->survarium::victory_item_core::survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::victory_item::`vftable'{for `survarium::link_resolver'};
  w->survarium::victory_item_core::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::victory_item::`vftable';
  w->m_model.m_object = 0;
  w->m_game_world = (survarium::game_world *)wa;
  memset(&position, 0, sizeof(position));
  memset((int)&dst, 0, sizeof(dst));
  LODWORD(dst.i.x) = clear_value;
  LODWORD(dst.j.y) = clear_value;
  LODWORD(dst.k.z) = clear_value;
  LODWORD(dst.c.w) = clear_value;
  memset(&angles, 0, sizeof(angles));
  v3 = vostok::math::create_rotation(&result, &angles);
  vostok::math::mul4x3(&left, v3, &dst);
  v4 = vostok::math::create_translation(&v10, &position);
  vostok::math::mul4x3(&dst, &left, v4);
  qmemcpy((void *)&w->m_transform, &dst, sizeof(w->m_transform));
}
