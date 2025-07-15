void __userpurge vostok::animation::mixing::animation_event::animation_event(
        vostok::animation::mixing::animation_event *this@<ecx>,
        int a2@<eax>,
        __int16 event_time_in_ms,
        const unsigned __int16 event_type,
        const unsigned __int8 channel_ids)
{
  *(_DWORD *)a2 = -1;
  *(_DWORD *)(a2 + 8) = this;
  *(_DWORD *)(a2 + 4) = -33698355;
  *(_WORD *)(a2 + 12) = event_time_in_ms;
  *(_BYTE *)(a2 + 14) = 0;
  *(_BYTE *)(a2 + 15) = -1;
}
