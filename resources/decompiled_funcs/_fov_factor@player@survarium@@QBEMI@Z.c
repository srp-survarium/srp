float __usercall survarium::player::fov_factor@<xmm0>(
        survarium::player *this@<esi>,
        const unsigned int current_time_in_ms@<eax>)
{
  double v2; // st7
  float v3; // xmm0_4
  float current_transition_time; // [esp+0h] [ebp-10h]
  float time[3]; // [esp+4h] [ebp-Ch] BYREF

  time[0] = 0.0;
  LODWORD(time[0]) = current_time_in_ms - *(int *)((char *)&dword_10F28 + (_DWORD)this);
  v2 = (double)LODWORD(time[0]) * 0.001;
  v3 = *(float *)((char *)&dword_10F24 + (_DWORD)this);
  time[0] = v2;
  if ( time[0] >= v3 )
    return *(float *)((char *)&dword_10F18 + (_DWORD)this);
  current_transition_time = v2;
  LODWORD(time[0]) = &vostok::animation::linear_interpolator::`vftable';
  time[1] = v3;
  time[0] = vostok::animation::linear_interpolator::`vftable'(
              (vostok::animation::linear_interpolator *)time,
              current_transition_time);
  return (float)((float)(*(float *)((char *)&dword_10F18 + (_DWORD)this)
                       - *(float *)((char *)&dword_10F1C + (_DWORD)this))
               * time[0])
       + *(float *)((char *)&dword_10F1C + (_DWORD)this);
}
