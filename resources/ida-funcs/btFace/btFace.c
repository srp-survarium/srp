void __stdcall btFace::btFace(btFace *this)
{
  const btAlignedObjectArray<int> *v1; // eax
  btAlignedObjectArray<int> *v2; // ecx
  float *v3; // edi

  v3 = (float *)v1;
  btAlignedObjectArray<int>::btAlignedObjectArray<int>(v2, &this->m_indices, v1);
  this->m_plane[0] = v3[5];
  this->m_plane[1] = v3[6];
  this->m_plane[2] = v3[7];
  this->m_plane[3] = v3[8];
}
