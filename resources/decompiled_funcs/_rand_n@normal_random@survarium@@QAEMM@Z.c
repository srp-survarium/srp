float __thiscall survarium::normal_random::rand_n(survarium::normal_random *this, float sigma)
{
  float v2; // xmm0_4
  double v3; // st7
  float v5; // [esp+4h] [ebp-24h]
  int v7; // [esp+14h] [ebp-14h]
  float value; // [esp+1Ch] [ebp-Ch] BYREF
  float c_one_over_sigma_exp; // [esp+20h] [ebp-8h]
  float y; // [esp+24h] [ebp-4h]

  c_one_over_sigma_exp = 1.2539185;
  if ( sigma == 0.0 )
  {
    __asm { fldz }
  }
  else
  {
    do
    {
      this->m_seed = (int)&loc_269EC3 + 214013 * this->m_seed;
      logf((float)((this->m_seed >> 16) & 0x7FFF) / 32767.0);
      __asm
      {
        fchs
        fstp    [ebp+y]
      }
      value = y - *(float *)&clear_value;
      this->m_seed = (int)&loc_269EC3 + 214013 * this->m_seed;
      v7 = (this->m_seed >> 16) & 0x7FFF;
      v2 = (float)-vostok::math::sqr<float>(&value) * 0.5;
      v3 = expf((float)v7 / 32767.0);
    }
    while ( v5 > v2 );
    this->m_seed = (int)&loc_269EC3 + 214013 * this->m_seed;
    if ( ((this->m_seed >> 16) & 1) != 0 )
    {
      __asm
      {
        fld     [ebp+y]
        fmul    [ebp+sigma]
        fmul    [ebp+c_one_over_sigma_exp]
      }
    }
    else
    {
      __asm
      {
        fld     [ebp+y]
        fchs
        fmul    [ebp+sigma]
        fmul    [ebp+c_one_over_sigma_exp]
      }
    }
  }
  return v3;
}
