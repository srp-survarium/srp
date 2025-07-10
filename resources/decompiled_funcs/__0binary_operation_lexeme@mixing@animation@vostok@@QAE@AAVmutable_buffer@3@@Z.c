void __usercall vostok::animation::mixing::binary_operation_lexeme::binary_operation_lexeme(
        vostok::animation::mixing::binary_operation_lexeme *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)a2 = this;
  *(_BYTE *)(a2 + 4) = 0;
}
