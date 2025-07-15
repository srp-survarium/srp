BOOL __fastcall vostok::math::operator==(const vostok::math::float3_pod *right, const vostok::math::float3_pod *left)
{
  return left->x == right->x && left->y == right->y && left->z == right->z;
}


vostok::math::float3 *__usercall vostok::math::operator*@<eax>(
        const vostok::math::float3_pod *right@<ecx>,
        vostok::math::float3 *result@<eax>,
        float *value)
{
  float v3; // xmm0_4

  v3 = *value;
  result->x = *value * right->x;
  result->y = right->y * v3;
  result->z = right->z * v3;
  return result;
}


vostok::math::float3 *__usercall vostok::math::operator*@<eax>(
        const vostok::math::float3_pod *left@<ecx>,
        vostok::math::float3 *result@<eax>,
        float *value)
{
  float v3; // xmm0_4

  v3 = *value;
  result->x = left->x * *value;
  result->y = left->y * v3;
  result->z = left->z * v3;
  return result;
}


vostok::math::float4 *__usercall vostok::math::operator*@<eax>(
        const vostok::math::float4_pod *left@<ecx>,
        vostok::math::float4 *result@<eax>,
        float *value)
{
  float v3; // xmm0_4

  v3 = *value;
  result->x = left->x * *value;
  result->y = left->y * v3;
  result->z = left->z * v3;
  result->w = left->w * v3;
  return result;
}


vostok::math::float4x4 *__cdecl vostok::math::operator*(
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *left,
        const vostok::math::float4x4 *right)
{
  vostok::math::mul4x3(result, left, right);
  return result;
}


vostok::math::float2 *__fastcall vostok::math::operator-(
        const vostok::math::float2_pod *right,
        const vostok::math::float2_pod *left,
        vostok::math::float2 *a3)
{
  vostok::math::float2 *result; // eax

  result = a3;
  a3->x = left->x - right->x;
  a3->y = left->y - right->y;
  return result;
}


vostok::math::float3 *__fastcall vostok::math::operator-(
        const vostok::math::float3_pod *right,
        const vostok::math::float3_pod *left,
        vostok::math::float3 *a3)
{
  vostok::math::float3 *result; // eax

  result = a3;
  a3->x = left->x - right->x;
  a3->y = left->y - right->y;
  a3->z = left->z - right->z;
  return result;
}


vostok::math::float3 *__fastcall vostok::math::operator+(
        const vostok::math::float3_pod *right,
        const vostok::math::float3_pod *left,
        vostok::math::float3 *a3)
{
  vostok::math::float3 *result; // eax

  result = a3;
  a3->x = left->x + right->x;
  a3->y = left->y + right->y;
  a3->z = left->z + right->z;
  return result;
}


vostok::math::float4 *__cdecl vostok::math::operator+(
        vostok::math::float4 *result,
        const vostok::math::float4_pod *left,
        const vostok::math::float4_pod *right)
{
  vostok::math::float4 *v3; // eax

  v3 = result;
  result->x = left->x + right->x;
  result->y = left->y + right->y;
  result->z = left->z + right->z;
  result->w = left->w + right->w;
  return v3;
}


BOOL __usercall vostok::math::operator<@<eax>(
        const vostok::math::float3_pod *left@<ecx>,
        const vostok::math::float3_pod *right@<eax>)
{
  return right->x > left->x && right->y > left->y && right->z > left->z;
}


BOOL __usercall vostok::math::operator<@<eax>(
        const vostok::math::float4_pod *left@<ecx>,
        const vostok::math::float4_pod *right@<eax>)
{
  return right->x > left->x && right->y > left->y && right->z > left->z && right->w > left->w;
}


BOOL __usercall vostok::math::operator<=@<eax>(
        const vostok::math::float3_pod *left@<ecx>,
        const vostok::math::float3_pod *right@<eax>)
{
  return right->x >= left->x && right->y >= left->y && right->z >= left->z;
}


BOOL __usercall vostok::math::operator>@<eax>(
        const vostok::math::float3_pod *left@<ecx>,
        const vostok::math::float3_pod *right@<eax>)
{
  return left->x > right->x && left->y > right->y && left->z > right->z;
}


BOOL __usercall vostok::math::operator>@<eax>(
        const vostok::math::float4_pod *left@<ecx>,
        const vostok::math::float4_pod *right@<eax>)
{
  return left->x > right->x && left->y > right->y && left->z > right->z && left->w > right->w;
}


BOOL __usercall vostok::math::operator>=@<eax>(
        const vostok::math::float3_pod *left@<ecx>,
        const vostok::math::float3_pod *right@<eax>)
{
  return left->x >= right->x && left->y >= right->y && left->z >= right->z;
}


vostok::math::float3 *__fastcall vostok::math::operator^(
        const vostok::math::float3_pod *right,
        const vostok::math::float3_pod *left,
        vostok::math::float3 *a3)
{
  float z; // xmm3_4
  float v4; // xmm4_4
  float y; // xmm5_4
  float v6; // xmm2_4
  vostok::math::float3 *result; // eax
  float x; // xmm1_4
  float v9; // xmm0_4

  z = right->z;
  v4 = left->z;
  y = right->y;
  v6 = left->y;
  result = a3;
  x = right->x;
  a3->x = (float)(z * v6) - (float)(y * v4);
  v9 = (float)(left->x * y) - (float)(x * v6);
  a3->y = (float)(x * v4) - (float)(left->x * z);
  a3->z = v9;
  return result;
}


float __usercall vostok::math::operator|@<xmm0>(
        const vostok::math::float3_pod *left@<ecx>,
        const vostok::math::float3_pod *right@<eax>)
{
  return (float)((float)(left->z * right->z) + (float)(left->y * right->y)) + (float)(left->x * right->x);
}
