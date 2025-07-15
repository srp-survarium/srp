void __userpurge Wm4::HullEdge2<float>::HullEdge2<float>(
        Wm4::HullEdge2<float> *this@<ecx>,
        Wm4::HullEdge2<float> **a2@<eax>,
        Wm4::HullEdge2<float> *iV0,
        int iV1)
{
  a2[5] = (Wm4::HullEdge2<float> *)-1;
  *a2 = this;
  a2[1] = iV0;
  a2[2] = 0;
  a2[3] = 0;
  a2[4] = 0;
}
