void __userpurge survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter>::translate_query(
        survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter> *this@<ecx>,
        const vostok::variant<32> *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const vostok::variant<32> **parent)
{
  const vostok::variant<32> *v5; // esi
  vostok::resources::query_result_for_cook *v6; // ecx
  const vostok::configs::binary_config_value *v7; // eax
  int v8; // esi
  void *v9; // esp
  void *v10; // esp
  void *v11; // esp
  vostok::variant<32> *pointer; // eax
  vostok::variant<32> *v13; // esi
  const void *v14; // eax
  vostok::buffer_vector<vostok::variant<32> > *v15; // ecx
  vostok::variant<32> *v16; // ecx
  const vostok::variant<32> *v17; // edi
  const vostok::variant<32> *v18; // esi
  vostok::variant<32> *v19; // ecx
  vostok::buffer_vector<vostok::variant<32> const *> *v20; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v21; // ecx
  vostok::buffer_vector<vostok::variant<32> > *v22; // ecx
  void (__thiscall **v23)(survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter> *, vostok::resources::queries_result *, vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *); // [esp-A4h] [ebp-B0h]
  _DWORD v24[2]; // [esp-A0h] [ebp-ACh] BYREF
  vostok::variant<32> v25; // [esp-98h] [ebp-A4h] BYREF
  int v26[4]; // [esp-68h] [ebp-74h] BYREF
  vostok::resources::request v27; // [esp-58h] [ebp-64h]
  const char *v28; // [esp-50h] [ebp-5Ch]
  int v29; // [esp-4Ch] [ebp-58h]
  void (__thiscall *v30)(survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter> *, vostok::resources::queries_result *, vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *); // [esp-44h] [ebp-50h] BYREF
  int v31; // [esp-40h] [ebp-4Ch]
  vostok::resources::request v32; // [esp-3Ch] [ebp-48h] BYREF
  const vostok::variant<32> *const *v33[3]; // [esp-34h] [ebp-40h] BYREF
  const vostok::variant<32> *v34; // [esp-28h] [ebp-34h]
  _DWORD *v35; // [esp-24h] [ebp-30h] BYREF
  _DWORD *v36; // [esp-20h] [ebp-2Ch]
  _DWORD *v37; // [esp-1Ch] [ebp-28h]
  survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter> *v38; // [esp-18h] [ebp-24h]
  vostok::buffer_vector<vostok::resources::request> v39; // [esp-14h] [ebp-20h] BYREF
  int v40; // [esp-8h] [ebp-14h] BYREF
  const vostok::variant<32> *v41[4]; // [esp-4h] [ebp-10h] BYREF
  const vostok::variant<32> *retaddr; // [esp+Ch] [ebp+0h]

  v41[1] = a2;
  v41[2] = retaddr;
  v24[1] = a4;
  v24[0] = a3;
  v5 = parent[66];
  v38 = this;
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value const *>(
         (vostok::variant<32> *)this,
         (int)v5,
         (const vostok::configs::binary_config_value **)&v40) )
  {
    v7 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v40, "effects");
    v8 = 24 * v7->count;
    v41[0] = (const vostok::variant<32> *)v7;
    v40 = v8 / 24;
    v9 = alloca(8 * (v8 / 24));
    v39.m_max_end = (vostok::resources::request *)&v24[2 * (v8 / 24)];
    v39.m_begin = (vostok::resources::request *)v24;
    v39.m_end = (vostok::resources::request *)v24;
    v10 = alloca(4 * (v8 / 24));
    v33[2] = (const vostok::variant<32> *const *)&v24[v8 / 24];
    v33[0] = (const vostok::variant<32> *const *)v24;
    v33[1] = (const vostok::variant<32> *const *)v24;
    v11 = alloca(48 * (v8 / 24));
    v35 = v24;
    v36 = v24;
    pointer = (vostok::variant<32> *)v7->data.pointer;
    v13 = (vostok::variant<32> *)(*(_DWORD *)v41[0] + v8);
    v37 = &v24[12 * v40];
    v41[0] = pointer;
    v34 = v13;
    if ( pointer != v13 )
    {
      v28 = uri;
      while ( 1 )
      {
        v14 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)pointer, "type")->data.pointer;
        v32.path = v28;
        v32.id = (vostok::resources::class_id_enum)v14;
        vostok::buffer_vector<vostok::resources::request>::push_back(&v39, &v32);
        v25.m_helper = 0;
        v25.m_type_id = 0;
        vostok::buffer_vector<vostok::variant<32>>::push_back(v15, (int)&v35, &v25);
        vostok::variant<32>::destroy_previous_variable_if_needed(v16, (int)&v25);
        v17 = v41[0];
        v18 = (const vostok::variant<32> *)(v36 - 12);
        vostok::variant<32>::set<vostok::configs::binary_config_value const *>(
          v19,
          (int)(v36 - 12),
          (const vostok::configs::binary_config_value **)v41);
        v41[0] = v18;
        vostok::buffer_vector<vostok::variant<32> const *>::push_back(v20, (int)v33, v41);
        v41[0] = (const vostok::variant<32> *)&v17->m_storage[16];
        if ( &v17->m_storage[16] == (char *)v34 )
          break;
        pointer = (vostok::variant<32> *)v41[0];
      }
    }
    v27.path = (const char *)survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter>::on_effects_loaded;
    v28 = (const char *)v38;
    v29 = v40;
    v27.id = unknown_data_class;
    v30 = survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter>::on_effects_loaded;
    v31 = 0;
    v32.path = (const char *)v38;
    v23 = &v30;
    v32.id = v40;
    if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
    {
      v26[0] = 0;
    }
    else
    {
      v26[2] = (int)v30;
      v26[3] = v31;
      v27 = v32;
      v26[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter>,vostok::resources::queries_result &,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::composite_game_effect_emitter_cook<survarium::composite_game_effect_emitter> *>,boost::arg<1>,boost::_bi::value<unsigned int>>>>'::`2'::stored_vtable
             + 1;
    }
    vostok::resources::query_resources(
      v39.m_begin,
      v39.m_end - v39.m_begin,
      survarium::g_allocator,
      v33[0],
      parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v21, v26);
    vostok::buffer_vector<vostok::variant<32>>::~buffer_vector<vostok::variant<32>>(v22, (int *)&v35);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v6,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
