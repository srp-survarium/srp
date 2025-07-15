void __userpurge vostok::ui::ui_text_edit::init_internals(
        vostok::ui::ui_text_edit *this@<ecx>,
        vostok::ui::ui_text_edit *a2@<eax>,
        vostok::ui::enum_text_edit_mode mode)
{
  vostok::ui::base_edit_action *shift_action; // eax
  vostok::ui::ui_text_edit *M_start; // ecx
  vostok::ui::base_edit_action *v6; // eax
  vostok::ui::ui_text_edit *v7; // ecx
  vostok::ui::base_edit_action *v8; // eax
  vostok::ui::ui_text_edit *v9; // ecx
  vostok::ui::base_edit_action *v10; // eax
  vostok::ui::ui_text_edit *v11; // ecx
  vostok::ui::base_edit_action *v12; // eax
  vostok::ui::ui_text_edit *v13; // ecx
  vostok::ui::base_edit_action *v14; // eax
  vostok::ui::ui_text_edit *v15; // ecx
  vostok::ui::ui_text_edit *v16; // ecx
  vostok::ui::ui_text_edit *v17; // ecx
  vostok::ui::ui_text_edit *v18; // ecx
  vostok::ui::ui_text_edit *v19; // ecx
  vostok::ui::ui_text_edit *v20; // ecx
  vostok::ui::ui_text_edit *v21; // ecx
  vostok::ui::ui_text_edit *v22; // ecx
  vostok::ui::ui_text_edit *v23; // ecx
  vostok::ui::ui_text_edit *v24; // ecx
  vostok::ui::ui_text_edit *v25; // ecx
  vostok::ui::ui_text_edit *v26; // ecx
  vostok::ui::ui_text_edit *v27; // ecx
  vostok::ui::ui_text_edit *v28; // ecx
  vostok::ui::ui_text_edit *v29; // ecx
  vostok::ui::ui_text_edit *v30; // ecx
  vostok::ui::ui_text_edit *v31; // ecx
  vostok::ui::ui_text_edit *v32; // ecx
  vostok::input::world *m_input_world; // esi
  vostok::ui::ui_text_edit *v34; // ecx
  vostok::ui::ui_text_edit *v35; // ecx
  vostok::ui::ui_text_edit *v36; // ecx
  vostok::ui::ui_text_edit *v37; // ecx
  vostok::ui::ui_text_edit *v38; // ecx
  vostok::ui::ui_text_edit *v39; // ecx
  vostok::ui::ui_text_edit *v40; // ecx
  vostok::ui::ui_text_edit *v41; // ecx
  vostok::ui::ui_text_edit *v42; // ecx
  vostok::ui::ui_text_edit *v43; // ecx
  vostok::ui::ui_text_edit *v44; // ecx
  vostok::ui::ui_text_edit *v45; // ecx
  vostok::ui::ui_text_edit *v46; // ecx
  vostok::ui::ui_text_edit *v47; // ecx
  vostok::ui::ui_text_edit *v48; // ecx
  vostok::ui::ui_text_edit *v49; // ecx
  vostok::ui::ui_text_edit *v50; // ecx
  vostok::ui::ui_text_edit *v51; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v52; // [esp-4h] [ebp-24h]
  vostok::ui::ui_text_edit *v53; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v54; // [esp-4h] [ebp-24h]
  vostok::ui::ui_text_edit *v55; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v56; // [esp-4h] [ebp-24h]
  vostok::ui::ui_text_edit *v57; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v58; // [esp-4h] [ebp-24h]
  vostok::ui::ui_text_edit *v59; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v60; // [esp-4h] [ebp-24h]
  vostok::ui::ui_text_edit *v61; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v62; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v63; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v64; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v65; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v66; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v67; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v68; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v69; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v70; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v71; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v72; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v73; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v74; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v75; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v76; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v77; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v78; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v79; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v80; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v81; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v82; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v83; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v84; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v85; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v86; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v87; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v88; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v89; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v90; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v91; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v92; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v93; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v94; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v95; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v96; // [esp-4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v97; // [esp-4h] [ebp-24h]
  fastdelegate::FastDelegate0<void> v98; // [esp+10h] [ebp-10h] BYREF
  vostok::ui::shift_state::data_storage v99; // [esp+1Bh] [ebp-5h] BYREF
  vostok::ui::shift_state::data_storage v100; // [esp+1Ch] [ebp-4h] BYREF
  vostok::ui::shift_state::data_storage v101; // [esp+1Dh] [ebp-3h] BYREF
  vostok::ui::shift_state::data_storage v102; // [esp+1Eh] [ebp-2h] BYREF
  vostok::ui::shift_state::data_storage v103; // [esp+1Fh] [ebp-1h] BYREF

  v102.dummy = -86;
  v101.dummy = 0;
  v103.dummy = 1;
  v100.dummy = 16;
  v99.dummy = 17;
  shift_action = vostok::ui::create_shift_action(a2, key_lshift, 0);
  M_start = (vostok::ui::ui_text_edit *)v52._M_start;
  v52._M_start = (void **)&shift_action->__vftable;
  vostok::ui::ui_text_edit::add_action(M_start, (int)a2, v52);
  v6 = vostok::ui::create_shift_action(a2, key_rshift, 0);
  v7 = v53;
  v54._M_start = (void **)&v6->__vftable;
  vostok::ui::ui_text_edit::add_action(v7, (int)a2, v54);
  v8 = vostok::ui::create_shift_action(a2, key_lcontrol, (vostok::ui::base_edit_action_vtbl *)1);
  v9 = v55;
  v56._M_start = (void **)&v8->__vftable;
  vostok::ui::ui_text_edit::add_action(v9, (int)a2, v56);
  v10 = vostok::ui::create_shift_action(a2, key_rcontrol, (vostok::ui::base_edit_action_vtbl *)1);
  v11 = v57;
  v58._M_start = (void **)&v10->__vftable;
  vostok::ui::ui_text_edit::add_action(v11, (int)a2, v58);
  v12 = vostok::ui::create_shift_action(a2, key_lmenu, (vostok::ui::base_edit_action_vtbl *)2);
  v13 = v59;
  v60._M_start = (void **)&v12->__vftable;
  vostok::ui::ui_text_edit::add_action(v13, (int)a2, v60);
  v14 = vostok::ui::create_shift_action(a2, key_rmenu, (vostok::ui::base_edit_action_vtbl *)2);
  v15 = v61;
  v62._M_start = (void **)&v14->__vftable;
  vostok::ui::ui_text_edit::add_action(v15, (int)a2, v62);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::move_cursor_left;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v63._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_left, &v102);
  vostok::ui::ui_text_edit::add_action(v16, (int)a2, v63);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::move_cursor_right;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v64._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_right, &v102);
  vostok::ui::ui_text_edit::add_action(v17, (int)a2, v64);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::move_cursor_begin;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v65._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_home, &v102);
  vostok::ui::ui_text_edit::add_action(v18, (int)a2, v65);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::move_cursor_end;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v66._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_end, &v102);
  vostok::ui::ui_text_edit::add_action(v19, (int)a2, v66);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::select_all;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v67._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_a, &v103);
  vostok::ui::ui_text_edit::add_action(v20, (int)a2, v67);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::copy_to_clipboard;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v68._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_c, &v103);
  vostok::ui::ui_text_edit::add_action(v21, (int)a2, v68);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::copy_to_clipboard;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v69._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_insert, &v103);
  vostok::ui::ui_text_edit::add_action(v22, (int)a2, v69);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::switch_insert_mode;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v70._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_insert, &v101);
  vostok::ui::ui_text_edit::add_action(v23, (int)a2, v70);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::undo;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v71._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_z, &v103);
  vostok::ui::ui_text_edit::add_action(v24, (int)a2, v71);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::redo;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v72._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_z, &v99);
  vostok::ui::ui_text_edit::add_action(v25, (int)a2, v72);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::cut_to_clipboard;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v73._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_x, &v103);
  vostok::ui::ui_text_edit::add_action(v26, (int)a2, v73);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::cut_to_clipboard;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v74._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_delete, &v100);
  vostok::ui::ui_text_edit::add_action(v27, (int)a2, v74);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::paste_from_clipboard;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v75._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_v, &v103);
  vostok::ui::ui_text_edit::add_action(v28, (int)a2, v75);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::paste_from_clipboard;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v76._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_insert, &v100);
  vostok::ui::ui_text_edit::add_action(v29, (int)a2, v76);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::delete_left;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v77._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_back, &v101);
  vostok::ui::ui_text_edit::add_action(v30, (int)a2, v77);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::delete_right;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v78._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_delete, &v101);
  vostok::ui::ui_text_edit::add_action(v31, (int)a2, v78);
  v98.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::ui::ui_text_edit::commit_text;
  v98.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)a2;
  v79._M_start = (void **)vostok::ui::create_functor(a2, &v98, key_return, &v102);
  vostok::ui::ui_text_edit::add_action(v32, (int)a2, v79);
  m_input_world = a2->m_ui_world->m_input_world;
  v80._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_0,
                            (vostok::input::enum_keyboard_action)48,
                            41,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v34, (int)a2, v80);
  v81._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_numpad0,
                            (vostok::input::enum_keyboard_action)48,
                            48,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v35, (int)a2, v81);
  v82._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_1,
                            (vostok::input::enum_keyboard_action)49,
                            33,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v36, (int)a2, v82);
  v83._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_numpad1,
                            (vostok::input::enum_keyboard_action)49,
                            49,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v37, (int)a2, v83);
  v84._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_2,
                            (vostok::input::enum_keyboard_action)50,
                            64,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v38, (int)a2, v84);
  v85._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_numpad2,
                            (vostok::input::enum_keyboard_action)50,
                            50,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v39, (int)a2, v85);
  v86._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_3,
                            (vostok::input::enum_keyboard_action)51,
                            35,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v40, (int)a2, v86);
  v87._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_numpad3,
                            (vostok::input::enum_keyboard_action)51,
                            51,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v41, (int)a2, v87);
  v88._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_4,
                            (vostok::input::enum_keyboard_action)52,
                            36,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v42, (int)a2, v88);
  v89._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_numpad4,
                            (vostok::input::enum_keyboard_action)52,
                            52,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v43, (int)a2, v89);
  v90._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_5,
                            (vostok::input::enum_keyboard_action)53,
                            37,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v44, (int)a2, v90);
  v91._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_numpad5,
                            (vostok::input::enum_keyboard_action)53,
                            53,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v45, (int)a2, v91);
  v92._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_6,
                            (vostok::input::enum_keyboard_action)54,
                            94,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v46, (int)a2, v92);
  v93._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_numpad6,
                            (vostok::input::enum_keyboard_action)54,
                            54,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v47, (int)a2, v93);
  v94._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_7,
                            (vostok::input::enum_keyboard_action)55,
                            38,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v48, (int)a2, v94);
  v95._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_numpad7,
                            (vostok::input::enum_keyboard_action)55,
                            55,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v49, (int)a2, v95);
  v96._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_8,
                            (vostok::input::enum_keyboard_action)56,
                            42,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v50, (int)a2, v96);
  v97._M_start = (void **)vostok::ui::create_char_action(
                            a2,
                            key_numpad8,
                            (vostok::input::enum_keyboard_action)56,
                            56,
                            0,
                            (vostok::ui::base_edit_action_vtbl *)m_input_world);
  vostok::ui::ui_text_edit::add_action(v51, (int)a2, v97);
  JUMPOUT(0x200036);
}
