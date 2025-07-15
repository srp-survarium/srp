char __thiscall vostok::journaling::keyboard::get_dik_name(
        vostok::journaling::keyboard *this,
        int dik,
        char *dest_str,
        unsigned int dest_sz)
{
  strcpy_s(dest_str, dest_sz, uri);
  return 1;
}
