int __usercall close_console@<eax>(unsigned int a1@<edi>)
{
  if ( tty_in != __iob_func() )
    fclose(tty_in);
  if ( tty_out != &__iob_func()[2] )
    fclose(tty_out);
  CRYPTO_lock(a1, 10, 31, ".\\crypto\\ui\\ui_openssl.c", 576);
  return 1;
}
