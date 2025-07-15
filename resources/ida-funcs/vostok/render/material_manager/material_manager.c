void __usercall vostok::render::material_manager::material_manager(
        vostok::render::material_manager *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 12) = 0;
  *(_QWORD *)(a2 + 20) = 0;
  *(_BYTE *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y = a2;
  *(_DWORD *)(a2 + 20) = a2 + 12;
  *(_DWORD *)(a2 + 24) = a2 + 12;
  *(_BYTE *)(a2 + 32) = HIBYTE(this);
}
