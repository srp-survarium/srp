void __thiscall survarium::scheduler::on_frame(
        survarium::scheduler *this,
        survarium::scheduler::record *record,
        unsigned int frame_delta,
        unsigned int current_time)
{
  survarium::game_camera *v4; // ecx
  survarium::scheduler::identifier *v5; // ecx
  float value; // [esp+0h] [ebp-2C8h]
  int i; // [esp+28Ch] [ebp-3Ch]
  boost::function<void __cdecl(unsigned int,unsigned int)> callback; // [esp+290h] [ebp-38h] BYREF
  unsigned int update_delta; // [esp+2B4h] [ebp-14h]
  unsigned int time_delta; // [esp+2B8h] [ebp-10h]
  unsigned int last_update_time; // [esp+2BCh] [ebp-Ch]
  int count; // [esp+2C0h] [ebp-8h]
  survarium::scheduler::identifier *id; // [esp+2C4h] [ebp-4h]

  last_update_time = record->m_last_update_time;
  if ( current_time > last_update_time )
  {
    if ( *(_DWORD *)&record->survarium::scheduler::scheduler_record < 0 )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(*(_DWORD *)&record->survarium::scheduler::scheduler_record >> 31));
      update_delta = *(_DWORD *)&record->survarium::scheduler::scheduler_record & 0x7FFFFFFF;
      if ( current_time >= update_delta + last_update_time )
      {
        time_delta = current_time - last_update_time;
        value = (double)(current_time - last_update_time) / (double)update_delta;
        count = vostok::math::floor(value);
        record->m_last_update_time += update_delta * count;
        count = vostok::math::min(count, record->m_max_update_count);
        survarium::weapon_user_dead_state::finalize(v4);
        id = record->m_id;
        boost::function<void __cdecl (unsigned int,float,float,char const *)>::function<void __cdecl (unsigned int,float,float,char const *)>((boost::function<void __cdecl(unsigned int,float,float,char const *)> *)&record->m_callback);
        for ( i = 0; i < count; ++i )
        {
          v5 = id;
          if ( *(_DWORD *)id >= 0 )
            break;
          boost::function2<void,unsigned int,unsigned int>::operator()(&callback, update_delta, current_time);
        }
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v5,
          (int *)&callback);
      }
    }
    else
    {
      record->m_last_update_time = current_time;
      boost::function2<void,unsigned int,unsigned int>::operator()(&record->m_callback, frame_delta, current_time);
    }
  }
}
