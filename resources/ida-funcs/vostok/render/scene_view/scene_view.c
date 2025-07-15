void __thiscall vostok::render::scene_view::scene_view(vostok::render::scene_view *this, int a2)
{
  vostok::render::environment_properties *v2; // ecx
  vostok::math::float4x4 *v3; // ecx
  vostok::math::float4x4 *v4; // ecx
  vostok::math::float4x4 *v5; // ecx
  _DWORD *v6; // eax
  char *v7; // ecx

  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_class);
  *(_DWORD *)a2 = &vostok::render::base_scene_view::`vftable';
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 276) = 0;
  *(_DWORD *)a2 = &vostok::render::scene_view::`vftable';
  vostok::render::environment_properties::environment_properties(v2, a2 + 280, 1);
  *(_BYTE *)(a2 + 900) = 1;
  *(_BYTE *)(a2 + 929) = 0;
  vostok::math::float4x4::identity(v3, (vostok::math::float4x4 *)(a2 + 932));
  vostok::math::float4x4::identity(v4, (vostok::math::float4x4 *)(a2 + 996));
  vostok::math::float4x4::identity(v5, (vostok::math::float4x4 *)(a2 + 1060));
  *(_DWORD *)(a2 + 1124) = 3;
  *(_DWORD *)(a2 + 1128) = 0;
  *(_DWORD *)(a2 + 1164) = a2 + 1176;
  *(_DWORD *)(a2 + 1168) = a2 + 1176;
  *(_DWORD *)(a2 + 1172) = a2 + 9368;
  *(_DWORD *)(a2 + 9368) = a2 + 9380;
  *(_DWORD *)(a2 + 9372) = a2 + 9380;
  *(_DWORD *)(a2 + 9376) = a2 + 17572;
  *(_DWORD *)(a2 + 17572) = a2 + 17584;
  *(_DWORD *)(a2 + 17576) = a2 + 17584;
  *(_DWORD *)(a2 + 17580) = a2 + 25776;
  *(_DWORD *)(a2 + 25776) = a2 + 25788;
  *(_DWORD *)(a2 + 25780) = a2 + 25788;
  *(_DWORD *)(a2 + 25784) = a2 + 33980;
  *(_DWORD *)(a2 + 33980) = a2 + 33992;
  *(_DWORD *)(a2 + 33984) = a2 + 33992;
  *(_DWORD *)(a2 + 33988) = a2 + 42184;
  *(_DWORD *)(a2 + 42184) = a2 + 42196;
  *(_DWORD *)(a2 + 42188) = a2 + 42196;
  *(_DWORD *)(a2 + 42192) = a2 + 44244;
  *(_DWORD *)(a2 + 44244) = a2 + 44256;
  *(_DWORD *)(a2 + 44248) = a2 + 44256;
  *(_DWORD *)(a2 + 44252) = a2 + 48352;
  *(_DWORD *)(a2 + 48352) = a2 + 48364;
  *(_DWORD *)(a2 + 48356) = a2 + 48364;
  *(_DWORD *)(a2 + 48360) = a2 + 52460;
  *(_DWORD *)(a2 + 52460) = a2 + 52472;
  *(_DWORD *)(a2 + 52464) = a2 + 52472;
  *(_DWORD *)(a2 + 52468) = a2 + 56568;
  *(_DWORD *)(a2 + 56568) = a2 + 56580;
  *(_DWORD *)(a2 + 56572) = a2 + 56580;
  *(_DWORD *)(a2 + 56576) = a2 + 60676;
  *(_DWORD *)(a2 + 60676) = a2 + 60688;
  *(_DWORD *)(a2 + 60680) = a2 + 60688;
  *(_DWORD *)(a2 + 60684) = a2 + 64784;
  *(_DWORD *)(a2 + 64784) = a2 + 64796;
  *(_DWORD *)(a2 + 64788) = a2 + 64796;
  *(_DWORD *)(a2 + 64792) = a2 + 68892;
  v6 = (int *)((char *)&dword_10D1C + a2);
  v7 = (char *)&dword_10D1C + a2 + 12;
  *v6 = v7;
  v6[1] = v7;
  v6[2] = v6 + 35;
  *(int *)((char *)&dword_10DA8 + a2) = 0;
  *(int *)((char *)&dword_10DAC + a2) = 0;
  *(int *)((char *)&dword_10DF8 + a2) = 0;
  *(_DWORD *)(a2 + 896) = 0;
  *(int *)((char *)&dword_10DFC + a2) = 0;
  *(int *)((char *)&dword_10E00 + a2) = 0;
  *(int *)((char *)&dword_10E04 + a2) = 0;
  *(int *)((char *)&dword_10E08 + a2) = 0;
  *(int *)((char *)&dword_10E0C + a2) = 0;
  *(int *)((char *)&dword_10E10 + a2) = 0;
  *(int *)((char *)&dword_10E14 + a2) = 0;
  *(int *)((char *)&dword_10E18 + a2) = 0;
  *(int *)((char *)&dword_10E1C + a2) = 0;
  *(int *)((char *)&dword_10E20 + a2) = 0;
  *(_DWORD *)(a2 + 1148) = 0;
  *(_DWORD *)(a2 + 1152) = 0;
  *(_DWORD *)(a2 + 1156) = 0;
  *(int *)((char *)&dword_10E28 + a2) = -1;
  *(_DWORD *)(a2 + 1160) = 0;
  *(_DWORD *)(a2 + 1132) = 0;
  *(_DWORD *)(a2 + 1136) = 0;
  *(_DWORD *)(a2 + 1140) = 0;
  byte_10E2C[a2] = 1;
  *(_DWORD *)(a2 + 904) = 0;
  *(_DWORD *)(a2 + 908) = 0;
  *(_DWORD *)(a2 + 912) = 0;
  *(_DWORD *)(a2 + 916) = 0;
  *(_BYTE *)(a2 + 928) = 0;
  *(_DWORD *)(a2 + 920) = 0;
  *(_DWORD *)(a2 + 924) = 0;
  *(_DWORD *)(a2 + 1144) = 0;
  memset((int)&byte_10DB8[a2], 0, 0x40u);
}
