void __usercall vostok::render::state_descriptor::reset(vostok::render::state_descriptor *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // edx
  _DWORD *v3; // eax

  *((_BYTE *)a2 + 360) = 0;
  *((_BYTE *)a2 + 361) = 0;
  *((_BYTE *)a2 + 362) = 0;
  memset(a2, 0, 0x28u);
  *a2 = 3;
  a2[1] = 3;
  a2[2] = 0;
  a2[3] = 0;
  *((_QWORD *)a2 + 2) = 0;
  a2[6] = 1;
  a2[7] = 1;
  a2[8] = 0;
  a2[9] = 0;
  memset((int)(a2 + 10), 0, 0x34u);
  a2[10] = 1;
  a2[11] = 0;
  a2[12] = 4;
  a2[13] = 0;
  *((_BYTE *)a2 + 56) = 127;
  *((_BYTE *)a2 + 57) = 127;
  a2[15] = 1;
  a2[16] = 1;
  a2[17] = 1;
  a2[18] = 8;
  a2[19] = 1;
  a2[20] = 1;
  a2[21] = 1;
  a2[22] = 8;
  memset((int)(a2 + 23), 0, 0x108u);
  v2 = 8;
  a2[23] = 0;
  a2[24] = 0;
  v3 = a2 + 26;
  do
  {
    *(v3 - 1) = 0;
    *v3 = 2;
    v3[1] = 1;
    v3[2] = 1;
    v3[3] = 2;
    v3[4] = 1;
    v3[5] = 1;
    *((_BYTE *)v3 + 24) = 15;
    v3 += 8;
    --v2;
  }
  while ( v2 );
  a2[89] = 0;
}
