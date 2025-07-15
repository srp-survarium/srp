void __thiscall Scaleform::Render::MatrixState::recalculateUVPOC(Scaleform::Render::MatrixState *this)
{
  int v2; // ecx
  __int64 v3; // rax
  int v4; // ebx
  __int64 v5; // rax
  int v6; // ecx
  int x2; // edx
  double v8; // st6
  int v9; // ecx
  int v10; // eax
  Scaleform::Render::Matrix4x4<float> *p_ViewRectCompensated3D; // edi
  double v12; // st6
  int v13; // ecx
  const Scaleform::Render::Matrix4x4<float> *v14; // eax
  const Scaleform::Render::Matrix4x4<float> *updated; // ebx
  float VRP_48; // [esp+1B8h] [ebp-130h]
  float VRP_52; // [esp+1BCh] [ebp-12Ch]
  int v18; // [esp+1DCh] [ebp-10Ch]
  int v19; // [esp+1DCh] [ebp-10Ch]
  float v20; // [esp+1DCh] [ebp-10Ch]
  float v21; // [esp+1DCh] [ebp-10Ch]
  int v22; // [esp+1E0h] [ebp-108h]
  int v23; // [esp+1E4h] [ebp-104h]
  Scaleform::Render::Matrix4x4<float> dst; // [esp+1E8h] [ebp-100h] BYREF
  Scaleform::Render::Matrix4x4<float> result; // [esp+228h] [ebp-C0h] BYREF
  Scaleform::Render::Matrix4x4<float> m1; // [esp+268h] [ebp-80h] BYREF
  Scaleform::Render::Matrix4x4<float> m2; // [esp+2A8h] [ebp-40h] BYREF

  if ( this->UVPOChanged )
  {
    if ( this->ViewRect.x1 == this->ViewRectOriginal.x1
      && this->ViewRect.x2 == this->ViewRectOriginal.x2
      && this->ViewRect.y1 == this->ViewRectOriginal.y1
      && this->ViewRect.y2 == this->ViewRectOriginal.y2
      || (v2 = this->ViewRectOriginal.x2, v2 == this->ViewRectOriginal.x1)
      && this->ViewRectOriginal.y2 == this->ViewRectOriginal.y1 )
    {
      p_ViewRectCompensated3D = &this->ViewRectCompensated3D;
      memcpy(
        (unsigned __int8 *)&this->ViewRectCompensated3D,
        (unsigned __int8 *)&Scaleform::Render::Matrix4x4<float>::Identity,
        sizeof(this->ViewRectCompensated3D));
    }
    else
    {
      v3 = this->ViewRectOriginal.y1 + this->ViewRectOriginal.y2;
      v4 = ((int)v3 - HIDWORD(v3)) >> 1;
      v5 = this->ViewRect.x1 + this->ViewRect.x2;
      v23 = (this->ViewRect.y1 + this->ViewRect.y2) / 2 - v4;
      v22 = (((int)v5 - HIDWORD(v5)) >> 1) - (this->ViewRectOriginal.x1 + v2) / 2;
      memset((int)&dst, 0, sizeof(dst));
      v6 = this->ViewRectOriginal.x2 - this->ViewRectOriginal.x1;
      x2 = this->ViewRect.x2;
      dst.M[3][3] = 1.0;
      v8 = (double)v6;
      v9 = this->ViewRect.y2 - this->ViewRect.y1;
      v18 = this->ViewRectOriginal.y2 - this->ViewRectOriginal.y1;
      v10 = v9;
      p_ViewRectCompensated3D = &this->ViewRectCompensated3D;
      dst.M[0][0] = v8 / (double)(x2 - this->ViewRect.x1);
      v12 = (double)v18;
      v19 = v9;
      v13 = this->ViewRect.x2 - this->ViewRect.x1;
      dst.M[1][1] = v12 / (double)v19;
      dst.M[2][2] = 1.0;
      v20 = (double)v23 * 2.0 / (double)v10;
      VRP_52 = v20;
      v21 = 2.0 * (double)v22 / (double)v13;
      VRP_48 = -v21;
      v14 = Scaleform::Render::Matrix4x4<float>::Translation(&result, VRP_48, VRP_52, 0.0);
      Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&this->ViewRectCompensated3D, v14, &dst);
    }
    updated = Scaleform::Render::MatrixState::updateStereoProjection(this, 1.0);
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&m1, &this->User3D, p_ViewRectCompensated3D);
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&m2, &this->Orient3D, updated);
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&dst, &m1, &m2);
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&result, &dst, &this->View3D);
    memcpy((unsigned __int8 *)&this->UVPO, (unsigned __int8 *)&result, sizeof(this->UVPO));
    this->UVPOChanged = 0;
  }
}
