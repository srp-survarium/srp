void __thiscall survarium::particle_game_effect_emitter_cook::translate_query(
        survarium::particle_game_effect_emitter_cook *this,
        const vostok::variant<32> **parent)
{
  vostok::variant<32> *v2; // esi
  vostok::resources::query_result_for_cook *v3; // ecx
  const vostok::configs::binary_config_value *v4; // edi
  int v5; // eax
  int v6; // ebx
  char *v7; // eax
  char *v8; // ecx
  vostok::configs::binary_config_value *v9; // esi
  const vostok::configs::binary_config_value *v10; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v12; // eax
  float v13; // xmm0_4
  char **v14; // eax
  const vostok::configs::binary_config_value *v15; // eax
  void *v16; // eax
  const char **v17; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v18; // ecx
  const char *v19; // [esp+0h] [ebp-B0h]
  const char *v20; // [esp+4h] [ebp-ACh]
  unsigned int v21; // [esp+8h] [ebp-A8h]
  int v22; // [esp+Ch] [ebp-A4h]
  char *v23; // [esp+Ch] [ebp-A4h]
  char *v24; // [esp+10h] [ebp-A0h]
  const vostok::configs::binary_config_value *v25; // [esp+14h] [ebp-9Ch] BYREF
  int v26; // [esp+18h] [ebp-98h]
  float v27; // [esp+1Ch] [ebp-94h]
  char *v28; // [esp+20h] [ebp-90h]
  const vostok::configs::binary_config_value *v29; // [esp+24h] [ebp-8Ch]
  int v30; // [esp+28h] [ebp-88h]
  survarium::particle_game_effect_emitter_cook *v31; // [esp+2Ch] [ebp-84h]
  int (__cdecl **v32)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type); // [esp+30h] [ebp-80h] BYREF
  void *v33; // [esp+38h] [ebp-78h]
  _DWORD v34[12]; // [esp+50h] [ebp-60h] BYREF
  _DWORD v35[12]; // [esp+80h] [ebp-30h] BYREF

  v2 = (vostok::variant<32> *)parent[66];
  v31 = this;
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value const *>(
         (vostok::variant<32> *)this,
         (int)v2,
         &v25) )
  {
    v4 = vostok::configs::binary_config_value::operator[](v25, "key_frames");
    v5 = 24 * v4->count / 24;
    v29 = v4;
    v6 = v5;
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)0x18,
           (int)survarium::g_allocator,
           8 * v5 + 288,
           "hud_game_effect_emitter",
           v19,
           v20,
           v21);
    v8 = v7;
    v28 = v7;
    if ( v6 )
    {
      v26 = 0;
      v24 = v7;
      v22 = v6;
      do
      {
        v9 = (vostok::configs::binary_config_value *)((char *)v4->data.pointer + v26);
        if ( v24 )
        {
          v10 = vostok::configs::binary_config_value::operator[](v9, "particle_system_time");
          if ( v10->type == 2 )
            pointer = *(float *)&v10->data.pointer;
          else
            pointer = (float)(int)v10->data.pointer;
          v27 = pointer;
          v12 = vostok::configs::binary_config_value::operator[](v9, "time");
          if ( v12->type == 2 )
            v13 = *(float *)&v12->data.pointer;
          else
            v13 = (float)(int)v12->data.pointer;
          v8 = v28;
          v4 = v29;
          *(float *)v24 = v27;
          *((float *)v24 + 1) = v13;
        }
        v26 += 24;
        v24 += 8;
        --v22;
      }
      while ( v22 );
    }
    v14 = (char **)&v8[8 * v6];
    if ( v14 )
    {
      *v14 = v8;
      v14[1] = (char *)v6;
      v23 = &v8[8 * v6];
    }
    else
    {
      v23 = 0;
    }
    v30 = 0;
    v15 = vostok::configs::binary_config_value::operator[](v25, "time_to_finish");
    v34[0] = v31;
    qmemcpy(&v34[2], v15, 0x18u);
    v34[8] = v23;
    v35[1] = v30;
    v35[0] = survarium::particle_game_effect_emitter_cook::on_particle_system_loaded;
    qmemcpy(&v35[2], v34, 0x28u);
    v32 = 0;
    qmemcpy(v34, v35, sizeof(v34));
    if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
    {
      v32 = 0;
    }
    else
    {
      qmemcpy(v35, v34, sizeof(v35));
      v16 = operator new(0x30u);
      if ( v16 )
      {
        qmemcpy(v16, v35, 0x30u);
        v33 = v16;
      }
      else
      {
        v33 = 0;
      }
      v32 = &`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::particle_game_effect_emitter_cook,vostok::resources::queries_result &,float,survarium::value_animation<float,survarium::particle_game_effect_emitter_cook> *>,boost::_bi::list4<boost::_bi::value<survarium::particle_game_effect_emitter_cook *>,boost::arg<1>,boost::_bi::value<vostok::configs::binary_config_value>,boost::_bi::value<survarium::value_animation<float,survarium::particle_game_effect_emitter_cook> *>>>>'::`2'::stored_vtable;
    }
    v17 = (const char **)vostok::configs::binary_config_value::operator[](v25, "particle_system");
    vostok::resources::query_resource(
      *v17,
      (vostok::variant<32> *)0x3E,
      survarium::g_allocator,
      0,
      parent,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v18,
      (int *)&v32);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v3,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
