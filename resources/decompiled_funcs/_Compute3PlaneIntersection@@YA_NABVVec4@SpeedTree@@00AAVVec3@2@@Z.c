char __cdecl Compute3PlaneIntersection(
        const struct SpeedTree::Vec4 *a1,
        const struct SpeedTree::Vec4 *a2,
        const struct SpeedTree::Vec4 *a3,
        struct SpeedTree::Vec3 *a4)
{
  const struct SpeedTree::Vec3 *v4; // eax
  SpeedTree::Vec3 *v5; // eax
  SpeedTree::Vec3 *v6; // eax
  SpeedTree::Vec3 *v7; // eax
  float *v8; // eax
  float *v9; // eax
  float v11; // [esp+0h] [ebp-148h]
  float v12; // [esp+8h] [ebp-140h]
  float *v13; // [esp+8h] [ebp-140h]
  float x_4; // [esp+10h] [ebp-138h]
  float *x_4a; // [esp+10h] [ebp-138h]
  float v16; // [esp+14h] [ebp-134h]
  float v17; // [esp+18h] [ebp-130h]
  float v18[3]; // [esp+94h] [ebp-B4h] BYREF
  float v19[3]; // [esp+A0h] [ebp-A8h] BYREF
  SpeedTree::Vec3 v20; // [esp+ACh] [ebp-9Ch] BYREF
  float v21[3]; // [esp+B8h] [ebp-90h] BYREF
  float v22[3]; // [esp+C4h] [ebp-84h] BYREF
  SpeedTree::Vec3 v23; // [esp+D0h] [ebp-78h] BYREF
  float v24[3]; // [esp+DCh] [ebp-6Ch] BYREF
  SpeedTree::Vec3 v25; // [esp+E8h] [ebp-60h] BYREF
  SpeedTree::Vec3 result; // [esp+F4h] [ebp-54h] BYREF
  float v27[3]; // [esp+100h] [ebp-48h] BYREF
  SpeedTree::Vec3 v28; // [esp+10Ch] [ebp-3Ch] BYREF
  SpeedTree::Vec3 vIn; // [esp+118h] [ebp-30h] BYREF
  SpeedTree::Vec3 v30; // [esp+124h] [ebp-24h] BYREF
  char v31; // [esp+133h] [ebp-15h]
  float v32; // [esp+134h] [ebp-14h]
  float v33; // [esp+138h] [ebp-10h]
  float v34; // [esp+13Ch] [ebp-Ch]
  float w; // [esp+140h] [ebp-8h]
  float v36; // [esp+144h] [ebp-4h]

  v31 = 0;
  v32 = 0.0000001;
  v28.x = a1->x;
  v28.y = a1->y;
  v28.z = a1->z;
  v30.x = a2->x;
  v30.y = a2->y;
  v30.z = a2->z;
  vIn.x = a3->x;
  vIn.y = a3->y;
  vIn.z = a3->z;
  w = a1->w;
  v36 = a2->w;
  v33 = a3->w;
  v4 = SpeedTree::Vec3::Cross(&v30, &result, &vIn);
  v34 = SpeedTree::Vec3::Dot(&v28, v4);
  v17 = fabs(v34);
  if ( v32 < (double)v17 )
  {
    x_4 = v33;
    v5 = SpeedTree::Vec3::Cross(&v28, &v20, &v30);
    x_4a = SpeedTree::Vec3::operator*(&v5->x, v19, x_4);
    v12 = v36;
    v6 = SpeedTree::Vec3::Cross(&vIn, &v23, &v28);
    v13 = SpeedTree::Vec3::operator*(&v6->x, v22, v12);
    v11 = w;
    v7 = SpeedTree::Vec3::Cross(&v30, &v25, &vIn);
    v8 = SpeedTree::Vec3::operator*(&v7->x, v24, v11);
    v9 = SpeedTree::Vec3::operator+(v8, v21, v13);
    SpeedTree::Vec3::operator+(v9, v27, x_4a);
    v16 = -1.0 / v34;
    *a4 = *(struct SpeedTree::Vec3 *)SpeedTree::Vec3::operator*(v27, v18, v16);
    return 1;
  }
  return v31;
}
