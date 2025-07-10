void __thiscall Scaleform::Render::MatrixState::MatrixState(Scaleform::Render::MatrixState *this)
{
  const vostok::math::float4x4 *v1; // xmm1_4
  Scaleform::Render::Matrix3x4<float> *p_View3D; // edi
  const vostok::math::float4x4 *v4; // xmm0_4
  const vostok::math::float4x4 *v5; // xmm0_4
  const vostok::math::float4x4 *v6; // xmm0_4
  const vostok::math::float4x4 *v7; // xmm1_4
  const vostok::math::float4x4 *v8; // xmm0_4
  const vostok::math::float4x4 *v9; // xmm0_4
  const vostok::math::float4x4 *v10; // xmm0_4

  v1 = clear_value;
  this->__vftable = (Scaleform::Render::MatrixState_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::MatrixState_vtbl *)&Scaleform::Render::MatrixState::`vftable';
  p_View3D = &this->View3D;
  *(_QWORD *)&this->View2D.M[0][0] = (unsigned int)v1;
  *(_QWORD *)&this->View2D.M[0][2] = 0;
  this->View2D.M[1][0] = 0.0;
  *(_QWORD *)&this->View2D.M[1][1] = (unsigned int)v1;
  this->View2D.M[1][3] = 0.0;
  memset((unsigned __int8 *)&this->View3D, 0, sizeof(this->View3D));
  v4 = clear_value;
  LODWORD(p_View3D->M[0][0]) = clear_value;
  LODWORD(p_View3D->M[1][1]) = v4;
  LODWORD(p_View3D->M[2][2]) = v4;
  memset((unsigned __int8 *)&this->Proj3D, 0, sizeof(this->Proj3D));
  v5 = clear_value;
  LODWORD(this->Proj3D.M[0][0]) = clear_value;
  LODWORD(this->Proj3D.M[1][1]) = v5;
  LODWORD(this->Proj3D.M[2][2]) = v5;
  LODWORD(this->Proj3D.M[3][3]) = v5;
  memset((unsigned __int8 *)&this->Proj3DLeft, 0, sizeof(this->Proj3DLeft));
  v6 = clear_value;
  LODWORD(this->Proj3DLeft.M[0][0]) = clear_value;
  LODWORD(this->Proj3DLeft.M[1][1]) = v6;
  LODWORD(this->Proj3DLeft.M[2][2]) = v6;
  LODWORD(this->Proj3DLeft.M[3][3]) = v6;
  memset((unsigned __int8 *)&this->Proj3DRight, 0, sizeof(this->Proj3DRight));
  v7 = clear_value;
  LODWORD(this->Proj3DRight.M[0][0]) = clear_value;
  LODWORD(this->Proj3DRight.M[1][1]) = v7;
  LODWORD(this->Proj3DRight.M[2][2]) = v7;
  LODWORD(this->Proj3DRight.M[3][3]) = v7;
  LODWORD(this->User.M[0][0]) = v7;
  this->User.M[0][1] = 0.0;
  this->User.M[0][2] = 0.0;
  this->User.M[0][3] = 0.0;
  this->User.M[1][0] = 0.0;
  LODWORD(this->User.M[1][1]) = v7;
  this->User.M[1][2] = 0.0;
  this->User.M[1][3] = 0.0;
  LODWORD(this->User3D.M[0][0]) = v7;
  this->User3D.M[0][1] = 0.0;
  this->User3D.M[0][2] = 0.0;
  this->User3D.M[0][3] = 0.0;
  this->User3D.M[1][0] = 0.0;
  LODWORD(this->User3D.M[1][1]) = v7;
  this->User3D.M[1][2] = 0.0;
  this->User3D.M[1][3] = 0.0;
  LODWORD(this->Orient2D.M[0][0]) = v7;
  this->Orient2D.M[0][1] = 0.0;
  this->Orient2D.M[0][2] = 0.0;
  this->Orient2D.M[0][3] = 0.0;
  this->Orient2D.M[1][0] = 0.0;
  LODWORD(this->Orient2D.M[1][1]) = v7;
  this->Orient2D.M[1][2] = 0.0;
  this->Orient2D.M[1][3] = 0.0;
  memset((unsigned __int8 *)&this->Orient3D, 0, sizeof(this->Orient3D));
  v8 = clear_value;
  LODWORD(this->Orient3D.M[0][0]) = clear_value;
  LODWORD(this->Orient3D.M[1][1]) = v8;
  LODWORD(this->Orient3D.M[2][2]) = v8;
  LODWORD(this->Orient3D.M[3][3]) = v8;
  this->ViewRectOriginal.x1 = 0;
  this->ViewRectOriginal.y1 = 0;
  this->ViewRectOriginal.x2 = 0;
  this->ViewRectOriginal.y2 = 0;
  this->ViewRect.x1 = 0;
  this->ViewRect.y1 = 0;
  this->ViewRect.x2 = 0;
  this->ViewRect.y2 = 0;
  LODWORD(this->UserView.M[0][0]) = v8;
  this->UserView.M[0][1] = 0.0;
  this->UserView.M[0][2] = 0.0;
  this->UserView.M[0][3] = 0.0;
  this->UserView.M[1][0] = 0.0;
  LODWORD(this->UserView.M[1][1]) = v8;
  this->UserView.M[1][2] = 0.0;
  this->UserView.M[1][3] = 0.0;
  memset((unsigned __int8 *)&this->UVPO, 0, sizeof(this->UVPO));
  v9 = clear_value;
  LODWORD(this->UVPO.M[0][0]) = clear_value;
  LODWORD(this->UVPO.M[1][1]) = v9;
  LODWORD(this->UVPO.M[2][2]) = v9;
  LODWORD(this->UVPO.M[3][3]) = v9;
  memset((unsigned __int8 *)&this->ViewRectCompensated3D, 0, sizeof(this->ViewRectCompensated3D));
  v10 = clear_value;
  LODWORD(this->ViewRectCompensated3D.M[0][0]) = clear_value;
  LODWORD(this->ViewRectCompensated3D.M[1][1]) = v10;
  LODWORD(this->ViewRectCompensated3D.M[2][2]) = v10;
  LODWORD(this->ViewRectCompensated3D.M[3][3]) = v10;
  this->UVPOChanged = 0;
  this->OrientationSet = 0;
  this->S3DParams.DisplayWidthCm = 0.0;
  this->S3DParams.Distortion = 0.75;
  this->S3DParams.DisplayDiagInches = 52.0;
  this->S3DParams.DisplayAspectRatio = 0.5625;
  this->S3DParams.EyeSeparationCm = 6.4000001;
  this->S3DDisplay = StereoCenter;
  this->pHAL = 0;
}
