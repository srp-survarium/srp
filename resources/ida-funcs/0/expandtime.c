BOOL __usercall expandtime@<eax>(
        char specifier@<al>,
        const tm *timeptr@<edx>,
        char **string@<ecx>,
        localeinfo_struct *plocinfo,
        unsigned int *left,
        __lc_time_data *lc_time,
        unsigned int alternate_form)
{
  char **v7; // ebx
  unsigned int tm_hour; // esi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int tm_mday; // eax
  bool v15; // cc
  char *v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned int v24; // eax
  int tm_yday; // eax
  int v26; // et2
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  char **v39; // eax
  int tm_year; // eax
  unsigned int tm_wday; // eax
  unsigned int v42; // [esp-8h] [ebp-18h]
  unsigned int v43; // [esp-4h] [ebp-14h]

  v7 = string;
  tm_hour = (unsigned int)timeptr;
  if ( specifier > 89 )
  {
    if ( specifier > 109 )
    {
      v35 = specifier - 112;
      if ( !v35 )
      {
        tm_hour = timeptr->tm_hour;
        if ( tm_hour >= 0x18 )
          goto LABEL_74;
        if ( (int)tm_hour > 11 )
          v16 = lc_time->ampm[1];
        else
          v16 = lc_time->ampm[0];
        goto LABEL_96;
      }
      v36 = v35 - 7;
      if ( !v36 )
      {
        tm_wday = timeptr->tm_wday;
        if ( tm_wday <= 6 )
        {
          store_num(tm_wday, 1u, string, left, alternate_form);
          return 1;
        }
        goto LABEL_74;
      }
      v37 = v36 - 1;
      if ( !v37 )
      {
        if ( alternate_form )
          v23 = store_winword(plocinfo, 1, timeptr, string, left, lc_time);
        else
          v23 = store_winword(plocinfo, 0, timeptr, string, left, lc_time);
        return v23 != 0;
      }
      v38 = v37 - 1;
      if ( !v38 )
      {
        tm_year = timeptr->tm_year;
        if ( tm_year >= 0 )
        {
          v43 = alternate_form;
          tm_mday = tm_year % 100;
          goto LABEL_61;
        }
        goto LABEL_74;
      }
      if ( v38 != 1 )
        return 0;
    }
    else
    {
      if ( specifier == 109 )
      {
        tm_hour = timeptr->tm_mon;
        if ( tm_hour >= 0xC )
          goto LABEL_74;
        tm_mday = tm_hour + 1;
        goto LABEL_60;
      }
      v28 = specifier - 90;
      if ( v28 )
      {
        v29 = v28 - 7;
        if ( !v29 )
        {
          tm_hour = timeptr->tm_wday;
          if ( tm_hour > 6 )
            goto LABEL_74;
          v16 = lc_time->wday_abbr[tm_hour];
          goto LABEL_96;
        }
        v30 = v29 - 1;
        if ( !v30 )
        {
          tm_hour = timeptr->tm_mon;
          if ( tm_hour >= 0xC )
            goto LABEL_74;
          v16 = lc_time->month_abbr[tm_hour];
          goto LABEL_96;
        }
        v31 = v30 - 1;
        if ( v31 )
        {
          v32 = v31 - 1;
          if ( v32 )
          {
            if ( v32 != 6 )
              return 0;
            tm_hour = timeptr->tm_yday;
            if ( tm_hour > 0x16D )
              goto LABEL_74;
            v43 = alternate_form;
            tm_mday = tm_hour + 1;
            v42 = 3;
LABEL_62:
            store_num(tm_mday, v42, v7, left, v43);
            return 1;
          }
          tm_hour = timeptr->tm_mday;
          if ( (int)tm_hour < 1 || (int)tm_hour > 31 )
            goto LABEL_74;
          tm_mday = timeptr->tm_mday;
LABEL_60:
          v43 = alternate_form;
LABEL_61:
          v42 = 2;
          goto LABEL_62;
        }
        if ( alternate_form )
          v33 = store_winword(plocinfo, 1, timeptr, string, left, lc_time);
        else
          v33 = store_winword(plocinfo, 0, timeptr, string, left, lc_time);
        if ( !v33 || !*left )
          return 0;
        *(*v7)++ = 32;
        --*left;
        v23 = store_winword(plocinfo, 2, (const tm *)tm_hour, v7, left, lc_time);
        return v23 != 0;
      }
    }
    __tzset(string);
    v39 = __tzname();
    string = v7;
    v16 = v39[*(_DWORD *)(tm_hour + 32) != 0];
    goto LABEL_96;
  }
  if ( specifier == 89 )
  {
    v27 = timeptr->tm_year;
    if ( v27 < -1900 || v27 > 8099 )
      goto LABEL_74;
    v43 = alternate_form;
    v42 = 4;
    tm_mday = v27 % 100 + 100 * (v27 / 100 + 19);
    goto LABEL_62;
  }
  if ( specifier > 73 )
  {
    v18 = specifier - 77;
    if ( v18 )
    {
      v19 = 6;
      v20 = v18 - 6;
      if ( v20 )
      {
        v21 = v20 - 2;
        if ( v21 )
        {
          v22 = v21 - 2;
          if ( v22 )
          {
            if ( v22 != 1 )
              return 0;
            v23 = store_winword(plocinfo, 2, timeptr, v7, left, lc_time);
            return v23 != 0;
          }
          v24 = timeptr->tm_wday;
          if ( v24 > 6 )
            goto LABEL_74;
          if ( v24 )
            v19 = v24 - 1;
        }
        else
        {
          if ( timeptr->tm_wday > 6u )
            goto LABEL_74;
          v19 = timeptr->tm_wday;
        }
        tm_yday = timeptr->tm_yday;
        if ( (unsigned int)tm_yday <= 0x16D )
        {
          if ( tm_yday >= v19 )
          {
            v26 = tm_yday % 7;
            tm_mday = tm_yday / 7;
            if ( v26 >= v19 )
              ++tm_mday;
          }
          else
          {
            tm_mday = 0;
          }
          goto LABEL_60;
        }
        goto LABEL_74;
      }
      tm_mday = timeptr->tm_sec;
    }
    else
    {
      tm_mday = timeptr->tm_min;
    }
    if ( tm_mday >= 0 )
    {
      v15 = tm_mday <= 59;
LABEL_13:
      if ( v15 )
        goto LABEL_60;
    }
LABEL_74:
    *_errno() = 22;
    _invalid_parameter((int)v7, 0, tm_hour);
    return 0;
  }
  if ( specifier == 73 )
  {
    v17 = timeptr->tm_hour;
    if ( (unsigned int)v17 < 0x18 )
    {
      tm_mday = v17 % 12;
      if ( !tm_mday )
        tm_mday = 12;
      goto LABEL_60;
    }
    goto LABEL_74;
  }
  v9 = specifier - 4;
  if ( !v9 )
    return 1;
  v10 = v9 - 9;
  if ( !v10 )
    return 1;
  v11 = v10 - 24;
  if ( v11 )
  {
    v12 = v11 - 28;
    if ( v12 )
    {
      v13 = v12 - 1;
      if ( v13 )
      {
        if ( v13 == 6 )
        {
          tm_mday = timeptr->tm_hour;
          if ( tm_mday >= 0 )
          {
            v15 = tm_mday <= 23;
            goto LABEL_13;
          }
          goto LABEL_74;
        }
        return 0;
      }
      tm_hour = timeptr->tm_mon;
      if ( tm_hour >= 0xC )
        goto LABEL_74;
      v16 = lc_time->month[tm_hour];
    }
    else
    {
      tm_hour = timeptr->tm_wday;
      if ( tm_hour > 6 )
        goto LABEL_74;
      v16 = lc_time->wday[tm_hour];
    }
LABEL_96:
    store_str(v16, string, left);
    return 1;
  }
  *(*string)++ = 37;
  --*left;
  return 1;
}
