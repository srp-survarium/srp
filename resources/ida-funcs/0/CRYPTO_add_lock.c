int __cdecl CRYPTO_add_lock(int *pointer, int amount, int type, const char *file, int line)
{
  int v6; // esi

  if ( add_lock_callback )
    return add_lock_callback(pointer, amount, type, file, line);
  CRYPTO_lock(line, 9, type, file, line);
  v6 = amount + *pointer;
  *pointer = v6;
  CRYPTO_lock(line, 10, type, file, line);
  return v6;
}
