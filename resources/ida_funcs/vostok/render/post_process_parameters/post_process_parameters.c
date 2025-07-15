void __usercall vostok::render::post_process_parameters::post_process_parameters(
        vostok::render::post_process_parameters *this@<ecx>,
        int a2@<edi>)
{
  vostok::render::resource_manager *v2; // xmm0_4
  __int64 v3; // xmm4_8
  __int64 v4; // xmm4_8
  __int64 v5; // xmm4_8
  vostok::render::resource_manager *v6; // eax
  vostok::render::resource_manager *v7; // ecx
  vostok::render::resource_manager *v8; // eax
  __int64 v9; // xmm4_8
  __int64 v10; // xmm3_8
  __int64 v11; // xmm4_8
  __int64 v12; // xmm3_8
  vostok::render::resource_manager *v13; // ecx
  vostok::render::res_texture_vtbl *v14; // eax
  vostok::render::res_texture *v15; // ecx
  const vostok::render::res_texture *v16; // esi
  bool v17; // zf
  const vostok::render::res_texture *v18; // esi
  const vostok::render::res_texture *v19; // esi
  const vostok::render::res_texture *v20; // esi
  vostok::render::resource_manager *v21; // xmm0_4
  __int64 v22; // xmm2_8
  vostok::render::resource_manager *v23; // [esp-8h] [ebp-2Ch]
  const vostok::render::res_texture *v24; // [esp+Ch] [ebp-18h] BYREF
  __int64 v25; // [esp+10h] [ebp-14h]
  vostok::render::resource_manager *v26[2]; // [esp+18h] [ebp-Ch]

  v2 = (vostok::render::resource_manager *)clear_value;
  *(_DWORD *)(a2 + 500) = 0;
  *(_DWORD *)(a2 + 504) = 0;
  *(_DWORD *)(a2 + 508) = 0;
  *(_DWORD *)(a2 + 512) = 0;
  LODWORD(v25) = v2;
  HIDWORD(v25) = v2;
  *(_QWORD *)a2 = v25;
  LODWORD(v25) = v2;
  HIDWORD(v25) = v2;
  v3 = v25;
  *(_DWORD *)(a2 + 12) = 1058642330;
  *(_QWORD *)(a2 + 72) = v3;
  LODWORD(v25) = v2;
  HIDWORD(v25) = v2;
  v4 = v25;
  *(_DWORD *)(a2 + 16) = 1101004800;
  *(_QWORD *)(a2 + 100) = v4;
  LODWORD(v25) = v2;
  HIDWORD(v25) = v2;
  v5 = v25;
  v26[0] = v2;
  *(_DWORD *)(a2 + 8) = v2;
  v6 = v26[0];
  *(float *)(a2 + 20) = default_fps_3;
  *(_QWORD *)(a2 + 112) = v5;
  v26[0] = 0;
  *(_DWORD *)(a2 + 80) = v2;
  v7 = v26[0];
  *(_QWORD *)(a2 + 124) = 0;
  *(_DWORD *)(a2 + 108) = v2;
  *(_DWORD *)(a2 + 36) = 1090519040;
  *(_QWORD *)(a2 + 136) = 0;
  *(_BYTE *)(a2 + 668) = 1;
  *(_DWORD *)(a2 + 652) = v2;
  *(_DWORD *)(a2 + 656) = v2;
  *(_DWORD *)(a2 + 660) = v2;
  *(_DWORD *)(a2 + 664) = v2;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_BYTE *)(a2 + 32) = 1;
  *(_BYTE *)(a2 + 33) = 0;
  *(_DWORD *)(a2 + 40) = v2;
  *(_BYTE *)(a2 + 44) = 0;
  *(float *)(a2 + 56) = FLOAT_0_5;
  *(float *)(a2 + 60) = retry_to_increase_quality_period_sec;
  *(_DWORD *)(a2 + 64) = 3;
  *(_BYTE *)(a2 + 84) = 0;
  *(_BYTE *)(a2 + 85) = 1;
  *(_DWORD *)(a2 + 88) = v2;
  *(_DWORD *)(a2 + 92) = v2;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 120) = v6;
  *(_DWORD *)(a2 + 132) = v7;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 68) = 1025758986;
  *((float *)&v25 + 1) = survarium::s_camera_far_plane;
  LODWORD(v25) = 0;
  *(_QWORD *)(a2 + 156) = v25;
  LODWORD(v25) = v2;
  HIDWORD(v25) = v2;
  *(_QWORD *)(a2 + 168) = v25;
  *(_QWORD *)(a2 + 192) = 0x3F4CCCCD3F5EB852LL;
  v26[0] = (vostok::render::resource_manager *)1041865114;
  *(_QWORD *)(a2 + 180) = 0x3E19999A3E19999ALL;
  v25 = 0;
  *(_DWORD *)(a2 + 204) = 1176256512;
  v26[1] = 0;
  *(_QWORD *)(a2 + 232) = v25;
  *(_DWORD *)(a2 + 164) = 0;
  v8 = v26[0];
  v26[0] = 0;
  v25 = 0;
  *(_QWORD *)(a2 + 240) = *(_QWORD *)v26;
  v9 = v25;
  *(float *)&v25 = retry_to_increase_quality_period_sec;
  *((float *)&v25 + 1) = retry_to_increase_quality_period_sec;
  v10 = v25;
  *(_QWORD *)v26 = 0;
  *(_QWORD *)(a2 + 248) = v9;
  v11 = *(_QWORD *)v26;
  v26[0] = 0;
  *(_QWORD *)(a2 + 328) = v10;
  *(_DWORD *)(a2 + 316) = v2;
  *(_DWORD *)(a2 + 320) = v2;
  *(_DWORD *)(a2 + 216) = v2;
  v26[1] = 0;
  v12 = (unsigned int)v26[0];
  v26[0] = v2;
  *(_DWORD *)(a2 + 344) = v2;
  v25 = (unsigned int)v2;
  *(_QWORD *)(a2 + 364) = (unsigned int)v2;
  *(_DWORD *)(a2 + 176) = v2;
  v13 = v26[0];
  *(_DWORD *)(a2 + 376) = 1048576000;
  *(_DWORD *)(a2 + 148) = 0;
  *(_BYTE *)(a2 + 152) = 1;
  *(_DWORD *)(a2 + 200) = 1061997773;
  *(_DWORD *)(a2 + 188) = v8;
  *(_DWORD *)(a2 + 208) = 0;
  *(float *)(a2 + 212) = FLOAT_0_5;
  *(_DWORD *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 312) = 0;
  *(_BYTE *)(a2 + 324) = 0;
  *(_QWORD *)(a2 + 256) = v11;
  *(_QWORD *)(a2 + 336) = v12;
  *(_DWORD *)(a2 + 372) = v13;
  v23 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  *(float *)(a2 + 348) = satisfaction_equality_tolerance;
  *(float *)(a2 + 352) = FLOAT_0_5;
  *(_DWORD *)(a2 + 356) = 0;
  *(float *)(a2 + 360) = FLOAT_0_5;
  *(_BYTE *)(a2 + 380) = 1;
  *(_BYTE *)(a2 + 496) = 0;
  v14 = vostok::render::resource_manager::get_color_grading_base_lut(v13, v23, (vostok::render::res_texture *)&v24)->__vftable;
  v15 = 0;
  if ( v14 )
  {
    v15 = (vostok::render::res_texture *)v14;
    ++v14[1].~vostok::render::res_texture;
  }
  v16 = *(const vostok::render::res_texture **)(a2 + 500);
  *(_DWORD *)(a2 + 500) = v15;
  if ( v16 )
  {
    v17 = v16->m_reference_count-- == 1;
    if ( v17 )
      vostok::render::res_texture::destroy_impl(v15, v16);
  }
  if ( v24 )
  {
    v17 = v24->m_reference_count-- == 1;
    if ( v17 )
      vostok::render::res_texture::destroy_impl(v15, v24);
  }
  v18 = *(const vostok::render::res_texture **)(a2 + 504);
  *(_DWORD *)(a2 + 504) = 0;
  if ( v18 )
  {
    v17 = v18->m_reference_count-- == 1;
    if ( v17 )
      vostok::render::res_texture::destroy_impl(v15, v18);
  }
  v19 = *(const vostok::render::res_texture **)(a2 + 508);
  *(_DWORD *)(a2 + 508) = 0;
  if ( v19 )
  {
    v17 = v19->m_reference_count-- == 1;
    if ( v17 )
      vostok::render::res_texture::destroy_impl(v15, v19);
  }
  v20 = *(const vostok::render::res_texture **)(a2 + 512);
  *(_DWORD *)(a2 + 512) = 0;
  if ( v20 )
  {
    v17 = v20->m_reference_count-- == 1;
    if ( v17 )
      vostok::render::res_texture::destroy_impl(v15, v20);
  }
  *(_QWORD *)(a2 + 384) = 0;
  *(_QWORD *)(a2 + 392) = 0;
  *(_QWORD *)(a2 + 400) = 0;
  *(_QWORD *)(a2 + 408) = 0;
  *(_QWORD *)(a2 + 416) = 0;
  *(_QWORD *)(a2 + 424) = 0;
  *(_QWORD *)(a2 + 432) = 0;
  *(_QWORD *)(a2 + 440) = 0;
  *(_QWORD *)(a2 + 448) = 0;
  *(_QWORD *)(a2 + 456) = 0;
  *(_QWORD *)(a2 + 464) = 0;
  *(_QWORD *)(a2 + 472) = 0;
  *(_QWORD *)(a2 + 480) = 0;
  *(_QWORD *)(a2 + 488) = 0;
  *(_DWORD *)(a2 + 572) = 1046562734;
  *(float *)(a2 + 576) = s_aim_transition_time;
  *(float *)(a2 + 592) = s_aim_transition_time;
  *(float *)(a2 + 580) = FLOAT_0_1;
  *(_DWORD *)(a2 + 596) = 1093874483;
  v21 = (vostok::render::resource_manager *)clear_value;
  *(_DWORD *)(a2 + 588) = 1008981770;
  LODWORD(v25) = v21;
  HIDWORD(v25) = v21;
  *(_QWORD *)(a2 + 264) = v25;
  v26[0] = v21;
  v26[1] = v21;
  v22 = *(_QWORD *)v26;
  *(_DWORD *)(a2 + 584) = 1045220557;
  *(_QWORD *)(a2 + 272) = v22;
  LODWORD(v25) = v21;
  HIDWORD(v25) = v21;
  *(_QWORD *)(a2 + 280) = v25;
  *(_DWORD *)(a2 + 48) = 1017370378;
  *(_DWORD *)(a2 + 688) = 1045220557;
  *(_DWORD *)(a2 + 296) = v21;
  *(_DWORD *)(a2 + 300) = v21;
  *(_BYTE *)(a2 + 45) = 1;
  *(_DWORD *)(a2 + 600) = v21;
  *(_DWORD *)(a2 + 620) = 0;
  *(_DWORD *)(a2 + 628) = v21;
  *(_DWORD *)(a2 + 632) = v21;
  *(_BYTE *)(a2 + 636) = 0;
  *(_DWORD *)(a2 + 228) = v21;
  *(_DWORD *)(a2 + 640) = v21;
  *(_DWORD *)(a2 + 644) = v21;
  *(_DWORD *)(a2 + 648) = v21;
  *(_DWORD *)(a2 + 676) = 16;
  *(_DWORD *)(a2 + 680) = v21;
  *(_DWORD *)(a2 + 684) = v21;
  *(_DWORD *)(a2 + 692) = 1061158912;
  v26[0] = v21;
  v26[1] = v21;
  *(_QWORD *)(a2 + 288) = *(_QWORD *)v26;
  *(float *)(a2 + 304) = FLOAT_0_5;
  *(float *)(a2 + 696) = FLOAT_0_5;
  *(float *)&v25 = FLOAT_0_5;
  *(_DWORD *)(a2 + 700) = 1066192077;
  HIDWORD(v25) = 1060320051;
  *(_QWORD *)(a2 + 608) = v25;
  *(_DWORD *)(a2 + 624) = 1112014848;
  *(float *)(a2 + 220) = retry_to_increase_quality_period_sec;
  *(_DWORD *)(a2 + 224) = 1040187392;
  *(_DWORD *)(a2 + 52) = 1;
  *(_BYTE *)(a2 + 604) = 1;
  *(_BYTE *)(a2 + 153) = 1;
  *(_DWORD *)(a2 + 672) = 1;
  *(_DWORD *)(a2 + 616) = v21;
  *(_DWORD *)(a2 + 704) = 5;
  *(_DWORD *)(a2 + 708) = v21;
  *(_DWORD *)(a2 + 712) = 1148846080;
  *(_DWORD *)(a2 + 716) = 1040187392;
  *(_BYTE *)(a2 + 720) = 1;
  *(_DWORD *)(a2 + 536) = v21;
  LODWORD(v25) = v21;
  HIDWORD(v25) = v21;
  *(_QWORD *)(a2 + 540) = v25;
  v26[0] = v21;
  v26[1] = v21;
  *(_QWORD *)(a2 + 548) = *(_QWORD *)v26;
  *(_DWORD *)(a2 + 556) = v21;
  *(_DWORD *)(a2 + 560) = 1048576000;
  LODWORD(v25) = v21;
  HIDWORD(v25) = v21;
  *(_QWORD *)(a2 + 516) = v25;
  *(_DWORD *)(a2 + 524) = v21;
  *(_DWORD *)(a2 + 528) = v21;
  *(_BYTE *)(a2 + 532) = 1;
  *(_DWORD *)(a2 + 564) = 0;
  *(_DWORD *)(a2 + 568) = 0;
  *(_BYTE *)(a2 + 721) = 1;
}
