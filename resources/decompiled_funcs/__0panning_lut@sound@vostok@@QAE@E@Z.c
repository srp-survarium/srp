void __thiscall vostok::sound::panning_lut::panning_lut(vostok::sound::panning_lut *this, unsigned __int8 channels_num)
{
  long double v2; // [esp+0h] [ebp-7Ch]
  long double var7Ca; // [esp+0h] [ebp-7Ch]
  long double var7Cb; // [esp+0h] [ebp-7Ch]
  float v5; // [esp+18h] [ebp-64h]
  float alpha; // [esp+1Ch] [ebp-60h]
  unsigned int i; // [esp+20h] [ebp-5Ch]
  float theta; // [esp+24h] [ebp-58h]
  unsigned int offset; // [esp+28h] [ebp-54h]
  unsigned __int8 s; // [esp+2Fh] [ebp-4Dh]
  unsigned int pos; // [esp+30h] [ebp-4Ch]
  float speaker_angle[9]; // [esp+34h] [ebp-48h]
  vostok::sound::speakers speaker_to_channel[9]; // [esp+58h] [ebp-24h]

  HIDWORD(v2) = this;
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  *(_DWORD *)HIDWORD(v2) = &vostok::sound::panning_lut::`vftable';
  LOBYTE(v2) = channels_num;
  if ( channels_num == 2 )
  {
    speaker_to_channel[0] = front_left;
    speaker_to_channel[1] = front_right;
    speaker_angle[0] = (float)(-90.0 * 3.1415927) / 180.0;
    speaker_angle[1] = (float)(90.0 * 3.1415927) / 180.0;
  }
  else
  {
    speaker_to_channel[0] = front_center;
    speaker_angle[0] = (float)(0.0 * 3.1415927) / 180.0;
  }
  for ( pos = 0; pos < 0x200; ++pos )
  {
    offset = 9 * pos;
    for ( i = 0; i < 9; ++i )
      *(_DWORD *)(HIDWORD(v2) + 4 * (i + offset) + 264) = *(_DWORD *)&FLOAT_0_0;
    if ( channels_num == 1 )
    {
      *(float *)(HIDWORD(v2) + 4 * (speaker_to_channel[0] + offset) + 264) = FLOAT_1_0;
    }
    else
    {
      theta = vostok::sound::pos_to_angle(pos);
      for ( s = 0; s < channels_num - 1; ++s )
      {
        if ( theta >= speaker_angle[s] && speaker_angle[s + 1] > theta )
        {
          alpha = (float)((float)(theta - speaker_angle[s]) * 1.5707964)
                / (float)(speaker_angle[s + 1] - speaker_angle[s]);
          __libm_sse2_cos(v2);
          *(float *)(HIDWORD(var7Ca) + 4 * (speaker_to_channel[s] + offset) + 264) = alpha;
          __libm_sse2_sin(var7Ca);
          *(float *)(HIDWORD(v2) + 4 * (speaker_to_channel[s + 1] + offset) + 264) = alpha;
          break;
        }
      }
      if ( s == channels_num - 1 )
      {
        if ( speaker_angle[0] > theta )
          theta = (float)(2.0 * 3.1415927) + theta;
        v5 = (float)((float)(theta - speaker_angle[s]) * 1.5707964)
           / (float)((float)((float)(2.0 * 3.1415927) + speaker_angle[0]) - speaker_angle[s]);
        __libm_sse2_cos(v2);
        *(float *)(HIDWORD(var7Cb) + 4 * (speaker_to_channel[s] + offset) + 264) = v5;
        __libm_sse2_sin(var7Cb);
        *(float *)(HIDWORD(v2) + 4 * (speaker_to_channel[0] + offset) + 264) = v5;
      }
    }
  }
}
