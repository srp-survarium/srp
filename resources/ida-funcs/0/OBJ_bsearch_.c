char *__cdecl OBJ_bsearch_(
        const void *key,
        char *base,
        int num,
        int size,
        int (__cdecl *cmp)(const void *, const void *))
{
  return OBJ_bsearch_ex_(key, base, num, size, cmp, 0);
}
