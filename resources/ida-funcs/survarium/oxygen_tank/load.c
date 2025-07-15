void __thiscall survarium::oxygen_tank::load(
        survarium::oxygen_tank *this,
        vostok::configs::binary_config_value config,
        int a3)
{
  _DWORD *pointer; // ebx
  const vostok::configs::binary_config_value *v4; // eax
  float v5; // xmm0_4
  unsigned int v6; // eax
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  int v9; // eax
  bool v10; // zf
  _DWORD *v11; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  char **v13; // eax
  float *v14; // esi
  char **v15; // eax
  const vostok::configs::binary_config_value *v16; // eax
  float v17; // xmm0_4
  const vostok::configs::binary_config_value *v18; // eax
  float v19; // xmm0_4
  const char *v20; // [esp+4h] [ebp-6Ch]
  const char *v21; // [esp+8h] [ebp-68h]
  unsigned int v22; // [esp+Ch] [ebp-64h]
  boost::function1<void,vostok::physics::contact_point const &> v23; // [esp+14h] [ebp-5Ch] BYREF
  _QWORD v24[3]; // [esp+34h] [ebp-3Ch] BYREF
  void (__thiscall *v25)(survarium::oxygen_tank *, char *, survarium::hit_type_enum, float *, float *); // [esp+4Ch] [ebp-24h]
  int v26; // [esp+50h] [ebp-20h]
  _DWORD *v27; // [esp+54h] [ebp-1Ch]
  unsigned int v28; // [esp+58h] [ebp-18h]
  _DWORD *v29; // [esp+60h] [ebp-10h]
  unsigned int v30; // [esp+64h] [ebp-Ch]
  int v31; // [esp+68h] [ebp-8h]

  pointer = config.data.pointer;
  v4 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
         "amount_time_sec");
  if ( v4->type == 2 )
    v5 = *(float *)&v4->data.pointer;
  else
    v5 = (float)(int)v4->data.pointer;
  v6 = vostok::math::floor(v5 * 1000.0);
  *((_DWORD *)config.data.pointer + 76) = v6;
  *((_DWORD *)config.data.pointer + 77) = v6;
  qmemcpy(
    v24,
    vostok::configs::binary_config_value::operator[](
      (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
      "influences"),
    sizeof(v24));
  v7 = survarium::g_allocator;
  *((_BYTE *)config.data.pointer + 316) = 24 * HIWORD(HIDWORD(v24[2])) / 24;
  v8 = type_info::raw_name(&survarium::oxygen_tank::item_influence `RTTI Type Descriptor');
  *((_DWORD *)config.data.pointer + 78) = vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)(144
                                                                                 * *((unsigned __int8 *)config.data.pointer
                                                                                   + 316)),
                                            (int)v7,
                                            144 * *((unsigned __int8 *)config.data.pointer + 316),
                                            v8,
                                            v20,
                                            v21,
                                            v22);
  v30 = 0;
  if ( *((_BYTE *)config.data.pointer + 316) )
  {
    v31 = 0;
    config.data.pointer = (const void *)v24[0];
    do
    {
      v9 = pointer[78];
      v10 = v31 + v9 == 0;
      v11 = (_DWORD *)(v31 + v9);
      v29 = v11;
      if ( !v10 )
      {
        *v11 = &survarium::damage_protector::`vftable';
        v11[2] = 0;
        v11[10] = 0;
        v11[18] = 0;
        v11[26] = 0;
      }
      v25 = survarium::oxygen_tank::reduce_damage;
      v26 = 0;
      v27 = pointer;
      LODWORD(v24[1]) = survarium::oxygen_tank::reduce_damage;
      HIDWORD(v24[1]) = 0;
      v24[2] = __PAIR64__(v28, (unsigned int)pointer);
      if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
      {
        v23.vtable = 0;
      }
      else
      {
        *(_QWORD *)&v23.functor.obj_ptr = v24[1];
        *((_QWORD *)&v23.functor.data + 1) = v24[2];
        v23.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::oxygen_tank,char const *,enum survarium::hit_type_enum,float &,float &>,boost::_bi::list5<boost::_bi::value<survarium::oxygen_tank *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>>>>'::`2'::stored_vtable
                                                            + 1);
      }
      boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
        (boost::function1<void,vostok::physics::contact_point const &> *)(v29 + 2),
        &v23);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v12,
        (int *)&v23);
      v13 = (char **)vostok::configs::binary_config_value::operator[](
                       (vostok::configs::binary_config_value *)config.data.pointer,
                       "body_part");
      v14 = (float *)v29;
      vostok::strings::copy<16>((char (*)[16])((char *)v29 + 7), *v13);
      v15 = (char **)vostok::configs::binary_config_value::operator[](
                       (vostok::configs::binary_config_value *)config.data.pointer,
                       "hit_type");
      *((_DWORD *)v14 + 32) = survarium::hit_type(*v15);
      v16 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)config.data.pointer,
              "hit_coeff");
      if ( v16->type == 2 )
        v17 = *(float *)&v16->data.pointer;
      else
        v17 = (float)(int)v16->data.pointer;
      v14[33] = v17;
      v18 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)config.data.pointer,
              "threshold");
      if ( v18->type == 2 )
        v19 = *(float *)&v18->data.pointer;
      else
        v19 = (float)(int)v18->data.pointer;
      ++v30;
      v31 += 144;
      config.data.pointer = (char *)config.data.pointer + 24;
      v14[34] = v19;
    }
    while ( v30 < *((unsigned __int8 *)pointer + 316) );
  }
}
