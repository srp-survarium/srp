void __cdecl ApplyScaleToLeafCards(struct SpeedTree::SLeafCards *a1, float a2)
{
  int i; // [esp+0h] [ebp-10h]
  float *m_pPositions; // [esp+4h] [ebp-Ch]
  float *v4; // [esp+4h] [ebp-Ch]
  float *m_pDimensions; // [esp+8h] [ebp-8h]
  float *v6; // [esp+8h] [ebp-8h]
  float *m_pLeafCardOffsets; // [esp+Ch] [ebp-4h]
  float *v8; // [esp+Ch] [ebp-4h]

  if ( a1->m_nTotalNumCards > 0 && a1->m_pPositions )
  {
    m_pPositions = (float *)a1->m_pPositions;
    m_pDimensions = (float *)a1->m_pDimensions;
    m_pLeafCardOffsets = (float *)a1->m_pLeafCardOffsets;
    for ( i = 0; i < a1->m_nTotalNumCards; ++i )
    {
      *m_pPositions = *m_pPositions * a2;
      v4 = m_pPositions + 1;
      *v4 = *v4 * a2;
      ++v4;
      *v4 = *v4 * a2;
      m_pPositions = v4 + 1;
      *m_pDimensions = *m_pDimensions * a2;
      v6 = m_pDimensions + 1;
      *v6 = *v6 * a2;
      m_pDimensions = v6 + 1;
      *m_pLeafCardOffsets = *m_pLeafCardOffsets * a2;
      v8 = m_pLeafCardOffsets + 1;
      *v8 = *v8 * a2;
      ++v8;
      *v8 = *v8 * a2;
      v8[1] = v8[1] * a2;
      m_pLeafCardOffsets = v8 + 2;
    }
  }
}
