void __usercall vostok::fs_new::virtual_path_string::virtual_path_string(
        vostok::fs_new::virtual_path_string *this@<ecx>,
        int a2@<eax>)
{
  vostok::fixed_string<260>::fixed_string<260>(&this->m_string, (vostok::buffer_string *)a2, (char *)uri);
  *(_BYTE *)(a2 + 272) = 47;
}


void __usercall vostok::fs_new::virtual_path_string::virtual_path_string(
        vostok::fs_new::virtual_path_string *this@<ecx>,
        char **other@<eax>)
{
  vostok::fixed_string<260>::fixed_string<260>(&this->m_string, &this->m_string, *other);
  this->m_separator = 47;
}


void __usercall vostok::fs_new::virtual_path_string::virtual_path_string(
        vostok::fs_new::virtual_path_string *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 272;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 272) = 47;
}
