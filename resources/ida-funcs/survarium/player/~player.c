void __usercall survarium::player::~player(survarium::player *this@<ecx>, int a2@<edi>)
{
  survarium::inventory *v2; // ecx
  vostok::collision::animated_object *v3; // ecx
  void *v4; // esi
  int f; // ebp
  void *v6; // eax
  void *v7; // esi
  int v8; // eax
  survarium::circular_buffer<survarium::client_player_history_item> *v9; // ecx
  survarium::client_player_state *v10; // ecx
  void *v11; // eax
  void *v12; // esi
  survarium::client_player_state *v13; // ecx

  v2 = *(survarium::inventory **)(a2 + 8);
  *(_DWORD *)a2 = &survarium::player::`vftable'{for `survarium::inventory_holder'};
  *(_DWORD *)(a2 + 12) = &survarium::player::`vftable'{for `survarium::collision_user'};
  *(_DWORD *)(a2 + 48) = &survarium::player::`vftable'{for `survarium::hit_initiator'};
  *(_DWORD *)(a2 + 56) = &survarium::player::`vftable'{for `survarium::hit_receiver'};
  *(_DWORD *)(a2 + 288) = &survarium::player::`vftable';
  survarium::inventory::unset_holder(v2);
  v4 = *(void **)((char *)&dword_10EF0 + a2);
  f = (int)survarium::g_allocator.f_.f_;
  if ( v4 )
  {
    vostok::collision::animated_object::~animated_object(v3);
    v6 = v4;
    v7 = *(void **)(f + 20);
    *(_BYTE *)(f + 42) = 0;
    vostok_mspace_free(v7, v6);
    *(int *)((char *)&dword_10EF0 + a2) = 0;
  }
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::physics::bt_character_controller,vostok::memory::detail::call_destructor_predicate>(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    (vostok::physics::bt_character_controller **)((char *)&dword_10DC8 + a2));
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::physics::bt_character_controller,vostok::memory::detail::call_destructor_predicate>(
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
    (vostok::physics::bt_character_controller **)(a2 + 34804));
  v8 = *(int *)((char *)&dword_10F08 + a2);
  if ( v8 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v8 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(int *)((char *)&dword_10F08 + a2) + 208),
      *(vostok::resources::unmanaged_resource **)((char *)&dword_10F08 + a2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&unk_10E38 + a2));
  survarium::circular_buffer<survarium::client_player_history_item>::~circular_buffer<survarium::client_player_history_item>(
    v9,
    (int)&dword_10E1C + a2);
  v11 = *(void **)((char *)&dword_10E10 + a2);
  if ( v11 )
  {
    v12 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v12, v11);
  }
  survarium::client_player_state::~client_player_state(v10, a2 + 34812);
  survarium::client_player_state::~client_player_state(v13, a2 + 552);
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)(a2 + 288));
  survarium::base_player::~base_player((survarium::base_player *)a2);
}
