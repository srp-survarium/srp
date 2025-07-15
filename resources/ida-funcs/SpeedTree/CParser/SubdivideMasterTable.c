void __thiscall SpeedTree::CParser::SubdivideMasterTable(
        SpeedTree::CParser *this,
        const struct SpeedTree::CParser::STriListTmp *a2,
        const struct SpeedTree::CParser::STriListTmp *a3,
        const struct SpeedTree::CParser::STriListTmp *a4,
        const struct SpeedTree::CParser::SLeafCardsTmp *a5)
{
  int v5; // [esp+0h] [ebp-A0h]
  int v6; // [esp+4h] [ebp-9Ch]
  int v7; // [esp+8h] [ebp-98h]
  int nn; // [esp+48h] [ebp-58h]
  int v10; // [esp+4Ch] [ebp-54h]
  int mm; // [esp+50h] [ebp-50h]
  float *v12; // [esp+54h] [ebp-4Ch]
  int kk; // [esp+58h] [ebp-48h]
  int v14; // [esp+5Ch] [ebp-44h]
  int v15; // [esp+64h] [ebp-3Ch]
  int jj; // [esp+68h] [ebp-38h]
  int n; // [esp+6Ch] [ebp-34h]
  int ii; // [esp+70h] [ebp-30h]
  int m; // [esp+74h] [ebp-2Ch]
  float *v20; // [esp+78h] [ebp-28h]
  int k; // [esp+7Ch] [ebp-24h]
  float *v22; // [esp+80h] [ebp-20h]
  int *v23; // [esp+84h] [ebp-1Ch]
  int v24; // [esp+88h] [ebp-18h]
  int j; // [esp+8Ch] [ebp-14h]
  int v26; // [esp+90h] [ebp-10h]
  const struct SpeedTree::CParser::STriListTmp *v27; // [esp+94h] [ebp-Ch]
  int i; // [esp+98h] [ebp-8h]
  int v29; // [esp+9Ch] [ebp-4h]

  v29 = *(_DWORD *)a4 + *(_DWORD *)a3 + *(_DWORD *)a2;
  if ( v29 > 0 )
  {
    *(_DWORD *)(*((_DWORD *)this + 3) + 168) = SpeedTree::st_new_array<SpeedTree::SIndexedTriangles>(
                                                 v29,
                                                 "CCore::SIndexedTriangles");
    *(_DWORD *)(*((_DWORD *)this + 3) + 8) = *(_DWORD *)a2;
    if ( *(int *)a2 <= 0 )
      v7 = 0;
    else
      v7 = *(_DWORD *)(*((_DWORD *)this + 3) + 168);
    *(_DWORD *)(*((_DWORD *)this + 3) + 12) = v7;
    *(_DWORD *)(*((_DWORD *)this + 3) + 16) = *(_DWORD *)a3;
    if ( *(int *)a3 <= 0 )
      v6 = 0;
    else
      v6 = *(_DWORD *)(*((_DWORD *)this + 3) + 168) + 68 * *(_DWORD *)a2;
    *(_DWORD *)(*((_DWORD *)this + 3) + 20) = v6;
    *(_DWORD *)(*((_DWORD *)this + 3) + 24) = *(_DWORD *)a4;
    if ( *(int *)a4 <= 0 )
      v5 = 0;
    else
      v5 = 68 * *(_DWORD *)a3 + 68 * *(_DWORD *)a2 + *(_DWORD *)(*((_DWORD *)this + 3) + 168);
    *(_DWORD *)(*((_DWORD *)this + 3) + 28) = v5;
    for ( i = 0; i < 3; ++i )
    {
      v27 = a2;
      v26 = *(_DWORD *)(*((_DWORD *)this + 3) + 12);
      if ( i == 1 )
      {
        v27 = a3;
        v26 = *(_DWORD *)(*((_DWORD *)this + 3) + 20);
      }
      else if ( i == 2 )
      {
        v27 = a4;
        v26 = *(_DWORD *)(*((_DWORD *)this + 3) + 28);
      }
      if ( v26 )
      {
        for ( j = 0; j < *(_DWORD *)v27; ++j )
        {
          v23 = (int *)((char *)v27 + 176 * j + 4);
          v24 = v26 + 68 * j;
          *(_DWORD *)(v24 + 16) = *v23;
          *(_DWORD *)(v24 + 20) = *((_DWORD *)this + 6);
          *((_DWORD *)this + 6) += 12 * *v23;
          *(_DWORD *)(v24 + 24) = *((_DWORD *)this + 6);
          *((_DWORD *)this + 6) += 12 * *v23;
          *(_DWORD *)(v24 + 28) = *((_DWORD *)this + 12);
          *((_DWORD *)this + 12) += 3 * *v23;
          if ( *((_BYTE *)this + 96) )
          {
            *(_DWORD *)(v24 + 32) = *((_DWORD *)this + 12);
            *((_DWORD *)this + 12) += 3 * *v23;
            *(_DWORD *)(v24 + 36) = *((_DWORD *)this + 12);
            *((_DWORD *)this + 12) += 3 * *v23;
          }
          *(_DWORD *)(v24 + 40) = *((_DWORD *)this + 6);
          *((_DWORD *)this + 6) += 8 * *v23;
          if ( *((_BYTE *)v27 + 176 * j + 12) )
          {
            *(_DWORD *)(v24 + 44) = *((_DWORD *)this + 6);
            *((_DWORD *)this + 6) += 8 * *v23;
          }
          else
          {
            *(_DWORD *)(v24 + 44) = 0;
          }
          if ( SpeedTree::CParser::TexturesNeedFlipping(this) )
          {
            v22 = (float *)(*(_DWORD *)(v24 + 40) + 4);
            for ( k = 0; k < *v23; ++k )
            {
              *v22 = 1.0 - *v22;
              v22 += 2;
            }
            if ( *(_DWORD *)(v24 + 44) )
            {
              v20 = (float *)(*(_DWORD *)(v24 + 44) + 4);
              for ( m = 0; m < *v23; ++m )
              {
                *v20 = 1.0 - *v20;
                v20 += 2;
              }
            }
          }
          *(_DWORD *)(v24 + 48) = *((_DWORD *)this + 12);
          *((_DWORD *)this + 12) += *v23;
          if ( *((_BYTE *)this + 95) )
          {
            *(float *)(v24 + 52) = *((float *)v27 + 44 * j + 4);
            *(_DWORD *)(v24 + 56) = *((_DWORD *)this + 12);
            *((_DWORD *)this + 12) += 6 * *v23;
            if ( i == 1 )
            {
              *(_DWORD *)(v24 + 60) = *((_DWORD *)this + 6);
              *((_DWORD *)this + 6) += 8 * *v23;
            }
            else if ( i == 2 )
            {
              *(_DWORD *)(v24 + 64) = *((_DWORD *)this + 6);
              *((_DWORD *)this + 6) += 12 * *v23;
            }
          }
          *(_DWORD *)v24 = *((_DWORD *)v27 + 44 * j + 2);
          if ( *(int *)(v24 + 16) <= 0 )
          {
            *(_DWORD *)(v24 + 4) = &g_sEmptyDrawCallInfo;
          }
          else
          {
            *(_DWORD *)(v24 + 4) = *((_DWORD *)this + 9);
            *((_DWORD *)this + 9) += 20 * *((_DWORD *)v27 + 44 * j + 2);
          }
          if ( *(int *)(v24 + 16) <= 0xFFFF )
          {
            *(_DWORD *)(v24 + 8) = *((_DWORD *)this + 15);
            for ( n = 0; n < *(_DWORD *)v24; ++n )
              *((_DWORD *)this + 15) += 2 * *(_DWORD *)(*(_DWORD *)(v24 + 4) + 20 * n + 8);
          }
          else
          {
            *(_DWORD *)(v24 + 12) = *((_DWORD *)this + 18);
            for ( ii = 0; ii < *(_DWORD *)v24; ++ii )
              *((_DWORD *)this + 18) += 4 * *(_DWORD *)(*(_DWORD *)(v24 + 4) + 20 * ii + 8);
          }
          if ( *((_DWORD *)this + 22) )
          {
            SpeedTree::CParser::ConvertFloatArray(this, *(float **)(v24 + 20), *v23);
            SpeedTree::CParser::ConvertFloatArray(this, *(float **)(v24 + 24), *v23);
            SpeedTree::CParser::ConvertUint8Array(this, *(unsigned __int8 **)(v24 + 28), *v23, 0);
            if ( *((_BYTE *)this + 96) )
            {
              SpeedTree::CParser::ConvertUint8Array(this, *(unsigned __int8 **)(v24 + 32), *v23, 0);
              SpeedTree::CParser::ConvertUint8Array(this, *(unsigned __int8 **)(v24 + 36), *v23, 0);
            }
            if ( *((_BYTE *)this + 95) )
              SpeedTree::CParser::ConvertUint8Array(this, *(unsigned __int8 **)(v24 + 56), *v23, 3);
          }
        }
      }
    }
  }
  *(_DWORD *)(*((_DWORD *)this + 3) + 32) = *(_DWORD *)a5;
  if ( *(int *)a5 > 0 )
  {
    *(_DWORD *)(*((_DWORD *)this + 3) + 36) = SpeedTree::st_new_array<SpeedTree::SLeafCards>(
                                                *(_DWORD *)(*((_DWORD *)this + 3) + 32),
                                                "CCore::SLeafCards");
    for ( jj = 0; jj < *(_DWORD *)(*((_DWORD *)this + 3) + 32); ++jj )
    {
      v14 = *(_DWORD *)(*((_DWORD *)this + 3) + 36) + 60 * jj;
      *(_DWORD *)v14 = *((_DWORD *)a5 + 42 * jj + 1);
      if ( *(int *)v14 <= 0 )
      {
        *(_DWORD *)(v14 + 4) = &g_sEmptyDrawCallInfo;
      }
      else
      {
        *(_DWORD *)(v14 + 4) = *((_DWORD *)this + 9);
        *((_DWORD *)this + 9) += 20 * *(_DWORD *)v14;
      }
      v15 = 0;
      for ( kk = 0; kk < *((_DWORD *)a5 + 42 * jj + 1); ++kk )
        v15 += *(_DWORD *)(*(_DWORD *)(v14 + 4) + 20 * kk + 8);
      *(_DWORD *)(v14 + 8) = v15;
      *(_DWORD *)(v14 + 12) = *((_DWORD *)this + 6);
      *((_DWORD *)this + 6) += 12 * v15;
      *(_DWORD *)(v14 + 16) = *((_DWORD *)this + 6);
      *((_DWORD *)this + 6) += 8 * v15;
      *(_DWORD *)(v14 + 20) = *((_DWORD *)this + 6);
      *((_DWORD *)this + 6) += 8 * v15;
      *(_DWORD *)(v14 + 24) = *((_DWORD *)this + 6);
      *((_DWORD *)this + 6) += 8 * v15;
      *(_DWORD *)(v14 + 28) = *((_DWORD *)this + 12);
      *((_DWORD *)this + 12) += 12 * v15;
      if ( *((_BYTE *)this + 96) )
      {
        *(_DWORD *)(v14 + 32) = *((_DWORD *)this + 12);
        *((_DWORD *)this + 12) += 12 * v15;
        *(_DWORD *)(v14 + 36) = *((_DWORD *)this + 12);
        *((_DWORD *)this + 12) += 12 * v15;
      }
      *(_DWORD *)(v14 + 40) = *((_DWORD *)this + 6);
      *((_DWORD *)this + 6) += 32 * v15;
      if ( SpeedTree::CParser::TexturesNeedFlipping(this) )
      {
        v12 = (float *)(*(_DWORD *)(v14 + 40) + 4);
        for ( mm = 0; mm < 4 * v15; ++mm )
        {
          *v12 = 1.0 - *v12;
          v12 += 2;
        }
      }
      *(_DWORD *)(v14 + 44) = *((_DWORD *)this + 12);
      *((_DWORD *)this + 12) += v15;
      if ( *((_BYTE *)this + 95) )
      {
        *(float *)(v14 + 48) = *((float *)a5 + 42 * jj + 2);
        *(_DWORD *)(v14 + 52) = *((_DWORD *)this + 12);
        *((_DWORD *)this + 12) += 5 * v15;
      }
      *(_DWORD *)(v14 + 56) = *((_DWORD *)this + 6);
      *((_DWORD *)this + 6) += 16 * v15;
      if ( *((_DWORD *)this + 22) )
      {
        SpeedTree::CParser::ConvertFloatArray(this, *(float **)(v14 + 12), v15);
        SpeedTree::CParser::ConvertUint8Array(this, *(unsigned __int8 **)(v14 + 28), 4 * v15, 0);
        if ( *((_BYTE *)this + 96) )
        {
          SpeedTree::CParser::ConvertUint8Array(this, *(unsigned __int8 **)(v14 + 32), 4 * v15, 0);
          SpeedTree::CParser::ConvertUint8Array(this, *(unsigned __int8 **)(v14 + 36), 4 * v15, 0);
        }
        if ( *((_BYTE *)this + 95) )
          SpeedTree::CParser::ConvertUint8Array(this, *(unsigned __int8 **)(v14 + 52), v15, 2);
      }
    }
  }
  *(_DWORD *)(*((_DWORD *)this + 3) + 60) = *((_DWORD *)this + 6);
  if ( SpeedTree::CParser::TexturesNeedFlipping(this) )
  {
    v10 = *(_DWORD *)(*((_DWORD *)this + 3) + 60);
    for ( nn = 0; nn < *(_DWORD *)(*((_DWORD *)this + 3) + 44); ++nn )
    {
      *(float *)(v10 + 4) = 1.0 - *(float *)(v10 + 4);
      *(float *)(v10 + 12) = -*(float *)(v10 + 12);
      v10 += 16;
    }
  }
  *((_DWORD *)this + 6) += 16 * *(_DWORD *)(*((_DWORD *)this + 3) + 44);
}
