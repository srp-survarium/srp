void __usercall vostok::physics::bt_character_controller::~bt_character_controller(
        vostok::physics::bt_character_controller *this@<ecx>,
        void **a2@<esi>)
{
  vostok::memory::base_allocator *v2; // edi
  vostok::memory::base_allocator *v3; // edi
  _BYTE *v4; // [esp+18h] [ebp-4h]
  _BYTE *v5; // [esp+18h] [ebp-4h]

  v2 = vostok::physics::g_allocator;
  if ( *a2 )
  {
    v4 = __RTCastToVoid((void **)*a2);
    (**(void (__thiscall ***)(_DWORD, _DWORD))*a2)(*a2, 0);
    v2->call_free(
      v2,
      v4,
      "vostok::physics::bt_character_controller::~bt_character_controller",
      ".\\character_controller.cpp",
      46u);
    *a2 = 0;
  }
  *a2 = 0;
  v3 = vostok::physics::g_allocator;
  if ( a2[1] )
  {
    v5 = __RTCastToVoid((void **)a2[1]);
    (**(void (__thiscall ***)(void *, _DWORD))a2[1])(a2[1], 0);
    v3->call_free(
      v3,
      v5,
      "vostok::physics::bt_character_controller::~bt_character_controller",
      ".\\character_controller.cpp",
      49u);
    a2[1] = 0;
  }
  a2[1] = 0;
}
