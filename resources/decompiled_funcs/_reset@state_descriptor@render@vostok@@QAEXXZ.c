void __usercall vostok::render::state_descriptor::reset(vostok::render::state_descriptor *this@<ecx>, int a2@<esi>)
{
  *(_BYTE *)(a2 + 360) = 0;
  *(_BYTE *)(a2 + 361) = 0;
  *(_BYTE *)(a2 + 362) = 0;
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_DWORD *)a2 = 3;
  *(_DWORD *)(a2 + 4) = 3;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 1;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  memset(a2 + 40, 0, 0x34u);
  *(_BYTE *)(a2 + 56) = 127;
  *(_BYTE *)(a2 + 57) = 127;
  *(_DWORD *)(a2 + 72) = 8;
  *(_DWORD *)(a2 + 88) = 8;
  *(_DWORD *)(a2 + 40) = 1;
  *(_DWORD *)(a2 + 44) = 1;
  *(_DWORD *)(a2 + 48) = 2;
  *(_DWORD *)(a2 + 52) = 1;
  *(_DWORD *)(a2 + 60) = 1;
  *(_DWORD *)(a2 + 64) = 1;
  *(_DWORD *)(a2 + 68) = 1;
  *(_DWORD *)(a2 + 76) = 1;
  *(_DWORD *)(a2 + 80) = 1;
  *(_DWORD *)(a2 + 84) = 1;
  vostok::render::state_utils::reset((D3D11_BLEND_DESC *)(a2 + 92));
  *(_DWORD *)(a2 + 356) = 0;
}
