_DWORD *__thiscall sub_3752F0(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // edx
  bool v3; // cf
  int v4; // ecx

  result = (_DWORD *)this[102];
  v2 = 1;
  if ( (int)this[74] <= 1 )
  {
    v3 = this[32] < (unsigned int)(this[72] - 1);
    v4 = this[75];
    if ( v3 )
    {
      result[7] = *(_DWORD *)(v4 + 12);
      result[5] = 0;
      result[6] = 0;
      return result;
    }
    v2 = *(_DWORD *)(v4 + 76);
  }
  result[7] = v2;
  result[5] = 0;
  result[6] = 0;
  return result;
}
