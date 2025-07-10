void __usercall survarium::simple_game_project::remove(survarium::simple_game_project *this@<ecx>, int a2@<esi>)
{
  unsigned int v2; // ebp
  int v3; // edi
  unsigned int v4; // edi
  int v5; // ebp
  _DWORD *v6; // edi
  _DWORD *i; // ebp
  _DWORD *v8; // edi
  _DWORD *j; // ebp
  int v10; // edi
  int k; // ebp
  _DWORD *v12; // edi
  _DWORD *m; // ebp
  survarium::usable_object **v14; // edi
  survarium::usable_object **n; // ebp

  v2 = 0;
  if ( *(_DWORD *)(a2 + 432) )
  {
    v3 = 0;
    do
    {
      if ( *(_DWORD *)(v3 + *(_DWORD *)(a2 + 428) + 64) )
        vostok::render::scene_renderer::remove_model(
          *(vostok::render::scene_renderer **)(*(_DWORD *)(a2 + 312) + 168),
          *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 312) + 168) + 148) + 16),
          (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 312) + 4));
      ++v2;
      v3 += 68;
    }
    while ( v2 < *(_DWORD *)(a2 + 432) );
  }
  v4 = 0;
  if ( *(_DWORD *)(a2 + 308) )
  {
    v5 = 0;
    do
    {
      survarium::static_collision::remove(
        (survarium::static_collision *)(v5 + *(_DWORD *)(a2 + 304)),
        *(vostok::physics::world **)(*(_DWORD *)(a2 + 312) + 176));
      ++v4;
      v5 += 76;
    }
    while ( v4 < *(_DWORD *)(a2 + 308) );
  }
  v6 = *(_DWORD **)(a2 + 392);
  for ( i = *(_DWORD **)(a2 + 396); v6 != i; ++v6 )
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v6 + 32))(*v6);
  v8 = *(_DWORD **)(a2 + 404);
  for ( j = *(_DWORD **)(a2 + 408); v8 != j; ++v8 )
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v8 + 12))(*v8);
  v10 = *(_DWORD *)(a2 + 368);
  for ( k = *(_DWORD *)(a2 + 372); v10 != k; v10 += 4 )
  {
    if ( *(_BYTE *)(*(_DWORD *)v10 + 528) )
      (*(void (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)v10 + 264) + 44))(*(_DWORD *)v10 + 264);
  }
  v12 = *(_DWORD **)(a2 + 320);
  for ( m = *(_DWORD **)(a2 + 324); v12 != m; ++v12 )
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v12 + 36))(*v12);
  v14 = *(survarium::usable_object ***)(a2 + 416);
  for ( n = *(survarium::usable_object ***)(a2 + 420); v14 != n; ++v14 )
    survarium::usable_object::remove(*v14);
  *(_BYTE *)(a2 + 436) = 0;
}
