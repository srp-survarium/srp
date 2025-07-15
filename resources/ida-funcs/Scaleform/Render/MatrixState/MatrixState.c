void __thiscall Scaleform::Render::MatrixState::MatrixState(
        Scaleform::Render::MatrixState *this,
        const Scaleform::Render::MatrixState *__that)
{
  int y2; // eax
  int x2; // ecx
  int x1; // ebx
  int v6; // eax
  int v7; // ecx
  int v8; // ebx

  this->__vftable = (Scaleform::Render::MatrixState_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = __that->RefCount;
  this->__vftable = (Scaleform::Render::MatrixState_vtbl *)&Scaleform::Render::MatrixState::`vftable';
  this->View2D = __that->View2D;
  memcpy((unsigned __int8 *)&this->View3D, (unsigned __int8 *)&__that->View3D, sizeof(this->View3D));
  memcpy((unsigned __int8 *)&this->Proj3D, (unsigned __int8 *)&__that->Proj3D, sizeof(this->Proj3D));
  memcpy((unsigned __int8 *)&this->Proj3DLeft, (unsigned __int8 *)&__that->Proj3DLeft, sizeof(this->Proj3DLeft));
  memcpy((unsigned __int8 *)&this->Proj3DRight, (unsigned __int8 *)&__that->Proj3DRight, 0xA0u);
  memcpy((unsigned __int8 *)&this->Orient3D, (unsigned __int8 *)&__that->Orient3D, sizeof(this->Orient3D));
  y2 = __that->ViewRectOriginal.y2;
  x2 = __that->ViewRectOriginal.x2;
  x1 = __that->ViewRectOriginal.x1;
  this->ViewRectOriginal.y1 = __that->ViewRectOriginal.y1;
  this->ViewRectOriginal.y2 = y2;
  this->ViewRectOriginal.x1 = x1;
  this->ViewRectOriginal.x2 = x2;
  v6 = __that->ViewRect.y2;
  v7 = __that->ViewRect.x2;
  v8 = __that->ViewRect.x1;
  this->ViewRect.y1 = __that->ViewRect.y1;
  this->ViewRect.y2 = v6;
  this->ViewRect.x1 = v8;
  this->ViewRect.x2 = v7;
  this->UserView = __that->UserView;
  memcpy((unsigned __int8 *)&this->UVPO, (unsigned __int8 *)&__that->UVPO, sizeof(this->UVPO));
  memcpy((unsigned __int8 *)&this->ViewRectCompensated3D, (unsigned __int8 *)&__that->ViewRectCompensated3D, 0x42u);
  this->S3DParams = __that->S3DParams;
  this->S3DDisplay = __that->S3DDisplay;
  this->pHAL = __that->pHAL;
}


void __userpurge Scaleform::Render::MatrixState::MatrixState(
        Scaleform::Render::MatrixState *this@<ecx>,
        int a2@<esi>,
        Scaleform::Render::HAL *phal)
{
  const vostok::math::float4x4 *v3; // xmm1_4
  const vostok::math::float4x4 *v4; // xmm0_4
  const vostok::math::float4x4 *v5; // xmm0_4
  const vostok::math::float4x4 *v6; // xmm0_4
  const vostok::math::float4x4 *v7; // xmm1_4
  const vostok::math::float4x4 *v8; // xmm0_4
  const vostok::math::float4x4 *v9; // xmm0_4
  const vostok::math::float4x4 *v10; // xmm0_4

  v3 = clear_value;
  *(_DWORD *)a2 = &Scaleform::RefCountImplCore::`vftable';
  *(_DWORD *)(a2 + 4) = 1;
  *(_DWORD *)a2 = &Scaleform::Render::MatrixState::`vftable';
  *(_DWORD *)(a2 + 16) = v3;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = v3;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  memset((unsigned __int8 *)(a2 + 48), 0, 0x30u);
  v4 = clear_value;
  *(_DWORD *)(a2 + 48) = clear_value;
  *(_DWORD *)(a2 + 68) = v4;
  *(_DWORD *)(a2 + 88) = v4;
  memset((unsigned __int8 *)(a2 + 96), 0, 0x40u);
  v5 = clear_value;
  *(_DWORD *)(a2 + 96) = clear_value;
  *(_DWORD *)(a2 + 116) = v5;
  *(_DWORD *)(a2 + 136) = v5;
  *(_DWORD *)(a2 + 156) = v5;
  memset((unsigned __int8 *)(a2 + 160), 0, 0x40u);
  v6 = clear_value;
  *(_DWORD *)(a2 + 160) = clear_value;
  *(_DWORD *)(a2 + 180) = v6;
  *(_DWORD *)(a2 + 200) = v6;
  *(_DWORD *)(a2 + 220) = v6;
  memset((unsigned __int8 *)(a2 + 224), 0, 0x40u);
  v7 = clear_value;
  *(_DWORD *)(a2 + 224) = clear_value;
  *(_DWORD *)(a2 + 244) = v7;
  *(_DWORD *)(a2 + 264) = v7;
  *(_DWORD *)(a2 + 284) = v7;
  *(_DWORD *)(a2 + 288) = v7;
  *(_DWORD *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  *(_DWORD *)(a2 + 300) = 0;
  *(_DWORD *)(a2 + 304) = 0;
  *(_DWORD *)(a2 + 308) = v7;
  *(_DWORD *)(a2 + 312) = 0;
  *(_DWORD *)(a2 + 316) = 0;
  *(_DWORD *)(a2 + 320) = v7;
  *(_DWORD *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 328) = 0;
  *(_DWORD *)(a2 + 332) = 0;
  *(_DWORD *)(a2 + 336) = 0;
  *(_DWORD *)(a2 + 340) = v7;
  *(_DWORD *)(a2 + 344) = 0;
  *(_DWORD *)(a2 + 348) = 0;
  *(_DWORD *)(a2 + 352) = v7;
  *(_DWORD *)(a2 + 356) = 0;
  *(_DWORD *)(a2 + 360) = 0;
  *(_DWORD *)(a2 + 364) = 0;
  *(_DWORD *)(a2 + 368) = 0;
  *(_DWORD *)(a2 + 372) = v7;
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 380) = 0;
  memset((unsigned __int8 *)(a2 + 384), 0, 0x40u);
  v8 = clear_value;
  *(_DWORD *)(a2 + 384) = clear_value;
  *(_DWORD *)(a2 + 404) = v8;
  *(_DWORD *)(a2 + 424) = v8;
  *(_DWORD *)(a2 + 444) = v8;
  *(_DWORD *)(a2 + 448) = 0;
  *(_DWORD *)(a2 + 452) = 0;
  *(_DWORD *)(a2 + 456) = 0;
  *(_DWORD *)(a2 + 460) = 0;
  *(_DWORD *)(a2 + 464) = 0;
  *(_DWORD *)(a2 + 468) = 0;
  *(_DWORD *)(a2 + 472) = 0;
  *(_DWORD *)(a2 + 476) = 0;
  *(_DWORD *)(a2 + 480) = v8;
  *(_DWORD *)(a2 + 484) = 0;
  *(_DWORD *)(a2 + 488) = 0;
  *(_DWORD *)(a2 + 492) = 0;
  *(_DWORD *)(a2 + 496) = 0;
  *(_DWORD *)(a2 + 500) = v8;
  *(_DWORD *)(a2 + 504) = 0;
  *(_DWORD *)(a2 + 508) = 0;
  memset((unsigned __int8 *)(a2 + 512), 0, 0x40u);
  v9 = clear_value;
  *(_DWORD *)(a2 + 512) = clear_value;
  *(_DWORD *)(a2 + 532) = v9;
  *(_DWORD *)(a2 + 552) = v9;
  *(_DWORD *)(a2 + 572) = v9;
  memset((unsigned __int8 *)(a2 + 576), 0, 0x40u);
  v10 = clear_value;
  *(_DWORD *)(a2 + 576) = clear_value;
  *(_DWORD *)(a2 + 596) = v10;
  *(_DWORD *)(a2 + 616) = v10;
  *(_DWORD *)(a2 + 636) = v10;
  *(_BYTE *)(a2 + 640) = 0;
  *(_BYTE *)(a2 + 641) = 0;
  *(_DWORD *)(a2 + 644) = 0;
  *(_DWORD *)(a2 + 648) = 1061158912;
  *(_DWORD *)(a2 + 652) = 1112539136;
  *(_DWORD *)(a2 + 656) = 1058013184;
  *(_DWORD *)(a2 + 660) = 1087163597;
  *(_DWORD *)(a2 + 664) = 0;
  *(_DWORD *)(a2 + 668) = phal;
}


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
