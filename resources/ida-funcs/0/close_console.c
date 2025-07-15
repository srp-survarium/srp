int __usercall close_console@<eax>(int a1@<edi>, int a2@<ebx>)
{
  if ( tty_in != __iob_func() )
    fclose(a2, tty_in);
  if ( tty_out != &__iob_func()[2] )
    fclose(a2, tty_out);
  CRYPTO_lock(a1, a2, 10, 31, ".\\crypto\\ui\\ui_openssl.c", 576);
  return 1;
}
