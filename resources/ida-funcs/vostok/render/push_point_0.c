int __usercall vostok::render::push_point_0@<eax>(
        int a1@<eax>,
        _DWORD *a2@<edx>,
        int a3@<xmm0>,
        float y,
        unsigned int c,
        float u,
        float v)
{
  int result; // eax

  result = *a2 + 28 * a1;
  *(_DWORD *)result = a3;
  *(float *)(result + 4) = y;
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 12) = clear_value;
  *(float *)(result + 20) = u;
  *(float *)(result + 24) = v;
  *(_DWORD *)(result + 16) = c;
  return result;
}
