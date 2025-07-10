void __userpurge vostok::resources::query_result_for_cook::query_result_for_cook(
        vostok::resources::query_result_for_cook *this@<ecx>,
        int a2@<eax>,
        vostok::resources::queries_result *parent)
{
  vostok::resources::query_result_for_user::query_result_for_user(this, a2);
  *(_DWORD *)a2 = &vostok::resources::query_result_for_cook::`vftable';
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  *(_DWORD *)(a2 + 300) = 0;
  *(_DWORD *)(a2 + 304) = 0;
  *(_DWORD *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 312) = 0;
  *(_DWORD *)(a2 + 328) = parent;
  *(_DWORD *)(a2 + 316) = 0;
  *(_BYTE *)(a2 + 320) = 0;
  *(_BYTE *)(a2 + 321) = 0;
  *(_DWORD *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 332) = 0;
  *(_BYTE *)(a2 + 336) = 0;
  *(_DWORD *)(a2 + 596) = 260;
  *(_DWORD *)(a2 + 248) = a2 + 336;
}
