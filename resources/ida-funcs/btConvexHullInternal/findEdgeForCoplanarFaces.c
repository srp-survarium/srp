void __userpurge btConvexHullInternal::findEdgeForCoplanarFaces(
        btConvexHullInternal::Vertex *c1@<edx>,
        btConvexHullInternal *this,
        btConvexHullInternal::Vertex *c0,
        btConvexHullInternal::Edge **e0,
        btConvexHullInternal::Edge **e1,
        btConvexHullInternal::Vertex *stop0,
        btConvexHullInternal::Vertex *stop1)
{
  btConvexHullInternal::Edge *v7; // ecx
  btConvexHullInternal::Edge **v8; // ebx
  btConvexHullInternal::Edge *v9; // eax
  btConvexHullInternal::Vertex *target; // esi
  int *p_x; // esi
  btConvexHullInternal::Point32 *p_point; // esi
  int *p_y; // esi
  btConvexHullInternal::Point32 *v14; // esi
  int v15; // eax
  btConvexHullInternal::Point32 *v16; // eax
  btConvexHullInternal::Point32 *v17; // ecx
  btConvexHullInternal::Edge *v18; // eax
  btConvexHullInternal::Edge *prev; // edi
  __int64 v20; // rax
  __int64 v21; // rax
  btConvexHullInternal::Edge **v22; // eax
  btConvexHullInternal::Edge *next; // edi
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // kr00_8
  bool v27; // cc
  btConvexHullInternal::Edge *v28; // eax
  btConvexHullInternal::Vertex *v29; // ebx
  int *v30; // ebx
  __int64 v31; // rax
  unsigned int v32; // esi
  int v33; // ecx
  __int64 v34; // rax
  btConvexHullInternal::Edge *v35; // eax
  btConvexHullInternal::Vertex *v36; // ebx
  int v37; // eax
  btConvexHullInternal::Point32 *v38; // ebx
  int v39; // edi
  const btConvexHullInternal::Rational64 *v40; // eax
  const btConvexHullInternal::Rational64 *v41; // edi
  btConvexHullInternal::Rational64 *v42; // ecx
  btConvexHullInternal::Rational64 *v43; // eax
  const btConvexHullInternal::Rational64 *v44; // eax
  const btConvexHullInternal::Rational64 *v45; // edi
  btConvexHullInternal::Rational64 *v46; // ecx
  btConvexHullInternal::Rational64 *v47; // eax
  int *v48; // esi
  btConvexHullInternal::Edge *v49; // eax
  btConvexHullInternal::Vertex *v50; // ebx
  btConvexHullInternal::Point32 *v51; // ebx
  __int64 v52; // rax
  unsigned int v53; // esi
  int v54; // ecx
  __int64 v55; // rax
  btConvexHullInternal::Edge *v56; // eax
  btConvexHullInternal::Vertex *v57; // ebx
  int v58; // eax
  int *v59; // ebx
  int v60; // edi
  const btConvexHullInternal::Rational64 *v61; // eax
  const btConvexHullInternal::Rational64 *v62; // edi
  btConvexHullInternal::Rational64 *v63; // ecx
  btConvexHullInternal::Rational64 *v64; // eax
  const btConvexHullInternal::Rational64 *v65; // eax
  const btConvexHullInternal::Rational64 *v66; // edi
  btConvexHullInternal::Rational64 *v67; // ecx
  btConvexHullInternal::Rational64 *v68; // eax
  const btConvexHullInternal::Point32 *v69; // [esp+0h] [ebp-120h]
  const btConvexHullInternal::Point32 *v70; // [esp+0h] [ebp-120h]
  int v71[6]; // [esp+10h] [ebp-110h] BYREF
  int v72[6]; // [esp+28h] [ebp-F8h] BYREF
  btConvexHullInternal::Point64 v73; // [esp+40h] [ebp-E0h] BYREF
  btConvexHullInternal::Point64 v74; // [esp+58h] [ebp-C8h] BYREF
  btConvexHullInternal::Point32 v75; // [esp+70h] [ebp-B0h] BYREF
  btConvexHullInternal::Point32 v76; // [esp+80h] [ebp-A0h] BYREF
  btConvexHullInternal::Point32 v77; // [esp+90h] [ebp-90h] BYREF
  __int64 v78; // [esp+A0h] [ebp-80h]
  __int64 v79; // [esp+A8h] [ebp-78h]
  __int64 v80; // [esp+B0h] [ebp-70h]
  btConvexHullInternal::Point32 v81; // [esp+B8h] [ebp-68h] BYREF
  __int64 v82; // [esp+C8h] [ebp-58h]
  __int64 v83; // [esp+D0h] [ebp-50h]
  btConvexHullInternal::Point64 v84; // [esp+D8h] [ebp-48h] BYREF
  int z; // [esp+F0h] [ebp-30h]
  int index; // [esp+F4h] [ebp-2Ch]
  btConvexHullInternal::Point32 v87; // [esp+F8h] [ebp-28h] BYREF
  __int64 v88; // [esp+108h] [ebp-18h]
  __int64 v89; // [esp+110h] [ebp-10h]
  __int64 v90; // [esp+118h] [ebp-8h]
  btConvexHullInternal::Point32 *v91; // [esp+12Ch] [ebp+Ch]
  btConvexHullInternal::Point32 *v92; // [esp+12Ch] [ebp+Ch]
  btConvexHullInternal::Edge *reverse; // [esp+12Ch] [ebp+Ch]
  btConvexHullInternal::Edge *v94; // [esp+12Ch] [ebp+Ch]
  btConvexHullInternal::Edge *v95; // [esp+12Ch] [ebp+Ch]
  btConvexHullInternal::Edge *v96; // [esp+12Ch] [ebp+Ch]

  v7 = *e1;
  v8 = e0;
  v9 = *e0;
  HIDWORD(v83) = v9;
  HIDWORD(v82) = v7;
  if ( v9 )
    target = v9->target;
  else
    target = c0;
  p_x = &target->point.x;
  v87.x = *p_x++;
  v87.y = *p_x++;
  v87.z = *p_x;
  v87.index = p_x[1];
  if ( v7 )
    p_point = &v7->target->point;
  else
    p_point = &c1->point;
  LODWORD(v84.z) = p_point->x;
  p_y = &p_point->y;
  HIDWORD(v84.z) = *p_y++;
  z = *p_y;
  index = p_y[1];
  v14 = &c0->point;
  btConvexHullInternal::Point32::operator-(&c0->point, (btConvexHullInternal::Point32 *)&v84, &c1->point, v69);
  v15 = HIDWORD(v83);
  if ( !HIDWORD(v83) )
    v15 = HIDWORD(v82);
  v16 = btConvexHullInternal::Point32::operator-(
          v14,
          &v77,
          (btConvexHullInternal::Point32 *)(*(_DWORD *)(v15 + 12) + 88),
          v70);
  btConvexHullInternal::Point32::cross((const btConvexHullInternal::Point32 *)&v84, &v73, v16);
  v88 = btConvexHullInternal::Point32::dot(&v73, v14);
  btConvexHullInternal::Point32::cross(v17, (int)&v74, &v84, &v73);
  v89 = btConvexHullInternal::Point32::dot(&v74, &v87);
  v18 = *e0;
  if ( *e0 )
  {
    while ( v18->target )
    {
      prev = (*e0)->reverse->prev;
      v91 = &prev->target->point;
      v20 = btConvexHullInternal::Point32::dot(&v73, v91);
      if ( v20 < v88 )
        break;
      if ( prev->copy == this->mergeStamp )
        break;
      v21 = btConvexHullInternal::Point32::dot(&v74, v91);
      if ( v21 <= v89 )
        break;
      *e0 = prev;
      v87.x = v91->x;
      v87.y = v91->y;
      v87.z = v91->z;
      v89 = v21;
      v18 = *e0;
      v87.index = v91->index;
    }
  }
  v90 = btConvexHullInternal::Point32::dot(&v74, (btConvexHullInternal::Point32 *)&v84.z);
  v22 = e1;
  if ( *e1 )
  {
    while ( (*v22)->target )
    {
      next = (*e1)->reverse->next;
      v92 = &next->target->point;
      v24 = btConvexHullInternal::Point32::dot(&v73, v92);
      if ( v24 < v88 )
        break;
      if ( next->copy == this->mergeStamp )
        break;
      v25 = btConvexHullInternal::Point32::dot(&v74, v92);
      if ( v25 <= v90 )
        break;
      LODWORD(v90) = v25;
      v22 = e1;
      *e1 = next;
      v84.z = *(_QWORD *)&v92->x;
      z = v92->z;
      HIDWORD(v90) = HIDWORD(v25);
      index = v92->index;
    }
  }
  v26 = v90 - v89;
  v27 = v90 < v89 || (unsigned __int64)(v90 - v89) >> 32 == 0;
  v90 -= v89;
  if ( v90 >= 0 && (!v27 || (_DWORD)v26) )
  {
    while ( 1 )
    {
      v88 = LODWORD(v84.x) * (LODWORD(v84.z) - v87.x)
          + (HIDWORD(v84.z) - v87.y) * HIDWORD(v84.x)
          + (z - v87.z) * LODWORD(v84.y);
      v28 = *v8;
      if ( !*v8 )
        goto LABEL_31;
      if ( !v28->target )
        goto LABEL_31;
      reverse = v28->next->reverse;
      if ( reverse->copy <= this->mergeStamp )
        goto LABEL_31;
      v29 = reverse->target;
      v75.index = -1;
      v30 = &v29->point.x;
      v75.x = *v30 - v87.x;
      v75.y = v30[1] - v87.y;
      v75.z = v30[2] - v87.z;
      v31 = btConvexHullInternal::Point32::dot(&v74, &v75);
      v32 = v31;
      v33 = LODWORD(v84.x) * (*v30 - v87.x);
      LODWORD(v31) = v30[1] - v87.y;
      HIDWORD(v79) = HIDWORD(v31);
      v34 = v33 + LODWORD(v84.y) * (v30[2] - v87.z) + HIDWORD(v84.x) * (int)v31;
      v78 = v34;
      if ( __PAIR64__(HIDWORD(v79), v32) )
      {
        if ( v79 < 0 )
        {
          btConvexHullInternal::Rational64::Rational64(
            (btConvexHullInternal::Rational64 *)(HIDWORD(v79) | v32),
            v72,
            v88,
            v90);
          v41 = v40;
          btConvexHullInternal::Rational64::Rational64(v42, v71, v78, __SPAIR64__(HIDWORD(v79), v32));
          if ( btConvexHullInternal::Rational64::compare(v41, v43) >= 0 )
            goto LABEL_41;
        }
LABEL_31:
        v35 = *e1;
        if ( !*e1 )
          return;
        if ( !v35->target )
          return;
        v94 = v35->reverse->next;
        if ( v94->copy <= this->mergeStamp )
          return;
        v36 = v94->target;
        v37 = v36->point.y - HIDWORD(v84.z);
        v81.index = -1;
        v38 = &v36->point;
        v39 = v38->x - LODWORD(v84.z);
        v81.y = v37;
        v81.z = v38->z - z;
        v81.x = v39;
        if ( btConvexHullInternal::Point32::dot(&v73, &v81) )
          return;
        v89 = btConvexHullInternal::Point32::dot(&v74, &v81);
        v77.index = -1;
        v82 = LODWORD(v84.x) * v39 + LODWORD(v84.y) * v81.z + HIDWORD(v84.x) * v81.y;
        v77.x = v38->x - v87.x;
        v77.y = v38->y - v87.y;
        v77.z = v38->z - v87.z;
        v80 = btConvexHullInternal::Point32::dot(&v74, &v77);
        if ( v80 <= 0 )
          return;
        if ( v89 )
        {
          if ( v89 >= 0 )
            return;
          btConvexHullInternal::Rational64::Rational64(0, v71, v88, v90);
          v45 = v44;
          btConvexHullInternal::Rational64::Rational64(v46, v72, v82, v89);
          if ( btConvexHullInternal::Rational64::compare(v45, v47) <= 0 )
            return;
        }
        else if ( v82 >= 0 )
        {
          return;
        }
        v48 = &v38->x;
        v8 = e0;
        LODWORD(v84.z) = *v48++;
        HIDWORD(v84.z) = *v48++;
        *e1 = v94;
        z = *v48;
        v90 = v80;
        index = v48[1];
      }
      else
      {
        if ( v34 >= 0 )
          goto LABEL_31;
LABEL_41:
        v87.x = *v30;
        v87.y = v30[1];
        v76.index = -1;
        v87.z = v30[2];
        v87.index = v30[3];
        v76.x = LODWORD(v84.z) - v87.x;
        v76.y = HIDWORD(v84.z) - v87.y;
        v76.z = z - v87.z;
        v90 = btConvexHullInternal::Point32::dot(&v74, &v76);
        v8 = e0;
        *e0 = HIDWORD(v83) != (_DWORD)*e0 ? reverse : 0;
      }
    }
  }
  if ( v26 < 0 )
  {
    while ( 1 )
    {
      v88 = LODWORD(v84.x) * (LODWORD(v84.z) - v87.x)
          + LODWORD(v84.y) * (z - v87.z)
          + HIDWORD(v84.x) * (HIDWORD(v84.z) - v87.y);
      v49 = *e1;
      if ( !*e1 )
        goto LABEL_52;
      if ( !v49->target )
        goto LABEL_52;
      v95 = v49->prev->reverse;
      if ( v95->copy <= this->mergeStamp )
        goto LABEL_52;
      v50 = v95->target;
      v77.index = -1;
      v51 = &v50->point;
      v77.x = v51->x - LODWORD(v84.z);
      v77.y = v51->y - HIDWORD(v84.z);
      v77.z = v51->z - z;
      v52 = btConvexHullInternal::Point32::dot(&v74, &v77);
      v53 = v52;
      v54 = LODWORD(v84.x) * (v51->x - LODWORD(v84.z));
      LODWORD(v52) = v51->y - HIDWORD(v84.z);
      HIDWORD(v80) = HIDWORD(v52);
      v55 = v54 + LODWORD(v84.y) * (v51->z - z) + HIDWORD(v84.x) * (int)v52;
      v78 = v55;
      if ( __PAIR64__(HIDWORD(v80), v53) )
      {
        if ( v80 < 0 )
        {
          btConvexHullInternal::Rational64::Rational64(
            (btConvexHullInternal::Rational64 *)(HIDWORD(v80) | v53),
            v71,
            v88,
            v90);
          v62 = v61;
          btConvexHullInternal::Rational64::Rational64(v63, v72, v78, __SPAIR64__(HIDWORD(v80), v53));
          if ( btConvexHullInternal::Rational64::compare(v62, v64) <= 0 )
            goto LABEL_62;
        }
LABEL_52:
        v56 = *e0;
        if ( !*e0 )
          return;
        if ( !v56->target )
          return;
        v96 = v56->reverse->prev;
        if ( v96->copy <= this->mergeStamp )
          return;
        v57 = v96->target;
        v58 = v57->point.y - v87.y;
        v81.index = -1;
        v59 = &v57->point.x;
        v60 = *v59 - v87.x;
        v81.y = v58;
        v81.z = v59[2] - v87.z;
        v81.x = v60;
        if ( btConvexHullInternal::Point32::dot(&v73, &v81) )
          return;
        v89 = btConvexHullInternal::Point32::dot(&v74, &v81);
        v75.index = -1;
        v83 = HIDWORD(v84.x) * v81.y + LODWORD(v84.x) * v60 + LODWORD(v84.y) * v81.z;
        v75.x = LODWORD(v84.z) - *v59;
        v75.y = HIDWORD(v84.z) - v59[1];
        v75.z = z - v59[2];
        v79 = btConvexHullInternal::Point32::dot(&v74, &v75);
        if ( v79 >= 0 )
          return;
        if ( v89 )
        {
          if ( v89 >= 0 )
            return;
          btConvexHullInternal::Rational64::Rational64(0, v71, v88, v90);
          v66 = v65;
          btConvexHullInternal::Rational64::Rational64(v67, v72, v83, v89);
          if ( btConvexHullInternal::Rational64::compare(v66, v68) >= 0 )
            return;
        }
        else if ( v83 <= 0 )
        {
          return;
        }
        v87.x = *v59;
        v87.y = v59[1];
        *e0 = v96;
        v87.z = v59[2];
        v90 = v79;
        v87.index = v59[3];
      }
      else
      {
        if ( v55 < 0 || !(_DWORD)v55 )
          goto LABEL_52;
LABEL_62:
        v84.z = *(_QWORD *)&v51->x;
        v76.index = -1;
        z = v51->z;
        index = v51->index;
        v76.x = LODWORD(v84.z) - v87.x;
        v76.y = HIDWORD(v84.z) - v87.y;
        v76.z = z - v87.z;
        v90 = btConvexHullInternal::Point32::dot(&v74, &v76);
        *e1 = *e1 != (btConvexHullInternal::Edge *)HIDWORD(v82) ? v95 : 0;
      }
    }
  }
}
