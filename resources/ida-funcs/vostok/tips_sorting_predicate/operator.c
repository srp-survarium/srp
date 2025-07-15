bool __userpurge vostok::tips_sorting_predicate::operator()@<al>(
        vostok::tips_sorting_predicate *this@<ecx>,
        unsigned __int8 **a2@<edi>,
        char *s1,
        char *s2)
{
  int v4; // eax
  int v5; // esi
  int v6; // eax

  strstr((unsigned __int8 *)s1, *a2);
  v5 = v4;
  strstr((unsigned __int8 *)s2, *a2);
  return v5 - (int)s1 < v6 - (int)s2;
}
