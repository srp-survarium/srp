void __userpurge vostok::math::float3_pod::set_length(
        vostok::math::float3_pod *this@<ecx>,
        float *a2@<esi>,
        float length)
{
  long double v3; // st7
  long double v4; // st6
  float v5; // [esp+4h] [ebp-4h]
  float lengtha; // [esp+Ch] [ebp+4h]

  v5 = *a2;
  v3 = length / sqrtf((float)((float)(a2[2] * a2[2]) + (float)(*a2 * *a2)) + (float)(a2[1] * a2[1]));
  lengtha = v3;
  v4 = v3 * a2[1];
  *a2 = v5 * lengtha;
  a2[1] = v4;
  a2[2] = v3 * a2[2];
}
