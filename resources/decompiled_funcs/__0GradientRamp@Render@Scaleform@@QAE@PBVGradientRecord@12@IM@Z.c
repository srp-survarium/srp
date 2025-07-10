void __thiscall Scaleform::Render::GradientRamp::GradientRamp(
        Scaleform::Render::GradientRamp *this,
        Scaleform::Render::GradientRecord *records,
        unsigned int recordCount,
        float gamma)
{
  unsigned int v4; // edx
  Scaleform::Render::GradientRecord *p_fakeColor; // eax
  unsigned __int8 *p_Red; // edi
  unsigned __int8 Alpha; // cl
  unsigned int v8; // esi
  __int16 v9; // bx
  double v10; // st7
  double v11; // st7
  double v12; // st7
  unsigned __int16 v13; // ax
  __int16 v14; // bx
  double v15; // st7
  double v16; // st7
  double v17; // st7
  unsigned __int16 v18; // dx
  int v19; // ebx
  int v20; // ecx
  int v21; // ebx
  char v22; // al
  bool v23; // zf
  int v24; // [esp+3Ch] [ebp-4Ch]
  unsigned __int8 c[4]; // [esp+40h] [ebp-48h] BYREF
  unsigned int end; // [esp+44h] [ebp-44h]
  Scaleform::Render::GradientRamp *v27; // [esp+48h] [ebp-40h]
  int v28; // [esp+4Ch] [ebp-3Ch]
  int v29; // [esp+50h] [ebp-38h]
  int ratio; // [esp+54h] [ebp-34h]
  int v31; // [esp+58h] [ebp-30h]
  int v32; // [esp+5Ch] [ebp-2Ch]
  unsigned __int8 *v33; // [esp+60h] [ebp-28h]
  int v34; // [esp+64h] [ebp-24h]
  float gammaInv; // [esp+68h] [ebp-20h]
  Scaleform::Render::GradientRamp::ColorType c1; // [esp+6Ch] [ebp-1Ch] BYREF
  Scaleform::Render::GradientRecord fakeColor; // [esp+74h] [ebp-14h] BYREF
  Scaleform::Render::GradientRamp::ColorType c2; // [esp+7Ch] [ebp-Ch] BYREF

  v4 = recordCount;
  v27 = this;
  if ( !recordCount || (p_fakeColor = records) == 0 )
  {
    fakeColor.Ratio = 0;
    fakeColor.ColorV.Raw = -16777216;
    v4 = 1;
    p_fakeColor = &fakeColor;
  }
  p_Red = &p_fakeColor->ColorV.Channels.Red;
  c[0] = p_fakeColor->ColorV.Channels.Red;
  c[1] = p_fakeColor->ColorV.Channels.Green;
  c[2] = p_fakeColor->ColorV.Channels.Blue;
  Alpha = p_fakeColor->ColorV.Channels.Alpha;
  v33 = &p_fakeColor->ColorV.Channels.Red;
  c[3] = Alpha;
  if ( v4 <= 1 )
  {
    memset32(v27, *(int *)c, 0x100u);
  }
  else
  {
    v8 = p_fakeColor->Ratio;
    gammaInv = 1.0 / gamma;
    if ( v8 )
    {
      memset32(v27, *(int *)c, v8);
      p_Red = v33;
    }
    v33 = (unsigned __int8 *)(v4 - 1);
    do
    {
      end = p_Red[2];
      if ( end < v8 )
        end = v8;
      v32 = *p_Red;
      v9 = p_Red[1];
      *(float *)&v32 = (double)v32 / 255.0;
      *(float *)&v32 = pow(*(float *)&v32, gamma);
      *(float *)&v32 = *(float *)&v32 * 65535.0 + 0.5;
      v10 = floor(*(float *)&v32);
      v32 = (int)v10;
      v32 = *(p_Red - 1);
      c1.r = (int)v10;
      *(float *)&v32 = (double)v32 / 255.0;
      *(float *)&v32 = pow(*(float *)&v32, gamma);
      *(float *)&v32 = *(float *)&v32 * 65535.0 + 0.5;
      v11 = floor(*(float *)&v32);
      v32 = (int)v11;
      v32 = *(p_Red - 2);
      c1.g = (int)v11;
      *(float *)&v32 = (double)v32 / 255.0;
      *(float *)&v32 = pow(*(float *)&v32, gamma);
      *(float *)&v32 = *(float *)&v32 * 65535.0 + 0.5;
      v12 = floor(*(float *)&v32);
      v32 = (int)v12;
      v32 = p_Red[8];
      v13 = v9 | (v9 << 8);
      v14 = p_Red[9];
      c1.b = (int)v12;
      c1.a = v13;
      *(float *)&v32 = (double)v32 / 255.0;
      *(float *)&v32 = pow(*(float *)&v32, gamma);
      *(float *)&v32 = *(float *)&v32 * 65535.0 + 0.5;
      v15 = floor(*(float *)&v32);
      v32 = (int)v15;
      v32 = p_Red[7];
      c2.r = (int)v15;
      *(float *)&v32 = (double)v32 / 255.0;
      *(float *)&v32 = pow(*(float *)&v32, gamma);
      *(float *)&v32 = *(float *)&v32 * 65535.0 + 0.5;
      v16 = floor(*(float *)&v32);
      v32 = (int)v16;
      v32 = p_Red[6];
      c2.g = (int)v16;
      *(float *)&v32 = (double)v32 / 255.0;
      *(float *)&v32 = pow(*(float *)&v32, gamma);
      *(float *)&v32 = *(float *)&v32 * 65535.0 + 0.5;
      v17 = floor(*(float *)&v32);
      v18 = v14 | (v14 << 8);
      v19 = end - v8;
      v32 = (int)v17;
      c2.b = (int)v17;
      c2.a = v18;
      if ( 1.0 == gamma )
      {
        if ( v8 < end )
        {
          v20 = v19 | (v19 << 8);
          v21 = v18 - c1.a;
          v32 = c2.b - c1.b;
          v31 = c2.g - c1.g;
          v29 = v32;
          v34 = c2.r - c1.r;
          ratio = v21;
          v28 = v31;
          v24 = v34;
          do
          {
            ++v8;
            c[0] = LOBYTE(c1.r) + v24 / v20;
            c[1] = LOBYTE(c1.g) + v28 / v20;
            c[2] = LOBYTE(c1.b) + v29 / v20;
            v22 = ratio / v20;
            ratio += v21;
            c[3] = LOBYTE(c1.a) + v22;
            *(_DWORD *)&v27->Ramp[4 * v8 - 4] = *(_DWORD *)c;
            v24 += v34;
            v28 += v31;
            v29 += v32;
          }
          while ( v8 < end );
        }
      }
      else if ( v8 < end )
      {
        ratio = 1;
        do
        {
          Scaleform::Render::GradientRamp::blendColors(c, &c1, &c2, ratio++, v19, gammaInv);
          *(_DWORD *)&v27->Ramp[4 * v8++] = *(_DWORD *)c;
        }
        while ( v8 < end );
      }
      c[0] = HIBYTE(c2.r);
      p_Red += 8;
      v23 = v33-- == (unsigned __int8 *)1;
      c[1] = HIBYTE(c2.g);
      c[2] = HIBYTE(c2.b);
      c[3] = HIBYTE(c2.a);
    }
    while ( !v23 );
    if ( end < 0x100 )
      memset32((char *)v27 + 4 * end, *(int *)c, 256 - end);
  }
}
