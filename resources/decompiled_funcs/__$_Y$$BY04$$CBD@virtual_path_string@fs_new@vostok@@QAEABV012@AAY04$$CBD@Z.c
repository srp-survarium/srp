const vostok::fs_new::virtual_path_string *__usercall vostok::fs_new::virtual_path_string::operator+=<char const [5]>@<eax>(
        vostok::fs_new::virtual_path_string *this@<ecx>,
        int a2@<esi>)
{
  unsigned int v2; // edi

  v2 = strlen(".dds");
  memcpy(*(unsigned __int8 **)(a2 + 4), ".dds", v2);
  *(_DWORD *)(a2 + 4) += v2;
  **(_BYTE **)(a2 + 4) = 0;
  return (const vostok::fs_new::virtual_path_string *)a2;
}
