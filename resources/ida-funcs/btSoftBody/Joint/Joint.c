void __usercall btSoftBody::Joint::Joint(btSoftBody::Joint *this@<ecx>, int a2@<eax>)
{
  _DWORD *v2; // ecx
  int i; // edx

  *(_DWORD *)a2 = &btSoftBody::Joint::`vftable';
  v2 = (_DWORD *)(a2 + 16);
  for ( i = 1; i >= 0; --i )
  {
    *v2 = 0;
    v2[1] = 0;
    v2[2] = 0;
    v2 += 3;
  }
  *(_BYTE *)(a2 + 176) = 0;
}
