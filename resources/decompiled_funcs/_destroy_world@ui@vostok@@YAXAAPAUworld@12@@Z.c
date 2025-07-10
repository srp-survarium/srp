void __cdecl vostok::ui::destroy_world(vostok::ui::world **world)
{
  int v1; // esi
  vostok::ui::world_vtbl *v2; // edi
  _BYTE *v3; // ebp

  v1 = (int)*world;
  v2 = (*world)[4].__vftable;
  v3 = __RTCastToVoid((void **)&(*world)->__vftable);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v1 + 56))(v1, 0);
  (*((void (__thiscall **)(vostok::ui::world_vtbl *, _BYTE *))v2->tick + 6))(v2, v3);
  *world = 0;
}
