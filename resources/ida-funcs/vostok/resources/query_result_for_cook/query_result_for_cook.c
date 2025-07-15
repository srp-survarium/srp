void __userpurge vostok::resources::query_result_for_cook::query_result_for_cook(
        vostok::resources::query_result_for_cook *this@<ecx>,
        int a2@<esi>,
        vostok::resources::queries_result *parent)
{
  vostok::resources::query_result_for_user::query_result_for_user(
    this,
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)a2);
  *(_DWORD *)a2 = &vostok::resources::query_result_for_cook::`vftable';
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 312) = 0;
  *(_DWORD *)(a2 + 316) = 0;
  *(_DWORD *)(a2 + 320) = 0;
  *(_DWORD *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 328) = 0;
  *(_DWORD *)(a2 + 344) = parent;
  *(_DWORD *)(a2 + 332) = 0;
  *(_BYTE *)(a2 + 336) = 0;
  *(_BYTE *)(a2 + 337) = 0;
  *(_DWORD *)(a2 + 340) = 0;
  *(_BYTE *)(a2 + 348) = 0;
  *(_DWORD *)(a2 + 608) = 260;
  *(_DWORD *)(a2 + 248) = a2 + 348;
}
