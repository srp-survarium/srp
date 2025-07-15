unsigned __int8 *__cdecl calloc(unsigned int count, unsigned int element_size)
{
  void *v2; // edi

  v2 = malloc(element_size * count);
  memset((int)v2, 0, element_size * count);
  return (unsigned __int8 *)v2;
}
