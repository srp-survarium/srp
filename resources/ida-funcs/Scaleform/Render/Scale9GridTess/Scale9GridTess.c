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
  float v; // [esp+24h] [ebp-498h]
  unsigned int epsilon; // [esp+28h] [ebp-494h]
  unsigned int epsilona; // [esp+28h] [ebp-494h]
  unsigned int epsilonb; // [esp+28h] [ebp-494h]
  unsigned int epsilonc; // [esp+28h] [ebp-494h]
  unsigned int epsilond; // [esp+28h] [ebp-494h]
  unsigned int epsilone; // [esp+28h] [ebp-494h]
  unsigned int epsilonf; // [esp+28h] [ebp-494h]
  unsigned int epsilong; // [esp+28h] [ebp-494h]
  unsigned int epsilonh; // [esp+28h] [ebp-494h]
  unsigned int epsiloni; // [esp+28h] [ebp-494h]
  unsigned int epsilonj; // [esp+28h] [ebp-494h]
  unsigned int epsilonk; // [esp+28h] [ebp-494h]
  unsigned int epsilonl; // [esp+28h] [ebp-494h]
  unsigned int epsilonm; // [esp+28h] [ebp-494h]
  unsigned int epsilonn; // [esp+28h] [ebp-494h]
  unsigned int epsilono; // [esp+28h] [ebp-494h]
  float v50; // [esp+44h] [ebp-478h]
  float v51; // [esp+44h] [ebp-478h]
  float v52; // [esp+44h] [ebp-478h]
  float v53; // [esp+44h] [ebp-478h]
  float v54; // [esp+44h] [ebp-478h]
  float v55; // [esp+44h] [ebp-478h]
  float v56; // [esp+44h] [ebp-478h]
  float v57; // [esp+44h] [ebp-478h]
  float v58; // [esp+44h] [ebp-478h]
  float v59; // [esp+44h] [ebp-478h]
  float v60; // [esp+44h] [ebp-478h]
  float v61; // [esp+44h] [ebp-478h]
  float v62; // [esp+44h] [ebp-478h]
  float v63; // [esp+44h] [ebp-478h]
  float v64; // [esp+44h] [ebp-478h]
  float v65; // [esp+44h] [ebp-478h]
  float v66; // [esp+44h] [ebp-478h]
  float v67; // [esp+44h] [ebp-478h]
  float v68; // [esp+44h] [ebp-478h]
  float v69; // [esp+44h] [ebp-478h]
  float v70; // [esp+44h] [ebp-478h]
  float v71; // [esp+44h] [ebp-478h]
  float v72; // [esp+44h] [ebp-478h]
  float v73; // [esp+44h] [ebp-478h]
  float v74; // [esp+44h] [ebp-478h]
  float v75; // [esp+44h] [ebp-478h]
  float v76; // [esp+44h] [ebp-478h]
  float v77; // [esp+44h] [ebp-478h]
  float v78; // [esp+44h] [ebp-478h]
  float v79; // [esp+44h] [ebp-478h]
  float v80; // [esp+44h] [ebp-478h]
  float v81; // [esp+44h] [ebp-478h]
  float v82; // [esp+44h] [ebp-478h]
  float v83; // [esp+48h] [ebp-474h] BYREF
  float v84; // [esp+4Ch] [ebp-470h] BYREF
  float v85; // [esp+50h] [ebp-46Ch]
  Scaleform::Render::Image9GridVertex *u[2]; // [esp+54h] [ebp-468h]
  Scaleform::Render::Rect<float> cy; // [esp+5Ch] [ebp-460h] BYREF
  float v88; // [esp+6Ch] [ebp-450h]
  float v89; // [esp+70h] [ebp-44Ch]
  float c; // [esp+7Ch] [ebp-440h] BYREF
  float y; // [esp+80h] [ebp-43Ch]
  float x; // [esp+84h] [ebp-438h]
  float by; // [esp+88h] [ebp-434h]
  float x2; // [esp+8Ch] [ebp-430h]
  float ay; // [esp+90h] [ebp-42Ch]
  float x1; // [esp+94h] [ebp-428h]
  float y2; // [esp+98h] [ebp-424h]
  Scaleform::Render::Matrix2x4<float> toUV; // [esp+9Ch] [ebp-420h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+BCh] [ebp-400h] BYREF
  Scaleform::Render::Matrix2x4<float> v100; // [esp+DCh] [ebp-3E0h] BYREF
  float v101; // [esp+104h] [ebp-3B8h]
  float v102; // [esp+108h] [ebp-3B4h]
  Scaleform::Render::Matrix2x4<float> v103; // [esp+10Ch] [ebp-3B0h] BYREF
  double v104; // [esp+134h] [ebp-388h]
  double v105; // [esp+13Ch] [ebp-380h]
  double v106; // [esp+144h] [ebp-378h]
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> ver; // [esp+14Ch] [ebp-370h] BYREF

  this->VerCount = 0;
  this->Indices.Size = 0;
  this->Indices.pHeap = heap;
  this->Indices.Reserved = 72;
  this->Indices.Data = this->Indices.Static;
  c = imgRect->x1;
  y = imgRect->y1;
  x = imgRect->x2;
  by = imgRect->y1;
  x2 = imgRect->x2;
  ay = imgRect->y2;
  x1 = imgRect->x1;
  y2 = imgRect->y2;
  *(float *)u = c;
  c = c * s9g->ShapeMatrix.M[0][0] + s9g->ShapeMatrix.M[0][1] * y + s9g->ShapeMatrix.M[0][3];
  y = y * s9g->ShapeMatrix.M[1][1] + s9g->ShapeMatrix.M[1][0] * *(float *)u + s9g->ShapeMatrix.M[1][3];
  *(float *)u = x;
  x = x * s9g->ShapeMatrix.M[0][0] + s9g->ShapeMatrix.M[0][1] * by + s9g->ShapeMatrix.M[0][3];
  by = by * s9g->ShapeMatrix.M[1][1] + s9g->ShapeMatrix.M[1][0] * *(float *)u + s9g->ShapeMatrix.M[1][3];
  *(float *)u = x2;
  x2 = x2 * s9g->ShapeMatrix.M[0][0] + s9g->ShapeMatrix.M[0][1] * ay + s9g->ShapeMatrix.M[0][3];
  ay = ay * s9g->ShapeMatrix.M[1][1] + s9g->ShapeMatrix.M[1][0] * *(float *)u + s9g->ShapeMatrix.M[1][3];
  *(float *)u = x1;
  x1 = x1 * s9g->ShapeMatrix.M[0][0] + s9g->ShapeMatrix.M[0][1] * y2 + s9g->ShapeMatrix.M[0][3];
  y2 = y2 * s9g->ShapeMatrix.M[1][1] + s9g->ShapeMatrix.M[1][0] * *(float *)u + s9g->ShapeMatrix.M[1][3];
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
  toUV.M[0][0] = 1.0;
  toUV.M[0][1] = 0.0;
  toUV.M[0][2] = 0.0;
  toUV.M[0][3] = 0.0;
  toUV.M[1][0] = 0.0;
  toUV.M[1][2] = 0.0;
  toUV.M[1][3] = 0.0;
  cy.x1 = 0.0;
  cy.y1 = 0.0;
  cy.y2 = 0.0;
  toUV.M[1][1] = 1.0;
  cy.x2 = 1.0;
  v88 = 1.0;
  v89 = 1.0;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&toUV, &c, &cy.x1);
  Scaleform::Render::Matrix2x4<float>::Append(&toUV, &v100);
  cy.x1 = s9g->ResultingGrid.x1;
  ver.pHeap = heap;
  cy.y1 = s9g->ResultingGrid.y1;
  v7 = s9g->ResultingGrid.x2;
  ver.Size = 0;
  cy.x2 = v7;
  ver.Reserved = 72;
  v8 = s9g->ResultingGrid.y2;
  ver.Data = ver.Static;
  cy.y2 = v8;
  v105 = v100.M[0][1] * 0.0;
  v83 = v105 + v100.M[0][0] + v100.M[0][3];
  v106 = v100.M[1][1] * 0.0;
  v85 = v106 + v100.M[1][0] + v100.M[1][3];
  v101 = v100.M[0][0] + v100.M[0][1] + v100.M[0][3];
  v84 = v100.M[1][0] + v100.M[1][1] + v100.M[1][3];
  v104 = v100.M[0][0] * 0.0;
  v50 = v100.M[0][3] + v100.M[0][1] + v104;
  *(double *)u = 0.0 * v100.M[1][0];
  v102 = v100.M[1][3] + v100.M[1][1] + *(double *)u;
  AreaCode = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, c, y);
  *(float *)u = *(double *)u + v106 + v100.M[1][3];
  v = *(float *)u;
  *(float *)u = v104 + v105 + v100.M[0][3];
  Scaleform::Render::Scale9GridTess::addVertex(this, &ver, c, y, *(float *)u, v, AreaCode);
  v10 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, x, by);
  Scaleform::Render::Scale9GridTess::addVertex(this, &ver, x, by, v83, v85, v10);
  v11 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, x2, ay);
  Scaleform::Render::Scale9GridTess::addVertex(this, &ver, x2, ay, v101, v84, v11);
  v12 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, x1, y2);
  Scaleform::Render::Scale9GridTess::addVertex(this, &ver, x1, y2, v50, v102, v12);
  *(float *)u = (cy.x2 - cy.x1) * 0.5;
  v85 = 0.5 * (cy.y2 - cy.y1);
  if ( Scaleform::Render::SegmentLineIntersection(c, y, x, by, cy.x1, cy.y1, cy.x2, cy.y1, &v83, &v84, 0.001) )
  {
    v51 = v84 - v85;
    epsilon = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v51);
    v52 = v84 + v85;
    v13 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v52);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v13, epsilon);
  }
  if ( Scaleform::Render::SegmentLineIntersection(c, y, x, by, cy.x2, cy.y1, cy.x2, cy.y2, &v83, &v84, 0.001) )
  {
    v53 = v83 - *(float *)u;
    epsilona = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v53, v84);
    v54 = v83 + *(float *)u;
    v14 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v54, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v14, epsilona);
  }
  if ( Scaleform::Render::SegmentLineIntersection(c, y, x, by, cy.x2, cy.y2, cy.x1, cy.y2, &v83, &v84, 0.001) )
  {
    v55 = v84 - v85;
    epsilonb = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v55);
    v56 = v84 + v85;
    v15 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v56);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v15, epsilonb);
  }
  if ( Scaleform::Render::SegmentLineIntersection(c, y, x, by, cy.x1, cy.y2, cy.x1, cy.y1, &v83, &v84, 0.001) )
  {
    v57 = v83 - *(float *)u;
    epsilonc = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v57, v84);
    v58 = v83 + *(float *)u;
    v16 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v58, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v16, epsilonc);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x, by, x2, ay, cy.x1, cy.y1, cy.x2, cy.y1, &v83, &v84, 0.001) )
  {
    v59 = v84 - v85;
    epsilond = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v59);
    v60 = v84 + v85;
    v17 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v60);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v17, epsilond);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x, by, x2, ay, cy.x2, cy.y1, cy.x2, cy.y2, &v83, &v84, 0.001) )
  {
    v61 = v83 - *(float *)u;
    epsilone = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v61, v84);
    v62 = v83 + *(float *)u;
    v18 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v62, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v18, epsilone);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x, by, x2, ay, cy.x2, cy.y2, cy.x1, cy.y2, &v83, &v84, 0.001) )
  {
    v63 = v84 - v85;
    epsilonf = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v63);
    v64 = v84 + v85;
    v19 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v64);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v19, epsilonf);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x, by, x2, ay, cy.x1, cy.y2, cy.x1, cy.y1, &v83, &v84, 0.001) )
  {
    v65 = v83 - *(float *)u;
    epsilong = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v65, v84);
    v66 = v83 + *(float *)u;
    v20 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v66, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v20, epsilong);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x2, ay, x1, y2, cy.x1, cy.y1, cy.x2, cy.y1, &v83, &v84, 0.001) )
  {
    v67 = v84 - v85;
    epsilonh = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v67);
    v68 = v84 + v85;
    v21 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v68);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v21, epsilonh);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x2, ay, x1, y2, cy.x2, cy.y1, cy.x2, cy.y2, &v83, &v84, 0.001) )
  {
    v69 = v83 - *(float *)u;
    epsiloni = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v69, v84);
    v70 = v83 + *(float *)u;
    v22 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v70, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v22, epsiloni);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x2, ay, x1, y2, cy.x2, cy.y2, cy.x1, cy.y2, &v83, &v84, 0.001) )
  {
    v71 = v84 - v85;
    epsilonj = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v71);
    v72 = v84 + v85;
    v23 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v72);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v23, epsilonj);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x2, ay, x1, y2, cy.x1, cy.y2, cy.x1, cy.y1, &v83, &v84, 0.001) )
  {
    v73 = v83 - *(float *)u;
    epsilonk = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v73, v84);
    v74 = v83 + *(float *)u;
    v24 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v74, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v24, epsilonk);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x1, y2, c, y, cy.x1, cy.y1, cy.x2, cy.y1, &v83, &v84, 0.001) )
  {
    v75 = v84 - v85;
    epsilonl = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v75);
    v76 = v84 + v85;
    v25 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v76);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v25, epsilonl);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x1, y2, c, y, cy.x2, cy.y1, cy.x2, cy.y2, &v83, &v84, 0.001) )
  {
    v77 = v83 - *(float *)u;
    epsilonm = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v77, v84);
    v78 = v83 + *(float *)u;
    v26 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v78, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v26, epsilonm);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x1, y2, c, y, cy.x2, cy.y2, cy.x1, cy.y2, &v83, &v84, 0.001) )
  {
    v79 = v84 - v85;
    epsilonn = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v79);
    v80 = v84 + v85;
    v27 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v83, v80);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v27, epsilonn);
  }
  if ( Scaleform::Render::SegmentLineIntersection(x1, y2, c, y, cy.x1, cy.y2, cy.x1, cy.y1, &v83, &v84, 0.001) )
  {
    v81 = v83 - *(float *)u;
    epsilono = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v81, v84);
    v82 = v83 + *(float *)u;
    v28 = Scaleform::Render::Scale9GridTess::getAreaCode(this, &cy, v82, v84);
    Scaleform::Render::Scale9GridTess::addVertices(this, &ver, &toUV, v83, v84, v28, epsilono);
  }
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, &c, cy.x1, cy.y1, &toUV, 0, 4u, 0xCu, 8u);
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, &c, cy.x2, cy.y1, &toUV, 1u, 0, 8u, 9u);
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, &c, cy.x2, cy.y2, &toUV, 3u, 2u, 0, 1u);
  Scaleform::Render::Scale9GridTess::addCorner(this, &ver, &c, cy.x1, cy.y2, &toUV, 2u, 6u, 4u, 0);
  Scaleform::Alg::QuickSortSliced<Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>,bool (__cdecl *)(Scaleform::Render::Scale9GridTess::TmpVertexType const &,Scaleform::Render::Scale9GridTess::TmpVertexType const &)>(
    &ver,
    0,
    ver.Size,
    (bool (__cdecl *)(const Scaleform::Render::Scale9GridTess::TmpVertexType *, const Scaleform::Render::Scale9GridTess::TmpVertexType *))Scaleform::Render::Scale9GridTess::cmpCodes);
  v85 = 0.0;
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
        Scaleform::Render::Scale9GridTess::tessellateArea(this, &ver, v85, v29);
        v31 = u[0];
        Data = ver.Data;
        v85 = *(float *)&v29;
      }
      u[0] = (Scaleform::Render::Image9GridVertex *)((char *)u[0] + 12);
      ++v29;
    }
    while ( v29 < ver.Size );
  }
  Scaleform::Render::Scale9GridTess::tessellateArea(this, &ver, v85, v29);
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
