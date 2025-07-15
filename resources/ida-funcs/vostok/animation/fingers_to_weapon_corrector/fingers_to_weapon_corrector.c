void __usercall vostok::animation::fingers_to_weapon_corrector::fingers_to_weapon_corrector(
        vostok::animation::fingers_to_weapon_corrector *this@<ecx>,
        int a2@<esi>)
{
  vostok::animation::fingers_to_weapon_corrector::hand *v2; // edi
  int i; // ebx

  v2 = (vostok::animation::fingers_to_weapon_corrector::hand *)a2;
  for ( i = 1; i >= 0; --i )
    vostok::animation::fingers_to_weapon_corrector::hand::hand(v2++);
  *(_DWORD *)(a2 + 5912) = &vostok::animation::linear_interpolator::`vftable';
  *(float *)(a2 + 5916) = s_aim_transition_time;
  *(_DWORD *)(a2 + 5920) = 0;
  *(_BYTE *)(a2 + 5924) = 0;
}
