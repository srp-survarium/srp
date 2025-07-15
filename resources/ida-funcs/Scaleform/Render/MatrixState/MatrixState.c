void __thiscall Scaleform::Render::MatrixState::MatrixState(
        Scaleform::Render::MatrixState *this,
        const Scaleform::Render::MatrixState *__that)
{
  this->__vftable = (Scaleform::Render::MatrixState_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = __that->RefCount;
  this->__vftable = (Scaleform::Render::MatrixState_vtbl *)&Scaleform::Render::MatrixState::`vftable';
  Scaleform::Render::Matrix2x4<float>::SetMatrix(&this->View2D, &__that->View2D);
  memcpy((unsigned __int8 *)&this->View3D, (unsigned __int8 *)&__that->View3D, sizeof(this->View3D));
  memcpy((unsigned __int8 *)&this->Proj3D, (unsigned __int8 *)&__that->Proj3D, sizeof(this->Proj3D));
  memcpy((unsigned __int8 *)&this->Proj3DLeft, (unsigned __int8 *)&__that->Proj3DLeft, sizeof(this->Proj3DLeft));
  memcpy((unsigned __int8 *)&this->Proj3DRight, (unsigned __int8 *)&__that->Proj3DRight, sizeof(this->Proj3DRight));
  Scaleform::Render::Matrix2x4<float>::SetMatrix(&this->User, &__that->User);
  Scaleform::Render::Matrix2x4<float>::SetMatrix(&this->User3D, &__that->User3D);
  Scaleform::Render::Matrix2x4<float>::SetMatrix(&this->Orient2D, &__that->Orient2D);
  memcpy((unsigned __int8 *)&this->Orient3D, (unsigned __int8 *)&__that->Orient3D, sizeof(this->Orient3D));
  Scaleform::Render::Rect<int>::SetRect(&this->ViewRectOriginal, &__that->ViewRectOriginal);
  Scaleform::Render::Rect<int>::SetRect(&this->ViewRect, &__that->ViewRect);
  Scaleform::Render::Matrix2x4<float>::SetMatrix(&this->UserView, &__that->UserView);
  memcpy((unsigned __int8 *)&this->UVPO, (unsigned __int8 *)&__that->UVPO, sizeof(this->UVPO));
  memcpy((unsigned __int8 *)&this->ViewRectCompensated3D, (unsigned __int8 *)&__that->ViewRectCompensated3D, 0x42u);
  qmemcpy(&this->S3DParams, &__that->S3DParams, 0x1Cu);
}


void __userpurge Scaleform::Render::MatrixState::MatrixState(
        Scaleform::Render::MatrixState *this@<ecx>,
        int a2@<esi>,
        Scaleform::Render::HAL *phal)
{
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4

  v3 = s_bm_current_air_resistance;
  *(_DWORD *)a2 = &Scaleform::RefCountImplCore::`vftable';
  *(_DWORD *)(a2 + 4) = 1;
  *(_DWORD *)a2 = &Scaleform::Render::MatrixState::`vftable';
  *(float *)(a2 + 16) = v3;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(float *)(a2 + 36) = v3;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  memset(a2 + 48, 0, 0x30u);
  v4 = s_bm_current_air_resistance;
  *(float *)(a2 + 48) = s_bm_current_air_resistance;
  *(float *)(a2 + 68) = v4;
  *(float *)(a2 + 88) = v4;
  memset(a2 + 96, 0, 0x40u);
  v5 = s_bm_current_air_resistance;
  *(float *)(a2 + 96) = s_bm_current_air_resistance;
  *(float *)(a2 + 116) = v5;
  *(float *)(a2 + 136) = v5;
  *(float *)(a2 + 156) = v5;
  memset(a2 + 160, 0, 0x40u);
  v6 = s_bm_current_air_resistance;
  *(float *)(a2 + 160) = s_bm_current_air_resistance;
  *(float *)(a2 + 180) = v6;
  *(float *)(a2 + 200) = v6;
  *(float *)(a2 + 220) = v6;
  memset(a2 + 224, 0, 0x40u);
  v7 = s_bm_current_air_resistance;
  *(float *)(a2 + 224) = s_bm_current_air_resistance;
  *(float *)(a2 + 244) = v7;
  *(float *)(a2 + 264) = v7;
  *(float *)(a2 + 284) = v7;
  *(float *)(a2 + 288) = v7;
  *(_DWORD *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  *(_DWORD *)(a2 + 300) = 0;
  *(_DWORD *)(a2 + 304) = 0;
  *(float *)(a2 + 308) = v7;
  *(_DWORD *)(a2 + 312) = 0;
  *(_DWORD *)(a2 + 316) = 0;
  *(float *)(a2 + 320) = v7;
  *(_DWORD *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 328) = 0;
  *(_DWORD *)(a2 + 332) = 0;
  *(_DWORD *)(a2 + 336) = 0;
  *(float *)(a2 + 340) = v7;
  *(_DWORD *)(a2 + 344) = 0;
  *(_DWORD *)(a2 + 348) = 0;
  *(float *)(a2 + 352) = v7;
  *(_DWORD *)(a2 + 356) = 0;
  *(_DWORD *)(a2 + 360) = 0;
  *(_DWORD *)(a2 + 364) = 0;
  *(_DWORD *)(a2 + 368) = 0;
  *(float *)(a2 + 372) = v7;
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 380) = 0;
  memset(a2 + 384, 0, 0x40u);
  v8 = s_bm_current_air_resistance;
  *(float *)(a2 + 384) = s_bm_current_air_resistance;
  *(float *)(a2 + 404) = v8;
  *(float *)(a2 + 424) = v8;
  *(float *)(a2 + 444) = v8;
  *(_DWORD *)(a2 + 448) = 0;
  *(_DWORD *)(a2 + 452) = 0;
  *(_DWORD *)(a2 + 456) = 0;
  *(_DWORD *)(a2 + 460) = 0;
  *(_DWORD *)(a2 + 464) = 0;
  *(_DWORD *)(a2 + 468) = 0;
  *(_DWORD *)(a2 + 472) = 0;
  *(_DWORD *)(a2 + 476) = 0;
  *(float *)(a2 + 480) = v8;
  *(_DWORD *)(a2 + 484) = 0;
  *(_DWORD *)(a2 + 488) = 0;
  *(_DWORD *)(a2 + 492) = 0;
  *(_DWORD *)(a2 + 496) = 0;
  *(float *)(a2 + 500) = v8;
  *(_DWORD *)(a2 + 504) = 0;
  *(_DWORD *)(a2 + 508) = 0;
  memset(a2 + 512, 0, 0x40u);
  v9 = s_bm_current_air_resistance;
  *(float *)(a2 + 512) = s_bm_current_air_resistance;
  *(float *)(a2 + 532) = v9;
  *(float *)(a2 + 552) = v9;
  *(float *)(a2 + 572) = v9;
  memset(a2 + 576, 0, 0x40u);
  v10 = s_bm_current_air_resistance;
  *(float *)(a2 + 576) = s_bm_current_air_resistance;
  *(float *)(a2 + 596) = v10;
  *(float *)(a2 + 616) = v10;
  *(float *)(a2 + 636) = v10;
  *(_BYTE *)(a2 + 640) = 0;
  *(_BYTE *)(a2 + 641) = 0;
  *(_DWORD *)(a2 + 644) = 0;
  *(float *)(a2 + 648) = FLOAT_0_75;
  *(float *)(a2 + 652) = FLOAT_52_0;
  *(float *)(a2 + 656) = FLOAT_0_5625;
  *(float *)(a2 + 660) = FLOAT_6_4000001;
  *(_DWORD *)(a2 + 664) = 0;
  *(_DWORD *)(a2 + 668) = phal;
}


void __thiscall Scaleform::Render::MatrixState::MatrixState(Scaleform::Render::MatrixState *this)
{
  float v1; // xmm1_4
  Scaleform::Render::Matrix3x4<float> *p_View3D; // edi
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4

  v1 = s_bm_current_air_resistance;
  this->__vftable = (Scaleform::Render::MatrixState_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::MatrixState_vtbl *)&Scaleform::Render::MatrixState::`vftable';
  p_View3D = &this->View3D;
  *(_QWORD *)&this->View2D.M[0][0] = LODWORD(v1);
  *(_QWORD *)&this->View2D.M[0][2] = 0;
  this->View2D.M[1][0] = 0.0;
  *(_QWORD *)&this->View2D.M[1][1] = LODWORD(v1);
  this->View2D.M[1][3] = 0.0;
  memset((int)&this->View3D, 0, sizeof(this->View3D));
  v4 = s_bm_current_air_resistance;
  p_View3D->M[0][0] = s_bm_current_air_resistance;
  p_View3D->M[1][1] = v4;
  p_View3D->M[2][2] = v4;
  memset((int)&this->Proj3D, 0, sizeof(this->Proj3D));
  v5 = s_bm_current_air_resistance;
  this->Proj3D.M[0][0] = s_bm_current_air_resistance;
  this->Proj3D.M[1][1] = v5;
  this->Proj3D.M[2][2] = v5;
  this->Proj3D.M[3][3] = v5;
  memset((int)&this->Proj3DLeft, 0, sizeof(this->Proj3DLeft));
  v6 = s_bm_current_air_resistance;
  this->Proj3DLeft.M[0][0] = s_bm_current_air_resistance;
  this->Proj3DLeft.M[1][1] = v6;
  this->Proj3DLeft.M[2][2] = v6;
  this->Proj3DLeft.M[3][3] = v6;
  memset((int)&this->Proj3DRight, 0, sizeof(this->Proj3DRight));
  v7 = s_bm_current_air_resistance;
  this->Proj3DRight.M[0][0] = s_bm_current_air_resistance;
  this->Proj3DRight.M[1][1] = v7;
  this->Proj3DRight.M[2][2] = v7;
  this->Proj3DRight.M[3][3] = v7;
  this->User.M[0][0] = v7;
  this->User.M[0][1] = 0.0;
  this->User.M[0][2] = 0.0;
  this->User.M[0][3] = 0.0;
  this->User.M[1][0] = 0.0;
  this->User.M[1][1] = v7;
  this->User.M[1][2] = 0.0;
  this->User.M[1][3] = 0.0;
  this->User3D.M[0][0] = v7;
  this->User3D.M[0][1] = 0.0;
  this->User3D.M[0][2] = 0.0;
  this->User3D.M[0][3] = 0.0;
  this->User3D.M[1][0] = 0.0;
  this->User3D.M[1][1] = v7;
  this->User3D.M[1][2] = 0.0;
  this->User3D.M[1][3] = 0.0;
  this->Orient2D.M[0][0] = v7;
  this->Orient2D.M[0][1] = 0.0;
  this->Orient2D.M[0][2] = 0.0;
  this->Orient2D.M[0][3] = 0.0;
  this->Orient2D.M[1][0] = 0.0;
  this->Orient2D.M[1][1] = v7;
  this->Orient2D.M[1][2] = 0.0;
  this->Orient2D.M[1][3] = 0.0;
  memset((int)&this->Orient3D, 0, sizeof(this->Orient3D));
  v8 = s_bm_current_air_resistance;
  this->Orient3D.M[0][0] = s_bm_current_air_resistance;
  this->Orient3D.M[1][1] = v8;
  this->Orient3D.M[2][2] = v8;
  this->Orient3D.M[3][3] = v8;
  this->ViewRectOriginal.x1 = 0;
  this->ViewRectOriginal.y1 = 0;
  this->ViewRectOriginal.x2 = 0;
  this->ViewRectOriginal.y2 = 0;
  this->ViewRect.x1 = 0;
  this->ViewRect.y1 = 0;
  this->ViewRect.x2 = 0;
  this->ViewRect.y2 = 0;
  this->UserView.M[0][0] = v8;
  this->UserView.M[0][1] = 0.0;
  this->UserView.M[0][2] = 0.0;
  this->UserView.M[0][3] = 0.0;
  this->UserView.M[1][0] = 0.0;
  this->UserView.M[1][1] = v8;
  this->UserView.M[1][2] = 0.0;
  this->UserView.M[1][3] = 0.0;
  memset((int)&this->UVPO, 0, sizeof(this->UVPO));
  v9 = s_bm_current_air_resistance;
  this->UVPO.M[0][0] = s_bm_current_air_resistance;
  this->UVPO.M[1][1] = v9;
  this->UVPO.M[2][2] = v9;
  this->UVPO.M[3][3] = v9;
  memset((int)&this->ViewRectCompensated3D, 0, sizeof(this->ViewRectCompensated3D));
  v10 = s_bm_current_air_resistance;
  this->ViewRectCompensated3D.M[0][0] = s_bm_current_air_resistance;
  this->ViewRectCompensated3D.M[1][1] = v10;
  this->ViewRectCompensated3D.M[2][2] = v10;
  this->ViewRectCompensated3D.M[3][3] = v10;
  this->UVPOChanged = 0;
  this->OrientationSet = 0;
  this->S3DParams.DisplayWidthCm = 0.0;
  this->S3DParams.Distortion = FLOAT_0_75;
  this->S3DParams.DisplayDiagInches = FLOAT_52_0;
  this->S3DParams.DisplayAspectRatio = FLOAT_0_5625;
  this->S3DParams.EyeSeparationCm = FLOAT_6_4000001;
  this->S3DDisplay = StereoCenter;
  this->pHAL = 0;
}
