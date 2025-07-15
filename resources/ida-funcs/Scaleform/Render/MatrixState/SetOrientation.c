Scaleform::Render::Viewport *__thiscall Scaleform::Render::MatrixState::SetOrientation(
        Scaleform::Render::MatrixState *this,
        Scaleform::Render::Viewport *result,
        const Scaleform::Render::Viewport *vp)
{
  unsigned int v4; // eax
  double v5; // st7
  double v6; // st6
  Scaleform::Render::Matrix4x4<float> *p_Orient3D; // esi
  const Scaleform::Render::Matrix2x4<float> *v8; // eax
  int Left; // eax
  int Top; // ecx
  double v11; // st7
  double v12; // st7
  double v13; // st4
  double v14; // st7
  double v15; // st7
  double v16; // st7
  bool v17; // zf
  int ScissorLeft; // eax
  int ScissorTop; // ecx
  int v20; // edx
  int v21; // eax
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  int v26; // edx
  float v28; // [esp+14h] [ebp-54h]
  float v29; // [esp+14h] [ebp-54h]
  float v30; // [esp+14h] [ebp-54h]
  float v31; // [esp+14h] [ebp-54h]
  float v32; // [esp+14h] [ebp-54h]
  float v33; // [esp+14h] [ebp-54h]
  float v34; // [esp+18h] [ebp-50h]
  float v35; // [esp+18h] [ebp-50h]
  float v36; // [esp+18h] [ebp-50h]
  float v37; // [esp+18h] [ebp-50h]
  float BufferWidth; // [esp+1Ch] [ebp-4Ch]
  float v39; // [esp+1Ch] [ebp-4Ch]
  float v40; // [esp+1Ch] [ebp-4Ch]
  float v41; // [esp+1Ch] [ebp-4Ch]
  float v42; // [esp+1Ch] [ebp-4Ch]
  float v43; // [esp+20h] [ebp-48h]
  float v44; // [esp+20h] [ebp-48h]
  float v45; // [esp+20h] [ebp-48h]
  float v46; // [esp+20h] [ebp-48h]
  float BufferHeight; // [esp+24h] [ebp-44h]
  float v48; // [esp+24h] [ebp-44h]
  float v49; // [esp+24h] [ebp-44h]
  float v50; // [esp+24h] [ebp-44h]
  float v51; // [esp+24h] [ebp-44h]
  float v52; // [esp+24h] [ebp-44h]
  float v53; // [esp+24h] [ebp-44h]
  float v54; // [esp+24h] [ebp-44h]
  float v55; // [esp+24h] [ebp-44h]
  float v56; // [esp+24h] [ebp-44h]
  float v57; // [esp+24h] [ebp-44h]
  float v58; // [esp+24h] [ebp-44h]
  float v59; // [esp+24h] [ebp-44h]
  float v60; // [esp+24h] [ebp-44h]
  float v61; // [esp+24h] [ebp-44h]
  float v62; // [esp+24h] [ebp-44h]
  float v63; // [esp+24h] [ebp-44h]
  float v64; // [esp+24h] [ebp-44h]
  float v65; // [esp+24h] [ebp-44h]
  float v66; // [esp+24h] [ebp-44h]
  float v67; // [esp+24h] [ebp-44h]
  Scaleform::Render::Matrix2x4<float> resulta; // [esp+28h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v69; // [esp+48h] [ebp-20h] BYREF

  this->OrientationSet = 0;
  this->UVPOChanged = 1;
  v4 = vp->Flags & 0x30;
  if ( v4 )
  {
    if ( v4 == 16 || v4 == 48 )
    {
      this->OrientationSet = 1;
      if ( (vp->Flags & 0x30) == 0x30 )
      {
        v28 = -1.0;
        BufferHeight = (float)vp->BufferHeight;
        v5 = 0.0;
        BufferWidth = 0.0;
      }
      else
      {
        v28 = 1.0;
        v5 = 0.0;
        BufferHeight = 0.0;
        BufferWidth = (float)vp->BufferWidth;
      }
      this->Orient2D.M[0][0] = v5;
      v6 = v28;
      v29 = -v28;
      this->Orient2D.M[0][1] = v29;
      this->Orient2D.M[0][2] = v5;
      this->Orient2D.M[0][3] = BufferWidth;
      this->Orient2D.M[1][0] = v6;
      this->Orient2D.M[1][1] = v5;
      this->Orient2D.M[1][2] = v5;
      this->Orient2D.M[1][3] = BufferHeight;
      this->Orient3D.M[0][0] = v5;
      this->Orient3D.M[1][1] = v5;
      this->Orient3D.M[0][1] = v6;
      this->Orient3D.M[1][0] = v29;
    }
  }
  else
  {
    this->Orient2D.M[0][0] = 1.0;
    p_Orient3D = &this->Orient3D;
    this->Orient2D.M[0][1] = 0.0;
    this->Orient2D.M[0][2] = 0.0;
    this->Orient2D.M[0][3] = 0.0;
    this->Orient2D.M[1][0] = 0.0;
    this->Orient2D.M[1][2] = 0.0;
    this->Orient2D.M[1][3] = 0.0;
    this->Orient2D.M[1][1] = 1.0;
    memset((int)&this->Orient3D, 0, sizeof(this->Orient3D));
    p_Orient3D->M[0][0] = 1.0;
    this->Orient3D.M[1][1] = 1.0;
    this->Orient3D.M[2][2] = 1.0;
    this->Orient3D.M[3][3] = 1.0;
  }
  v8 = Scaleform::Render::operator*(&resulta, &this->User, &this->Orient2D);
  this->UserView = *Scaleform::Render::operator*(&v69, &this->View2D, v8);
  result->BufferWidth = 0;
  result->BufferHeight = 0;
  result->Top = 0;
  result->Left = 0;
  result->ScissorHeight = 0;
  result->ScissorWidth = 0;
  result->ScissorTop = 0;
  result->ScissorLeft = 0;
  Left = vp->Left;
  result->Height = 1;
  result->Width = 1;
  Top = vp->Top;
  v39 = (float)Left;
  v43 = (float)Top;
  v11 = v39;
  v40 = this->Orient2D.M[0][0] * v39 + this->Orient2D.M[0][1] * v43 + this->Orient2D.M[0][3];
  v44 = v11 * this->Orient2D.M[1][0] + v43 * this->Orient2D.M[1][1] + this->Orient2D.M[1][3];
  v30 = (float)(Left + vp->Width);
  v34 = (float)(Top + vp->Height);
  v12 = this->Orient2D.M[0][1] * v34;
  result->Flags = vp->Flags;
  v13 = v12;
  v14 = v30;
  v31 = this->Orient2D.M[0][0] * v30 + v13 + this->Orient2D.M[0][3];
  v35 = v14 * this->Orient2D.M[1][0] + v34 * this->Orient2D.M[1][1] + this->Orient2D.M[1][3];
  v15 = v40;
  if ( v31 <= (double)v40 )
    v15 = v31;
  v48 = v15;
  v49 = ceil(v48);
  v16 = v44;
  result->Left = (int)v49;
  if ( v35 <= (double)v44 )
    v16 = v35;
  v50 = v16;
  v51 = ceil(v50);
  result->Top = (int)v51;
  v52 = v40 - v31;
  v53 = fabs(v52);
  v54 = ceil(v53);
  result->Width = (int)v54;
  v55 = v44 - v35;
  v56 = fabs(v55);
  v57 = ceil(v56);
  v17 = (result->Flags & 4) == 0;
  result->Height = (int)v57;
  if ( !v17 )
  {
    ScissorTop = vp->ScissorTop;
    ScissorLeft = vp->ScissorLeft;
    v20 = ScissorLeft + vp->ScissorWidth;
    v41 = (float)ScissorLeft;
    v21 = ScissorTop + vp->ScissorHeight;
    v45 = (float)ScissorTop;
    result->Flags = vp->Flags;
    v22 = v41;
    v42 = this->Orient2D.M[0][1] * v45 + v41 * this->Orient2D.M[0][0] + this->Orient2D.M[0][3];
    v46 = v22 * this->Orient2D.M[1][0] + v45 * this->Orient2D.M[1][1] + this->Orient2D.M[1][3];
    v32 = (float)v20;
    v36 = (float)v21;
    v23 = v32;
    v33 = this->Orient2D.M[0][0] * v32 + this->Orient2D.M[0][1] * v36 + this->Orient2D.M[0][3];
    v37 = v23 * this->Orient2D.M[1][0] + v36 * this->Orient2D.M[1][1] + this->Orient2D.M[1][3];
    v24 = v42;
    if ( v33 <= (double)v42 )
      v24 = v33;
    v58 = v24;
    v59 = ceil(v58);
    v25 = v46;
    result->ScissorLeft = (int)v59;
    if ( v37 <= (double)v46 )
      v25 = v37;
    v60 = v25;
    v61 = ceil(v60);
    result->ScissorTop = (int)v61;
    v62 = v42 - v33;
    v63 = fabs(v62);
    v64 = ceil(v63);
    result->ScissorWidth = (int)v64;
    v65 = v46 - v37;
    v66 = fabs(v65);
    v67 = ceil(v66);
    result->ScissorHeight = (int)v67;
  }
  v26 = vp->BufferWidth;
  result->BufferHeight = vp->BufferHeight;
  result->BufferWidth = v26;
  return result;
}
