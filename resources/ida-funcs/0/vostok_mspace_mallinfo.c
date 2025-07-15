mallinfo *__usercall vostok_mspace_mallinfo@<eax>(malloc_state *msp@<edx>, mallinfo *a2)
{
  mallinfo *v2; // esi
  mallinfo *result; // eax
  mallinfo v4; // [esp+8h] [ebp-2Ch] BYREF

  v2 = internal_mallinfo(msp, &v4);
  result = a2;
  qmemcpy(a2, v2, sizeof(mallinfo));
  return result;
}
