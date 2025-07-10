vostok::fs_new::virtual_path_string *__usercall stlp_std::priv::__copy<vostok::fs_new::virtual_path_string *,vostok::fs_new::virtual_path_string *,int>@<eax>(
        vostok::fs_new::virtual_path_string *__first@<ecx>,
        vostok::fs_new::virtual_path_string *__last@<eax>,
        vostok::fs_new::virtual_path_string *__result)
{
  vostok::fs_new::virtual_path_string *v4; // edi
  int i; // esi

  v4 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    vostok::fs_new::virtual_path_string::operator=(__result, v4);
    --i;
    ++v4;
  }
  return __result;
}
