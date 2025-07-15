int __cdecl _XcptFilter(unsigned int xcptnum, _EXCEPTION_POINTERS *pxcptinfoptrs)
{
  int result; // eax
  _DWORD *v3; // esi
  int *v4; // edx
  int *v5; // ecx
  int *v6; // eax
  void (__cdecl *v7)(int); // ebx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  int v13; // [esp+4h] [ebp-8h]

  result = (int)_getptd_noexit();
  v3 = (_DWORD *)result;
  if ( result )
  {
    v4 = *(int **)(result + 92);
    v5 = v4;
    do
    {
      if ( *v5 == xcptnum )
        break;
      v5 += 3;
    }
    while ( v5 < &v4[3 * _XcptActTabCount] );
    if ( v5 < &v4[3 * _XcptActTabCount] && *v5 == xcptnum )
      v6 = v5;
    else
      v6 = 0;
    if ( v6 && (v7 = (void (__cdecl *)(int))v6[2]) != 0 )
    {
      if ( v7 == (void (__cdecl *)(int))5 )
      {
        v6[2] = 0;
        return 1;
      }
      else
      {
        if ( v7 != (void (__cdecl *)(int))1 )
        {
          v13 = v3[24];
          v3[24] = pxcptinfoptrs;
          v8 = v6[1];
          if ( v8 == 8 )
          {
            v9 = _First_FPE_Indx;
            if ( _First_FPE_Indx < _First_FPE_Indx + _Num_FPE )
            {
              v10 = 12 * _First_FPE_Indx;
              do
              {
                *(_DWORD *)(v10 + v3[23] + 8) = 0;
                ++v9;
                v10 += 12;
              }
              while ( v9 < _First_FPE_Indx + _Num_FPE );
            }
            v11 = *v6;
            v12 = v3[25];
            switch ( v11 )
            {
              case -1073741682:
                v3[25] = 131;
                break;
              case -1073741680:
                v3[25] = 129;
                break;
              case -1073741679:
                v3[25] = 132;
                break;
              case -1073741677:
                v3[25] = 133;
                break;
              case -1073741683:
                v3[25] = 130;
                break;
              case -1073741681:
                v3[25] = 134;
                break;
              case -1073741678:
                v3[25] = 138;
                break;
            }
            v7(8);
            v3[25] = v12;
          }
          else
          {
            v6[2] = 0;
            v7(v8);
          }
          v3[24] = v13;
        }
        return -1;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
