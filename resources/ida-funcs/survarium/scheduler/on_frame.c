void __userpurge survarium::scheduler::on_frame(
        survarium::scheduler *this@<ecx>,
        int a2@<eax>,
        vostok::math::float4x4 *record,
        survarium::scheduler::record *frame_delta,
        const unsigned int current_time)
{
  survarium::scheduler::record *M_start; // edi
  signed int m_current_index; // eax
  int v9; // eax
  signed int v10; // eax
  survarium::scheduler::record *v11; // ecx
  survarium::scheduler::record *v12; // edi
  boost::function2<void,vostok::math::float4x4 *,unsigned int> *v13; // ecx
  int i; // esi
  float v15; // [esp+0h] [ebp-34h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+14h] [ebp-20h] BYREF
  vostok::math::float4x4 *a0; // [esp+3Ch] [ebp+8h]
  unsigned int a1; // [esp+40h] [ebp+Ch]

  *(_DWORD *)(a2 + 44) = frame_delta;
  M_start = this[1].m_inactive_objects._M_impl._M_start;
  if ( frame_delta > M_start )
  {
    m_current_index = this->m_current_index;
    if ( m_current_index < 0 )
    {
      v9 = m_current_index & 0x7FFFFFFF;
      a1 = v9;
      if ( frame_delta >= (survarium::scheduler::record *)((char *)M_start + v9) )
      {
        v15 = (double)(unsigned int)((char *)frame_delta - (char *)M_start) / (double)(unsigned int)v9;
        v10 = vostok::math::floor(v15);
        v11 = (survarium::scheduler::record *)((char *)M_start + a1 * v10);
        v12 = this->m_inactive_objects._M_impl._M_start;
        this[1].m_inactive_objects._M_impl._M_start = v11;
        a0 = (vostok::math::float4x4 *)(this->m_last_tick_time_ms
                                      + (v10 < (signed int)this->m_last_tick_time_ms
                                       ? v10 - this->m_last_tick_time_ms
                                       : 0));
        boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
          (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&this->m_inactive_objects._M_impl._M_end_of_storage,
          &f);
        for ( i = 0; i < (int)a0; ++i )
        {
          if ( (int)v12->m_id >= 0 )
            break;
          boost::function1<void,boost::system::error_code>::operator()(
            v13,
            &f,
            (vostok::math::float4x4 *)a1,
            (unsigned int)frame_delta);
        }
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v13,
          (int *)&f);
      }
    }
    else
    {
      this[1].m_inactive_objects._M_impl._M_start = frame_delta;
      boost::function1<void,boost::system::error_code>::operator()(
        (boost::function2<void,vostok::math::float4x4 *,unsigned int> *)this,
        &this->m_inactive_objects._M_impl._M_end_of_storage.m_allocator,
        record,
        (unsigned int)frame_delta);
    }
  }
}


void __userpurge survarium::scheduler::on_frame(
        survarium::scheduler *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::math::float4x4 *frame_delta,
        survarium::scheduler::record *current_time)
{
  unsigned int savedregs; // [esp+0h] [ebp+0h]

  for ( a2[10] = 0; a2[10] < (unsigned int)((a2[5] - a2[4]) / 56); ++a2[10] )
    survarium::scheduler::on_frame(
      (survarium::scheduler *)(a2[4] + 56 * a2[10]),
      (int)a2,
      frame_delta,
      current_time,
      savedregs);
  a2[10] = -1;
}
