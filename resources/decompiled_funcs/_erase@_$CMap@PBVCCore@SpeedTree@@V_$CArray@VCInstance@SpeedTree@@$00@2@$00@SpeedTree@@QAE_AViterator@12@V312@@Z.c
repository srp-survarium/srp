_DWORD *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::erase(
        _DWORD *this,
        _DWORD *a2,
        int a3,
        int a4)
{
  int v5; // [esp+10h] [ebp-32Ch]
  int v6; // [esp+20h] [ebp-31Ch]
  int v7; // [esp+2Ch] [ebp-310h]
  int v8; // [esp+30h] [ebp-30Ch]
  int v9; // [esp+34h] [ebp-308h]
  int v10; // [esp+38h] [ebp-304h]
  int v11; // [esp+3Ch] [ebp-300h]
  int v12; // [esp+40h] [ebp-2FCh]
  int v13; // [esp+44h] [ebp-2F8h]
  int v14; // [esp+48h] [ebp-2F4h]
  int v15; // [esp+4Ch] [ebp-2F0h]
  int v16; // [esp+50h] [ebp-2ECh]
  int v17; // [esp+54h] [ebp-2E8h]
  int v18; // [esp+58h] [ebp-2E4h]
  int v19; // [esp+5Ch] [ebp-2E0h]
  int v20; // [esp+60h] [ebp-2DCh]
  int v21; // [esp+64h] [ebp-2D8h]
  int v22; // [esp+68h] [ebp-2D4h]
  int v23; // [esp+6Ch] [ebp-2D0h]
  int v24; // [esp+70h] [ebp-2CCh]
  int v25; // [esp+74h] [ebp-2C8h]
  int v26; // [esp+78h] [ebp-2C4h]
  int v27; // [esp+7Ch] [ebp-2C0h]
  int v28; // [esp+80h] [ebp-2BCh]
  int v29; // [esp+84h] [ebp-2B8h]
  int v30; // [esp+88h] [ebp-2B4h]
  int v31; // [esp+8Ch] [ebp-2B0h]
  int v32; // [esp+90h] [ebp-2ACh]
  int v33; // [esp+94h] [ebp-2A8h]
  int v34; // [esp+98h] [ebp-2A4h]
  int v35; // [esp+9Ch] [ebp-2A0h]
  int v36; // [esp+A0h] [ebp-29Ch]
  int v37; // [esp+A4h] [ebp-298h]
  int v38; // [esp+A8h] [ebp-294h]
  int v39; // [esp+ACh] [ebp-290h]
  int v40; // [esp+B0h] [ebp-28Ch]
  int v41; // [esp+B4h] [ebp-288h]
  int v42; // [esp+B8h] [ebp-284h]
  int v43; // [esp+BCh] [ebp-280h]
  int v44; // [esp+C0h] [ebp-27Ch]
  int v45; // [esp+C4h] [ebp-278h]
  int v46; // [esp+C8h] [ebp-274h]
  int v47; // [esp+CCh] [ebp-270h]
  int v48; // [esp+D0h] [ebp-26Ch]
  int v49; // [esp+D4h] [ebp-268h]
  int v50; // [esp+D8h] [ebp-264h]
  int v51; // [esp+DCh] [ebp-260h]
  int v52; // [esp+E0h] [ebp-25Ch]
  int v53; // [esp+E4h] [ebp-258h]
  int v54; // [esp+E8h] [ebp-254h]
  int v55; // [esp+ECh] [ebp-250h]
  int v56; // [esp+F0h] [ebp-24Ch]
  int v57; // [esp+F4h] [ebp-248h]
  int v58; // [esp+F8h] [ebp-244h]
  int v59; // [esp+FCh] [ebp-240h]
  int v60; // [esp+100h] [ebp-23Ch]
  int v61; // [esp+104h] [ebp-238h]
  int v62; // [esp+108h] [ebp-234h]
  int v63; // [esp+10Ch] [ebp-230h]
  int v64; // [esp+110h] [ebp-22Ch]
  int v66; // [esp+118h] [ebp-224h]
  int v67; // [esp+208h] [ebp-134h]
  int v68; // [esp+218h] [ebp-124h]
  int v69; // [esp+244h] [ebp-F8h]
  int v70; // [esp+24Ch] [ebp-F0h]
  int v71; // [esp+254h] [ebp-E8h]
  int v72; // [esp+260h] [ebp-DCh]
  int v73; // [esp+26Ch] [ebp-D0h]
  int v74; // [esp+284h] [ebp-B8h]
  int v75; // [esp+29Ch] [ebp-A0h]
  int v76; // [esp+2C8h] [ebp-74h]
  int v77; // [esp+2D0h] [ebp-6Ch]
  int v78; // [esp+2D8h] [ebp-64h]
  int v79; // [esp+2F4h] [ebp-48h]
  int v80; // [esp+2FCh] [ebp-40h]
  int v81; // [esp+304h] [ebp-38h]
  int v82; // [esp+320h] [ebp-1Ch]
  int v83; // [esp+324h] [ebp-18h]
  int i; // [esp+328h] [ebp-14h]
  int v85; // [esp+32Ch] [ebp-10h]
  bool v86; // [esp+333h] [ebp-9h]
  int v87; // [esp+334h] [ebp-8h]
  int v88; // [esp+338h] [ebp-4h] BYREF

  v88 = a3;
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::iterator_base::operator++(&a3);
  v86 = v88 == this[1];
  if ( v88 )
    v64 = v88 + this[4];
  else
    v64 = 0;
  if ( *(_DWORD *)(v64 + 24) || (!v88 ? (v63 = 0) : (v63 = v88 + this[4]), *(_DWORD *)(v63 + 28)) )
  {
    if ( v88 )
      v54 = v88 + this[4];
    else
      v54 = 0;
    if ( *(_DWORD *)(v54 + 24) && (!v88 ? (v53 = 0) : (v53 = v88 + this[4]), *(_DWORD *)(v53 + 28)) )
    {
      if ( v88 )
        v41 = v88 + this[4];
      else
        v41 = 0;
      for ( i = *(_DWORD *)(v41 + 24); ; i = *(_DWORD *)(v39 + 28) )
      {
        v40 = i ? i + this[4] : 0;
        if ( !*(_DWORD *)(v40 + 28) )
          break;
        if ( i )
          v39 = i + this[4];
        else
          v39 = 0;
      }
      if ( v88 )
        v38 = v88 + this[4];
      else
        v38 = 0;
      if ( i == *(_DWORD *)(v38 + 24) )
      {
        if ( v88 )
          v37 = v88 + this[4];
        else
          v37 = 0;
        if ( i )
          v36 = i + this[4];
        else
          v36 = 0;
        *(_DWORD *)(v36 + 28) = *(_DWORD *)(v37 + 28);
        if ( i )
          v35 = i + this[4];
        else
          v35 = 0;
        if ( *(_DWORD *)(v35 + 28) )
        {
          if ( i )
            v34 = i + this[4];
          else
            v34 = 0;
          v75 = *(_DWORD *)(v34 + 28);
          if ( v75 )
            v33 = v75 + this[4];
          else
            v33 = 0;
          *(_DWORD *)(v33 + 32) = i;
        }
        v87 = i;
      }
      else
      {
        if ( i )
          v32 = i + this[4];
        else
          v32 = 0;
        v83 = *(_DWORD *)(v32 + 32);
        if ( i )
          v31 = i + this[4];
        else
          v31 = 0;
        if ( v83 )
          v30 = v83 + this[4];
        else
          v30 = 0;
        *(_DWORD *)(v30 + 28) = *(_DWORD *)(v31 + 24);
        if ( v83 )
          v29 = v83 + this[4];
        else
          v29 = 0;
        if ( *(_DWORD *)(v29 + 28) )
        {
          if ( v83 )
            v28 = v83 + this[4];
          else
            v28 = 0;
          v74 = *(_DWORD *)(v28 + 28);
          if ( v74 )
            v27 = v74 + this[4];
          else
            v27 = 0;
          *(_DWORD *)(v27 + 32) = v83;
        }
        if ( v88 )
          v26 = v88 + this[4];
        else
          v26 = 0;
        if ( i )
          v25 = i + this[4];
        else
          v25 = 0;
        *(_DWORD *)(v25 + 24) = *(_DWORD *)(v26 + 24);
        if ( v88 )
          v24 = v88 + this[4];
        else
          v24 = 0;
        if ( i )
          v23 = i + this[4];
        else
          v23 = 0;
        *(_DWORD *)(v23 + 28) = *(_DWORD *)(v24 + 28);
        if ( i )
          v22 = i + this[4];
        else
          v22 = 0;
        v73 = *(_DWORD *)(v22 + 24);
        if ( v73 )
          v21 = v73 + this[4];
        else
          v21 = 0;
        *(_DWORD *)(v21 + 32) = i;
        if ( i )
          v20 = i + this[4];
        else
          v20 = 0;
        if ( *(_DWORD *)(v20 + 28) )
        {
          if ( i )
            v19 = i + this[4];
          else
            v19 = 0;
          v72 = *(_DWORD *)(v19 + 28);
          if ( v72 )
            v18 = v72 + this[4];
          else
            v18 = 0;
          *(_DWORD *)(v18 + 32) = i;
        }
        v87 = v83;
      }
      if ( v88 )
        v17 = v88 + this[4];
      else
        v17 = 0;
      if ( *(_DWORD *)(v17 + 32) )
      {
        if ( v88 )
          v16 = v88 + this[4];
        else
          v16 = 0;
        v71 = *(_DWORD *)(v16 + 32);
        if ( v71 )
          v15 = v71 + this[4];
        else
          v15 = 0;
        if ( *(_DWORD *)(v15 + 24) == v88 )
        {
          if ( v88 )
            v14 = v88 + this[4];
          else
            v14 = 0;
          v70 = *(_DWORD *)(v14 + 32);
          if ( v70 )
            v13 = v70 + this[4];
          else
            v13 = 0;
          *(_DWORD *)(v13 + 24) = i;
        }
        else
        {
          if ( v88 )
            v12 = v88 + this[4];
          else
            v12 = 0;
          v69 = *(_DWORD *)(v12 + 32);
          if ( v69 )
            v11 = v69 + this[4];
          else
            v11 = 0;
          *(_DWORD *)(v11 + 28) = i;
        }
      }
      if ( v88 )
        v10 = v88 + this[4];
      else
        v10 = 0;
      if ( i )
        v9 = i + this[4];
      else
        v9 = 0;
      *(_DWORD *)(v9 + 32) = *(_DWORD *)(v10 + 32);
      if ( v88 )
        v8 = v88 + this[4];
      else
        v8 = 0;
      if ( i )
        v7 = i + this[4];
      else
        v7 = 0;
      *(_DWORD *)(v7 + 36) = *(_DWORD *)(v8 + 36);
      if ( v86 )
        this[1] = i;
    }
    else
    {
      if ( v88 )
        v52 = v88 + this[4];
      else
        v52 = 0;
      v85 = *(_DWORD *)(v52 + 24);
      if ( !v85 )
      {
        if ( v88 )
          v51 = v88 + this[4];
        else
          v51 = 0;
        v85 = *(_DWORD *)(v51 + 28);
      }
      v87 = v85;
      if ( v88 )
        v50 = v88 + this[4];
      else
        v50 = 0;
      if ( *(_DWORD *)(v50 + 32) )
      {
        if ( v88 )
          v49 = v88 + this[4];
        else
          v49 = 0;
        v78 = *(_DWORD *)(v49 + 32);
        if ( v78 )
          v48 = v78 + this[4];
        else
          v48 = 0;
        if ( *(_DWORD *)(v48 + 24) == v88 )
        {
          if ( v88 )
            v47 = v88 + this[4];
          else
            v47 = 0;
          v77 = *(_DWORD *)(v47 + 32);
          if ( v77 )
            v46 = v77 + this[4];
          else
            v46 = 0;
          *(_DWORD *)(v46 + 24) = v85;
        }
        else
        {
          if ( v88 )
            v45 = v88 + this[4];
          else
            v45 = 0;
          v76 = *(_DWORD *)(v45 + 32);
          if ( v76 )
            v44 = v76 + this[4];
          else
            v44 = 0;
          *(_DWORD *)(v44 + 28) = v85;
        }
      }
      if ( v88 )
        v43 = v88 + this[4];
      else
        v43 = 0;
      if ( v85 )
        v42 = v85 + this[4];
      else
        v42 = 0;
      *(_DWORD *)(v42 + 32) = *(_DWORD *)(v43 + 32);
      if ( v86 )
        this[1] = v85;
    }
  }
  else
  {
    if ( v88 )
      v62 = v88 + this[4];
    else
      v62 = 0;
    v87 = *(_DWORD *)(v62 + 32);
    if ( v88 )
      v61 = v88 + this[4];
    else
      v61 = 0;
    if ( *(_DWORD *)(v61 + 32) )
    {
      if ( v88 )
        v60 = v88 + this[4];
      else
        v60 = 0;
      v81 = *(_DWORD *)(v60 + 32);
      if ( v81 )
        v59 = v81 + this[4];
      else
        v59 = 0;
      if ( *(_DWORD *)(v59 + 24) == v88 )
      {
        if ( v88 )
          v58 = v88 + this[4];
        else
          v58 = 0;
        v80 = *(_DWORD *)(v58 + 32);
        if ( v80 )
          v57 = v80 + this[4];
        else
          v57 = 0;
        *(_DWORD *)(v57 + 24) = 0;
      }
      else
      {
        if ( v88 )
          v56 = v88 + this[4];
        else
          v56 = 0;
        v79 = *(_DWORD *)(v56 + 32);
        if ( v79 )
          v55 = v79 + this[4];
        else
          v55 = 0;
        *(_DWORD *)(v55 + 28) = 0;
      }
    }
    if ( v86 )
      this[1] = 0;
  }
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::Deallocate(&v88);
  if ( v87 )
  {
    v82 = v87;
    while ( v82 )
    {
      if ( *(_DWORD *)(v82 + this[4] + 24)
        && ((v68 = *(_DWORD *)(v82 + this[4] + 24)) == 0 ? (v6 = 0) : (v6 = v68 + this[4]),
            *(_DWORD *)(v6 + 36) < (unsigned int)(*(_DWORD *)(v82 + this[4] + 36) - 1))
        || *(_DWORD *)(v82 + this[4] + 28)
        && ((v67 = *(_DWORD *)(v82 + this[4] + 28)) == 0 ? (v5 = 0) : (v5 = v67 + this[4]),
            *(_DWORD *)(v5 + 36) < (unsigned int)(*(_DWORD *)(v82 + this[4] + 36) - 1)) )
      {
        --*(_DWORD *)(v82 + this[4] + 36);
        v82 = *(_DWORD *)(v82 + this[4] + 32);
      }
      else
      {
        v82 = 0;
      }
    }
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::Rebalance(v87);
  }
  --this[2];
  v66 = a4;
  *a2 = a3;
  a2[1] = v66;
  return a2;
}
