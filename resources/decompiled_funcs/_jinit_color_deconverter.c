int __cdecl jinit_color_deconverter(int a1)
{
  _DWORD *v1; // edi
  int result; // eax
  int v3; // eax
  int v4; // ecx

  v1 = (_DWORD *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 28);
  *(_DWORD *)(a1 + 436) = v1;
  *v1 = Scaleform::Render::JPEG::JPEGRwSource::TermSource;
  switch ( *(_DWORD *)(a1 + 40) )
  {
    case 1:
      if ( *(_DWORD *)(a1 + 36) != 1 )
        goto LABEL_9;
      break;
    case 2:
    case 3:
      if ( *(_DWORD *)(a1 + 36) != 3 )
        goto LABEL_9;
      break;
    case 4:
    case 5:
      if ( *(_DWORD *)(a1 + 36) != 4 )
        goto LABEL_9;
      break;
    default:
      if ( *(int *)(a1 + 36) < 1 )
      {
LABEL_9:
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 11;
        (**(void (__cdecl ***)(int))a1)(a1);
      }
      break;
  }
  if ( *(_DWORD *)(a1 + 44) != 1 )
  {
    if ( *(_DWORD *)(a1 + 44) == 2 )
    {
      result = *(_DWORD *)(a1 + 40);
      *(_DWORD *)(a1 + 100) = 3;
      switch ( result )
      {
        case 3:
          v1[1] = sub_37A660;
          result = sub_37A590(a1);
          goto LABEL_33;
        case 1:
          v1[1] = sub_37A9E0;
          goto LABEL_33;
        case 2:
          v1[1] = sub_37A8A0;
          goto LABEL_33;
      }
    }
    else
    {
      result = *(_DWORD *)(a1 + 44) - 4;
      if ( *(_DWORD *)(a1 + 44) == 4 )
      {
        result = *(_DWORD *)(a1 + 40);
        *(_DWORD *)(a1 + 100) = 4;
        if ( result == 5 )
        {
          v1[1] = sub_37AA40;
          result = sub_37A590(a1);
          goto LABEL_33;
        }
        if ( result == 4 )
        {
          v1[1] = sub_37A920;
          goto LABEL_33;
        }
      }
      else if ( *(_DWORD *)(a1 + 44) == *(_DWORD *)(a1 + 40) )
      {
        *(_DWORD *)(a1 + 100) = *(_DWORD *)(a1 + 36);
        v1[1] = sub_37A920;
        goto LABEL_33;
      }
    }
LABEL_29:
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 28;
    result = (**(int (__cdecl ***)(int))a1)(a1);
    goto LABEL_33;
  }
  v3 = *(_DWORD *)(a1 + 40);
  *(_DWORD *)(a1 + 100) = 1;
  if ( v3 != 1 && v3 != 3 )
  {
    if ( v3 == 2 )
    {
      v1[1] = sub_37A7E0;
      result = (int)sub_37A780(a1);
      goto LABEL_33;
    }
    goto LABEL_29;
  }
  v1[1] = sub_37A9B0;
  result = 1;
  if ( *(int *)(a1 + 36) > 1 )
  {
    v4 = 88;
    do
    {
      *(_BYTE *)(*(_DWORD *)(a1 + 196) + v4 + 52) = 0;
      ++result;
      v4 += 88;
    }
    while ( result < *(_DWORD *)(a1 + 36) );
  }
LABEL_33:
  if ( *(_BYTE *)(a1 + 74) )
  {
    *(_DWORD *)(a1 + 104) = 1;
  }
  else
  {
    result = *(_DWORD *)(a1 + 100);
    *(_DWORD *)(a1 + 104) = result;
  }
  return result;
}
