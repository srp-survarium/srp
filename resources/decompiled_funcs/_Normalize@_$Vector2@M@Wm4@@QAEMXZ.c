double __usercall Wm4::Vector2<float>::Normalize@<st0>(Wm4::Vector2<float> *this@<ecx>, float *a2@<esi>)
{
  double result; // st7
  float fInvLength; // [esp+0h] [ebp-4h]
  float fInvLengtha; // [esp+0h] [ebp-4h]
  float fInvLengthb; // [esp+0h] [ebp-4h]

  fInvLength = a2[1] * a2[1] + *a2 * *a2;
  fInvLengtha = sqrt(fInvLength);
  result = fInvLengtha;
  if ( fInvLengtha <= 0.000001 )
  {
    *a2 = 0.0;
    a2[1] = 0.0;
    return (float)0.0;
  }
  else
  {
    fInvLengthb = 1.0 / result;
    *a2 = *a2 * fInvLengthb;
    a2[1] = fInvLengthb * a2[1];
  }
  return result;
}
