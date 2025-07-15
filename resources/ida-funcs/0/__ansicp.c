unsigned int __usercall __ansicp@<eax>(int a1@<ebx>, LCID lcid)
{
  char LCData[8]; // [esp+0h] [ebp-Ch] BYREF

  LCData[6] = 0;
  if ( GetLocaleInfoA(lcid, 0x1004u, LCData, 6) )
    return atol(a1, LCData);
  else
    return -1;
}
