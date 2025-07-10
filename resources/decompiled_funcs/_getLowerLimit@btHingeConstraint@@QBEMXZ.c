float __usercall btHingeConstraint::getLowerLimit@<xmm0>(btHingeConstraint *this@<ecx>, int a2@<eax>, double a3@<st1>)
{
  float result; // xmm0_4
  float v4; // [esp+8h] [ebp-4h]

  fmodf(*(float *)(a2 + 760) - *(float *)(a2 + 764), 6.2831855);
  v4 = a3;
  result = v4;
  if ( a3 < -3.1415927 )
    return v4 + 6.2831855;
  if ( v4 > 3.1415927 )
    return v4 - 6.2831855;
  return result;
}
