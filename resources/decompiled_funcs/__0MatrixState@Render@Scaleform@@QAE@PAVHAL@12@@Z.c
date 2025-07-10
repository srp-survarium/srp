void __userpurge Scaleform::Render::MatrixState::MatrixState(
        Scaleform::Render::MatrixState *this@<ecx>,
        int a2@<esi>,
        Scaleform::Render::HAL *phal)
{
  const vostok::math::float4x4 *v3; // xmm1_4
  const vostok::math::float4x4 *v4; // xmm0_4
  const vostok::math::float4x4 *v5; // xmm0_4
  const vostok::math::float4x4 *v6; // xmm0_4
  const vostok::math::float4x4 *v7; // xmm1_4
  const vostok::math::float4x4 *v8; // xmm0_4
  const vostok::math::float4x4 *v9; // xmm0_4
  const vostok::math::float4x4 *v10; // xmm0_4

  v3 = clear_value;
  *(_DWORD *)a2 = &Scaleform::RefCountImplCore::`vftable';
  *(_DWORD *)(a2 + 4) = 1;
  *(_DWORD *)a2 = &Scaleform::Render::MatrixState::`vftable';
  *(_DWORD *)(a2 + 16) = v3;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = v3;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  memset((unsigned __int8 *)(a2 + 48), 0, 0x30u);
  v4 = clear_value;
  *(_DWORD *)(a2 + 48) = clear_value;
  *(_DWORD *)(a2 + 68) = v4;
  *(_DWORD *)(a2 + 88) = v4;
  memset((unsigned __int8 *)(a2 + 96), 0, 0x40u);
  v5 = clear_value;
  *(_DWORD *)(a2 + 96) = clear_value;
  *(_DWORD *)(a2 + 116) = v5;
  *(_DWORD *)(a2 + 136) = v5;
  *(_DWORD *)(a2 + 156) = v5;
  memset((unsigned __int8 *)(a2 + 160), 0, 0x40u);
  v6 = clear_value;
  *(_DWORD *)(a2 + 160) = clear_value;
  *(_DWORD *)(a2 + 180) = v6;
  *(_DWORD *)(a2 + 200) = v6;
  *(_DWORD *)(a2 + 220) = v6;
  memset((unsigned __int8 *)(a2 + 224), 0, 0x40u);
  v7 = clear_value;
  *(_DWORD *)(a2 + 224) = clear_value;
  *(_DWORD *)(a2 + 244) = v7;
  *(_DWORD *)(a2 + 264) = v7;
  *(_DWORD *)(a2 + 284) = v7;
  *(_DWORD *)(a2 + 288) = v7;
  *(_DWORD *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  *(_DWORD *)(a2 + 300) = 0;
  *(_DWORD *)(a2 + 304) = 0;
  *(_DWORD *)(a2 + 308) = v7;
  *(_DWORD *)(a2 + 312) = 0;
  *(_DWORD *)(a2 + 316) = 0;
  *(_DWORD *)(a2 + 320) = v7;
  *(_DWORD *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 328) = 0;
  *(_DWORD *)(a2 + 332) = 0;
  *(_DWORD *)(a2 + 336) = 0;
  *(_DWORD *)(a2 + 340) = v7;
  *(_DWORD *)(a2 + 344) = 0;
  *(_DWORD *)(a2 + 348) = 0;
  *(_DWORD *)(a2 + 352) = v7;
  *(_DWORD *)(a2 + 356) = 0;
  *(_DWORD *)(a2 + 360) = 0;
  *(_DWORD *)(a2 + 364) = 0;
  *(_DWORD *)(a2 + 368) = 0;
  *(_DWORD *)(a2 + 372) = v7;
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 380) = 0;
  memset((unsigned __int8 *)(a2 + 384), 0, 0x40u);
  v8 = clear_value;
  *(_DWORD *)(a2 + 384) = clear_value;
  *(_DWORD *)(a2 + 404) = v8;
  *(_DWORD *)(a2 + 424) = v8;
  *(_DWORD *)(a2 + 444) = v8;
  *(_DWORD *)(a2 + 448) = 0;
  *(_DWORD *)(a2 + 452) = 0;
  *(_DWORD *)(a2 + 456) = 0;
  *(_DWORD *)(a2 + 460) = 0;
  *(_DWORD *)(a2 + 464) = 0;
  *(_DWORD *)(a2 + 468) = 0;
  *(_DWORD *)(a2 + 472) = 0;
  *(_DWORD *)(a2 + 476) = 0;
  *(_DWORD *)(a2 + 480) = v8;
  *(_DWORD *)(a2 + 484) = 0;
  *(_DWORD *)(a2 + 488) = 0;
  *(_DWORD *)(a2 + 492) = 0;
  *(_DWORD *)(a2 + 496) = 0;
  *(_DWORD *)(a2 + 500) = v8;
  *(_DWORD *)(a2 + 504) = 0;
  *(_DWORD *)(a2 + 508) = 0;
  memset((unsigned __int8 *)(a2 + 512), 0, 0x40u);
  v9 = clear_value;
  *(_DWORD *)(a2 + 512) = clear_value;
  *(_DWORD *)(a2 + 532) = v9;
  *(_DWORD *)(a2 + 552) = v9;
  *(_DWORD *)(a2 + 572) = v9;
  memset((unsigned __int8 *)(a2 + 576), 0, 0x40u);
  v10 = clear_value;
  *(_DWORD *)(a2 + 576) = clear_value;
  *(_DWORD *)(a2 + 596) = v10;
  *(_DWORD *)(a2 + 616) = v10;
  *(_DWORD *)(a2 + 636) = v10;
  *(_BYTE *)(a2 + 640) = 0;
  *(_BYTE *)(a2 + 641) = 0;
  *(_DWORD *)(a2 + 644) = 0;
  *(_DWORD *)(a2 + 648) = 1061158912;
  *(_DWORD *)(a2 + 652) = 1112539136;
  *(_DWORD *)(a2 + 656) = 1058013184;
  *(_DWORD *)(a2 + 660) = 1087163597;
  *(_DWORD *)(a2 + 664) = 0;
  *(_DWORD *)(a2 + 668) = phal;
}
