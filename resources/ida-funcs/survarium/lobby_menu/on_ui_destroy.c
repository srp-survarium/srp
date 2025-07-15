void __usercall survarium::lobby_menu::on_ui_destroy(survarium::lobby_menu *this@<ecx>, int a2@<eax>)
{
  int f; // ebp
  void **v4; // eax
  char *v5; // esi
  char *v6; // eax
  malloc_state *v7; // esi

  f = (int)survarium::g_allocator.f_.f_;
  v4 = *(void ***)(a2 + 240);
  if ( v4 )
  {
    v5 = __RTCastToVoid(v4);
    (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 240))(*(_DWORD *)(a2 + 240), 0);
    if ( v5 )
    {
      v6 = v5;
      v7 = *(malloc_state **)(f + 20);
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(v7, v6);
    }
    *(_DWORD *)(a2 + 240) = 0;
  }
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::relocate_item_func,vostok::memory::detail::call_destructor_predicate>(
    (survarium::relocate_item_func **)(a2 + 236),
    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_);
}
