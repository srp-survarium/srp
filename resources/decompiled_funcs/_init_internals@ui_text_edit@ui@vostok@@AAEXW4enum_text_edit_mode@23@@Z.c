void __thiscall vostok::ui::ui_text_edit::init_internals(
        vostok::ui::ui_text_edit *this,
        vostok::ui::base_edit_action *mode)
{
  vostok::ui::enum_text_edit_mode v2; // ebp
  vostok::input::enum_keyboard_action m_key_action; // ecx
  int (__thiscall *v4)(vostok::input::enum_keyboard_action, int); // edx
  int v5; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v6; // ecx
  int v7; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v8; // ecx
  int v9; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v10; // ecx
  int v11; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v12; // ecx
  int v13; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v14; // ecx
  int v15; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v16; // ecx
  int v17; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v18; // ecx
  int v19; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v20; // ecx
  int v21; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v22; // ecx
  int v23; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v24; // ecx
  int v25; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v26; // ecx
  int v27; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v28; // ecx
  int v29; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v30; // ecx
  fastdelegate::detail::GenericClass *v31; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v32; // ecx
  fastdelegate::detail::GenericClass *v33; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v34; // ecx
  fastdelegate::detail::GenericClass *v35; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v36; // ecx
  fastdelegate::detail::GenericClass *v37; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v38; // ecx
  fastdelegate::detail::GenericClass *v39; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v40; // ecx
  vostok::ui::base_edit_action *v41; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v42; // ecx
  vostok::ui::base_edit_action *v43; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v44; // ecx
  vostok::ui::base_edit_action *v45; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v46; // ecx
  vostok::ui::base_edit_action *v47; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v48; // ecx
  vostok::ui::base_edit_action *v49; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v50; // ecx
  vostok::input::world *v51; // edi
  vostok::ui::base_edit_action *char_action; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v53; // ecx
  vostok::ui::base_edit_action *v54; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v55; // ecx
  vostok::ui::base_edit_action *v56; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v57; // ecx
  vostok::ui::base_edit_action *v58; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v59; // ecx
  vostok::ui::base_edit_action *v60; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v61; // ecx
  vostok::ui::base_edit_action *v62; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v63; // ecx
  vostok::ui::base_edit_action *v64; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v65; // ecx
  vostok::ui::base_edit_action *v66; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v67; // ecx
  vostok::ui::base_edit_action *v68; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v69; // ecx
  vostok::ui::base_edit_action *v70; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v71; // ecx
  vostok::ui::base_edit_action *v72; // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v73; // ecx
  vostok::ui::base_edit_action *v74; // eax
  vostok::ui::ui_text_edit *v75; // ecx
  vostok::ui::base_edit_action *v76; // eax
  vostok::ui::ui_text_edit *v77; // ecx
  vostok::ui::base_edit_action *v78; // eax
  vostok::ui::ui_text_edit *v79; // ecx
  vostok::ui::base_edit_action *v80; // eax
  vostok::ui::ui_text_edit *v81; // ecx
  vostok::ui::base_edit_action *v82; // eax
  vostok::ui::ui_text_edit *v83; // ecx
  vostok::ui::base_edit_action *v84; // eax
  vostok::ui::ui_text_edit *v85; // ecx
  vostok::ui::base_edit_action *v86; // eax
  vostok::ui::ui_text_edit *v87; // ecx
  vostok::ui::base_edit_action *v88; // eax
  vostok::ui::ui_text_edit *v89; // ecx
  vostok::ui::base_edit_action *v90; // eax
  vostok::ui::ui_text_edit *v91; // ecx
  vostok::ui::base_edit_action *v92; // eax
  vostok::ui::ui_text_edit *v93; // ecx
  vostok::ui::base_edit_action *v94; // eax
  vostok::ui::ui_text_edit *v95; // ecx
  vostok::ui::base_edit_action *v96; // eax
  vostok::ui::ui_text_edit *v97; // ecx
  vostok::ui::base_edit_action *v98; // eax
  vostok::ui::ui_text_edit *v99; // ecx
  vostok::ui::base_edit_action *v100; // eax
  vostok::ui::ui_text_edit *v101; // ecx
  vostok::ui::base_edit_action *v102; // eax
  vostok::ui::ui_text_edit *v103; // ecx
  vostok::ui::base_edit_action *v104; // eax
  vostok::ui::ui_text_edit *v105; // ecx
  vostok::ui::base_edit_action *v106; // eax
  vostok::ui::ui_text_edit *v107; // ecx
  vostok::ui::base_edit_action *v108; // eax
  vostok::ui::ui_text_edit *v109; // ecx
  vostok::ui::base_edit_action *v110; // eax
  vostok::ui::ui_text_edit *v111; // ecx
  vostok::ui::base_edit_action *v112; // eax
  vostok::ui::ui_text_edit *v113; // ecx
  vostok::ui::base_edit_action *v114; // eax
  vostok::ui::ui_text_edit *v115; // ecx
  vostok::ui::base_edit_action *v116; // eax
  vostok::ui::ui_text_edit *v117; // ecx
  vostok::ui::base_edit_action *v118; // eax
  vostok::ui::ui_text_edit *v119; // ecx
  vostok::ui::base_edit_action *v120; // eax
  vostok::ui::ui_text_edit *v121; // ecx
  vostok::ui::base_edit_action *v122; // eax
  vostok::ui::ui_text_edit *v123; // ecx
  vostok::ui::base_edit_action *v124; // eax
  vostok::ui::ui_text_edit *v125; // ecx
  vostok::ui::base_edit_action *v126; // eax
  vostok::ui::ui_text_edit *v127; // ecx
  vostok::ui::base_edit_action *v128; // eax
  vostok::ui::ui_text_edit *v129; // ecx
  vostok::ui::base_edit_action *v130; // eax
  vostok::ui::ui_text_edit *v131; // ecx
  vostok::ui::base_edit_action *v132; // eax
  vostok::ui::ui_text_edit *v133; // ecx
  vostok::ui::base_edit_action *v134; // eax
  vostok::ui::ui_text_edit *v135; // ecx
  vostok::ui::base_edit_action *v136; // eax
  vostok::ui::ui_text_edit *v137; // ecx
  vostok::ui::base_edit_action *v138; // eax
  vostok::ui::ui_text_edit *v139; // ecx
  vostok::ui::base_edit_action *v140; // eax
  vostok::ui::ui_text_edit *v141; // ecx
  vostok::ui::base_edit_action *v142; // eax
  vostok::ui::ui_text_edit *v143; // ecx
  vostok::ui::base_edit_action *v144; // eax
  vostok::ui::ui_text_edit *v145; // ecx
  vostok::ui::base_edit_action *v146; // eax
  vostok::ui::ui_text_edit *v147; // ecx
  vostok::ui::base_edit_action *v148; // eax
  vostok::ui::ui_text_edit *v149; // ecx
  vostok::ui::base_edit_action *v150; // eax
  vostok::ui::ui_text_edit *v151; // ecx
  vostok::ui::base_edit_action *v152; // eax
  vostok::ui::ui_text_edit *v153; // ecx
  vostok::ui::base_edit_action *v154; // eax
  vostok::ui::ui_text_edit *v155; // ecx
  vostok::ui::base_edit_action *v156; // eax
  vostok::ui::ui_text_edit *v157; // ecx
  vostok::ui::base_edit_action *v158; // eax
  vostok::ui::ui_text_edit *v159; // ecx
  vostok::ui::base_edit_action *v160; // eax
  vostok::ui::ui_text_edit *v161; // ecx
  vostok::ui::base_edit_action *v162; // eax
  vostok::ui::ui_text_edit *v163; // ecx
  vostok::ui::base_edit_action *v164; // eax
  vostok::ui::ui_text_edit *v165; // ecx
  vostok::ui::base_edit_action *v166; // eax
  vostok::ui::ui_text_edit *v167; // ecx
  vostok::ui::base_edit_action *v168; // eax
  vostok::ui::ui_text_edit *v169; // ecx
  vostok::ui::base_edit_action *v170; // eax
  vostok::ui::ui_text_edit *v171; // ecx
  vostok::ui::base_edit_action *v172; // eax
  vostok::ui::ui_text_edit *v173; // ecx
  vostok::ui::base_edit_action *v174; // eax
  vostok::ui::ui_text_edit *v175; // ecx
  vostok::ui::base_edit_action *v176; // eax
  vostok::ui::ui_text_edit *v177; // ecx
  const stlp_std::__true_type *v178; // [esp+20h] [ebp-20h]
  unsigned int v179; // [esp+24h] [ebp-1Ch]
  bool v180; // [esp+28h] [ebp-18h]
  vostok::ui::shift_state none_sh_state; // [esp+34h] [ebp-Ch] BYREF
  vostok::ui::shift_state shift_sh_state; // [esp+35h] [ebp-Bh] BYREF
  vostok::ui::shift_state ctrl_shift_sh_state; // [esp+36h] [ebp-Ah] BYREF
  vostok::ui::shift_state any_sh_state; // [esp+37h] [ebp-9h] BYREF
  fastdelegate::FastDelegate0<void> __x; // [esp+38h] [ebp-8h] BYREF

  v2 = (vostok::ui::enum_text_edit_mode)mode;
  m_key_action = mode->m_key_action;
  v4 = *(int (__thiscall **)(vostok::input::enum_keyboard_action, int))(*(_DWORD *)m_key_action + 16);
  any_sh_state.m_data.d = (vostok::ui::shift_state::data_storage::<unnamed_type_d>)-86;
  none_sh_state.m_data.d = 0;
  LOBYTE(mode) = 1;
  shift_sh_state.m_data.d = (vostok::ui::shift_state::data_storage::<unnamed_type_d>)16;
  ctrl_shift_sh_state.m_data.d = (vostok::ui::shift_state::data_storage::<unnamed_type_d>)17;
  v5 = v4(m_key_action, 24);
  if ( v5 )
  {
    *(_DWORD *)(v5 + 4) = v2;
    *(_DWORD *)(v5 + 8) = 42;
    *(_DWORD *)(v5 + 12) = 0;
    *(_BYTE *)(v5 + 16) = -86;
    *(_DWORD *)v5 = &vostok::ui::shift_state_action::`vftable';
    *(_DWORD *)(v5 + 20) = 0;
  }
  else
  {
    v5 = 0;
  }
  v6 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v5;
  if ( v6 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v6,
      (unsigned __int8 **)(v2 + 616),
      (int)v6,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v6->_M_start = (unsigned int *)v5;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v7 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 24);
  if ( v7 )
  {
    *(_DWORD *)(v7 + 4) = v2;
    *(_DWORD *)(v7 + 8) = 54;
    *(_DWORD *)(v7 + 12) = 0;
    *(_BYTE *)(v7 + 16) = -86;
    *(_DWORD *)v7 = &vostok::ui::shift_state_action::`vftable';
    *(_DWORD *)(v7 + 20) = 0;
  }
  else
  {
    v7 = 0;
  }
  v8 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v7;
  if ( v8 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v8,
      (unsigned __int8 **)(v2 + 616),
      (int)v8,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v8->_M_start = (unsigned int *)v7;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v9 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 24);
  if ( v9 )
  {
    *(_DWORD *)(v9 + 4) = v2;
    *(_DWORD *)(v9 + 8) = 29;
    *(_DWORD *)(v9 + 12) = 0;
    *(_BYTE *)(v9 + 16) = -86;
    *(_DWORD *)v9 = &vostok::ui::shift_state_action::`vftable';
    *(_DWORD *)(v9 + 20) = 1;
  }
  else
  {
    v9 = 0;
  }
  v10 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v9;
  if ( v10 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v10,
      (unsigned __int8 **)(v2 + 616),
      (int)v10,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v10->_M_start = (unsigned int *)v9;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v11 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 24);
  if ( v11 )
  {
    *(_DWORD *)(v11 + 4) = v2;
    *(_DWORD *)(v11 + 8) = 157;
    *(_DWORD *)(v11 + 12) = 0;
    *(_BYTE *)(v11 + 16) = -86;
    *(_DWORD *)v11 = &vostok::ui::shift_state_action::`vftable';
    *(_DWORD *)(v11 + 20) = 1;
  }
  else
  {
    v11 = 0;
  }
  v12 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v11;
  if ( v12 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v12,
      (unsigned __int8 **)(v2 + 616),
      (int)v12,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v12->_M_start = (unsigned int *)v11;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v13 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 24);
  if ( v13 )
  {
    *(_DWORD *)(v13 + 4) = v2;
    *(_DWORD *)(v13 + 8) = 56;
    *(_DWORD *)(v13 + 12) = 0;
    *(_BYTE *)(v13 + 16) = -86;
    *(_DWORD *)v13 = &vostok::ui::shift_state_action::`vftable';
    *(_DWORD *)(v13 + 20) = 2;
  }
  else
  {
    v13 = 0;
  }
  v14 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v13;
  if ( v14 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v14,
      (unsigned __int8 **)(v2 + 616),
      (int)v14,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v14->_M_start = (unsigned int *)v13;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v15 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 24);
  if ( v15 )
  {
    *(_DWORD *)(v15 + 4) = v2;
    *(_DWORD *)(v15 + 8) = 184;
    *(_DWORD *)(v15 + 12) = 0;
    *(_BYTE *)(v15 + 16) = -86;
    *(_DWORD *)v15 = &vostok::ui::shift_state_action::`vftable';
    *(_DWORD *)(v15 + 20) = 2;
  }
  else
  {
    v15 = 0;
  }
  v16 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v15;
  if ( v16 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v16,
      (unsigned __int8 **)(v2 + 616),
      (int)v16,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v16->_M_start = (unsigned int *)v15;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v17 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 28);
  if ( v17 )
  {
    *(_DWORD *)(v17 + 4) = v2;
    *(_DWORD *)(v17 + 8) = 203;
    *(_DWORD *)(v17 + 12) = 1;
    *(_BYTE *)(v17 + 16) = -86;
    *(_DWORD *)v17 = &vostok::ui::functor_edit_action::`vftable';
    *(_DWORD *)(v17 + 24) = vostok::ui::ui_text_edit::move_cursor_left;
    *(_DWORD *)(v17 + 20) = v2;
  }
  else
  {
    v17 = 0;
  }
  v18 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v17;
  if ( v18 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v18,
      (unsigned __int8 **)(v2 + 616),
      (int)v18,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v18->_M_start = (unsigned int *)v17;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v19 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 28);
  if ( v19 )
  {
    *(_DWORD *)(v19 + 4) = v2;
    *(_DWORD *)(v19 + 8) = 205;
    *(_DWORD *)(v19 + 12) = 1;
    *(_BYTE *)(v19 + 16) = -86;
    *(_DWORD *)v19 = &vostok::ui::functor_edit_action::`vftable';
    *(_DWORD *)(v19 + 24) = vostok::ui::ui_text_edit::move_cursor_right;
    *(_DWORD *)(v19 + 20) = v2;
  }
  else
  {
    v19 = 0;
  }
  v20 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v19;
  if ( v20 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v20,
      (unsigned __int8 **)(v2 + 616),
      (int)v20,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v20->_M_start = (unsigned int *)v19;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v21 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 28);
  if ( v21 )
  {
    *(_DWORD *)(v21 + 4) = v2;
    *(_DWORD *)(v21 + 8) = 199;
    *(_DWORD *)(v21 + 12) = 1;
    *(_BYTE *)(v21 + 16) = -86;
    *(_DWORD *)v21 = &vostok::ui::functor_edit_action::`vftable';
    *(_DWORD *)(v21 + 24) = vostok::ui::ui_text_edit::move_cursor_begin;
    *(_DWORD *)(v21 + 20) = v2;
  }
  else
  {
    v21 = 0;
  }
  v22 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v21;
  if ( v22 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v22,
      (unsigned __int8 **)(v2 + 616),
      (int)v22,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v22->_M_start = (unsigned int *)v21;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v23 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 28);
  if ( v23 )
  {
    *(_DWORD *)(v23 + 4) = v2;
    *(_DWORD *)(v23 + 8) = 207;
    *(_DWORD *)(v23 + 12) = 1;
    *(_BYTE *)(v23 + 16) = -86;
    *(_DWORD *)v23 = &vostok::ui::functor_edit_action::`vftable';
    *(_DWORD *)(v23 + 24) = vostok::ui::ui_text_edit::move_cursor_end;
    *(_DWORD *)(v23 + 20) = v2;
  }
  else
  {
    v23 = 0;
  }
  v24 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v23;
  if ( v24 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v24,
      (unsigned __int8 **)(v2 + 616),
      (int)v24,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v24->_M_start = (unsigned int *)v23;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v25 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 28);
  if ( v25 )
  {
    *(_DWORD *)(v25 + 4) = v2;
    *(_DWORD *)(v25 + 8) = 30;
    *(_DWORD *)(v25 + 12) = 1;
    *(_BYTE *)(v25 + 16) = 1;
    *(_DWORD *)v25 = &vostok::ui::functor_edit_action::`vftable';
    *(_DWORD *)(v25 + 24) = vostok::ui::ui_text_edit::select_all;
    *(_DWORD *)(v25 + 20) = v2;
  }
  else
  {
    v25 = 0;
  }
  v26 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v25;
  if ( v26 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v26,
      (unsigned __int8 **)(v2 + 616),
      (int)v26,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v26->_M_start = (unsigned int *)v25;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v27 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 28);
  if ( v27 )
  {
    *(_DWORD *)(v27 + 4) = v2;
    *(_DWORD *)(v27 + 8) = 46;
    *(_DWORD *)(v27 + 12) = 1;
    *(_BYTE *)(v27 + 16) = 1;
    *(_DWORD *)v27 = &vostok::ui::functor_edit_action::`vftable';
    *(_DWORD *)(v27 + 24) = vostok::ui::ui_text_edit::copy_to_clipboard;
    *(_DWORD *)(v27 + 20) = v2;
  }
  else
  {
    v27 = 0;
  }
  v28 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v27;
  if ( v28 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v28,
      (unsigned __int8 **)(v2 + 616),
      (int)v28,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v28->_M_start = (unsigned int *)v27;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v29 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(v2 + 12) + 16))(*(_DWORD *)(v2 + 12), 28);
  if ( v29 )
  {
    *(_DWORD *)(v29 + 4) = v2;
    *(_DWORD *)(v29 + 8) = 210;
    *(_DWORD *)(v29 + 12) = 1;
    *(_BYTE *)(v29 + 16) = 1;
    *(_DWORD *)v29 = &vostok::ui::functor_edit_action::`vftable';
    *(_DWORD *)(v29 + 24) = vostok::ui::ui_text_edit::copy_to_clipboard;
    *(_DWORD *)(v29 + 20) = v2;
  }
  else
  {
    v29 = 0;
  }
  v30 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v29;
  if ( v30 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v30,
      (unsigned __int8 **)(v2 + 616),
      (int)v30,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v30->_M_start = (unsigned int *)v29;
    *(_DWORD *)(v2 + 620) += 4;
  }
  __x.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::switch_insert_mode;
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v2;
  v31 = (fastdelegate::detail::GenericClass *)vostok::ui::create_functor(
                                                &__x,
                                                (vostok::ui::ui_text_edit *)v2,
                                                key_insert,
                                                &none_sh_state);
  v32 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = v31;
  if ( v32 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v32,
      (unsigned __int8 **)(v2 + 616),
      (int)v32,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v32->_M_start = (unsigned int *)v31;
    *(_DWORD *)(v2 + 620) += 4;
  }
  __x.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::undo;
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v2;
  v33 = (fastdelegate::detail::GenericClass *)vostok::ui::create_functor(
                                                &__x,
                                                (vostok::ui::ui_text_edit *)v2,
                                                key_z,
                                                (const vostok::ui::shift_state *)&mode);
  v34 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = v33;
  if ( v34 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v34,
      (unsigned __int8 **)(v2 + 616),
      (int)v34,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v34->_M_start = (unsigned int *)v33;
    *(_DWORD *)(v2 + 620) += 4;
  }
  __x.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::redo;
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v2;
  v35 = (fastdelegate::detail::GenericClass *)vostok::ui::create_functor(
                                                &__x,
                                                (vostok::ui::ui_text_edit *)v2,
                                                key_z,
                                                &ctrl_shift_sh_state);
  v36 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = v35;
  if ( v36 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v36,
      (unsigned __int8 **)(v2 + 616),
      (int)v36,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v36->_M_start = (unsigned int *)v35;
    *(_DWORD *)(v2 + 620) += 4;
  }
  __x.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::cut_to_clipboard;
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v2;
  v37 = (fastdelegate::detail::GenericClass *)vostok::ui::create_functor(
                                                &__x,
                                                (vostok::ui::ui_text_edit *)v2,
                                                key_x,
                                                (const vostok::ui::shift_state *)&mode);
  v38 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = v37;
  if ( v38 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v38,
      (unsigned __int8 **)(v2 + 616),
      (int)v38,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v38->_M_start = (unsigned int *)v37;
    *(_DWORD *)(v2 + 620) += 4;
  }
  __x.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::cut_to_clipboard;
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v2;
  v39 = (fastdelegate::detail::GenericClass *)vostok::ui::create_functor(
                                                &__x,
                                                (vostok::ui::ui_text_edit *)v2,
                                                key_delete,
                                                &shift_sh_state);
  v40 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  __x.m_Closure.m_pthis = v39;
  if ( v40 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v40,
      (unsigned __int8 **)(v2 + 616),
      (int)v40,
      (const unsigned int *)&__x,
      v178,
      v179,
      v180);
  }
  else
  {
    v40->_M_start = (unsigned int *)v39;
    *(_DWORD *)(v2 + 620) += 4;
  }
  __x.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::paste_from_clipboard;
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v2;
  v41 = vostok::ui::create_functor(&__x, (vostok::ui::ui_text_edit *)v2, key_v, (const vostok::ui::shift_state *)&mode);
  v42 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v41;
  if ( v42 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v42,
      (unsigned __int8 **)(v2 + 616),
      (int)v42,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v42->_M_start = (unsigned int *)v41;
    *(_DWORD *)(v2 + 620) += 4;
  }
  __x.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::paste_from_clipboard;
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v2;
  v43 = vostok::ui::create_functor(&__x, (vostok::ui::ui_text_edit *)v2, key_insert, &shift_sh_state);
  v44 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v43;
  if ( v44 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v44,
      (unsigned __int8 **)(v2 + 616),
      (int)v44,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v44->_M_start = (unsigned int *)v43;
    *(_DWORD *)(v2 + 620) += 4;
  }
  __x.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::delete_left;
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v2;
  v45 = vostok::ui::create_functor(&__x, (vostok::ui::ui_text_edit *)v2, key_back, &none_sh_state);
  v46 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v45;
  if ( v46 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v46,
      (unsigned __int8 **)(v2 + 616),
      (int)v46,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v46->_M_start = (unsigned int *)v45;
    *(_DWORD *)(v2 + 620) += 4;
  }
  __x.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::delete_right;
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v2;
  v47 = vostok::ui::create_functor(&__x, (vostok::ui::ui_text_edit *)v2, key_delete, &none_sh_state);
  v48 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v47;
  if ( v48 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v48,
      (unsigned __int8 **)(v2 + 616),
      (int)v48,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v48->_M_start = (unsigned int *)v47;
    *(_DWORD *)(v2 + 620) += 4;
  }
  __x.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::commit_text;
  __x.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v2;
  v49 = vostok::ui::create_functor(&__x, (vostok::ui::ui_text_edit *)v2, key_return, &any_sh_state);
  v50 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v49;
  if ( v50 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v50,
      (unsigned __int8 **)(v2 + 616),
      (int)v50,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v50->_M_start = (unsigned int *)v49;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v51 = *(vostok::input::world **)(*(_DWORD *)(v2 + 612) + 4);
  char_action = vostok::ui::create_char_action(
                  (vostok::ui::ui_text_edit *)v2,
                  key_0,
                  (vostok::input::enum_keyboard_action)48,
                  41,
                  0,
                  v51);
  v53 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = char_action;
  if ( v53 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v53,
      (unsigned __int8 **)(v2 + 616),
      (int)v53,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v53->_M_start = (unsigned int *)char_action;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v54 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_numpad0,
          (vostok::input::enum_keyboard_action)48,
          48,
          0,
          v51);
  v55 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v54;
  if ( v55 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v55,
      (unsigned __int8 **)(v2 + 616),
      (int)v55,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v55->_M_start = (unsigned int *)v54;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v56 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_1,
          (vostok::input::enum_keyboard_action)49,
          33,
          0,
          v51);
  v57 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v56;
  if ( v57 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v57,
      (unsigned __int8 **)(v2 + 616),
      (int)v57,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v57->_M_start = (unsigned int *)v56;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v58 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_numpad1,
          (vostok::input::enum_keyboard_action)49,
          49,
          0,
          v51);
  v59 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v58;
  if ( v59 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v59,
      (unsigned __int8 **)(v2 + 616),
      (int)v59,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v59->_M_start = (unsigned int *)v58;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v60 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_2,
          (vostok::input::enum_keyboard_action)50,
          64,
          0,
          v51);
  v61 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v60;
  if ( v61 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v61,
      (unsigned __int8 **)(v2 + 616),
      (int)v61,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v61->_M_start = (unsigned int *)v60;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v62 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_numpad2,
          (vostok::input::enum_keyboard_action)50,
          50,
          0,
          v51);
  v63 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v62;
  if ( v63 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v63,
      (unsigned __int8 **)(v2 + 616),
      (int)v63,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v63->_M_start = (unsigned int *)v62;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v64 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_3,
          (vostok::input::enum_keyboard_action)51,
          35,
          0,
          v51);
  v65 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v64;
  if ( v65 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v65,
      (unsigned __int8 **)(v2 + 616),
      (int)v65,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v65->_M_start = (unsigned int *)v64;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v66 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_numpad3,
          (vostok::input::enum_keyboard_action)51,
          51,
          0,
          v51);
  v67 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v66;
  if ( v67 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v67,
      (unsigned __int8 **)(v2 + 616),
      (int)v67,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v67->_M_start = (unsigned int *)v66;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v68 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_4,
          (vostok::input::enum_keyboard_action)52,
          36,
          0,
          v51);
  v69 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v68;
  if ( v69 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v69,
      (unsigned __int8 **)(v2 + 616),
      (int)v69,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v69->_M_start = (unsigned int *)v68;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v70 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_numpad4,
          (vostok::input::enum_keyboard_action)52,
          52,
          0,
          v51);
  v71 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v70;
  if ( v71 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v71,
      (unsigned __int8 **)(v2 + 616),
      (int)v71,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v71->_M_start = (unsigned int *)v70;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v72 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_5,
          (vostok::input::enum_keyboard_action)53,
          37,
          0,
          v51);
  v73 = *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 620);
  mode = v72;
  if ( v73 == *(stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > **)(v2 + 628) )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v73,
      (unsigned __int8 **)(v2 + 616),
      (int)v73,
      (const unsigned int *)&mode,
      v178,
      v179,
      v180);
  }
  else
  {
    v73->_M_start = (unsigned int *)v72;
    *(_DWORD *)(v2 + 620) += 4;
  }
  v74 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_numpad5,
          (vostok::input::enum_keyboard_action)53,
          53,
          0,
          v51);
  vostok::ui::ui_text_edit::add_action(v75, v74);
  v76 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_6,
          (vostok::input::enum_keyboard_action)54,
          94,
          0,
          v51);
  vostok::ui::ui_text_edit::add_action(v77, v76);
  v78 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_numpad6,
          (vostok::input::enum_keyboard_action)54,
          54,
          0,
          v51);
  vostok::ui::ui_text_edit::add_action(v79, v78);
  v80 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_7,
          (vostok::input::enum_keyboard_action)55,
          38,
          0,
          v51);
  vostok::ui::ui_text_edit::add_action(v81, v80);
  v82 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_numpad7,
          (vostok::input::enum_keyboard_action)55,
          55,
          0,
          v51);
  vostok::ui::ui_text_edit::add_action(v83, v82);
  v84 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_8,
          (vostok::input::enum_keyboard_action)56,
          42,
          0,
          v51);
  vostok::ui::ui_text_edit::add_action(v85, v84);
  v86 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_numpad8,
          (vostok::input::enum_keyboard_action)56,
          56,
          0,
          v51);
  vostok::ui::ui_text_edit::add_action(v87, v86);
  v88 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_9,
          (vostok::input::enum_keyboard_action)57,
          40,
          0,
          v51);
  vostok::ui::ui_text_edit::add_action(v89, v88);
  v90 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_numpad9,
          (vostok::input::enum_keyboard_action)57,
          57,
          0,
          v51);
  vostok::ui::ui_text_edit::add_action(v91, v90);
  v92 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_a,
          (vostok::input::enum_keyboard_action)97,
          65,
          1,
          v51);
  vostok::ui::ui_text_edit::add_action(v93, v92);
  v94 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_b,
          (vostok::input::enum_keyboard_action)98,
          66,
          1,
          v51);
  vostok::ui::ui_text_edit::add_action(v95, v94);
  v96 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_c,
          (vostok::input::enum_keyboard_action)99,
          67,
          1,
          v51);
  vostok::ui::ui_text_edit::add_action(v97, v96);
  v98 = vostok::ui::create_char_action(
          (vostok::ui::ui_text_edit *)v2,
          key_d,
          (vostok::input::enum_keyboard_action)100,
          68,
          1,
          v51);
  vostok::ui::ui_text_edit::add_action(v99, v98);
  v100 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_e,
           (vostok::input::enum_keyboard_action)101,
           69,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v101, v100);
  v102 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_f,
           (vostok::input::enum_keyboard_action)102,
           70,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v103, v102);
  v104 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_g,
           (vostok::input::enum_keyboard_action)103,
           71,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v105, v104);
  v106 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_h,
           (vostok::input::enum_keyboard_action)104,
           72,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v107, v106);
  v108 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_i,
           (vostok::input::enum_keyboard_action)105,
           73,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v109, v108);
  v110 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_j,
           (vostok::input::enum_keyboard_action)106,
           74,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v111, v110);
  v112 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_k,
           (vostok::input::enum_keyboard_action)107,
           75,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v113, v112);
  v114 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_l,
           (vostok::input::enum_keyboard_action)108,
           76,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v115, v114);
  v116 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_m,
           (vostok::input::enum_keyboard_action)109,
           77,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v117, v116);
  v118 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_n,
           (vostok::input::enum_keyboard_action)110,
           78,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v119, v118);
  v120 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_o,
           (vostok::input::enum_keyboard_action)111,
           79,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v121, v120);
  v122 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_p,
           (vostok::input::enum_keyboard_action)112,
           80,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v123, v122);
  v124 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_q,
           (vostok::input::enum_keyboard_action)113,
           81,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v125, v124);
  v126 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_r,
           (vostok::input::enum_keyboard_action)114,
           82,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v127, v126);
  v128 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_s,
           (vostok::input::enum_keyboard_action)115,
           83,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v129, v128);
  v130 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_t,
           (vostok::input::enum_keyboard_action)116,
           84,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v131, v130);
  v132 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_u,
           (vostok::input::enum_keyboard_action)117,
           85,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v133, v132);
  v134 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_v,
           (vostok::input::enum_keyboard_action)118,
           86,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v135, v134);
  v136 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_w,
           (vostok::input::enum_keyboard_action)119,
           87,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v137, v136);
  v138 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_x,
           (vostok::input::enum_keyboard_action)120,
           88,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v139, v138);
  v140 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_y,
           (vostok::input::enum_keyboard_action)121,
           89,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v141, v140);
  v142 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_z,
           (vostok::input::enum_keyboard_action)122,
           90,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v143, v142);
  v144 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_subtract,
           (vostok::input::enum_keyboard_action)45,
           45,
           0,
           v51);
  vostok::ui::ui_text_edit::add_action(v145, v144);
  v146 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_add,
           (vostok::input::enum_keyboard_action)43,
           43,
           0,
           v51);
  vostok::ui::ui_text_edit::add_action(v147, v146);
  v148 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_decimal,
           (vostok::input::enum_keyboard_action)46,
           46,
           0,
           v51);
  vostok::ui::ui_text_edit::add_action(v149, v148);
  v150 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_minus,
           (vostok::input::enum_keyboard_action)45,
           95,
           0,
           v51);
  vostok::ui::ui_text_edit::add_action(v151, v150);
  v152 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_space,
           (vostok::input::enum_keyboard_action)32,
           32,
           0,
           v51);
  vostok::ui::ui_text_edit::add_action(v153, v152);
  v154 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_grave,
           (vostok::input::enum_keyboard_action)96,
           126,
           0,
           v51);
  vostok::ui::ui_text_edit::add_action(v155, v154);
  v156 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_backslash,
           (vostok::input::enum_keyboard_action)92,
           124,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v157, v156);
  v158 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_lbracket,
           (vostok::input::enum_keyboard_action)91,
           123,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v159, v158);
  v160 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_rbracket,
           (vostok::input::enum_keyboard_action)93,
           125,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v161, v160);
  v162 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_apostrophe,
           (vostok::input::enum_keyboard_action)39,
           34,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v163, v162);
  v164 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_comma,
           (vostok::input::enum_keyboard_action)44,
           60,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v165, v164);
  v166 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_period,
           (vostok::input::enum_keyboard_action)46,
           62,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v167, v166);
  v168 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_equals,
           (vostok::input::enum_keyboard_action)61,
           43,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v169, v168);
  v170 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_semicolon,
           (vostok::input::enum_keyboard_action)59,
           58,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v171, v170);
  v172 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_slash,
           (vostok::input::enum_keyboard_action)47,
           63,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v173, v172);
  v174 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_multiply,
           (vostok::input::enum_keyboard_action)42,
           42,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v175, v174);
  v176 = vostok::ui::create_char_action(
           (vostok::ui::ui_text_edit *)v2,
           key_divide,
           (vostok::input::enum_keyboard_action)47,
           47,
           1,
           v51);
  vostok::ui::ui_text_edit::add_action(v177, v176);
}
