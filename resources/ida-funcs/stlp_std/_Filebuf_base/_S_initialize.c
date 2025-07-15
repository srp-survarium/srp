void stlp_std::_Filebuf_base::_S_initialize()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(&SystemInfo);
  stlp_std::_Filebuf_base::_M_page_size = SystemInfo.dwPageSize;
}
