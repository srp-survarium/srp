char __thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::Rebalance(_DWORD *this, int a2)
{
  int v2; // eax
  int v4; // [esp+0h] [ebp-1B8h]
  int v5; // [esp+8h] [ebp-1B0h]
  int v6; // [esp+10h] [ebp-1A8h]
  int v7; // [esp+14h] [ebp-1A4h]
  int v8; // [esp+18h] [ebp-1A0h]
  int v9; // [esp+1Ch] [ebp-19Ch]
  int v10; // [esp+20h] [ebp-198h]
  int v11; // [esp+24h] [ebp-194h]
  int v12; // [esp+28h] [ebp-190h]
  int v13; // [esp+2Ch] [ebp-18Ch]
  int v14; // [esp+34h] [ebp-184h]
  int v15; // [esp+38h] [ebp-180h]
  int v16; // [esp+48h] [ebp-170h]
  int v17; // [esp+4Ch] [ebp-16Ch]
  int v18; // [esp+54h] [ebp-164h]
  int v19; // [esp+58h] [ebp-160h]
  int v20; // [esp+60h] [ebp-158h]
  int v21; // [esp+70h] [ebp-148h]
  int v22; // [esp+74h] [ebp-144h]
  int v23; // [esp+78h] [ebp-140h]
  int v24; // [esp+7Ch] [ebp-13Ch]
  int v25; // [esp+80h] [ebp-138h]
  int v26; // [esp+84h] [ebp-134h]
  int v27; // [esp+88h] [ebp-130h]
  int v28; // [esp+8Ch] [ebp-12Ch]
  int v29; // [esp+94h] [ebp-124h]
  int v30; // [esp+98h] [ebp-120h]
  int v31; // [esp+A8h] [ebp-110h]
  int v32; // [esp+ACh] [ebp-10Ch]
  int v33; // [esp+BCh] [ebp-FCh]
  int v34; // [esp+CCh] [ebp-ECh]
  int v35; // [esp+E8h] [ebp-D0h]
  int v36; // [esp+F0h] [ebp-C8h]
  int v37; // [esp+F8h] [ebp-C0h]
  int v38; // [esp+110h] [ebp-A8h]
  int v39; // [esp+12Ch] [ebp-8Ch]
  int v40; // [esp+130h] [ebp-88h]
  int v41; // [esp+138h] [ebp-80h]
  int v42; // [esp+148h] [ebp-70h]
  int v43; // [esp+150h] [ebp-68h]
  int v44; // [esp+158h] [ebp-60h]
  int v45; // [esp+170h] [ebp-48h]
  int v46; // [esp+190h] [ebp-28h]
  int v47; // [esp+1A0h] [ebp-18h]
  int v48; // [esp+1ACh] [ebp-Ch]
  int v49; // [esp+1B0h] [ebp-8h]
  char v50; // [esp+1B6h] [ebp-2h]

  v50 = 5;
  while ( a2 )
  {
    if ( *(_DWORD *)(a2 + this[4] + 144)
      && ((v47 = *(_DWORD *)(a2 + this[4] + 144)) == 0 ? (v34 = 0) : (v34 = v47 + this[4]),
          *(_DWORD *)(v34 + 156) == *(_DWORD *)(a2 + this[4] + 156)) )
    {
      if ( *(_DWORD *)(a2 + this[4] + 148)
        && ((v46 = *(_DWORD *)(a2 + this[4] + 148)) == 0 ? (v33 = 0) : (v33 = v46 + this[4]),
            *(_DWORD *)(v33 + 156) == *(_DWORD *)(a2 + this[4] + 156)) )
      {
        ++*(_DWORD *)(a2 + this[4] + 156);
      }
      else
      {
        v32 = a2 + this[4];
        v49 = *(_DWORD *)(v32 + 144);
        if ( v49 )
          v31 = *(_DWORD *)(v32 + 144) + this[4];
        else
          v31 = 0;
        *(_DWORD *)(a2 + this[4] + 144) = *(_DWORD *)(v31 + 148);
        if ( *(_DWORD *)(a2 + this[4] + 144) )
        {
          v45 = *(_DWORD *)(a2 + this[4] + 144);
          if ( v45 )
            v30 = v45 + this[4];
          else
            v30 = 0;
          *(_DWORD *)(v30 + 152) = a2;
        }
        v29 = v49 ? v49 + this[4] : 0;
        *(_DWORD *)(v29 + 148) = a2;
        v28 = v49 ? v49 + this[4] : 0;
        *(_DWORD *)(v28 + 152) = *(_DWORD *)(a2 + this[4] + 152);
        v27 = v49 ? v49 + this[4] : 0;
        if ( *(_DWORD *)(v27 + 152) )
        {
          v26 = v49 ? v49 + this[4] : 0;
          v44 = *(_DWORD *)(v26 + 152);
          v25 = v44 ? v44 + this[4] : 0;
          if ( *(_DWORD *)(v25 + 148) == a2 )
          {
            v24 = v49 ? v49 + this[4] : 0;
            v43 = *(_DWORD *)(v24 + 152);
            v23 = v43 ? v43 + this[4] : 0;
            *(_DWORD *)(v23 + 148) = v49;
          }
          else
          {
            v22 = v49 ? v49 + this[4] : 0;
            v42 = *(_DWORD *)(v22 + 152);
            v21 = v42 ? v42 + this[4] : 0;
            *(_DWORD *)(v21 + 144) = v49;
          }
        }
        else
        {
          this[1] = v49;
        }
        *(_DWORD *)(a2 + this[4] + 152) = v49;
        a2 = v49;
      }
      v50 = 5;
    }
    else if ( *(_DWORD *)(a2 + this[4] + 148) )
    {
      v41 = *(_DWORD *)(a2 + this[4] + 148);
      v20 = v41 ? v41 + this[4] : 0;
      if ( *(_DWORD *)(v20 + 148) )
      {
        v40 = *(_DWORD *)(a2 + this[4] + 148);
        v19 = v40 ? v40 + this[4] : 0;
        v39 = *(_DWORD *)(v19 + 148);
        v18 = v39 ? v39 + this[4] : 0;
        if ( *(_DWORD *)(v18 + 156) == *(_DWORD *)(a2 + this[4] + 156) )
        {
          v17 = a2 + this[4];
          v48 = *(_DWORD *)(v17 + 148);
          if ( v48 )
            v16 = *(_DWORD *)(v17 + 148) + this[4];
          else
            v16 = 0;
          *(_DWORD *)(a2 + this[4] + 148) = *(_DWORD *)(v16 + 144);
          if ( *(_DWORD *)(a2 + this[4] + 148) )
          {
            v38 = *(_DWORD *)(a2 + this[4] + 148);
            if ( v38 )
              v15 = v38 + this[4];
            else
              v15 = 0;
            *(_DWORD *)(v15 + 152) = a2;
          }
          if ( v48 )
            v14 = v48 + this[4];
          else
            v14 = 0;
          *(_DWORD *)(v14 + 144) = a2;
          if ( v48 )
            v13 = v48 + this[4];
          else
            v13 = 0;
          *(_DWORD *)(v13 + 152) = *(_DWORD *)(a2 + this[4] + 152);
          if ( v48 )
            v12 = v48 + this[4];
          else
            v12 = 0;
          if ( *(_DWORD *)(v12 + 152) )
          {
            if ( v48 )
              v11 = v48 + this[4];
            else
              v11 = 0;
            v37 = *(_DWORD *)(v11 + 152);
            if ( v37 )
              v10 = v37 + this[4];
            else
              v10 = 0;
            if ( *(_DWORD *)(v10 + 148) == a2 )
            {
              if ( v48 )
                v9 = v48 + this[4];
              else
                v9 = 0;
              v36 = *(_DWORD *)(v9 + 152);
              if ( v36 )
                v8 = v36 + this[4];
              else
                v8 = 0;
              *(_DWORD *)(v8 + 148) = v48;
            }
            else
            {
              if ( v48 )
                v7 = v48 + this[4];
              else
                v7 = 0;
              v35 = *(_DWORD *)(v7 + 152);
              if ( v35 )
                v6 = v35 + this[4];
              else
                v6 = 0;
              *(_DWORD *)(v6 + 144) = v48;
            }
          }
          else
          {
            this[1] = v48;
          }
          *(_DWORD *)(a2 + this[4] + 152) = v48;
          a2 = v48;
          if ( v48 )
            v5 = v48 + this[4];
          else
            v5 = 0;
          ++*(_DWORD *)(v5 + 156);
          v50 = 5;
        }
      }
    }
    LOBYTE(v2) = --v50;
    if ( !v50 )
      break;
    if ( a2 )
      v4 = a2 + this[4];
    else
      v4 = 0;
    v2 = *(_DWORD *)(v4 + 152);
    a2 = v2;
  }
  return v2;
}
