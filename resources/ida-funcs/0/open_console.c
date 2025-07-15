int __usercall open_console@<eax>(int a1@<edi>, int a2@<ebx>, const char *a3@<esi>)
{
  CRYPTO_lock(a1, a2, 9, 31, ".\\crypto\\ui\\ui_openssl.c", 478);
  is_a_tty = 1;
  tty_in = fopen(a3, "con", "r");
  if ( !tty_in )
    tty_in = __iob_func();
  tty_out = fopen(a3, "con", "w");
  if ( !tty_out )
    tty_out = __iob_func() + 2;
  return 1;
}
