void __thiscall survarium::medkit::load(survarium::medkit *this, vostok::configs::binary_config_value config, int a3)
{
  _DWORD *pointer; // ebx
  const vostok::configs::binary_config_value *v4; // eax
  float v5; // xmm0_4
  const vostok::configs::binary_config_value *v6; // eax
  float v7; // xmm0_4
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  char *v10; // eax
  vostok::memory::doug_lea_allocator *v11; // esi
  char *v12; // eax
  char *v13; // eax
  bool v14; // zf
  int v15; // esi
  char **v16; // eax
  const vostok::configs::binary_config_value *v17; // eax
  float v18; // xmm0_4
  unsigned int v19; // ecx
  vostok::memory::doug_lea_allocator *v20; // esi
  char *v21; // eax
  char *v22; // eax
  int v23; // esi
  char **v24; // eax
  const void *v25; // eax
  vostok::memory::doug_lea_allocator *v26; // esi
  char *v27; // eax
  int v28; // eax
  _DWORD *v29; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v30; // ecx
  char **v31; // eax
  float v32; // esi
  char **v33; // eax
  const vostok::configs::binary_config_value *v34; // eax
  float v35; // xmm0_4
  const vostok::configs::binary_config_value *v36; // eax
  float v37; // xmm0_4
  const char *v38; // [esp+4h] [ebp-6Ch]
  const char *v39; // [esp+4h] [ebp-6Ch]
  const char *v40; // [esp+4h] [ebp-6Ch]
  const char *v41; // [esp+4h] [ebp-6Ch]
  const char *v42; // [esp+8h] [ebp-68h]
  const char *v43; // [esp+8h] [ebp-68h]
  const char *v44; // [esp+8h] [ebp-68h]
  const char *v45; // [esp+8h] [ebp-68h]
  unsigned int v46; // [esp+Ch] [ebp-64h]
  unsigned int v47; // [esp+Ch] [ebp-64h]
  unsigned int v48; // [esp+Ch] [ebp-64h]
  unsigned int v49; // [esp+Ch] [ebp-64h]
  boost::function1<void,vostok::physics::contact_point const &> v50; // [esp+14h] [ebp-5Ch] BYREF
  _QWORD v51[3]; // [esp+34h] [ebp-3Ch] BYREF
  void (__thiscall *v52)(survarium::medkit *, char *, survarium::hit_type_enum, float *, float *); // [esp+4Ch] [ebp-24h]
  int v53; // [esp+50h] [ebp-20h]
  _DWORD *v54; // [esp+54h] [ebp-1Ch]
  unsigned int v55; // [esp+58h] [ebp-18h]
  float v56; // [esp+60h] [ebp-10h]
  int v57; // [esp+64h] [ebp-Ch]
  unsigned int v58; // [esp+68h] [ebp-8h]

  pointer = config.data.pointer;
  v4 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
         "activity_time_sec");
  if ( v4->type == 2 )
    v5 = *(float *)&v4->data.pointer;
  else
    v5 = (float)(int)v4->data.pointer;
  *(float *)&config.data.pointer = v5;
  if ( v5 <= 0.001 )
  {
    v5 = epsilon_3_4;
    *(float *)&config.data.pointer = epsilon_3_4;
  }
  pointer[82] = vostok::math::floor(v5 * 1000.0);
  v6 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
         "activation_delay_sec");
  if ( v6->type == 2 )
    v7 = *(float *)&v6->data.pointer;
  else
    v7 = (float)(int)v6->data.pointer;
  pointer[83] = vostok::math::floor(v7 * 1000.0);
  qmemcpy(
    v51,
    vostok::configs::binary_config_value::operator[](
      (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
      "influences"),
    sizeof(v51));
  v8 = survarium::g_allocator;
  *((_BYTE *)pointer + 308) = 24 * HIWORD(HIDWORD(v51[2])) / 24;
  v9 = type_info::raw_name(&survarium::medkit::item_influence `RTTI Type Descriptor');
  v10 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)(20 * *((unsigned __int8 *)pointer + 308)),
          (int)v8,
          20 * *((unsigned __int8 *)pointer + 308),
          v9,
          v38,
          v42,
          v46);
  v11 = survarium::g_allocator;
  pointer[75] = v10;
  v12 = type_info::raw_name(&float `RTTI Type Descriptor');
  v13 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)(4 * *((unsigned __int8 *)pointer + 308)),
          (int)v11,
          4 * *((unsigned __int8 *)pointer + 308),
          v12,
          v39,
          v43,
          v47);
  v58 = 0;
  v14 = *((_BYTE *)pointer + 308) == 0;
  pointer[76] = v13;
  if ( !v14 )
  {
    v57 = 0;
    v56 = s_bm_current_air_resistance / *(float *)&config.data.pointer;
    config.data.pointer = (const void *)v51[0];
    do
    {
      v15 = v57 + pointer[75];
      v16 = (char **)vostok::configs::binary_config_value::operator[](
                       (vostok::configs::binary_config_value *)config.data.pointer,
                       "body_part");
      vostok::strings::copy<16>((char (*)[16])v15, *v16);
      v17 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)config.data.pointer,
              "amount");
      if ( v17->type == 2 )
        v18 = *(float *)&v17->data.pointer;
      else
        v18 = (float)(int)v17->data.pointer;
      v19 = v58++;
      v57 += 20;
      config.data.pointer = (char *)config.data.pointer + 24;
      *(float *)(v15 + 16) = v18 * v56;
      *(_DWORD *)(pointer[76] + 4 * v19) = 0;
    }
    while ( v58 < *((unsigned __int8 *)pointer + 308) );
  }
  qmemcpy(
    v51,
    vostok::configs::binary_config_value::operator[](
      (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
      "remove_affects"),
    sizeof(v51));
  v20 = survarium::g_allocator;
  *((_BYTE *)pointer + 316) = 24 * HIWORD(HIDWORD(v51[2])) / 24;
  v21 = type_info::raw_name(&survarium::medkit::affect `RTTI Type Descriptor');
  v22 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)(20 * *((unsigned __int8 *)pointer + 316)),
          (int)v20,
          20 * *((unsigned __int8 *)pointer + 316),
          v21,
          v40,
          v44,
          v48);
  v58 = 0;
  v14 = *((_BYTE *)pointer + 316) == 0;
  pointer[78] = v22;
  if ( !v14 )
  {
    v57 = 0;
    config.data.pointer = (const void *)v51[0];
    do
    {
      v23 = v57 + pointer[78];
      v24 = (char **)vostok::configs::binary_config_value::operator[](
                       (vostok::configs::binary_config_value *)config.data.pointer,
                       "body_part");
      vostok::strings::copy<16>((char (*)[16])v23, *v24);
      v25 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)config.data.pointer,
              "affect")->data.pointer;
      ++v58;
      v57 += 20;
      config.data.pointer = (char *)config.data.pointer + 24;
      *(_DWORD *)(v23 + 16) = v25;
    }
    while ( v58 < *((unsigned __int8 *)pointer + 316) );
  }
  qmemcpy(
    v51,
    vostok::configs::binary_config_value::operator[](
      (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
      "damage_protection"),
    sizeof(v51));
  v26 = survarium::g_allocator;
  *((_BYTE *)pointer + 324) = 24 * HIWORD(HIDWORD(v51[2])) / 24;
  v27 = type_info::raw_name(&survarium::medkit::damage_protection `RTTI Type Descriptor');
  pointer[80] = vostok::memory::doug_lea_allocator::malloc_impl(
                  (vostok::memory::doug_lea_allocator *)(144 * *((unsigned __int8 *)pointer + 324)),
                  (int)v26,
                  144 * *((unsigned __int8 *)pointer + 324),
                  v27,
                  v41,
                  v45,
                  v49);
  v58 = 0;
  if ( *((_BYTE *)pointer + 324) )
  {
    v57 = 0;
    config.data.pointer = (const void *)v51[0];
    do
    {
      v28 = pointer[80];
      v14 = v57 + v28 == 0;
      v29 = (_DWORD *)(v57 + v28);
      v56 = *(float *)&v29;
      if ( !v14 )
      {
        *v29 = &survarium::damage_protector::`vftable';
        v29[2] = 0;
        v29[10] = 0;
        v29[18] = 0;
        v29[26] = 0;
      }
      v52 = survarium::medkit::reduce_damage;
      v53 = 0;
      v54 = pointer;
      LODWORD(v51[1]) = survarium::medkit::reduce_damage;
      HIDWORD(v51[1]) = 0;
      v51[2] = __PAIR64__(v55, (unsigned int)pointer);
      if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
      {
        v50.vtable = 0;
      }
      else
      {
        *(_QWORD *)&v50.functor.obj_ptr = v51[1];
        *((_QWORD *)&v50.functor.data + 1) = v51[2];
        v50.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::medkit,char const *,enum survarium::hit_type_enum,float &,float &>,boost::_bi::list5<boost::_bi::value<survarium::medkit *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>>>>'::`2'::stored_vtable
                                                            + 1);
      }
      boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
        (boost::function1<void,vostok::physics::contact_point const &> *)(LODWORD(v56) + 8),
        &v50);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v30,
        (int *)&v50);
      v31 = (char **)vostok::configs::binary_config_value::operator[](
                       (vostok::configs::binary_config_value *)config.data.pointer,
                       "body_part");
      v32 = v56;
      vostok::strings::copy<16>((char (*)[16])(LODWORD(v56) + 112), *v31);
      v33 = (char **)vostok::configs::binary_config_value::operator[](
                       (vostok::configs::binary_config_value *)config.data.pointer,
                       "hit_type");
      *(_DWORD *)(LODWORD(v32) + 128) = survarium::hit_type(*v33);
      v34 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)config.data.pointer,
              "hit_coeff");
      if ( v34->type == 2 )
        v35 = *(float *)&v34->data.pointer;
      else
        v35 = (float)(int)v34->data.pointer;
      *(float *)(LODWORD(v32) + 132) = v35;
      v36 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)config.data.pointer,
              "threshold");
      if ( v36->type == 2 )
        v37 = *(float *)&v36->data.pointer;
      else
        v37 = (float)(int)v36->data.pointer;
      ++v58;
      v57 += 144;
      config.data.pointer = (char *)config.data.pointer + 24;
      *(float *)(LODWORD(v32) + 136) = v37;
    }
    while ( v58 < *((unsigned __int8 *)pointer + 324) );
  }
}
