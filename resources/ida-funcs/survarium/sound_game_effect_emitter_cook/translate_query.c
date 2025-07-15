void __thiscall survarium::sound_game_effect_emitter_cook::translate_query(
        survarium::sound_game_effect_emitter_cook *this,
        const vostok::variant<32> **parent)
{
  const vostok::variant<32> *v2; // esi
  vostok::resources::query_result_for_cook *v3; // ecx
  const vostok::configs::binary_config_value *v4; // edi
  int v5; // eax
  int v6; // ebx
  char *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // esi
  vostok::configs::binary_config_value *v10; // ecx
  const vostok::configs::binary_config_value *v11; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v13; // eax
  float v14; // xmm0_4
  const vostok::configs::binary_config_value *v15; // eax
  float v16; // xmm0_4
  char *v17; // eax
  vostok::configs::binary_config_value **v18; // eax
  vostok::configs::binary_config_value *v19; // eax
  vostok::configs::binary_config_value *v20; // eax
  vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value *v22; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v23; // ecx
  const char *v24; // [esp+0h] [ebp-70h]
  const char *v25; // [esp+4h] [ebp-6Ch]
  unsigned int v26; // [esp+8h] [ebp-68h]
  const vostok::configs::binary_config_value *v27; // [esp+10h] [ebp-60h] BYREF
  char *v28; // [esp+14h] [ebp-5Ch]
  int v29; // [esp+18h] [ebp-58h]
  char *v30; // [esp+1Ch] [ebp-54h]
  const vostok::configs::binary_config_value *v31; // [esp+20h] [ebp-50h]
  void (__thiscall *v32)(survarium::sound_game_effect_emitter_cook *, vostok::particle::particle_system_instance_impl *, survarium::pure_game_effect_emitter_base *); // [esp+24h] [ebp-4Ch]
  vostok::resources::class_id_enum v33; // [esp+28h] [ebp-48h]
  survarium::sound_game_effect_emitter_cook *v34; // [esp+2Ch] [ebp-44h]
  void (__thiscall *v35)(survarium::sound_game_effect_emitter_cook *, vostok::particle::particle_system_instance_impl *, survarium::pure_game_effect_emitter_base *); // [esp+30h] [ebp-40h] BYREF
  float v36; // [esp+34h] [ebp-3Ch]
  survarium::sound_game_effect_emitter_cook *v37; // [esp+38h] [ebp-38h]
  char *v38; // [esp+3Ch] [ebp-34h]
  survarium::sound_game_effect_emitter_cook *v39; // [esp+40h] [ebp-30h]
  char *v40; // [esp+44h] [ebp-2Ch]
  vostok::resources::request v41; // [esp+50h] [ebp-20h] BYREF
  int v42; // [esp+58h] [ebp-18h]
  vostok::resources::class_id_enum v43; // [esp+5Ch] [ebp-14h]
  void (__thiscall *v44)(survarium::sound_game_effect_emitter_cook *, vostok::particle::particle_system_instance_impl *, survarium::pure_game_effect_emitter_base *); // [esp+60h] [ebp-10h]
  char *v45; // [esp+64h] [ebp-Ch]
  survarium::sound_game_effect_emitter_cook *v46; // [esp+68h] [ebp-8h]
  char *v47; // [esp+6Ch] [ebp-4h]

  v2 = parent[66];
  v34 = this;
  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value const *>(
         (vostok::variant<32> *)this,
         (int)v2,
         &v27) )
  {
    v4 = vostok::configs::binary_config_value::operator[](v27, "key_frames");
    v5 = 24 * v4->count / 24;
    v31 = v4;
    v6 = v5;
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)0x18,
           (int)survarium::g_allocator,
           12 * (v5 + 24),
           "sound_game_effect_emitter",
           v24,
           v25,
           v26);
    v8 = (vostok::configs::binary_config_value *)v7;
    v33 = (vostok::resources::class_id_enum)v7;
    if ( v6 )
    {
      v29 = 0;
      v28 = v7;
      v30 = (char *)v6;
      while ( 1 )
      {
        v9 = (vostok::configs::binary_config_value *)((char *)v4->data.pointer + v29);
        if ( vostok::configs::binary_config_value::value_exists(v8, (int)v9, (unsigned int)"mean_offset") )
        {
          v11 = vostok::configs::binary_config_value::operator[](v9, "mean_offset");
          if ( v11->type == 2 )
            pointer = *(float *)&v11->data.pointer;
          else
            pointer = (float)(int)v11->data.pointer;
        }
        else
        {
          pointer = 0.0;
        }
        v32 = (void (__thiscall *)(survarium::sound_game_effect_emitter_cook *, vostok::particle::particle_system_instance_impl *, survarium::pure_game_effect_emitter_base *))LODWORD(pointer);
        if ( vostok::configs::binary_config_value::value_exists(v10, (int)v9, (unsigned int)"max_offset") )
        {
          v13 = vostok::configs::binary_config_value::operator[](v9, "max_offset");
          if ( v13->type == 2 )
            v14 = *(float *)&v13->data.pointer;
          else
            v14 = (float)(int)v13->data.pointer;
        }
        else
        {
          v14 = 0.0;
        }
        v35 = v32;
        v36 = v14;
        if ( v28 )
        {
          v15 = vostok::configs::binary_config_value::operator[](v9, "time");
          if ( v15->type == 2 )
            v16 = *(float *)&v15->data.pointer;
          else
            v16 = (float)(int)v15->data.pointer;
          v17 = v28;
          *(_DWORD *)v28 = v35;
          v8 = (vostok::configs::binary_config_value *)LODWORD(v36);
          *((float *)v17 + 1) = v36;
          *((float *)v17 + 2) = v16;
        }
        v29 += 24;
        v28 += 12;
        if ( !--v30 )
          break;
        v4 = v31;
      }
      v8 = (vostok::configs::binary_config_value *)v33;
    }
    v18 = (vostok::configs::binary_config_value **)((char *)v8 + 12 * v6);
    if ( v18 )
    {
      *v18 = v8;
      v18[1] = (vostok::configs::binary_config_value *)v6;
      v30 = (char *)v8 + 12 * v6;
    }
    else
    {
      v30 = 0;
    }
    v19 = vostok::configs::binary_config_value::operator[](v27, "sounds");
    v33 = *(_DWORD *)vostok::configs::binary_config_value::operator[](v19, "first_person")->data.pointer;
    v20 = vostok::configs::binary_config_value::operator[](v27, "sounds");
    v41.path = (const char *)*((_DWORD *)vostok::configs::binary_config_value::operator[](v20, "first_person")->data.pointer
                             + 6);
    v41.id = v33;
    v21 = vostok::configs::binary_config_value::operator[](v27, "sounds");
    v33 = *(_DWORD *)vostok::configs::binary_config_value::operator[](v21, "third_person")->data.pointer;
    v22 = vostok::configs::binary_config_value::operator[](v27, "sounds");
    v42 = *((_DWORD *)vostok::configs::binary_config_value::operator[](v22, "third_person")->data.pointer + 6);
    v43 = v33;
    v35 = survarium::sound_game_effect_emitter_cook::on_sound_emitters_loaded;
    v37 = v34;
    v38 = v30;
    v36 = 0.0;
    v44 = survarium::sound_game_effect_emitter_cook::on_sound_emitters_loaded;
    v45 = 0;
    v46 = v34;
    v47 = v30;
    if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
    {
      v35 = 0;
    }
    else
    {
      v37 = (survarium::sound_game_effect_emitter_cook *)v44;
      v38 = v45;
      v39 = v46;
      v40 = v47;
      v35 = (void (__thiscall *)(survarium::sound_game_effect_emitter_cook *, vostok::particle::particle_system_instance_impl *, survarium::pure_game_effect_emitter_base *))((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::sound_game_effect_emitter_cook,vostok::resources::queries_result &,survarium::value_animation<survarium::sound_game_effect::properties,survarium::sound_game_effect_emitter_cook> *>,boost::_bi::list3<boost::_bi::value<survarium::sound_game_effect_emitter_cook *>,boost::arg<1>,boost::_bi::value<survarium::value_animation<survarium::sound_game_effect::properties,survarium::sound_game_effect_emitter_cook> *>>>>'::`2'::stored_vtable + 1);
    }
    vostok::resources::query_resources(&v41, 2u, survarium::g_allocator, 0, parent, assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v23,
      (int *)&v35);
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
