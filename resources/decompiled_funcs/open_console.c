int __usercall open_console@<eax>(unsigned int a1@<edi>)
{
  CRYPTO_lock(a1, 9, 31, ".\\crypto\\ui\\ui_openssl.c", 478);
  is_a_tty = 1;
  tty_in = fopen((_iobuf *)"con", "r");
  if ( !tty_in )
    tty_in = __iob_func();
  tty_out = fopen((_iobuf *)"con", "w");
  if ( !tty_out )
    tty_out = __iob_func() + 2;
  return 1;
}
