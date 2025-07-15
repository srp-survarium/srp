void __thiscall vostok::network_core::buffer_writer::w(
        vostok::network_core::buffer_writer *this,
        _DWORD *buffer,
        unsigned __int8 *buffer_size,
        unsigned int count)
{
  vostok::network_core::mutable_buffer *v4; // esi
  unsigned int m_size; // ebx

  v4 = (vostok::network_core::mutable_buffer *)buffer[5];
  m_size = v4->m_size;
  vostok::network_core::mutable_buffer::resize(v4, m_size + count);
  memcpy((unsigned __int8 *)(m_size + *(_DWORD *)(buffer[5] + 4)), buffer_size, count);
}


void __userpurge vostok::network_core::buffer_writer::w<signed char>(
        char *value@<eax>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::buffer_writer *this,
        const char *const file,
        const int line,
        const char *const function,
        const char *const expression)
{
  vostok::network_core::buffer_writer::serialization_operation_descriptor *v9; // eax
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v10; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // ecx
  bool has_passed_filters; // al
  bool v13; // al
  bool v14; // al
  bool v15; // al
  bool v16; // zf
  bool v17; // al
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  bool v22; // al
  bool v23; // al
  bool v24; // al
  const char *v25; // edi
  char player_id; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v28; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v30; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v32; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v33; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v34; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v36; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v37; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v38; // [esp+20h] [ebp-3Ch]
  const char *v39; // [esp+24h] [ebp-38h]
  unsigned __int8 v40; // [esp+24h] [ebp-38h]
  const char *v41; // [esp+28h] [ebp-34h]
  unsigned int v42; // [esp+2Ch] [ebp-30h]
  void *v43; // [esp+38h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v44; // [esp+3Ch] [ebp-20h] BYREF
  __int16 v45; // [esp+60h] [ebp+4h]

  v45 = 0;
  if ( vostok::network_core::g_debug_hash_mismatches && vostok::network_core::g_debug_hash_mismatches_enabled )
  {
    v43 = vostok::memory::new_helper<vostok::network_core::buffer_writer::serialization_operation_descriptor>::call<vostok::memory::pthreads3_allocator>(
            &vostok::memory::g_mt_allocator,
            v39,
            v41,
            v42);
    if ( v43 )
    {
      player_id = this->player_id;
      v9 = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)type_info::name(
                                                                                        &signed char `RTTI Type Descriptor',
                                                                                        &__type_info_root_node);
      vostok::network_core::buffer_writer::serialization_operation_descriptor::serialization_operation_descriptor(
        v9,
        (int)v43,
        "static_cast< s8 >( m_initiator_stance )",
        "survarium::bullet::serialize",
        ".\\bullet.cpp",
        (const char *const)0xA4,
        1,
        player_id,
        v40);
    }
    else
    {
      v10 = 0;
    }
    vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v10,
      (int)this);
  }
  vostok::network_core::buffer_writer::w(a2, this, (unsigned __int8 *)value, 1u);
  if ( vostok::network_core::g_debug_dump_serialization_info )
  {
    if ( type_info::operator==(&signed char `RTTI Type Descriptor', &vostok::math::float4x4 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"net_hash",
                                   (const char *)2),
            v11 = v27,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        LOBYTE(v45) = 1;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x6Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          *((float *)value + 2),
          *((float *)value + 3),
          "static_cast< s8 >( m_initiator_stance )");
      }
      if ( (v45 & 1) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFE;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v13 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v28,
            v13) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        LOBYTE(v45) = v45 | 2;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x70u,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 4),
          *((float *)value + 5),
          *((float *)value + 6),
          *((float *)value + 7),
          "static_cast< s8 >( m_initiator_stance )");
      }
      if ( (v45 & 2) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFD;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v29,
            v14) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        LOBYTE(v45) = v45 | 4;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x71u,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 8),
          *((float *)value + 9),
          *((float *)value + 10),
          *((float *)value + 11),
          "static_cast< s8 >( m_initiator_stance )");
      }
      if ( (v45 & 4) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFB;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v15 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v30,
            v15) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        LOBYTE(v45) = v45 | 8;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x72u,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 12),
          *((float *)value + 13),
          *((float *)value + 14),
          *((float *)value + 15),
          "static_cast< s8 >( m_initiator_stance )");
      }
      v16 = (v45 & 8) == 0;
    }
    else if ( type_info::operator==(&signed char `RTTI Type Descriptor', &float `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v17 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v31,
            v17) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        LOBYTE(v45) = 16;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x75u,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%.8g(%s)",
          *(float *)value,
          "static_cast< s8 >( m_initiator_stance )");
      }
      v16 = (v45 & 0x10) == 0;
    }
    else if ( type_info::operator==(&signed char `RTTI Type Descriptor', &vostok::math::float2 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v32,
            v18) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        LOBYTE(v45) = 32;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x78u,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          "static_cast< s8 >( m_initiator_stance )");
      }
      v16 = (v45 & 0x20) == 0;
    }
    else if ( type_info::operator==(&signed char `RTTI Type Descriptor', &vostok::math::float3 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v19 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v33,
            v19) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        LOBYTE(v45) = 64;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Bu,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          *((float *)value + 2),
          "static_cast< s8 >( m_initiator_stance )");
      }
      v16 = (v45 & 0x40) == 0;
    }
    else if ( type_info::operator==(&signed char `RTTI Type Descriptor', &unsigned __int64 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v20 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v34,
            v20) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        LOBYTE(v45) = 0x80;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Du,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%I64d(%s)",
          *(_QWORD *)value,
          "static_cast< s8 >( m_initiator_stance )");
      }
      v16 = (v45 & 0x80u) == 0;
    }
    else if ( type_info::operator==(&signed char `RTTI Type Descriptor', &unsigned int `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v21 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v35,
            v21) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        v45 = 256;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(_DWORD *)value,
          "static_cast< s8 >( m_initiator_stance )");
      }
      v16 = (v45 & 0x100) == 0;
    }
    else if ( type_info::operator==(&signed char `RTTI Type Descriptor', &unsigned short `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v36,
            v22) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        v45 = 512;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x81u,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(unsigned __int16 *)value,
          "static_cast< s8 >( m_initiator_stance )");
      }
      v16 = (v45 & 0x200) == 0;
    }
    else if ( type_info::operator==(&signed char `RTTI Type Descriptor', &unsigned char `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v23 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v37,
            v23) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        v45 = 1024;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x83u,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          (unsigned __int8)*value,
          "static_cast< s8 >( m_initiator_stance )");
      }
      v16 = (v45 & 0x400) == 0;
    }
    else
    {
      if ( !type_info::operator==(&signed char `RTTI Type Descriptor', &bool `RTTI Type Descriptor') )
        return;
      if ( !vostok::core::g_log_filter_tree
        || (v24 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v38,
            v24) )
      {
        v16 = *value == 0;
        v25 = "true";
        if ( v16 )
          v25 = "false";
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v44);
        v45 = 2048;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x85u,
          "void __thiscall vostok::network_core::buffer_writer::w<signed char>(const signed char &,const char *const ,con"
          "st int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%s(%s)",
          v25,
          "static_cast< s8 >( m_initiator_stance )");
      }
      v16 = (v45 & 0x800) == 0;
    }
    if ( !v16 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
        (int *)&v44);
  }
}


void __userpurge vostok::network_core::buffer_writer::w<unsigned char>(
        unsigned __int8 *value@<eax>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::buffer_writer *this,
        const char *file,
        const char *line,
        const char *function,
        const char *expression)
{
  vostok::network_core::buffer_writer::serialization_operation_descriptor *v8; // eax
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v9; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool has_passed_filters; // al
  bool v12; // al
  bool v13; // al
  bool v14; // al
  bool v15; // zf
  bool v16; // al
  bool v17; // al
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  bool v22; // al
  bool v23; // al
  const char *v24; // edi
  char player_id; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v26; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v28; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v30; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v32; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v33; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v34; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v36; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v37; // [esp+20h] [ebp-3Ch]
  const char *v38; // [esp+24h] [ebp-38h]
  unsigned __int8 v39; // [esp+24h] [ebp-38h]
  const char *v40; // [esp+28h] [ebp-34h]
  unsigned int v41; // [esp+2Ch] [ebp-30h]
  __int16 v42; // [esp+34h] [ebp-28h]
  void *v43; // [esp+38h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v44; // [esp+3Ch] [ebp-20h] BYREF

  v42 = 0;
  if ( vostok::network_core::g_debug_hash_mismatches && vostok::network_core::g_debug_hash_mismatches_enabled )
  {
    v43 = vostok::memory::new_helper<vostok::network_core::buffer_writer::serialization_operation_descriptor>::call<vostok::memory::pthreads3_allocator>(
            &vostok::memory::g_mt_allocator,
            v38,
            v40,
            v41);
    if ( v43 )
    {
      player_id = this->player_id;
      v8 = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)type_info::name(
                                                                                        &unsigned char `RTTI Type Descriptor',
                                                                                        &__type_info_root_node);
      vostok::network_core::buffer_writer::serialization_operation_descriptor::serialization_operation_descriptor(
        v8,
        (int)v43,
        expression,
        function,
        file,
        line,
        1,
        player_id,
        v39);
    }
    else
    {
      v9 = 0;
    }
    vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v9,
      (int)this);
  }
  vostok::network_core::buffer_writer::w(a2, this, value, 1u);
  if ( vostok::network_core::g_debug_dump_serialization_info )
  {
    if ( type_info::operator==(&unsigned char `RTTI Type Descriptor', &vostok::math::float4x4 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"net_hash",
                                   (const char *)2),
            v10 = v26,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 1;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x6Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          *((float *)value + 2),
          *((float *)value + 3),
          expression);
      }
      if ( (v42 & 1) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFE;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v12 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v27,
            v12) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 2;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x70u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 4),
          *((float *)value + 5),
          *((float *)value + 6),
          *((float *)value + 7),
          expression);
      }
      if ( (v42 & 2) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFD;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v13 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v28,
            v13) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 4;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x71u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 8),
          *((float *)value + 9),
          *((float *)value + 10),
          *((float *)value + 11),
          expression);
      }
      if ( (v42 & 4) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFB;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v29,
            v14) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 8;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x72u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 12),
          *((float *)value + 13),
          *((float *)value + 14),
          *((float *)value + 15),
          expression);
      }
      v15 = (v42 & 8) == 0;
    }
    else if ( type_info::operator==(&unsigned char `RTTI Type Descriptor', &float `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v16 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v30,
            v16) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 16;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x75u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%.8g(%s)",
          *(float *)value,
          expression);
      }
      v15 = (v42 & 0x10) == 0;
    }
    else if ( type_info::operator==(&unsigned char `RTTI Type Descriptor', &vostok::math::float2 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v17 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v31,
            v17) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 32;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x78u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          expression);
      }
      v15 = (v42 & 0x20) == 0;
    }
    else if ( type_info::operator==(&unsigned char `RTTI Type Descriptor', &vostok::math::float3 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v32,
            v18) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 64;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Bu,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          *((float *)value + 2),
          expression);
      }
      v15 = (v42 & 0x40) == 0;
    }
    else if ( type_info::operator==(&unsigned char `RTTI Type Descriptor', &unsigned __int64 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v19 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v33,
            v19) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 0x80;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Du,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%I64d(%s)",
          *(_QWORD *)value,
          expression);
      }
      v15 = (v42 & 0x80u) == 0;
    }
    else if ( type_info::operator==(&unsigned char `RTTI Type Descriptor', &unsigned int `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v20 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v34,
            v20) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 256;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(_DWORD *)value,
          expression);
      }
      v15 = (v42 & 0x100) == 0;
    }
    else if ( type_info::operator==(&unsigned char `RTTI Type Descriptor', &unsigned short `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v21 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v35,
            v21) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 512;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x81u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(unsigned __int16 *)value,
          expression);
      }
      v15 = (v42 & 0x200) == 0;
    }
    else if ( type_info::operator==(&unsigned char `RTTI Type Descriptor', &unsigned char `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v36,
            v22) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 1024;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x83u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *value,
          expression);
      }
      v15 = (v42 & 0x400) == 0;
    }
    else
    {
      if ( !type_info::operator==(&unsigned char `RTTI Type Descriptor', &bool `RTTI Type Descriptor') )
        return;
      if ( !vostok::core::g_log_filter_tree
        || (v23 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v37,
            v23) )
      {
        v15 = *value == 0;
        v24 = "true";
        if ( v15 )
          v24 = "false";
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 2048;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x85u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned char>(const unsigned char &,const char *const "
          ",const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%s(%s)",
          v24,
          expression);
      }
      v15 = (v42 & 0x800) == 0;
    }
    if ( !v15 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
        (int *)&v44);
  }
}


void __userpurge vostok::network_core::buffer_writer::w<unsigned short>(
        unsigned __int8 *value@<eax>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::buffer_writer *this,
        const char *file,
        const char *line,
        const char *function,
        const char *expression)
{
  vostok::network_core::buffer_writer::serialization_operation_descriptor *v8; // eax
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v9; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool has_passed_filters; // al
  bool v12; // al
  bool v13; // al
  bool v14; // al
  bool v15; // zf
  bool v16; // al
  bool v17; // al
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  bool v22; // al
  bool v23; // al
  const char *v24; // edi
  char player_id; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v26; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v28; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v30; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v32; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v33; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v34; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v36; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v37; // [esp+20h] [ebp-3Ch]
  const char *v38; // [esp+24h] [ebp-38h]
  unsigned __int8 v39; // [esp+24h] [ebp-38h]
  const char *v40; // [esp+28h] [ebp-34h]
  unsigned int v41; // [esp+2Ch] [ebp-30h]
  __int16 v42; // [esp+34h] [ebp-28h]
  void *v43; // [esp+38h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v44; // [esp+3Ch] [ebp-20h] BYREF

  v42 = 0;
  if ( vostok::network_core::g_debug_hash_mismatches && vostok::network_core::g_debug_hash_mismatches_enabled )
  {
    v43 = vostok::memory::new_helper<vostok::network_core::buffer_writer::serialization_operation_descriptor>::call<vostok::memory::pthreads3_allocator>(
            &vostok::memory::g_mt_allocator,
            v38,
            v40,
            v41);
    if ( v43 )
    {
      player_id = this->player_id;
      v8 = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)type_info::name(
                                                                                        &unsigned short `RTTI Type Descriptor',
                                                                                        &__type_info_root_node);
      vostok::network_core::buffer_writer::serialization_operation_descriptor::serialization_operation_descriptor(
        v8,
        (int)v43,
        expression,
        function,
        file,
        line,
        2,
        player_id,
        v39);
    }
    else
    {
      v9 = 0;
    }
    vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v9,
      (int)this);
  }
  vostok::network_core::buffer_writer::w(a2, this, value, 2u);
  if ( vostok::network_core::g_debug_dump_serialization_info )
  {
    if ( type_info::operator==(&unsigned short `RTTI Type Descriptor', &vostok::math::float4x4 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"net_hash",
                                   (const char *)2),
            v10 = v26,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 1;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x6Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          *((float *)value + 2),
          *((float *)value + 3),
          expression);
      }
      if ( (v42 & 1) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFE;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v12 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v27,
            v12) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 2;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x70u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 4),
          *((float *)value + 5),
          *((float *)value + 6),
          *((float *)value + 7),
          expression);
      }
      if ( (v42 & 2) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFD;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v13 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v28,
            v13) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 4;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x71u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 8),
          *((float *)value + 9),
          *((float *)value + 10),
          *((float *)value + 11),
          expression);
      }
      if ( (v42 & 4) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFB;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v29,
            v14) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 8;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x72u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 12),
          *((float *)value + 13),
          *((float *)value + 14),
          *((float *)value + 15),
          expression);
      }
      v15 = (v42 & 8) == 0;
    }
    else if ( type_info::operator==(&unsigned short `RTTI Type Descriptor', &float `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v16 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v30,
            v16) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 16;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x75u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%.8g(%s)",
          *(float *)value,
          expression);
      }
      v15 = (v42 & 0x10) == 0;
    }
    else if ( type_info::operator==(
                &unsigned short `RTTI Type Descriptor',
                &vostok::math::float2 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v17 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v31,
            v17) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 32;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x78u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          expression);
      }
      v15 = (v42 & 0x20) == 0;
    }
    else if ( type_info::operator==(
                &unsigned short `RTTI Type Descriptor',
                &vostok::math::float3 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v32,
            v18) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 64;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Bu,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          *((float *)value + 2),
          expression);
      }
      v15 = (v42 & 0x40) == 0;
    }
    else if ( type_info::operator==(&unsigned short `RTTI Type Descriptor', &unsigned __int64 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v19 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v33,
            v19) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 0x80;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Du,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%I64d(%s)",
          *(_QWORD *)value,
          expression);
      }
      v15 = (v42 & 0x80u) == 0;
    }
    else if ( type_info::operator==(&unsigned short `RTTI Type Descriptor', &unsigned int `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v20 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v34,
            v20) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 256;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(_DWORD *)value,
          expression);
      }
      v15 = (v42 & 0x100) == 0;
    }
    else if ( type_info::operator==(&unsigned short `RTTI Type Descriptor', &unsigned short `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v21 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v35,
            v21) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 512;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x81u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(unsigned __int16 *)value,
          expression);
      }
      v15 = (v42 & 0x200) == 0;
    }
    else if ( type_info::operator==(&unsigned short `RTTI Type Descriptor', &unsigned char `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v36,
            v22) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 1024;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x83u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *value,
          expression);
      }
      v15 = (v42 & 0x400) == 0;
    }
    else
    {
      if ( !type_info::operator==(&unsigned short `RTTI Type Descriptor', &bool `RTTI Type Descriptor') )
        return;
      if ( !vostok::core::g_log_filter_tree
        || (v23 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v37,
            v23) )
      {
        v15 = *value == 0;
        v24 = "true";
        if ( v15 )
          v24 = "false";
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 2048;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x85u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned short>(const unsigned short &,const char *cons"
          "t ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%s(%s)",
          v24,
          expression);
      }
      v15 = (v42 & 0x800) == 0;
    }
    if ( !v15 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
        (int *)&v44);
  }
}


void __userpurge vostok::network_core::buffer_writer::w<unsigned int>(
        unsigned __int8 *value@<eax>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::buffer_writer *this,
        const char *file,
        const char *line,
        const char *function,
        const char *expression)
{
  vostok::network_core::buffer_writer::serialization_operation_descriptor *v8; // eax
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v9; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool has_passed_filters; // al
  bool v12; // al
  bool v13; // al
  bool v14; // al
  bool v15; // zf
  bool v16; // al
  bool v17; // al
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  bool v22; // al
  bool v23; // al
  const char *v24; // edi
  char player_id; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v26; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v28; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v30; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v32; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v33; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v34; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v36; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v37; // [esp+20h] [ebp-3Ch]
  const char *v38; // [esp+24h] [ebp-38h]
  unsigned __int8 v39; // [esp+24h] [ebp-38h]
  const char *v40; // [esp+28h] [ebp-34h]
  unsigned int v41; // [esp+2Ch] [ebp-30h]
  __int16 v42; // [esp+34h] [ebp-28h]
  void *v43; // [esp+38h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v44; // [esp+3Ch] [ebp-20h] BYREF

  v42 = 0;
  if ( vostok::network_core::g_debug_hash_mismatches && vostok::network_core::g_debug_hash_mismatches_enabled )
  {
    v43 = vostok::memory::new_helper<vostok::network_core::buffer_writer::serialization_operation_descriptor>::call<vostok::memory::pthreads3_allocator>(
            &vostok::memory::g_mt_allocator,
            v38,
            v40,
            v41);
    if ( v43 )
    {
      player_id = this->player_id;
      v8 = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)type_info::name(
                                                                                        &unsigned int `RTTI Type Descriptor',
                                                                                        &__type_info_root_node);
      vostok::network_core::buffer_writer::serialization_operation_descriptor::serialization_operation_descriptor(
        v8,
        (int)v43,
        expression,
        function,
        file,
        line,
        4,
        player_id,
        v39);
    }
    else
    {
      v9 = 0;
    }
    vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v9,
      (int)this);
  }
  vostok::network_core::buffer_writer::w(a2, this, value, 4u);
  if ( vostok::network_core::g_debug_dump_serialization_info )
  {
    if ( type_info::operator==(&unsigned int `RTTI Type Descriptor', &vostok::math::float4x4 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"net_hash",
                                   (const char *)2),
            v10 = v26,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 1;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x6Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          *((float *)value + 2),
          *((float *)value + 3),
          expression);
      }
      if ( (v42 & 1) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFE;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v12 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v27,
            v12) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 2;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x70u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 4),
          *((float *)value + 5),
          *((float *)value + 6),
          *((float *)value + 7),
          expression);
      }
      if ( (v42 & 2) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFD;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v13 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v28,
            v13) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 4;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x71u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 8),
          *((float *)value + 9),
          *((float *)value + 10),
          *((float *)value + 11),
          expression);
      }
      if ( (v42 & 4) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFB;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v29,
            v14) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 8;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x72u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 12),
          *((float *)value + 13),
          *((float *)value + 14),
          *((float *)value + 15),
          expression);
      }
      v15 = (v42 & 8) == 0;
    }
    else if ( type_info::operator==(&unsigned int `RTTI Type Descriptor', &float `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v16 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v30,
            v16) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 16;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x75u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%.8g(%s)",
          *(float *)value,
          expression);
      }
      v15 = (v42 & 0x10) == 0;
    }
    else if ( type_info::operator==(&unsigned int `RTTI Type Descriptor', &vostok::math::float2 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v17 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v31,
            v17) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 32;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x78u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          expression);
      }
      v15 = (v42 & 0x20) == 0;
    }
    else if ( type_info::operator==(&unsigned int `RTTI Type Descriptor', &vostok::math::float3 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v32,
            v18) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 64;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Bu,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          *((float *)value + 2),
          expression);
      }
      v15 = (v42 & 0x40) == 0;
    }
    else if ( type_info::operator==(&unsigned int `RTTI Type Descriptor', &unsigned __int64 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v19 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v33,
            v19) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 0x80;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Du,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%I64d(%s)",
          *(_QWORD *)value,
          expression);
      }
      v15 = (v42 & 0x80u) == 0;
    }
    else if ( type_info::operator==(&unsigned int `RTTI Type Descriptor', &unsigned int `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v20 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v34,
            v20) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 256;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(_DWORD *)value,
          expression);
      }
      v15 = (v42 & 0x100) == 0;
    }
    else if ( type_info::operator==(&unsigned int `RTTI Type Descriptor', &unsigned short `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v21 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v35,
            v21) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 512;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x81u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(unsigned __int16 *)value,
          expression);
      }
      v15 = (v42 & 0x200) == 0;
    }
    else if ( type_info::operator==(&unsigned int `RTTI Type Descriptor', &unsigned char `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v36,
            v22) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 1024;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x83u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *value,
          expression);
      }
      v15 = (v42 & 0x400) == 0;
    }
    else
    {
      if ( !type_info::operator==(&unsigned int `RTTI Type Descriptor', &bool `RTTI Type Descriptor') )
        return;
      if ( !vostok::core::g_log_filter_tree
        || (v23 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v37,
            v23) )
      {
        v15 = *value == 0;
        v24 = "true";
        if ( v15 )
          v24 = "false";
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 2048;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x85u,
          "void __thiscall vostok::network_core::buffer_writer::w<unsigned int>(const unsigned int &,const char *const ,c"
          "onst int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%s(%s)",
          v24,
          expression);
      }
      v15 = (v42 & 0x800) == 0;
    }
    if ( !v15 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
        (int *)&v44);
  }
}


void __userpurge vostok::network_core::buffer_writer::w<float>(
        float *value@<eax>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::buffer_writer *this,
        const char *file,
        const char *line,
        const char *function,
        const char *expression)
{
  vostok::network_core::buffer_writer::serialization_operation_descriptor *v9; // eax
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v10; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // ecx
  bool has_passed_filters; // al
  bool v13; // al
  bool v14; // al
  bool v15; // al
  bool v16; // zf
  bool v17; // al
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  bool v22; // al
  bool v23; // al
  bool v24; // al
  const char *v25; // edi
  char player_id; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v28; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v30; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v32; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v33; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v34; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v36; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v37; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v38; // [esp+20h] [ebp-40h]
  const char *v39; // [esp+24h] [ebp-3Ch]
  unsigned __int8 v40; // [esp+24h] [ebp-3Ch]
  const char *v41; // [esp+28h] [ebp-38h]
  unsigned int v42; // [esp+2Ch] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v43; // [esp+34h] [ebp-2Ch] BYREF
  void *v44; // [esp+58h] [ebp-8h]
  __int16 v45; // [esp+68h] [ebp+8h]

  v45 = 0;
  if ( vostok::network_core::g_debug_hash_mismatches && vostok::network_core::g_debug_hash_mismatches_enabled )
  {
    v44 = vostok::memory::new_helper<vostok::network_core::buffer_writer::serialization_operation_descriptor>::call<vostok::memory::pthreads3_allocator>(
            &vostok::memory::g_mt_allocator,
            v39,
            v41,
            v42);
    if ( v44 )
    {
      player_id = this->player_id;
      v9 = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)type_info::name(
                                                                                        &float `RTTI Type Descriptor',
                                                                                        &__type_info_root_node);
      vostok::network_core::buffer_writer::serialization_operation_descriptor::serialization_operation_descriptor(
        v9,
        (int)v44,
        expression,
        function,
        file,
        line,
        4,
        player_id,
        v40);
    }
    else
    {
      v10 = 0;
    }
    vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v10,
      (int)this);
  }
  vostok::network_core::buffer_writer::w(a2, this, (unsigned __int8 *)value, 4u);
  if ( vostok::network_core::g_debug_dump_serialization_info )
  {
    if ( type_info::operator==(&float `RTTI Type Descriptor', &vostok::math::float4x4 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"net_hash",
                                   (const char *)2),
            v11 = v27,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 1;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x6Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *value,
          value[1],
          value[2],
          value[3],
          expression);
      }
      if ( (v45 & 1) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFE;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v13 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v28,
            v13) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 2;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x70u,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value[4],
          value[5],
          value[6],
          value[7],
          expression);
      }
      if ( (v45 & 2) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFD;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v29,
            v14) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 4;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x71u,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value[8],
          value[9],
          value[10],
          value[11],
          expression);
      }
      if ( (v45 & 4) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFB;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v15 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v30,
            v15) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 8;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x72u,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value[12],
          value[13],
          value[14],
          value[15],
          expression);
      }
      v16 = (v45 & 8) == 0;
    }
    else if ( type_info::operator==(&float `RTTI Type Descriptor', &float `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v17 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v31,
            v17) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 16;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x75u,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "%.8g(%s)",
          *value,
          expression);
      }
      v16 = (v45 & 0x10) == 0;
    }
    else if ( type_info::operator==(&float `RTTI Type Descriptor', &vostok::math::float2 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v32,
            v18) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 32;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x78u,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g](%s)",
          *value,
          value[1],
          expression);
      }
      v16 = (v45 & 0x20) == 0;
    }
    else if ( type_info::operator==(&float `RTTI Type Descriptor', &vostok::math::float3 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v19 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v33,
            v19) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 64;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Bu,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g](%s)",
          *value,
          value[1],
          value[2],
          expression);
      }
      v16 = (v45 & 0x40) == 0;
    }
    else if ( type_info::operator==(&float `RTTI Type Descriptor', &unsigned __int64 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v20 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v34,
            v20) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 0x80;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Du,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "%I64d(%s)",
          *(_QWORD *)value,
          expression);
      }
      v16 = (v45 & 0x80u) == 0;
    }
    else if ( type_info::operator==(&float `RTTI Type Descriptor', &unsigned int `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v21 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v35,
            v21) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 256;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(_DWORD *)value,
          expression);
      }
      v16 = (v45 & 0x100) == 0;
    }
    else if ( type_info::operator==(&float `RTTI Type Descriptor', &unsigned short `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v36,
            v22) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 512;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x81u,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(unsigned __int16 *)value,
          expression);
      }
      v16 = (v45 & 0x200) == 0;
    }
    else if ( type_info::operator==(&float `RTTI Type Descriptor', &unsigned char `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v23 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v37,
            v23) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 1024;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x83u,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(unsigned __int8 *)value,
          expression);
      }
      v16 = (v45 & 0x400) == 0;
    }
    else
    {
      if ( !type_info::operator==(&float `RTTI Type Descriptor', &bool `RTTI Type Descriptor') )
        return;
      if ( !vostok::core::g_log_filter_tree
        || (v24 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v38,
            v24) )
      {
        v16 = *(_BYTE *)value == 0;
        v25 = "true";
        if ( v16 )
          v25 = "false";
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 2048;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x85u,
          "void __thiscall vostok::network_core::buffer_writer::w<float>(const float &,const char *const ,const int,const"
          " char *const ,const char *const ) const",
          "net_hash",
          error,
          "%s(%s)",
          v25,
          expression);
      }
      v16 = (v45 & 0x800) == 0;
    }
    if ( !v16 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
        (int *)&v43);
  }
}


void __userpurge vostok::network_core::buffer_writer::w<vostok::math::float2>(
        vostok::math::float2 *value@<eax>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::buffer_writer *this,
        const char *file,
        const char *line,
        const char *function,
        const char *expression)
{
  vostok::network_core::buffer_writer::serialization_operation_descriptor *v9; // eax
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v10; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // ecx
  bool has_passed_filters; // al
  bool v13; // al
  bool v14; // al
  bool v15; // al
  bool v16; // zf
  bool v17; // al
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  bool v22; // al
  bool v23; // al
  bool v24; // al
  const char *v25; // edi
  char player_id; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v28; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v30; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v32; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v33; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v34; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v36; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v37; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v38; // [esp+20h] [ebp-40h]
  const char *v39; // [esp+24h] [ebp-3Ch]
  unsigned __int8 v40; // [esp+24h] [ebp-3Ch]
  const char *v41; // [esp+28h] [ebp-38h]
  unsigned int v42; // [esp+2Ch] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v43; // [esp+34h] [ebp-2Ch] BYREF
  void *v44; // [esp+58h] [ebp-8h]
  __int16 v45; // [esp+68h] [ebp+8h]

  v45 = 0;
  if ( vostok::network_core::g_debug_hash_mismatches && vostok::network_core::g_debug_hash_mismatches_enabled )
  {
    v44 = vostok::memory::new_helper<vostok::network_core::buffer_writer::serialization_operation_descriptor>::call<vostok::memory::pthreads3_allocator>(
            &vostok::memory::g_mt_allocator,
            v39,
            v41,
            v42);
    if ( v44 )
    {
      player_id = this->player_id;
      v9 = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)type_info::name(
                                                                                        &vostok::math::float2 `RTTI Type Descriptor',
                                                                                        &__type_info_root_node);
      vostok::network_core::buffer_writer::serialization_operation_descriptor::serialization_operation_descriptor(
        v9,
        (int)v44,
        expression,
        function,
        file,
        line,
        8,
        player_id,
        v40);
    }
    else
    {
      v10 = 0;
    }
    vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v10,
      (int)this);
  }
  vostok::network_core::buffer_writer::w(a2, this, (unsigned __int8 *)value, 8u);
  if ( vostok::network_core::g_debug_dump_serialization_info )
  {
    if ( type_info::operator==(
           &vostok::math::float2 `RTTI Type Descriptor',
           &vostok::math::float4x4 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"net_hash",
                                   (const char *)2),
            v11 = v27,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 1;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x6Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value->x,
          value->y,
          value[1].x,
          value[1].y,
          expression);
      }
      if ( (v45 & 1) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFE;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v13 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v28,
            v13) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 2;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x70u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value[2].x,
          value[2].y,
          value[3].x,
          value[3].y,
          expression);
      }
      if ( (v45 & 2) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFD;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v29,
            v14) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 4;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x71u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value[4].x,
          value[4].y,
          value[5].x,
          value[5].y,
          expression);
      }
      if ( (v45 & 4) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFB;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v15 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v30,
            v15) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 8;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x72u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value[6].x,
          value[6].y,
          value[7].x,
          value[7].y,
          expression);
      }
      v16 = (v45 & 8) == 0;
    }
    else if ( type_info::operator==(&vostok::math::float2 `RTTI Type Descriptor', &float `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v17 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v31,
            v17) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 16;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x75u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%.8g(%s)",
          value->x,
          expression);
      }
      v16 = (v45 & 0x10) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float2 `RTTI Type Descriptor',
                &vostok::math::float2 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v32,
            v18) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 32;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x78u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g](%s)",
          value->x,
          value->y,
          expression);
      }
      v16 = (v45 & 0x20) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float2 `RTTI Type Descriptor',
                &vostok::math::float3 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v19 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v33,
            v19) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 64;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Bu,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g](%s)",
          value->x,
          value->y,
          value[1].x,
          expression);
      }
      v16 = (v45 & 0x40) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float2 `RTTI Type Descriptor',
                &unsigned __int64 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v20 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v34,
            v20) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 0x80;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Du,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%I64d(%s)",
          *value,
          expression);
      }
      v16 = (v45 & 0x80u) == 0;
    }
    else if ( type_info::operator==(&vostok::math::float2 `RTTI Type Descriptor', &unsigned int `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v21 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v35,
            v21) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 256;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          value->x,
          expression);
      }
      v16 = (v45 & 0x100) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float2 `RTTI Type Descriptor',
                &unsigned short `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v36,
            v22) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 512;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x81u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          LOWORD(value->x),
          expression);
      }
      v16 = (v45 & 0x200) == 0;
    }
    else if ( type_info::operator==(&vostok::math::float2 `RTTI Type Descriptor', &unsigned char `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v23 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v37,
            v23) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 1024;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x83u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          LOBYTE(value->x),
          expression);
      }
      v16 = (v45 & 0x400) == 0;
    }
    else
    {
      if ( !type_info::operator==(&vostok::math::float2 `RTTI Type Descriptor', &bool `RTTI Type Descriptor') )
        return;
      if ( !vostok::core::g_log_filter_tree
        || (v24 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v38,
            v24) )
      {
        v16 = LOBYTE(value->x) == 0;
        v25 = "true";
        if ( v16 )
          v25 = "false";
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 2048;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x85u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float2>(const class vostok::math::f"
          "loat2 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%s(%s)",
          v25,
          expression);
      }
      v16 = (v45 & 0x800) == 0;
    }
    if ( !v16 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
        (int *)&v43);
  }
}


void __userpurge vostok::network_core::buffer_writer::w<vostok::math::float3>(
        vostok::math::float3 *value@<eax>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::buffer_writer *this,
        const char *file,
        const char *line,
        const char *function,
        const char *expression)
{
  vostok::network_core::buffer_writer::serialization_operation_descriptor *v9; // eax
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v10; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // ecx
  bool has_passed_filters; // al
  bool v13; // al
  bool v14; // al
  bool v15; // al
  bool v16; // zf
  bool v17; // al
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  bool v22; // al
  bool v23; // al
  bool v24; // al
  const char *v25; // edi
  char player_id; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v28; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v30; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v32; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v33; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v34; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v36; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v37; // [esp+20h] [ebp-40h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v38; // [esp+20h] [ebp-40h]
  const char *v39; // [esp+24h] [ebp-3Ch]
  unsigned __int8 v40; // [esp+24h] [ebp-3Ch]
  const char *v41; // [esp+28h] [ebp-38h]
  unsigned int v42; // [esp+2Ch] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v43; // [esp+34h] [ebp-2Ch] BYREF
  void *v44; // [esp+58h] [ebp-8h]
  __int16 v45; // [esp+68h] [ebp+8h]

  v45 = 0;
  if ( vostok::network_core::g_debug_hash_mismatches && vostok::network_core::g_debug_hash_mismatches_enabled )
  {
    v44 = vostok::memory::new_helper<vostok::network_core::buffer_writer::serialization_operation_descriptor>::call<vostok::memory::pthreads3_allocator>(
            &vostok::memory::g_mt_allocator,
            v39,
            v41,
            v42);
    if ( v44 )
    {
      player_id = this->player_id;
      v9 = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)type_info::name(
                                                                                        &vostok::math::float3 `RTTI Type Descriptor',
                                                                                        &__type_info_root_node);
      vostok::network_core::buffer_writer::serialization_operation_descriptor::serialization_operation_descriptor(
        v9,
        (int)v44,
        expression,
        function,
        file,
        line,
        12,
        player_id,
        v40);
    }
    else
    {
      v10 = 0;
    }
    vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v10,
      (int)this);
  }
  vostok::network_core::buffer_writer::w(a2, this, (unsigned __int8 *)value, 0xCu);
  if ( vostok::network_core::g_debug_dump_serialization_info )
  {
    if ( type_info::operator==(
           &vostok::math::float3 `RTTI Type Descriptor',
           &vostok::math::float4x4 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"net_hash",
                                   (const char *)2),
            v11 = v27,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 1;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x6Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value->x,
          value->y,
          value->z,
          value[1].x,
          expression);
      }
      if ( (v45 & 1) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFE;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v13 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v28,
            v13) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 2;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x70u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value[1].y,
          value[1].z,
          value[2].x,
          value[2].y,
          expression);
      }
      if ( (v45 & 2) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFD;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v29,
            v14) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 4;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x71u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value[2].z,
          value[3].x,
          value[3].y,
          value[3].z,
          expression);
      }
      if ( (v45 & 4) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFB;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v15 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v30,
            v15) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 8;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x72u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value[4].x,
          value[4].y,
          value[4].z,
          value[5].x,
          expression);
      }
      v16 = (v45 & 8) == 0;
    }
    else if ( type_info::operator==(&vostok::math::float3 `RTTI Type Descriptor', &float `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v17 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v31,
            v17) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 16;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x75u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%.8g(%s)",
          value->x,
          expression);
      }
      v16 = (v45 & 0x10) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float3 `RTTI Type Descriptor',
                &vostok::math::float2 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v32,
            v18) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 32;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x78u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g](%s)",
          value->x,
          value->y,
          expression);
      }
      v16 = (v45 & 0x20) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float3 `RTTI Type Descriptor',
                &vostok::math::float3 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v19 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v33,
            v19) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 64;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Bu,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g](%s)",
          value->x,
          value->y,
          value->z,
          expression);
      }
      v16 = (v45 & 0x40) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float3 `RTTI Type Descriptor',
                &unsigned __int64 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v20 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v34,
            v20) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 0x80;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Du,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%I64d(%s)",
          *(_QWORD *)&value->x,
          expression);
      }
      v16 = (v45 & 0x80u) == 0;
    }
    else if ( type_info::operator==(&vostok::math::float3 `RTTI Type Descriptor', &unsigned int `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v21 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v35,
            v21) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 256;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          value->x,
          expression);
      }
      v16 = (v45 & 0x100) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float3 `RTTI Type Descriptor',
                &unsigned short `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v36,
            v22) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 512;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x81u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          LOWORD(value->x),
          expression);
      }
      v16 = (v45 & 0x200) == 0;
    }
    else if ( type_info::operator==(&vostok::math::float3 `RTTI Type Descriptor', &unsigned char `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v23 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v37,
            v23) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 1024;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x83u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          LOBYTE(value->x),
          expression);
      }
      v16 = (v45 & 0x400) == 0;
    }
    else
    {
      if ( !type_info::operator==(&vostok::math::float3 `RTTI Type Descriptor', &bool `RTTI Type Descriptor') )
        return;
      if ( !vostok::core::g_log_filter_tree
        || (v24 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v38,
            v24) )
      {
        v16 = LOBYTE(value->x) == 0;
        v25 = "true";
        if ( v16 )
          v25 = "false";
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 2048;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x85u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float3>(const class vostok::math::f"
          "loat3 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%s(%s)",
          v25,
          expression);
      }
      v16 = (v45 & 0x800) == 0;
    }
    if ( !v16 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
        (int *)&v43);
  }
}


void __userpurge vostok::network_core::buffer_writer::w<vostok::math::float4x4>(
        vostok::math::float4x4 *value@<eax>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::buffer_writer *this,
        const char *file,
        const char *line,
        const char *function,
        const char *const expression)
{
  vostok::network_core::buffer_writer::serialization_operation_descriptor *v9; // eax
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v10; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // ecx
  bool has_passed_filters; // al
  bool v13; // al
  bool v14; // al
  bool v15; // al
  bool v16; // zf
  bool v17; // al
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  bool v22; // al
  bool v23; // al
  bool v24; // al
  const char *v25; // edi
  char player_id; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v28; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v30; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v32; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v33; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v34; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v36; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v37; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v38; // [esp+20h] [ebp-3Ch]
  const char *v39; // [esp+24h] [ebp-38h]
  unsigned __int8 v40; // [esp+24h] [ebp-38h]
  const char *v41; // [esp+28h] [ebp-34h]
  unsigned int v42; // [esp+2Ch] [ebp-30h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v43; // [esp+34h] [ebp-28h] BYREF
  void *v44; // [esp+58h] [ebp-4h]
  __int16 v45; // [esp+64h] [ebp+8h]

  v45 = 0;
  if ( vostok::network_core::g_debug_hash_mismatches && vostok::network_core::g_debug_hash_mismatches_enabled )
  {
    v44 = vostok::memory::new_helper<vostok::network_core::buffer_writer::serialization_operation_descriptor>::call<vostok::memory::pthreads3_allocator>(
            &vostok::memory::g_mt_allocator,
            v39,
            v41,
            v42);
    if ( v44 )
    {
      player_id = this->player_id;
      v9 = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)type_info::name(
                                                                                        &vostok::math::float4x4 `RTTI Type Descriptor',
                                                                                        &__type_info_root_node);
      vostok::network_core::buffer_writer::serialization_operation_descriptor::serialization_operation_descriptor(
        v9,
        (int)v44,
        "m_transform",
        function,
        file,
        line,
        64,
        player_id,
        v40);
    }
    else
    {
      v10 = 0;
    }
    vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v10,
      (int)this);
  }
  vostok::network_core::buffer_writer::w(a2, this, (unsigned __int8 *)value, 0x40u);
  if ( vostok::network_core::g_debug_dump_serialization_info )
  {
    if ( type_info::operator==(
           &vostok::math::float4x4 `RTTI Type Descriptor',
           &vostok::math::float4x4 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"net_hash",
                                   (const char *)2),
            v11 = v27,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 1;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x6Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value->i.x,
          value->i.y,
          value->i.z,
          value->i.w,
          "m_transform");
      }
      if ( (v45 & 1) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFE;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v13 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v28,
            v13) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 2;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x70u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value->j.x,
          value->j.y,
          value->j.z,
          value->j.w,
          "m_transform");
      }
      if ( (v45 & 2) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFD;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v29,
            v14) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 4;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x71u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value->k.x,
          value->k.y,
          value->k.z,
          value->k.w,
          "m_transform");
      }
      if ( (v45 & 4) != 0 )
      {
        LOBYTE(v45) = v45 & 0xFB;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
          (int *)&v43);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v15 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v30,
            v15) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = v45 | 8;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x72u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          value->c.x,
          value->c.y,
          value->c.z,
          value->c.w,
          "m_transform");
      }
      v16 = (v45 & 8) == 0;
    }
    else if ( type_info::operator==(&vostok::math::float4x4 `RTTI Type Descriptor', &float `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v17 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v31,
            v17) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 16;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x75u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%.8g(%s)",
          value->i.x,
          "m_transform");
      }
      v16 = (v45 & 0x10) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float4x4 `RTTI Type Descriptor',
                &vostok::math::float2 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v32,
            v18) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 32;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x78u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g](%s)",
          value->i.x,
          value->i.y,
          "m_transform");
      }
      v16 = (v45 & 0x20) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float4x4 `RTTI Type Descriptor',
                &vostok::math::float3 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v19 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v33,
            v19) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 64;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Bu,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g](%s)",
          value->i.x,
          value->i.y,
          value->i.z,
          "m_transform");
      }
      v16 = (v45 & 0x40) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float4x4 `RTTI Type Descriptor',
                &unsigned __int64 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v20 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v34,
            v20) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        LOBYTE(v45) = 0x80;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Du,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%I64d(%s)",
          *(_QWORD *)&value->i.x,
          "m_transform");
      }
      v16 = (v45 & 0x80u) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float4x4 `RTTI Type Descriptor',
                &unsigned int `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v21 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v35,
            v21) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 256;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          value->i.x,
          "m_transform");
      }
      v16 = (v45 & 0x100) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float4x4 `RTTI Type Descriptor',
                &unsigned short `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v36,
            v22) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 512;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x81u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          LOWORD(value->i.x),
          "m_transform");
      }
      v16 = (v45 & 0x200) == 0;
    }
    else if ( type_info::operator==(
                &vostok::math::float4x4 `RTTI Type Descriptor',
                &unsigned char `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v23 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v37,
            v23) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 1024;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x83u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          LOBYTE(value->i.x),
          "m_transform");
      }
      v16 = (v45 & 0x400) == 0;
    }
    else
    {
      if ( !type_info::operator==(&vostok::math::float4x4 `RTTI Type Descriptor', &bool `RTTI Type Descriptor') )
        return;
      if ( !vostok::core::g_log_filter_tree
        || (v24 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v11 = v38,
            v24) )
      {
        v16 = LOBYTE(value->i.x) == 0;
        v25 = "true";
        if ( v16 )
          v25 = "false";
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v11,
          &v43);
        v45 = 2048;
        vostok::logging::append(
          &v43,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x85u,
          "void __thiscall vostok::network_core::buffer_writer::w<class vostok::math::float4x4>(const class vostok::math:"
          ":float4x4 &,const char *const ,const int,const char *const ,const char *const ) const",
          "net_hash",
          error,
          "%s(%s)",
          v25,
          "m_transform");
      }
      v16 = (v45 & 0x800) == 0;
    }
    if ( !v16 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v11,
        (int *)&v43);
  }
}


void __userpurge vostok::network_core::buffer_writer::w<bool>(
        const bool *value@<eax>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::buffer_writer *this)
{
  unsigned __int8 v3; // [esp+1h] [ebp-1h] BYREF

  v3 = HIBYTE(a2);
  v3 = !*value - 1;
  vostok::network_core::buffer_writer::w(a2, this, &v3, 1u);
}


void __userpurge vostok::network_core::buffer_writer::w<bool>(
        const bool *value@<eax>,
        vostok::network_core::buffer_writer *a2@<ecx>,
        vostok::network_core::buffer_writer *this,
        const char *file,
        const char *line,
        const char *function,
        const char *expression)
{
  vostok::network_core::buffer_writer::serialization_operation_descriptor *v8; // eax
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v9; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool has_passed_filters; // al
  bool v12; // al
  bool v13; // al
  bool v14; // al
  bool v15; // zf
  bool v16; // al
  bool v17; // al
  bool v18; // al
  bool v19; // al
  bool v20; // al
  bool v21; // al
  bool v22; // al
  bool v23; // al
  const char *v24; // edi
  char player_id; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v26; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v27; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v28; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v29; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v30; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v31; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v32; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v33; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v34; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v35; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v36; // [esp+20h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v37; // [esp+20h] [ebp-3Ch]
  const char *v38; // [esp+24h] [ebp-38h]
  unsigned __int8 v39; // [esp+24h] [ebp-38h]
  const char *v40; // [esp+28h] [ebp-34h]
  unsigned int v41; // [esp+2Ch] [ebp-30h]
  __int16 v42; // [esp+34h] [ebp-28h]
  void *v43; // [esp+38h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v44; // [esp+3Ch] [ebp-20h] BYREF

  v42 = 0;
  if ( vostok::network_core::g_debug_hash_mismatches && vostok::network_core::g_debug_hash_mismatches_enabled )
  {
    v43 = vostok::memory::new_helper<vostok::network_core::buffer_writer::serialization_operation_descriptor>::call<vostok::memory::pthreads3_allocator>(
            &vostok::memory::g_mt_allocator,
            v38,
            v40,
            v41);
    if ( v43 )
    {
      player_id = this->player_id;
      v8 = (vostok::network_core::buffer_writer::serialization_operation_descriptor *)type_info::name(
                                                                                        &bool `RTTI Type Descriptor',
                                                                                        &__type_info_root_node);
      vostok::network_core::buffer_writer::serialization_operation_descriptor::serialization_operation_descriptor(
        v8,
        (int)v43,
        expression,
        function,
        file,
        line,
        1,
        player_id,
        v39);
    }
    else
    {
      v9 = 0;
    }
    vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v9,
      (int)this);
  }
  vostok::network_core::buffer_writer::w<bool>(value, a2, this);
  if ( vostok::network_core::g_debug_dump_serialization_info )
  {
    if ( type_info::operator==(&bool `RTTI Type Descriptor', &vostok::math::float4x4 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"net_hash",
                                   (const char *)2),
            v10 = v26,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 1;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x6Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          *((float *)value + 2),
          *((float *)value + 3),
          expression);
      }
      if ( (v42 & 1) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFE;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v12 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v27,
            v12) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 2;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x70u,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 4),
          *((float *)value + 5),
          *((float *)value + 6),
          *((float *)value + 7),
          expression);
      }
      if ( (v42 & 2) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFD;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v13 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v28,
            v13) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 4;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x71u,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 8),
          *((float *)value + 9),
          *((float *)value + 10),
          *((float *)value + 11),
          expression);
      }
      if ( (v42 & 4) != 0 )
      {
        LOBYTE(v42) = v42 & 0xFB;
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
          (int *)&v44);
      }
      if ( !vostok::core::g_log_filter_tree
        || (v14 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v29,
            v14) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = v42 | 8;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x72u,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g][%.8g](%s)",
          *((float *)value + 12),
          *((float *)value + 13),
          *((float *)value + 14),
          *((float *)value + 15),
          expression);
      }
      v15 = (v42 & 8) == 0;
    }
    else if ( type_info::operator==(&bool `RTTI Type Descriptor', &float `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v16 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v30,
            v16) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 16;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x75u,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "%.8g(%s)",
          *(float *)value,
          expression);
      }
      v15 = (v42 & 0x10) == 0;
    }
    else if ( type_info::operator==(&bool `RTTI Type Descriptor', &vostok::math::float2 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v17 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v31,
            v17) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 32;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x78u,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          expression);
      }
      v15 = (v42 & 0x20) == 0;
    }
    else if ( type_info::operator==(&bool `RTTI Type Descriptor', &vostok::math::float3 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v18 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v32,
            v18) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 64;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Bu,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "[%.8g][%.8g][%.8g](%s)",
          *(float *)value,
          *((float *)value + 1),
          *((float *)value + 2),
          expression);
      }
      v15 = (v42 & 0x40) == 0;
    }
    else if ( type_info::operator==(&bool `RTTI Type Descriptor', &unsigned __int64 `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v19 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v33,
            v19) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        LOBYTE(v42) = 0x80;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Du,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "%I64d(%s)",
          *(_QWORD *)value,
          expression);
      }
      v15 = (v42 & 0x80u) == 0;
    }
    else if ( type_info::operator==(&bool `RTTI Type Descriptor', &unsigned int `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v20 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v34,
            v20) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 256;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x7Fu,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(_DWORD *)value,
          expression);
      }
      v15 = (v42 & 0x100) == 0;
    }
    else if ( type_info::operator==(&bool `RTTI Type Descriptor', &unsigned short `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v21 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v35,
            v21) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 512;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x81u,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(unsigned __int16 *)value,
          expression);
      }
      v15 = (v42 & 0x200) == 0;
    }
    else if ( type_info::operator==(&bool `RTTI Type Descriptor', &unsigned char `RTTI Type Descriptor') )
    {
      if ( !vostok::core::g_log_filter_tree
        || (v22 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v36,
            v22) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 1024;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x83u,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "%d(%s)",
          *(unsigned __int8 *)value,
          expression);
      }
      v15 = (v42 & 0x400) == 0;
    }
    else
    {
      if ( !type_info::operator==(&bool `RTTI Type Descriptor', &bool `RTTI Type Descriptor') )
        return;
      if ( !vostok::core::g_log_filter_tree
        || (v23 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"net_hash", (const char *)2),
            v10 = v37,
            v23) )
      {
        v15 = !*value;
        v24 = "true";
        if ( v15 )
          v24 = "false";
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v10,
          &v44);
        v42 = 2048;
        vostok::logging::append(
          &v44,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          "c:\\survarium.deploy\\sources\\vostok/network_core/buffer_writer.h",
          0x85u,
          "void __thiscall vostok::network_core::buffer_writer::w<bool>(const bool &,const char *const ,const int,const c"
          "har *const ,const char *const ) const",
          "net_hash",
          error,
          "%s(%s)",
          v24,
          expression);
      }
      v15 = (v42 & 0x800) == 0;
    }
    if ( !v15 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
        (int *)&v44);
  }
}
