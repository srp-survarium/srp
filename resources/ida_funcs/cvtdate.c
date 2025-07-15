void __usercall cvtdate(
        int month@<eax>,
        int hour@<ecx>,
        int trantype,
        int datetype,
        int year,
        int week,
        int dayofweek,
        int date,
        int min,
        int sec,
        int msec)
{
  int v11; // edi
  int v13; // eax
  int v14; // esi
  int v15; // esi
  unsigned int v16; // ebx
  int v17; // edx
  int v18; // eax
  int v19; // esi
  int v20; // eax
  int v21; // esi
  int v22; // ecx
  int dstbias; // [esp+14h] [ebp-4h] BYREF
  int datetypea; // [esp+24h] [ebp+Ch]

  dstbias = 0;
  v11 = year;
  if ( datetype == 1 )
  {
    if ( (year % 4 || !(year % 100)) && (year + 1900) % 400 )
    {
      v13 = 4 * month;
      v14 = dword_9AEFF8[month];
    }
    else
    {
      v13 = 4 * month;
      v14 = (int)*(&off_9AEFC4 + month);
    }
    datetypea = v13;
    v15 = v14 + 1;
    v11 = year;
    v16 = 7;
    v17 = (365 * year + (year + 299) / 400 - (year - 1) / 100 + v15 + (year - 1) / 4 - 25563) % 7;
    v18 = dayofweek + 7 * week - v17;
    if ( v17 > dayofweek )
      v19 = v18 + v15;
    else
      v19 = v15 + v18 - 7;
    if ( week == 5 )
    {
      if ( (year % 4 || (v16 = 100, !(year % 100))) && (v16 = 400, (year + 1900) % 400) )
        v20 = *(int *)((char *)_days + datetypea);
      else
        v20 = *(int *)((char *)_lpdays + datetypea);
      if ( v19 > v20 )
        v19 -= 7;
    }
  }
  else
  {
    if ( (year % 4 || (v16 = 100, !(year % 100))) && (v16 = 400, (year + 1900) % 400) )
      v21 = dword_9AEFF8[month];
    else
      v21 = (int)*(&off_9AEFC4 + month);
    v19 = date + v21;
  }
  v22 = msec + 1000 * (sec + 60 * (min + 60 * hour));
  if ( trantype == 1 )
  {
    dststart.yd = v19;
    dststart.ms = v22;
    dststart.yr = v11;
  }
  else
  {
    dstend.yd = v19;
    dstend.ms = v22;
    if ( _get_dstbias(&dstbias) )
      _invoke_watson(v16, v11, v19);
    dstend.ms += 1000 * dstbias;
    if ( dstend.ms >= 0 )
    {
      if ( dstend.ms >= 86400000 )
      {
        dstend.ms -= 86400000;
        ++dstend.yd;
      }
    }
    else
    {
      dstend.ms += 86400000;
      --dstend.yd;
    }
    dstend.yr = v11;
  }
}
