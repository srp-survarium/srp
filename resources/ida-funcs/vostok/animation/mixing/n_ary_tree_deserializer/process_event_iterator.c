void __thiscall vostok::animation::mixing::n_ary_tree_deserializer::process_event_iterator(
        vostok::animation::mixing::n_ary_tree_deserializer *this,
        vostok::animation::mixing::n_ary_tree_deserializer *event_iterator,
        __int32 a3)
{
  __int16 v3; // cx
  _DWORD *v4; // eax
  int v5; // ecx
  int v6; // eax
  __int32 v7; // edi
  float *m_end; // eax
  int v9; // xmm0_4
  char v10; // al

  v3 = vostok::animation::mixing::n_ary_tree_deserializer::r(event_iterator, 6u);
  v4 = (_DWORD *)a3;
  *(_WORD *)(a3 + 12) = 2 * v3;
  if ( (unsigned __int16)v4[3] )
  {
    v5 = *--event_iterator->m_times_in_ms.m_end;
    v4[2] = v5;
    v6 = vostok::animation::mixing::n_ary_tree_deserializer::r(event_iterator, 1u);
    v7 = a3;
    *(_DWORD *)a3 = v6;
    m_end = event_iterator->m_floats.m_end;
    v9 = *((_DWORD *)m_end - 1);
    _InterlockedExchange(&a3, (__int32)m_end);
    --event_iterator->m_floats.m_end;
    *(_DWORD *)(v7 + 4) = v9;
    *(_BYTE *)(v7 + 14) = vostok::animation::mixing::n_ary_tree_deserializer::r(event_iterator, 8u);
    v10 = vostok::animation::mixing::n_ary_tree_deserializer::r(event_iterator, 4u);
    if ( v10 == 15 )
      *(_BYTE *)(v7 + 15) = -1;
    else
      *(_BYTE *)(v7 + 15) = v10;
  }
  else
  {
    v4[2] = -1;
    v4[4] = 0;
  }
}


void __usercall vostok::animation::mixing::n_ary_tree_deserializer::process_event_iterator(
        vostok::animation::mixing::n_ary_tree_deserializer *this@<eax>,
        vostok::animation::mixing::n_ary_tree_weight_event_iterator *event_iterator@<edi>)
{
  vostok::animation::mixing::n_ary_tree_weight_event_iterator *v3; // ecx
  unsigned int v4; // eax
  vostok::animation::mixing::animation_event result; // [esp+4h] [ebp-10h] BYREF

  event_iterator->m_event_type = 0;
  event_iterator->m_event_type |= vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u) != 1 ? 0 : 256;
  event_iterator->m_event_type |= vostok::animation::mixing::n_ary_tree_deserializer::r(this, 1u) != 1 ? 0 : 2;
  if ( vostok::animation::mixing::n_ary_tree_weight_event_iterator::operator*(v3, &result)->event_type )
  {
    v4 = *--this->m_times_in_ms.m_end;
    event_iterator->m_time_in_ms = v4;
  }
  else
  {
    event_iterator->m_time_in_ms = -1;
    event_iterator->m_animation = 0;
  }
}
