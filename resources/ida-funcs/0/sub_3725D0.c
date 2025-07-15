int __usercall sub_3725D0@<eax>(_BYTE *a1@<eax>, unsigned int a2@<ecx>, _BYTE *a3@<esi>, int a4)
{
  int v4; // ebx
  int v5; // edx
  int v6; // edi
  _DWORD *v7; // ecx
  int result; // eax

  if ( a2 >= 0xC && *a1 == 65 && a1[1] == 100 && a1[2] == 111 && a1[3] == 98 && a1[4] == 101 )
  {
    v4 = (unsigned __int8)a1[11];
    v5 = (unsigned __int8)a1[8] + ((unsigned __int8)a1[7] << 8);
    v6 = (unsigned __int8)a1[10] + ((unsigned __int8)a1[9] << 8);
    v7 = (_DWORD *)(*(_DWORD *)a3 + 24);
    *v7 = (unsigned __int8)a1[6] + ((unsigned __int8)a1[5] << 8);
    v7[1] = v5;
    v7[2] = v6;
    v7[3] = v4;
    *(_DWORD *)(*(_DWORD *)a3 + 20) = 78;
    result = (*(int (__cdecl **)(_BYTE *, int))(*(_DWORD *)a3 + 4))(a3, 1);
    a3[265] = v4;
    a3[264] = 1;
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)a3 + 20) = 80;
    *(_DWORD *)(*(_DWORD *)a3 + 24) = a4 + a2;
    return (*(int (__cdecl **)(_BYTE *, int))(*(_DWORD *)a3 + 4))(a3, 1);
  }
  return result;
}
