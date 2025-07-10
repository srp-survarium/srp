int __usercall sub_372370@<eax>(unsigned int a1@<eax>, int a2@<ecx>, _BYTE *a3@<edi>, int *a4@<esi>)
{
  int v4; // ebx
  bool v5; // zf
  _DWORD *v6; // eax
  int result; // eax
  int v8; // ebx
  int v9; // ecx

  v4 = a1 + a2;
  if ( a1 >= 0xE && *a3 == 74 && a3[1] == 70 && a3[2] == 73 && a3[3] == 70 && !a3[4] )
  {
    *((_BYTE *)a4 + 256) = 1;
    *((_BYTE *)a4 + 257) = a3[5];
    *((_BYTE *)a4 + 258) = a3[6];
    *((_BYTE *)a4 + 259) = a3[7];
    *((_WORD *)a4 + 130) = (unsigned __int8)a3[9] + ((unsigned __int8)a3[8] << 8);
    v5 = *((_BYTE *)a4 + 257) == 1;
    *((_WORD *)a4 + 131) = (unsigned __int8)a3[11] + ((unsigned __int8)a3[10] << 8);
    if ( !v5 )
    {
      *(_DWORD *)(*a4 + 20) = 122;
      *(_DWORD *)(*a4 + 24) = *((unsigned __int8 *)a4 + 257);
      *(_DWORD *)(*a4 + 28) = *((unsigned __int8 *)a4 + 258);
      (*(void (__cdecl **)(int *, int))(*a4 + 4))(a4, -1);
    }
    v6 = (_DWORD *)(*a4 + 24);
    *v6 = *((unsigned __int8 *)a4 + 257);
    v6[1] = *((unsigned __int8 *)a4 + 258);
    v6[2] = *((unsigned __int16 *)a4 + 130);
    v6[3] = *((unsigned __int16 *)a4 + 131);
    v6[4] = *((unsigned __int8 *)a4 + 259);
    *(_DWORD *)(*a4 + 20) = 89;
    (*(void (__cdecl **)(int *, int))(*a4 + 4))(a4, 1);
    if ( *((_WORD *)a3 + 6) )
    {
      *(_DWORD *)(*a4 + 20) = 92;
      *(_DWORD *)(*a4 + 24) = (unsigned __int8)a3[12];
      *(_DWORD *)(*a4 + 28) = (unsigned __int8)a3[13];
      (*(void (__cdecl **)(int *, int))(*a4 + 4))(a4, 1);
    }
    result = (unsigned __int8)a3[13] * (unsigned __int8)a3[12];
    v8 = v4 - 14;
    if ( v8 != 3 * result )
    {
      *(_DWORD *)(*a4 + 20) = 90;
      *(_DWORD *)(*a4 + 24) = v8;
      return (*(int (__cdecl **)(int *, int))(*a4 + 4))(a4, 1);
    }
  }
  else if ( a1 >= 6 && *a3 == 74 && a3[1] == 70 && a3[2] == 88 && a3[3] == 88 && !a3[4] )
  {
    if ( a3[5] == 16 )
    {
      *(_DWORD *)(*a4 + 20) = 110;
      *(_DWORD *)(*a4 + 24) = v4;
      return (*(int (__cdecl **)(int *, int))(*a4 + 4))(a4, 1);
    }
    else if ( a3[5] == 17 )
    {
      *(_DWORD *)(*a4 + 20) = 111;
      *(_DWORD *)(*a4 + 24) = v4;
      return (*(int (__cdecl **)(int *, int))(*a4 + 4))(a4, 1);
    }
    else
    {
      v9 = *a4;
      if ( a3[5] == 19 )
      {
        *(_DWORD *)(v9 + 20) = 112;
        *(_DWORD *)(*a4 + 24) = v4;
      }
      else
      {
        *(_DWORD *)(v9 + 20) = 91;
        *(_DWORD *)(*a4 + 24) = (unsigned __int8)a3[5];
        *(_DWORD *)(*a4 + 28) = v4;
      }
      return (*(int (__cdecl **)(int *, int))(*a4 + 4))(a4, 1);
    }
  }
  else
  {
    *(_DWORD *)(*a4 + 20) = 79;
    *(_DWORD *)(*a4 + 24) = v4;
    return (*(int (__cdecl **)(int *, int))(*a4 + 4))(a4, 1);
  }
  return result;
}
