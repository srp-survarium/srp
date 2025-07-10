void __usercall btRigidBody::applyGravity(btRigidBody *this@<ecx>, int a2@<eax>)
{
  float v2; // xmm2_4
  float v3; // xmm3_4
  float v4; // xmm0_4

  if ( (*(_BYTE *)(a2 + 216) & 3) == 0 )
  {
    v2 = *(float *)(a2 + 376) * *(float *)(a2 + 392);
    v3 = *(float *)(a2 + 432) + (float)(*(float *)(a2 + 368) * *(float *)(a2 + 384));
    *(float *)(a2 + 436) = *(float *)(a2 + 436) + (float)(*(float *)(a2 + 372) * *(float *)(a2 + 388));
    v4 = *(float *)(a2 + 440) + v2;
    *(float *)(a2 + 432) = v3;
    *(float *)(a2 + 440) = v4;
  }
}
