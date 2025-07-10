void __usercall vostok::render::effect_manager::effect_manager(
        vostok::render::effect_manager *this@<ecx>,
        survarium::game_action_id a2@<esi>)
{
  LOBYTE(this) = HIBYTE(this);
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = &vostok::memory::g_mt_allocator;
  *(_DWORD *)(a2 + 16) = 0;
  *(_BYTE *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_BYTE *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = a2 + 24;
  *(_DWORD *)(a2 + 36) = a2 + 24;
  *(_DWORD *)(a2 + 64) = 0;
  *(_QWORD *)(a2 + 48) = 0;
  *(_QWORD *)(a2 + 56) = 0;
  *(_BYTE *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = a2 + 48;
  *(_DWORD *)(a2 + 60) = a2 + 48;
  *(_DWORD *)(a2 + 88) = 0;
  *(_QWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_BYTE *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)(a2 + 80) = a2 + 72;
  *(_DWORD *)(a2 + 84) = a2 + 72;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 124) = 0;
  *(_BYTE *)(a2 + 128) = HIBYTE(this);
  *(_QWORD *)(a2 + 108) = 0;
  *(_QWORD *)(a2 + 116) = 0;
  *(_BYTE *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 112) = 0;
  *(_DWORD *)(a2 + 116) = a2 + 108;
  *(_DWORD *)(a2 + 120) = a2 + 108;
  *(_QWORD *)(a2 + 132) = 0;
  *(_QWORD *)(a2 + 140) = 0;
  *(_BYTE *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 136) = 0;
  *(_DWORD *)(a2 + 140) = a2 + 132;
  *(_DWORD *)(a2 + 144) = a2 + 132;
  *(_DWORD *)(a2 + 148) = 0;
  *(_BYTE *)(a2 + 152) = HIBYTE(this);
  *(_BYTE *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 160) = 0;
  *(_DWORD *)(a2 + 164) = 0;
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind = a2;
  *(_DWORD *)(a2 + 168) = 0;
  if ( (_S3_10 & 1) == 0 )
  {
    _S3_10 |= 1u;
    vostok::render::effect_cook::effect_cook((vostok::render::effect_cook *)this);
    atexit(vostok::render::effect_manager::effect_manager_::_2_::_dynamic_atexit_destructor_for__effect_cooker__);
  }
  vostok::resources::resources_manager::register_cook((int)this, &effect_cooker);
  *(_BYTE *)a2 = 0;
}
