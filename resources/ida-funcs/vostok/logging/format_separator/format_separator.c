void __userpurge vostok::logging::format_separator::format_separator(
        vostok::logging::format_separator *this@<ecx>,
        int a2@<esi>,
        char *separator)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 7;
  vostok::strings::copy<128>((char (*)[128])(a2 + 12), separator);
}
