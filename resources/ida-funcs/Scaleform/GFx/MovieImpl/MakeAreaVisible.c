void __thiscall Scaleform::GFx::MovieImpl::MakeAreaVisible(
        Scaleform::GFx::MovieImpl *this,
        __m128 *screenRect,
        const Scaleform::Render::Rect<float> *box,
        char flags)
{
  double v4; // st7
  const Scaleform::Render::Matrix2x4<float> *v5; // ecx
  Scaleform::Render::Matrix2x4<float> *v6; // ebx
  double v7; // st6
  long double v8; // st5
  double y2; // st4
  double y1; // st3
  double x1; // st7
  double v12; // st5
  double v13; // st4
  long double v14; // st7
  double v15; // st5
  long double v16; // st7
  double v17; // st6
  double v18; // rt1
  long double v19; // st4
  long double v20; // rt1
  double v21; // st4
  double v22; // rt0
  double v23; // st4
  double v24; // st6
  double v25; // st7
  double x2; // st6
  double v27; // st5
  double v28; // st4
  double v29; // st7
  double v30; // st5
  double v31; // st7
  double v32; // st6
  double v33; // st5
  double v34; // st4
  double v35; // st3
  double v36; // st6
  float v37; // [esp+18h] [ebp-A8h]
  float v38; // [esp+18h] [ebp-A8h]
  float v39; // [esp+18h] [ebp-A8h]
  float v40; // [esp+18h] [ebp-A8h]
  float v41; // [esp+18h] [ebp-A8h]
  float v42; // [esp+18h] [ebp-A8h]
  float v43; // [esp+18h] [ebp-A8h]
  float v44; // [esp+1Ch] [ebp-A4h]
  float v45; // [esp+1Ch] [ebp-A4h]
  float v46; // [esp+1Ch] [ebp-A4h]
  float v47; // [esp+20h] [ebp-A0h]
  float v48; // [esp+20h] [ebp-A0h]
  float v49; // [esp+20h] [ebp-A0h]
  float v50; // [esp+24h] [ebp-9Ch]
  float v51; // [esp+28h] [ebp-98h]
  float v52; // [esp+28h] [ebp-98h]
  float v53; // [esp+2Ch] [ebp-94h]
  float v54; // [esp+2Ch] [ebp-94h]
  Scaleform::Render::Rect<float> pr; // [esp+30h] [ebp-90h] BYREF
  Scaleform::Render::Rect<float> v56; // [esp+40h] [ebp-80h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+50h] [ebp-70h] BYREF
  long double v58; // [esp+78h] [ebp-48h]
  Scaleform::Render::Rect<float> v59; // [esp+80h] [ebp-40h] BYREF
  Scaleform::GFx::MovieImpl *v60; // [esp+9Ch] [ebp-24h]
  Scaleform::Render::Matrix2x4<float> v61; // [esp+A0h] [ebp-20h] BYREF

  v4 = screenRect->m128_f32[2];
  v60 = this;
  if ( box->x2 > v4
    || box->y2 > (double)screenRect->m128_f32[3]
    || box->x1 < (double)screenRect->m128_f32[0]
    || box->y1 < (double)screenRect->m128_f32[1] )
  {
    v61.M[0][0] = 1.0;
    v61.M[0][1] = 0.0;
    v61.M[0][2] = 0.0;
    v61.M[0][3] = 0.0;
    v61.M[1][0] = 0.0;
    v61.M[1][2] = 0.0;
    v61.M[1][3] = 0.0;
    v61.M[1][1] = 1.0;
    Scaleform::GFx::MovieImpl::ResetViewportMatrix(this);
    v6 = (Scaleform::Render::Matrix2x4<float> *)&v5[6];
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v61, v5 + 6);
    pr.x1 = 0.0;
    pr.y1 = 0.0;
    pr.x2 = 0.0;
    pr.y2 = 0.0;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v61, (__m128 *)&pr, screenRect);
    v56.x1 = box->x1 * 20.0;
    v56.y1 = box->y1 * 20.0;
    v56.x2 = box->x2 * 20.0;
    v56.y2 = 20.0 * box->y2;
    v7 = 1.0;
    v8 = 1.0;
    v58 = 1.0;
    y2 = pr.y2;
    y1 = v56.y1;
    if ( (flags & 1) == 0 )
    {
      v51 = v56.x2 - v56.x1;
      v53 = pr.x2 - pr.x1;
      if ( v53 < (double)v51 )
        v7 = v53 / v51;
      v44 = v56.y2 - y1;
      v47 = y2 - pr.y1;
      if ( v47 < (double)v44 )
      {
        v58 = v47 / v44;
        v8 = v58;
      }
    }
    if ( (flags & 2) != 0 && 1.0 == v7 )
    {
      x1 = v56.x1;
      if ( 1.0 == v8 )
      {
        v12 = v56.y1;
        v48 = y2 - pr.y1;
        v54 = pr.x2 - pr.x1;
        v45 = v48 * v54;
        v13 = v45;
        v52 = v56.x2 - x1;
        v46 = v56.y2 - y1;
        v37 = v46 * v52;
        if ( v37 + v37 >= v13 )
        {
          v19 = v58;
        }
        else
        {
          v58 = v13 * 0.5;
          v14 = sqrt(v52 / v46 * v58);
          v15 = v14 / v52;
          v16 = v58 / v14 / v46;
          if ( v54 >= v52 * v15 )
          {
            v17 = v46;
          }
          else
          {
            v15 = v54 / v52;
            v17 = v46;
          }
          if ( v48 >= v17 * v16 )
          {
            v7 = v15;
            v12 = v56.y1;
            v19 = v16;
            x1 = v56.x1;
          }
          else
          {
            v18 = v15;
            v12 = v56.y1;
            x1 = v56.x1;
            v19 = v48 / v17;
            v7 = v18;
          }
        }
        v20 = v19;
        v21 = v12;
        v8 = v20;
LABEL_21:
        m.M[0][3] = 0.0 - x1;
        m.M[1][3] = 0.0 - v21;
        if ( v7 < v8 )
          v8 = v7;
        v22 = v21;
        v38 = v8;
        v23 = v38;
        m.M[0][0] = v38;
        v24 = v38;
        v39 = 0.0 * v38;
        m.M[0][1] = v39;
        m.M[0][2] = v39;
        m.M[0][3] = m.M[0][3] * v23;
        m.M[1][0] = v39;
        m.M[1][2] = v39;
        m.M[1][1] = v24;
        m.M[1][3] = v23 * m.M[1][3];
        m.M[0][3] = x1 + m.M[0][3];
        m.M[1][3] = v22 + m.M[1][3];
        v59.x1 = 0.0;
        v59.y1 = 0.0;
        v59.x2 = 0.0;
        v59.y2 = 0.0;
        Scaleform::Render::Matrix2x4<float>::EncloseTransform(&m, (__m128 *)&v59, (__m128 *)&v56);
        v49 = 0.0;
        v50 = 0.0;
        v25 = v59.x1;
        x2 = pr.x2;
        v27 = pr.x1;
        v28 = v59.x2;
        if ( pr.x2 >= (double)v59.x1 && v28 >= v27 && v28 <= x2 )
        {
          if ( v59.x1 >= v27 )
            goto LABEL_34;
          v28 = v59.x2;
          v25 = v59.x1;
        }
        if ( (flags & 4) == 0 )
        {
          v40 = v28 - v25;
          v29 = v25 + v40 * 0.5;
          v41 = x2 - v27;
          v30 = v29;
          v31 = 0.5;
          v49 = v30 - (x2 - v41 * 0.5);
LABEL_35:
          v32 = v59.y1;
          v33 = pr.y2;
          v34 = pr.y1;
          v35 = v59.y2;
          if ( pr.y2 >= (double)v59.y1 && v35 >= v34 && v35 <= v33 )
          {
            if ( v59.y1 >= v34 )
            {
LABEL_43:
              m.M[0][3] = m.M[0][3] - v49;
              m.M[1][3] = m.M[1][3] - v50;
              Scaleform::Render::Matrix2x4<float>::Prepend(v6, &m);
              Scaleform::Render::TreeNode::SetMatrix(v60->pRenderRoot.pObject, v6);
              return;
            }
            v35 = v59.y2;
            v32 = v59.y1;
          }
          if ( (flags & 4) != 0 )
          {
            v50 = v32 - v34;
          }
          else
          {
            v42 = v35 - v32;
            v36 = v32 + v42 * v31;
            v43 = v33 - v34;
            v50 = v36 - (v33 - v31 * v43);
          }
          goto LABEL_43;
        }
        v49 = v25 - v27;
LABEL_34:
        v31 = 0.5;
        goto LABEL_35;
      }
    }
    else
    {
      x1 = v56.x1;
    }
    v21 = v56.y1;
    goto LABEL_21;
  }
}
