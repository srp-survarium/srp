void __usercall putShortMSB(internal_state *s@<eax>, __int16 b@<cx>)
{
  int dummy; // edi

  *(_BYTE *)(s[2].dummy + s[5].dummy) = HIBYTE(b);
  dummy = s[2].dummy;
  *(_BYTE *)(++s[5].dummy + dummy) = b;
  ++s[5].dummy;
}
