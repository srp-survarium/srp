void __usercall vostok::engine::engine_world::logic_tick(vostok::engine::engine_world *this@<ecx>, int a2@<esi>)
{
  vostok::resources::resources_manager *v2; // ecx
  vostok::sound::world_user *v3; // eax
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4> > *v4; // ecx
  char v5; // al

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD, vostok::engine::engine_world *))(**(_DWORD **)(a2 + 656) + 16))(
         *(_DWORD *)(a2 + 656),
         this) )
  {
    vostok::threading::yield(0xAu);
  }
  vostok::resources::dispatch_callbacks(v2);
  v3 = (vostok::sound::world_user *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 648) + 8))(*(_DWORD *)(a2 + 648));
  vostok::sound::world_user::dispatch_callbacks(v3);
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 644) + 16))(*(_DWORD *)(a2 + 644));
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>>::owner_delete_processed_items(
    v4,
    *(vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4> > **)(a2 + 632));
  v5 = *(_BYTE *)(a2 + 710);
  *(_BYTE *)(a2 + 711) = v5;
  if ( v5 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(a2 + 8) + 48))(a2 + 8) )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 656) + 4))(*(_DWORD *)(a2 + 656), *(_DWORD *)(a2 + 680));
    ++*(_DWORD *)(a2 + 680);
  }
  else if ( !*(_BYTE *)(a2 + 710) )
  {
    ++*(_DWORD *)(a2 + 680);
  }
}
