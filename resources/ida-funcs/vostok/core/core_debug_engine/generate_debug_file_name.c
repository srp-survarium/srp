void __thiscall vostok::core::core_debug_engine::generate_debug_file_name(
        vostok::core::core_debug_engine *this,
        char (*file_name)[260],
        const _SYSTEMTIME *const date_time,
        const char *report_id,
        const char *extension)
{
  char *v5; // ebx
  const char *v6; // edi
  unsigned int v7; // eax
  int v8; // [esp-1Ch] [ebp-30h]
  int wMonth; // [esp-18h] [ebp-2Ch]
  int wDay; // [esp-14h] [ebp-28h]
  int wHour; // [esp-10h] [ebp-24h]
  int wMinute; // [esp-Ch] [ebp-20h]
  int wSecond; // [esp-8h] [ebp-1Ch]
  const char *v14; // [esp+Ch] [ebp-8h]
  const char *v15; // [esp+10h] [ebp-4h]

  v5 = vostok::core::application_name();
  v15 = "_";
  if ( !*report_id )
    v15 = uri;
  v14 = "-#";
  if ( !*v5 )
    v14 = "#";
  v6 = s_engine_0->get_user_data_directory(s_engine_0);
  wSecond = date_time->wSecond;
  wMinute = date_time->wMinute;
  wHour = date_time->wHour;
  wDay = date_time->wDay;
  wMonth = date_time->wMonth;
  v8 = date_time->wYear % 100;
  v7 = vostok::build::build_station_build_id();
  sprintf_s<260>(
    file_name,
    "%s/%s%s%d%s%s%s%02d%02d%02d-%02d%02d%02d%s",
    v6,
    v5,
    v14,
    v7,
    "_",
    report_id,
    v15,
    v8,
    wMonth,
    wDay,
    wHour,
    wMinute,
    wSecond,
    extension);
}
