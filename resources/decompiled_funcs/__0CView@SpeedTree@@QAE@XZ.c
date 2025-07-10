void __usercall SpeedTree::CView::CView(SpeedTree::CView *this@<ecx>, int a2@<esi>)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  const vostok::math::float4x4 *v3; // xmm0_4
  const vostok::math::float4x4 *v4; // xmm0_4
  const vostok::math::float4x4 *v5; // xmm0_4
  const vostok::math::float4x4 *v6; // xmm0_4
  const vostok::math::float4x4 *v7; // xmm0_4

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_BYTE *)(a2 + 24) = 0;
  memset((unsigned __int8 *)(a2 + 28), 0, 0x40u);
  v2 = clear_value;
  *(_DWORD *)(a2 + 88) = clear_value;
  *(_DWORD *)(a2 + 68) = v2;
  *(_DWORD *)(a2 + 48) = v2;
  *(_DWORD *)(a2 + 28) = v2;
  memset((unsigned __int8 *)(a2 + 92), 0, 0x40u);
  v3 = clear_value;
  *(_DWORD *)(a2 + 152) = clear_value;
  *(_DWORD *)(a2 + 132) = v3;
  *(_DWORD *)(a2 + 112) = v3;
  *(_DWORD *)(a2 + 92) = v3;
  *(_DWORD *)(a2 + 156) = v3;
  *(_DWORD *)(a2 + 160) = 1120403456;
  *(_DWORD *)(a2 + 164) = 0;
  *(_DWORD *)(a2 + 168) = 0;
  *(_DWORD *)(a2 + 172) = 0;
  memset((unsigned __int8 *)(a2 + 176), 0, 0x40u);
  v4 = clear_value;
  *(_DWORD *)(a2 + 236) = clear_value;
  *(_DWORD *)(a2 + 216) = v4;
  *(_DWORD *)(a2 + 196) = v4;
  *(_DWORD *)(a2 + 176) = v4;
  memset((unsigned __int8 *)(a2 + 240), 0, 0x40u);
  v5 = clear_value;
  *(_DWORD *)(a2 + 300) = clear_value;
  *(_DWORD *)(a2 + 280) = v5;
  *(_DWORD *)(a2 + 260) = v5;
  *(_DWORD *)(a2 + 240) = v5;
  memset((unsigned __int8 *)(a2 + 304), 0, 0x40u);
  v6 = clear_value;
  *(_DWORD *)(a2 + 364) = clear_value;
  *(_DWORD *)(a2 + 344) = v6;
  *(_DWORD *)(a2 + 324) = v6;
  *(_DWORD *)(a2 + 304) = v6;
  *(_DWORD *)(a2 + 368) = 0;
  *(_DWORD *)(a2 + 372) = 0;
  `vector constructor iterator'((char *)(a2 + 376), 0xCu, 8, (void *(__thiscall *)(void *))SpeedTree::Vec3::Vec3);
  `vector constructor iterator'((char *)(a2 + 472), 0x10u, 6, (void *(__thiscall *)(void *))SpeedTree::Vec4::Vec4);
  *(_DWORD *)(a2 + 568) = 2139095039;
  *(_DWORD *)(a2 + 572) = 2139095039;
  *(_DWORD *)(a2 + 576) = 2139095039;
  *(_DWORD *)(a2 + 580) = -8388609;
  *(_DWORD *)(a2 + 584) = -8388609;
  *(_DWORD *)(a2 + 588) = -8388609;
  memset((unsigned __int8 *)(a2 + 592), 0, 0x40u);
  v7 = clear_value;
  *(_DWORD *)(a2 + 652) = clear_value;
  *(_DWORD *)(a2 + 632) = v7;
  *(_DWORD *)(a2 + 612) = v7;
  *(_DWORD *)(a2 + 592) = v7;
  *(_DWORD *)(a2 + 656) = 1057360530;
  *(float *)(a2 + 660) = pi_d3;
}
