void __thiscall vostok::core::core_debug_engine::generate_debug_file_name(
        vostok::core::core_debug_engine *this,
        char (*file_name)[260],
        const _SYSTEMTIME *const date_time,
        const char *report_id,
        const char *extension)
{
  const char *v5; // edi
  const char *v6; // ebp
  const char *v7; // ebx
  const char *v8; // esi
  unsigned int v9; // eax
  int v10; // [esp-1Ch] [ebp-2Ch]
  int wMonth; // [esp-18h] [ebp-28h]
  int wDay; // [esp-14h] [ebp-24h]
  int wHour; // [esp-10h] [ebp-20h]
  int wMinute; // [esp-Ch] [ebp-1Ch]
  int wSecond; // [esp-8h] [ebp-18h]

  v5 = (const char *)vostok::core::application_name();
  v6 = "_";
  if ( !*report_id )
    v6 = (const char *)&buf;
  v7 = "-#";
  if ( !*v5 )
    v7 = "#";
  v8 = s_engine_0->get_user_data_directory(s_engine_0);
  wSecond = date_time->wSecond;
  wMinute = date_time->wMinute;
  wHour = date_time->wHour;
  wDay = date_time->wDay;
  wMonth = date_time->wMonth;
  v10 = date_time->wYear % 100;
  v9 = vostok::build::build_station_build_id();
  sprintf_s<260>(
    file_name,
    "%s/%s%s%d%s%s%s%02d%02d%02d-%02d%02d%02d%s",
    v8,
    v5,
    v7,
    v9,
    "_",
    report_id,
    v6,
    v10,
    wMonth,
    wDay,
    wHour,
    wMinute,
    wSecond,
    extension);
}
