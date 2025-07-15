int __userpurge Wm4::ConvexHull<float>::ConvexHull<float>@<eax>(
        int result@<eax>,
        int a2@<ecx>,
        int a3@<xmm0>,
        int iVertexQuantity,
        bool bOwner)
{
  *(_DWORD *)(result + 4) = a2;
  *(_DWORD *)(result + 8) = iVertexQuantity;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = 0;
  *(_DWORD *)(result + 20) = 0;
  *(_DWORD *)result = &Wm4::ConvexHull<float>::`vftable';
  *(_DWORD *)(result + 24) = a3;
  *(_BYTE *)(result + 28) = bOwner;
  return result;
}
