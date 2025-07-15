void __usercall _mbspbrk(int a1@<edi>, unsigned __int8 *string, unsigned __int8 *charset)
{
  _mbspbrk_l(a1, string, charset, 0);
}
