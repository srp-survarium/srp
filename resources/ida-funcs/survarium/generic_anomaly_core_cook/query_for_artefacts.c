void __userpurge survarium::generic_anomaly_core_cook::query_for_artefacts(
        survarium::generic_anomaly_core_cook *this@<ecx>,
        int a2@<ebp>,
        const char *a3@<edi>,
        const char *a4@<esi>,
        vostok::resources::query_result_for_cook *parent,
        const vostok::variant<32> **config,
        vostok::configs::binary_config_value *game_world,
        int a8)
{
  const vostok::configs::binary_config_value *v8; // edi
  int v9; // eax
  void *v10; // esp
  int v11; // esi
  vostok::buffer_vector<survarium::artefact> *v12; // ecx
  void *v13; // esp
  void *v14; // esp
  int v15; // esi
  void *v16; // esp
  _WORD *v17; // esi
  survarium::items_dictionary *v18; // eax
  survarium::dictionary_item *v19; // eax
  vostok::variant<32> *v20; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v21; // ecx
  vostok::variant<32> *v22; // ecx
  int v23; // eax
  const char **v24; // esi
  bool v25; // zf
  void *v26; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v27; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v28; // ecx
  survarium::items_dictionary_vtbl *m_storage; // [esp-E4h] [ebp-F0h]
  const char *v30[2]; // [esp-E0h] [ebp-ECh] BYREF
  _DWORD v31[10]; // [esp-D8h] [ebp-E4h] BYREF
  int v32; // [esp-B0h] [ebp-BCh]
  vostok::variant<32> v33; // [esp-A8h] [ebp-B4h] BYREF
  int v34[9]; // [esp-78h] [ebp-84h] BYREF
  vostok::resources::request v35; // [esp-54h] [ebp-60h] BYREF
  const char **v36; // [esp-4Ch] [ebp-58h] BYREF
  const char **v37; // [esp-48h] [ebp-54h]
  const char **v38; // [esp-44h] [ebp-50h]
  const vostok::variant<32> *const *v39; // [esp-40h] [ebp-4Ch]
  vostok::buffer_vector<vostok::resources::request> v40; // [esp-3Ch] [ebp-48h] BYREF
  int v41; // [esp-30h] [ebp-3Ch] BYREF
  const char **v42; // [esp-2Ch] [ebp-38h]
  const char **v43; // [esp-28h] [ebp-34h]
  survarium::artefact v44; // [esp-24h] [ebp-30h] BYREF
  const char **pointer; // [esp-18h] [ebp-24h]
  int v46; // [esp-14h] [ebp-20h]
  const vostok::configs::binary_config_value *v47; // [esp-10h] [ebp-1Ch]
  int v48; // [esp-Ch] [ebp-18h]
  int v49; // [esp-8h] [ebp-14h]
  bool v50; // [esp-1h] [ebp-Dh] BYREF
  int v51; // [esp+0h] [ebp-Ch]
  void *v52; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v51 = a2;
  v52 = retaddr;
  v30[1] = a4;
  v30[0] = a3;
  v8 = vostok::configs::binary_config_value::operator[](game_world, "artefacts");
  v9 = 24 * v8->count / 24;
  v47 = v8;
  v48 = v9;
  v10 = alloca(12 * v9);
  *(_DWORD *)&v44.dictionary_id = v30;
  v44.weight = (unsigned int)v30;
  v44.count = (unsigned int)&v30[3 * v9];
  v11 = 0;
  if ( v9 )
  {
    v49 = 0;
    v46 = v9;
    while ( 1 )
    {
      pointer = (const char **)vostok::configs::binary_config_value::operator[](
                                 (vostok::configs::binary_config_value *)((char *)v8->data.pointer + v49),
                                 "count")->data.pointer;
      LOWORD(v41) = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)((char *)v47->data.pointer + v49),
                      "dict_id")->data.pointer;
      v43 = pointer;
      vostok::buffer_vector<survarium::`anonymous namespace'::artefact>::push_back(v12, &v44, &v41);
      v11 += *(_DWORD *)(v44.weight - 4);
      v49 += 24;
      if ( !--v46 )
        break;
      v8 = v47;
    }
  }
  v13 = alloca(8 * v11);
  v40.m_max_end = (vostok::resources::request *)&v30[2 * v11];
  v40.m_begin = (vostok::resources::request *)v30;
  v40.m_end = (vostok::resources::request *)v30;
  v14 = alloca(48 * v48);
  v36 = v30;
  v37 = v30;
  v15 = v11;
  v38 = &v30[12 * v48];
  v16 = alloca(v15 * 4);
  v39 = (const vostok::variant<32> *const *)v30;
  v42 = v30;
  v43 = &v30[v15];
  if ( v48 )
  {
    v17 = *(_WORD **)&v44.dictionary_id;
    v49 = *(_DWORD *)&v44.dictionary_id;
    v47 = (const vostok::configs::binary_config_value *)v48;
    while ( 1 )
    {
      m_storage = (survarium::items_dictionary_vtbl *)(unsigned __int16)*v17;
      v18 = (survarium::items_dictionary *)((int (__thiscall *)(vostok::resources::query_result_for_cook *))parent->__vftable[1].decrease_quality)(parent);
      v19 = survarium::items_dictionary::item_by_id(v18, m_storage);
      v33.m_helper = 0;
      v33.m_type_id = 0;
      pointer = (const char **)&v19->item_cfg_name.m_begin;
      LOWORD(v32) = *v17;
      vostok::variant<32>::destroy_previous_variable_if_needed(v20, (int)&v33);
      v33.m_type_id = vostok::detail::type_to_int<survarium::artefact_cook_data>::get();
      *(_DWORD *)v33.m_storage = v32;
      *(_DWORD *)&v33.m_storage[4] = a8;
      *(_DWORD *)v33.m_helper_storage = &vostok::detail::concrete_type_helper<survarium::artefact_cook_data>::`vftable';
      v33.m_helper = (vostok::detail::abstract_type_helper *)&v33;
      vostok::buffer_vector<vostok::variant<32>>::push_back(v21, (int)&v36, &v33);
      v23 = *(_DWORD *)(v49 + 8);
      if ( v23 )
      {
        v44.count = 115;
        v48 = (int)(v37 - 12);
        v46 = v23;
        do
        {
          v35.path = *pointer;
          v35.id = v44.count;
          vostok::buffer_vector<vostok::resources::request>::push_back(&v40, &v35);
          v24 = v42;
          if ( v42 >= v43
            && !`vostok::buffer_vector<vostok::variant<32> *>::push_back'::`11'::debug_macro_helper_ignore_always )
          {
            v50 = 0;
            vostok::debug::on_error(
              &v50,
              process_error_true,
              0,
              "assertion_failed",
              "fatal error",
              "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
              "vostok::buffer_vector<class vostok::variant<32> *>::push_back",
              (const char *)0x12E,
              "buffer overflow",
              v30[0]);
            if ( vostok::debug::is_debugger_present() || v50 )
              __debugbreak();
          }
          if ( v24 )
            *v24 = (const char *)v48;
          v25 = v46-- == 1;
          v42 = v24 + 1;
        }
        while ( !v25 );
      }
      vostok::variant<32>::destroy_previous_variable_if_needed(v22, (int)&v33);
      v49 += 12;
      v47 = (const vostok::configs::binary_config_value *)((char *)v47 - 1);
      if ( !v47 )
        break;
      v17 = (_WORD *)v49;
    }
  }
  v34[0] = (int)parent;
  qmemcpy(&v34[2], game_world, 0x18u);
  v31[0] = survarium::generic_anomaly_core_cook::on_artefacts_loaded;
  v31[1] = 0;
  qmemcpy(&v31[2], v34, 0x20u);
  v34[0] = 0;
  m_storage = (survarium::items_dictionary_vtbl *)v33.m_storage;
  qmemcpy(v33.m_storage, v31, 0x28u);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v34[0] = 0;
  }
  else
  {
    qmemcpy(v31, v33.m_storage, sizeof(v31));
    v26 = operator new(0x28u);
    if ( v26 )
    {
      qmemcpy(v26, v31, 0x28u);
      v34[2] = (int)v26;
    }
    else
    {
      v34[2] = 0;
    }
    v34[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::generic_anomaly_core_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &>,boost::_bi::list3<boost::_bi::value<survarium::generic_anomaly_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value>>>>'::`2'::stored_vtable;
  }
  vostok::resources::query_resources(
    v40.m_begin,
    v40.m_end - v40.m_begin,
    survarium::g_allocator,
    v39,
    config,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v27, v34);
  vostok::buffer_vector<vostok::variant<32>>::~buffer_vector<vostok::variant<32>>(v28, (int *)&v36);
}
