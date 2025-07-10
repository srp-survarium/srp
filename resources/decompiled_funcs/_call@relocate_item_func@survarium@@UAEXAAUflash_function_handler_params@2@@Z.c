void __thiscall survarium::relocate_item_func::call(
        survarium::relocate_item_func *this,
        survarium::flash_function_handler_params *params)
{
  void (__cdecl *v3)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v4)(unsigned int *, unsigned int *, int); // eax
  survarium::base_network_client *m_network_client; // ecx
  survarium::lobby_client *(__thiscall *lobby_client)(survarium::base_network_client *); // eax
  survarium::relocate_item_descr *M_start; // edi
  unsigned __int8 v8; // al
  survarium::flash_value *pArgs; // eax
  int v10; // ebx
  void (__thiscall *v11)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool); // eax
  unsigned int v12; // edi
  void (__thiscall *v13)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool); // edx
  void (__thiscall *v14)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool); // edx
  void (__thiscall *v15)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool); // edx
  survarium::game *m_game; // edx
  survarium::items_dictionary *m_object; // eax
  stlp_std::priv::_Rb_tree_node_base *M_parent; // ecx
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *p_m_items_dict; // eax
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *v20; // edx
  void (__cdecl *v21)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  unsigned int target_slot_id; // edi
  void (__cdecl *v23)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  survarium::game *v24; // ecx
  int m_selected_profile; // edx
  int v26; // ebx
  unsigned __int16 dict_id; // ax
  survarium::relocate_item_descr *M_finish; // edi
  unsigned int *p_item_dict_id; // eax
  survarium::items_dictionary *v30; // ecx
  stlp_std::priv::_Rb_tree_node_base *v31; // eax
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *v32; // ecx
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *v33; // esi
  unsigned int item_dict_id; // edx
  char v35; // bl
  unsigned int m_profile_slot_restrictions_count; // edi
  unsigned int v37; // ecx
  survarium::profile_slot_restriction *m_profile_slot_restrictions; // eax
  bool v39; // al
  void *v40; // esi
  const stlp_std::__true_type *v41; // [esp+70h] [ebp-1C0h]
  unsigned int v42; // [esp+74h] [ebp-1BCh]
  bool v43; // [esp+78h] [ebp-1B8h]
  int v44; // [esp+7Ch] [ebp-1B4h]
  survarium::lobby_client *lobby; // [esp+80h] [ebp-1B0h]
  survarium::vector<survarium::relocate_item_descr> descriptions; // [esp+84h] [ebp-1ACh] BYREF
  survarium::flash_value descr_value; // [esp+90h] [ebp-1A0h] BYREF
  int v48; // [esp+A8h] [ebp-188h]
  unsigned int second_item_id; // [esp+ACh] [ebp-184h]
  survarium::relocate_item_descr current; // [esp+B0h] [ebp-180h] BYREF
  survarium::flash_value descr_member_value; // [esp+D0h] [ebp-160h] BYREF
  int v52; // [esp+E8h] [ebp-148h]
  survarium::relocate_item_func *v53; // [esp+ECh] [ebp-144h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+F0h] [ebp-140h] BYREF
  survarium::dictionary_item current_item; // [esp+110h] [ebp-120h] BYREF

  v53 = this;
  v44 = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
  {
    v3 = vostok::core::g_log_callback;
    current.profile_id = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        (const boost::detail::function::function_buffer *)&current.item_dict_id,
        (boost::detail::function::function_buffer *)&current.item_dict_id,
        destroy_functor_tag);
    if ( v3 )
    {
      current.item_dict_id = (unsigned int)v3;
      current.profile_id = (unsigned int)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                         + 1;
    }
    else
    {
      current.profile_id = 0;
    }
    v44 = 1;
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&current,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\lobby_menu_ui.cpp",
      0x23u,
      "void __thiscall survarium::relocate_item_func::call(struct survarium::flash_function_handler_params &)",
      "game:",
      info,
      "TRY RELOCATE(FLASH)!!!");
  }
  if ( (v44 & 1) != 0 )
  {
    v44 &= ~1u;
    if ( current.profile_id )
    {
      if ( (current.profile_id & 1) == 0 )
      {
        v4 = *(void (__cdecl **)(unsigned int *, unsigned int *, int))(current.profile_id & 0xFFFFFFFE);
        if ( v4 )
          v4(&current.item_dict_id, &current.item_dict_id, 2);
      }
    }
  }
  m_network_client = this->m_game->m_network_client;
  lobby_client = m_network_client->lobby_client;
  M_start = 0;
  memset(&descriptions, 0, sizeof(descriptions));
  lobby = lobby_client(m_network_client);
  v8 = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)params->pArgs + 40))(*(_DWORD *)&params->pArgs->body[8]);
  if ( v8 )
  {
    v48 = 0;
    v52 = v8;
    while ( 1 )
    {
      pArgs = params->pArgs;
      *(_DWORD *)descr_value.body = 0;
      *(_DWORD *)&descr_value.body[4] = 0;
      *(_DWORD *)descr_member_value.body = 0;
      *(_DWORD *)&descr_member_value.body[4] = 0;
      (*(void (__stdcall **)(_DWORD, int, survarium::flash_value *))(**(_DWORD **)pArgs->body + 48))(
        *(_DWORD *)&pArgs->body[8],
        v48,
        &descr_value);
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)descr_value.body
                                                                                           + 16))(
        *(_DWORD *)descr_value.body,
        *(_DWORD *)&descr_value.body[8],
        "profile",
        &descr_member_value,
        (descr_value.body[4] & 0x8F) == 10);
      current.profile_id = *(_DWORD *)&descr_member_value.body[8];
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)descr_value.body
                                                                                           + 16))(
        *(_DWORD *)descr_value.body,
        *(_DWORD *)&descr_value.body[8],
        "id",
        &descr_member_value,
        (descr_value.body[4] & 0x8F) == 10);
      v10 = *(_DWORD *)&descr_member_value.body[8];
      v11 = *(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)descr_value.body
                                                                                                + 16);
      current.item_id = *(_DWORD *)&descr_member_value.body[8];
      v11(
        *(_DWORD *)descr_value.body,
        *(_DWORD *)&descr_value.body[8],
        "dict_id",
        &descr_member_value,
        (descr_value.body[4] & 0x8F) == 10);
      v12 = *(_DWORD *)&descr_member_value.body[8];
      v13 = *(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)descr_value.body
                                                                                                + 16);
      current.item_dict_id = *(_DWORD *)&descr_member_value.body[8];
      v13(
        *(_DWORD *)descr_value.body,
        *(_DWORD *)&descr_value.body[8],
        "sourceSlot",
        &descr_member_value,
        (descr_value.body[4] & 0x8F) == 10);
      v14 = *(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)descr_value.body
                                                                                                + 16);
      current.source_slot_id = *(_DWORD *)&descr_member_value.body[8];
      v14(
        *(_DWORD *)descr_value.body,
        *(_DWORD *)&descr_value.body[8],
        "targetSlot",
        &descr_member_value,
        (descr_value.body[4] & 0x8F) == 10);
      v15 = *(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)descr_value.body
                                                                                                + 16);
      current.target_slot_id = *(_DWORD *)&descr_member_value.body[8];
      v15(
        *(_DWORD *)descr_value.body,
        *(_DWORD *)&descr_value.body[8],
        "count",
        &descr_member_value,
        (descr_value.body[4] & 0x8F) == 10);
      m_game = v53->m_game;
      current.amount = *(_WORD *)&descr_member_value.body[8];
      m_object = m_game->m_items_dictionary.m_object;
      M_parent = m_object->m_items_dict._M_t._M_header._M_data._M_parent;
      p_m_items_dict = &m_object->m_items_dict;
      v20 = p_m_items_dict;
      if ( M_parent )
      {
        do
        {
          if ( *(_DWORD *)&M_parent[1]._M_color < v12 )
          {
            M_parent = M_parent->_M_right;
          }
          else
          {
            v20 = (survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *)M_parent;
            M_parent = M_parent->_M_left;
          }
        }
        while ( M_parent );
        if ( v20 != p_m_items_dict && v12 < v20->_M_t._M_node_count )
          v20 = p_m_items_dict;
      }
      survarium::dictionary_item::dictionary_item(
        &current_item,
        (const survarium::dictionary_item *)&v20->_M_t._M_key_compare);
      if ( vostok::core::g_log_filter_tree
        && !vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        target_slot_id = current.target_slot_id;
      }
      else
      {
        v21 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v21 )
        {
          log_callback.functor.obj_ptr = v21;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        target_slot_id = current.target_slot_id;
        v44 |= 2u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu_ui.cpp",
          0x4Au,
          "void __thiscall survarium::relocate_item_func::call(struct survarium::flash_function_handler_params &)",
          "game:",
          info,
          "try move item %d from %d to %d. amount=%d",
          v10,
          current.source_slot_id,
          current.target_slot_id,
          current.amount);
      }
      if ( (v44 & 2) != 0 )
      {
        v44 &= ~2u;
        if ( log_callback.vtable )
        {
          if ( ((int)log_callback.vtable & 1) == 0 )
          {
            v23 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
            if ( v23 )
              v23(&log_callback.functor, &log_callback.functor, 2);
          }
        }
      }
      v24 = v53->m_game;
      m_selected_profile = v24->m_lobby_menu->m_selected_profile;
      second_item_id = 0;
      if ( target_slot_id == 8 || target_slot_id == 9 )
      {
        v26 = 7;
      }
      else
      {
        if ( target_slot_id != 11 && target_slot_id != 12 )
          goto LABEL_51;
        v26 = 10;
      }
      dict_id = lobby->m_profiles[m_selected_profile].slots[v26].item.dict_id;
      if ( dict_id )
      {
        M_finish = descriptions._M_impl._M_finish;
        second_item_id = dict_id;
        if ( descriptions._M_impl._M_start != descriptions._M_impl._M_finish )
        {
          p_item_dict_id = &descriptions._M_impl._M_start->item_dict_id;
          do
          {
            if ( v26 == p_item_dict_id[2] )
              second_item_id = *p_item_dict_id;
            p_item_dict_id += 6;
          }
          while ( p_item_dict_id - 2 != (unsigned int *)descriptions._M_impl._M_finish );
        }
        goto LABEL_52;
      }
LABEL_51:
      M_finish = descriptions._M_impl._M_finish;
LABEL_52:
      v30 = v24->m_items_dictionary.m_object;
      v31 = v30->m_items_dict._M_t._M_header._M_data._M_parent;
      v32 = &v30->m_items_dict;
      v33 = v32;
      if ( v31 )
      {
        do
        {
          item_dict_id = current.item_dict_id;
          if ( *(_DWORD *)&v31[1]._M_color < current.item_dict_id )
          {
            v31 = v31->_M_right;
          }
          else
          {
            v33 = (survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *)v31;
            v31 = v31->_M_left;
          }
        }
        while ( v31 );
        if ( v33 != v32 && current.item_dict_id < v33->_M_t._M_node_count )
          v33 = v32;
      }
      else
      {
        item_dict_id = current.item_dict_id;
      }
      if ( current.target_slot_id == 100 )
      {
        v35 = 1;
      }
      else
      {
        m_profile_slot_restrictions_count = lobby->m_profile_slot_restrictions_count;
        v37 = 0;
        if ( m_profile_slot_restrictions_count )
        {
          m_profile_slot_restrictions = lobby->m_profile_slot_restrictions;
          while ( m_profile_slot_restrictions->slot_dict_id != current.target_slot_id
               || m_profile_slot_restrictions->category_dict_id != LOBYTE(v33[12]._M_t._M_header._M_data._M_right) )
          {
            ++v37;
            ++m_profile_slot_restrictions;
            if ( v37 >= m_profile_slot_restrictions_count )
              goto LABEL_68;
          }
          v35 = 1;
        }
        else
        {
LABEL_68:
          v35 = 0;
        }
        M_finish = descriptions._M_impl._M_finish;
      }
      if ( second_item_id )
      {
        v39 = survarium::lobby_client::check_compatibility(lobby, second_item_id, item_dict_id);
        M_finish = descriptions._M_impl._M_finish;
      }
      else
      {
        v39 = 1;
      }
      if ( v35 && v39 )
      {
        if ( M_finish == descriptions._M_impl._M_end_of_storage._M_data )
        {
          stlp_std::priv::_Impl_vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::_M_insert_overflow(
            &descriptions._M_impl,
            M_finish,
            &current,
            v41,
            v42,
            v43);
        }
        else
        {
          *M_finish = current;
          descriptions._M_impl._M_finish = M_finish + 1;
        }
      }
      if ( current_item.item_cfg.m_object
        && !_InterlockedExchangeAdd(&current_item.item_cfg.m_object->m_reference_count, 0xFFFFFFFF) )
      {
        vostok::resources::unmanaged_intrusive_base::destroy(
          &current_item.item_cfg.m_object->vostok::resources::unmanaged_intrusive_base,
          current_item.item_cfg.m_object);
      }
      if ( (descr_member_value.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)descr_member_value.body + 8))(
          *(_DWORD *)descr_member_value.body,
          &descr_member_value,
          *(_DWORD *)&descr_member_value.body[8]);
        *(_DWORD *)descr_member_value.body = 0;
      }
      *(_DWORD *)&descr_member_value.body[4] = 0;
      if ( (descr_value.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)descr_value.body + 8))(
          *(_DWORD *)descr_value.body,
          &descr_value,
          *(_DWORD *)&descr_value.body[8]);
      ++v48;
      if ( !--v52 )
      {
        M_start = descriptions._M_impl._M_start;
        break;
      }
    }
  }
  survarium::lobby_client::move_item(lobby, (survarium::vector<survarium::relocate_item_descr> *)lobby);
  if ( M_start )
  {
    v40 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v40, M_start);
  }
}
