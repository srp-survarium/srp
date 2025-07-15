char __thiscall Opcode::AABBNoLeafTree::Refit(
        Opcode::AABBNoLeafTree *this,
        const Opcode::MeshInterface *mesh_interface)
{
  Opcode::AABBNoLeafTree *v2; // eax
  unsigned int mNbNodes; // edx
  int v5; // ecx
  Opcode::AABBNoLeafNode *mNodes; // ebx
  unsigned int mPosData; // eax
  Opcode::AABBNoLeafNode *v8; // ebx
  const IceMaths::Point *mVerts; // edi
  const IceMaths::IndexedTriangle *v10; // esi
  int *v11; // eax
  int *v12; // edx
  int *v13; // esi
  unsigned int mNegData; // eax
  const IceMaths::Point *v18; // edi
  const IceMaths::IndexedTriangle *v19; // esi
  int *v20; // eax
  int *v21; // edx
  int *v22; // esi
  float v23; // xmm1_4
  float v24; // xmm4_4
  float v25; // [esp+4h] [ebp-158h]
  float v26; // [esp+8h] [ebp-154h]
  float Max; // [esp+Ch] [ebp-150h]
  float Max_4; // [esp+10h] [ebp-14Ch]
  float Max_8; // [esp+14h] [ebp-148h]
  float Min; // [esp+18h] [ebp-144h]
  float Min_4; // [esp+1Ch] [ebp-140h]
  float Min_8; // [esp+20h] [ebp-13Ch]
  float v33; // [esp+24h] [ebp-138h]
  float v34; // [esp+28h] [ebp-134h]
  unsigned int Index; // [esp+2Ch] [ebp-130h]
  float v36; // [esp+30h] [ebp-12Ch]
  float v37; // [esp+34h] [ebp-128h]
  float v38; // [esp+38h] [ebp-124h]
  float v39; // [esp+3Ch] [ebp-120h]
  float v40; // [esp+40h] [ebp-11Ch]
  float v41; // [esp+44h] [ebp-118h]
  float v42; // [esp+48h] [ebp-114h]
  float v43; // [esp+4Ch] [ebp-110h]
  float v44; // [esp+50h] [ebp-10Ch]
  float v45; // [esp+54h] [ebp-108h]
  float Max_; // [esp+58h] [ebp-104h]
  float Max__4; // [esp+5Ch] [ebp-100h]
  float Max__8; // [esp+60h] [ebp-FCh]
  float v49; // [esp+64h] [ebp-F8h]
  float v50; // [esp+68h] [ebp-F4h]
  float v51; // [esp+6Ch] [ebp-F0h]
  float v52; // [esp+70h] [ebp-ECh]
  float Min_; // [esp+74h] [ebp-E8h]
  float Min__4; // [esp+78h] [ebp-E4h]
  float Min__8; // [esp+7Ch] [ebp-E0h]
  int v56; // [esp+80h] [ebp-DCh]
  int v57; // [esp+84h] [ebp-D8h]
  int v58; // [esp+88h] [ebp-D4h]
  int v59; // [esp+8Ch] [ebp-D0h]
  int v60; // [esp+90h] [ebp-CCh]
  int v61; // [esp+94h] [ebp-C8h]
  int v62; // [esp+98h] [ebp-C4h]
  int v63; // [esp+9Ch] [ebp-C0h]
  int v64; // [esp+A0h] [ebp-BCh]
  int v65; // [esp+A4h] [ebp-B8h]
  int v66; // [esp+A8h] [ebp-B4h]
  int v67; // [esp+ACh] [ebp-B0h]
  int v68; // [esp+B0h] [ebp-ACh]
  int v69; // [esp+B4h] [ebp-A8h]
  int v70; // [esp+B8h] [ebp-A4h]
  int v71; // [esp+BCh] [ebp-A0h]
  int v72; // [esp+C0h] [ebp-9Ch]
  int v73; // [esp+C4h] [ebp-98h]
  int v74; // [esp+C8h] [ebp-94h]
  int v75; // [esp+CCh] [ebp-90h]
  int v76; // [esp+D0h] [ebp-8Ch]
  int v77; // [esp+D4h] [ebp-88h]
  int v78; // [esp+D8h] [ebp-84h]
  int v79; // [esp+DCh] [ebp-80h]
  int v80; // [esp+E0h] [ebp-7Ch]
  int v81; // [esp+E4h] [ebp-78h]
  int v82; // [esp+E8h] [ebp-74h]
  int v83; // [esp+ECh] [ebp-70h]
  int v84; // [esp+F0h] [ebp-6Ch]
  int v85; // [esp+F4h] [ebp-68h]
  int v86; // [esp+F8h] [ebp-64h]
  int v87; // [esp+FCh] [ebp-60h]
  int v88; // [esp+10Ch] [ebp-50h]
  int v89; // [esp+11Ch] [ebp-40h]
  int v90; // [esp+12Ch] [ebp-30h]
  int v91; // [esp+13Ch] [ebp-20h]

  v2 = this;
  if ( !mesh_interface )
    return 0;
  mNbNodes = this->mNbNodes;
  if ( mNbNodes )
  {
    v5 = mNbNodes;
    while ( 1 )
    {
      mNodes = v2->mNodes;
      mPosData = mNodes[--v5].mPosData;
      v8 = &mNodes[v5];
      Index = --mNbNodes;
      if ( (mPosData & 1) != 0 )
      {
        mVerts = mesh_interface->mVerts;
        v10 = &mesh_interface->mTris[mPosData >> 1];
        v11 = (int *)&mVerts[v10->mVRef[0]];
        v12 = (int *)&mVerts[v10->mVRef[1]];
        v84 = *v11;
        v13 = (int *)&mVerts[v10->mVRef[2]];
        v82 = *v12;
        v80 = *v13;
        __asm
        {
          fld     [esp+168h+var_6C]
          fld     [esp+168h+var_74]
          fld     [esp+168h+var_7C]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [esp+168h+var_108]
          fcompp
        }
        Min = v45;
        v59 = *v11;
        v90 = *v12;
        v86 = *v13;
        __asm
        {
          fld     [esp+168h+var_D0]
          fld     [esp+168h+var_30]
          fld     [esp+168h+var_64]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [esp+168h+var_F8]
          fcompp
        }
        Max = v49;
        v88 = v11[1];
        v61 = v12[1];
        v79 = v13[1];
        __asm
        {
          fld     [esp+168h+var_50]
          fld     [esp+168h+var_C8]
          fld     [esp+168h+var_80]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [esp+168h+var_F0]
          fcompp
        }
        Min_4 = v51;
        v65 = v88;
        v81 = v61;
        v63 = v79;
        __asm
        {
          fld     [esp+168h+var_B8]
          fld     [esp+168h+var_78]
          fld     [esp+168h+var_C0]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [esp+168h+var_EC]
          fcompp
        }
        Max_4 = v52;
        v83 = v11[2];
        v67 = v12[2];
        v56 = v13[2];
        __asm
        {
          fld     [esp+168h+var_70]
          fld     [esp+168h+var_B0]
          fld     [esp+168h+var_DC]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [esp+168h+var_12C]
          fcompp
        }
        Min_8 = v36;
        v71 = v83;
        v89 = v67;
        v69 = v56;
        __asm
        {
          fld     [esp+168h+var_A0]
          fld     [esp+168h+var_40]
          fld     [esp+168h+var_A8]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [esp+168h+var_10C]
          fcompp
        }
        mNbNodes = Index;
        Max_8 = v44;
      }
      else
      {
        Min = *(float *)mPosData - *(float *)(mPosData + 12);
        Max = *(float *)(mPosData + 12) + *(float *)mPosData;
        Min_4 = *(float *)(mPosData + 4) - *(float *)(mPosData + 16);
        Max_4 = *(float *)(mPosData + 16) + *(float *)(mPosData + 4);
        Min_8 = *(float *)(mPosData + 8) - *(float *)(mPosData + 20);
        Max_8 = *(float *)(mPosData + 20) + *(float *)(mPosData + 8);
      }
      mNegData = v8->mNegData;
      if ( (mNegData & 1) != 0 )
      {
        v18 = mesh_interface->mVerts;
        v19 = &mesh_interface->mTris[mNegData >> 1];
        v20 = (int *)&v18[v19->mVRef[0]];
        v21 = (int *)&v18[v19->mVRef[1]];
        v91 = *v20;
        v22 = (int *)&v18[v19->mVRef[2]];
        v73 = *v21;
        v85 = *v22;
        __asm
        {
          fld     [esp+168h+var_20]
          fld     [esp+168h+var_98]
          fld     [esp+168h+var_68]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [esp+168h+var_124]
          fcompp
        }
        Min_ = v38;
        v77 = *v20;
        v87 = *v21;
        v75 = *v22;
        __asm
        {
          fld     [esp+168h+var_88]
          fld     [esp+168h+var_60]
          fld     [esp+168h+var_90]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [esp+168h+var_F4]
          fcompp
        }
        Max_ = v50;
        v60 = v20[1];
        v58 = v21[1];
        v57 = v22[1];
        __asm
        {
          fld     [esp+168h+var_CC]
          fld     [esp+168h+var_D4]
          fld     [esp+168h+var_D8]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [esp+168h+var_11C]
          fcompp
        }
        Min__4 = v40;
        v66 = v60;
        v64 = v58;
        v62 = v57;
        __asm
        {
          fld     [esp+168h+var_B4]
          fld     [esp+168h+var_BC]
          fld     [esp+168h+var_C4]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [esp+168h+var_138]
          fcompp
        }
        Max__4 = v33;
        v72 = v20[2];
        v70 = v21[2];
        v68 = v22[2];
        __asm
        {
          fld     [esp+168h+var_9C]
          fld     [esp+168h+var_A4]
          fld     [esp+168h+var_AC]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [esp+168h+var_114]
          fcompp
        }
        Min__8 = v42;
        v78 = v72;
        v76 = v70;
        v74 = v68;
        __asm
        {
          fld     [esp+168h+var_84]
          fld     [esp+168h+var_8C]
          fld     [esp+168h+var_94]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [esp+168h+var_134]
          fcompp
        }
        mNbNodes = Index;
        Max__8 = v34;
      }
      else
      {
        v23 = *(float *)(mNegData + 4);
        v24 = *(float *)(mNegData + 8);
        Min_ = *(float *)mNegData - *(float *)(mNegData + 12);
        Max_ = *(float *)mNegData + *(float *)(mNegData + 12);
        Min__4 = v23 - *(float *)(mNegData + 16);
        Max__4 = *(float *)(mNegData + 16) + v23;
        Min__8 = v24 - *(float *)(mNegData + 20);
        Max__8 = *(float *)(mNegData + 20) + v24;
      }
      __asm
      {
        fld     [esp+168h+Min.x]
        fld     [esp+168h+Min_.x]
        fcomi   st, st(1)
        fcmovnb st, st(1)
        fstp    [esp+168h+var_154]
        fcomp   st(1)
      }
      __asm
      {
        fld     [esp+168h+Max.x]
        fld     [esp+168h+Max_.x]
        fcomi   st, st(1)
        fcmovb  st, st(1)
        fstp    [esp+168h+var_128]
        fcomp   st(1)
      }
      __asm
      {
        fld     [esp+168h+Min.y]
        fld     [esp+168h+Min_.y]
        fcomi   st, st(1)
        fcmovnb st, st(1)
        fstp    [esp+168h+var_158]
        fcomp   st(1)
      }
      __asm
      {
        fld     [esp+168h+Max.y]
        fld     [esp+168h+Max_.y]
        fcomi   st, st(1)
        fcmovb  st, st(1)
        fstp    [esp+168h+var_120]
        fcomp   st(1)
      }
      __asm
      {
        fld     [esp+168h+Min.z]
        fld     [esp+168h+Min_.z]
        fcomi   st, st(1)
        fcmovnb st, st(1)
        fstp    [esp+168h+var_118]
        fcomp   st(1)
      }
      __asm
      {
        fld     [esp+168h+Max.z]
        fld     [esp+168h+Max_.z]
        fcomi   st, st(1)
        fcmovb  st, st(1)
        fstp    [esp+168h+var_110]
        fcomp   st(1)
      }
      v8->mAABB.mCenter.x = (float)(v26 + v37) * 0.5;
      v8->mAABB.mCenter.y = (float)(v39 + v25) * 0.5;
      v8->mAABB.mCenter.z = (float)(v43 + v41) * 0.5;
      v8->mAABB.mExtents.x = (float)(v37 - v26) * 0.5;
      v8->mAABB.mExtents.y = (float)(v39 - v25) * 0.5;
      v8->mAABB.mExtents.z = (float)(v43 - v41) * 0.5;
      if ( !mNbNodes )
        break;
      v2 = this;
    }
  }
  return 1;
}
