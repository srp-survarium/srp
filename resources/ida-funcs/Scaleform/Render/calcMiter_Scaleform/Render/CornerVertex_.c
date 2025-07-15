void __usercall Scaleform::Render::calcMiter_Scaleform::Render::CornerVertex_(
        float *x@<edi>,
        float *y@<esi>,
        const Scaleform::Render::CornerVertex v0,
        Scaleform::Render::CornerVertex v1,
        const Scaleform::Render::CornerVertex v2,
        float width)
{
  double v6; // st3
  float ay; // [esp+4h] [ebp-44h]
  float v8; // [esp+8h] [ebp-40h]
  float by; // [esp+Ch] [ebp-3Ch]
  float v10; // [esp+10h] [ebp-38h]
  float cy; // [esp+14h] [ebp-34h]
  float v12; // [esp+18h] [ebp-30h]
  float dy; // [esp+1Ch] [ebp-2Ch]
  float v14; // [esp+2Ch] [ebp-1Ch]
  float v15; // [esp+2Ch] [ebp-1Ch]
  float v16; // [esp+2Ch] [ebp-1Ch]
  float v17; // [esp+30h] [ebp-18h]
  float v18; // [esp+30h] [ebp-18h]
  float v19; // [esp+30h] [ebp-18h]
  float v20; // [esp+30h] [ebp-18h]
  float v21; // [esp+30h] [ebp-18h]
  float v22; // [esp+30h] [ebp-18h]
  float v23; // [esp+34h] [ebp-14h]
  float v24; // [esp+34h] [ebp-14h]
  double v25; // [esp+38h] [ebp-10h]
  double v26; // [esp+40h] [ebp-8h]
  float v27; // [esp+64h] [ebp+1Ch]
  float v28; // [esp+64h] [ebp+1Ch]
  float v29; // [esp+64h] [ebp+1Ch]
  float v30; // [esp+64h] [ebp+1Ch]
  float v31; // [esp+64h] [ebp+1Ch]
  float v32; // [esp+64h] [ebp+1Ch]
  float v33; // [esp+64h] [ebp+1Ch]
  float v34; // [esp+64h] [ebp+1Ch]
  float v35; // [esp+64h] [ebp+1Ch]

  v17 = v1.x - v0.x;
  v25 = v1.y - v0.y;
  v14 = v25;
  v18 = v14 * v14 + v17 * v17;
  v19 = sqrt(v18);
  v23 = v19;
  v15 = v2.x - v1.x;
  v26 = v2.y - v1.y;
  v20 = v26;
  v21 = v20 * v20 + v15 * v15;
  v22 = sqrt(v21);
  *(float *)&v25 = v25 * width / v23;
  v16 = (v0.x - v1.x) * width / v23;
  v24 = width * v26 / v22;
  v27 = width * (v1.x - v2.x) / v22;
  *(Scaleform::Render::CornerVertex *)x = v1;
  v6 = v27;
  v28 = v27 + v2.y;
  dy = v28;
  v29 = v2.x + v24;
  v12 = v29;
  v30 = v6 + v1.y;
  cy = v30;
  v31 = v24 + v1.x;
  v10 = v31;
  v32 = v1.y + v16;
  by = v32;
  v33 = v1.x + *(float *)&v25;
  v8 = v33;
  v34 = v16 + v0.y;
  ay = v34;
  v35 = *(float *)&v25 + v0.x;
  Scaleform::Render::Math2D::Intersection(v35, ay, v8, by, v10, cy, v12, dy, x, y, 0.001);
}
