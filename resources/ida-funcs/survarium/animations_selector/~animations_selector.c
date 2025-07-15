void __usercall survarium::animations_selector::~animations_selector(
        survarium::animations_selector *this@<ecx>,
        int a2@<esi>)
{
  survarium::simple_animation_controller *v2; // ecx
  int v3; // eax
  int v4; // eax
  survarium::single_position_animation_controller *v5; // ecx

  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 236));
  v3 = *(_DWORD *)(a2 + 208);
  if ( v3 )
  {
    v2 = (survarium::simple_animation_controller *)_InterlockedExchangeAdd(
                                                     (volatile signed __int32 *)(v3 + 208),
                                                     0xFFFFFFFF);
    if ( !v2 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 208) + 208),
        *(vostok::resources::unmanaged_resource **)(a2 + 208));
  }
  v4 = *(_DWORD *)(a2 + 164);
  if ( v4 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 164) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 164));
  survarium::simple_animation_controller::~simple_animation_controller(v2);
  survarium::single_position_animation_controller::~single_position_animation_controller(v5);
}
