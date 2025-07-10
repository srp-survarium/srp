void __cdecl stlp_std::ios_base::_S_uninitialize()
{
  _DWORD *v0; // ecx
  int v1; // eax
  _DWORD *v2; // ecx
  int v3; // eax
  _DWORD *v4; // ecx
  int v5; // eax
  _DWORD *v6; // ecx
  int v7; // eax
  stlp_std::ios_base *v8; // eax
  void (__thiscall ***M_fmtflags)(_DWORD, int); // ecx
  stlp_std::ios_base *v10; // eax
  void (__thiscall ***v11)(_DWORD, int); // ecx
  stlp_std::ios_base *v12; // eax
  void (__thiscall ***v13)(_DWORD, int); // ecx
  stlp_std::ios_base *v14; // eax
  void (__thiscall ***v15)(_DWORD, int); // ecx
  _DWORD *v16; // ecx
  int v17; // eax
  _DWORD *v18; // ecx
  int v19; // eax
  _DWORD *v20; // ecx
  int v21; // eax
  _DWORD *v22; // ecx
  int v23; // eax
  stlp_std::ios_base *v24; // eax
  void (__thiscall ***v25)(_DWORD, int); // ecx
  stlp_std::ios_base *v26; // eax
  void (__thiscall ***v27)(_DWORD, int); // ecx
  stlp_std::ios_base *v28; // eax
  void (__thiscall ***v29)(_DWORD, int); // ecx
  stlp_std::ios_base *v30; // eax
  void (__thiscall ***v31)(_DWORD, int); // ecx

  v0 = &stlp_std::cin.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cin.gap0 + 4)];
  v1 = v0[3];
  v0[6] = 0;
  if ( !v0[22] )
    v1 |= 1u;
  v0[3] = v1;
  v2 = &stlp_std::cout.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cout.gap0 + 4)];
  v3 = v2[3];
  v2[6] = 0;
  if ( !v2[22] )
    v3 |= 1u;
  v2[3] = v3;
  v4 = &stlp_std::cerr.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cerr.gap0 + 4)];
  v5 = v4[3];
  v4[6] = 0;
  if ( !v4[22] )
    v5 |= 1u;
  v4[3] = v5;
  v6 = &stlp_std::clog.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::clog.gap0 + 4)];
  v7 = v6[3];
  v6[6] = 0;
  if ( !v6[22] )
    v7 |= 1u;
  v6[3] = v7;
  v8 = (stlp_std::ios_base *)&stlp_std::cin.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cin.gap0 + 4)];
  M_fmtflags = (void (__thiscall ***)(_DWORD, int))v8[1]._M_fmtflags;
  v8[1]._M_fmtflags = 0;
  v8->_M_iostate = 1;
  if ( (v8->_M_exception_mask & 1) != 0 )
    stlp_std::ios_base::_M_throw_failure(v8);
  if ( M_fmtflags )
    (**M_fmtflags)(M_fmtflags, 1);
  v10 = (stlp_std::ios_base *)&stlp_std::cout.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cout.gap0 + 4)];
  v11 = (void (__thiscall ***)(_DWORD, int))v10[1]._M_fmtflags;
  v10[1]._M_fmtflags = 0;
  v10->_M_iostate = 1;
  if ( (v10->_M_exception_mask & 1) != 0 )
    stlp_std::ios_base::_M_throw_failure(v10);
  if ( v11 )
    (**v11)(v11, 1);
  v12 = (stlp_std::ios_base *)&stlp_std::cerr.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cerr.gap0 + 4)];
  v13 = (void (__thiscall ***)(_DWORD, int))v12[1]._M_fmtflags;
  v12[1]._M_fmtflags = 0;
  v12->_M_iostate = 1;
  if ( (v12->_M_exception_mask & 1) != 0 )
    stlp_std::ios_base::_M_throw_failure(v12);
  if ( v13 )
    (**v13)(v13, 1);
  v14 = (stlp_std::ios_base *)&stlp_std::clog.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::clog.gap0 + 4)];
  v15 = (void (__thiscall ***)(_DWORD, int))v14[1]._M_fmtflags;
  v14[1]._M_fmtflags = 0;
  v14->_M_iostate = 1;
  if ( (v14->_M_exception_mask & 1) != 0 )
    stlp_std::ios_base::_M_throw_failure(v14);
  if ( v15 )
    (**v15)(v15, 1);
  (**(void (__thiscall ***)(_BYTE *, _DWORD))&stlp_std::cin.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cin.gap0 + 4)])(
    &stlp_std::cin.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cin.gap0 + 4)],
    0);
  (**(void (__thiscall ***)(_BYTE *, _DWORD))&stlp_std::cout.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cout.gap0 + 4)])(
    &stlp_std::cout.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cout.gap0 + 4)],
    0);
  (**(void (__thiscall ***)(_BYTE *, _DWORD))&stlp_std::cerr.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cerr.gap0 + 4)])(
    &stlp_std::cerr.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::cerr.gap0 + 4)],
    0);
  (**(void (__thiscall ***)(_BYTE *, _DWORD))&stlp_std::clog.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::clog.gap0 + 4)])(
    &stlp_std::clog.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::clog.gap0 + 4)],
    0);
  v16 = &stlp_std::wcin.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcin.gap0 + 4)];
  v17 = v16[3];
  v16[6] = 0;
  if ( !v16[22] )
    v17 |= 1u;
  v16[3] = v17;
  v18 = &stlp_std::wcout.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcout.gap0 + 4)];
  v19 = v18[3];
  v18[6] = 0;
  if ( !v18[22] )
    v19 |= 1u;
  v18[3] = v19;
  v20 = &stlp_std::wcerr.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcerr.gap0 + 4)];
  v21 = v20[3];
  v20[6] = 0;
  if ( !v20[22] )
    v21 |= 1u;
  v20[3] = v21;
  v22 = &stlp_std::wclog.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wclog.gap0 + 4)];
  v23 = v22[3];
  v22[6] = 0;
  if ( !v22[22] )
    v23 |= 1u;
  v22[3] = v23;
  v24 = (stlp_std::ios_base *)&stlp_std::wcin.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcin.gap0 + 4)];
  v25 = (void (__thiscall ***)(_DWORD, int))v24[1]._M_fmtflags;
  v24[1]._M_fmtflags = 0;
  v24->_M_iostate = 1;
  if ( (v24->_M_exception_mask & 1) != 0 )
    stlp_std::ios_base::_M_throw_failure(v24);
  if ( v25 )
    (**v25)(v25, 1);
  v26 = (stlp_std::ios_base *)&stlp_std::wcout.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcout.gap0 + 4)];
  v27 = (void (__thiscall ***)(_DWORD, int))v26[1]._M_fmtflags;
  v26[1]._M_fmtflags = 0;
  v26->_M_iostate = 1;
  if ( (v26->_M_exception_mask & 1) != 0 )
    stlp_std::ios_base::_M_throw_failure(v26);
  if ( v27 )
    (**v27)(v27, 1);
  v28 = (stlp_std::ios_base *)&stlp_std::wcerr.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcerr.gap0 + 4)];
  v29 = (void (__thiscall ***)(_DWORD, int))v28[1]._M_fmtflags;
  v28[1]._M_fmtflags = 0;
  v28->_M_iostate = 1;
  if ( (v28->_M_exception_mask & 1) != 0 )
    stlp_std::ios_base::_M_throw_failure(v28);
  if ( v29 )
    (**v29)(v29, 1);
  v30 = (stlp_std::ios_base *)&stlp_std::wclog.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wclog.gap0 + 4)];
  v31 = (void (__thiscall ***)(_DWORD, int))v30[1]._M_fmtflags;
  v30[1]._M_fmtflags = 0;
  v30->_M_iostate = 1;
  if ( (v30->_M_exception_mask & 1) != 0 )
    stlp_std::ios_base::_M_throw_failure(v30);
  if ( v31 )
    (**v31)(v31, 1);
  (**(void (__thiscall ***)(_BYTE *, _DWORD))&stlp_std::wcin.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcin.gap0 + 4)])(
    &stlp_std::wcin.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcin.gap0 + 4)],
    0);
  (**(void (__thiscall ***)(_BYTE *, _DWORD))&stlp_std::wcout.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcout.gap0 + 4)])(
    &stlp_std::wcout.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcout.gap0 + 4)],
    0);
  (**(void (__thiscall ***)(_BYTE *, _DWORD))&stlp_std::wcerr.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcerr.gap0 + 4)])(
    &stlp_std::wcerr.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wcerr.gap0 + 4)],
    0);
  (**(void (__thiscall ***)(_BYTE *, _DWORD))&stlp_std::wclog.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wclog.gap0 + 4)])(
    &stlp_std::wclog.gap0[*(_DWORD *)(*(_DWORD *)stlp_std::wclog.gap0 + 4)],
    0);
}
