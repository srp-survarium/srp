void __usercall survarium::player::add_models_to_scene(survarium::player *this@<ecx>, int a2@<esi>)
{
  vostok::render::base_scene *v2; // eax
  vostok::resources::unmanaged_resource *v3; // edi
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> scene; // [esp+8h] [ebp-4h] BYREF

  v2 = *(vostok::render::base_scene **)(*(int *)((char *)&dword_10F00 + a2) + 4);
  v3 = 0;
  scene.m_object = 0;
  if ( v2 )
  {
    v3 = v2;
    scene.m_object = v2;
    _InterlockedExchangeAdd(&v2->m_reference_count, 1u);
  }
  if ( byte_10F33[a2] )
    vostok::render::scene_renderer::add_model(
      (vostok::render::scene_renderer *)(a2 + 34672),
      &scene,
      (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 34800) + 264),
      (const vostok::math::float4x4 *)(a2 + 34672));
  if ( byte_10F32[a2] )
    vostok::render::scene_renderer::add_model(
      (vostok::render::scene_renderer *)&byte_10D44[a2],
      &scene,
      (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)(*(int *)((char *)&dword_10DC4 + a2) + 264),
      (const vostok::math::float4x4 *)&byte_10D44[a2]);
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  }
}
