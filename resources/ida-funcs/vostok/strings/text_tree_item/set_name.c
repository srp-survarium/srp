void __userpurge vostok::strings::text_tree_item::set_name(
        vostok::strings::text_tree_item *this@<ecx>,
        int a2@<edi>,
        char *s)
{
  int v3; // ecx
  unsigned int v4; // eax
  unsigned __int8 *v5; // esi

  if ( *(_DWORD *)(a2 + 104) )
    *(_DWORD *)(a2 + 104) = 0;
  if ( s )
  {
    v3 = *(_DWORD *)(a2 + 108);
    v4 = strlen(s);
    v5 = *(unsigned __int8 **)(v3 + 20);
    *(_DWORD *)(v3 + 20) = &v5[v4 + 1];
    memcpy(v5, (unsigned __int8 *)s, v4 + 1);
    *(_DWORD *)(a2 + 104) = v5;
  }
}
