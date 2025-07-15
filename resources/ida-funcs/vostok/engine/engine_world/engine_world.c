void __userpurge vostok::engine::engine_world::engine_world(
        vostok::engine::engine_world *this@<ecx>,
        int a2@<eax>,
        vostok::engine_user::module_proxy *proxy,
        const char *command_line,
        const char *application,
        const char *build_date)
{
  _DWORD *v7; // eax
  char *v8; // eax
  const char *v9; // ecx
  vostok::logging::format_specifier *v10; // eax
  const char *v11; // ecx
  vostok::logging::format_specifier *v12; // eax
  const char *v13; // ecx
  vostok::logging::format_specifier *v14; // eax
  const char *v15; // ecx
  int v16; // edi
  vostok::logging::format_specifier v17; // [esp+14h] [ebp-2B8h] BYREF
  vostok::logging::format_specifier left; // [esp+20h] [ebp-2ACh] BYREF
  vostok::logging::format_specifier format_expression; // [esp+2Ch] [ebp-2A0h] BYREF
  vostok::logging::format_specifier v20; // [esp+38h] [ebp-294h] BYREF
  vostok::logging::format_specifier v21; // [esp+44h] [ebp-288h] BYREF
  vostok::logging::format_specifier v22; // [esp+50h] [ebp-27Ch] BYREF
  vostok::logging::format_specifier v23; // [esp+5Ch] [ebp-270h] BYREF
  vostok::logging::format_specifier right; // [esp+68h] [ebp-264h] BYREF
  _BYTE *v25; // [esp+74h] [ebp-258h]
  _BYTE *v26; // [esp+78h] [ebp-254h]
  vostok::logging::format_specifier *v27; // [esp+7Ch] [ebp-250h]
  _BYTE v28[128]; // [esp+80h] [ebp-24Ch] BYREF
  vostok::logging::format_specifier v29; // [esp+100h] [ebp-1CCh] BYREF
  _BYTE *v30; // [esp+10Ch] [ebp-1C0h]
  _BYTE *v31; // [esp+110h] [ebp-1BCh]
  vostok::logging::format_specifier *v32; // [esp+114h] [ebp-1B8h]
  _BYTE v33[128]; // [esp+118h] [ebp-1B4h] BYREF
  vostok::logging::format_specifier v34; // [esp+198h] [ebp-134h] BYREF
  _BYTE *v35; // [esp+1A4h] [ebp-128h]
  _BYTE *v36; // [esp+1A8h] [ebp-124h]
  vostok::logging::format_specifier *v37; // [esp+1ACh] [ebp-120h]
  _BYTE v38[128]; // [esp+1B0h] [ebp-11Ch] BYREF
  vostok::logging::format_specifier v39; // [esp+230h] [ebp-9Ch] BYREF
  _BYTE *v40; // [esp+23Ch] [ebp-90h]
  _BYTE *v41; // [esp+240h] [ebp-8Ch]
  char *v42; // [esp+244h] [ebp-88h]
  _BYTE v43[128]; // [esp+248h] [ebp-84h] BYREF
  char v44; // [esp+2C8h] [ebp-4h] BYREF

  *(_DWORD *)a2 = &vostok::engine::engine_world::`vftable'{for `vostok::core::engine'};
  *(_DWORD *)(a2 + 4) = &vostok::engine::engine_world::`vftable'{for `vostok::engine_user::engine'};
  *(_DWORD *)(a2 + 8) = &vostok::engine::engine_world::`vftable'{for `vostok::editor::engine'};
  *(_DWORD *)(a2 + 16) = &vostok::fs_new::windows_hdd_file_system::`vftable';
  *(_DWORD *)(a2 + 20) = &vostok::fs_new::windows_hdd_file_system::`vftable';
  v7 = (_DWORD *)(a2 + 24);
  v7[50] = v7;
  v7[51] = 0;
  v7[52] = 0;
  *(_DWORD *)(a2 + 440) = a2 + 240;
  *(_DWORD *)(a2 + 444) = 0;
  *(_DWORD *)(a2 + 448) = 0;
  *(_DWORD *)(a2 + 460) = 0;
  *(_DWORD *)(a2 + 464) = 0;
  *(_DWORD *)(a2 + 468) = 0;
  *(_DWORD *)(a2 + 456) = &vostok::memory::doug_lea_allocator::`vftable';
  *(_DWORD *)(a2 + 476) = 0;
  *(_DWORD *)(a2 + 480) = "invalid thread id";
  *(_DWORD *)(a2 + 484) = 1;
  *(_BYTE *)(a2 + 488) = 0;
  *(_DWORD *)(a2 + 492) = GetCurrentThreadId();
  *(_BYTE *)(a2 + 496) = 1;
  *(_BYTE *)(a2 + 497) = 0;
  *(_BYTE *)(a2 + 498) = 0;
  *(_BYTE *)(a2 + 499) = 1;
  *(_DWORD *)(a2 + 504) = 0;
  *(_DWORD *)(a2 + 508) = 0;
  *(_DWORD *)(a2 + 512) = 0;
  *(_DWORD *)(a2 + 500) = &vostok::memory::doug_lea_allocator::`vftable';
  *(_DWORD *)(a2 + 520) = 0;
  *(_DWORD *)(a2 + 524) = "invalid thread id";
  *(_DWORD *)(a2 + 528) = 1;
  *(_BYTE *)(a2 + 532) = 0;
  *(_DWORD *)(a2 + 536) = GetCurrentThreadId();
  *(_BYTE *)(a2 + 540) = 1;
  *(_BYTE *)(a2 + 541) = 0;
  *(_BYTE *)(a2 + 542) = 0;
  *(_BYTE *)(a2 + 543) = 1;
  *(_DWORD *)(a2 + 548) = 0;
  *(_DWORD *)(a2 + 552) = 0;
  *(_DWORD *)(a2 + 556) = 0;
  *(_DWORD *)(a2 + 544) = &vostok::memory::doug_lea_allocator::`vftable';
  *(_DWORD *)(a2 + 564) = 0;
  *(_DWORD *)(a2 + 568) = "invalid thread id";
  *(_DWORD *)(a2 + 572) = 1;
  *(_BYTE *)(a2 + 576) = 0;
  *(_DWORD *)(a2 + 580) = GetCurrentThreadId();
  *(_BYTE *)(a2 + 584) = 1;
  *(_BYTE *)(a2 + 585) = 0;
  *(_BYTE *)(a2 + 586) = 0;
  *(_BYTE *)(a2 + 587) = 1;
  *(_DWORD *)(a2 + 592) = 0;
  *(_DWORD *)(a2 + 596) = 0;
  *(_DWORD *)(a2 + 600) = 0;
  *(_DWORD *)(a2 + 588) = &vostok::memory::doug_lea_allocator::`vftable';
  *(_DWORD *)(a2 + 608) = 0;
  *(_DWORD *)(a2 + 612) = "invalid thread id";
  *(_DWORD *)(a2 + 616) = 1;
  *(_BYTE *)(a2 + 620) = 0;
  *(_DWORD *)(a2 + 624) = GetCurrentThreadId();
  *(_BYTE *)(a2 + 628) = 1;
  *(_BYTE *)(a2 + 629) = 0;
  *(_BYTE *)(a2 + 630) = 0;
  *(_BYTE *)(a2 + 631) = 1;
  *(_DWORD *)(a2 + 632) = 0;
  *(_DWORD *)(a2 + 636) = 0;
  *(_DWORD *)(a2 + 640) = 0;
  *(_DWORD *)(a2 + 644) = 0;
  *(_DWORD *)(a2 + 648) = 0;
  *(_DWORD *)(a2 + 652) = proxy;
  *(_DWORD *)(a2 + 656) = 0;
  *(_DWORD *)(a2 + 660) = 0;
  *(_DWORD *)(a2 + 664) = 0;
  *(_DWORD *)(a2 + 668) = 0;
  *(_DWORD *)(a2 + 672) = 0;
  *(_DWORD *)(a2 + 676) = 0;
  *(_DWORD *)(a2 + 680) = 0;
  *(_DWORD *)(a2 + 684) = 0;
  *(_DWORD *)(a2 + 688) = 0;
  *(_DWORD *)(a2 + 692) = 0;
  *(_DWORD *)(a2 + 696) = 0;
  *(_DWORD *)(a2 + 700) = 0;
  *(_DWORD *)(a2 + 704) = 0;
  *(_BYTE *)(a2 + 708) = 0;
  *(_BYTE *)(a2 + 709) = 0;
  *(_BYTE *)(a2 + 710) = 1;
  *(_BYTE *)(a2 + 711) = 1;
  *(_BYTE *)(a2 + 712) = 0;
  *(_BYTE *)(a2 + 713) = 0;
  *(_BYTE *)(a2 + 714) = 0;
  vostok::timing::timer::timer((vostok::timing::timer *)(a2 + 720));
  vostok::core::preinitialize((vostok::core::engine *)a2, create_log, command_line);
  vostok::logging::format_specifier::format_specifier(&v39, format_specifier_separator);
  v8 = v43;
  v42 = &v44;
  v40 = v43;
  v41 = v43;
  v43[0] = 0;
  v9 = "]\t";
  do
  {
    if ( v8 >= v42 )
      break;
    *v8 = *v9;
    v8 = v41 + 1;
    ++v9;
    ++v41;
  }
  while ( *v9 );
  *v8 = 0;
  vostok::logging::format_specifier::format_specifier(&v29, format_specifier_separator);
  v10 = (vostok::logging::format_specifier *)v33;
  v32 = &v34;
  v30 = v33;
  v31 = v33;
  v33[0] = 0;
  v11 = "[";
  do
  {
    if ( v10 >= v32 )
      break;
    LOBYTE(v10->m_left) = *v11;
    v10 = (vostok::logging::format_specifier *)(v31 + 1);
    ++v11;
    ++v31;
  }
  while ( *v11 );
  LOBYTE(v10->m_left) = 0;
  vostok::logging::format_specifier::format_specifier(&v34, format_specifier_separator);
  v12 = (vostok::logging::format_specifier *)v38;
  v37 = &v39;
  v35 = v38;
  v36 = v38;
  v38[0] = 0;
  v13 = ">\t";
  do
  {
    if ( v12 >= v37 )
      break;
    LOBYTE(v12->m_left) = *v13;
    v12 = (vostok::logging::format_specifier *)(v36 + 1);
    ++v13;
    ++v36;
  }
  while ( *v13 );
  LOBYTE(v12->m_left) = 0;
  vostok::logging::format_specifier::format_specifier(&right, format_specifier_separator);
  v14 = (vostok::logging::format_specifier *)v28;
  v27 = &v29;
  v25 = v28;
  v26 = v28;
  v28[0] = 0;
  v15 = " <";
  do
  {
    if ( v14 >= v27 )
      break;
    LOBYTE(v14->m_left) = *v15;
    v14 = (vostok::logging::format_specifier *)(v26 + 1);
    ++v15;
    ++v26;
  }
  while ( *v15 );
  LOBYTE(v14->m_left) = 0;
  vostok::logging::format_specifier::format_specifier(&left, &vostok::logging::format_initiator, &right);
  vostok::logging::format_specifier::format_specifier(&v21, &left, &vostok::logging::format_verbosity);
  vostok::logging::format_specifier::format_specifier(&v20, &v21, &v34);
  vostok::logging::format_specifier::format_specifier(&v23, &v20, &v29);
  vostok::logging::format_specifier::format_specifier(&v22, &v23, &vostok::logging::format_time);
  vostok::logging::format_specifier::format_specifier(&v17, &v22, &v39);
  vostok::logging::format_specifier::format_specifier(&format_expression, &v17, &vostok::logging::format_message);
  vostok::logging::log_format::set(&vostok::core::g_log_format, &format_expression);
  vostok::memory::register_allocator(&vostok::engine::g_allocator, (unsigned int)&_sbh_sizeHeaderList, "engine");
  vostok::engine::g_scaleform_allocator = &vostok::memory::g_mt_allocator;
  vostok::memory::register_allocator((vostok::memory::base_allocator *)(a2 + 544), 0x10000000u, "render");
  vostok::memory::register_allocator((vostok::memory::base_allocator *)(a2 + 456), (unsigned int)&unk_800000, "network");
  vostok::memory::register_allocator(
    (vostok::memory::base_allocator *)(a2 + 500),
    (unsigned int)&loc_FFFFF + 1,
    "sound");
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 652) + 8))(*(_DWORD *)(a2 + 652));
  v16 = 0;
  if ( s_editor_mode )
  {
    v16 = 335544320;
    vostok::memory::register_allocator((vostok::memory::base_allocator *)(a2 + 588), 0x8000000u, "editor");
  }
  vostok::memory::allocate_region((unsigned int)v16, (unsigned int)v16);
  vostok::network::initialize();
}
