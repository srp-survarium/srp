// local variable allocation has failed, the output may be wrong!
void __cdecl vostok::physics::set_max_slope_angle(char *args)
{
  float v1; // xmm0_4
  long double var4; // [esp+0h] [ebp-4h] OVERLAPPED BYREF

  LODWORD(var4) = 0;
  if ( sscanf_s(args, "%f", &var4) != -1 )
  {
    v1 = *(float *)&var4;
    if ( *(float *)&var4 <= 90.0 && *(float *)&var4 >= 0.0 )
    {
      __libm_sse2_cos(var4);
      vostok::physics::bullet_character_controller::ms_max_slope_normal_dot = v1 * 0.017453292;
    }
  }
}
