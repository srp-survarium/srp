int __usercall get_lc_time@<eax>(__lc_time_data *lc_time@<esi>, threadlocaleinfostruct *ploci@<eax>)
{
  unsigned int wLanguage; // ecx
  unsigned int wCountry; // edx
  int result; // eax
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  int v22; // edi
  int v23; // edi
  int v24; // edi
  int v25; // edi
  int v26; // edi
  int v27; // edi
  int v28; // edi
  int v29; // edi
  int v30; // edi
  int v31; // edi
  int v32; // edi
  int v33; // edi
  int v34; // edi
  int v35; // edi
  int v36; // edi
  int v37; // edi
  int v38; // edi
  int v39; // edi
  int v40; // edi
  int v41; // edi
  int v42; // edi
  int v43; // edi
  int v44; // edi
  int v45; // edi
  int v46; // edi
  int v47; // edi
  unsigned int v48; // ebx
  localeinfo_struct locinfo; // [esp+0h] [ebp-10h] BYREF
  unsigned int ctryid; // [esp+8h] [ebp-8h]
  unsigned int langid; // [esp+Ch] [ebp-4h]

  wLanguage = ploci->lc_id[5].wLanguage;
  wCountry = ploci->lc_id[5].wCountry;
  langid = wLanguage;
  ctryid = wCountry;
  if ( !lc_time )
    return -1;
  locinfo.mbcinfo = 0;
  locinfo.locinfo = ploci;
  v5 = __getlocaleinfo(&locinfo, 1, wLanguage, 0x31u, &lc_time->wday_abbr[1]);
  v6 = __getlocaleinfo(&locinfo, 1, langid, 0x32u, &lc_time->wday_abbr[2]) | v5;
  v7 = __getlocaleinfo(&locinfo, 1, langid, 0x33u, &lc_time->wday_abbr[3]) | v6;
  v8 = __getlocaleinfo(&locinfo, 1, langid, 0x34u, &lc_time->wday_abbr[4]) | v7;
  v9 = __getlocaleinfo(&locinfo, 1, langid, 0x35u, &lc_time->wday_abbr[5]) | v8;
  v10 = __getlocaleinfo(&locinfo, 1, langid, 0x36u, &lc_time->wday_abbr[6]) | v9;
  v11 = __getlocaleinfo(&locinfo, 1, langid, 0x37u, lc_time->wday_abbr) | v10;
  v12 = __getlocaleinfo(&locinfo, 1, langid, 0x2Au, &lc_time->wday[1]) | v11;
  v13 = __getlocaleinfo(&locinfo, 1, langid, 0x2Bu, &lc_time->wday[2]) | v12;
  v14 = __getlocaleinfo(&locinfo, 1, langid, 0x2Cu, &lc_time->wday[3]) | v13;
  v15 = __getlocaleinfo(&locinfo, 1, langid, 0x2Du, &lc_time->wday[4]) | v14;
  v16 = __getlocaleinfo(&locinfo, 1, langid, 0x2Eu, &lc_time->wday[5]) | v15;
  v17 = __getlocaleinfo(&locinfo, 1, langid, 0x2Fu, &lc_time->wday[6]) | v16;
  v18 = __getlocaleinfo(&locinfo, 1, langid, 0x30u, lc_time->wday) | v17;
  v19 = __getlocaleinfo(&locinfo, 1, langid, 0x44u, lc_time->month_abbr) | v18;
  v20 = __getlocaleinfo(&locinfo, 1, langid, 0x45u, &lc_time->month_abbr[1]) | v19;
  v21 = __getlocaleinfo(&locinfo, 1, langid, 0x46u, &lc_time->month_abbr[2]) | v20;
  v22 = __getlocaleinfo(&locinfo, 1, langid, 0x47u, &lc_time->month_abbr[3]) | v21;
  v23 = __getlocaleinfo(&locinfo, 1, langid, 0x48u, &lc_time->month_abbr[4]) | v22;
  v24 = __getlocaleinfo(&locinfo, 1, langid, 0x49u, &lc_time->month_abbr[5]) | v23;
  v25 = __getlocaleinfo(&locinfo, 1, langid, 0x4Au, &lc_time->month_abbr[6]) | v24;
  v26 = __getlocaleinfo(&locinfo, 1, langid, 0x4Bu, &lc_time->month_abbr[7]) | v25;
  v27 = __getlocaleinfo(&locinfo, 1, langid, 0x4Cu, &lc_time->month_abbr[8]) | v26;
  v28 = __getlocaleinfo(&locinfo, 1, langid, 0x4Du, &lc_time->month_abbr[9]) | v27;
  v29 = __getlocaleinfo(&locinfo, 1, langid, 0x4Eu, &lc_time->month_abbr[10]) | v28;
  v30 = __getlocaleinfo(&locinfo, 1, langid, 0x4Fu, &lc_time->month_abbr[11]) | v29;
  v31 = __getlocaleinfo(&locinfo, 1, langid, 0x38u, lc_time->month) | v30;
  v32 = __getlocaleinfo(&locinfo, 1, langid, 0x39u, &lc_time->month[1]) | v31;
  v33 = __getlocaleinfo(&locinfo, 1, langid, 0x3Au, &lc_time->month[2]) | v32;
  v34 = __getlocaleinfo(&locinfo, 1, langid, 0x3Bu, &lc_time->month[3]) | v33;
  v35 = __getlocaleinfo(&locinfo, 1, langid, 0x3Cu, &lc_time->month[4]) | v34;
  v36 = __getlocaleinfo(&locinfo, 1, langid, 0x3Du, &lc_time->month[5]) | v35;
  v37 = __getlocaleinfo(&locinfo, 1, langid, 0x3Eu, &lc_time->month[6]) | v36;
  v38 = __getlocaleinfo(&locinfo, 1, langid, 0x3Fu, &lc_time->month[7]) | v37;
  v39 = __getlocaleinfo(&locinfo, 1, langid, 0x40u, &lc_time->month[8]) | v38;
  v40 = __getlocaleinfo(&locinfo, 1, langid, 0x41u, &lc_time->month[9]) | v39;
  v41 = __getlocaleinfo(&locinfo, 1, langid, 0x42u, &lc_time->month[10]) | v40;
  v42 = __getlocaleinfo(&locinfo, 1, langid, 0x43u, &lc_time->month[11]) | v41;
  v43 = __getlocaleinfo(&locinfo, 1, langid, 0x28u, lc_time->ampm) | v42;
  v44 = __getlocaleinfo(&locinfo, 1, langid, 0x29u, &lc_time->ampm[1]) | v43;
  v45 = __getlocaleinfo(&locinfo, 1, ctryid, 0x1Fu, &lc_time->ww_sdatefmt) | v44;
  v46 = __getlocaleinfo(&locinfo, 1, ctryid, 0x20u, &lc_time->ww_ldatefmt) | v45;
  v47 = __getlocaleinfo(&locinfo, 1, ctryid, 0x1003u, &lc_time->ww_timefmt) | v46;
  v48 = ctryid;
  result = __getlocaleinfo(&locinfo, 0, ctryid, 0x1009u, (char **)&lc_time->ww_caltype) | v47;
  lc_time->ww_lcid = v48;
  return result;
}
