BOOL __usercall vostok::animation::mixing::expression::is_empty@<eax>(
        vostok::animation::mixing::expression *this@<ecx>,
        _DWORD *a2@<eax>)
{
  return !*a2 || !a2[1];
}
