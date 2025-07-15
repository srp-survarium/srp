void __thiscall survarium::lobby_menu::fill_items_dictionary(survarium::lobby_menu *this, unsigned int a2)
{
  int v3; // eax
  Scaleform::GFx::Movie *v4; // ecx
  survarium::dictionary_item **v5; // eax
  vostok::configs::binary_config_value *item_id; // ecx
  vostok::configs::binary_config_value *m_root; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // ecx
  bool has_passed_filters; // al
  vostok::configs::binary_config_value *v10; // eax
  vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value *v12; // eax
  char **v13; // eax
  vostok::configs::binary_config_value *v14; // eax
  vostok::configs::binary_config_value *v15; // eax
  char **v16; // eax
  survarium::flash_movie *v17; // ecx
  survarium::flash_value *v18; // ecx
  survarium::flash_value *v19; // ecx
  survarium::flash_value *v20; // ecx
  survarium::flash_value *v21; // ecx
  survarium::flash_value *v22; // ecx
  survarium::flash_value *v23; // ecx
  survarium::flash_value *v24; // ecx
  survarium::flash_value *v25; // ecx
  survarium::flash_value *v26; // ecx
  survarium::flash_value *v27; // ecx
  vostok::configs::binary_config_value *v28; // eax
  unsigned int *v29; // eax
  survarium::flash_value *v30; // ecx
  survarium::flash_value *v31; // ecx
  vostok::configs::binary_config_value *v32; // eax
  const vostok::configs::binary_config_value *v33; // eax
  float v34; // xmm0_4
  vostok::configs::binary_config_value *v35; // eax
  unsigned int *v36; // eax
  survarium::flash_value *v37; // ecx
  survarium::flash_value *v38; // ecx
  survarium::flash_value *v39; // ecx
  const vostok::configs::binary_config_value *v40; // eax
  vostok::configs::binary_config_value *v41; // ecx
  survarium::flash_value *v42; // ecx
  vostok::configs::binary_config_value *v43; // eax
  unsigned __int8 v44; // al
  survarium::flash_value *v45; // ecx
  vostok::configs::binary_config_value *v46; // eax
  const vostok::configs::binary_config_value *v47; // eax
  float v48; // xmm0_4
  survarium::flash_value *v49; // ecx
  survarium::flash_value *v50; // ecx
  survarium::flash_value *v51; // ecx
  vostok::configs::binary_config_value *v52; // eax
  vostok::configs::binary_config_value *v53; // eax
  const vostok::configs::binary_config_value *v54; // eax
  survarium::flash_movie *v55; // ecx
  int v56; // eax
  char **v57; // eax
  vostok::configs::binary_config_value *v58; // ecx
  vostok::configs::binary_config_value *v59; // ecx
  survarium::flash_value *v60; // ecx
  survarium::flash_value *v61; // ecx
  survarium::flash_value *v62; // ecx
  survarium::flash_value *v63; // ecx
  survarium::flash_value *v64; // ecx
  survarium::flash_value *v65; // ecx
  vostok::configs::binary_config_value *v66; // ecx
  char **v67; // eax
  survarium::flash_value *v68; // ecx
  int v69; // eax
  survarium::flash_movie *v70; // ecx
  int v71; // eax
  survarium::text_translator *v72; // ecx
  survarium::flash_value *v73; // ecx
  survarium::flash_value *v74; // ecx
  survarium::flash_value *v75; // ecx
  survarium::flash_value *v76; // ecx
  float v77[68]; // [esp-10Ch] [ebp-9B4h] BYREF
  survarium::text_translator v78[128]; // [esp+14h] [ebp-894h] BYREF
  survarium::text_translator v79[128]; // [esp+214h] [ebp-694h] BYREF
  survarium::text_translator v80[128]; // [esp+414h] [ebp-494h] BYREF
  survarium::dictionary_item v81; // [esp+614h] [ebp-294h] BYREF
  Scaleform::GFx::Value v82; // [esp+794h] [ebp-114h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+7ACh] [ebp-FCh] BYREF
  survarium::flash_value v84; // [esp+7C4h] [ebp-E4h] BYREF
  Scaleform::GFx::Value pargs; // [esp+7DCh] [ebp-CCh] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v86; // [esp+7F4h] [ebp-B4h] BYREF
  vostok::configs::binary_config_value *v87; // [esp+818h] [ebp-90h]
  survarium::flash_value v88; // [esp+81Ch] [ebp-8Ch] BYREF
  Scaleform::GFx::Value v89; // [esp+834h] [ebp-74h] BYREF
  Scaleform::GFx::Value v90; // [esp+84Ch] [ebp-5Ch] BYREF
  bool v91[4]; // [esp+864h] [ebp-44h]
  bool v92[4]; // [esp+868h] [ebp-40h]
  unsigned int v93; // [esp+86Ch] [ebp-3Ch]
  int i; // [esp+870h] [ebp-38h]
  unsigned int v95; // [esp+874h] [ebp-34h]
  char *pointer; // [esp+878h] [ebp-30h]
  survarium::flash_value v97; // [esp+87Ch] [ebp-2Ch] BYREF
  int value; // [esp+894h] [ebp-14h]
  float v99; // [esp+898h] [ebp-10h]
  int v100; // [esp+89Ch] [ebp-Ch]
  vostok::configs::binary_config_value *v101; // [esp+8A0h] [ebp-8h]
  vostok::configs::binary_config_value *v102; // [esp+8B0h] [ebp+8h]
  unsigned int j; // [esp+8B0h] [ebp+8h]
  unsigned __int8 item_category; // [esp+8B3h] [ebp+Bh]

  LODWORD(v77[67]) = &pvalue;
  v3 = *(_DWORD *)(a2 + 1600);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  v4 = *(Scaleform::GFx::Movie **)(*(_DWORD *)(v3 + 264) + 4);
  v100 = 0;
  Scaleform::GFx::Movie::CreateArray(v4, &pvalue);
  v95 = 0;
  *(_DWORD *)v97.body = 0;
  *(_DWORD *)&v97.body[4] = 0;
  v93 = 0;
  for ( i = 0; ; i += 380 )
  {
    v5 = (survarium::dictionary_item **)(*(_DWORD *)(a2 + 160) + 13908);
    if ( v93 >= LODWORD((*v5)->modifiers[0]) )
      break;
    survarium::dictionary_item::dictionary_item(*v5, &v81, i + *(_DWORD *)&(*v5)->item_category);
    item_id = (vostok::configs::binary_config_value *)v81.item_id;
    m_root = v81.item_cfg.m_object->m_root;
    value = v81.item_id;
    item_category = v81.item_category;
    LOBYTE(item_id) = v81.is_stack;
    v101 = m_root;
    v91[0] = v81.is_stack;
    if ( vostok::configs::binary_config_value::value_exists(item_id, (int)m_root, (unsigned int)"ui_desc") )
    {
      v10 = vostok::configs::binary_config_value::operator[](v101, "ui_desc");
      pointer = (char *)vostok::configs::binary_config_value::operator[](v10, "icon")->data.pointer;
      v11 = vostok::configs::binary_config_value::operator[](v101, "ui_desc");
      v12 = vostok::configs::binary_config_value::operator[](v11, "text_descriptions");
      v13 = (char **)vostok::configs::binary_config_value::operator[](v12, "name");
      survarium::text_translator::translate_text(v78, *(_DWORD *)(a2 + 160) + 13944, *v13, (char *)v78);
      v14 = vostok::configs::binary_config_value::operator[](v101, "ui_desc");
      v15 = vostok::configs::binary_config_value::operator[](v14, "text_descriptions");
      v16 = (char **)vostok::configs::binary_config_value::operator[](v15, "description");
      survarium::text_translator::translate_text(v79, *(_DWORD *)(a2 + 160) + 13944, *v16, (char *)v79);
      v90.pObjectInterface = 0;
      v90.Type = VT_Undefined;
      survarium::flash_movie::CreateObject(v17, *(survarium::flash_value **)(*(_DWORD *)(a2 + 1600) + 264), &v90);
      survarium::flash_value::SetInt(v18, (int)&v97, value);
      survarium::flash_value::SetMember(v19, &v90, "dictId", &v97);
      survarium::flash_value::SetString(&v97, (const char *)v78);
      survarium::flash_value::SetMember(v20, &v90, "name", &v97);
      survarium::flash_value::SetString(&v97, (const char *)v79);
      survarium::flash_value::SetMember(v21, &v90, "descr", &v97);
      survarium::flash_value::SetUInt(v22, (int)&v97, item_category);
      survarium::flash_value::SetMember(v23, &v90, "category", &v97);
      survarium::flash_value::SetInt(v24, (int)&v97, (int)pointer);
      survarium::flash_value::SetMember(v25, &v90, "icon", &v97);
      survarium::flash_value::SetUInt(v26, (int)&v97, v81.item_level);
      survarium::flash_value::SetMember(v27, &v90, "level", &v97);
      if ( v81.item_category == 9
        || v81.item_category == 18
        || v81.item_category == 19
        || v81.item_category == 20
        || v81.item_category == 21 )
      {
        v28 = vostok::configs::binary_config_value::operator[](v101, "parameters");
        v29 = (unsigned int *)vostok::configs::binary_config_value::operator[](v28, "clip_size");
        survarium::flash_value::SetUInt(v30, (int)&v97, *v29);
        survarium::flash_value::SetMember(v31, &v90, "clip_size", &v97);
        v32 = vostok::configs::binary_config_value::operator[](v101, "parameters");
        v33 = vostok::configs::binary_config_value::operator[](v32, "clip_weight");
        if ( v33->type == 2 )
          v34 = *(float *)&v33->data.pointer;
        else
          v34 = (float)(int)v33->data.pointer;
        v99 = v34;
        v35 = vostok::configs::binary_config_value::operator[](v101, "parameters");
        v36 = (unsigned int *)vostok::configs::binary_config_value::operator[](v35, "clips_in_bag");
        survarium::flash_value::SetUInt(v37, (int)&v97, *v36);
        survarium::flash_value::SetMember(v38, &v90, "clips_in_bag", &v97);
      }
      else
      {
        if ( v91[0] )
        {
          LODWORD(v77[67]) = "quick_slot_item_size";
          v40 = vostok::configs::binary_config_value::operator[](v101, "parameters");
          if ( vostok::configs::binary_config_value::value_exists(v41, (int)v40, LODWORD(v77[67])) )
          {
            v43 = vostok::configs::binary_config_value::operator[](v101, "parameters");
            v44 = (unsigned __int8)vostok::configs::binary_config_value::operator[](v43, "quick_slot_item_size")->data.pointer;
          }
          else
          {
            v44 = 1;
          }
          survarium::flash_value::SetUInt(v42, (int)&v97, v44);
          survarium::flash_value::SetMember(v45, &v90, "quick_slot_item_size", &v97);
        }
        v46 = vostok::configs::binary_config_value::operator[](v101, "parameters");
        v47 = vostok::configs::binary_config_value::operator[](v46, "weight");
        if ( v47->type == 2 )
          v48 = *(float *)&v47->data.pointer;
        else
          v48 = (float)(int)v47->data.pointer;
        v99 = v48;
      }
      survarium::flash_value::SetNumber(v39, (int)&v97, v99);
      survarium::flash_value::SetMember(v49, &v90, "weight", &v97);
      survarium::flash_value::SetBoolean(v50, (int)&v97, v91[0]);
      survarium::flash_value::SetMember(v51, &v90, "is_stack", &v97);
      v89.pObjectInterface = 0;
      v89.Type = VT_Undefined;
      Scaleform::GFx::Movie::CreateArray(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
        &v89);
      v52 = vostok::configs::binary_config_value::operator[](v101, "ui_desc");
      v102 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v52, "props_list")->data.pointer;
      v53 = vostok::configs::binary_config_value::operator[](v101, "ui_desc");
      v54 = vostok::configs::binary_config_value::operator[](v53, "props_list");
      v55 = (survarium::flash_movie *)((char *)v54->data.pointer + 24 * v54->count);
      v87 = (vostok::configs::binary_config_value *)v55;
      *(_DWORD *)v88.body = 0;
      *(_DWORD *)&v88.body[4] = 0;
      v101 = 0;
      if ( v102 != (vostok::configs::binary_config_value *)v55 )
      {
        do
        {
          LODWORD(v77[67]) = &v86.functor;
          v56 = *(_DWORD *)(a2 + 1600);
          *(_QWORD *)&v86.functor.obj_ptr = 0;
          survarium::flash_movie::CreateObject(
            v55,
            *(survarium::flash_value **)(v56 + 264),
            (Scaleform::GFx::Value *)&v86.functor);
          v57 = (char **)vostok::configs::binary_config_value::operator[](v102, "prop_name");
          survarium::text_translator::translate_text(v80, *(_DWORD *)(a2 + 160) + 13944, *v57, (char *)v80);
          pointer = (char *)vostok::configs::binary_config_value::operator[](v102, "prop_value")->data.pointer;
          if ( vostok::configs::binary_config_value::value_exists(v58, (int)v102, (unsigned int)"prop_icon") )
            value = (int)vostok::configs::binary_config_value::operator[](v102, "prop_icon")->data.pointer;
          else
            value = 0;
          v92[0] = vostok::configs::binary_config_value::value_exists(v59, (int)v102, (unsigned int)"comparable")
                && vostok::configs::binary_config_value::operator[](v102, "comparable")->data.pointer != 0;
          survarium::flash_value::SetString(&v88, pointer);
          survarium::flash_value::SetMember(v60, &v86.functor.obj_ptr, "prop_value", &v88);
          survarium::flash_value::SetBoolean(v61, (int)&v88, v92[0]);
          survarium::flash_value::SetMember(v62, &v86.functor.obj_ptr, "comparable", &v88);
          survarium::flash_value::SetString(&v88, (const char *)v80);
          survarium::flash_value::SetMember(v63, &v86.functor.obj_ptr, "prop_name", &v88);
          survarium::flash_value::SetUInt(v64, (int)&v88, value);
          survarium::flash_value::SetMember(v65, &v86.functor.obj_ptr, "prop_icon", &v88);
          if ( vostok::configs::binary_config_value::value_exists(v66, (int)v102, (unsigned int)"prop_postfix") )
          {
            v67 = (char **)vostok::configs::binary_config_value::operator[](v102, "prop_postfix");
            survarium::text_translator::translate_text(v80, *(_DWORD *)(a2 + 160) + 13944, *v67, (char *)v80);
            survarium::flash_value::SetString(&v88, (const char *)v80);
            survarium::flash_value::SetMember(v68, &v86.functor.obj_ptr, "postfix", &v88);
          }
          v89.pObjectInterface->SetElement(
            v89.pObjectInterface,
            (void *)v89.mValue.IValue,
            (unsigned int)v101,
            (const Scaleform::GFx::Value *)&v86.functor);
          Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v86.functor);
          ++v102;
          v101 = (vostok::configs::binary_config_value *)((char *)v101 + 1);
        }
        while ( v102 != v87 );
      }
      survarium::flash_value::SetMember(
        (survarium::flash_value *)v55,
        &v90,
        "item_properties",
        (survarium::flash_value *)&v89);
      pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v95++, &v90);
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v88);
      Scaleform::GFx::Value::~Value(&v89);
      Scaleform::GFx::Value::~Value(&v90);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v81.item_cfg);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"game",
                                   (const char *)3),
            v8 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)LODWORD(v77[67]),
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v8,
          &v86);
        v100 |= 1u;
        qmemcpy(v77, &v81.item_cfg_name, sizeof(v77));
        vostok::logging::append(
          &v86,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\lobby_menu_ui.cpp",
          0x475u,
          "void __thiscall survarium::lobby_menu::fill_items_dictionary(void)",
          "game",
          warning,
          "There is no ui_desc info for [%s]");
      }
      if ( (v100 & 1) != 0 )
      {
        v100 &= ~1u;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v8,
          (int *)&v86);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v81.item_cfg);
    }
    ++v93;
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root._itemDescriptor.setItemsDictionary",
    0,
    &pvalue,
    1u);
  LODWORD(v77[67]) = &pargs;
  v69 = *(_DWORD *)(a2 + 1600);
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v69 + 264) + 4), &pargs);
  *(_DWORD *)v84.body = 0;
  *(_DWORD *)&v84.body[4] = 0;
  for ( j = 1; j <= 6; ++j )
  {
    LODWORD(v77[67]) = &v89;
    v71 = *(_DWORD *)(a2 + 1600);
    v89.pObjectInterface = 0;
    v89.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v70, *(survarium::flash_value **)(v71 + 264), &v89);
    survarium::text_translator::translate_text(
      v72,
      *(_DWORD *)(a2 + 160) + 13944,
      (char *)survarium::sellers_names[j],
      (char *)v79);
    survarium::flash_value::SetString(&v84, (const char *)v79);
    survarium::flash_value::SetMember(v73, &v89, "name", &v84);
    survarium::flash_value::SetUInt(v74, (int)&v84, j);
    survarium::flash_value::SetMember(v75, &v89, "faction_id", &v84);
    pargs.pObjectInterface->PushBack(pargs.pObjectInterface, (void *)pargs.mValue.IValue, &v89);
    Scaleform::GFx::Value::~Value(&v89);
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.shop_list.fillSellers",
    0,
    &pargs,
    1u);
  v82.pObjectInterface = 0;
  v82.Type = VT_Undefined;
  survarium::flash_value::SetBoolean(v76, (int)&v82, 1);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.set_squad_commander_mode",
    0,
    &v82,
    1u);
  Scaleform::GFx::Value::~Value(&v82);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v84);
  Scaleform::GFx::Value::~Value(&pargs);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v97);
  Scaleform::GFx::Value::~Value(&pvalue);
}
