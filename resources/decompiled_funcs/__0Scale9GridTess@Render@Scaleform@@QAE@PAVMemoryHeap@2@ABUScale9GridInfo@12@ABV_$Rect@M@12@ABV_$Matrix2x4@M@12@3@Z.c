void __thiscall Scaleform::Render::Scale9GridTess::Scale9GridTess(
        Scaleform::Render::Scale9GridTess *this,
        Scaleform::MemoryHeap *heap,
        const Scaleform::Render::Scale9GridInfo *s9g,
        const Scaleform::Render::Rect<float> *imgRect,
        const Scaleform::Render::Matrix2x4<float> *uvMatrix,
        const Scaleform::Render::Matrix2x4<float> *fillMatrix)
{
  double v7; // st7
  double v8; // st7
  unsigned int AreaCode; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // ebx
  Scaleform::Render::Scale9GridTess::TmpVertexType *Data; // ecx
  Scaleform::Render::Image9GridVertex *v31; // eax
  unsigned int v32; // ebx
  float v; // [esp+4B10h] [ebp-498h]
  unsigned int epsilon; // [esp+4B14h] [ebp-494h]
  unsigned int epsilona; // [esp+4B14h] [ebp-494h]
  unsigned int epsilonb; // [esp+4B14h] [ebp-494h]
  unsigned int epsilonc; // [esp+4B14h] [ebp-494h]
  unsigned int epsilond; // [esp+4B14h] [ebp-494h]
  unsigned int epsilone; // [esp+4B14h] [ebp-494h]
  unsigned int epsilonf; // [esp+4B14h] [ebp-494h]
  unsigned int epsilong; // [esp+4B14h] [ebp-494h]
  unsigned int epsilonh; // [esp+4B14h] [ebp-494h]
  unsigned int epsiloni; // [esp+4B14h] [ebp-494h]
  unsigned int epsilonj; // [esp+4B14h] [ebp-494h]
  unsigned int epsilonk; // [esp+4B14h] [ebp-494h]
  unsigned int epsilonl; // [esp+4B14h] [ebp-494h]
  unsigned int epsilonm; // [esp+4B14h] [ebp-494h]
  unsigned int epsilonn; // [esp+4B14h] [ebp-494h]
  unsigned int epsilono; // [esp+4B14h] [ebp-494h]
  float v50; // [esp+4B30h] [ebp-478h]
  float v51; // [esp+4B30h] [ebp-478h]
  float v52; // [esp+4B30h] [ebp-478h]
  float v53; // [esp+4B30h] [ebp-478h]
  float v54; // [esp+4B30h] [ebp-478h]
  float v55; // [esp+4B30h] [ebp-478h]
  float v56; // [esp+4B30h] [ebp-478h]
  float v57; // [esp+4B30h] [ebp-478h]
  float v58; // [esp+4B30h] [ebp-478h]
  float v59; // [esp+4B30h] [ebp-478h]
  float v60; // [esp+4B30h] [ebp-478h]
  float v61; // [esp+4B30h] [ebp-478h]
  float v62; // [esp+4B30h] [ebp-478h]
  float v63; // [esp+4B30h] [ebp-478h]
  float v64; // [esp+4B30h] [ebp-478h]
  float v65; // [esp+4B30h] [ebp-478h]
  float v66; // [esp+4B30h] [ebp-478h]
  float v67; // [esp+4B30h] [ebp-478h]
  float v68; // [esp+4B30h] [ebp-478h]
  float v69; // [esp+4B30h] [ebp-478h]
  float v70; // [esp+4B30h] [ebp-478h]
  float v71; // [esp+4B30h] [ebp-478h]
  float v72; // [esp+4B30h] [ebp-478h]
  float v73; // [esp+4B30h] [ebp-478h]
  float v74; // [esp+4B30h] [ebp-478h]
  float v75; // [esp+4B30h] [ebp-478h]
  float v76; // [esp+4B30h] [ebp-478h]
  float v77; // [esp+4B30h] [ebp-478h]
  float v78; // [esp+4B30h] [ebp-478h]
  float v79; // [esp+4B30h] [ebp-478h]
  float v80; // [esp+4B30h] [ebp-478h]
  float v81; // [esp+4B30h] [ebp-478h]
  float v82; // [esp+4B30h] [ebp-478h]
  float v83; // [esp+4B34h] [ebp-474h] BYREF
  float v84; // [esp+4B38h] [ebp-470h] BYREF
  unsigned int v85; // [esp+4B3Ch] [ebp-46Ch]
  Scaleform::Render::Image9GridVertex *u[2]; // [esp+4B40h] [ebp-468h]
  Scaleform::Render::Rect<float> dst; // [esp+4B48h] [ebp-460h] BYREF
  float v88; // [esp+4B58h] [ebp-450h]
  float v89; // [esp+4B5Ch] [ebp-44Ch]
  float src; // [esp+4B68h] [ebp-440h] BYREF
  float ay; // [esp+4B6Ch] [ebp-43Ch]
  float x2; // [esp+4B70h] [ebp-438h]
  float by; // [esp+4B74h] [ebp-434h]
  float v94; // [esp+4B78h] [ebp-430h]
  float y2; // [esp+4B7Ch] [ebp-42Ch]
  float x1; // [esp+4B80h] [ebp-428h]
  float v97; // [esp+4B84h] [ebp-424h]
  Scaleform::Render::Matrix2x4<float> v98; // [esp+4B88h] [ebp-420h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+4BA8h] [ebp-400h] BYREF
  Scaleform::Render::Matrix2x4<float> v100; // [esp+4BC8h] [ebp-3E0h] BYREF
  float v101; // [esp+4BF0h] [ebp-3B8h]
  float v102; // [esp+4BF4h] [ebp-3B4h]
  Scaleform::Render::Matrix2x4<float> v103; // [esp+4BF8h] [ebp-3B0h] BYREF
  double v104; // [esp+4C20h] [ebp-388h]
  double v105; // [esp+4C28h] [ebp-380h]
  double v106; // [esp+4C30h] [ebp-378h]
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> ver; // [esp+4C38h] [ebp-370h] BYREF

  this->VerCount = 0;
  this->Indices.Size = 0;
  this->Indices.pHeap = heap;
  this->Indices.Reserved = 72;
  this->Indices.Data = this->Indices.Static;
  src = imgRect->x1;
  ay = imgRect->y1;
  x2 = imgRect->x2;
  by = imgRect->y1;
  v94 = imgRect->x2;
  y2 = imgRect->y2;
  x1 = imgRect->x1;
  v97 = imgRect->y2;
  *(float *)u = src;
  src = src * s9g->ShapeMatrix.M[0][0] + s9g->ShapeMatrix.M[0][1] * ay + s9g->ShapeMatrix.M[0][3];
  ay = ay * s9g->ShapeMatrix.M[1][1] + s9g->ShapeMatrix.M[1][0] * *(float *)u + s9g->ShapeMatrix.M[1][3];
  *(float *)u = x2;
  x2 = x2 * s9g->ShapeMatrix.M[0][0] + s9g->ShapeMatrix.M[0][1] * by + s9g->ShapeMatrix.M[0][3];
  by = by * s9g->ShapeMatrix.M[1][1] + s9g->ShapeMatrix.M[1][0] * *(float *)u + s9g->ShapeMatrix.M[1][3];
  *(float *)u = v94;
  v94 = v94 * s9g->ShapeMatrix.M[0][0] + s9g->ShapeMatrix.M[0][1] * y2 + s9g->ShapeMatrix.M[0][3];
  y2 = y2 * s9g->ShapeMatrix.M[1][1] + s9g->ShapeMatrix.M[1][0] * *(float *)u + s9g->ShapeMatrix.M[1][3];
  *(float *)u = x1;
  x1 = x1 * s9g->ShapeMatrix.M[0][0] + s9g->ShapeMatrix.M[0][1] * v97 + s9g->ShapeMatrix.M[0][3];
  v97 = v97 * s9g->ShapeMatrix.M[1][1] + s9g->ShapeMatrix.M[1][0] * *(float *)u + s9g->ShapeMatrix.M[1][3];
  v100.M[0][0] = uvMatrix->M[0][0];
  v100.M[0][1] = uvMatrix->M[0][1];
  v100.M[0][2] = uvMatrix->M[0][2];
  v100.M[0][3] = uvMatrix->M[0][3];
  v100.M[1][0] = uvMatrix->M[1][0];
  v100.M[1][1] = uvMatrix->M[1][1];
  v100.M[1][2] = uvMatrix->M[1][2];
  v100.M[1][3] = uvMatrix->M[1][3];
  m.M[0][0] = fillMatrix->M[0][0];
  m.M[0][1] = fillMatrix->M[0][1];
  m.M[0][2] = fillMatrix->M[0][2];
  m.M[1][0] = fillMatrix->M[1][0];
  m.M[1][1] = fillMatrix->M[1][1];
  m.M[1][2] = fillMatrix->M[1][2];
  v103.M[0][0] = 1.0;
  v103.M[0][1] = 0.0;
  v103.M[0][2] = 0.0;
  v103.M[1][0] = 0.0;
  v103.M[1][2] = 0.0;
  v103.M[1][1] = 1.0;
  if ( m.M[0][0] <= -0.0000099999997 )
    m.M[0][0] = -1.0;
  if ( m.M[0][0] >= 0.0000099999997 )
    m.M[0][0] = 1.0;
  if ( m.M[1][1] <= -0.0000099999997 )
    m.M[1][1] = -1.0;
  if ( m.M[1][1] >= 0.0000099999997 )
    m.M[1][1] = 1.0;
  if ( m.M[0][1] <= -0.0000099999997 )
    m.M[0][1] = -1.0;
  if ( m.M[0][1] >= 0.0000099999997 )
    m.M[0][1] = 1.0;
  if ( m.M[1][0] <= -0.0000099999997 )
    m.M[1][0] = -1.0;
  if ( m.M[1][0] >= 0.0000099999997 )
    m.M[1][0] = 1.0;
  m.M[0][3] = 0.0;
  m.M[1][3] = 0.0;
  *(float *)u = 0.0 - 0.5;
  v103.M[0][3] = *(float *)u;
  v103.M[1][3] = *(float *)u;
  Scaleform::Render::Matrix2x4<float>::Append(&v103, &m);
  v103.M[0][3] = v103.M[0][3] + 0.5;
  v103.M[1][3] = v103.M[1][3] + 0.5;
  Scaleform::Render::Matrix2x4<float>::Prepend(&v100, &v103);
  v98.M[0][0] = 1.0;
  v98.M[0][1] = 0.0;
  v98.M[0][2] = 0.0;
  v98.M[0][3] = 0.0;
  v98.M[1][0] = 0.0;
  v98.M[1][2] = 0.0;
  v98.M[1][3] = 0.0;
  dst.x1 = 0.0;
  dst.y1 = 0.0;
  dst.y2 = 0.0;
  v98.M[1][1] = 1.0;
  dst.x2 = 1.0;
  v88 = 1.0;
  v89 = 1.0;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&v98, &src, &dst.x1);
  Scaleform::Render::Matrix2x4<float>::Append(&v98, &v100);
  dst.x1 = s9g->ResultingGrid.x1;
  ver.pHeap = heap;
  dst.y1 = s9g->ResultingGrid.y1;
  v7 = s9g->ResultingGrid.x2;
  ver.Size = 0;
  dst.x2 = v7;
  ver.Reserved = 72;
  v8 = s9g->ResultingGrid.y2;
  ver.Data = ver.Static;
  dst.y2 = v8;
  v105 = v100.M[0][1] * 0.0;
  v83 = v105 + v100.M[0][0] + v100.M[0][3];
  v106 = v100.M[1][1] * 0.0;
  *(float *)&v85 = v106 + v100.M[1][0] + v100.M[1][3];
  v101 = v100.M[0][0] + v100.M[0][1] + v100.M[0][3];
  v84 = v100.M[1][0] + v100.M[1][1] + v100.M[1][3];
  v104 = v100.M[0][0] * 0.0;
  v50 = v100.M[0][3] + v100.M[0][1] + v104;
  *(double *)u = 0.0 * v100.M[1][0];
  v102 = v100.M[1][3] + v100.M[1][1] + *(double *)u;
  AreaCode = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, src, ay);
  *(float *)u = *(double *)u + v106 + v100.M[1][3];
  v = *(float *)u;
  *(float *)u = v104 + v105 + v100.M[0][3];
  Scaleform::Render::Scale9GridTess::addVertex(this, &ver, src, ay, *(float *)u, v, AreaCode);
  v10 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, x2, by);
  Scaleform::Render::Scale9GridTess::addVertex(this, &ver, x2, by, v83, *(float *)&v85, v10);
  v11 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v94, y2);
  Scaleform::Render::Scale9GridTess::addVertex(this, &ver, v94, y2, v101, v84, v11);
  v12 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, x1, v97);
  Scaleform::Render::Scale9GridTess::addVertex(this, &ver, x1, v97, v50, v102, v12);
  *(float *)u = (dst.x2 - dst.x1) * 0.5;
  *(float *)&v85 = 0.5 * (dst.y2 - dst.y1);
  if ( Scaleform::Render::SegmentLineIntersection(src, ay, x2, by, dst.x1, dst.y1, dst.x2, dst.y1, &v83, &v84, 0.001) )
  {
    v51 = v84 - *(float *)&v85;
    epsilon = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v51);
    v52 = v84 + *(float *)&v85;
    v13 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v52);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v13, epsilon);
  }
  if ( Scaleform::Render::SegmentLineIntersection(src, ay, x2, by, dst.x2, dst.y1, dst.x2, dst.y2, &v83, &v84, 0.001) )
  {
    v53 = v83 - *(float *)u;
    epsilona = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v53, v84);
    v54 = v83 + *(float *)u;
    v14 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v54, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v14, epsilona);
  }
  if ( Scaleform::Render::SegmentLineIntersection(src, ay, x2, by, dst.x2, dst.y2, dst.x1, dst.y2, &v83, &v84, 0.001) )
  {
    v55 = v84 - *(float *)&v85;
    epsilonb = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v55);
    v56 = v84 + *(float *)&v85;
    v15 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v56);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v15, epsilonb);
  }
  if ( Scaleform::Render::SegmentLineIntersection(src, ay, x2, by, dst.x1, dst.y2, dst.x1, dst.y1, &v83, &v84, 0.001) )
  {
    v57 = v83 - *(float *)u;
    epsilonc = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v57, v84);
    v58 = v83 + *(float *)u;
    v16 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v58, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v16, epsilonc);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x2, by, v94, y2, dst.x1, dst.y1, dst.x2, dst.y1, &v83, &v84, 0.001) )
  {
    v59 = v84 - *(float *)&v85;
    epsilond = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v59);
    v60 = v84 + *(float *)&v85;
    v17 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v60);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v17, epsilond);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x2, by, v94, y2, dst.x2, dst.y1, dst.x2, dst.y2, &v83, &v84, 0.001) )
  {
    v61 = v83 - *(float *)u;
    epsilone = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v61, v84);
    v62 = v83 + *(float *)u;
    v18 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v62, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v18, epsilone);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x2, by, v94, y2, dst.x2, dst.y2, dst.x1, dst.y2, &v83, &v84, 0.001) )
  {
    v63 = v84 - *(float *)&v85;
    epsilonf = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v63);
    v64 = v84 + *(float *)&v85;
    v19 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v64);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v19, epsilonf);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x2, by, v94, y2, dst.x1, dst.y2, dst.x1, dst.y1, &v83, &v84, 0.001) )
  {
    v65 = v83 - *(float *)u;
    epsilong = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v65, v84);
    v66 = v83 + *(float *)u;
    v20 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v66, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v20, epsilong);
  }
  if ( Scaleform::Render::SegmentLineIntersection(v94, y2, x1, v97, dst.x1, dst.y1, dst.x2, dst.y1, &v83, &v84, 0.001) )
  {
    v67 = v84 - *(float *)&v85;
    epsilonh = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v67);
    v68 = v84 + *(float *)&v85;
    v21 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v68);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v21, epsilonh);
  }
  if ( Scaleform::Render::SegmentLineIntersection(v94, y2, x1, v97, dst.x2, dst.y1, dst.x2, dst.y2, &v83, &v84, 0.001) )
  {
    v69 = v83 - *(float *)u;
    epsiloni = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v69, v84);
    v70 = v83 + *(float *)u;
    v22 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v70, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v22, epsiloni);
  }
  if ( Scaleform::Render::SegmentLineIntersection(v94, y2, x1, v97, dst.x2, dst.y2, dst.x1, dst.y2, &v83, &v84, 0.001) )
  {
    v71 = v84 - *(float *)&v85;
    epsilonj = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v71);
    v72 = v84 + *(float *)&v85;
    v23 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v72);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v23, epsilonj);
  }
  if ( Scaleform::Render::SegmentLineIntersection(v94, y2, x1, v97, dst.x1, dst.y2, dst.x1, dst.y1, &v83, &v84, 0.001) )
  {
    v73 = v83 - *(float *)u;
    epsilonk = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v73, v84);
    v74 = v83 + *(float *)u;
    v24 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v74, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v24, epsilonk);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x1, v97, src, ay, dst.x1, dst.y1, dst.x2, dst.y1, &v83, &v84, 0.001) )
  {
    v75 = v84 - *(float *)&v85;
    epsilonl = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v75);
    v76 = v84 + *(float *)&v85;
    v25 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v76);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v25, epsilonl);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x1, v97, src, ay, dst.x2, dst.y1, dst.x2, dst.y2, &v83, &v84, 0.001) )
  {
    v77 = v83 - *(float *)u;
    epsilonm = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v77, v84);
    v78 = v83 + *(float *)u;
    v26 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v78, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v26, epsilonm);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x1, v97, src, ay, dst.x2, dst.y2, dst.x1, dst.y2, &v83, &v84, 0.001) )
  {
    v79 = v84 - *(float *)&v85;
    epsilonn = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v79);
    v80 = v84 + *(float *)&v85;
    v27 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v83, v80);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v27, epsilonn);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x1, v97, src, ay, dst.x1, dst.y2, dst.x1, dst.y1, &v83, &v84, 0.001) )
  {
    v81 = v83 - *(float *)u;
    epsilono = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v81, v84);
    v82 = v83 + *(float *)u;
    v28 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &dst, v82, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &v98, v83, v84, v28, epsilono);
  }
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, &src, dst.x1, dst.y1, &v98, 0, 4u, 0xCu, 8u);
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, &src, dst.x2, dst.y1, &v98, 1u, 0, 8u, 9u);
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, &src, dst.x2, dst.y2, &v98, 3u, 2u, 0, 1u);
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, &src, dst.x1, dst.y2, &v98, 2u, 6u, 4u, 0);
  Scaleform::Alg::QuickSortSliced<Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>,bool (__cdecl *)(Scaleform::Render::Scale9GridTess::TmpVertexType const &,Scaleform::Render::Scale9GridTess::TmpVertexType const &)>(
    &ver,
    0,
    ver.Size,
    (bool (__cdecl *)(const Scaleform::Render::Scale9GridTess::TmpVertexType *, const Scaleform::Render::Scale9GridTess::TmpVertexType *))Scaleform::Render::Scale9GridTess::cmpCodes);
  *(float *)&v85 = 0.0;
  v29 = 1;
  if ( ver.Size > 1 )
  {
    Data = ver.Data;
    v31 = 0;
    u[0] = (Scaleform::Render::Image9GridVertex *)12;
    do
    {
      if ( *(_DWORD *)((char *)&u[0]->x + (unsigned int)Data) != *(unsigned int *)((char *)&Data->AreaCode + (_DWORD)v31) )
      {
        Scaleform::Render::Scale9GridTess::tessellateArea(this, &ver, *(float *)&v85, v29);
        v31 = u[0];
        Data = ver.Data;
        v85 = v29;
      }
      u[0] = (Scaleform::Render::Image9GridVertex *)((char *)u[0] + 12);
      ++v29;
    }
    while ( v29 < ver.Size );
  }
  Scaleform::Render::Scale9GridTess::tessellateArea(this, &ver, *(float *)&v85, v29);
  v32 = 0;
  if ( this->VerCount )
  {
    u[0] = (Scaleform::Render::Image9GridVertex *)this;
    do
    {
      Scaleform::Render::Scale9GridTess::transformVertex(this, s9g, u[0]++);
      ++v32;
    }
    while ( v32 < this->VerCount );
  }
  if ( ver.Data != ver.Static )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ver.Data);
}
