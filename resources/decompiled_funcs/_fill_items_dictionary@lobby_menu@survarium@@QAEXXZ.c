void __thiscall survarium::lobby_menu::fill_items_dictionary(survarium::lobby_menu *this, survarium::lobby_menu *thisa)
{
  survarium::flash_movie_resource *m_object; // eax
  survarium::items_dictionary *v3; // esi
  stlp_std::priv::_Rb_tree_node_base *M_left; // ebx
  Scaleform::GFx::Movie *m_movie; // ecx
  vostok::configs::binary_config_value *m_root; // ebx
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v8)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v9; // eax
  bool v10; // zf
  vostok::configs::binary_config_value *v11; // eax
  const void *pointer; // edx
  vostok::configs::binary_config_value *v13; // eax
  vostok::configs::binary_config_value *v14; // eax
  const char **v15; // eax
  vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // eax
  const char **v18; // eax
  survarium::flash_movie_resource *v19; // ecx
  vostok::configs::binary_config_value *v20; // eax
  const void *v21; // esi
  vostok::configs::binary_config_value *v22; // eax
  const vostok::configs::binary_config_value *v23; // eax
  float v24; // xmm0_4
  survarium::flash_movie_resource *v25; // edx
  vostok::configs::binary_config_value *v26; // eax
  vostok::configs::binary_config_value *v27; // esi
  vostok::configs::binary_config_value *v28; // eax
  const vostok::configs::binary_config_value *v29; // eax
  survarium::flash_movie_resource *v30; // ecx
  const char **v31; // eax
  void *v32; // edi
  boost::detail::function::vtable_base *vtable; // ecx
  boost::detail::function::vtable_base *v34; // ecx
  unsigned int v35; // esi
  survarium::flash_movie_resource *v36; // ecx
  int v37; // ecx
  char *m_buffer; // eax
  char *m_end; // ecx
  const char *v40; // eax
  char *v41; // ecx
  const char *v42; // eax
  char *v43; // ecx
  const char *v44; // eax
  char *v45; // ecx
  const char *v46; // eax
  char *v47; // ecx
  const char *v48; // eax
  char *v49; // ecx
  const char *v50; // eax
  int v51; // ebx
  survarium::flash_movie_resource *v52; // edx
  boost::detail::function::vtable_base *v53; // ecx
  unsigned int v54; // esi
  char *v55[68]; // [esp+94h] [ebp-1050h] BYREF
  survarium::flash_value inventory_item_property; // [esp+1B4h] [ebp-F30h] BYREF
  unsigned int j; // [esp+1CCh] [ebp-F18h]
  bool current_item_is_stack; // [esp+1D2h] [ebp-F12h]
  unsigned __int8 current_item_category_id; // [esp+1D3h] [ebp-F11h]
  survarium::flash_value inventory_item_descr; // [esp+1D4h] [ebp-F10h] BYREF
  int v61; // [esp+1ECh] [ebp-EF8h]
  survarium::flash_value item_property_member; // [esp+1F0h] [ebp-EF4h] BYREF
  survarium::flash_value traders_array_item; // [esp+208h] [ebp-EDCh] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::dictionary_item>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,survarium::dictionary_item> > > itm_it; // [esp+220h] [ebp-EC4h]
  unsigned int prop_icon; // [esp+224h] [ebp-EC0h]
  float item_weight; // [esp+228h] [ebp-EBCh]
  survarium::flash_value traders_array_item_property; // [esp+22Ch] [ebp-EB8h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+244h] [ebp-EA0h] BYREF
  unsigned int in_array_index; // [esp+268h] [ebp-E7Ch]
  survarium::flash_value inventory_item_propertyies_array; // [esp+26Ch] [ebp-E78h] BYREF
  survarium::flash_value traders_array; // [esp+284h] [ebp-E60h] BYREF
  const survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *itm_dict; // [esp+29Ch] [ebp-E48h]
  const vostok::configs::binary_config_value *it_end; // [esp+2A0h] [ebp-E44h]
  survarium::flash_value items_descr_array; // [esp+2A4h] [ebp-E40h] BYREF
  vostok::fixed_string<32> sellers_names[6]; // [esp+2BCh] [ebp-E28h] BYREF
  survarium::dictionary_item current_item; // [esp+3C4h] [ebp-D20h] BYREF
  wchar_t faction_name[512]; // [esp+4E4h] [ebp-C00h] BYREF
  wchar_t item_name[512]; // [esp+8E4h] [ebp-800h] BYREF
  wchar_t item_desc[512]; // [esp+CE4h] [ebp-400h] BYREF

  m_object = thisa->m_lobby_menu_ui.m_object;
  v3 = thisa->m_game->m_items_dictionary.m_object;
  M_left = v3->m_items_dict._M_t._M_header._M_data._M_left;
  *(_DWORD *)items_descr_array.body = 0;
  *(_DWORD *)&items_descr_array.body[4] = 0;
  m_movie = m_object->movie->m_movie;
  v61 = 0;
  itm_dict = &v3->m_items_dict;
  itm_it._M_node = M_left;
  Scaleform::GFx::Movie::CreateArray(m_movie, (Scaleform::GFx::Value *)&items_descr_array);
  in_array_index = 0;
  *(_DWORD *)inventory_item_property.body = 0;
  *(_DWORD *)&inventory_item_property.body[4] = 0;
  if ( M_left != (stlp_std::priv::_Rb_tree_node_base *)&v3->m_items_dict )
  {
    do
    {
      survarium::dictionary_item::dictionary_item(
        &current_item,
        (const survarium::dictionary_item *)&itm_it._M_node[1]._M_parent);
      m_root = current_item.item_cfg.m_object->m_root;
      current_item_category_id = current_item.item_category;
      prop_icon = current_item.item_id;
      current_item_is_stack = current_item.is_stack;
      if ( vostok::configs::binary_config_value::value_exists(m_root, "ui_desc") )
      {
        v55[67] = "icon";
        v11 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        m_root,
                                                        "ui_desc");
        pointer = vostok::configs::binary_config_value::operator[](v11, v55[67])->data.pointer;
        v55[67] = "name";
        v55[66] = "text_descriptions";
        j = (unsigned int)pointer;
        v13 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        m_root,
                                                        "ui_desc");
        v14 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v13, v55[66]);
        v15 = (const char **)vostok::configs::binary_config_value::operator[](v14, v55[67]);
        survarium::text_translator::translate_text(&thisa->m_game->m_text_translator, *v15, item_name);
        v55[67] = "description";
        v55[66] = "text_descriptions";
        v16 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        m_root,
                                                        "ui_desc");
        v17 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v16, v55[66]);
        v18 = (const char **)vostok::configs::binary_config_value::operator[](v17, v55[67]);
        survarium::text_translator::translate_text(&thisa->m_game->m_text_translator, *v18, item_desc);
        v19 = thisa->m_lobby_menu_ui.m_object;
        *(_DWORD *)inventory_item_descr.body = 0;
        *(_DWORD *)&inventory_item_descr.body[4] = 0;
        Scaleform::GFx::Movie::CreateObject(
          v19->movie->m_movie,
          (Scaleform::GFx::Value *)&inventory_item_descr,
          0,
          0,
          0);
        if ( (inventory_item_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body
                                                                           + 8))(
            *(_DWORD *)inventory_item_property.body,
            &inventory_item_property,
            *(_DWORD *)&inventory_item_property.body[8]);
          *(_DWORD *)inventory_item_property.body = 0;
        }
        *(_DWORD *)&inventory_item_property.body[8] = prop_icon;
        *(_DWORD *)&inventory_item_property.body[4] = 3;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item_descr.body
                                                                                             + 20))(
          *(_DWORD *)inventory_item_descr.body,
          *(_DWORD *)&inventory_item_descr.body[8],
          "dictId",
          &inventory_item_property,
          (inventory_item_descr.body[4] & 0x8F) == 10);
        survarium::flash_value::SetStringW(&inventory_item_property, item_name);
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item_descr.body
                                                                                             + 20))(
          *(_DWORD *)inventory_item_descr.body,
          *(_DWORD *)&inventory_item_descr.body[8],
          "name",
          &inventory_item_property,
          (inventory_item_descr.body[4] & 0x8F) == 10);
        survarium::flash_value::SetStringW(&inventory_item_property, item_desc);
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item_descr.body
                                                                                             + 20))(
          *(_DWORD *)inventory_item_descr.body,
          *(_DWORD *)&inventory_item_descr.body[8],
          "descr",
          &inventory_item_property,
          (inventory_item_descr.body[4] & 0x8F) == 10);
        if ( (inventory_item_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body
                                                                           + 8))(
            *(_DWORD *)inventory_item_property.body,
            &inventory_item_property,
            *(_DWORD *)&inventory_item_property.body[8]);
          *(_DWORD *)inventory_item_property.body = 0;
        }
        *(_DWORD *)&inventory_item_property.body[8] = current_item_category_id;
        *(_DWORD *)&inventory_item_property.body[4] = 4;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item_descr.body
                                                                                             + 20))(
          *(_DWORD *)inventory_item_descr.body,
          *(_DWORD *)&inventory_item_descr.body[8],
          "category",
          &inventory_item_property,
          (inventory_item_descr.body[4] & 0x8F) == 10);
        if ( (inventory_item_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body
                                                                           + 8))(
            *(_DWORD *)inventory_item_property.body,
            &inventory_item_property,
            *(_DWORD *)&inventory_item_property.body[8]);
          *(_DWORD *)inventory_item_property.body = 0;
        }
        *(_DWORD *)&inventory_item_property.body[8] = j;
        *(_DWORD *)&inventory_item_property.body[4] = 3;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item_descr.body
                                                                                             + 20))(
          *(_DWORD *)inventory_item_descr.body,
          *(_DWORD *)&inventory_item_descr.body[8],
          "icon",
          &inventory_item_property,
          (inventory_item_descr.body[4] & 0x8F) == 10);
        if ( current_item.item_category == 9
          || current_item.item_category == 18
          || current_item.item_category == 19
          || current_item.item_category == 20
          || current_item.item_category == 21 )
        {
          v55[67] = "clip_size";
          v20 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                          m_root,
                                                          "parameters");
          v21 = vostok::configs::binary_config_value::operator[](v20, v55[67])->data.pointer;
          if ( (inventory_item_property.body[4] & 0x40) != 0 )
          {
            (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body
                                                                             + 8))(
              *(_DWORD *)inventory_item_property.body,
              &inventory_item_property,
              *(_DWORD *)&inventory_item_property.body[8]);
            *(_DWORD *)inventory_item_property.body = 0;
          }
          *(_DWORD *)&inventory_item_property.body[4] = 4;
          *(_DWORD *)&inventory_item_property.body[8] = v21;
          (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item_descr.body
                                                                                               + 20))(
            *(_DWORD *)inventory_item_descr.body,
            *(_DWORD *)&inventory_item_descr.body[8],
            "clip_size",
            &inventory_item_property,
            (inventory_item_descr.body[4] & 0x8F) == 10);
          v55[67] = "clip_weight";
        }
        else
        {
          v55[67] = "weight";
        }
        v22 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        m_root,
                                                        "parameters");
        v23 = vostok::configs::binary_config_value::operator[](v22, v55[67]);
        if ( v23->type == 2 )
          v24 = *(float *)&v23->data.pointer;
        else
          v24 = (float)(int)v23->data.pointer;
        item_weight = v24;
        if ( (inventory_item_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body
                                                                           + 8))(
            *(_DWORD *)inventory_item_property.body,
            &inventory_item_property,
            *(_DWORD *)&inventory_item_property.body[8]);
          *(_DWORD *)inventory_item_property.body = 0;
        }
        v55[67] = (char *)((inventory_item_descr.body[4] & 0x8F) == 10);
        v55[66] = (char *)&inventory_item_property;
        *(_DWORD *)&inventory_item_property.body[4] = 5;
        *(double *)&inventory_item_property.body[8] = item_weight;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, char *))(**(_DWORD **)inventory_item_descr.body
                                                                                               + 20))(
          *(_DWORD *)inventory_item_descr.body,
          *(_DWORD *)&inventory_item_descr.body[8],
          "weight",
          &inventory_item_property,
          v55[67]);
        if ( (inventory_item_property.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body
                                                                           + 8))(
            *(_DWORD *)inventory_item_property.body,
            &inventory_item_property,
            *(_DWORD *)&inventory_item_property.body[8]);
          *(_DWORD *)inventory_item_property.body = 0;
        }
        inventory_item_property.body[8] = current_item_is_stack;
        *(_DWORD *)&inventory_item_property.body[4] = 2;
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item_descr.body
                                                                                             + 20))(
          *(_DWORD *)inventory_item_descr.body,
          *(_DWORD *)&inventory_item_descr.body[8],
          "is_stack",
          &inventory_item_property,
          (inventory_item_descr.body[4] & 0x8F) == 10);
        v25 = thisa->m_lobby_menu_ui.m_object;
        *(_DWORD *)inventory_item_propertyies_array.body = 0;
        *(_DWORD *)&inventory_item_propertyies_array.body[4] = 0;
        Scaleform::GFx::Movie::CreateArray(
          v25->movie->m_movie,
          (Scaleform::GFx::Value *)&inventory_item_propertyies_array);
        v55[67] = "props_list";
        v26 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        m_root,
                                                        "ui_desc");
        v27 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v26, v55[67])->data.pointer;
        v55[67] = "props_list";
        v28 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        m_root,
                                                        "ui_desc");
        v29 = vostok::configs::binary_config_value::operator[](v28, v55[67]);
        it_end = (const vostok::configs::binary_config_value *)((char *)v29->data.pointer + 24 * v29->count);
        *(_DWORD *)item_property_member.body = 0;
        *(_DWORD *)&item_property_member.body[4] = 0;
        for ( j = 0; v27 != it_end; ++v27 )
        {
          v30 = thisa->m_lobby_menu_ui.m_object;
          *(_DWORD *)traders_array_item.body = 0;
          *(_DWORD *)&traders_array_item.body[4] = 0;
          Scaleform::GFx::Movie::CreateObject(
            v30->movie->m_movie,
            (Scaleform::GFx::Value *)&traders_array_item,
            0,
            0,
            0);
          v31 = (const char **)vostok::configs::binary_config_value::operator[](v27, "prop_name");
          survarium::text_translator::translate_text(&thisa->m_game->m_text_translator, *v31, faction_name);
          v32 = (void *)vostok::configs::binary_config_value::operator[](v27, "prop_value")->data.pointer;
          if ( vostok::configs::binary_config_value::value_exists(v27, "prop_icon") )
            prop_icon = (unsigned int)vostok::configs::binary_config_value::operator[](v27, "prop_icon")->data.pointer;
          else
            prop_icon = 0;
          vtable = 0;
          log_callback.vtable = 0;
          (&log_callback.vtable)[1] = (boost::detail::function::vtable_base *)6;
          log_callback.functor.obj_ptr = v32;
          if ( (item_property_member.body[4] & 0x40) != 0 )
          {
            (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)item_property_member.body + 8))(
              *(_DWORD *)item_property_member.body,
              &item_property_member,
              *(_DWORD *)&item_property_member.body[8]);
            vtable = log_callback.vtable;
            *(_DWORD *)item_property_member.body = 0;
          }
          *(_DWORD *)&item_property_member.body[4] = 6;
          *(_DWORD *)&item_property_member.body[8] = v32;
          if ( ((int)(&log_callback.vtable)[1] & 0x40) != 0 )
            (*((void (__thiscall **)(boost::detail::function::vtable_base *, boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *, void *))vtable->manager
             + 2))(
              vtable,
              &log_callback,
              log_callback.functor.obj_ptr);
          (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)traders_array_item.body
                                                                                               + 20))(
            *(_DWORD *)traders_array_item.body,
            *(_DWORD *)&traders_array_item.body[8],
            "prop_value",
            &item_property_member,
            (traders_array_item.body[4] & 0x8F) == 10);
          v34 = 0;
          log_callback.vtable = 0;
          (&log_callback.vtable)[1] = (boost::detail::function::vtable_base *)7;
          log_callback.functor.obj_ptr = faction_name;
          if ( (item_property_member.body[4] & 0x40) != 0 )
          {
            (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)item_property_member.body + 8))(
              *(_DWORD *)item_property_member.body,
              &item_property_member,
              *(_DWORD *)&item_property_member.body[8]);
            v34 = log_callback.vtable;
            *(_DWORD *)item_property_member.body = 0;
          }
          *(_DWORD *)&item_property_member.body[4] = 7;
          *(_DWORD *)&item_property_member.body[8] = faction_name;
          if ( ((int)(&log_callback.vtable)[1] & 0x40) != 0 )
            (*((void (__thiscall **)(boost::detail::function::vtable_base *, boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *, void *))v34->manager
             + 2))(
              v34,
              &log_callback,
              log_callback.functor.obj_ptr);
          (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)traders_array_item.body
                                                                                               + 20))(
            *(_DWORD *)traders_array_item.body,
            *(_DWORD *)&traders_array_item.body[8],
            "prop_name",
            &item_property_member,
            (traders_array_item.body[4] & 0x8F) == 10);
          if ( (item_property_member.body[4] & 0x40) != 0 )
          {
            (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)item_property_member.body + 8))(
              *(_DWORD *)item_property_member.body,
              &item_property_member,
              *(_DWORD *)&item_property_member.body[8]);
            *(_DWORD *)item_property_member.body = 0;
          }
          *(_DWORD *)&item_property_member.body[8] = prop_icon;
          *(_DWORD *)&item_property_member.body[4] = 4;
          (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)traders_array_item.body
                                                                                               + 20))(
            *(_DWORD *)traders_array_item.body,
            *(_DWORD *)&traders_array_item.body[8],
            "prop_icon",
            &item_property_member,
            (traders_array_item.body[4] & 0x8F) == 10);
          (*(void (__thiscall **)(_DWORD, _DWORD, unsigned int, survarium::flash_value *))(**(_DWORD **)inventory_item_propertyies_array.body
                                                                                         + 52))(
            *(_DWORD *)inventory_item_propertyies_array.body,
            *(_DWORD *)&inventory_item_propertyies_array.body[8],
            j,
            &traders_array_item);
          if ( (traders_array_item.body[4] & 0x40) != 0 )
            (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)traders_array_item.body + 8))(
              *(_DWORD *)traders_array_item.body,
              &traders_array_item,
              *(_DWORD *)&traders_array_item.body[8]);
          ++j;
        }
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)inventory_item_descr.body
                                                                                             + 20))(
          *(_DWORD *)inventory_item_descr.body,
          *(_DWORD *)&inventory_item_descr.body[8],
          "item_properties",
          &inventory_item_propertyies_array,
          (inventory_item_descr.body[4] & 0x8F) == 10);
        v35 = in_array_index;
        (*(void (__thiscall **)(_DWORD, _DWORD, unsigned int, survarium::flash_value *))(**(_DWORD **)items_descr_array.body
                                                                                       + 52))(
          *(_DWORD *)items_descr_array.body,
          *(_DWORD *)&items_descr_array.body[8],
          in_array_index,
          &inventory_item_descr);
        in_array_index = v35 + 1;
        if ( (item_property_member.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)item_property_member.body + 8))(
            *(_DWORD *)item_property_member.body,
            &item_property_member,
            *(_DWORD *)&item_property_member.body[8]);
          *(_DWORD *)item_property_member.body = 0;
        }
        *(_DWORD *)&item_property_member.body[4] = 0;
        if ( (inventory_item_propertyies_array.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_propertyies_array.body
                                                                           + 8))(
            *(_DWORD *)inventory_item_propertyies_array.body,
            &inventory_item_propertyies_array,
            *(_DWORD *)&inventory_item_propertyies_array.body[8]);
          *(_DWORD *)inventory_item_propertyies_array.body = 0;
        }
        *(_DWORD *)&inventory_item_propertyies_array.body[4] = 0;
        if ( (inventory_item_descr.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_descr.body + 8))(
            *(_DWORD *)inventory_item_descr.body,
            &inventory_item_descr,
            *(_DWORD *)&inventory_item_descr.body[8]);
          *(_DWORD *)inventory_item_descr.body = 0;
        }
        v9 = current_item.item_cfg.m_object;
        *(_DWORD *)&inventory_item_descr.body[4] = 0;
        v10 = current_item.item_cfg.m_object == 0;
      }
      else
      {
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", warning) )
        {
          v7 = vostok::core::g_log_callback;
          log_callback.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &log_callback.functor,
              &log_callback.functor,
              destroy_functor_tag);
          if ( v7 )
          {
            log_callback.functor.obj_ptr = v7;
            log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                         + 1);
          }
          else
          {
            log_callback.vtable = 0;
          }
          v61 |= 1u;
          qmemcpy(v55, &itm_it._M_node[1]._M_right, sizeof(v55));
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\lobby_menu_ui.cpp",
            0x2CEu,
            "void __thiscall survarium::lobby_menu::fill_items_dictionary(void)",
            "game:",
            warning,
            "There is no ui_desc info for [%s]");
        }
        if ( (v61 & 1) != 0 )
        {
          v61 &= ~1u;
          if ( log_callback.vtable )
          {
            if ( ((int)log_callback.vtable & 1) == 0 )
            {
              v8 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
              if ( v8 )
                v8(&log_callback.functor, &log_callback.functor, 2);
            }
          }
        }
        v9 = current_item.item_cfg.m_object;
        v10 = current_item.item_cfg.m_object == 0;
      }
      if ( !v10 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &current_item.item_cfg.m_object->vostok::resources::unmanaged_intrusive_base,
          current_item.item_cfg.m_object);
      itm_it._M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(itm_it._M_node);
    }
    while ( (const survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *)itm_it._M_node != itm_dict );
  }
  Scaleform::GFx::Movie::Invoke(
    thisa->m_lobby_menu_ui.m_object->movie->m_movie,
    "root._itemDescriptor.setItemsDictionary",
    0,
    (const Scaleform::GFx::Value *)&items_descr_array,
    1u);
  v36 = thisa->m_lobby_menu_ui.m_object;
  *(_DWORD *)traders_array.body = 0;
  *(_DWORD *)&traders_array.body[4] = 0;
  Scaleform::GFx::Movie::CreateArray(v36->movie->m_movie, (Scaleform::GFx::Value *)&traders_array);
  v37 = 5;
  m_buffer = sellers_names[0].m_buffer;
  do
  {
    *((_DWORD *)m_buffer - 3) = m_buffer;
    *((_DWORD *)m_buffer - 2) = m_buffer;
    *((_DWORD *)m_buffer - 1) = m_buffer + 32;
    *m_buffer = 0;
    *m_buffer = 0;
    m_buffer += 44;
    --v37;
  }
  while ( v37 >= 0 );
  if ( sellers_names[0].m_begin != "st_scavengers_faction" )
  {
    sellers_names[0].m_end = sellers_names[0].m_begin;
    *sellers_names[0].m_begin = 0;
    m_end = sellers_names[0].m_end;
    v40 = "st_scavengers_faction";
    do
    {
      if ( m_end >= sellers_names[0].m_max_end )
        break;
      *m_end = *v40;
      m_end = sellers_names[0].m_end + 1;
      v10 = *++v40 == 0;
      ++sellers_names[0].m_end;
    }
    while ( !v10 );
    *m_end = 0;
  }
  if ( sellers_names[1].m_begin != "st_black_market_faction" )
  {
    sellers_names[1].m_end = sellers_names[1].m_begin;
    *sellers_names[1].m_begin = 0;
    v41 = sellers_names[1].m_end;
    v42 = "st_black_market_faction";
    do
    {
      if ( v41 >= sellers_names[1].m_max_end )
        break;
      *v41 = *v42;
      v41 = sellers_names[1].m_end + 1;
      v10 = *++v42 == 0;
      ++sellers_names[1].m_end;
    }
    while ( !v10 );
    *v41 = 0;
  }
  if ( sellers_names[2].m_begin != "st_renaissance_faction" )
  {
    sellers_names[2].m_end = sellers_names[2].m_begin;
    *sellers_names[2].m_begin = 0;
    v43 = sellers_names[2].m_end;
    v44 = "st_renaissance_faction";
    do
    {
      if ( v43 >= sellers_names[2].m_max_end )
        break;
      *v43 = *v44;
      v43 = sellers_names[2].m_end + 1;
      v10 = *++v44 == 0;
      ++sellers_names[2].m_end;
    }
    while ( !v10 );
    *v43 = 0;
  }
  if ( sellers_names[3].m_begin != "st_border_faction" )
  {
    sellers_names[3].m_end = sellers_names[3].m_begin;
    *sellers_names[3].m_begin = 0;
    v45 = sellers_names[3].m_end;
    v46 = "st_border_faction";
    do
    {
      if ( v45 >= sellers_names[3].m_max_end )
        break;
      *v45 = *v46;
      v45 = sellers_names[3].m_end + 1;
      v10 = *++v46 == 0;
      ++sellers_names[3].m_end;
    }
    while ( !v10 );
    *v45 = 0;
  }
  if ( sellers_names[4].m_begin != "st_scientists_faction" )
  {
    sellers_names[4].m_end = sellers_names[4].m_begin;
    *sellers_names[4].m_begin = 0;
    v47 = sellers_names[4].m_end;
    v48 = "st_scientists_faction";
    do
    {
      if ( v47 >= sellers_names[4].m_max_end )
        break;
      *v47 = *v48;
      v47 = sellers_names[4].m_end + 1;
      v10 = *++v48 == 0;
      ++sellers_names[4].m_end;
    }
    while ( !v10 );
    *v47 = 0;
  }
  if ( sellers_names[5].m_begin != "st_mercenaries_faction" )
  {
    sellers_names[5].m_end = sellers_names[5].m_begin;
    *sellers_names[5].m_begin = 0;
    v49 = sellers_names[5].m_end;
    v50 = "st_mercenaries_faction";
    do
    {
      if ( v49 >= sellers_names[5].m_max_end )
        break;
      *v49 = *v50;
      v49 = sellers_names[5].m_end + 1;
      v10 = *++v50 == 0;
      ++sellers_names[5].m_end;
    }
    while ( !v10 );
    *v49 = 0;
  }
  *(_DWORD *)traders_array_item_property.body = 0;
  *(_DWORD *)&traders_array_item_property.body[4] = 0;
  v51 = 0;
  j = (unsigned int)sellers_names;
  do
  {
    v52 = thisa->m_lobby_menu_ui.m_object;
    *(_DWORD *)traders_array_item.body = 0;
    *(_DWORD *)&traders_array_item.body[4] = 0;
    Scaleform::GFx::Movie::CreateObject(v52->movie->m_movie, (Scaleform::GFx::Value *)&traders_array_item, 0, 0, 0);
    survarium::text_translator::translate_text(&thisa->m_game->m_text_translator, *(const char **)j, faction_name);
    v53 = 0;
    log_callback.vtable = 0;
    (&log_callback.vtable)[1] = (boost::detail::function::vtable_base *)7;
    log_callback.functor.obj_ptr = faction_name;
    if ( (traders_array_item_property.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)traders_array_item_property.body
                                                                       + 8))(
        *(_DWORD *)traders_array_item_property.body,
        &traders_array_item_property,
        *(_DWORD *)&traders_array_item_property.body[8]);
      v53 = log_callback.vtable;
      *(_DWORD *)traders_array_item_property.body = 0;
    }
    *(_DWORD *)&traders_array_item_property.body[4] = 7;
    *(_DWORD *)&traders_array_item_property.body[8] = faction_name;
    if ( ((int)(&log_callback.vtable)[1] & 0x40) != 0 )
      (*((void (__thiscall **)(boost::detail::function::vtable_base *, boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *, void *))v53->manager
       + 2))(
        v53,
        &log_callback,
        log_callback.functor.obj_ptr);
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)traders_array_item.body
                                                                                         + 20))(
      *(_DWORD *)traders_array_item.body,
      *(_DWORD *)&traders_array_item.body[8],
      "name",
      &traders_array_item_property,
      (traders_array_item.body[4] & 0x8F) == 10);
    if ( (traders_array_item_property.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)traders_array_item_property.body
                                                                       + 8))(
        *(_DWORD *)traders_array_item_property.body,
        &traders_array_item_property,
        *(_DWORD *)&traders_array_item_property.body[8]);
      *(_DWORD *)traders_array_item_property.body = 0;
    }
    v54 = v51 + 1;
    *(_DWORD *)&traders_array_item_property.body[4] = 4;
    *(_DWORD *)&traders_array_item_property.body[8] = v51 + 1;
    (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)traders_array_item.body
                                                                                         + 20))(
      *(_DWORD *)traders_array_item.body,
      *(_DWORD *)&traders_array_item.body[8],
      "faction_id",
      &traders_array_item_property,
      (traders_array_item.body[4] & 0x8F) == 10);
    (*(void (__thiscall **)(_DWORD, _DWORD, int, survarium::flash_value *))(**(_DWORD **)traders_array.body + 52))(
      *(_DWORD *)traders_array.body,
      *(_DWORD *)&traders_array.body[8],
      v51,
      &traders_array_item);
    if ( (traders_array_item.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)traders_array_item.body + 8))(
        *(_DWORD *)traders_array_item.body,
        &traders_array_item,
        *(_DWORD *)&traders_array_item.body[8]);
    j += 44;
    ++v51;
  }
  while ( v54 < 6 );
  Scaleform::GFx::Movie::Invoke(
    thisa->m_lobby_menu_ui.m_object->movie->m_movie,
    "root.shop_list.fillSellers",
    0,
    (const Scaleform::GFx::Value *)&traders_array,
    1u);
  if ( (traders_array_item_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)traders_array_item_property.body + 8))(
      *(_DWORD *)traders_array_item_property.body,
      &traders_array_item_property,
      *(_DWORD *)&traders_array_item_property.body[8]);
    *(_DWORD *)traders_array_item_property.body = 0;
  }
  *(_DWORD *)&traders_array_item_property.body[4] = 0;
  if ( (traders_array.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)traders_array.body + 8))(
      *(_DWORD *)traders_array.body,
      &traders_array,
      *(_DWORD *)&traders_array.body[8]);
    *(_DWORD *)traders_array.body = 0;
  }
  *(_DWORD *)&traders_array.body[4] = 0;
  if ( (inventory_item_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)inventory_item_property.body + 8))(
      *(_DWORD *)inventory_item_property.body,
      &inventory_item_property,
      *(_DWORD *)&inventory_item_property.body[8]);
    *(_DWORD *)inventory_item_property.body = 0;
  }
  *(_DWORD *)&inventory_item_property.body[4] = 0;
  if ( (items_descr_array.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)items_descr_array.body + 8))(
      *(_DWORD *)items_descr_array.body,
      &items_descr_array,
      *(_DWORD *)&items_descr_array.body[8]);
}
