void __cdecl jpeg_free_small(void *opaque, void *ptr)
{
  free(ptr);
}
