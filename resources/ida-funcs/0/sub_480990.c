int __usercall sub_480990@<eax>(int a1@<esi>)
{
  int v1; // eax
  int v2; // ebp
  bool v3; // cc
  int *v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // ebp
  int v11; // edi
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  int result; // eax

  if ( *(int *)(a1 + 32) > 65500 || *(int *)(a1 + 28) > 65500 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 42;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = 65500;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  if ( *(_DWORD *)(a1 + 192) != 8 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 16;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 192);
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  if ( *(int *)(a1 + 36) > 10 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 27;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 36);
    *(_DWORD *)(*(_DWORD *)a1 + 28) = 10;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v1 = *(_DWORD *)(a1 + 196);
  v2 = 0;
  v3 = *(_DWORD *)(a1 + 36) <= 0;
  *(_DWORD *)(a1 + 272) = 1;
  *(_DWORD *)(a1 + 276) = 1;
  if ( !v3 )
  {
    v4 = (int *)(v1 + 12);
    do
    {
      v5 = *(v4 - 1);
      if ( v5 <= 0 || v5 > 4 || *v4 <= 0 || *v4 > 4 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 19;
        (**(void (__cdecl ***)(int))a1)(a1);
      }
      v6 = *(_DWORD *)(a1 + 272);
      if ( v6 <= *(v4 - 1) )
        v6 = *(v4 - 1);
      *(_DWORD *)(a1 + 272) = v6;
      v7 = *(_DWORD *)(a1 + 276);
      if ( v7 <= *v4 )
        v7 = *v4;
      ++v2;
      *(_DWORD *)(a1 + 276) = v7;
      v4 += 22;
    }
    while ( v2 < *(_DWORD *)(a1 + 36) );
  }
  if ( *(_BYTE *)(a1 + 200) || *(_BYTE *)(a1 + 201) && *(_DWORD *)(a1 + 296) )
  {
LABEL_42:
    *(_DWORD *)(a1 + 384) = 8;
  }
  else
  {
    v8 = *(_DWORD *)(a1 + 372);
    if ( v8 > 255 )
    {
LABEL_41:
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 17;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 368);
      *(_DWORD *)(*(_DWORD *)a1 + 28) = *(_DWORD *)(a1 + 372);
      *(_DWORD *)(*(_DWORD *)a1 + 32) = *(_DWORD *)(a1 + 376);
      *(_DWORD *)(*(_DWORD *)a1 + 36) = *(_DWORD *)(a1 + 380);
      (**(void (__cdecl ***)(int))a1)(a1);
      goto LABEL_45;
    }
    if ( v8 != 255 )
    {
      switch ( v8 )
      {
        case 0:
          *(_DWORD *)(a1 + 384) = 1;
          *(_DWORD *)(a1 + 392) = v8;
          goto LABEL_44;
        case 3:
          *(_DWORD *)(a1 + 384) = 2;
          *(_DWORD *)(a1 + 388) = &jpeg_natural_order2;
          *(_DWORD *)(a1 + 392) = v8;
          break;
        case 8:
          *(_DWORD *)(a1 + 384) = 3;
          *(_DWORD *)(a1 + 388) = &jpeg_natural_order3;
          *(_DWORD *)(a1 + 392) = v8;
          break;
        case 15:
          *(_DWORD *)(a1 + 384) = 4;
          *(_DWORD *)(a1 + 388) = &jpeg_natural_order4;
          *(_DWORD *)(a1 + 392) = v8;
          break;
        case 24:
          *(_DWORD *)(a1 + 384) = 5;
          *(_DWORD *)(a1 + 388) = &jpeg_natural_order5;
          *(_DWORD *)(a1 + 392) = v8;
          break;
        case 35:
          *(_DWORD *)(a1 + 384) = 6;
          *(_DWORD *)(a1 + 388) = &jpeg_natural_order6;
          *(_DWORD *)(a1 + 392) = v8;
          break;
        case 48:
          *(_DWORD *)(a1 + 384) = 7;
          *(_DWORD *)(a1 + 388) = &jpeg_natural_order7;
          *(_DWORD *)(a1 + 392) = v8;
          break;
        case 63:
          goto LABEL_42;
        case 80:
          *(_DWORD *)(a1 + 384) = 9;
          goto LABEL_43;
        case 99:
          *(_DWORD *)(a1 + 384) = 10;
          goto LABEL_43;
        case 120:
          *(_DWORD *)(a1 + 384) = 11;
          goto LABEL_43;
        case 143:
          *(_DWORD *)(a1 + 384) = 12;
          goto LABEL_43;
        case 168:
          *(_DWORD *)(a1 + 384) = 13;
          goto LABEL_43;
        case 195:
          *(_DWORD *)(a1 + 384) = 14;
          goto LABEL_43;
        case 224:
          *(_DWORD *)(a1 + 384) = 15;
          goto LABEL_43;
        default:
          goto LABEL_41;
      }
      goto LABEL_45;
    }
    *(_DWORD *)(a1 + 384) = 16;
  }
LABEL_43:
  *(_DWORD *)(a1 + 392) = 63;
LABEL_44:
  *(_DWORD *)(a1 + 388) = &jpeg_natural_order;
LABEL_45:
  v9 = *(_DWORD *)(a1 + 384);
  v10 = 0;
  v3 = *(_DWORD *)(a1 + 36) <= 0;
  *(_DWORD *)(a1 + 280) = v9;
  *(_DWORD *)(a1 + 284) = v9;
  if ( !v3 )
  {
    v11 = *(_DWORD *)(a1 + 196) + 40;
    do
    {
      *(_DWORD *)(v11 - 4) = *(_DWORD *)(a1 + 384);
      v12 = *(_DWORD *)(v11 - 32);
      *(_DWORD *)v11 = *(_DWORD *)(a1 + 384);
      *(_DWORD *)(v11 - 12) = jdiv_round_up(*(_DWORD *)(a1 + 28) * v12, *(_DWORD *)(a1 + 272) * *(_DWORD *)(a1 + 384));
      v13 = jdiv_round_up(*(_DWORD *)(a1 + 32) * *(_DWORD *)(v11 - 28), *(_DWORD *)(a1 + 276) * *(_DWORD *)(a1 + 384));
      v14 = *(_DWORD *)(v11 - 32);
      *(_DWORD *)(v11 - 8) = v13;
      v15 = jdiv_round_up(*(_DWORD *)(a1 + 28) * v14, *(_DWORD *)(a1 + 272));
      v16 = *(_DWORD *)(v11 - 28);
      *(_DWORD *)(v11 + 4) = v15;
      *(_DWORD *)(v11 + 8) = jdiv_round_up(*(_DWORD *)(a1 + 32) * v16, *(_DWORD *)(a1 + 276));
      *(_BYTE *)(v11 + 12) = 1;
      *(_DWORD *)(v11 + 40) = 0;
      ++v10;
      v11 += 88;
    }
    while ( v10 < *(_DWORD *)(a1 + 36) );
  }
  result = jdiv_round_up(*(_DWORD *)(a1 + 32), *(_DWORD *)(a1 + 276) * *(_DWORD *)(a1 + 384));
  v3 = *(_DWORD *)(a1 + 296) < *(_DWORD *)(a1 + 36);
  *(_DWORD *)(a1 + 288) = result;
  if ( v3 || *(_BYTE *)(a1 + 201) )
  {
    result = *(_DWORD *)(a1 + 416);
    *(_BYTE *)(result + 16) = 1;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 416) + 16) = 0;
  }
  return result;
}
