void __usercall survarium::base_game_scene::destroy_physics(survarium::base_game_scene *this@<ecx>, int a2@<eax>)
{
  void **v2; // esi
  _BYTE *v3; // edi

  v2 = *(void ***)(a2 + 176);
  (*((void (__thiscall **)(void **))*v2 + 3))(v2);
  v3 = __RTCastToVoid(v2);
  (*(void (__thiscall **)(void **, _DWORD))*v2)(v2, 0);
  vostok::memory::g_mt_allocator.call_free(&vostok::memory::g_mt_allocator, v3);
}
