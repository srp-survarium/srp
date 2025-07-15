mallinfo *__usercall vostok_mspace_mallinfo@<eax>(malloc_state *msp@<eax>, mallinfo *a2@<esi>)
{
  mallinfo v3; // [esp+0h] [ebp-2Ch] BYREF

  *a2 = *internal_mallinfo(&v3, msp);
  return a2;
}
