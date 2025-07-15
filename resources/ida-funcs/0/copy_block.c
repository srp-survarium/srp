void __usercall copy_block(internal_state *s@<eax>, char *buf@<edx>, unsigned int len@<ecx>, int header)
{
  _DWORD *v6; // eax

  bi_windup(s);
  v6[1453] = 8;
  if ( header )
  {
    *(_BYTE *)(v6[5] + v6[2]) = len;
    ++v6[5];
    *(_BYTE *)(v6[2] + v6[5]++) = BYTE1(len);
    *(_BYTE *)(v6[2] + v6[5]++) = ~(_BYTE)len;
    *(_BYTE *)(v6[2] + v6[5]++) = (unsigned __int16)~(_WORD)len >> 8;
  }
  for ( ; len; ++buf )
  {
    *(_BYTE *)(v6[5] + v6[2]) = *buf;
    --len;
    ++v6[5];
  }
}
