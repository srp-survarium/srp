void __thiscall Scaleform::Render::DICommand_PaletteMap::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_PaletteMap *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen)
{
  bool (__thiscall *GetRequireSourceRead)(struct Scaleform::Render::DICommand_PaletteMap *); // edx
  float *v6; // eax
  double v7; // st7
  Scaleform::Render::Size<unsigned long> *v8; // eax
  Scaleform::Render::DrawableImage *pObject; // ecx
  unsigned int *v10; // eax
  int v11; // edx
  double v12; // st7
  Scaleform::Render::DrawableImage *v13; // ecx
  unsigned int *v14; // eax
  float v15; // [esp+10h] [ebp-B0h]
  float v16; // [esp+10h] [ebp-B0h]
  int v17; // [esp+14h] [ebp-ACh]
  float v18; // [esp+14h] [ebp-ACh]
  float v19; // [esp+14h] [ebp-ACh]
  float Width; // [esp+18h] [ebp-A8h]
  float v21; // [esp+18h] [ebp-A8h]
  float x; // [esp+18h] [ebp-A8h]
  float v23; // [esp+18h] [ebp-A8h]
  float Height; // [esp+1Ch] [ebp-A4h]
  float v25; // [esp+1Ch] [ebp-A4h]
  float y; // [esp+1Ch] [ebp-A4h]
  float v27; // [esp+1Ch] [ebp-A4h]
  float v28; // [esp+20h] [ebp-A0h] BYREF
  float v29; // [esp+24h] [ebp-9Ch]
  float v30; // [esp+28h] [ebp-98h]
  float v31; // [esp+2Ch] [ebp-94h]
  float v32; // [esp+30h] [ebp-90h]
  float v33; // [esp+34h] [ebp-8Ch]
  float v34; // [esp+38h] [ebp-88h]
  float v35; // [esp+3Ch] [ebp-84h]
  float v36; // [esp+40h] [ebp-80h] BYREF
  float v37; // [esp+44h] [ebp-7Ch]
  float v38; // [esp+48h] [ebp-78h] BYREF
  float v39; // [esp+4Ch] [ebp-74h]
  Scaleform::Render::Matrix2x4<float> m1; // [esp+50h] [ebp-70h] BYREF
  Scaleform::Render::Matrix2x4<float> m2; // [esp+70h] [ebp-50h] BYREF
  Scaleform::Render::Size<unsigned long> v42; // [esp+98h] [ebp-28h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+A0h] [ebp-20h] BYREF

  v28 = 1.0;
  GetRequireSourceRead = this->GetRequireSourceRead;
  v29 = 0.0;
  v30 = 0.0;
  v31 = 0.0;
  v32 = 0.0;
  v34 = 0.0;
  v35 = 0.0;
  v33 = 1.0;
  if ( GetRequireSourceRead(this) )
  {
    m2.M[0][0] = 1.0;
    m2.M[0][1] = 0.0;
    m2.M[0][2] = 0.0;
    m2.M[0][3] = -0.5;
    m2.M[1][3] = -0.5;
    m2.M[1][0] = 0.0;
    m2.M[1][2] = 0.0;
    m2.M[1][1] = 1.0;
    m1.M[0][0] = 2.0;
    m1.M[0][1] = 0.0;
    m1.M[0][2] = 0.0;
    m1.M[0][3] = 0.0;
    m1.M[1][0] = 0.0;
    m1.M[1][1] = -2.0;
    m1.M[1][2] = 0.0;
    m1.M[1][3] = 0.0;
    v6 = (float *)Scaleform::Render::operator*(&result, &m1, &m2);
    v28 = *v6;
    v29 = v6[1];
    v30 = v6[2];
    v31 = v6[3];
    v32 = v6[4];
    v33 = v6[5];
    v34 = v6[6];
    v7 = v6[7];
  }
  else
  {
    v8 = this->pImage.pObject->GetSize(this->pImage.pObject, &v38);
    Width = (float)v8->Width;
    Height = (float)v8->Height;
    v17 = this->SourceRect.y2 - this->SourceRect.y1;
    pObject = this->pImage.pObject;
    v36 = (float)(this->SourceRect.x2 - this->SourceRect.x1);
    v37 = (float)v17;
    v15 = v36 / Width;
    v18 = v37 / Height;
    v28 = v15 * v28;
    v29 = v29 * v15;
    v30 = v30 * v15;
    v31 = v15 * v31;
    v32 = v32 * v18;
    v33 = v33 * v18;
    v34 = v34 * v18;
    v35 = v18 * v35;
    v10 = (unsigned int *)pObject->GetSize(pObject, (Scaleform::Render::Size<unsigned long> *)&v36);
    v11 = v10[1];
    v38 = (float)*v10;
    v12 = (double)(int)v10[1];
    if ( v11 < 0 )
      v12 = v12 + 4294967300.0;
    v13 = this->pImage.pObject;
    v39 = v12;
    v14 = (unsigned int *)v13->GetSize(v13, &v42);
    v25 = (float)v14[1];
    v21 = (float)*v14;
    v36 = v21 * 0.5;
    v37 = 0.5 * v25;
    x = (float)this->DestPoint.x;
    y = (float)this->DestPoint.y;
    v16 = x - v36;
    v19 = y - v37;
    v23 = v16 / v38;
    v27 = v19 / v39;
    v31 = v31 + v23;
    v35 = v35 + v27;
    v28 = v28 * 2.0;
    v29 = v29 * 2.0;
    v30 = v30 * 2.0;
    v31 = 2.0 * v31;
    v32 = v32 * -2.0;
    v33 = v33 * -2.0;
    v34 = v34 * -2.0;
    v7 = -2.0 * v35;
  }
  v35 = v7;
  context->pHAL->DrawablePaletteMap(
    context->pHAL,
    tex,
    texgen,
    (const Scaleform::Render::Matrix2x4<float> *)&v28,
    this->ChannelMask,
    this->Channels);
}
