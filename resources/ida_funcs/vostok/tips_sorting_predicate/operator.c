bool __userpurge vostok::tips_sorting_predicate::operator()@<al>(
        char *s2@<edi>,
        vostok::tips_sorting_predicate *this,
        char *s1)
{
  int v3; // eax
  int v4; // esi
  int v5; // eax

  strstr((unsigned __int8 *)s1, (unsigned __int8 *)this->editor_str);
  v4 = v3;
  strstr((unsigned __int8 *)s2, (unsigned __int8 *)this->editor_str);
  return v4 - (int)s1 < v5 - (int)s2;
}
