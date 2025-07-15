void __thiscall SpeedTree::CCore::DeleteGeometry(SpeedTree::CCore *this, bool a2)
{
  unsigned __int8 *src; // [esp+34h] [ebp-8h]
  const float *m_pTexCoords; // [esp+38h] [ebp-4h] BYREF

  if ( this->m_bBillboardTexCoordsCopied )
  {
    m_pTexCoords = this->m_sGeometry.m_sVertBBs.m_pTexCoords;
    SpeedTree::st_delete_array<float>(&m_pTexCoords);
    this->m_bBillboardTexCoordsCopied = 0;
  }
  if ( a2 && this->m_sGeometry.m_sVertBBs.m_nNumBillboards > 0 )
  {
    src = (unsigned __int8 *)this->m_sGeometry.m_sVertBBs.m_pTexCoords;
    this->m_sGeometry.m_sVertBBs.m_pTexCoords = (const float *)SpeedTree::st_new_array<int>(
                                                                 4 * this->m_sGeometry.m_sVertBBs.m_nNumBillboards,
                                                                 "st_float32");
    memcpy(
      (unsigned __int8 *)this->m_sGeometry.m_sVertBBs.m_pTexCoords,
      src,
      16 * this->m_sGeometry.m_sVertBBs.m_nNumBillboards);
    this->m_bBillboardTexCoordsCopied = 1;
  }
  if ( this->m_bOwnsSrtBuffer && this->m_pSrtBuffer )
    SpeedTree::st_delete_array<unsigned char>(&this->m_pSrtBuffer);
  SpeedTree::SGeometry::Clear(&this->m_sGeometry);
}
