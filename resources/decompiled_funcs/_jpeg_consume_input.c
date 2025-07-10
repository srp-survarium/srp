int __cdecl jpeg_consume_input(_DWORD *a1)
{
  int v1; // edi
  int result; // eax

  v1 = 0;
  switch ( a1[5] )
  {
    case 0xC8:
      (*(void (__cdecl **)(_DWORD *))(a1[104] + 4))(a1);
      (*(void (__cdecl **)(_DWORD *))(a1[6] + 8))(a1);
      a1[5] = 201;
      goto LABEL_3;
    case 0xC9:
LABEL_3:
      v1 = (*(int (__cdecl **)(_DWORD *))a1[104])(a1);
      if ( v1 != 1 )
        goto LABEL_8;
      sub_370E80((int)a1);
      result = 1;
      a1[5] = 202;
      break;
    case 0xCA:
      return 1;
    case 0xCB:
    case 0xCC:
    case 0xCD:
    case 0xCE:
    case 0xCF:
    case 0xD0:
    case 0xD2:
      return (*(int (__cdecl **)(_DWORD *))a1[104])(a1);
    default:
      *(_DWORD *)(*a1 + 20) = 21;
      *(_DWORD *)(*a1 + 24) = a1[5];
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
LABEL_8:
      result = v1;
      break;
  }
  return result;
}
