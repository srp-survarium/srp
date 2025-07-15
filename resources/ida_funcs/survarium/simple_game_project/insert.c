void __userpurge survarium::simple_game_project::insert(
        survarium::simple_game_project *this@<ecx>,
        int a2@<esi>,
        survarium::scheduler *scheduler)
{
  unsigned int v3; // ebp
  int v4; // edi
  int v5; // eax
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v6; // ecx
  const vostok::math::float4x4 *v7; // eax
  unsigned int v8; // edi
  int v9; // ebp
  _DWORD *v10; // edi
  _DWORD *i; // ebp
  int v12; // edi
  int j; // ebp
  _DWORD *v14; // edi
  _DWORD *k; // ebp
  survarium::usable_object **v16; // edi
  survarium::usable_object **m; // ebp
  _DWORD *v18; // edi
  _DWORD *n; // ebp

  v3 = 0;
  if ( *(_DWORD *)(a2 + 432) )
  {
    v4 = 0;
    do
    {
      v5 = *(_DWORD *)(a2 + 428);
      v6 = *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)(v5 + v4 + 64);
      v7 = (const vostok::math::float4x4 *)(v4 + v5);
      if ( v6 )
        vostok::render::scene_renderer::add_model(
          *(vostok::render::scene_renderer **)(*(_DWORD *)(a2 + 312) + 168),
          (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 312) + 4),
          v6 + 66,
          v7);
      ++v3;
      v4 += 68;
    }
    while ( v3 < *(_DWORD *)(a2 + 432) );
  }
  v8 = 0;
  if ( *(_DWORD *)(a2 + 308) )
  {
    v9 = 0;
    do
    {
      survarium::static_collision::insert(
        (survarium::static_collision *)(v9 + *(_DWORD *)(a2 + 304)),
        *(vostok::physics::world **)(*(_DWORD *)(a2 + 312) + 176));
      ++v8;
      v9 += 76;
    }
    while ( v8 < *(_DWORD *)(a2 + 308) );
  }
  v10 = *(_DWORD **)(a2 + 320);
  for ( i = *(_DWORD **)(a2 + 324); v10 != i; ++v10 )
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v10 + 32))(*v10);
  v12 = *(_DWORD *)(a2 + 368);
  for ( j = *(_DWORD *)(a2 + 372); v12 != j; v12 += 4 )
  {
    if ( *(_BYTE *)(*(_DWORD *)v12 + 528) )
      (*(void (__thiscall **)(int, _DWORD, _DWORD, survarium::scheduler *))(*(_DWORD *)(*(_DWORD *)v12 + 264) + 40))(
        *(_DWORD *)v12 + 264,
        0,
        *(_DWORD *)(*(_DWORD *)(a2 + 312) + 176),
        scheduler);
  }
  v14 = *(_DWORD **)(a2 + 404);
  for ( k = *(_DWORD **)(a2 + 408); v14 != k; ++v14 )
    (*(void (__thiscall **)(_DWORD, _DWORD, survarium::scheduler *))(*(_DWORD *)*v14 + 8))(
      *v14,
      *(_DWORD *)(*(_DWORD *)(a2 + 312) + 176),
      scheduler);
  v16 = *(survarium::usable_object ***)(a2 + 416);
  for ( m = *(survarium::usable_object ***)(a2 + 420); v16 != m; ++v16 )
    survarium::usable_object::insert(*v16, *(vostok::physics::world **)(*(_DWORD *)(a2 + 312) + 176));
  v18 = *(_DWORD **)(a2 + 392);
  for ( n = *(_DWORD **)(a2 + 396); v18 != n; ++v18 )
    (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*v18 + 28))(*v18, *(_DWORD *)(*(_DWORD *)(a2 + 312) + 176));
  *(_BYTE *)(a2 + 436) = 1;
}
