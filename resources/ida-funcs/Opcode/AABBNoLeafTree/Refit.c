char __thiscall Opcode::AABBNoLeafTree::Refit(
        Opcode::AABBNoLeafTree *this,
        const Opcode::MeshInterface *mesh_interface)
{
  unsigned int mNbNodes; // esi
  int i; // edx
  int v7; // edx
  char *v8; // ebx
  unsigned int v9; // eax
  const IceMaths::Point *mVerts; // edi
  const IceMaths::IndexedTriangle *v11; // esi
  int *v12; // eax
  int *v13; // edx
  int *v14; // esi
  unsigned int v18; // eax
  const IceMaths::Point *v19; // edi
  const IceMaths::IndexedTriangle *v20; // esi
  int *v21; // eax
  int *v22; // edx
  int *v23; // esi
  int v24; // [esp+48h] [ebp-9Ch]
  Opcode::AABBNoLeafTree *v25; // [esp+4Ch] [ebp-98h]
  int v26; // [esp+50h] [ebp-94h]
  int v27; // [esp+54h] [ebp-90h]
  int v28; // [esp+58h] [ebp-8Ch]
  int v29; // [esp+5Ch] [ebp-88h]
  int v30; // [esp+60h] [ebp-84h]
  int v31; // [esp+64h] [ebp-80h]
  int v32; // [esp+68h] [ebp-7Ch]
  int v33; // [esp+6Ch] [ebp-78h]
  int v34; // [esp+70h] [ebp-74h]
  int v35; // [esp+74h] [ebp-70h]
  int v36; // [esp+78h] [ebp-6Ch]
  int v37; // [esp+7Ch] [ebp-68h]
  unsigned int v38; // [esp+80h] [ebp-64h]
  int v39; // [esp+84h] [ebp-60h]
  int v40; // [esp+88h] [ebp-5Ch]
  int v41; // [esp+8Ch] [ebp-58h]
  int v42; // [esp+90h] [ebp-54h]
  int v43; // [esp+94h] [ebp-50h]
  int v44; // [esp+98h] [ebp-4Ch]
  int v45; // [esp+9Ch] [ebp-48h]
  int v46; // [esp+A0h] [ebp-44h]
  int v47; // [esp+A4h] [ebp-40h]
  int v48; // [esp+A8h] [ebp-3Ch]
  int v49; // [esp+ACh] [ebp-38h]
  int v50; // [esp+B0h] [ebp-34h]
  int v51; // [esp+B4h] [ebp-30h]
  int v52; // [esp+B8h] [ebp-2Ch]
  int v53; // [esp+BCh] [ebp-28h]
  int v54; // [esp+C0h] [ebp-24h]
  int v55; // [esp+C4h] [ebp-20h]
  int v56; // [esp+C8h] [ebp-1Ch]
  int v57; // [esp+CCh] [ebp-18h]
  int v58; // [esp+D0h] [ebp-14h]
  int v59; // [esp+D4h] [ebp-10h]
  int v60; // [esp+D8h] [ebp-Ch]
  int v61; // [esp+DCh] [ebp-8h]
  int v62; // [esp+E0h] [ebp-4h]
  float v63; // [esp+E4h] [ebp+0h]
  float v64; // [esp+E8h] [ebp+4h]
  float v65; // [esp+ECh] [ebp+8h]
  float v66; // [esp+F0h] [ebp+Ch]
  float v67; // [esp+F4h] [ebp+10h]
  float v68; // [esp+F8h] [ebp+14h]
  float v69; // [esp+FCh] [ebp+18h]
  float v70; // [esp+100h] [ebp+1Ch]
  float v71; // [esp+104h] [ebp+20h]
  float v72; // [esp+108h] [ebp+24h]
  float v73; // [esp+10Ch] [ebp+28h]
  float v74; // [esp+110h] [ebp+2Ch]
  float v75; // [esp+114h] [ebp+30h]
  float v76; // [esp+118h] [ebp+34h]
  float v77; // [esp+11Ch] [ebp+38h]
  float v78; // [esp+120h] [ebp+3Ch]
  float v79; // [esp+124h] [ebp+40h]
  float v80; // [esp+128h] [ebp+44h]
  float v81; // [esp+12Ch] [ebp+48h]
  float v82; // [esp+130h] [ebp+4Ch]
  float v83; // [esp+134h] [ebp+50h]
  float v84; // [esp+138h] [ebp+54h]
  float v85; // [esp+13Ch] [ebp+58h]
  float v86; // [esp+140h] [ebp+5Ch]
  float v87; // [esp+144h] [ebp+60h]
  float v88; // [esp+148h] [ebp+64h]
  float v89; // [esp+14Ch] [ebp+68h]
  float v90; // [esp+150h] [ebp+6Ch]
  float v91; // [esp+154h] [ebp+70h]
  float v92; // [esp+160h] [ebp+7Ch]

  v25 = this;
  if ( !mesh_interface )
    return 0;
  mNbNodes = this->mNbNodes;
  if ( mNbNodes )
  {
    for ( i = 32 * mNbNodes; ; i = v36 )
    {
      v7 = i - 32;
      v8 = (char *)this->mNodes + v7;
      v9 = *((_DWORD *)v8 + 6);
      v38 = mNbNodes - 1;
      v36 = v7;
      if ( (v9 & 1) != 0 )
      {
        mVerts = mesh_interface->mVerts;
        v11 = &mesh_interface->mTris[v9 >> 1];
        v12 = (int *)&mVerts[v11->mVRef[0]];
        v13 = (int *)&mVerts[v11->mVRef[1]];
        v30 = *v12;
        v14 = (int *)&mVerts[v11->mVRef[2]];
        v32 = *v13;
        v34 = *v14;
        __asm
        {
          fld     [ebp+74h+var_F8]
          fld     [ebp+74h+var_F0]
          fld     [ebp+74h+var_E8]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [ebp+74h+var_54]
          fcompp
        }
        v85 = v71;
        v24 = *v12;
        v59 = *v13;
        v39 = *v14;
        __asm
        {
          fld     [ebp+74h+var_110]
          fld     [ebp+74h+var_84]
          fld     [ebp+74h+var_D4]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [ebp+74h+var_5C]
          fcompp
        }
        v88 = v69;
        v55 = v12[1];
        v37 = v13[1];
        v57 = v14[1];
        __asm
        {
          fld     [ebp+74h+var_94]
          fld     [ebp+74h+var_DC]
          fld     [ebp+74h+var_8C]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [ebp+74h+var_50]
          fcompp
        }
        v86 = v72;
        v35 = v55;
        v53 = v37;
        v27 = v57;
        __asm
        {
          fld     [ebp+74h+var_E4]
          fld     [ebp+74h+var_9C]
          fld     [ebp+74h+var_104]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [ebp+74h+var_28]
          fcompp
        }
        v89 = v82;
        v49 = v12[2];
        v62 = v13[2];
        v51 = v14[2];
        __asm
        {
          fld     [ebp+74h+var_AC]
          fld     [ebp+74h+var_78]
          fld     [ebp+74h+var_A4]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [ebp+74h+var_48]
          fcompp
        }
        v87 = v74;
        v28 = v49;
        v47 = v62;
        v33 = v51;
        __asm
        {
          fld     [ebp+74h+var_100]
          fld     [ebp+74h+var_B4]
          fld     [ebp+74h+var_EC]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [ebp+74h+var_30]
          fcompp
        }
        v90 = v80;
      }
      else
      {
        v85 = *(float *)v9 - *(float *)(v9 + 12);
        v86 = *(float *)(v9 + 4) - *(float *)(v9 + 16);
        v87 = *(float *)(v9 + 8) - *(float *)(v9 + 20);
        v88 = *(float *)(v9 + 12) + *(float *)v9;
        v89 = *(float *)(v9 + 16) + *(float *)(v9 + 4);
        v90 = *(float *)(v9 + 20) + *(float *)(v9 + 8);
      }
      v18 = *((_DWORD *)v8 + 7);
      if ( (v18 & 1) != 0 )
      {
        v19 = mesh_interface->mVerts;
        v20 = &mesh_interface->mTris[v18 >> 1];
        v21 = (int *)&v19[v20->mVRef[0]];
        v22 = (int *)&v19[v20->mVRef[1]];
        v43 = *v21;
        v23 = (int *)&v19[v20->mVRef[2]];
        v31 = *v22;
        v45 = *v23;
        __asm
        {
          fld     [ebp+74h+var_C4]
          fld     [ebp+74h+var_F4]
          fld     [ebp+74h+var_BC]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [ebp+74h+var_58]
          fcompp
        }
        v63 = v70;
        v29 = *v21;
        v41 = *v22;
        v26 = *v23;
        __asm
        {
          fld     [ebp+74h+var_FC]
          fld     [ebp+74h+var_CC]
          fld     [ebp+74h+var_108]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [ebp+74h+var_38]
          fcompp
        }
        v66 = v78;
        v58 = v21[1];
        v60 = v22[1];
        v61 = v23[1];
        __asm
        {
          fld     [ebp+74h+var_88]
          fld     [ebp+74h+var_80]
          fld     [ebp+74h+var_7C]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [ebp+74h+var_40]
          fcompp
        }
        v64 = v76;
        v52 = v58;
        v54 = v60;
        v56 = v61;
        __asm
        {
          fld     [ebp+74h+var_A0]
          fld     [ebp+74h+var_98]
          fld     [ebp+74h+var_90]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [ebp+74h+var_20]
          fcompp
        }
        v67 = v84;
        v46 = v21[2];
        v48 = v22[2];
        v50 = v23[2];
        __asm
        {
          fld     [ebp+74h+var_B8]
          fld     [ebp+74h+var_B0]
          fld     [ebp+74h+var_A8]
          fcomi   st, st(1)
          fcmovnb st, st(1)
          fcomi   st, st(2)
          fcmovnb st, st(2)
          fstp    [ebp+74h+var_44]
          fcompp
        }
        v65 = v75;
        v40 = v46;
        v42 = v48;
        v44 = v50;
        __asm
        {
          fld     [ebp+74h+var_D0]
          fld     [ebp+74h+var_C8]
          fld     [ebp+74h+var_C0]
          fcomi   st, st(1)
          fcmovb  st, st(1)
          fcomi   st, st(2)
          fcmovb  st, st(2)
          fstp    [ebp+74h+var_24]
          fcompp
        }
        v68 = v83;
      }
      else
      {
        v63 = *(float *)v18 - *(float *)(v18 + 12);
        v64 = *(float *)(v18 + 4) - *(float *)(v18 + 16);
        v65 = *(float *)(v18 + 8) - *(float *)(v18 + 20);
        v66 = *(float *)v18 + *(float *)(v18 + 12);
        v67 = *(float *)(v18 + 16) + *(float *)(v18 + 4);
        v68 = *(float *)(v18 + 20) + *(float *)(v18 + 8);
      }
      __asm
      {
        fld     [ebp+74h+var_1C]
        fld     [ebp+74h+var_74]
        fcomi   st, st(1)
        fcmovnb st, st(1)
        fstp    [ebp+74h+arg_0]
        fcomp   st(1)
      }
      __asm
      {
        fld     [ebp+74h+var_10]
        fld     [ebp+74h+var_68]
        fcomi   st, st(1)
        fcmovb  st, st(1)
        fstp    [ebp+74h+var_2C]
        fcomp   st(1)
      }
      __asm
      {
        fld     [ebp+74h+var_18]
        fld     [ebp+74h+var_70]
        fcomi   st, st(1)
        fcmovnb st, st(1)
        fstp    [ebp+74h+var_4]
        fcomp   st(1)
      }
      __asm
      {
        fld     [ebp+74h+var_C]
        fld     [ebp+74h+var_64]
        fcomi   st, st(1)
        fcmovb  st, st(1)
        fstp    [ebp+74h+var_34]
        fcomp   st(1)
      }
      __asm
      {
        fld     [ebp+74h+var_14]
        fld     [ebp+74h+var_6C]
        fcomi   st, st(1)
        fcmovnb st, st(1)
        fstp    [ebp+74h+var_3C]
        fcomp   st(1)
      }
      __asm
      {
        fld     [ebp+74h+var_8]
        fld     [ebp+74h+var_60]
        fcomi   st, st(1)
        fcmovb  st, st(1)
        fstp    [ebp+74h+var_4C]
        fcomp   st(1)
      }
      *(float *)v8 = (float)(v92 + v81) * 0.5;
      *((float *)v8 + 1) = (float)(v79 + v91) * 0.5;
      *((float *)v8 + 2) = (float)(v73 + v77) * 0.5;
      *((float *)v8 + 3) = (float)(v81 - v92) * 0.5;
      *((float *)v8 + 4) = (float)(v79 - v91) * 0.5;
      *((float *)v8 + 5) = (float)(v73 - v77) * 0.5;
      mNbNodes = v38;
      if ( !v38 )
        break;
      this = v25;
    }
  }
  return 1;
}
